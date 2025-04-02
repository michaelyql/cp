const int N = 5e4 + 2;
using ll = long long;

class Solution {
    bool isPrime[N];
    vector<int> primes;
    void sieve() {
        memset(isPrime, true, sizeof(isPrime));
        isPrime[1] = false;
        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        sieve();
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = 0; j < primes.size(); j++) {
                int p = primes[j];
                if (a % p == 0 && p != a / p) {
                    if (isPrime[a / p] || a / p == 1ll * p * p) {
                        total += 1 + a + p + a / p;
                    } 
                    break;
                }
            }
        }
        return total;
    }
};
