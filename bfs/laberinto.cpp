// 1) Modelamiento
// 2) Temática , te lo dan or smth
// 3) Algoritmo
// 4) Demostración , not rn

// BFS

#include <bits/stdc++.h>

int BFS(int sx, int sy, int tx, int ty, int n, int m, std::vector<std::string> &s){
    std::vector<int> dx = {1, -1, 0, 0}; std::vector<int> dy = {0, 0, 1, -1};
    std::vector<std::vector<int>> d(n, std::vector<int>(m, -1)); 
    std::queue<std::pair<int, int>> Q; 
    Q.emplace(sx, sy); d[sx][sy] = 0;
    while(not Q.empty()){
        int ux, uy;
        std::tie(ux, uy) = Q.front(); 
            // if(ux == tx && uy == ty) ...
        Q.pop();
        for(int k=0; k<4; ++k){
            int vx = ux + dx[k]; int vy = uy + dy[k];
            if(vx < 0 || vy < 0 || vx >= n || vy >= m) continue;
                if(s[vx][vy] == '#') continue;
                if(d[vx][vy] != -1) continue;
            d[vx][vy] = d[ux][uy] + 1; Q.emplace(vx, vy);
        }
    } return d[tx][ty];
}

int main(){
    int n, m; std::cin>> n >> m; 
    std::vector<std::string> s(n);
    int sx, sy, tx, ty;
    for(int i=0; i<n; ++i){
        std::cin >> s[i];
        for(int j=0; j<m; ++j){
            if(s[i][j] == 'S'){
                sx = i; sy = j;
            } if(s[i][j] == 'E'){
                tx = i; ty = j;
            }
        }
    } std::cout << BFS(sx, sy, tx, ty, n, m, s);

    return 0;
}