#pragma once

#include <string>


/**
 * encodes spaces in url inplace: ' ' --> '%20'
 */
void UrlEncode(std::string& str);