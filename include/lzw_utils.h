#ifndef LZW_UTILS_H
#define LZW_UTILS_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void print_encode_instructions();
void print_decode_instructions();
void print_str_results(string name, vector<string> &a);
void print_results(string name, vector<int> &a);

#endif /* LZW_UTILS_H */ 
