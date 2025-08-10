class Solution {
    // generate combinations of distinct numbers from 1..9 that sum to target
    void genCombinations(int start, int target, vector<int> &curr, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        for (int d = start; d <= 9; d++) {
            if (d <= target) {
                curr.push_back(d);
                genCombinations(d + 1, target - d, curr, result);
                curr.pop_back();
            }
        }
    }
    
    // generate unique permutations of a string
    void uniquePermutations(string &s, vector<string> &perms) {
        sort(s.begin(), s.end());
        do {
            perms.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
    }
    
    // generate all palindromes from a combination of digits
    vector<long long> genPalindromes(const vector<int> &combo) {
        // build multiset
        string multiset;
        for (int d : combo) {
            multiset += string(d, char('0' + d));
        }
    
        // count frequencies
        vector<int> freq(10, 0);
        for (char c : multiset) freq[c - '0']++;
    
        // check palindrome possibility
        int oddCount = 0;
        char middleChar = 0;
        for (int d = 0; d <= 9; d++) {
            if (freq[d] % 2 != 0) {
                oddCount++;
                middleChar = char('0' + d);
            }
        }
        if (oddCount > 1) return {}; // impossible
    
        // build half string
        string half;
        for (int d = 0; d <= 9; d++) {
            half += string(freq[d] / 2, char('0' + d));
        }
    
        //generate unique permutations of half
        vector<string> halfPerms;
        uniquePermutations(half, halfPerms);
    
        // mirror to form palindromes
        vector<long long> pals;
        for (auto &h : halfPerms) {
            string rev = h;
            reverse(rev.begin(), rev.end());
            if (middleChar) {
                pals.push_back(stoll(h + string(1, middleChar) + rev));
            } else {
                pals.push_back(stoll(h + rev));
            }
        }
        return pals;
    }
    
public:
    long long specialPalindrome(long long n) {
        if (n == 0) return 1;
        if (n < 22) return 22;
        
        string s = to_string(n);
        int l = s.length();

        vector<long long> p;
        
        for (int target = l; target <= l + 1; target++) {            
            vector<vector<int>> combos;
            vector<int> curr;
            genCombinations(1, target, curr, combos);
            
            for (auto &combo : combos) {
                vector<long long> pals = genPalindromes(combo);
    
                p.insert(p.end(), pals.begin(), pals.end());
            }
        }

        sort(p.begin(), p.end());
        return *upper_bound(p.begin(), p.end(), n);
    }
};
