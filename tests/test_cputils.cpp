#include "cputils.h"
#include <cassert>
#include <sstream>
#include <iostream>

int main() {
    
    assert(gcd(12, 8) == 4);
    assert(gcd(0, 5) == 5);
    assert(gcd(-12, 8) == 4);
    assert(gcd(-12, -8) == 4);
    assert(lcm(4, 6) == 12);
    assert(lcm(7, 1) == 7);
    assert(lcm(-4, 6) == 12);
    assert(lcm(0, 6) == 0);

    int best = 10;
    assert(chmin(best, 7));
    assert(best == 7);
    assert(!chmin(best, 9));
    assert(chmax(best, 12));
    assert(best == 12);
    assert(!chmax(best, 11));

    assert(modNormalize(-3, 5) == 2);
    assert(modPow(2, 10, 1000000007) == 1024);
    assert(modPow(-2, 3, 5) == 2);
    assert(isPrime(2));
    assert(isPrime(97));
    assert(!isPrime(1));
    assert(!isPrime(100));
    assert((sieve(10) == vi{2, 3, 5, 7}));
    assert((prefixSum(vll{1, 2, 3}) == vll{0, 1, 3, 6}));

    ll  big   = 1000000000LL * 1000000000LL;
    ull ubig  = 18000000000000000000ULL;
    pii p     = {3, 7};
    vi  v     = {1, 2, 3};
    vvi vv    = {{1, 2}, {3, 4}};
    (void)big; (void)ubig;

    printPair(p);
    printPairs(std::vector<pii>{{1,2},{3,4}});
    
    print1d(v);
    print2d(vv);

    fastIO();

    int x = 42;
    dbg(x);
    dbgv(v);

    std::cout << "All tests passed!\n";
    return 0;
}
