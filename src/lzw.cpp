#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <bits/stdc++.h>

using namespace std;

void print_encode_instructions() {
  cout << "Enter:\n";
  cout << " - The string to encode\n";
  cout << " - n (length of the dictionary)\n";
  cout << " - The n dictionary entries." << endl;
}

void print_decode_instructions() {
  cout << "Enter:\n";
  cout << " - m (Number of elements in the dictionary)\n";
  cout << " - The entries of the dictionary." << endl;

  cout << "Enter:\n";
  cout << " - n (The number of elements in the code)\n";
  cout << " - The n entries of the code." << endl;
}

void print_str_results(string name, vector<string> &a) {
  cout << "--------------------------------------" << endl;
  cout << name << ": ";
  size_t n = a.size();
  for ( int i = 0; i < n - 1; ++i ) cout << a[i] << ", ";
  cout << a[ n - 1 ] << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;
}

void print_results(string name, vector<int> &a) {
  cout << "--------------------------------------" << endl;
  cout << name << ": ";
  size_t n = a.size();
  for ( int i = 0; i < n - 1; ++i ) cout << a[i] << ", ";
  cout << a[ n - 1 ] << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;
}

// Encode a string using LZW given a corresponding dictionary.
// TODO: Use an 'encoder' object with accessors for private code and 
// updated dictionary fields.
vector<int> encode(string x, vector<string> d) {
  int n, m, k = 0, l = 1, p, i;

  string sub;
  vector<string> s;
  vector<int> c;
  vector<string>::iterator it1, it2;

  m = d.size();
  n = x.size();

  // Iterate through string x.
  string w = "";
  stringstream ss;
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
  string x = "";
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

TEST_CASE( "Can correctly encode strings" ) {
  vector<string> d_1 = {"a", "b", "c", "d", "r"}; 
  vector<string> d_2 = {"i", "m", "p", "s"};
  vector<string> d_3 = {"a", "b"};

  vector<int> c_1 = {0, 1, 4, 0, 2, 0, 3, 5, 7};
  vector<int> c_2 = {1, 0, 3, 3, 5, 7, 2, 2, 0};
  vector<int> c_3 = {0, 1, 2, 4, 3};
  vector<int> c_4 = {0, 1, 0};
 
  // Encoding tests. 
  REQUIRE( encode( "abracadabra", d_1 ) == c_1);
  REQUIRE( encode( "mississippi", d_2 ) == c_2); 
  REQUIRE( encode( "ababababa", d_3 ) == c_3);
  REQUIRE( encode( "aba", d_3 ) == c_4);

  // Decoding tests.
  REQUIRE( decode( d_1, c_1 ) == "abracadabra" );
  REQUIRE( decode( d_2, c_2 ) == "mississippi" );
  REQUIRE( decode( d_3, c_3 ) == "ababababa" );
  REQUIRE( decode( d_3, c_4 ) == "aba" );
}

// Implementation of LZW Encoding and Decoding.
//
// TODO: OOP version (to allow mocking?)
/*
 * int main() {
  encode( string s, vector<string> &d );
  decode();
}
*/
