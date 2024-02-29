//
// Created by Andrew on 2/19/2024.
//

#include "operation.h"

Operation *Operation::buildCommand(std::string command) { return nullptr; }

int BorrowOperation::getCustomerID() { return customerID; }
int BorrowOperation::getMovieID() { return movieID; }

int ReturnOperation::getCustomerID() { return customerID; }
int ReturnOperation::getMovieID() { return movieID; }

int DisplayCustomerHistoryOperation::getCustomerID() { return customerID; }