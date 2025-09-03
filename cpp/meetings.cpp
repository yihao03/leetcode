#include <algorithm>
#include <vector>
using namespace std;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool Sorter(Interval &a, Interval &b) {
  if (a.end != b.end) {
    return a.end < b.end;
  } else {
    return a.start < b.start;
  }
}

class Solution {

public:
  /**
   * @param intervals: an array of meeting time intervals
   * @return: if a person could attend all meetings
   */
  bool canAttendMeetings(vector<Interval> &intervals) {
    // Write your code here
    sort(intervals.begin(), intervals.end(), Sorter);
  }
};
