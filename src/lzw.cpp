#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <bits/stdc++.h>

using namespace std;

vector<int> encode(string x, vector<string> &d) {
  int n, m, k = 0, l = 1, p, i;

  cout << "Enter:\n";
  cout << " - The string to encode\n";
  cout << " - n (length of the dictionary)\n";
  cout << " - The n dictionary entries." << endl;

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
  while ( k + l < n ) {
    // Find longest substring of x starting at index k in d.
    sub = x.substr( k, l );
    it1 = find( d.begin(), d.end(), sub );
    while ( it1 != d.end() ) {
      it2 = it1;
      if ( k + l == n ) break;
      l++;
      sub = x.substr( k, l );
      it1 = find( d.begin(), d.end(), sub );
    }
    p = distance(d.begin(), it2);
    c.push_back( p );
    if ( k + l < n) {
      d.push_back( sub );
      k += l - 1;
      l = 1;
    }
  }
  
  cout << "--------------------------------------" << endl;
  cout << "C: ";
  for ( i = 0; i < c.size() - 1; ++i ) cout << c[i] << ", ";
  cout << c[ c.size() - 1 ] << endl;
  cout << endl << "D: ";
  for ( i = 0; i < d.size() - 1; ++i ) cout << d[i] << ", ";
  cout << d[ d.size() - 1 ] << endl;
  cout << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;
  return d;
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
  cout << "D: ";
  for ( int i = 0; i < d.size() - 1; ++i ) cout << d[i] << ", ";
  cout << d[d.size() - 1] << endl;
  cout << "--------------------------------------" << endl;
} 

TEST_CASE( "Can correctly encode the following string" "[encode]" ) {
  vector<string> vec_1 = {"a", "b", "c", "d", "r"}; 
  vector<string> vec_2 = {"i", "m", "p", "s"};

  REQUIRE( encode( "abracadabra", vec_1 ) == {0, 1, 4, 0, 2, 0, 3, 5, 7} );
  REQUIRE( encode( "missisippi", vec_2 ) == {1, 0, 3, 3, 5, 7, 2, 2, 0} );
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
