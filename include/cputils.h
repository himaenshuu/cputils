#ifndef CPUTILS_H
#define CPUTILS_H

#include <vector>
#include <iostream>
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
typedef std::vector<std::vector<int>> vvi;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

#endif // CPUTILS_H
