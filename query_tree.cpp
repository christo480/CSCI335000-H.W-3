/*Tree<SequenceMap> a_tree; string db_line; // Read the file line-by-line: 
while (GetNextLineFromDatabaseFile(db_line)) 
{    
  // Get the first part of the line:    
  string an_enz_acro = GetEnzymeAcronym(db_line);    
  string a_reco_seq;    
  while(GetNextRecognitionSequence(db_line, a_rego_seq)
  {
     SequenceMap new_sequence_map(a_reco_seq, an_enz_acro); 
     a_tree.insert(new_sequence_map);    
  }  // End second while.  
}  // End first while. 
#include "avl_tree.h"
#include "sequence_map.h"
#include "query_tree.cc"

int main()
{
  AvlTree<sequence_map> a_tree; string db_line; // Read the file line-by-line: 
  while (GetNextLineFromDatabaseFile(db_line)) 
  {    
    // Get the first part of the line:    
    string an_enz_acro = GetEnzymeAcronym(db_line);    
    string a_reco_seq;    
    while(GetNextRecognitionSequence(db_line, a_rego_seq)
    {
      SequenceMap new_sequence_map(a_reco_seq, an_enz_acro); 
      a_tree.insert(new_sequence_map);    
    }  // End second while.  
  }  // End first while. 
}*/