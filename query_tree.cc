// <Your name>
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"// You will have to add #include "sequence_map.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace {

// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &dbx_filename, TreeType &a_tree) {
  // Code for running Part 2.1
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
  string search;
  cin>> search
  while(search!= "")
  {
    std::cout<<a_tree.GetEnzymeAcronym(search);
    cin>> search;
  }
}

}  // namespace

/*Tree<SequenceMap> a_tree; string db_line; // Read the file line-by-line: 
while (getline(db_line)) //GetNextLineFromDatabaseFile
  {    
    // Get the first part of the line:    
    string an_enz_acro = db_line;// GetEnzymeAcronym   
    string a_reco_seq;    
    while(getline(db_line, a_rego_seq)
    {
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map);    
    }  // End second while.  
  }  // End first while.*/ 
int main(int argc, char **argv) 
{
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<sequence_map> a_tree;
  QueryTree(dbx_filename, a_tree);//Sends file name and data to be read
  
  /*string db_line;
  while (getline(db_line)) //GetNextLineFromDatabaseFile
  {    
    // Get the first part of the line:    
    string an_enz_acro = db_line;// GetEnzymeAcronym   
    string a_reco_seq;    
    while(getline(db_line, a_rego_seq)
    {
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map);    
    }  // End second while.  
  }  // End first while.*/
  
  return 0;
}


