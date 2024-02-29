// main.cpp

#include "customerdb.h"
#include "inventory.h"
#include "operation.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void parseCommands(std::fstream &file, std::vector<Operation *> &commands);

int main() {
  /**
  using namespace std;


  // You will design and implement a program that will initialize the contents
  // of the inventory from a file (data4movies.txt), the customer list from
  // another file (data4customers.txt), and then process an arbitrary sequence
  // of commands from a third file (data4commands.txt).
  const string inventoryFileName = "data4movies.txt";
  const string customerFileName = "data4customers.txt";
  const string commandFileName = "data4commands.txt";
  fstream file;

  // initialize inventory
  file.open(inventoryFileName);
  Inventory movieDB;
  movieDB.buildInventory(file);
  file.close();

  // initialize customer list
  file.open(customerFileName);
  CustomerDB customerDB;
  customerDB.buildDB(file);
  file.close();

  // initialize command list
  file.open(commandFileName);
  vector<Operation *> commands;
  parseCommands(file, commands);
  file.close();

  // process commands in sequence
  for (Operation *command : commands) {
    command->execute();
  }
  **/

  return 0;
}

void parseCommands(std::fstream &file, std::vector<Operation *> &commands) {
  std::string line;
  while (std::getline(file, line)) {
    Operation *operation = Operation::buildCommand(line);
    commands.push_back(operation);
  }
}