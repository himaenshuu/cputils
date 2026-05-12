#ifndef CPUTILS_H
#define CPUTILS_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

inline void fastIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

template <typename T>
inline void print1d(const std::vector<T>& v, char sep = ' ', char end = '\n') {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << sep;
        std::cout << v[i];
    }
    std::cout << end;
}

template <typename T>
inline void print2d(const std::vector<std::vector<T>>& v, char sep = ' ') {
    for (const auto& row : v) print1d(row, sep);
}

template <typename A, typename B>
inline void printPair(const std::pair<A, B>& p) {
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

template <typename A, typename B>
inline void printPairs(const std::vector<std::pair<A, B>>& v) {
    for (const auto& p : v) printPair(p);
}

template <typename T>
inline std::vector<T> readVector(int n) {
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

template <typename T, typename U>
inline bool chmax(T& a, const U& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T, typename U>
inline bool chmin(T& a, const U& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

inline ll gcd(ll a, ll b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

inline ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    ll g = gcd(a, b);
    ll ans = (a / g) * b;
    return ans < 0 ? -ans : ans;
}

inline ll floorDiv(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) != (b > 0))) --q;
    return q;
}

inline ll ceilDiv(ll a, ll b) {
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r > 0) == (b > 0))) ++q;
    return q;
}

inline ll normalizeMod(ll a, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
}

inline ll modAdd(ll a, ll b, ll mod) {
    return (normalizeMod(a, mod) + normalizeMod(b, mod)) % mod;
}

inline ll modSub(ll a, ll b, ll mod) {
    return normalizeMod(normalizeMod(a, mod) - normalizeMod(b, mod), mod);
}

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

inline ll modPow(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base = normalizeMod(base, mod);
    while (exp > 0) {
        if (exp & 1LL) result = modMul(result, base, mod);
        base = modMul(base, base, mod);
        exp >>= 1LL;
    }
    return result;
}

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

inline ll modInverse(ll a, ll mod) {
    ll x = 0, y = 0;
    ll g = extendedGcd(a, mod, x, y);
    if (g != 1) return -1;
    return normalizeMod(x, mod);
}

inline bool isPrime(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (ll d = 3; d <= n / d; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

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

inline std::vector<std::vector<int>> readGraph(int n, int m, bool directed = false, bool oneIndexed = true) {
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        if (oneIndexed) {
            --u;
            --v;
        }
        graph[u].push_back(v);
        if (!directed) graph[v].push_back(u);
    }
    return graph;
}

template <typename T>
inline std::vector<T> prefixSums(const std::vector<T>& v) {
    std::vector<T> pref(v.size() + 1, T{});
    for (std::size_t i = 0; i < v.size(); ++i) pref[i + 1] = pref[i] + v[i];
    return pref;
}

class DSU {
    std::vector<int> parent;
    std::vector<int> componentSize;

public:
    explicit DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n);
        componentSize.assign(n, 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (componentSize[a] < componentSize[b]) std::swap(a, b);
        parent[b] = a;
        componentSize[a] += componentSize[b];
        return true;
    }

    bool same(int a, int b) { return find(a) == find(b); }

    int size(int x) { return componentSize[find(x)]; }
};

template <typename T>
class Fenwick {
    int n = 0;
    std::vector<T> bit;

public:
    explicit Fenwick(int n = 0) { init(n); }

    void init(int size) {
        n = size;
        bit.assign(n + 1, T{});
    }

    void add(int index, T delta) {
        for (++index; index <= n; index += index & -index) bit[index] += delta;
    }

    T sumPrefix(int index) const {
        T result{};
        for (++index; index > 0; index -= index & -index) result += bit[index];
        return result;
    }

    T rangeSum(int left, int right) const {
        if (left > right) return T{};
        return sumPrefix(right) - (left == 0 ? T{} : sumPrefix(left - 1));
    }
};

#endif // CPUTILS_H
