#pragma once

#include <string>


/**
 * @brief
 * encodes spaces in url inplace: ' ' --> '%20'
 *
 * @param str Input string to be encoded
 *
 * @return void
 *
 */
void UrlEncode(std::string& str);