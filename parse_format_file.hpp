#include <fstream>
#include <map>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "format.hpp"

#define YEAR        "YEAR"
#define MONTH       "MONTH"
#define DAY         "DAY"
#define HOUR        "HOUR"
#define MINUTE      "MINUTE"
#define SECOND      "SECOND"
#define TIME        "TIME"
#define DATE        "DATE"
#define USER        "USER"
#define FILENAME    "FILENAME"

#define FIELDS { YEAR, MONTH, DAY, HOUR, MINUTE, SECOND, TIME, DATE, USER }
#define FIELD_VALUES { year, month, day, hour, minute, second, ltime, date, user }

/*
 ** filename: template filename
 ** result: format result string
*/
void parse_format_file(std::string &filename, std::vector<std::string> &string_list, std::map<std::string, std::string> &string_map, std::string &result)
{
    if(filename == "")
        return;
    std::stringstream strbuff;
    time_t now  = time(0);
    tm  *ltm    = localtime(&now);
    auto year   = std::to_string(ltm->tm_year + 1900);
    auto month  = std::to_string(ltm->tm_mon + 1);
    auto day    = std::to_string(ltm->tm_mday);
    auto hour   = std::to_string(ltm->tm_hour);
    auto minute = std::to_string(ltm->tm_min);
    auto second = std::to_string(ltm->tm_sec);
    char date[11];
    char ltime[20];
    strftime(date, sizeof(date), "%Y-%m-%d", ltm);
    strftime(ltime, sizeof(ltime), "%Y-%m-%d %H:%M:%S", ltm);
    auto user = getlogin();
    std::vector<std::string>    fields              = FIELDS;
    std::vector<std::string>    field_values        = FIELD_VALUES;
    auto                        field_len           = fields.size();
    auto                        field_value_len     = field_values.size();
    if (field_len != field_value_len)
    {
        throw format_exception("field name size and field value size not match.");
    }
    for (int i = 0; i < field_len; ++i)
    {
        string_map[fields[i]] = field_values[i];
    }
    std::ifstream fin(filename);
    if(!fin)
    {
        return;
    }
    std::string line;
    while(!fin.eof())
    {
        std::getline(fin, line, '\n');
        strbuff << fmt::format(line, string_list, string_map) << '\n';
    }
    result = strbuff.str();
}