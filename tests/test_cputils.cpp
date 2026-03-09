#include "cputils.h"
#include <cassert>
#include <sstream>
#include <iostream>

int main() {
    // --- gcd / lcm ---
    assert(gcd(12, 8) == 4);
    assert(gcd(0, 5) == 5);
    assert(lcm(4, 6) == 12);
    assert(lcm(7, 1) == 7);

    // --- type aliases compile ---
    ll  big   = 1000000000LL * 1000000000LL;
    ull ubig  = 18000000000000000000ULL;
    pii p     = {3, 7};
    vi  v     = {1, 2, 3};
    vvi vv    = {{1, 2}, {3, 4}};
    (void)big; (void)ubig;

    // --- printPair / printPairs (smoke-test, just must not crash) ---
    printPair(p);
    printPairs(std::vector<pii>{{1,2},{3,4}});

    // --- print1d / print2d ---
    print1d(v);
    print2d(vv);

    // --- fastIO ---
    fastIO();

    // --- dbg macro (should produce output since ONLINE_JUDGE is not defined) ---
    int x = 42;
    dbg(x);
    dbgv(v);

    std::cout << "All tests passed!\n";
    return 0;
}
