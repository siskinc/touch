#include <iostream>
#include <stdlib.h>
#include "format_help.hpp"
#include "cmdline/cmdline.h"
#include "utils.hpp"
#include "parse_format_file.hpp"

#define DEFAULT_PATH "/.touch/"

int main(int argc, char **argv)
{
    cmdline::parser cmdline_parser;
    cmdline_parser.add<std::string>("file", "f", "touch file path", false, "");
    cmdline_parser.add<std::string>("template", "t", "touch file format template", false, "");
    cmdline_parser.add("format_help", "fp", "write format template file help");
    cmdline_parser.parse_check(argc, argv);
    auto filename = cmdline_parser.get<std::string>("file");
    auto template_name = cmdline_parser.get<std::string>("template");
    if (cmdline_parser.exist("format_help") || argc < 2)
    {
        print_format_help();
        return 0;
    }
    if (argc == 2)
    {
        filename = argv[1];
    }
    if (template_name == "")
    {
        template_name = get_filename_suffix(filename);
    }
    if(template_name == "")
    {
        std::cerr << "filename is invalid" << std::endl;
        return -1;
    }
    template_name = std::string(getenv("HOME")) + DEFAULT_PATH + template_name;
    std::string result = "";
    std::vector<std::string> string_list;
    std::map<std::string, std::string> string_map;
    string_map[FILENAME] = get_filename(filename);
    try
    {
        parse_format_file(template_name, string_list, string_map, result);
    }
    catch (const format_exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::ofstream fout(filename);
    fout << result;
    fout.close();
}
