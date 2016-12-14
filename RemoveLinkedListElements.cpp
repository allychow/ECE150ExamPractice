#include <iostream>
using namespace std;

struct ListNode {
  int   val;
  ListNode *next;
};
ListNode* insert(ListNode *n, int d) {
  ListNode *nd = new ListNode;

  nd->val = d;
  nd->next = n;
  return nd;
}

ListNode* findByIndex(ListNode *n, int i) {
  if (n == 0) return 0;

  if (i == 0) return n;

  return findByIndex(n->next, --i);
}

ListNode* removeByIndex(ListNode* n, int i) {
  if (n == NULL || i < 0) {
    cerr << "Error: does not exist";
    return NULL;
  }
  if (i == 0) {
    n = n->next;
    return n;
  }

  int index = 0;
  ListNode *temp = n;
  ListNode *moving = 0;
  while (index < i) {
    moving = temp;
    temp = temp->next;
    index++;
  }
  moving->next = temp->next;
  return n;
}

ListNode* removeElements(ListNode* head, int val) {
  // cout << "ok";
        if (head == 0) {
            return NULL;
        }
        if (head->val == val && head->next == NULL) {
            head = head->next;
            // cout << 52;
            return head;
        }
        // cout << "yes";
        ListNode *prev = 0;
        ListNode *moves = head;
        while (moves->val != val && moves->next != NULL){
            prev = moves;
            moves = moves->next;
        }
        while (moves->val == val && moves != NULL) {
          prev = moves;
          moves = moves->next;
        }
        if (moves->next == NULL) {
          return head;
        }

        prev->next = moves->next;
      //  cout << 63;
        return head;
    }

int main() {
  ListNode *n = 0;

  n = insert(n, 1);
  n = insert(n, 2);
  n = insert(n, 1);

  n = removeElements(n, 1);

  while (n != 0) {
    cout << n->val << " ";
    n = n->next;
  }
}
