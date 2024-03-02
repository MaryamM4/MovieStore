//
// Created by Andrew on 2/19/2024.
//

#include "customer.h"

Customer::Customer(int UID, std::string firstName, std::string lastName)
    : UID(UID), firstName(firstName), lastName(lastName) {}

int Customer::getID() const { return UID; }
std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  os << customer.getFirstName() << std::string(" ") << customer.getLastName();
  return os;
}