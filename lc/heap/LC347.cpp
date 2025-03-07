struct ccomp {
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
      return p1.second < p2.second;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> mp;
      for (int i = 0; i < nums.size(); i++) {
          mp[nums[i]]++;
      }
      priority_queue<pair<int, int>, vector<pair<int, int>>, ccomp> pq;
      for (auto it = mp.begin(); it != mp.end(); it++) {
          pq.push({ (*it).first, (*it).second });
      }
      vector<int> ans;
      for (int i = 0; i < k; i++) {
          pair<int, int> p = pq.top();
          pq.pop();
          ans.push_back(p.first);
      }
      return ans;
  }
};
