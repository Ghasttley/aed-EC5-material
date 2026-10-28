#include<bits/stdc++.h>

// Ejercicios de Representacion de Grafos - Semana 11 | D
// Fix: wrong answer on test 1

int main() {
    int n, m, q; std::cin >> n >> m >> q;
    std::vector<std::vector<int>> G(n + 1, std::vector<int>());
    for (int i = 1; i <= m; ++i) {
        int u, v; std::cin >> u >> v;
        G[u].emplace_back(v); G[v].emplace_back(u);
    } for (int i=1; i<=n; ++i) {
        std::sort(G[i].begin(), G[i].end());
    } while (q--) {
        int op; std::cin >> op;
        if (op == 1) {
            int u, k; std::cin >> u >> k;
            std::cout << (G[u].size() >= k ? G[u][k - 1] : -1) << '\n';
        } else {
            int u, x; std::cin >> u >> x;
            std::cout << upper_bound(G[u].begin(), G[u].end(), x) - G[u].begin() << '\n';
        }
    } return 0;
}