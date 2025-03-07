#include <bits/stdc++.h>
#include "helpers.cpp"
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> v;
  priority_queue<int> maxHeap;
  priority_queue<int,vector<int>,greater<int>> minHeap;
  for(int i=0;i<n;i++) {
    int t;cin>>t;
    v.push_back(t);
  }
  if (n==1) {
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  int l=0,r=0;
  int d=1;
  unordered_set<int> toDelete; // lazy delete
  deque<int> indices;
  vector<vector<int>> timePeriods;
  while(r<n) {
    int curr=v[r];
    maxHeap.push(curr);
    minHeap.push(curr);
    int mx=maxHeap.top();
    while (toDelete.find(mx)!=toDelete.end()) {
      maxHeap.pop();
      mx=maxHeap.top();
    }
    int mn=minHeap.top();
    while (toDelete.find(mn)!=toDelete.end()) {
      minHeap.pop();
      mn=minHeap.top();
    }
    if (mx-mn<=k) {
      d=max(d,r-l+1);
      indices.push_back(r); 
      timePeriods.push_back({indices.front(), indices.back()});
      r++;
    }
    else {
      toDelete.insert(v[l++]);
      indices.pop_front();
    }
  }
  int sz=timePeriods.size();
  cout<<timePeriods;
  unordered_map<int,int> m;
  if (d>1) for (int i=0;i<timePeriods.size();i++) {
    
    m[timePeriods[i][0]]=timePeriods[i][1];
  }
  for (auto it=m.begin();it!=m.end();it++) sz-=(*it).second-(*it).first;
  cout<<d<<" "<<sz<<endl;
  for (int i=0;i<timePeriods.size();i++){
    if (d>1 && timePeriods[i][0]==timePeriods[i][1]) continue; 
    if (timePeriods[i][1] != m[timePeriods[i][0]]) continue;
    cout<<timePeriods[i][0]+1<<" "<<timePeriods[i][1]+1<<endl;
  }
}
