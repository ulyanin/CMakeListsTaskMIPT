#include "main.h"

#include <iostream>
#include <string>

int main()
{
    std::string url = "aba caba daba";
    UrlEncode(url);
    std::cerr << url << std::endl;
}