/*
  - 1 cannot handle UTF-8
  - 2 need a way to find optimal shingl size
*/

#include "shingling.hpp"
#include "inputHandler.hpp"
#include "utility.hpp"
#include "hash_handler.hpp"

using namespace std;

int main(int argc, char** argv) {

  if (argc < 5) {
    cerr << "You need to hav at least 5 parameter. programName shingSize numberOfProgram document..";
    return EXIT_FAILURE;
  }

  long long shingSize{stoi(argv[1])}, numberOfText{stoi(argv[2])};

  vector<vector<long long>> shinglOfEachDocument;
  long long maxNumber{};

  // run O(n), numberOfDocumetn into hash 
  // optimzed this later
  for (long long i{};i<numberOfText;i++){
    vector<long long> shingl{shinglingText(readFile(argv[3+i]), shingSize)};
    shinglOfEachDocument.push_back(shingl);
  }

  // algorithm for optimized k value 

  // how large shoukd my hash table be 
  vector<long long> collsionBook(shinglOfEachDocument.size());
  applyMinHash(shinglOfEachDocument, collsionBook);
  



  


  

  return EXIT_SUCCESS;
}