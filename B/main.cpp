#include "main.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
    (void)argc;
    (void)argv;
    std::string url = "aba caba daba";
    UrlEncode(url);
    std::cerr << url << std::endl;

    std::cerr << GetSomeNumber() << std::endl;
}