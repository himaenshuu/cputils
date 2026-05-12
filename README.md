# cputils

A lightweight, single-header C++17 utility library for **competitive programming** and **DSA**.
No build step. No third-party dependencies. Just `#include` and go.

---

## Install in 5 Seconds

**Windows (PowerShell):**
```powershell
Invoke-WebRequest -UseBasicParsing -Uri "https://github.com/himaenshuu/cputils/releases/latest/download/cputils.h" -OutFile "cputils.h"
```

**Linux / macOS:**
```bash
curl -fsSL https://github.com/himaenshuu/cputils/releases/latest/download/cputils.h -o cputils.h
```

**Script installer:**
```powershell
.\scripts\install.ps1
```

```bash
sh scripts/install.sh
```

Both scripts download the latest release asset and overwrite `cputils.h` in the target path.

Then in your solution:
```cpp
#include "cputils.h"

int main() {
    fastIO();

    return 0;
}
```

Start from [`templates/main.cpp`](templates/main.cpp) when you want a ready-to-copy contest file.

---

## What this repo provides

This repository is intentionally small: the public API lives in [`include/cputils.h`](include/cputils.h), and the CMake/vcpkg files only package that header. After reviewing the original utilities, the most useful additions for CP users are helpers that remove repeated boilerplate in nearly every contest:

- numeric helpers for `gcd`, `lcm`, division, and modular arithmetic;
- prime helpers for quick primality checks and sieve generation;
- common state-update helpers like `chmax` / `chmin`;
- prefix sums for range-sum setup;
- graph input, DSU, and Fenwick Tree implementations;
- input/output and debug helpers for fast local testing.

---

## Features

| Category | Utility | What it does |
|---|---|---|
| I/O | `fastIO()` | Disables sync with C stdio and unties `cin` from `cout` |
| I/O | `print1d(v, sep, end)` | Prints any `vector<T>` with configurable separator/end characters |
| I/O | `print2d(v, sep)` | Prints any `vector<vector<T>>`, one row per line |
| I/O | `printPair(p)` | Prints a `pair<A, B>` as `(first, second)` |
| I/O | `printPairs(v)` | Prints a `vector<pair<A, B>>`, one pair per line |
| I/O | `readVector<T>(n)` | Reads and returns a vector of `n` values from `cin`; rejects negative sizes |
| Graphs | `readGraph(n, m, directed, oneIndexed)` | Reads an unweighted adjacency list from `m` valid edges |
| Debug | `dbg(x)` | Prints `name = value` to `cerr` when `ONLINE_JUDGE` is not defined |
| Debug | `dbgv(v)` | Prints vector contents to `cerr` when `ONLINE_JUDGE` is not defined |
| Types | `ll`, `ull`, `pii`, `vi`, `vvi` | Common aliases for contest code |
| Version | `CPUTILS_VERSION` | Header version string for local verification |
| Updates | `chmax(a, b)` | Assigns `a = b` when `b` is larger; returns whether it changed |
| Updates | `chmin(a, b)` | Assigns `a = b` when `b` is smaller; returns whether it changed |
| Math | `gcd(a, b)` | Non-negative greatest common divisor for `long long` values, with overflow detection |
| Math | `lcm(a, b)` | Non-negative least common multiple; returns `0` if either input is `0`; detects overflow |
| Math | `floorDiv(a, b)` | Mathematical floor of integer division, including negative inputs; rejects invalid division |
| Math | `ceilDiv(a, b)` | Mathematical ceiling of integer division, including negative inputs; rejects invalid division |
| Mod math | `normalizeMod(a, mod)` | Converts `a` into the range `[0, mod)` for positive moduli |
| Mod math | `modAdd(a, b, mod)` | Modular addition |
| Mod math | `modSub(a, b, mod)` | Modular subtraction |
| Mod math | `modMul(a, b, mod)` | Overflow-safe modular multiplication (`__int128` when available, fallback otherwise) |
| Mod math | `modPow(base, exp, mod)` | Binary exponentiation under a positive modulus and non-negative exponent |
| Mod math | `extendedGcd(a, b, x, y)` | Extended Euclidean algorithm; fills Bezout coefficients |
| Mod math | `modInverse(a, mod)` | Modular inverse, or `-1` when it does not exist |
| Primes | `isPrime(n)` | Trial-division primality check |
| Primes | `sieve(n)` | Returns all primes `<= n` |
| Arrays | `prefixSums(v)` | Returns prefix sums with a leading zero: `pref[i+1] = sum(v[0..i])` |
| DS | `DSU` | Disjoint Set Union with path compression, union by size, and bounds checks |
| DS | `Fenwick<T>` | Binary Indexed Tree for checked point updates and prefix/range sums |

---

## Quick install (raw main)

**Linux / macOS:**
```bash
curl -fsSL https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h -o cputils.h
```

**Windows (PowerShell):**
```powershell
Invoke-WebRequest -UseBasicParsing -Uri "https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h" -OutFile "cputils.h"
```

> Note: On Windows, `wget` and `curl` are often aliases for `Invoke-WebRequest` and may not save the file without `-OutFile`. Use the command above if you are in PowerShell.

Then in your solution:
```cpp
#include "cputils.h"

int main() {
    fastIO();

    vi v = {1, 2, 3, 4};
    print1d(v);              // 1 2 3 4

    dbg(v.size());           // v.size() = 4  (only in local builds)

    ll a = 12, b = 18;
    std::cout << gcd(a, b);  // 6
}
```

For stable installs, prefer the latest-release commands at the top of this README.

---

## API guide and examples

### Examples

Ready-to-run examples live in [`examples/`](examples):

| File | Focus |
|---|---|
| [`basic.cpp`](examples/basic.cpp) | Include setup, printing, and math helpers |
| [`graph.cpp`](examples/graph.cpp) | Reading an adjacency list |
| [`dsu.cpp`](examples/dsu.cpp) | Disjoint Set Union usage |
| [`fenwick.cpp`](examples/fenwick.cpp) | Point updates and range sums |
| [`mod_math.cpp`](examples/mod_math.cpp) | Modular arithmetic helpers |

### Fast I/O

```cpp
int main() {
    fastIO();
    int n;
    std::cin >> n;
}
```

Call `fastIO()` once at the start of `main()` for typical contest input.

### Printing helpers

```cpp
vi a = {1, 2, 3};
vvi grid = {{1, 2}, {3, 4}};
pii edge = {2, 5};

print1d(a);                 // 1 2 3
print1d(a, ',');            // 1,2,3
print2d(grid);              // 1 2\n3 4
printPair(edge);            // (2, 5)
printPairs(vector<pii>{{1, 2}, {3, 4}});
```

`print1d` and `print2d` are templates, so they work with any printable element type.

### Reading a vector

```cpp
int n;
std::cin >> n;
auto a = readVector<ll>(n);
```

This is useful for the common pattern of reading `n` followed by an array.

### Reading a graph

```cpp
int n, m;
std::cin >> n >> m;
auto graph = readGraph(n, m);        // undirected, 1-indexed input converted to 0-indexed
auto directed = readGraph(n, m, true);
auto zeroIndexed = readGraph(n, m, false, false);
```

`readGraph` returns `vector<vector<int>>`. By default, it expects common CP-style 1-indexed edge input and stores 0-indexed adjacency lists. Vertex ids outside the selected indexing mode throw `std::out_of_range`.

### Debug macros

```cpp
int answer = 42;
vi a = {1, 2, 3};

dbg(answer);  // answer = 42
dbgv(a);      // a = [ 1 2 3 ]
```

`dbg` and `dbgv` compile to no-ops when `ONLINE_JUDGE` is defined.

### State-update helpers

```cpp
int best = -1;
if (chmax(best, score)) {
    // best changed
}

int low = 1e9;
chmin(low, candidate);
```

These helpers reduce noise in DP, greedy, and graph solutions.

### GCD, LCM, and signed division

```cpp
std::cout << gcd(-12, 8);     // 4
std::cout << lcm(-4, 6);      // 12
std::cout << floorDiv(-7, 3); // -3
std::cout << ceilDiv(-7, 3);  // -2
```

`floorDiv` and `ceilDiv` implement mathematical floor/ceiling division instead of C++'s truncation toward zero. They throw `std::invalid_argument` for division by zero and `std::overflow_error` for `LLONG_MIN / -1`.

### Modular arithmetic

```cpp
const ll MOD = 1'000'000'007;

ll x = normalizeMod(-3, MOD);       // MOD - 3
ll y = modPow(2, 10, MOD);          // 1024
ll inv = modInverse(3, 11);         // 4, because 3 * 4 = 1 mod 11
ll bad = modInverse(2, 4);          // -1, inverse does not exist
ll prod = modMul(1e18, 1e18, MOD);  // avoids long long multiplication overflow
```

All modular helpers require `mod > 0`. `modPow` also requires `exp >= 0`. `modInverse(a, mod)` works when `gcd(a, mod) == 1`; it does not require `mod` to be prime.

### Prime helpers

```cpp
if (isPrime(n)) {
    // n is prime
}

auto primes = sieve(100); // 2, 3, 5, ..., 97
```

`isPrime` uses trial division and is best for occasional checks. Use `sieve(n)` when you need all primes up to `n`.

### Prefix sums

```cpp
vector<ll> a = {2, 4, 6};
auto pref = prefixSums(a); // {0, 2, 6, 12}

// sum on inclusive range [l, r]
ll range = pref[r + 1] - pref[l];
```

### Disjoint Set Union (DSU)

```cpp
DSU dsu(n);
dsu.unite(0, 1);

if (dsu.same(0, 1)) {
    std::cout << dsu.size(0);
}
```

Available methods:

| Method | Description |
|---|---|
| `DSU(n)` | Creates `n` singleton sets indexed `0..n-1` |
| `init(n)` | Resets the DSU to `n` singleton sets |
| `find(x)` | Returns the representative of `x` |
| `unite(a, b)` | Merges components and returns whether a merge happened |
| `same(a, b)` | Returns whether two elements are in the same component |
| `size(x)` | Returns the size of `x`'s component |

DSU operations throw `std::out_of_range` when an index is outside `0..n-1`.

### Fenwick Tree / Binary Indexed Tree

```cpp
Fenwick<ll> fw(n);
fw.add(0, 5);
fw.add(3, 2);

ll prefix = fw.sumPrefix(3); // sum on [0, 3]
ll range = fw.rangeSum(1, 3); // sum on [1, 3]
```

Available methods:

| Method | Description |
|---|---|
| `Fenwick<T>(n)` | Creates a tree of size `n`, indexed externally as `0..n-1` |
| `init(n)` | Resets the tree to size `n` with zero values |
| `add(index, delta)` | Adds `delta` to `index` |
| `sumPrefix(index)` | Returns the sum on `[0, index]` |
| `rangeSum(left, right)` | Returns the sum on `[left, right]`; returns zero for an empty range |

Fenwick operations throw `std::out_of_range` for invalid indices or ranges. `sumPrefix(-1)` returns zero, which is useful when computing ranges.

### Error handling

The library validates inputs that would otherwise cause undefined behavior, infinite loops, or out-of-bounds access. It uses standard exceptions from `<stdexcept>`:

| Exception | Used for |
|---|---|
| `std::invalid_argument` | Negative sizes, non-positive modulus, division by zero, or negative modular exponent |
| `std::out_of_range` | Invalid graph, DSU, or Fenwick indices |
| `std::overflow_error` | Results that cannot fit in `long long` |

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
    GIT_TAG        v1.1.0
)
FetchContent_MakeAvailable(cputils)
target_link_libraries(your_target PRIVATE cputils)
```

---

## Testing locally

```bash
cmake -S . -B build -DCPUTILS_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

---

## Contributing

PRs welcome! Useful future additions could include:

- shortest path templates;
- segment tree and lazy segment tree templates;
- rolling hash helpers for strings;
- coordinate compression helpers;
- combinatorics helpers for factorials, inverse factorials, and `nCr` modulo a prime.

---

## Made with care
