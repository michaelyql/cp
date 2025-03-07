#include <bits/stdc++.h>
#include "helpers.cpp"
using namespace std;

/**
 * AtCoder Beginner Contest 235 D - Multiply and Rotate
 * 
 * @link https://atcoder.jp/contests/abc235/tasks/abc235_d
 */
int main()
{
  int ops=0;
  int a,N;
  cin>>a>>N;
  queue<int> q;
  unordered_set<int> seen;
  q.push(1);
  while(!q.empty())
  {
    int size=q.size();

    /* --DEBUG--
    queue<int> copy(q);
    cout<<"Level: "<<ops<<", "<<endl;
    cout<<"Queue: [";
    int szz=copy.size();
    for(int i=0;i<szz;i++)
    {
      cout<<copy.front();copy.pop();
      cout<<", ";
    }
    cout<<"]"<<endl;
    */
   cout<<q;

    while (size--)
    {
      int node=q.front();q.pop();
      if (node==N) 
      {
        cout<<ops<<endl;
        return 0;
      }
      if (seen.find(node)!=seen.end()) continue;
      if (ceil(log10(node))>ceil(log10(N))) continue; 
      seen.insert(node);
      if (seen.find(node*a)==seen.end()) 
        q.push(node*a);
      if(node>=10 && node%10!=0) 
      {
        int temp=(node%10)*pow(10, floor(log10(node)))+node/10;
        if (seen.find(temp)==seen.end())
          q.push(temp);
      }
    }
    ops++;
  }
  cout<<-1<<endl;
}
