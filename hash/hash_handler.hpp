#ifndef HASH_GENERATOR
#define HASH_GENERATOR 

#include "utility.hpp"

using namespace std;

void applyMinHash(const vector<vector<long long>>& shinglOfEachDocument, 
  vector<long long>& collsionBook);

#endif