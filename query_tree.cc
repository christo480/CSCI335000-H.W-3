// <Your name>
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
// You will have to add #include "sequence_map.h"

#include <iostream>
#include <string>
using namespace std;

namespace {

// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &dbx_filename, TreeType &a_tree) {
  // Code for running Part 2.1
  // You can use public functions of TreeType. For example:
  a_tree.insert(10);
  a_tree.printTree();
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<int> a_tree;
  QueryTree(dbx_filename, a_tree);
  return 0;
}
