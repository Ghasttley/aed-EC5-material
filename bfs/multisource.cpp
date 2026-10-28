#include <bits/stdc++.h>

std::vector<int> Multisource(std::vector<int> &src, int n, std::vector<std::vector<int>> G){
    std::vector<int> D(n, -1); std::queue<int> Q;
    for(auto &x: src){
        D[x] = 0; Q.emplace(x);
    } while (not Q.empty()){
        int u = Q.front(); Q.pop();
        for(int &v: G[u]){
            if(D[v] != -1) continue;
            D[v] = D[u] + 1; Q.emplace(v);
        }
    } return D;
}

int main(){
    int n, m, k; std::cin >> n >> m >> k; 
    std::vector<int> special(k);
    for(int i=0; i<k; ++i){
        std::cin >> special[i]; --special[i];
    } std::vector<std::vector<int>> G(n, std::vector<int>());
    for(int i=0; i<m; ++i){
        int u, v; std::cin >> u >> v; --u; --v;
        G[u].emplace_back(v); G[v].emplace_back(u);
    } std::vector<int> dist = Multisource(special, n, G);
    for(int i=0; i<n; ++i){
        std::cout << dist[i] << " \n"[i + 1 == n];
    } return 0;
}