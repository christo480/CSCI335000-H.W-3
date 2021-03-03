 #ifndef sequence_map_h
 #define sequence_map_h
#include "sequence_map.h"

  /*! SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    /param @a_rec_seq
    /param @an_enz_acro
  */
  sequence_map::sequence_map(const string &a_rec_seq, const string &an_enz_acro)
  {
    recognition_sequence_ =a_rec_seq;
    enzyme_acronyms_ = vector<string>(1);
    enzyme_acronyms_.push_back(an_enz_acro);
  }
  bool sequence_map::operator<(const sequence_map &rhs) const
  {
    return this->recognition_sequence_<rhs.recognition_sequence_; 
  }
  ostream& operator<<(ostream& os, const sequence_map& seq)
  {
    cout << seq.recognition_sequence_ <<"/";
    for(string strand:seq.enzyme_acronyms_)
    {
      cout << strand<<"/";
    }
    cout <<"/";
    return os;
  }
  /*! SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    /param @a_rec_seq
    /param @an_enz_acro
  */
  void sequence_map::Merge(const sequence_map &other_sequence)
  {
    for(int i =0; i< other_sequence.enzyme_acronyms_.size();i++)
    {
      this->enzyme_acronyms_.at(i) = this->enzyme_acronyms_.at(i)+ other_sequence.enzyme_acronyms_.at(i);
    }
  }
  #endif //end of class