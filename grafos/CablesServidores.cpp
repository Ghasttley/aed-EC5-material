#include <bits/stdc++.h>

// Ejercicios de Representacion de Grafos - Semana 11 | E

int main() {
    int n, m, q; std::cin >> n >> m >> q;
        std::map<std::pair<int, int>, int> frec;
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        if (u > v) std::swap(u, v);
            ++frec[std::make_pair(u, v)];
    } while (q--) {
        int u, v; std::cin >> u >> v;
        if (u > v) std::swap(u, v);
        std::cout << (frec.count(std::make_pair(u, v)) ? frec[std::make_pair(u, v)] : 0) << '\n';
    } return 0;
}