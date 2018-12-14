#include "parse_format_file.hpp"

int  main(int argc, char const *argv[])
{
    std::string a, filename = "parse_format_file_test.case";
    std::vector<std::string> string_list;
    std::map<std::string, std::string> string_map;
    parse_format_file(filename, string_list, string_map, a);
    std::cout << a << std::endl;
    return 0;
}
