/*
  - 1 cannot handle UTF-8
*/

#include "shingling.hpp"
#include "inputHandler.hpp"
#include "utility.hpp"

using namespace std;

int main(int argc, char** argv) {

  if (argc < 5) {
    cerr << "You need to hav at least 5 parameter. programName shingSize numberOfProgram document..";
    return EXIT_FAILURE;
  }

  int shingSize{stoi(argv[1])}, numberOfText{stoi(argv[2])};

  vector<set<string> > shinglOfEachDocument;
  set<string> vocab;

  // run O(n), numberOfDocumetn into hash 
  for (int i{};i<numberOfText;i++){
    set<string> shingl{shinglText(readFile(argv[3+i]), shingSize)};
    shinglOfEachDocument.push_back(shingl);
    vocab.merge(shingl);
  }
  

  return EXIT_SUCCESS;
}