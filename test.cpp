
#include "int_ptr.hpp"

#include "catch.hpp"

TEST_CASE("int_ptr can be default-constructed")
{
    int_ptr p{};
    REQUIRE(p.ptr == nullptr);
}

TEST_CASE("int_ptr can be constructed from int")
{
    int_ptr p{1};
    REQUIRE(p.ptr != nullptr);
    REQUIRE(*p.ptr == 1);
}

TEST_CASE("int_ptr can be copy-constructed")
{
    int_ptr p{22};
    int_ptr p2 = p;
    REQUIRE(p2.ptr);
    REQUIRE(*p2.ptr == 22);
}

TEST_CASE("int_ptr can be copy-assigned")
{
    int_ptr p{11};
    int_ptr p2{};
    p2 = p;
    REQUIRE(p2.ptr);
    REQUIRE(*p2.ptr == 11);
}

TEST_CASE("int_ptr can be dereferenced")
{
    int_ptr p{11};
    REQUIRE(p.ptr);
    REQUIRE(*p == 11);
}

TEST_CASE("int_ptr can be reset")
{
    int_ptr p{22};
    p.reset();
    REQUIRE(p.ptr == nullptr);
}

TEST_CASE("int_ptr can be reset (2)")
{
    int_ptr p{22};
    p.reset(new int{44});
    REQUIRE(p.ptr);
    REQUIRE(*p.ptr == 44);
}

TEST_CASE("int_ptr can be converted to bool")
{
    int_ptr p{};
    REQUIRE_FALSE(p);

    int_ptr p2{11};
    REQUIRE(p2);
}
