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

  string str_1 = "abracadabra";
  string str_2 = "mississippi";
  string str_3 = "ababababa";
  string str_4 = "aba";
 
  // It must be the case that:
  // ( encode . decode ) x = id x
  // and
  // ( decode . encode ) x = id x
  REQUIRE( decode( d_1, encode( str_1, d_1 )) == str_1);
  REQUIRE( decode( d_2, encode( str_2, d_2 )) == str_2); 
  REQUIRE( decode( d_3, encode( str_3, d_3 )) == str_3); 
  REQUIRE( decode( d_3, encode( str_4, d_3 )) == str_4); 

  REQUIRE( encode( decode( d_1, c_1 ), d_1 ) == c_1 );
  REQUIRE( encode( decode( d_2, c_2 ), d_2 ) == c_2);
  REQUIRE( encode( decode( d_3, c_3 ), d_3 ) == c_3 );
  REQUIRE( encode( decode( d_3, c_4 ), d_3 ) == c_4 );
}
