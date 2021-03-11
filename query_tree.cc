// Christian Gillies
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"// You will have to add #include "sequence_map.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
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
    string extracted_line = db_line;      
    string an_enz_acro;
    string a_reco_seq;

  
    

    an_enz_acro= extracted_line.substr(0,extracted_line.find_first_of("/"));// GetEnzymeAcronym
    //cout<<an_enz_acro<<std::endl;
    extracted_line = extracted_line.substr(extracted_line.find_first_of("/")+1,extracted_line.size());
    int recog_count = std::count(extracted_line.begin(), extracted_line.end(),'/');
    
    for(int i =0;i<recog_count;i++)//while(extracted_line.substr(0,2)!="//")
    {
      a_reco_seq= extracted_line.substr(0,extracted_line.find_first_of("/"));
      extracted_line = extracted_line.substr(extracted_line.find_first_of("/")+1,extracted_line.size());
      
      //cout<<" "<<a_reco_seq<<std::endl;
     
      
      if(a_reco_seq!="" && an_enz_acro!="")
      {
        //cout<<a_reco_seq << " "<<an_enz_acro<<std::endl;
        sequence_map new_sequence_map(a_reco_seq, an_enz_acro);
        a_tree.insert(new_sequence_map);   
      }
      
       
    }  // End second while.  
  }  // End first while.*/
  
  //a_tree.printTree();
  
  string search;
  //cin>> search;
  //search!= "-1"
  while(cin>> search)
  {
    sequence_map entry(search,"");
    if(a_tree.contains(entry))
      std::cout<<a_tree.find(entry).get_acronyms()<<endl;
    else
      std::cout<<"Not Found"<<endl;
    
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


