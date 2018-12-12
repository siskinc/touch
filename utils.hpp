#include <string>

#ifndef UTILS_HPP
#define  UTILS_HPP
std::string get_filename_suffix(std::string &filename)
{
    if(filename == "")
        return "";
    if(filename.length() >= 256)
        return "";
    int i;
    for(i = filename.length() - 1; i >= 0; --i)
    {
        if(filename[i] == '.')
            break;
    }
    if(i <= 0)
        return "";
    return filename.substr(i+1);
}

std::string get_filename(std::string &filepath)
{
    if (filepath == "")
        return "";
    if (filepath.length() >= 256)
        return "";
    int i;
    for(i = filepath.length() - 1; i >= 0; --i)
    {
        if(filepath[i] == '/')
            break;
    }
    if(i < 0)
        return filepath;
    return filepath.substr(i + 1);
}
#endif //UTILS_HPP
