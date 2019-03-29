#!/usr/bin/env python3

code = """
size_t GetSomeNumber() {
    return 42;
}
"""

with open("index.h", "w") as out_f:
    print(code, file=out_f)