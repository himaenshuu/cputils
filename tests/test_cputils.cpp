#include "cputils.h"
#include <cassert>
#include <limits>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    assert(std::string(CPUTILS_VERSION) == "1.1.0");

    assert(gcd(12, 8) == 4);
    assert(gcd(-12, 8) == 4);
    assert(gcd(0, 5) == 5);
    assert(gcd(std::numeric_limits<ll>::min(), 2) == 2);
    assert(lcm(4, 6) == 12);
    assert(lcm(-4, 6) == 12);
    assert(lcm(0, 6) == 0);
    assert(lcm(7, 1) == 7);
    try {
        (void)gcd(std::numeric_limits<ll>::min(), 0);
        assert(false);
    } catch (const std::overflow_error&) {
    }
    try {
        (void)lcm(std::numeric_limits<ll>::max(), 2);
        assert(false);
    } catch (const std::overflow_error&) {
    }

    assert(floorDiv(7, 3) == 2);
    assert(floorDiv(-7, 3) == -3);
    assert(ceilDiv(7, 3) == 3);
    assert(ceilDiv(-7, 3) == -2);
    try {
        (void)floorDiv(1, 0);
        assert(false);
    } catch (const std::invalid_argument&) {
    }

    assert(normalizeMod(-1, 5) == 4);
    assert(modAdd(4, 3, 5) == 2);
    assert(modSub(2, 5, 7) == 4);
    assert(modMul(1000000000000000000LL, 2, 1000000007LL) == 98);
    assert(modPow(2, 10, 1000000007LL) == 1024);
    assert(modInverse(3, 11) == 4);
    assert(modInverse(2, 4) == -1);
    try {
        (void)normalizeMod(1, 0);
        assert(false);
    } catch (const std::invalid_argument&) {
    }
    try {
        (void)modPow(2, -1, 5);
        assert(false);
    } catch (const std::invalid_argument&) {
    }

    assert(isPrime(2));
    assert(isPrime(97));
    assert(!isPrime(1));
    assert(!isPrime(100));
    assert((sieve(-5) == std::vector<int>{}));
    assert((sieve(12) == std::vector<int>{2, 3, 5, 7, 11}));

    ll  big   = 1000000000LL * 1000000000LL;
    ull ubig  = 18000000000000000000ULL;
    pii p     = {3, 7};
    vi  v     = {1, 2, 3};
    vvi vv    = {{1, 2}, {3, 4}};
    (void)big; (void)ubig;

    printPair(p);
    printPairs(std::vector<pii>{{1, 2}, {3, 4}});
    print1d(v);
    print2d(vv);
    print1d(std::vector<std::string>{"a", "b"}, ',');

    int best = 10;
    assert(chmax(best, 20));
    assert(best == 20);
    assert(!chmax(best, 15));
    assert(chmin(best, 5));
    assert(best == 5);

    auto pref = prefixSums(std::vector<ll>{2, 4, 6});
    assert((pref == std::vector<ll>{0, 2, 6, 12}));

    DSU dsu(5);
    assert(dsu.unite(0, 1));
    assert(dsu.unite(3, 4));
    assert(dsu.same(0, 1));
    assert(!dsu.same(0, 3));
    assert(dsu.size(0) == 2);
    assert(!dsu.unite(1, 0));

    Fenwick<ll> fw(5);
    fw.add(0, 5);
    fw.add(1, 3);
    fw.add(4, 2);
    assert(fw.sumPrefix(1) == 8);
    assert(fw.rangeSum(1, 4) == 5);
    assert(fw.rangeSum(3, 2) == 0);

    std::istringstream input("10 20 30");
    auto* oldCin = std::cin.rdbuf(input.rdbuf());
    auto read = readVector<int>(3);
    std::cin.rdbuf(oldCin);
    assert((read == std::vector<int>{10, 20, 30}));
    try {
        (void)readVector<int>(-1);
        assert(false);
    } catch (const std::invalid_argument&) {
    }

    std::istringstream graphInput("1 2 2 3 1 3");
    oldCin = std::cin.rdbuf(graphInput.rdbuf());
    auto graph = readGraph(3, 3);
    std::cin.rdbuf(oldCin);
    assert((graph == std::vector<std::vector<int>>{{1, 2}, {0, 2}, {1, 0}}));
    try {
        std::istringstream badGraphInput("1 4");
        oldCin = std::cin.rdbuf(badGraphInput.rdbuf());
        (void)readGraph(3, 1);
        std::cin.rdbuf(oldCin);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cin.rdbuf(oldCin);
    }

    try {
        dsu.find(-1);
        assert(false);
    } catch (const std::out_of_range&) {
    }

    try {
        fw.add(-1, 1);
        assert(false);
    } catch (const std::out_of_range&) {
    }
    try {
        (void)fw.sumPrefix(5);
        assert(false);
    } catch (const std::out_of_range&) {
    }
    try {
        (void)fw.rangeSum(-1, 1);
        assert(false);
    } catch (const std::out_of_range&) {
    }

    fastIO();

    int x = 42;
    dbg(x);
    dbgv(v);

    std::cout << "All tests passed!\n";
    return 0;
}
