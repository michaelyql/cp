/*
ID: yql.mic1
PROG: ride
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");

    string comet;
    string group;

    getline(fin, comet);
    getline(fin, group);
    
    int sum1 = 1;
    int sum2 = 1;
    for (char c : comet) {
        sum1 *= (c - 'A' + 1);
    }
    for (char c : group) {
        sum2 *= (c - 'A' + 1);
    }
    if (sum1 % 47 == sum2 % 47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
