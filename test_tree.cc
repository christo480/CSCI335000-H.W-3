// <Your name>
// Main file for Part 2.2 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"// You will have to add #include "sequence_map.h"

#include <iostream>
#include <string>
using namespace std;

namespace {


// @dbx_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &dbx_filename, const string &seq_filename, TreeType &a_tree)
{
  // Code for running Part 2.2
  std::cout<< "dbx_filename :" << dbx_filename<<std::endl;
  ifstream file(dbx_filename);
  string db_line; //read database line
  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);
  //a_tree.printTree();

  
  while (getline(file,db_line)) //GetNextLineFromDatabaseFile
  {    
    // Get the first part of the line:    
    string an_enz_acro = db_line;// GetEnzymeAcronym      
    string a_reco_seq;    
    while(getline(file, a_reco_seq))
    {
      sequence_map new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map);    
    }  // End second while.  
  }  // End first while.*/
  a_tree.printTree();

}

}  // namespace

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << dbx_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<int> a_tree;
  TestTree(dbx_filename, seq_filename, a_tree);

  return 0;
}
