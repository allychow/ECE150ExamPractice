#include <iostream>
using namespace std;

struct Node {
  int   data;
  Node *next;
};
Node* insert(Node *n, int d) {
  Node *nd = new Node;

  nd->data = d;
  nd->next = n;
  return nd;
}

Node* findByIndex(Node *n, int i) {
  if (n == 0) return 0;

  if (i == 0) return n;

  return findByIndex(n->next, --i);
}

Node* removeByIndex(Node* n, int i) {
  if (n == NULL || i < 0) {
    cerr << "Error: does not exist";
    return NULL;
  }
  if (i == 0) {
    n = n->next;
    return n;
  }

  int index = 0;
  Node *temp = n;
  Node *moving = 0;
  while (index < i) {
    moving = temp;
    temp = temp->next;
    index++;
  }
  moving->next = temp->next;
  return n;
}

int main() {
  Node *n = 0;

  n = insert(n, 3);
  n = insert(n, 21);
  n = insert(n, -19);
  n = insert(n, 46);
  n = insert(n, 15);


  n = removeByIndex(n, 2);

  while (n != 0) {
    cout << n->data << " ";
    n = n->next;
  }
}
