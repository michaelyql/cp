#include <iostream>
using namespace std;

struct node {
  node *next = nullptr;
  int idx;
  node(int i) {
    idx = i;
  }
};

void print_list(node *cur) {
  if (cur == nullptr) return;
  cout << cur->idx << " ";
  print_list(cur->next);
}

node *reverse(node *cur) {
  if (cur->next == nullptr) return cur;
  
  node *tail = reverse(cur->next);
  cur->next->next = cur;
  cur->next = nullptr;
  
  return tail;  
}

void helper(node *l1, node *l2) {
  if (l1 == nullptr) return;
  
  node *nxt = l1->next; 
  l1->next = l2;
  helper(l2, nxt); 
}

void reorder(node *start) {
  int n = 0;
  node *cur = start;
  while (cur != nullptr) {
    n++;
    cur = cur->next;
  }
  cur = start;
  cout << "Size: " << n << endl;
  for (int i = 0; i < n / 2 - 1; i++) {
    cur = cur->next; 
  }
  
  node *second_half = cur->next;
  cout << second_half->idx << endl;
  cur->next = nullptr; // break the chain to prevent infinite loop
  node *last = reverse(second_half);
  print_list(last); 
  cout << endl;
  helper(start, last);
}

int main(int argc, char const *argv[])
{
  node *start = new node(0);
  node *cur = start;
  for (int i = 1; i <= 9; i++) {
    node *n = new node(i);
    cur->next = n;
    cur = n;
  }
  print_list(start); 
  cout << endl;
  reorder(start); 

  print_list(start); 
  cout << endl;
  return 0;
}
