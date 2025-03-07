#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Assuming only lowercase characters
struct TrieNode {
  TrieNode *children[26];
  char c;
  TrieNode(char x) {
    this->c = x;
    for (int i = 0; i < 26; i++) children[i] = nullptr;
  }
  TrieNode(): TrieNode('\0') {
    // 
  }
}; 

void insert(TrieNode* root, const string& s) {
  TrieNode* current = root;
  for (char c : s) {
    int idx = c - 'a';
    if (current->children[idx] == nullptr) {
      current->children[idx] = new TrieNode(c);
    } 
    current = current->children[idx]; 
  }
}

bool search(TrieNode* root, const string& s) {
  TrieNode* current = root;
  for (char c : s) {
    int idx = c - 'a';
    if (current->children[idx] == nullptr) {
      return false;
    }
    current = current->children[idx];
  }
  return true;
}

void printTrie(TrieNode* root) {
  
}

int main() {
  TrieNode* root = new TrieNode();
  insert(root, "helloworld");
  cout << "'w' found in trie: " << (search(root, "w") ? "Yes" : "No") << endl;
}
