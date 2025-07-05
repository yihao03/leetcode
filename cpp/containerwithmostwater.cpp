#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxArea{0};

    int start{0};
    int end{static_cast<int>(height.size() - 1)};

    while (start < end) {
      maxArea = max(maxArea, min(height[start], height[end]) * (end - start));

      if (height[start] < height[end]) {
        start++;
      } else {
        end--;
      }
    }

    return maxArea;
  }
};
