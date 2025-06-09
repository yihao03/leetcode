#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < len; ++i) {
      if (nums[i] > 0) {
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int low = i + 1;
      int high = len - 1;
      int sum = 0;

      while (low < high) {
        sum = nums[i] + nums[low] + nums[high];

        if (sum > 0) {
          high--;
        } else if (sum < 0) {
          low++;
        } else {
          result.push_back({nums[i], nums[low], nums[high]});

          while (low < high && nums[low] == nums[low + 1]) {
            low++;
          }

          while (low < high && nums[high] == nums[high - 1]) {
            high--;
          }

          low++, high--;
        }
      }
    }

    return result;
  }
};
