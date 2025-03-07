#include <bits/stdc++.h>

using namespace std;

/**
 * LC76: Minimum Window Substring
 */
class Solution {
public:
    string minWindow(string s, string t) {
        pair<int,int> ans (0, 10e7);
        int winStart=0,winEnd=1;
        unordered_map<char, int> refMap;
        for(char &c: t) refMap[c]++;
        unordered_map<char, int> freqMap;
        while(winEnd<=s.length())
        {
            char c=s[winEnd-1];
            freqMap[c]++;
            bool missing=false;
            for(auto it=refMap.begin();it!=refMap.end();it++)
            {
                char d=it->first;
                if(freqMap[d]<refMap[d]) 
                {
                    missing=true;
                    break;
                }
            }
            if (!missing) // valid window
            {
                // update answer
                if (winEnd-winStart<ans.second-ans.first)
                    ans=make_pair(winStart,winEnd);
                // shrink from left
                char toRemove=s[winStart];
                while(freqMap[toRemove]>refMap[toRemove] 
                    || refMap.find(toRemove)==refMap.end())
                {
                    winStart++;
                    if (winEnd-winStart<ans.second-ans.first)
                    {
                        ans=make_pair(winStart,winEnd);
                    }
                    freqMap[toRemove]--;
                    toRemove=s[winStart];
                }
            }
            winEnd++;
        }
        if (ans.first == 0 && ans.second == 10e7) return "";
        return s.substr(ans.first,ans.second-ans.first);
    }
};
