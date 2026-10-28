#include<bits/stdc++.h>

// Ejercicios de Representacion de Grafos - Semana 11 | C

int main() {
    int n, m; std::cin >> n >> m;
    // (a, b) -> a * (n + 1) * b
    std::unordered_set<long long> edge_hashes;
        std::vector<std::pair<int, int>> edges;
            std::vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
            edges.emplace_back(u, v); 
            edge_hashes.emplace(1ll * u * (n + 1) + v);
        ++in_degree[v];
    } int res = 0;
    for (auto &e : edges) {
        int u, v; std::tie(u, v) = e;
        if (edge_hashes.find(1ll * v * (n + 1) + u) != edge_hashes.end()) {
            ++res;
        }
    } int best = max_element(in_degree.begin() + 1, in_degree.end()) - in_degree.begin();
    std::cout << (res >> 1) << " " << best << " " << in_degree[best] << '\n';
    return 0;
}