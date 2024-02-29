// HashTable.h
/**
 * Template class for a hash table.
 * Implemented using arrays and pointers.
 *
 * Preconditions:
 *   All stored items must have a method called getID that returns an int.
 */

#pragma once

template <typename T> class HashTable {
public:
  HashTable(); // Constructor. Initializes all ptrs in hashtable to nullptr.
  ~HashTable();

  // Add, remove, and get rely on hash function to locate it in the hastable.

  bool add(T *item);    // Add item to the hash table.
  bool remove(T *item); // Remove item from the hash table.

  // ID must match the result of the item's getID method.
  T *getByID(int itemID);
  T *get(T *item); // Get an item by its pointer.

  void display();

private:
  static const int MAXSIZE = 100; // Maximum size of the hash table.
  T *hashtable[]; // Array of pointers to items in the hash table.

  // Returns the index for an item, but does not store it.
  int hash(const T *item);
  int hashID(int ID);

  int probeNext(int currIdx, int i);
};
