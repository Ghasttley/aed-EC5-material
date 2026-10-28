#include <bits/stdc++.h>

bool valid_position(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}

int BFS(int sx, int sy, int tx, int ty, int n, int m, std::vector<std::string> &s){
    std::vector<int> dx = {1, -1, 0, 0}; std::vector<int> dy = {0, 0, 1, -1};
    std::vector<std::vector<std::vector<int>>> d(4, std::vector<std::vector<int>>(n, std::vector<int> (m, -1))); 
    std::queue<std::tuple<int, int, int>> Q; 
        Q.emplace(0, sx, sy); d[0][sx][sy] = 0;
    while(not Q.empty()){
        int dir, ux, uy;
        std::tie(dir, ux, uy) = Q.front(); 
            if(ux == tx && uy == ty) return d[dir][ux][uy];
        Q.pop();
        if(valid_position(ux + dx[dir], uy + dy[dir] , n, m) && s[ux + dx[dir]][uy + dy[dir]] != '#'){
            int vx = ux + dx[dir]; int vy = uy + dy[dir];
            if(d[dir][vx][vy] == -1){
                d[dir][vx][vy] = d[dir][ux][uy] + 1;
                    Q.emplace(dir, ux, uy);
            } if (d[(dir + 3) % 4][ux][uy] == -1) {
                d[(dir + 3) % 4][ux][uy] = d[dir][ux][uy] + 1;
                    Q.emplace((dir + 3) % 4, ux, uy);
                } if (d[(dir + 1) % 4][ux][uy] == -1) {
                d[(dir + 1) % 4][ux][uy] = d[dir][ux][uy] + 1;
                    Q.emplace((dir + 1) % 4, ux, uy);
            }
        } 
    } return -1;
}

int main(){
    int n, m; std::cin >> n >> m;
    std::vector<std::string> s(n);
    for(int i=0; i<n; ++i){
        std::cin >> s[i];
    } std::cout << BFS(0, 0, n-1, m-1, n, m, s) << '\n';
    return 0;
}