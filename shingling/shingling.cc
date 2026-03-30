#include <unordered_set>
#include "shingling.hpp"

vector<long long> shinglingText(const string& text, int kSize) {

  if ((int)text.size() < kSize) return {};

  unordered_set<long long> shingleSet;

  long long basePow{1};
  for (int i{}; i < kSize - 1; i++) {
    basePow = static_cast<long long>((__uint128_t)basePow * BASE % PRIME);
  }

  long long h{};
  for (int i{}; i < kSize; i++) {
    h = static_cast<long long>((__uint128_t)h * BASE + (unsigned char)text[i]) % PRIME;
  }
  shingleSet.insert(h);

  for (int i{kSize}; i < (int)text.size(); i++) {
    long long drop = static_cast<long long>((__uint128_t)basePow * (unsigned char)text[i - kSize] % PRIME);
    h = (h - drop + PRIME) % PRIME;
    h = static_cast<long long>((__uint128_t)h * BASE + (unsigned char)text[i]) % PRIME;
    shingleSet.insert(h);
  }

  return vector<long long>(shingleSet.begin(), shingleSet.end());
}
