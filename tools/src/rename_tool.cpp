#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Error input format!" << endl;
    exit(-1);
  }
  auto s = string();
  for (int i = 1; i < argc; i++) {
    s += argv[i];
    s += ' ';
  }
  auto res = string();
  for (auto& c : s) {
    if (isalnum(c)) {
      res += c;
    } else {
      if (res.back() != '_') {
        res += '_';
      }
    }
  }
  res += ".hpp";
  auto fout = ofstream("/Users/johnson/Desktop/others/leet_code/leetcode/Algorithms/2024/Jun/" + res);
  if (!fout.is_open()) {
    cerr << "file open failed!" << endl;
    exit(-1);
  } else {
    cout << "file created:\t";
    cout << res << endl;
  }
}
