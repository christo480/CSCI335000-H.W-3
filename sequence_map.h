#include <iostream>
#include <vector>
#include <string>
using namespace std;
class sequence_map
{
  private:
    string recognition_sequence_ ;     
    vector<string> enzyme_acronyms_;
  public:
  /*! SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    /param @a_rec_seq
    /param @an_enz_acro
  */
  sequence_map(const string &a_rec_seq, const string &an_enz_acro);
  bool operator<(const sequence_map &rhs) const;
  friend ostream& operator<<(ostream& os, const sequence_map& seq);
  /*! SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    /param @a_rec_seq
    /param @an_enz_acro
  */
  void Merge(const sequence_map &other_sequence);

};