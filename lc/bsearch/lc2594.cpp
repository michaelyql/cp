using ll = long long;

class Solution {
    bool ok(ll x, vector<int>& ranks, int cars) {
        int total = 0;
        for (int i = 0; i < ranks.size(); i++) {
            total += (int) sqrt(x / ranks[i]);
            if (total >= cars) return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        ll lo = 1;
        ll hi = 1ll * cars * cars * ranks[n - 1];
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (ok(mid, ranks, cars)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
