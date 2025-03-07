#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int d, sumTime;
    cin >> d >> sumTime;
    if (sumTime > d * 24)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> minh(d);
    vector<int> maxh(d);
    int upper = 0;
    int lower = 0;
    vector<int> schedule;
    for (int i = 0; i < d; i++) 
    {
        cin >> minh[i] >> maxh[i];
        lower += minh[i];
        upper += maxh[i];
        schedule.push_back(minh[i]);
    }
    if (lower > sumTime || upper < sumTime) 
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int currsum = lower;
    if (currsum < sumTime) 
    {
        for (int i = 0; i < d; i++) 
        {
            int diff = maxh[i] - minh[i];
            int j = 0;
            while (j < diff) 
            {
                if (currsum == sumTime) break;
                currsum++;
                schedule[i]++;
                j++;
            }
        }
    }
    for (int i = 0; i < d; i++) 
    {
        cout << schedule[i] << " ";
    }
    cout << endl;
    return 0;
}
