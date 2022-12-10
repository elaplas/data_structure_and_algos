#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


/**
 * we have the following dependencies, write a function to return the right order of building
 *
 * A depends on B and C
 * B depends on D
 * C depends on D
 * D depends on nothing
 *
 * the building orders could be D->C->B->A or D->B->C->A
 */


/**
 *
 * elegant solution:
 * make a graph from dependencies and
 * perform topological sorting,
 *
 * why we need topological sorting ?
 * because after topological sorting, it is possible to find
 * the right order (building/dependency order) in a graph configurations with any configurations
 *
 */



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
