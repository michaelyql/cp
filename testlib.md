## Checker

Checker file needs to be run with 
- Input file
- (User) Output file 
- Answer file 
- Optional: `--testset <testset>` flag 
- Optional: `--group <group>` flag

`./123a_checker <input> <output> <ans>`

Run help with `./123a_checker --help`

### Register checker
```cpp
#include "testlib.h"

int main(int argc, char * argv[]) {
    setName("compares two signed integers");
    registerTestlibCmd(argc, argv);
    int ja = ans.readInt();
    int pa = ouf.readInt();
    if (ja != pa)
        quitf(_wa, "expected %d, found %d", ja, pa);
    quitf(_ok, "answer is %d", ja);
}
```

### Set Name
`setName("<checker name>")`

Sets the name of the checker.

## Generator

### Register generator

```cpp
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>(1);
    println(n);
    println(rnd.perm(n, 1));
}
```

`registerGen(argc, argv)` is deprecated.

Use `registerGen(argc, argv, 0)` or `registerGen(argc, argv, 1)`. The third parameter stands for the random generator version. Use 1 as it's newer. 0 is for old checkers.

### Usage

Use the global instance `rnd` of the custom random generator class `random_t`

Note:
- It uses a uniform generation strategy if a  strategy is not explicitly stated.
- `registerGen` will set the seed.


### Printing to std output
`println(...)` is overloaded to print most things

### Random number in a range

`rnd.next(1, 10)` generates a random int from [1, 10]. This is overloaded for floats/doubles.

`rnd.next(5)` generates a random int from 0 to 4. This is overloaded for floats/doubles.

`rnd.next()` generates a random double from &lbrack;0, 1&rpar;

### Random word of length [1, 1000]

`rnd.next("[a-zA-Z0-9]{1,1000})"`

### Random permutation of length n, starting from 1

`rnd.perm(n, 1)` 

`rnd.perm(n)` starts from 0

### Seed
The seed is automatically generated (and set) based on arguments passed in to the generator file (i.e. from argc and argv) from the command line.

Manually set seed by `rnd.setSeed(long long)`

### Random element from a container

`rnd.any(container)`

### Distinct numbers in a range

`rnd.distinct(size, from, to)`

`rnd.distinct(size, upper)` generates values between 0 and upper - 1
