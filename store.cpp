#include "store.h"

void Store::initFromFiles(std::string movies_filename,
                          std::string customers_filename,
                          std::string operations_filename) {

  std::fstream file;

  // Build customer database
  file.open(customers_filename);
  customers.buildDB(file);
  file.close();

  // Build movie inventory
  file.open(movies_filename);
  inventory.buildInventory(file);
  file.close();

  // Build operations vector
  file.open(movies_filename);
  // TODO
  file.close();
}

// Executes operations in operations.
void Store::executeCommands() {}