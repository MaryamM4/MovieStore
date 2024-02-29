#include "store.h"

#include <iostream>
#include <sstream>

/**
 * Build customer database, movie inventory, and operations file
 * based on instructions from corresponding files.
 */
void Store::initFromFiles(std::string movies_filename,
                          std::string customers_filename,
                          std::string operations_filename) {

  std::fstream file;

  // Build customer database
  file.open(customers_filename);
  if (file.is_open()) {
    customers.buildDB(file);
    file.close();

  } else {
    std::cout << "Invalid customers build file: " << customers_filename
              << std::endl;
  }

  // Build movie inventory
  file.open(movies_filename);
  if (file.is_open()) {
    inventory.buildInventory(file);
    file.close();

  } else {
    std::cout << "Invalid movies build file: " << movies_filename << std::endl;
  }

  // Build operations vector
  file.open(movies_filename);
  if (file.is_open()) {
    buildOperations(file);
    file.close();
  } else {
    std::cout << "Invalid operations build file: " << operations_filename
              << std::endl;
  }
}

/**
 *
 */
void Store::buildOperations(std::fstream &infile) {
  char operationType;
  char movieType;
  char mediaType;
  int customerID;

  Operation *op;
  bool invalidLine;
  std::string currLine;
  while (std::getline(infile, currLine)) {
    invalidLine = true;

    std::istringstream iss(currLine);
    if (iss >> operationType) {
      switch (operationType) {

      case 'I': // Display inventory operation
        op = new DisplayInventoryOperation();
        operations.push_back(op);
        invalidLine = false;

      case 'H': // Display history of customer
        if (iss >> customerID) {
          op = new DisplayCustomerHistoryOperation(customerID);
          operations.push_back(op);
          invalidLine = false;
        }

      case 'B': // Borrow
        if (iss >> customerID >> mediaType >> movieType) {
        }

      case 'R': // Return

      default: // Invalid command type.
        invalidLine = true;
      }
    }
  }
}

/**
 * Executes operations in operations.
 *
 * @pre operations vector should have already been built.
 */
void Store::executeCommands() {}