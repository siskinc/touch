#include <string>
#include <iostream>
std::string format_help = "-------------------------\n"
                          "TIME: The file create time.\n"
                          "USER: The operate linux user.\n"
                          "DATE: The file create data.\n"
                          "YEAR: -\n"
                          "MONTH: -\n"
                          "DAY: -\n"
                          "HOUR: -\n"
                          "MINUTE: -\n"
                          "SECOND: -\n"
                          "FILENAME: -\n"
                          "--------------------------\n";

void print_format_help()
{
    std::cout << format_help << std::endl;
}