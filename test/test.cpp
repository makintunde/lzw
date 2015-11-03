#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lzw.h"

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
