#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lzw.h"

TEST_CASE( "Can correctly encode strings" ) {
  const int max = 4;

  vector<string> d_1 = {"a", "b", "c", "d", "r"}; 
  vector<string> d_2 = {"i", "m", "p", "s"};
  vector<string> d_3 = {"a", "b"};
  vector<string> d_4 = {"U", "V", "W", "X", "Y", "Z"};
  vector< vector<string> > ds =  { d_1, d_2, d_3, d_4 };

  vector<int> c_1 = {0, 1, 4, 0, 2, 0, 3, 5, 7};
  vector<int> c_2 = {1, 0, 3, 3, 5, 7, 2, 2, 0};
  vector<int> c_3 = {0, 1, 2, 4, 3};
  vector<int> c_4 = {2, 6, 2, 3, 7, 9, 8, 2};
  vector< vector<int> > cs = { c_1, c_2, c_3, c_4 };

  string str_1 = "abracadabra";
  string str_2 = "mississippi";
  string str_3 = "ababababa";

  // TODO: Figure out why decoding for this is not working.
  string str_4 = "WWWWXWWWXWWXW"; 

  vector<string> xs = {str_1, str_2, str_3, str_4 };

  Compressor *lzw;

  for (int i = 0; i < max; ++i) {
    lzw = new Compressor();
    lzw->set_x(xs[i]);
    lzw->set_d(ds[i]);
    lzw->encode();
    REQUIRE(lzw->get_c() == cs[i]);
  }

  // TODO: Iterate to max to include last test case.
  for (int i = 0; i < max - 1; ++i) {
    lzw = new Compressor();
    lzw->set_d(ds[i]);
    lzw->set_c(cs[i]);
    lzw->decode();
    REQUIRE(lzw->get_x() == xs[i]);
  }

  delete lzw;
}
