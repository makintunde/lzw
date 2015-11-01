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
vector<int> encode(string x, vector<string> &d) {
  int n, m, k = 0, l = 1, p, i;

  //print_encode_instructions();
  //string x;
  //cin >> x;
  string sub;
  //vector<string> d;
  vector<string> s;
  vector<int> c;
  vector<string>::iterator it1, it2;

  //cin >> m;
  m = d.size();
  n = x.size();

  for ( i = 0; i < m; ++i ) { 
    //string next;
    //cin >> next;
    s.push_back(d[i]);
    //d.push_back(next);
  }

  // Iterate through string x.
  string w = "";
  stringstream ss;
  i = 0;
  for (auto c_it = x.begin(); c_it < x.end(); c_it++) {
    cout << "k: " << *c_it << endl;
    char k = *c_it;
    string next = w + k;
    cout << "next: " << next << endl;
    auto it = find(d.begin(), d.end(), next);
    if (it != d.end()) {
      w = next;
    } else {
      if (w.size() > 0) {
        cout << "w: " << w << endl;
        size_t p = distance(d.begin(), find(d.begin(), d.end(), w));
        cout << "p: " << p << endl;
        c.push_back(p);
      }
      d.push_back(w + k);
      print_results("c", c);
      print_str_results("d", d);
      ss.clear();
      ss.str(string());
      ss << k;
      ss >> w;
      cout << "new w: " << w << endl;
      if (c_it == x.end()-1) c.push_back(distance(d.begin(), find(d.begin(), d.end(), w)));
    }
  }
  //print_results("C", c);
  //print_results("D", d);
  return c;
}

void decode() {
  vector<string> d; // Dictionary.
  vector<int> c; // Code.
  int m;
  cout << "Enter:\n";
  cout << " - m (Number of elements in the dictionary)\n";
  cout << " - The entries of the dictionary." << endl;
  cin >> m;
  for ( int i = 0; i < m; ++i ) {
    string next;
    cin >> next;
    d.push_back( next );
  }

  cout << "Enter:\n";
  cout << " - n (The number of elements in the code)\n";
  cout << " - The n entries of the code." << endl;
  int n;
  string x;
  cin >> n;
  for (int i = 0; i < n; ++i ) {
    int next;
    cin >> next;
    c.push_back( next );
  }
  cout << endl;
  cout << "--------------------------------------" << endl;
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
  cout << "X: " << x << endl;
  // print_results("D", d);
} 

TEST_CASE( "Can correctly encode strings" ) {
  vector<string> vec_1 = {"a", "b", "c", "d", "r"}; 
  vector<string> vec_2 = {"i", "m", "p", "s"};
  vector<string> vec_3 = {"a", "b"};

  vector<int> exp_1 = {0, 1, 4, 0, 2, 0, 3, 5, 7};
  vector<int> exp_2 = {1, 0, 3, 3, 5, 7, 2, 2, 0};
  vector<int> exp_3 = {0, 1, 2, 4, 3};
  
  REQUIRE( encode( "mississippi", vec_2 ) == exp_2); // <- Not passing?
  REQUIRE( encode( "abracadabra", vec_1 ) == exp_1);
  REQUIRE( encode( "ababababa", vec_3 ) == exp_3);
}

// Implementation of LZW Encoding and Decoding.
//
// TODO: OOP version (to allow mocking?)
// TODO: Sort out testing framework.
/*
 * int main() {
  encode( string s, vector<string> &d );
  decode();
}
*/
