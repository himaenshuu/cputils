#include "cputils.h"

int main() {
    fastIO();

    Fenwick<ll> tree(5);
    tree.add(0, 5);
    tree.add(2, 7);
    tree.add(4, 3);

    std::cout << tree.sumPrefix(2) << '\n';
    std::cout << tree.rangeSum(1, 4) << '\n';

    return 0;
}
