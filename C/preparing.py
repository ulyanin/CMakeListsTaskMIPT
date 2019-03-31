#!/usr/bin/env python3

code = """
/**
 * @brief
 * encodes spaces in url inplace: ' ' --> '%20'
 *
 * @param str Input string to be encoded
 *
 * @return void
 *
 */
size_t GetSomeNumber() {
    return 42;
}
"""

with open("index.h", "w") as out_f:
    print(code, file=out_f)