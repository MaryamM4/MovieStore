//
// Created by Andrew on 2/19/2024.
//

#include "operation.h"

Operation *Operation::buildCommand(std::string command) { return nullptr; }

std::ostream &Operation::display(std::ostream &os) const {
  os << std::string("Operation");
  return os;
}

std::ostream &operator<<(std::ostream &os, const Operation &op) {
  op.display(os);
  return os;
}

// === Borrow Op.
int BorrowOperation::getCustomerID() const { return customerID; }
int BorrowOperation::getMovieID() const { return movieID; }

std::ostream &BorrowOperation::display(std::ostream &os) const {
  os << std::string("B ") << std::to_string(getCustomerID()) << std::string(" ")
     << std::to_string(getMovieID());
  return os;
}

// === Return Op.
int ReturnOperation::getCustomerID() const { return customerID; }
int ReturnOperation::getMovieID() const { return movieID; }

std::ostream &ReturnOperation::display(std::ostream &os) const {
  os << std::string("R ") << std::to_string(getCustomerID()) << std::string(" ")
     << std::to_string(getMovieID());
  return os;
}

// === Display Inventory Op.
std::ostream &DisplayInventoryOperation::display(std::ostream &os) const {

  os << std::string("I");
  return os;
}

// === Display Customer History Op.
int DisplayCustomerHistoryOperation::getCustomerID() const {
  return customerID;
}

std::ostream &DisplayCustomerHistoryOperation::display(std::ostream &os) const {

  os << std::string("H ") << std::to_string(getCustomerID());
  return os;
}