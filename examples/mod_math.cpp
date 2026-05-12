#include "cputils.h"

int main() {
    fastIO();

    const ll mod = 1000000007LL;

    std::cout << normalizeMod(-3, mod) << '\n';
    std::cout << modPow(2, 10, mod) << '\n';
    std::cout << modInverse(3, 11) << '\n';

    return 0;
}
