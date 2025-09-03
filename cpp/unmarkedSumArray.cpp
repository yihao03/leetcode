#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<long long> unmarkedSumArray(vector<int> &nums,
                                     vector<vector<int>> &queries) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long total = 0;
    vector<long long> result(queries.size());
    int size = nums.size();
    unordered_set<int> marked(size);

    for (int i = 0; i < size; ++i) {
      pq.push({nums[i], i});
      total += nums[i];
    }

    int querySize = queries.size();
    for (int j = 0; j < querySize; ++j) {
      auto &query = queries[j];
      auto exist = marked.insert(query[0]);
      if (exist.second) {
        total -= nums[query[0]];
      }

      int i = query[1];

      while (i > 0 && !pq.empty()) {
        auto curr = pq.top();
        if (marked.find(curr.second) == marked.end()) {
          marked.insert(curr.second);
          total -= curr.first;
          --i;
        }
        pq.pop();
      }

      result[j] = total;
    }

    return result;
  }
};
