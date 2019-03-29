#include "lib.h"

#include <string>
#include <algorithm>

void UrlEncode(std::string& str) {
    size_t spacesNum = std::count(str.begin(), str.end(), ' ');
    if (str.empty() || spacesNum == 0) {
        return;
    }
    str.resize(str.length() + 2 * spacesNum);
    auto writer = str.rbegin();
    for (auto reader = str.rbegin() + 2 * spacesNum; reader != str.rend(); ++reader) {
        if (*reader == ' ') {
            *writer++ = '0';
            *writer++ = '2';
            *writer++ = '%';
        } else {
            *writer++ = *reader;
        }
    }
}