#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    int curr = 0;

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= intervals[curr][1]) {
        intervals[curr][1] = max(intervals[curr][1], intervals[i][1]);
      } else {
        ++curr;
        intervals[curr] = intervals[i];
      }
    }

    intervals.resize(curr + 1);
    return intervals;
  }
};
