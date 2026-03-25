
#include "inputHandler.hpp"

using namespace std;

string readFile(const string& path) {
  ifstream file(path);
  ostringstream ss;
  ss << file.rdbuf();
  return ss.str();
}