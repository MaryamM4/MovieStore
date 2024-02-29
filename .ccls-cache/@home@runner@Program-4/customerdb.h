// customerdb.h
/**
 * Customer Database class.
 * Manages a collection of customers using a hashtable.
 */

#pragma once

#include "customer.h"
#include "hashtable.h"

#include <fstream>
#include <string>

class CustomerDB {
public:
  // Builds the customer database from a file.
  void buildDB(std::fstream &infile);

  // Returns a pointer of the customer from the database by thier ID.
  // Returns nullptr if not found.
  Customer *getCustomer(int customerID);

private:
  HashTable<Customer> customers;
};