#include "shingling.hpp"

/* 
  +1 how to deal with shingl that does not have enough character. 
     HERE: use special char to pad it "$"
  -2 i will just use substr instead of string view for eash of coding
    if i have time i will come back and make another version and test
    if it better. 
    
*/
vector<long long> stringSignatureSetup(const set<string>& shingleSet) {
  vector<long long>signatureVector{};
  auto it{shingleSet.begin()};
  long long signature{};
  
  int i{(*it).length()};
  long long front{(*it).front()*static_cast<long long>(pow(BASE,i-1))};
  // implement hold first char for delete
  for( auto character : *it) {
    signature+=character * static_cast<long long>(pow(BASE,--i)) % PRIME;
  }

  signatureVector.push_back(signature);
  it++;

  // rolling hash 
  for(;it!=shingleSet.end();it++){
    signature=(signature-front + (*it).back()) * BASE;
    front=pow(BASE,(*it).length()-1) * (*it).front();
  }

  return signatureVector;
}


vector<long long> shinglingText(const string& text, int kSize) {

  set<string> setOfshingle;

  for(long long startIndex{};startIndex<text.size();startIndex+=1){
    string shingeler{padString(text.substr(startIndex, kSize), kSize)};
    setOfshingle.insert(shingeler);
  }

  return stringSignatureSetup(setOfshingle);
}

// i don't do original string edit becasue i want cleaner code :) (bite me!!)
string padString(string text, int kSize) {

  int remaing{ (kSize - static_cast<int>(text.size()) % kSize) % kSize};
  text.append(remaing, PAD_CHAR);

  return text;
}

