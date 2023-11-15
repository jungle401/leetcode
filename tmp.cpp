#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
  vector<string> in;
  for (int i = 0; i < argc; i++) {
    in.push_back(argv[i]);
  }
  auto out = string();
  in[1].pop_back();
  for (int i = 1; i < in.size(); i++) {
    out += in[i] + '_';
  }
  out.pop_back();
  out += ".hpp";
  cout << out << endl;
}
