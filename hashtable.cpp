#include "hashtable.h"

#include <iostream>
#include <type_traits>

// Default constructor.
// Initializes array to nullptr of MAXSIZE.
template <typename T> HashTable<T>::HashTable() {
  hashtable = new TableItem<T> *[MAXSIZE]();
}

// Deconstructor
template <typename T> HashTable<T>::~HashTable() {
  for (int i = 0; i < MAXSIZE; i++) {
    TableItem<T> *currItem = hashtable[i];

    while (currItem->item != nullptr) {
      TableItem<T> *nextItem = currItem->nextItem;
      delete currItem;
      currItem = nextItem;
    }

    // delete hashtable[i];
    // hashtable[i] = nullptr;
  }

  delete[] hashtable;
}

// Add item to the hash table.
// Returns false on fail
template <typename T> bool HashTable<T>::add(T *item) {
  std::cout << "Added item: " << item << std::endl;
  /*
  int idx = hash(item);

  if (idx < 0 || idx > MAXSIZE) { // hash function returns -1 if unable to hash.
    return false;
  }

  TableItem<T> *currItem = hashtable[idx];
  TableItem<T> *prevItem = nullptr;

  while (currItem->item != nullptr) {
    prevItem = currItem;
    currItem = currItem->nextItem;
    prevItem->nextItem = currItem;
  }

  currItem->item = item;
  currItem->nextItem = new TableItem<T>;
  */
  return true;
}

// Remove item from the hash table.
// Returns false on fail.
template <typename T> bool HashTable<T>::remove(T *item) {
  int idx = hash(item);

  if (idx == -1) { // hash function returns -1 if unable to hash.
    return false;
  }

  delete hashtable[idx];
  hashtable[idx] = nullptr;

  return true;
}

// ID must match the result of the item's getID method.
// Returns nullptr on fail.
template <typename T> T *HashTable<T>::getByID(int itemID) {
  int idx = hashID(itemID);

  if (idx == -1) { // hash function returns -1 if unable to hash.
    return nullptr;
  }

  return hashtable[idx];
}

// Get an item by its pointer.
// Returns nullptr on fail.
template <typename T> T HashTable<T>::*get(T *item) {}

// Prints array in order (excluding nullptrs)
template <typename T> void HashTable<T>::display() {}

// Returns the index for an item, but does not store it.
// Returns -1 if item is invalid.
template <typename T> int HashTable<T>::hash(const T *item) {
  if (!(std::is_member_function_pointer<decltype(&T::getID)>::value)) {
    return -1;
  }

  return hashID(item->getID());
}

template <typename T> int HashTable<T>::hashID(int ID) {
  // TODO: Placeholder
  return ID % MAXSIZE;
}

template <typename T> int HashTable<T>::probeNext(int currIdx, int i) {}