#ifndef SHINGLING
#define SHINGLING 

#include "utility.hpp"
using namespace std;

constexpr char PAD_CHAR{'$'};

// look into std::string with small string optimization (SSO)
// i can't use array becasue i know k at run time
vector<long long> shinglingText(const string& text, int kSize);

#endif