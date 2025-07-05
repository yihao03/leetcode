#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    queue<ListNode *> q;
    ListNode *curr = head;

    while (curr != nullptr) {
      q.push(curr);
      curr = curr->next;
      if (q.size() > n + 1) {
        q.pop();
      }
    }

    // If we need to remove the head
    if (q.size() == n) {
      ListNode *toDelete = head;
      head = head->next;
      delete toDelete;
      return head;
    }

    // Otherwise, remove the nth node from end
    ListNode *prev = q.front();
    ListNode *toDelete = prev->next;
    prev->next = prev->next->next;
    delete toDelete;
    return head;
  }
};
