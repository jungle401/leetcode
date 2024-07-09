class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double t = 0;
    auto s = 0ull;
    auto n = double(customers.size());
    for (auto ti : customers) {
      auto arrive = ti[0];
      auto run = ti[1];
      if (arrive < s) {
        t += (s - arrive + run) / n;
        s += run;
      } else {
        t += run / n;
        s += arrive - s + run;
      }
    }
    return t;
  }
};
