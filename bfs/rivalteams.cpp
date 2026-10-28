#include <bits/stdc++.h>

bool BipartiteCheck(int src, std::vector<int> &color, std::vector<std::vector<int>> G){
    color[src] = 0; std::queue<int> Q; Q.emplace(src);
    while(not Q.empty()){
        int u = Q.front(); Q.pop();
        for(int &v: G[u]){
            if(color[v] != -1){
                if(color[u] == color[v]) return false; 
                continue;
            } color[v] = 1 - color[u]; Q.emplace(v);
        }
    } return true; 
}

int main(){
    int n, m;  std::cin >> n >> m; const int MOD = 1e9 + 7;
    std::vector<std::vector<int>> G(n, std::vector<int>());
    for(int i=0; i<m; ++i){
        int u, v; std::cin >> u >> v; 
        G[u].emplace_back(v); G[v].emplace_back(u);
    } int res = 1; std::vector<int> color(n, -1);
    for(int i=0; i<n; ++i){
        if(color[i] != -1) continue;
        if(not BipartiteCheck(i, color, G)){
            std::cout << "NO" << '\n'; return 0;
        } res = (res * 2) % MOD;
    } std::cout << "SI " << res << '\n';
    return 0;
}