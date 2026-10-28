#include<bits/stdc++.h>

// Ejercicios de Representacion de Grafos - Semana 11 | F
// Fix: time limit exceeded on test 8

int main() {
    int n, m, q; std::cin >> n >> m >> q;
    std::vector<std::vector<int>> G(n + 1, std::vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        G[u].emplace_back(v); G[v].emplace_back(u);
    } std::vector<bool> used(n + 1, false);
    while (q--) {
        int u, v; std::cin >> u >> v;
        //if (G[u].size() > G[v].size()) swap(u, v);
        for (int &x : G[u]) { used[x] = true; }
        int res = 0; for (int &x : G[v]) {
            if (used[x]) ++res;
        } for (int &x : G[u]) {
            used[x] = false;
        } std::cout << res << '\n';
    } return 0;
}