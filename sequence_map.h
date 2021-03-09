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
  sequence_map(const string &a_rec_seq, const string &an_enz_acro)
  {
    recognition_sequence_ =a_rec_seq;
    enzyme_acronyms_ = vector<string>(1);
    enzyme_acronyms_.push_back(an_enz_acro);
  }
  bool operator<(const sequence_map &rhs) const
  {
    return this->recognition_sequence_<rhs.recognition_sequence_; 
  }
  bool operator>(const sequence_map &rhs) const
  {
    return this->recognition_sequence_>rhs.recognition_sequence_; 
  }
  bool has_recog(const string ene) const
  {
    for(string x : enzyme_acronyms)
    {
      if(x==ene)
        return true;
    }
    return false;
  }
  friend ostream& operator<<(ostream& os, const sequence_map& seq)
  {
    cout << seq.recognition_sequence_ ;
    for(string strand:seq.enzyme_acronyms_)
    {
      cout << strand<<"/";
    }
    cout <<"/";
    return os;
  }
  string getRecg()
  {
    return recognition_sequence_;
  }
  /*! SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
    /param @a_rec_seq
    /param @an_enz_acro
  */
  void Merge(const sequence_map &other_sequence)
  {
    for(int i =0; i< other_sequence.enzyme_acronyms_.size();i++)
    {
      this->enzyme_acronyms_.at(i) = this->enzyme_acronyms_.at(i)+ other_sequence.enzyme_acronyms_.at(i);
    }
  }
};