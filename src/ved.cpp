#include <iostream>
#include <cxxopts.hpp>

int main(int argc, char** argv)
{
    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    auto result = options.parse(argc, argv);
    return 0;
}

