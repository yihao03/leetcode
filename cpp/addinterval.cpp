#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.size() == 0) {
      return vector<vector<int>>{newInterval};
    }
    vector<vector<int>> result;
    int a{0};

    while (a < intervals.size() && intervals[a][1] < newInterval[0]) {
      result.push_back(intervals[a++]);
    }

    if (a >= intervals.size()) {
      result.push_back(newInterval);
      return result;
    }

    int start{min(newInterval[0], intervals[a][0])};

    int b{a};
    while (b < intervals.size() && intervals[b][0] <= newInterval[1]) {
      ++b;
    }
    if (a == b) {
      result.push_back(newInterval);
    } else {
      result.push_back(
          vector<int>{start, max(intervals[b - 1][1], newInterval[1])});
    }
    result.insert(result.end(), intervals.begin() + a, intervals.end());
    return result;
  }
};
