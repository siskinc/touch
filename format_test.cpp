#include <iostream>
#include <vector>
#include <map>
#include "format.hpp"

int main(int argc, char const *argv[])
{
    std::string format_str;
    std::string field_name, field_value;
    std::vector<std::string> string_list;
    std::map<std::string, std::string> string_map;
    std::string value;
    int string_list_size = 0;
    int string_map_size = 0;
    while (std::cin >> string_list_size >> string_map_size)
    {
        string_list.clear();
        string_map.clear();
        std::getline(std::cin, format_str);
        std::getline(std::cin, format_str);
        for (size_t i = 0; i < string_list_size; i++)
        {
            std::cin >> value;
            string_list.emplace_back(std::move(value));
        }
        for (size_t i = 0; i < string_map_size; i++)
        {
            std::cin >> field_name >> field_value;
            string_map[field_name] = field_value;
        }
        
        try
        {
            std::cout << format_str << std::endl;
            std::cout << fmt::format(format_str, string_list, string_map) << std::endl;
        }
        catch (const format_exception&e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
