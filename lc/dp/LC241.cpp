static const int N = 21;

class Solution {
    vector<int> dp[N][N]; 
public:
    vector<int> diffWaysToCompute(string expression) {
        return f(0, expression.size() - 1, expression);
    }
    vector<int> f(int l, int r, string& expression) {
        if (!dp[l][r].empty()) return dp[l][r];
        if (l == r) 
            return {expression[l] - '0'}; 
        if (l + 1 == r) 
            return {(expression[l] - '0') * 10 + expression[r] - '0'};

        vector<int> res;

        for (int i = l; i <= r; i++) {
            char c = expression[i];
            if (isdigit(c)) continue;
            vector<int> left = f(l, i - 1, expression);
            vector<int> right = f(i + 1, r, expression);
            
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    if (c == '+') {
                        res.push_back(left[j] + right[k]);
                    } else if (c == '-') {
                        res.push_back(left[j] - right[k]);
                    } else {
                        res.push_back(left[j] * right[k]);
                    }
                }
            }
        }

        return dp[l][r] = res;
    }
    
};
