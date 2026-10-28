#include<bits/stdc++.h>

// Ejercicios de Representacion de Grafos - Semana 11 | B

int main() {
    int n, m; std::cin >> n >> m;
        std::vector<int> deg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        --u; --v; ++deg[u]; ++deg[v];
    } int cnt_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2 == 1) {
            ++cnt_odd;
        }
    } if (cnt_odd == 0) std::cout << "CIRCUITO" << '\n';
        else if (cnt_odd == 2) std::cout << "CAMINO" << '\n';
            else std::cout << "IMPOSIBLE" << '\n';
    return 0;
}