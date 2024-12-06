#include "catch2/catch.hpp"
#include "Pixel.h"

TEST_CASE("Pixel works as expected", "[Pixel]")
{
    const auto p1 = Pixel();
    const auto p2 = Pixel(176);
    auto p3 = Pixel(219);

    REQUIRE(p1 != p2);
    REQUIRE((p1 & p2) == p1);
    REQUIRE((p1 | p2) == p2);
    p3 &= p1;
    REQUIRE(p3 == p1);
    p3 |= p2;
    REQUIRE(p3 == p2);
}
