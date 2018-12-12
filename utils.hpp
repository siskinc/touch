#include <string>

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