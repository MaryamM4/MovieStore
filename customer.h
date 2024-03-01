// customer.h
/**
 * The customer class only stores information about the customer themselves.
 * Customer operations are managed by the Operation class.
 */

#pragma once
#include <string>

class Customer {
public:
  // UID must be given to constructor to prevent overlapping IDs in DBs.
  // Constructor initializes a UID.
  Customer(int userID, std::string firstname, std::string lastname);

  int getID() const;

private:
  int UID; // 4-digit identification
  std::string firstName;
  std::string lastName;
};
