#include "lzw_utils.h"


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
