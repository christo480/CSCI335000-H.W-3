#include <iostream>
#include "sequence_map.h"

int main() {
  std::cout << "Hello World!\n";
  sequence_map test = sequence_map("CACA","ACAC");
  std::cout << test <<std::endl;
  
  sequence_map test2 = sequence_map("CGGACA","ACACS");
  sequence_map test3 = sequence_map("CACHHA","ACADC");
  std::cout << test2 <<std::endl;
  std::cout << test3 <<std::endl;
  test2.Merge(test3);
  std::cout << test2 <<std::endl;
  
}