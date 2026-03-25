#include "shingling.hpp"

string padString(string text, int kSize);

/* 
  +1 how to deal with shingl that does not have enough character. 
     HERE: use special char to pad it "$"
  -2 i will just use substr instead of string view for eash of coding
    if i have time i will come back and make another version and test
    if it better. 
    
*/

set<string> shinglText(const string& text, int kSize) {

  set<string> setOfshing;

  for(long long startIndex{};startIndex<text.size();startIndex+=1){
    string shingeler{padString(text.substr(startIndex, kSize), kSize)};
    setOfshing.insert(shingeler);
  }

  return setOfshing;

}

// i don't do original string edit becasue i want cleaner code :) (bite me!!)
string padString(string text, int kSize) {

  int remaing{ (kSize - static_cast<int>(text.size()) % kSize) % kSize};
  text.append(remaing, PAD_CHAR);

  return text;
}


