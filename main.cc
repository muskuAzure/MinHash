/*
  - 1 cannot handle UTF-8
  - 2 need a way to find optimal shingl size
*/

#include <filesystem>
#include "shingling.hpp"
#include "inputHandler.hpp"
#include "utility.hpp"
#include "hash_handler.hpp"

using namespace std;
namespace fs = filesystem;

double jaccard(const vector<long long>& a, const vector<long long>& b) {
  set<long long> sa(a.begin(), a.end());
  set<long long> sb(b.begin(), b.end());

  long long intersect{};
  for (const auto& x : sa) {
    if (sb.count(x)) intersect++;
  }

  long long uni = (long long)sa.size() + (long long)sb.size() - intersect;
  return uni == 0 ? 1.0 : (double)intersect / uni;
}

int main(int argc, char** argv) {

  if (argc < 3) {
    cerr << "Usage: programName shingSize numHashes <folder | file1 file2 ...>\n";
    return EXIT_FAILURE;
  }

  long long shingSize{stoi(argv[1])};
  int numHashes{stoi(argv[2])};

  vector<string> filePaths;
  if (argc == 4 && fs::is_directory(argv[3])) {
    for (const auto& entry : fs::directory_iterator(argv[3])) {
      if (entry.path().extension() == ".txt") {
        filePaths.push_back(entry.path().string());
      }
    }
    sort(filePaths.begin(), filePaths.end());
  } else {
    for (int i{3}; i < argc; i++) {
      filePaths.push_back(argv[i]);
    }
  }

  if (filePaths.size() < 2) {
    cerr << "Need at least 2 documents to compare.\n";
    return EXIT_FAILURE;
  }

  vector<vector<long long>> shinglOfEachDocument;
  for (const auto& path : filePaths) {
    shinglOfEachDocument.push_back(shinglingText(readFile(path), shingSize));
  }

  int n = shinglOfEachDocument.size();
  vector<int> collisionBook;
  applyMinHash(shinglOfEachDocument, collisionBook, numHashes);

  cout << format("{:<45} {:>15} {:>10}\n", "Pair", "MinHash est.", "Jaccard");
  cout << string(72, '-') << "\n";

  for (int i{}; i < n; i++) {
    for (int j{i+1}; j < n; j++) {
      string pair = fs::path(filePaths[i]).filename().string()
                  + " vs "
                  + fs::path(filePaths[j]).filename().string();
      double minhashEst  = (double)collisionBook[triangleIndex(i, j, n)] / numHashes;
      double exactJaccard = jaccard(shinglOfEachDocument[i], shinglOfEachDocument[j]);
      cout << format("{:<45} {:>12.2f}%  {:>8.2f}%\n",
                     pair, minhashEst * 100, exactJaccard * 100);
    }
  }

  return EXIT_SUCCESS;
}
