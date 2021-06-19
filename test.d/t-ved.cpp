#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <vector>

TEST_CASE( "Catch runs", "[single-file]" ) {
    REQUIRE( 1 == 1 );
}
