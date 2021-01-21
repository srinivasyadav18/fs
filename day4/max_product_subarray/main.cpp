#include <bits/stdc++.h>

using namespace std;

vector<int> res;
void helper(vector<vector<int>> &grid, const int r, const int c, int i , int j);

void dfs(vector<vector<int>> grid){
    int ans = 0;
    const int r = grid.size();
    const int c = grid[0].size();
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (grid[i][j] == 1){
                helper(grid, r, c, i, j);
                ans++;
            }
        }
    }
    res.push_back(ans);
}

void helper(vector<vector<int>> &grid, const int r, const int c, int i , int j){
    if (i < 0 || i >= r || j < 0 || j >= c) return;
    if (grid[i][j] != 1) return;
    grid[i][j] = -1;
    helper(grid, r, c, i+1, j);
    helper(grid, r, c, i-1, j);
    helper(grid, r, c, i, j+1);
    helper(grid, r, c, i, j-1);
}

int main(){
    int m, n, p;
    cin >> m >> n >> p;
    
    vector<vector<int>> grid(m, vector<int> (n, 0));
    
    for (int i = 0; i < p; i++){
        int u, v;
        cin >> u >> v;
        grid[u][v] = 1;
        dfs(grid);
    }
    string ans = "[";
    for (int i = 0; i < res.size() - 1; i++){
        ans += to_string(res[i]);
        ans += ", ";
    }
    ans += to_string(res.back());
    ans += "]";
    cout << ans << endl;
}