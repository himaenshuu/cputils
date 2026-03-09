# cputils

A lightweight, single-header C++ utility library for **Competitive Programming** and **DSA**.  
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
| `gcd(a, b)` | GCD of two `long long` values |
| `lcm(a, b)` | LCM of two `long long` values |
| `ll`, `vi`, `vvi`, `pii` | Common typedefs |

---

## Quick Install (recommended for CP)

```bash
curl -O https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h
```

Or with `wget`:
```bash
wget https://raw.githubusercontent.com/himaenshuu/cputils/main/include/cputils.h
```

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

## Manual / CMake FetchContent

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

## Debug macros

The `dbg` and `dbgv` macros print to `stderr` only when `ONLINE_JUDGE` is **not** defined.  
Most online judges (Codeforces, LeetCode, etc.) define `ONLINE_JUDGE` automatically, so your debug output is silently stripped — no need to remove it before submitting.

---

## Contributing

PRs welcome! Planned additions:
- String helpers
- Graph input readers
- Segment tree / BIT templates

---

## License

MIT
