#ifndef CPUTILS_H
#define CPUTILS_H

#include <iostream>
#include <vector>
#include <utility>

inline void print1d(const std::vector<int>& v) {
    for (const auto& el : v) std::cout << el << " ";
    std::cout << "\n";
}

inline void print2d(const std::vector<std::vector<int>>& v) {
    for (const auto& row : v) {
        for (const auto& el : row) std::cout << el << " ";
        std::cout << "\n";
    }
}

template <typename A, typename B>
inline void printPair(const std::pair<A, B>& p) {
    std::cout << "(" << p.first << ", " << p.second << ")\n";
}

template <typename A, typename B>
inline void printPairs(const std::vector<std::pair<A, B>>& v) {
    for (const auto& p : v) printPair(p);
}

inline void fastIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

#ifndef ONLINE_JUDGE
#define dbg(x) std::cerr << #x << " = " << x << "\n"
#define dbgv(v) do { std::cerr << #v << " = [ "; for (const auto& _e : v) std::cerr << _e << " "; std::cerr << "]\n"; } while(0)
#else
#define dbg(x)
#define dbgv(v)
#endif

typedef long long           ll;
typedef unsigned long long  ull;
typedef std::pair<int, int>      pii;
typedef std::vector<int>         vi;
typedef std::vector<long long>   vll;
typedef std::vector<std::vector<int>> vvi;

template <typename T>
inline bool chmin(T& current, const T& candidate) {
    if (candidate < current) {
        current = candidate;
        return true;
    }

    return false;
}

template <typename T>
inline bool chmax(T& current, const T& candidate) {
    if (current < candidate) {
        current = candidate;
        return true;
    }

    return false;
}

inline ll absll(ll value) {
    return value < 0 ? -value : value;
}

inline ll gcd(ll a, ll b) {
    a = absll(a);
    b = absll(b);

    while (b != 0) {
        const ll remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

inline ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return absll(a / gcd(a, b) * b);
}

inline ll modNormalize(ll value, ll mod) {
    value %= mod;
    if (value < 0) value += mod;
    return value;
}

inline ll modPow(ll base, ll exponent, ll mod) {
    if (mod == 1) return 0;

    ll result = 1 % mod;
    base = modNormalize(base, mod);

    while (exponent > 0) {
        if (exponent & 1LL) result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1LL;
    }

    return result;
}

inline bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll divisor = 3; divisor <= n / divisor; divisor += 2) {
        if (n % divisor == 0) return false;
    }

    return true;
}

inline vi sieve(int n) {
    vi primes;
    if (n < 2) return primes;

    std::vector<bool> composite(n + 1, false);
    for (int value = 2; value <= n; ++value) {
        if (composite[value]) continue;

        primes.push_back(value);
        if (value > n / value) continue;

        for (int multiple = value * value; multiple <= n; multiple += value) {
            composite[multiple] = true;
        }
    }

    return primes;
}

inline vll prefixSum(const vll& v) {
    vll prefix(v.size() + 1, 0);
    for (std::size_t i = 0; i < v.size(); ++i) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    return prefix;
}

#endif // CPUTILS_H
