#include "lzw_utils.h"
#include <bits/stdc++.h>

using namespace std;

class Compressor {
public:
  Compressor();
  // Encode a string using LZW given a corresponding dictionary.
  // TODO: Use an 'encoder' object with accessors for private code and 
  // updated dictionary fields.
  void encode();

  // Decode a code into its original string, given a dictionary and a code.
  void decode();

  void set_x(string x);
  void set_d(vector<string> d);
  void set_c(vector<int> c);
  string get_x();
  vector<string> get_d();
  vector<int> get_c();

private:
  vector<int> c_; // The code.  
  vector<string> d_; // Dictionary.
  string x_;
};

