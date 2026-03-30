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

long long minSignature(long long x){
  pair<long long, long long> hashInfo{genHashInfo};
  return (x*hashInfo.first+hashInfo.second) % PRIME;
}

void applyMinHash(const vector<vector<long long>>& shinglOfEachDocument, 
  vector<long long>& collsionBook){
    
    vector<long long> minValueOfEachDocument(shinglOfEachDocument.size());
    
    // compute all min value of all document 
    long long shinglSetIndex{};
    for (const auto& shinglSet : shinglOfEachDocument) {
      long long minValue{numeric_limits<long long>::max()};
      for (const auto& shingleSignature : shinglSet) {
        minValue = min(minValue, minSignature(shingleSignature));
      }
      minValueOfEachDocument.push_back(minValue);      
    }

    // i could optimized this to use triangle table.
    // compare to find collsion
    for (int i{};i<minValueOfEachDocument.size();i++) {
      for (int j{};j<minValueOfEachDocument.size();j++) {
        if()
      }
    }
}