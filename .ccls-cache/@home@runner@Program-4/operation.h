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

  virtual std::ostream &display(std::ostream &os) const;
  friend std::ostream &operator<<(std::ostream &os, const Operation &op);
};

class BorrowOperation : public Operation {
public:
  BorrowOperation(int customerID, int movieID)
      : customerID(customerID), movieID(movieID) {}

  int getCustomerID() const;
  int getMovieID() const;

  virtual std::ostream &display(std::ostream &os) const override;

private:
  int customerID;
  int movieID;
};

class ReturnOperation : public Operation {
public:
  ReturnOperation(int customerID, int movieID)
      : customerID(customerID), movieID(movieID) {}

  int getCustomerID() const;
  int getMovieID() const;

  virtual std::ostream &display(std::ostream &os) const override;

private:
  int customerID;
  int movieID;
};

class DisplayInventoryOperation : public Operation {
public:
  friend std::ostream &operator<<(std::ostream &os, const Operation &op);

  virtual std::ostream &display(std::ostream &os) const override;
};

class DisplayCustomerHistoryOperation : public Operation {
public:
  DisplayCustomerHistoryOperation(int customerID) : customerID(customerID) {}
  int getCustomerID() const;

  virtual std::ostream &display(std::ostream &os) const override;

private:
  int customerID;
};
