#include "cputils.h"

int main() {
    fastIO();

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    auto graph = readGraph(n, m);
    for (const auto& neighbors : graph) {
        print1d(neighbors);
    }

    return 0;
}
