// store.h
/**
 * Store class manages a store with customers and inventory.
 */

#pragma once

#include "customerdb.h"
#include "inventory.h"
#include "operation.h"

#include <string>
#include <vector>

class Operation; // Forward declaration

class Store {
public:
  // Builds inventory, customer database, and vector of operations
  // based on instructions from files
  void initFromFiles(std::string movies_filename,
                     std::string customers_filename,
                     std::string operations_filename);

  // Executes operations in operations.
  void executeCommands();

private:
  std::vector<Operation *> operations;
  Inventory inventory;
  CustomerDB customers;

  void buildOperations(std::fstream &infile);
};
