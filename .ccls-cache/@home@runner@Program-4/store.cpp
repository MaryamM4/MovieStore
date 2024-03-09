#include "store.h"

#include <iostream>
#include <sstream>
#include <string>

/**
 * Build customer database, movie inventory, and operations file
 * based on instructions from corresponding files.
 */
void Store::initFromFiles(std::string movies_filename,
                          std::string customers_filename,
                          std::string operations_filename) {

  std::fstream file;

  // Build customer database
  std::cout << "\n===========================" << std::endl; // DELETE ME
  std::cout << "======== CUSTOMERS ========" << std::endl;   // DELETE ME
  std::cout << "---------------------------\n" << std::endl; // DELETE ME
  file.open(customers_filename);
  if (file.is_open()) {
    std::cout << "Store succesfully opened customer file.\n"
              << std::endl; // DELETE ME
    customers.buildDB(file);
    file.close();

  } else {
    std::cout << "Invalid customers build file: " << customers_filename
              << std::endl;
  }

  // Build movie inventory
  std::cout << "\n===========================" << std::endl; // DELETE ME
  std::cout << "========= MOVIES =========" << std::endl;    // DELETE ME
  std::cout << "---------------------------\n" << std::endl; // DELETE ME
  file.open(movies_filename);
  std::cout << "Store succesfully opened movie file.\n"
            << std::endl; // DELETE ME
  if (file.is_open()) {
    inventory.buildInventory(file);
    file.close();

  } else {
    std::cout << "Invalid movies build file: " << movies_filename << std::endl;
  }

  // Build operations vector
  std::cout << "\n===========================" << std::endl; // DELETE ME
  std::cout << "======= OPERATIONS ========" << std::endl;   // DELETE ME
  std::cout << "---------------------------\n" << std::endl; // DELETE ME
  file.open(operations_filename);
  if (file.is_open()) {
    std::cout << "Store succesfully opened operation file.\n"
              << std::endl; // DELETE ME
    buildOperations(file);
    file.close();
  } else {
    std::cout << "Invalid operations build file: " << operations_filename
              << std::endl;
  }
}

/**
 * @note buildOperations only determines if the info in each line
 *       is valid. Does not check if customers/movies exist.
 */
void Store::buildOperations(std::fstream &infile) {
  char operationType;
  char mediaType;
  int customerID;
  int movieID;

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

        invalidLine = false;
        break;

      case 'H': // Display history of customer
        if (iss >> customerID) {
          op = new DisplayCustomerHistoryOperation(customerID);

          invalidLine = false;
        }

        break;

      case 'B': // Borrow
        if (iss >> customerID >> mediaType) {
          std::ostringstream oss;
          Movie *movie = MovieFactory::determineMovie(oss.str());

          if (movie != nullptr) {
            movieID = movie->getID();
            op = new BorrowOperation(customerID, movieID);

            delete movie;
            movie = nullptr;

            invalidLine = false;
          }
        }
        break;

      case 'R': // Return
        if (iss >> customerID >> mediaType) {
          std::ostringstream oss;
          Movie *movie = MovieFactory::determineMovie(oss.str());

          if (movie != nullptr) {
            movieID = movie->getID();
            op = new ReturnOperation(customerID, movieID);

            delete movie;
            movie = nullptr;

            invalidLine = false;
          }
        }
        break;

      default: // Invalid command type.
        invalidLine = true;
      }
    }

    if (invalidLine) {
      std::cout << "Invalid operation file line:\n"
                << currLine << "\n"
                << std::endl;

    } else {
      operations.push_back(op);
    }
  }
}

/**
 * Executes operations in operations.
 *
 * @pre operations vector should have already been built.
 */
void Store::executeCommands() {
  Operation *op;

  for (int i = 0; i < operations.size(); i++) {
    op = operations[i];
    std::cout << "Executing operation: " << *op << std::endl; // DELETE ME
  }
}