#include "hash_table.h"

int main() {
  HashTable<int, std::string> hashTable;

  hashTable.Insert(1, "one");
  hashTable.Insert(2, "two");
  hashTable.Insert(3, "three");

  std::string value;
  for (int key = 1; key <= 3; ++key) {
    if (hashTable.Get(key, value)) {
      std::cout << "Value for key " << key << ": " << value << std::endl;
    } else {
      std::cout << "Key " << key << " not found" << std::endl;
    }
  }
  return 0;
}