#include <bits/stdc++.h>
// #include "helpers.cpp"
using namespace std;

/**
 * PPATH - Prime Path
 * 
 * Given a starting 4 digit prime number and a target 4 digit prime number,
 * 
 * find the min number of steps needed to get to the target from start, given that 
 * 
 * in each operation you can only change one digit in the current number 
 * 
 * such that the resulting number is also a 4 digit number.
 */
unordered_set<string> sieve(int n)
{
  vector<bool> isPrime(n + 1, true);
  for (int p = 2; p * p <= n; p++)
  {
    if (isPrime[p])
    {
      for (int i = p * p; i <= n; i += p)
      {
        isPrime[i] = false;
      }
    }
  }
  unordered_set<string> res;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i]) res.insert(to_string(i));
  }
  return res;
}

unordered_set<string> fourDigitPrimes = sieve(10000); // primes up to 10e5

void solve()
{
  string start,target;
  cin>>start>>target;
  queue<string> q;
  int cost=0;
  unordered_set<string> seen;
  q.push(start);
  while (!q.empty())
  {
    int sz = q.size();
    // cout<<q;
    while (sz--)
    {
      string curr=q.front();q.pop();
      if (curr.compare(target) == 0) 
      {
        cout << cost << endl;
        return;
      }
      if (seen.find(curr)!=seen.end()) continue;
      seen.insert(curr);
      for (int i=0;i<4;i++) // for each digit in the 4 digit prime
      {
        for (int j=0;j<10;j++)
        {
          string temp = curr;
          if (temp[i] != to_string(j)[0])
          {
            temp[i] = to_string(j)[0]; 
            if (fourDigitPrimes.find(temp)!=fourDigitPrimes.end() && seen.find(temp) == seen.end())
              q.push(temp);
          }  
        }
      }
    }
    cost++;
  }
  cout << "Impossible" << endl;
}

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    solve();
  }
}
