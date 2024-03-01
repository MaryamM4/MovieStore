//
// Created by Andrew on 2/19/2024.
//

#include "customer.h"

Customer::Customer(int UID, std::string firstName, std::string lastName)
    : UID(UID), firstName(firstName), lastName(lastName) {}

int Customer::getID() const { return UID; }