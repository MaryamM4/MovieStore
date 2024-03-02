// HashTable.h
/**
 * Template class for a hash table.
 * Implemented using arrays and pointers.
 *
 * Preconditions:
 *   All stored items must have a method called getID that returns an int.
 */

#pragma once

template <typename T> struct TableItem {
  T *item = nullptr;
  TableItem<T> *nextItem = nullptr;
};

template <typename T> class HashTable {
public:
  HashTable(); // Constructor. Initializes to empty TableItems.
  ~HashTable();

  // Add, remove, and get rely on hash function to locate it in the hastable.

  bool add(T *item);    // Add item to the hash table.
  bool remove(T *item); // Remove item from the hash table.

  // ID must match the result of the item's getID method.
  T *getByID(int itemID);
  T *get(T *item); // Get an item by its pointer.

  void display();

private:
  // Size of the hash table (prime).
  static const int HASHTABLE_SIZE = 1009; // 101 or 1009
  TableItem<T> *hashtable[HASHTABLE_SIZE];

  // Returns the index for an item based on ID. (Does not change hashtable)
  int hash(const T *item) const;
  int hashID(int ID) const;

  // Helper function. Returns true if 0 <= idx < HASHTABLE_SIZE
  bool outOfRange(int idx);

  // Helper print functions for testing purposes.
  void printListAtIdx(int idx);
  void printTable();
};
