## Random Number Generator in C++

1. Declare an instance of a random number generator *engine*

```cpp
#include <random>

typedef std::mt19937 MyRNG;  // the Mersenne Twister with a popular choice of parameters
uint32_t seed_val;           // populate somehow

MyRNG rng;                   // e.g. keep one global instance (per thread)

void initialize()
{
  rng.seed(seed_val);
}
```

2. Create the type of distribution you want (uniform, normal, etc.)

```cpp
std::uniform_int_distribution<uint32_t> uint_dist;         // by default range [0, MAX]

std::uniform_int_distribution<uint32_t> uint_dist10(0,10); // range [0,10]

std::normal_distribution<double> normal_dist(mean, stddeviation);  // N(mean, stddeviation)
```

3. Pass the engine to the distribution to generate random numbers

```cpp
while (true)
{
  std::cout << uint_dist(rng) << " "
            << uint_dist10(rng) << " "
            << normal_dist(rng) << std::endl;

}
```
