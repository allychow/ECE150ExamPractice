#include <iostream>
using namespace std;

struct Node {
  int   data;
  Node *next;
};

Node* InsertNth(Node *head, int data, int position)
{
    Node *nodal = new Node;
    nodal->data = data;
    nodal->next = NULL;
    if (head == NULL) {
        head = nodal;
        return head;
    }
    Node *mover = new Node;
    Node *curr = new Node;
    curr = head;
    mover = 0;
    if (position == 0) {
        nodal->next = curr->next;
        head = nodal;
        return head;
    }
    int i = 0;
    while (i < position) {
        mover = curr;
        curr = curr->next;
        i++;
    }
    nodal->next = curr;
    mover->next = nodal;
    return head;
}

int main() {
  Node *head = 0;
  head = InsertNth(head, 3, 0);
  head = InsertNth(head, 5, 1);
  head = InsertNth(head, 4, 2);
  head = InsertNth(head, 2, 3);
  head = InsertNth(head, 10, 1);


  //displays the contents of the list.
  while (head != 0) {
    cout << head->data << " ";
    head = head->next;
  }
}
