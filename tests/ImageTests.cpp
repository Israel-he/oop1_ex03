#include "catch2/catch.hpp"

#include "Image.h"

TEST_CASE("Image supports basic operations", "[Image]")
{
    const auto img1 = Image(5, 2);
    const auto img2 = Image(2, 5);

    SECTION("GetHeight, GetWidth works")
    {
        REQUIRE(img1.GetHeight() == 5);
        REQUIRE(img1.GetWidth() == 2);
    }

    SECTION("basic + operations works")
    {
        REQUIRE((img1 + img1).GetHeight() == 5);
        REQUIRE((img1 + img1).GetWidth() == 4);
    }

    SECTION("copy operations work")
    {
        auto img3 = img1;
        REQUIRE(img3 == img1);
    }
}

TEST_CASE("Empty Image", "[Image]")
{
    const auto img1 = Image();
    const auto img2 = Image(2, 5);

    REQUIRE(img1.GetHeight() == 0);
    REQUIRE(img1.GetWidth() == 0);

    SECTION("operations on empty Image")
    {
        SECTION("adding empty Image")
        {
            REQUIRE((img1 + img2).GetWidth() == 5);
        }

        //.....
    }

}
