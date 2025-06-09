#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int ans{0};
    int right{0};
    int left{0};
    int len{static_cast<int>(s.size())};

    if (len < 2) {
      return len;
    }

    while (right < len) {
      if (map[s[right]] == 0) {
        ans = max(ans, right - left + 1);
        ++map[s[right]];
        ++right;
      } else {
        --map[s[left]];
        ++left;
      }
    }

    return ans;
  }
};
