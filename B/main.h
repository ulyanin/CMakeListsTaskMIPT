#pragma once

#include "A/lib.h"
#include "C/index.h"

/*! \mainpage Index page of cmake project task2
 *
 * \section intro_sec Introduction
 *
 * This documentation for task2
 * you can also see mylib documentation
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Create build dir
 * ```bash
 * mkdir build
 * cd build
 * ```
 * \subsection step2 Step 2: make project
 * ```bash
 * make
 * ```
 *
 * \subsection step3 Step 3: launch project
 * ```bash
 * ./task2
 *
 * ```
 * \subsection step4 Open generated doc
 * ```bash
 * xdg-open ../doc/task2/html/index.html
 * xdg-open ../doc/mylib/html/index.html
 * ```
 *
 * etc...
 */


/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
int main(int argc, const char** argv);