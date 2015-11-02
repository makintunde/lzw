#include "lzw_utils.h"
#include <bits/stdc++.h>

using namespace std;

// Encode a string using LZW given a corresponding dictionary.
// TODO: Use an 'encoder' object with accessors for private code and 
// updated dictionary fields.
vector<int> encode(string x, vector<string> d);

// Decode a code into its original string, given a dictionary and a code.
string decode(vector<string> d, vector<int> c);
