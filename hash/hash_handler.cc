#include <random>
#include <limits>
#include "hash_handler.hpp"

using namespace std;


pair<long long, long long> genHashInfo(){

  mt19937_64 rng(random_device{}());
  uniform_int_distribution<long long> distA(1, (1ULL << 61) - 2);
  uniform_int_distribution<long long> distB(1, (1ULL << 61) - 2);

  return {distA(rng), distB(rng)};
}

long long minSignature(long long x, long long a, long long b){
  return (x * a + b) % PRIME;
}

void applyMinHash(const vector<vector<long long>>& shinglOfEachDocument,
  vector<int>& collisionBook, int numHashes){

    int n{shinglOfEachDocument.size()};

    collisionBook.assign(n * (n-1) / 2, 0);

    for (int h{}; h < numHashes; h++) {
      pair<long long, long long> hashInfo{genHashInfo()};

      vector<long long> minValueOfEachDocument(n);
      for (int i{}; i < n; i++) {
        long long minValue{numeric_limits<long long>::max()};
        for (const auto& shingleSignature : shinglOfEachDocument[i]) {
          minValue = min(minValue, minSignature(shingleSignature, hashInfo.first, hashInfo.second));
        }
        minValueOfEachDocument[i] = minValue;
      }

      for (int i{}; i < n; i++) {
        for (int j{i+1}; j < n; j++) {
          if (minValueOfEachDocument[i] == minValueOfEachDocument[j]) {
            collisionBook[triangleIndex(i, j, n)]++;
          }
        }
      }
    }
}
