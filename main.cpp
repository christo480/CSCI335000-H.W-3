#include <iostream>
#include "sequence_map.h"
#include "avl_tree.h"
#include <string>
#include <fstream>
/*
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
  std::cout << (test2<test) <<std::endl;
}
*/


// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &dbx_filename, TreeType &a_tree) {
  // Code for running Part 2.1
  std::cout<< "dbx_filename :" << dbx_filename<<std::endl;
  std::string real_file_name = dbx_filename;
  std::ifstream file;
  file.open(real_file_name);
  string db_line; //read database line
  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);
  //a_tree.printTree();

  
  while (std::getline(file,db_line)) //GetNextLineFromDatabaseFile
  {    
    // Get the first part of the line:    
    string an_enz_acro = db_line;// GetEnzymeAcronym      
    string a_reco_seq;    
    while(std::getline(file, a_reco_seq))
    {
      sequence_map new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map);    
    }  // End second while.  
  }  // End first while.*/
  string query;
  cin>> query;
  while(query!="")
  {
    std::cout << a_tree.get_acronym(query);
    cin>> query;
  }
}

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
  std::ifstream file;

  
  return 0;
}