#include "helpers.cpp"
// to compile: clang++ -std=c++17 lc30.cpp -o lc30
// c++11 or above needed for initializer list initialization

using namespace std;

/**
 * LC30: Substring with Concatenation of All Words
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        unordered_map<string, int> refMap;
        for (string& word : words) {
            refMap[word]++;
        }

        int wordLen = words[0].length();
        int start, end;

        for (int i = 0; i < wordLen; i++) {
            start = i;
            end = start + wordLen - 1;
            int windowSize = 0;

            unordered_map<string, int> freqMap;

            while (end < s.length()) {
                string sub = s.substr(end - wordLen + 1, wordLen);
                freqMap[sub]++; 
                windowSize++;
                if (refMap.find(sub) != refMap.end()) {
                    while (freqMap[sub] > refMap[sub]) {
                        // invalid window, shrink from left
                        string toRemove = s.substr(start, wordLen);
                        freqMap[toRemove]--;
                        windowSize--;
                        start = start + wordLen; // move left ptr
                    } 
                    if (windowSize == words.size()) { // valid window
                        result.push_back(start); 
                    }
                } else {
                    // word does not exist in 'words', invalid window
                    freqMap.clear();
                    windowSize = 0;
                    start = end + 1;
                }
                end += wordLen;
            }
        }

        return result;
    }
};

int main() {
  Solution s;
  string a1 [] = {"word","good","best","good"};
  vector<string> input1 (a1, a1+4);
  cout << s.findSubstring("wordgoodgoodgoodbestword", input1); // [8]
  
  string a2 [] = {"aa", "aa"};
  vector<string> input2 (a2, a2+2);
  cout << s.findSubstring("aaaaaaaaaaaaaa", input2); // [0,1,2,3,4,5,6,7,8,9,10]
}
