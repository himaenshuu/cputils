#ifndef CPUTILS_H
#define CPUTILS_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

inline constexpr const char* CPUTILS_VERSION = "1.1.0";

namespace cputils_detail {
inline ull magnitude(ll value) {
    if (value >= 0) return static_cast<ull>(value);
    return static_cast<ull>(-(value + 1)) + 1ULL;
}

inline ll checkedSignedMagnitude(ull value) {
    if (value > static_cast<ull>(std::numeric_limits<ll>::max())) {
        throw std::overflow_error("result does not fit in long long");
    }
    return static_cast<ll>(value);
}

inline void requirePositiveMod(ll mod) {
    if (mod <= 0) throw std::invalid_argument("mod must be positive");
}

inline void requireValidDivision(ll a, ll b) {
    if (b == 0) throw std::invalid_argument("divisor must be non-zero");
    if (a == std::numeric_limits<ll>::min() && b == -1) {
        throw std::overflow_error("division result does not fit in long long");
    }
}

inline void requireVertex(int vertex, int n) {
    if (vertex < 0 || vertex >= n) throw std::out_of_range("graph vertex out of range");
}
}

// Enables faster standard input and output.
inline void fastIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// Prints a one-dimensional vector with configurable separators.
template <typename T>
inline void print1d(const std::vector<T>& v, char sep = ' ', char end = '\n') {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << sep;
        std::cout << v[i];
    }
    std::cout << end;
}

// Prints a two-dimensional vector row by row.
template <typename T>
inline void print2d(const std::vector<std::vector<T>>& v, char sep = ' ') {
    for (const auto& row : v) print1d(row, sep);
}

// Prints a pair in a readable format.
template <typename A, typename B>
inline void printPair(const std::pair<A, B>& p) {
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

// Prints a vector of pairs, one pair per line.
template <typename A, typename B>
inline void printPairs(const std::vector<std::pair<A, B>>& v) {
    for (const auto& p : v) printPair(p);
}

// Reads n values from standard input into a vector.
template <typename T>
inline std::vector<T> readVector(int n) {
    if (n < 0) throw std::invalid_argument("vector size must be non-negative");
    std::vector<T> v(n);
    for (auto& x : v) std::cin >> x;
    return v;
}

#ifndef ONLINE_JUDGE
#define dbg(x) std::cerr << #x << " = " << x << "\n"
#define dbgv(v) do { std::cerr << #v << " = [ "; for (const auto& _e : v) std::cerr << _e << " "; std::cerr << "]\n"; } while(0)
#else
#define dbg(x)
#define dbgv(v)
#endif

// Updates a value when the candidate is larger.
template <typename T, typename U>
inline bool chmax(T& a, const U& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// Updates a value when the candidate is smaller.
template <typename T, typename U>
inline bool chmin(T& a, const U& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// Returns the non-negative greatest common divisor.
inline ll gcd(ll a, ll b) {
    ull x = cputils_detail::magnitude(a);
    ull y = cputils_detail::magnitude(b);
    while (y != 0) {
        ull t = x % y;
        x = y;
        y = t;
    }
    return cputils_detail::checkedSignedMagnitude(x);
}

// Returns the non-negative least common multiple.
inline ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    ll g = gcd(a, b);
    ull left = cputils_detail::magnitude(a / g);
    ull right = cputils_detail::magnitude(b);
#if defined(__SIZEOF_INT128__)
    __uint128_t result = static_cast<__uint128_t>(left) * right;
    if (result > static_cast<__uint128_t>(std::numeric_limits<ll>::max())) {
        throw std::overflow_error("lcm result does not fit in long long");
    }
    return static_cast<ll>(result);
#else
    if (left != 0 && right > static_cast<ull>(std::numeric_limits<ll>::max()) / left) {
        throw std::overflow_error("lcm result does not fit in long long");
    }
    return static_cast<ll>(left * right);
#endif
}

// Returns floor(a / b) for signed integers.
inline ll floorDiv(ll a, ll b) {
    cputils_detail::requireValidDivision(a, b);
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) != (b > 0))) --q;
    return q;
}

// Returns ceil(a / b) for signed integers.
inline ll ceilDiv(ll a, ll b) {
    cputils_detail::requireValidDivision(a, b);
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) == (b > 0))) ++q;
    return q;
}

// Normalizes a value into the range [0, mod).
inline ll normalizeMod(ll a, ll mod) {
    cputils_detail::requirePositiveMod(mod);
    a %= mod;
    if (a < 0) a += mod;
    return a;
}

// Adds two values under a positive modulus.
inline ll modAdd(ll a, ll b, ll mod) {
    return (normalizeMod(a, mod) + normalizeMod(b, mod)) % mod;
}

// Subtracts two values under a positive modulus.
inline ll modSub(ll a, ll b, ll mod) {
    return normalizeMod(normalizeMod(a, mod) - normalizeMod(b, mod), mod);
}

// Multiplies two values under a positive modulus without overflow.
inline ll modMul(ll a, ll b, ll mod) {
    a = normalizeMod(a, mod);
    b = normalizeMod(b, mod);
#if defined(__SIZEOF_INT128__)
    return static_cast<ll>((__int128)a * b % mod);
#else
    ll result = 0;
    while (b > 0) {
        if (b & 1LL) result = modAdd(result, a, mod);
        a = modAdd(a, a, mod);
        b >>= 1LL;
    }
    return result;
#endif
}

// Computes base raised to exp under a positive modulus.
inline ll modPow(ll base, ll exp, ll mod) {
    cputils_detail::requirePositiveMod(mod);
    if (exp < 0) throw std::invalid_argument("exponent must be non-negative");
    ll result = 1 % mod;
    base = normalizeMod(base, mod);
    while (exp > 0) {
        if (exp & 1LL) result = modMul(result, base, mod);
        base = modMul(base, base, mod);
        exp >>= 1LL;
    }
    return result;
}

// Computes gcd and Bezout coefficients for two integers.
inline ll extendedGcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return a >= 0 ? a : -a;
    }
    ll x1 = 0, y1 = 0;
    ll g = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Returns the modular inverse, or -1 when it does not exist.
inline ll modInverse(ll a, ll mod) {
    cputils_detail::requirePositiveMod(mod);
    ll x = 0, y = 0;
    ll g = extendedGcd(a, mod, x, y);
    if (g != 1) return -1;
    return normalizeMod(x, mod);
}

// Checks whether a number is prime by trial division.
inline bool isPrime(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (ll d = 3; d <= n / d; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

// Returns all primes less than or equal to n.
inline std::vector<int> sieve(int n) {
    if (n < 2) return {};

    std::vector<bool> composite(n + 1, false);
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (!composite[i]) {
            primes.push_back(i);
            if (1LL * i * i <= n) {
                for (long long j = 1LL * i * i; j <= n; j += i) composite[static_cast<std::size_t>(j)] = true;
            }
        }
    }
    return primes;
}

// Reads an unweighted graph into an adjacency list.
inline std::vector<std::vector<int>> readGraph(int n, int m, bool directed = false, bool oneIndexed = true) {
    if (n < 0) throw std::invalid_argument("vertex count must be non-negative");
    if (m < 0) throw std::invalid_argument("edge count must be non-negative");
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        if (oneIndexed) {
            --u;
            --v;
        }
        cputils_detail::requireVertex(u, n);
        cputils_detail::requireVertex(v, n);
        graph[u].push_back(v);
        if (!directed) graph[v].push_back(u);
    }
    return graph;
}

// Builds prefix sums with a leading zero value.
template <typename T>
inline std::vector<T> prefixSums(const std::vector<T>& v) {
    std::vector<T> pref(v.size() + 1, T{});
    for (std::size_t i = 0; i < v.size(); ++i) pref[i + 1] = pref[i] + v[i];
    return pref;
}

// Maintains disjoint sets with union by size and path compression.
class DSU {
    std::vector<int> parent;
    std::vector<int> componentSize;

public:
    explicit DSU(int n = 0) { init(n); }

    // Reinitializes the structure with n singleton sets.
    void init(int n) {
        if (n < 0) throw std::invalid_argument("DSU size must be non-negative");
        parent.resize(n);
        componentSize.assign(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Returns the representative of the set containing x.
    int find(int x) {
        if (x < 0 || x >= static_cast<int>(parent.size())) throw std::out_of_range("DSU index out of range");
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // Merges two sets and returns whether a merge happened.
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (componentSize[a] < componentSize[b]) std::swap(a, b);
        parent[b] = a;
        componentSize[a] += componentSize[b];
        return true;
    }

    // Checks whether two elements are in the same set.
    bool same(int a, int b) { return find(a) == find(b); }

    // Returns the size of the set containing x.
    int size(int x) { return componentSize[find(x)]; }
};

// Supports point updates and prefix/range sum queries.
template <typename T>
class Fenwick {
    int n = 0;
    std::vector<T> bit;

public:
    explicit Fenwick(int n = 0) { init(n); }

    // Reinitializes the tree with the given size.
    void init(int size) {
        if (size < 0) throw std::invalid_argument("Fenwick size must be non-negative");
        n = size;
        bit.assign(n + 1, T{});
    }

    // Adds delta to one zero-based index.
    void add(int index, T delta) {
        if (index < 0 || index >= n) throw std::out_of_range("Fenwick index out of range");
        for (++index; index <= n; index += index & -index) bit[index] += delta;
    }

    // Returns the sum from index 0 through index.
    T sumPrefix(int index) const {
        if (index < 0) return T{};
        if (index >= n) throw std::out_of_range("Fenwick index out of range");
        T result{};
        for (++index; index > 0; index -= index & -index) result += bit[index];
        return result;
    }

    // Returns the sum over the inclusive range [left, right].
    T rangeSum(int left, int right) const {
        if (left > right) return T{};
        if (left < 0 || right >= n) throw std::out_of_range("Fenwick range out of range");
        return sumPrefix(right) - (left == 0 ? T{} : sumPrefix(left - 1));
    }
};

#endif // CPUTILS_H
