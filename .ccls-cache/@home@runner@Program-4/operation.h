//
// Created by Andrew on 2/19/2024.
//

#pragma once

#include <string>

class Operation {
public:
  Operation() = default;
  virtual ~Operation() = default;

  // static factory method
  static Operation *buildCommand(std::string command);
  // if (command == "borrow") return new BorrowOperation;
  // ect...

  // virtual void execute() = 0;
};

class BorrowOperation : public Operation {
public:
  BorrowOperation(int customerID, int movieID)
      : customerID(customerID), movieID(movieID) {}

  int getCustomerID();
  int getMovieID();

private:
  int customerID;
  int movieID;
};

class ReturnOperation : public Operation {
public:
  ReturnOperation(int customerID, int movieID)
      : customerID(customerID), movieID(movieID) {}

  int getCustomerID();
  int getMovieID();

private:
  int customerID;
  int movieID;
};

class DisplayInventoryOperation : public Operation {};

class DisplayCustomerHistoryOperation : public Operation {
public:
  DisplayCustomerHistoryOperation(int customerID) : customerID(customerID) {}
  int getCustomerID();

private:
  int customerID;
};
