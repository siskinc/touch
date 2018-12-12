#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>


namespace fmt
{
    std::string format(std::string &format_str, std::vector<std::string> &string_list, std::map<std::string, std::string> string_map = {});
} // fmt

struct Node
{
    Node(char &value, int &index): index(index), value(value){}
    char value;
    int index;
};

class format_exception: std::exception
{
public:
    format_exception(const char * exception_str)
    {
        // std::cout << exception_str << std::endl; 
        this->exception_str = exception_str;
    }
    const char * what() const throw()
    {
        return this->exception_str.c_str();
    }
private:
    std::string exception_str = "";
};

std::string fmt::format(std::string &format_str, std::vector<std::string> &string_list, std::map<std::string, std::string> string_map)
{
    std::stringstream ss;
    std::stack<Node> symbols;
    auto cur_format_count = 0;
    int index = 0;
    auto str_list_size = string_list.size();
    std::string field_name;
    auto format_len = format_str.length();
    auto push_symbols = [&](int i) { symbols.push({format_str[i], i}); };
    auto get_str = [&](int i) -> std::string { if (str_list_size > i) return string_list[i]; return std::string(""); };
    for (int i = 0; i < format_len; ++i)
    {
        if (format_str[i] == '{')
        {
            if(symbols.empty())
            {
                push_symbols(i);
                continue;
            }
            auto last_symbol = symbols.top();
            if (last_symbol.value == '{' && last_symbol.index == i - 1)
            {
                ss << '{';
                symbols.pop();
                continue;
            }
            char buff[1024];
            memset(buff, 0x00, sizeof(buff));
            sprintf(buff, "In index %d, tow discontinuous '{' symbol exist but not match '}'.", i); 
            throw format_exception(buff);
        }
        if(format_str[i] == '}')
        {
            if (symbols.empty())
            {
                push_symbols(i);
            }
            auto last_symbol = symbols.top();
            if (last_symbol.value == '}' && last_symbol.index == i - 1)
            {
                ss << '}';
                symbols.pop();
                continue;
            }
            if (last_symbol.value == '{' && last_symbol.index == i - 1)
            {
                ss << get_str(cur_format_count);
                ++cur_format_count;
                symbols.pop();
                continue;
            }
            field_name = format_str.substr(last_symbol.index + 1, i - last_symbol.index - 1);
            if (string_map[field_name] != "")
            {
                ss << string_map[field_name];
                symbols.pop();
                continue;
            }
        }
        if(symbols.empty())
            ss << format_str[i];
    }
    return ss.str();
}
