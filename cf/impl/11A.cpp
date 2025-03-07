#include <iostream>
#include <cmath>

using namespace std;


// 10 3
// 10 24 13 15 18 14 15 26 33 35, Ans: 29

int main() 
{
    int n, d;
    cin >> n >> d;
    int nums[n];
    int adds[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
        adds[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] && adds[i - 1] == 0) 
        {
            adds[i] = 1;
        }
        else if (nums[i] == nums[i - 1] && adds[i - 1] > 0)
        {
            adds[i] = adds[i - 1] + 1;
        }
        else if (nums[i] > nums[i - 1] && adds[i - 1] == 0) 
        {
            continue;
        }
        else if (nums[i] > nums[i - 1] && adds[i - 1] > 0) 
        {
            int diff = nums[i] - nums[i - 1];
            for (int j = 0; j < adds[i - 1]; j++)
            {
                diff -= d;
                if (diff <= 0) 
                {
                    adds[i] = adds[i - 1] - j;
                    break;
                }
            }
        }
        else if (nums[i] < nums[i - 1] && adds[i - 1] == 0) 
        {
            int diff = nums[i - 1] - nums[i];
            adds[i] = ceil((float)(diff + 1) / d);
        }
        else 
        {
            int diff = nums[i - 1] - nums[i];
            adds[i] = ceil((float)(diff + 1) / d) + adds[i - 1]; 
        }
    }
    int moves = 0;
    for (int i = 0; i < n; i++) moves += adds[i];
    cout << moves << endl;
    cout << endl << endl;
    return 0;
}

// 673
