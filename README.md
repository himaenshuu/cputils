# cputils

A lightweight, single-header C++ utility library for **Programming** and **DSA**.  
No build step. No dependencies. Just `#include` and go.

---

## Features

| Utility | What it does |
|---|---|
| `print1d(v)` | Print a 1D `vector<int>` |
| `print2d(v)` | Print a 2D `vector<vector<int>>` |
| `printPair(p)` | Print a `pair<A,B>` |
| `printPairs(v)` | Print a `vector<pair<A,B>>` |
| `fastIO()` | `ios::sync_with_stdio(false); cin.tie(nullptr)` |
| `dbg(x)` | Debug print `x` to stderr (disabled on online judges) |
| `dbgv(v)` | Debug print a vector to stderr |
| `gcd(a, b)` | Non-negative GCD of two `long long` values |
| `lcm(a, b)` | Non-negative LCM of two `long long` values; returns `0` when either input is `0` |
| `modNormalize(value, mod)` | Normalize a value into `[0, mod)` |
| `modPow(base, exponent, mod)` | Fast binary modular exponentiation |
| `isPrime(n)` | Trial-division primality check |
| `sieve(n)` | List primes up to `n` |
| `prefixSum(v)` | Prefix sums for a `vector<long long>` with a leading `0` |
| `chmin(x, y)`, `chmax(x, y)` | Update-and-report min/max helpers |
| `ll`, `ull`, `vi`, `vll`, `vvi`, `pii` | Common typedefs |

---

## Quick Install (recommended for CP)

**Linux / macOS:**
```bash
curl -O https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h
```

**Windows (PowerShell):**
```powershell
Invoke-WebRequest -UseBasicParsing -Uri "https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h" -OutFile "cputils.h"
```

> Note: On Windows, `wget` and `curl` are aliases for `Invoke-WebRequest` and won't save the file without `-OutFile`. Use the command above instead.

Then in your solution:
```cpp
#include "cputils.h"

int main() {
    fastIO();
    vector<int> v = {1, 2, 3, 4};
    print1d(v);         // 1 2 3 4

    dbg(v.size());      // v.size() = 4  (only in local builds)

    ll a = 12, b = 18;
    cout << gcd(a, b);  // 6

    cout << modPow(2, 10, 1000000007);  // 1024

    auto primes = sieve(20);             // 2 3 5 7 11 13 17 19

    vll nums = {1, 2, 3};
    auto pref = prefixSum(nums);         // 0 1 3 6
}
```

---

## Install via vcpkg (overlay port)

1. Copy the `vcpkg-ports/cputils/` folder into your project.
2. Run:
```bash
vcpkg install cputils --overlay-ports=./vcpkg-ports
```
3. In your `CMakeLists.txt`:
```cmake
find_package(cputils CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE cputils::cputils)
```

---

## CMake FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(
    cputils
    GIT_REPOSITORY https://github.com/himaenshuu/cputils.git
    GIT_TAG        v1.0.0
)
FetchContent_MakeAvailable(cputils)
target_link_libraries(your_target PRIVATE cputils)
```

---

## Contributing

PRs welcome! Planned additions:
- String helpers
- Graph input readers
- Segment tree / BIT templates

---

## Made with love ❤️
