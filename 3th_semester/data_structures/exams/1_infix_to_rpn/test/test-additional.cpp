#include <iostream>
#include "catch2/catch_all.hpp"
#include "solution.h"

// TODO If you want to add additional tests, write them in this file

void checkResult1(std::string infix1, Associativity associativity, std::string expectedRpn) {
    std::cout << toRpn(infix1, associativity) << std::endl;
    CHECK(toRpn(infix1, associativity) == expectedRpn);
}

TEST_CASE("Sample test")
{
//    checkResult1("2/3/4+5/6/7", Associativity::Left, "23/4/56/7/+");
//    checkResult1("2/3/4+5/6/7", Associativity::Right, "234//567//+");
//    checkResult1("2+3+4/5+6+7", Associativity::Left, "23+45/+6+7+");
//    checkResult1("2+3+4/5+6+7", Associativity::Right, "2345/67++++");


    checkResult1("1+2*3^4*5+6+7*8^9+0-1+2", Associativity::Left, "1234^*5*+6+789^*+0+1-2+");
//    checkResult1("1+2*3^4*5+6+7*8^9+0-1+2", Associativity::Right, "1234^5**6789^*012+-++++");
}