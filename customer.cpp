//
// Created by Andrew on 2/19/2024.
//

#include "customer.h"

Customer::Customer(int UID, std::string firstName, std::string lastName)
    : UID(UID), firstName(firstName), lastName(lastName) {

  // If  set to false, << also displays ID
  PRINT_ID = true;
}

int Customer::getID() const { return UID; }
std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  os << customer.getFirstName() << std::string(" ") << customer.getLastName();

  if (customer.PRINT_ID) {
    os << std::string(" [") << std::to_string(customer.getID())
       << std::string("]");
  }

  return os;
}