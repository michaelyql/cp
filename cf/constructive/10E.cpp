#include <iostream>
#include <vector>

using namespace std;

/*
For tight coin systems (i.e. systems with no counterexample smaller than C1), return -1 straight away, since
a tight coin system means that the greedy representation is the optimal representation for all values less than C1. 

For non-tight coin systems, they are also non-canonical by definition...
*/

// Returns the greedy representation of x
int greedy(vector<int>& nums, int x) 
{
    int i = 0; 
    int count = 0;
    while (x > 0) 
    {
        while (nums[i] <= x)
        {
            x -= nums[i];
            count++;
        }
        i++;
    }
    return count;
}


int main()
{
    int n;
    vector<int> values(n);
    cin >> n;
    if (n <= 2) 
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> values[i];
    

    return 0;
}
