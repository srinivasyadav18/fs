#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int src, vector<bool> &visited, bool &ans, const vector<vector<int>> &adj_list){
    if (ans == true) return;
    for (auto i : adj_list[src]){
        if (visited[i] == true) {
            ans = true;
            return;
        }
        visited[i] = true;
        dfs(i, visited, ans, adj_list);
        visited[i] = false;
    }
}
bool is_cyclic(const vector<vector<int>> adj_list){
    vector<bool> visited(adj_list.size(), false);
    bool ans = false;
    for (int i = 1; i < adj_list.size(); i++){
        if (ans == true) return true;
        dfs(i, visited, ans, adj_list);
    }
    return false;
}

void build_dp(const vector<vector<int>> &adj_list, vector<int> &dp, vector<bool> &visited, int src){
    visited[src] = true;
    for (int i : adj_list[src]){
        if (visited[i] == false){
            build_dp(adj_list, dp, visited, i);
        }
        dp[src] += max(dp[src], 1 + dp[i]);
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj_list(v+1);

    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_list[v].push_back(u);
    }

    if (is_cyclic(adj_list)) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> dp(v+1);
    vector<bool> visited(v+1);
    for (int i = 1; i <= v; i++){
        if (visited[i] == false)
            build_dp(adj_list, dp, visited, i);
    }
    cout << *max_element(dp.begin(), dp.end()) + 1;
}