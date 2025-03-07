#include <bits/stdc++.h>
using namespace std;

/**
 * LC127: Word Ladder
 * 
 * Given a start and end word (both may not be inside wordList) return no. of words in the transformation from
 * start to end word. In each operation you can change only one character in the current string.
 * 
 * If end word does not exist in the word list, the transformation is impossible. 
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words;
        unordered_set<string> vis;
        for (auto &word : wordList) words.insert(word);
        if (words.find(endWord)==words.end()) return 0;
        q.push(beginWord);
        int ans = 1;
        while (!q.empty())
        {
            int sz=q.size();
            while (sz--)
            {
                string word=q.front();q.pop();
                if (word.compare(endWord)==0)
                {
                    return ans;
                }
                if (vis.find(word)!=vis.end()) continue;
                vis.insert(word);
                for (int i=0;i<word.length();i++)
                {
                    for (int j=0;j<26;j++)
                    {
                        string temp=word;
                        temp[i]=j+'a';
                        if (words.find(temp)!=words.end())
                        {
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
