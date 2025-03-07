#include <vector>
#include <iostream>
#include "helpers.cpp"

using namespace std;

/**
 * Generates prime numbers less than or equal to n in O(N*log(log(N))) time, using O(N) space.
 * 
 * @param n
 * @returns A vector of prime numbers less than or equal to n.
 */
vector<int> sieve(int n)
{
  vector<bool> isPrime(n + 1, true);
  for (int p = 2; p * p <= n; p++) // Iterate from 2 to sqrt(n)
  {
    if (isPrime[p]) // For each p, every multiple of it is not a prime
    {
      for (int i = p * p; i <= n; i += p) // Initiate i = p * p because multiples of previous primes have already been considered
      {
        isPrime[i] = false;
      }
    }
  }
  vector<int> res;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i]) res.push_back(i);
  }
  return res;
}

// TESTS
int main()
{
  cout << "Primes up to 30: "<<  sieve(30);
  cout << "Primes up to 10,000: " << sieve(1e4);
}
