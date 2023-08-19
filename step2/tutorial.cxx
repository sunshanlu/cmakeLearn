#include "MathFunctions.h"
#include <iostream>

int main(int argc, const char **argv)
{
    std::cout << MathFunctions::sqrt(100) << std::endl;
    std::cout << MathFunctions::add(100, 200) << std::endl;
    std::cout << MathFunctions::sub(100, 50) << std::endl;
    std::cout << MathFunctions::mul(10, 10) << std::endl;

    return 0;
}
