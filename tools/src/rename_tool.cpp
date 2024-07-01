#include <cctype>
#include <fstream>
#include <iostream>
#include <filesystem>

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
  auto written_file_path = filesystem::path(res);
  res += ".hpp";
  written_file_path = filesystem::path("/Users/johnson/Desktop/others/leet_code/leetcode/Algorithms/2024/Jul") / res;
  auto fout = ofstream(written_file_path);
  if (!fout.is_open()) {
    cerr << "file open failed!" << endl;
    exit(-1);
  } else {
    cout << "file created:\n";
    cout << written_file_path << endl;
  }
}
