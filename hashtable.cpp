#include "hashtable.h"

#include "customer.h"
#include "movie.h"

#include <iostream>
#include <type_traits>

// Default constructor.
template <typename T> HashTable<T>::HashTable() {}

// Deconstructor
template <typename T> HashTable<T>::~HashTable() {
  TableItem<T> *currItem;
  TableItem<T> *nextItem;

  // Iterate through the array
  for (int i = 0; i < HASHTABLE_SIZE; i++) {
    currItem = hashtable[i];

    // Iterate through each linked-list
    while (currItem->item != nullptr) {
      nextItem = currItem->nextItem;

      delete currItem;          // Free memory
      currItem->item = nullptr; // De-allocate pointer

      currItem = nextItem;
    }

    // delete hashtable[i];
    // hashtable[i] = nullptr;
  }
}

// Add item to the hash table.
// Returns false on fail
template <typename T> bool HashTable<T>::add(T *item) {
  int idx = hash(item);

  // The hash function returns -1 if unable to hash.
  if (idx < 0 || idx > HASHTABLE_SIZE) {
    return false;
  }

  TableItem<T> *newItem = new TableItem<T>();
  newItem->item = item;

  if (hashtable[idx]->item == nullptr) {
    newItem->nextItem = nullptr;
  } else {
    newItem->nextItem = hashtable[idx];
  }

  hashtable[idx] = newItem;

  return true;
}

// Remove item from the hash table.
// Returns false on fail.
template <typename T> bool HashTable<T>::remove(T *item) {
  int idx = hash(item);

  // The hash function returns -1 if unable to hash.
  if (idx == -1 || idx > HASHTABLE_SIZE) {
    return false;
  }

  printListAtIdx(idx); // DELETE ME

  TableItem<T> *currItem = hashtable[idx];
  TableItem<T> *prevItem = currItem;

  while (currItem != nullptr && currItem->item != nullptr &&
         currItem->item != item) {
    prevItem = currItem;
    currItem = currItem->nextItem;
  }

  prevItem->nextItem = currItem->nextItem;

  printListAtIdx(idx); // DELETE ME

  return true;
}

// ID must match the result of the item's getID method.
// Returns nullptr on fail.
template <typename T> T *HashTable<T>::getByID(int itemID) {
  /*
  int idx = hashID(itemID);

  if (idx == -1) { // hash function returns -1 if unable to hash.
    return nullptr;
  }

  return hashtable[idx];
  */

  // TODO
  return nullptr;
}

// Get an item by its pointer.
// Returns nullptr on fail.
template <typename T> T *HashTable<T>::get(T *item) {
  if (!(std::is_member_function_pointer<decltype(&T::getID)>::value)) {
    std::cout << "HashTable could not retrieve item without getID() function."
              << std::endl;
    return nullptr;
  }

  return getByID(item->getID());
}

// Prints array in order (excluding nullptrs)
template <typename T> void HashTable<T>::display() {
  // TODO
  std::cout << "HashTable display()." << std::endl;
}

// Returns the index for an item, but does not store it.
// Returns -1 if item is invalid.

/**
 * Hashes an item's ID.
 *
 * @para   An item with a getID() function.
 * @return An int representing the array index the item should be stored at.
 *         Returns -1 if item is invlaid, or if unable to hash it's ID.
 */
template <typename T> int HashTable<T>::hash(const T *item) {
  if (!(std::is_member_function_pointer<decltype(&T::getID)>::value)) {
    return -1;
  }

  int itemID = item->getID();
  return hashID(itemID);
}

/**
 * Hashes an ID.
 *
 * @para An int representing an item's ID
 * @return An int representing the array index the item should be stored at.
 *         Returns -1 if unable to hash.
 */
template <typename T> int HashTable<T>::hashID(int ID) {
  // TODO: Placeholder
  return ID % HASHTABLE_SIZE;
}

template <typename T> void HashTable<T>::printListAtIdx(int idx) {
  if (idx < 0 || idx > HASHTABLE_SIZE) {
    return;
  }

  std::cout << "HashTable list at idx " << idx << ":" << std::endl;

  TableItem<T> *currItem = hashtable[idx];
  int i = 0;

  while (currItem != nullptr && currItem->item != nullptr) {
    std::cout << "[" << i << ": " << currItem->item << "]-> ";
    i++;
  }
  std::cout << std::endl;
}

template class HashTable<Movie>;
template class HashTable<Customer>;