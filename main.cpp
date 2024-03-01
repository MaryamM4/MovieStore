// main.cpp

#include "store.h"

#include <iostream>

int main() {
  Store *store = new Store();

  std::string movies_filename = "data4movies.txt";
  std::string customers_filename = "data4customers.txt";
  std::string operations_filename = "data4commands.txt";

  store->initFromFiles(movies_filename, customers_filename,
                       operations_filename);

  return 0;
}

void parseCommands(std::fstream &file, std::vector<Operation *> &commands) {
  std::string line;
  while (std::getline(file, line)) {
    Operation *operation = Operation::buildCommand(line);
    commands.push_back(operation);
  }
}