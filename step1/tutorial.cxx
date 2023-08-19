#include <iostream>
#include <cmath>
#include <string>

#include "TurtorialConfig.h"

int main(int argc, const char **argv)
{
    const double value = std::stod(argv[1]);
    std::cout << std::sqrt(value) << std::endl;
    std::cout << Tutorial_VERSION_MAJOR << std::endl;
    std::cout << Tutorial_VERSION_MINOR << std::endl;
    std::cout << FUNCK_HAHA << std::endl;
}