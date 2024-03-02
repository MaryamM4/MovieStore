//
// Created by Andrew on 2/19/2024.
//

#include "customerdb.h"

#include <iostream>
#include <sstream>

/**
 * @note: Each line in the input file must be formatted as:
 *        <UID : 4-digit int> <last name : string> <first name : string>
 *        Lines that are faulty or incomplete will be skipped.
 **/
void CustomerDB::buildDB(std::fstream &infile) {
  int UID;
  std::string firstName;
  std::string lastName;

  std::string currLine;
  while (std::getline(infile, currLine)) {
    std::istringstream iss(currLine);

    if (!(iss >> UID >> lastName >> firstName)) {
      std::cout << "Failed to add customer:\n" << currLine << "\n" << std::endl;
      continue; // Skip line on fail

    } else {
      Customer *newCustomer = new Customer(UID, firstName, lastName);

      // Don't add duplicates
      if (customers.getByID(UID) == nullptr) {
        customers.add(newCustomer);
      }
    }
  }
}

/**
 * Retrieves a customer from the database by thier ID.
 *
 * @return A pointer to the customer, or nullptr if not found.
 **/
Customer *CustomerDB::getCustomer(int customerID) {
  return customers.getByID(customerID);
}