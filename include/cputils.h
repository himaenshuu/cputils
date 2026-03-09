#ifndef CPUTILS_H
#define CPUTILS_H

#include <vector>
#include <iostream>

using namespace std;

// ─── 1D / 2D Array Printers ─────────────────────────────────────────────────

inline void print1d(const vector<int>& v) {
    for (const auto& el : v) cout << el << " ";
    cout << "\n";
}

inline void print2d(const vector<vector<int>>& v) {
    for (const auto& row : v) {
        for (const auto& el : row) cout << el << " ";
        cout << "\n";
    }
}

// ─── Pair / Tuple Printers ───────────────────────────────────────────────────

template <typename A, typename B>
inline void printPair(const pair<A, B>& p) {
    cout << "(" << p.first << ", " << p.second << ")\n";
}

template <typename A, typename B>
inline void printPairs(const vector<pair<A, B>>& v) {
    for (const auto& p : v) printPair(p);
}

// ─── Fast I/O ────────────────────────────────────────────────────────────────

inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ─── Debug Macro (disabled in online judges via ONLINE_JUDGE) ────────────────

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " = " << x << "\n"
#define dbgv(v) do { cerr << #v << " = [ "; for (const auto& _e : v) cerr << _e << " "; cerr << "]\n"; } while(0)
#else
#define dbg(x)
#define dbgv(v)
#endif

// ─── Common Typedefs ─────────────────────────────────────────────────────────

typedef long long           ll;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<int>         vi;
typedef vector<vector<int>> vvi;

// ─── Math Helpers ────────────────────────────────────────────────────────────

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

#endif // CPUTILS_H
