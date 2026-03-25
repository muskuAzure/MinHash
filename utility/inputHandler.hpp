#ifndef INPUTHANDLER
#define INPUTHANDLER

#include <fstream>
#include <sstream>

#include "utility.hpp"
using namespace std;

/*
  - 1 Not support UTF-8 right now
*/

string readFile(const string& path);

#endif