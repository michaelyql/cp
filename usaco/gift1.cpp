
/*
ID: yql.mic1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    
    int n;
    fin >> n;
    string s;
    unordered_map<string, int> amt;
    vector<string> order;
    for (int i = 0; i < n; i++) {
        fin >> s;
        amt[s] = 0;
        order.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string giver, receiver;
        int total, k;
        fin >> giver;
        fin >> total >> k;
        for (int j = 0; j < k; j++) {
            fin >> receiver;
            amt[receiver] += total / k;
        }
        amt[giver] -= total;
        if (k > 0) amt[giver] += total % k;
    }
    for (string &name : order) {
        fout << name << " " << amt[name] << endl;
    }

    return 0;
}
