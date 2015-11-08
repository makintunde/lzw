#include "lzw.h"
// Implementation of LZW Encoding and Decoding.
// TODO: OOP version.

Compressor::Compressor() { x_ = ""; }

void Compressor::set_x(string x) { x_ = x; }

void Compressor::set_d(vector<string> d) { d_ = d; }

void Compressor::set_c(vector<int> c) { c_ = c; }

vector<int> Compressor::get_c() { return c_; }

vector<string> Compressor::get_d() { return d_; }

string Compressor::get_x() { return x_; }

void Compressor::encode() {
  string w = "";
  stringstream ss;

  // Iterate through string x.
  for (auto c_it = x_.begin(); c_it < x_.end(); c_it++) {
    char k = *c_it;
    string next = w + k;
    auto it = find(d_.begin(), d_.end(), next);

    if (it != d_.end()) {
      w = next;
      if (c_it == x_.end() - 1)
        c_.push_back(distance(d_.begin(), find(d_.begin(), d_.end(), w)));
    } else {
      if (w.size() > 0) {
        size_t p = distance(d_.begin(), find(d_.begin(), d_.end(), w));
        c_.push_back(p);
      }
      d_.push_back(w + k);

      // Ensure that string stream is cleared after each iteration.
      ss.clear();
      ss.str(string());

      // Converts k char to string.
      ss << k;
      ss >> w;

      if (c_it == x_.end() - 1)
        c_.push_back(distance(d_.begin(), find(d_.begin(), d_.end(), w)));
    }
  }
}

// Decode a code into its original string, given a dictionary and a code.
void Compressor::decode() {
  int n = c_.size();

  for ( int i = 0; i < n; ++i ) {
    x_.append( d_[c_[i]] );
    string s = "";
    s += d_[c_[i]];
    if (i < n - 1) {
      int index = c_[i + 1] % d_.size();
      s += d_[index].at( 0 );
    }
    d_.push_back( s );
  }
} 


