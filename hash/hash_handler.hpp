#ifndef HASH_GENERATOR
#define HASH_GENERATOR

#include "utility.hpp"

using namespace std;

inline int triangleIndex(int i, int j, int n) {
  return i * (2*n - i - 1) / 2 + (j - i - 1);
}

void applyMinHash(const vector<vector<long long>>& shinglOfEachDocument,
  vector<int>& collisionBook, int numHashes);

#endif
