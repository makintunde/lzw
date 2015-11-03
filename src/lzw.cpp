#include "lzw.h"
// Implementation of LZW Encoding and Decoding.
// TODO: OOP version (to allow mocking?)

vector<int> encode(string x, vector<string> d) {
  vector<int> c;
  string w = "";
  stringstream ss;
  int m = d.size();
  int n = x.size();

  // Iterate through string x.
  for (auto c_it = x.begin(); c_it < x.end(); c_it++) {
    char k = *c_it;
    string next = w + k;
    auto it = find(d.begin(), d.end(), next);

    if (it != d.end()) {
      w = next;
      if (c_it == x.end() - 1)
        c.push_back(distance(d.begin(), find(d.begin(), d.end(), w)));
    } else {
      if (w.size() > 0) {
        size_t p = distance(d.begin(), find(d.begin(), d.end(), w));
        c.push_back(p);
      }
      d.push_back(w + k);

      // Ensure that string stream is cleared after each iteration.
      ss.clear();
      ss.str(string());

      // Converts k char to string.
      ss << k;
      ss >> w;

      if (c_it == x.end() - 1)
        c.push_back(distance(d.begin(), find(d.begin(), d.end(), w)));
    }
  }
  return c;
}

// Decode a code into its original string, given a dictionary and a code.
string decode(vector<string> d, vector<int> c) {
  int m = d.size();
  int n = c.size();
  string x;

  for ( int i = 0; i < n; ++i ) {
    x.append( d[c[i]] );
    string s = "";
    s += d[c[i]];
    if (i < n - 1) {
      int index = c[i + 1] % d.size();
      s += d[index].at( 0 );
    }
    d.push_back( s );
  }
  return x;
} 


