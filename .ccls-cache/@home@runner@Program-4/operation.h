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

class BorrowOperation : public Operation {};

class ReturnOperation : public Operation {};

class DisplayInventoryOperation : public Operation {};

class DisplayCustomerHistoryOperation : public Operation {};
