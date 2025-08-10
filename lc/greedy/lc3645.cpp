class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        map<int, vector<int>> limitGroup;
        for (int i = 0; i < n; i++) {
            limitGroup[limit[i]].push_back(value[i]); 
        }
        long long ans = 0;
        int active = 0;
        queue<int> leftover;
        for (auto it = limitGroup.begin(); it != limitGroup.end(); it++) {
            int l = it->first;
            auto v = it->second;
            sort(v.begin(), v.end(), greater<int>());
            int i = 0, sz = v.size();
            while (active < l && i < sz) {
                ans += v[i];
                i++;
                active++;
                leftover.push(l);
                if (active == l) {
                    while (leftover.front() < l) {
                        leftover.pop();
                        active--;
                    }
                    if (active == l) {
                        while (!leftover.empty()) leftover.pop(), active--;
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
}
