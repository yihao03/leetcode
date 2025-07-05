#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    if (numCourses <= prerequisites.size()) {
      return false;
    }
  }
};
