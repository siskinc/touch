#include "parse_format_file.hpp"

int  main(int argc, char const *argv[])
{
    std::string a, filename = "parse_format_file_test.case";
    parse_format_file(filename, a);
    std::cout << a << std::endl;
    return 0;
}
