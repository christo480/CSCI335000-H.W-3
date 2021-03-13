// <Your name>
// Main file for Part 2.2 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"// You will have to add #include "sequence_map.h"
#include <fstream>
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
  
  std::cout <<"2. "<<a_tree.get_size()<<std::endl;
  std::cout <<"3a. "<< "Not Done"<<std::endl;
  /*
  string search_entry;
  for(int i=0;i<421;i++)
  {
    cin>> search_entry;
    std::cout<< search_entry;
    sequence_map entry(search_entry,"");
    if(a_tree.contains(entry))
      std::cout<<a_tree.find(entry).get_acronyms()<<endl;
    else
      std::cout<<"Not Found"<<endl;
    
  }
  */
  std::cout <<"4a. "<<a_tree.get_searches();
  
  std::cout <<std::endl;
  std::cout <<"4b. "<< "Not Done"<<std::endl;
  std::cout <<"5a. "<< "Not Done"<<std::endl;
  std::cout <<"5b. "<< "Not Done"<<std::endl;
  std::cout <<"6a. "<< "Not Done"<<std::endl;
  std::cout <<"6b. "<< "Not Done"<<std::endl;
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
  AvlTree<sequence_map> a_tree;
  TestTree(dbx_filename, seq_filename, a_tree);

  return 0;
}
