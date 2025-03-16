#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Assuming only lowercase alphabetical characters
struct TrieNode {
  TrieNode *children[26];
  TrieNode() {
    for (int i = 0; i < 26; i++) children[i] = nullptr;
  }
  bool isEnd = false;
}; 

void insert(TrieNode* root, const string& s) {
  TrieNode* curr = root;
  for (char c : s) {
    int idx = c - 'a';
    if (curr->children[idx] == nullptr) {
      curr->children[idx] = new TrieNode();
    } 
    curr = curr->children[idx]; 
  }
  curr->isEnd = true;
}

bool search(TrieNode* root, const string& s) {
  TrieNode* curr = root;
  for (char c : s) {
    int idx = c - 'a';
    if (curr->children[idx] == nullptr) {
      return false;
    }
    curr = curr->children[idx];
  }
  return curr->isEnd;
}

void printTrie(TrieNode* root) {
  
}

int main() {
  TrieNode root;
  insert(&root, "helloworld");
  insert(&root, "hello");
  cout << "'hello' found in trie: " << (search(&root, "hello") ? "Yes" : "No") << endl; // Yes
  cout << "'world' found in trie: " << (search(&root, "world") ? "Yes" : "No") << endl; // No
}
