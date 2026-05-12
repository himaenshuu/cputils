#include "cputils.h"

int main() {
    fastIO();

    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(3, 4);

    std::cout << dsu.same(0, 1) << '\n';
    std::cout << dsu.size(3) << '\n';

    return 0;
}
