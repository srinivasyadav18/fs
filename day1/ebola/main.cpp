#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    
    vector<vector<int>> grid(r, vector<int> (c, 0));
    for (auto &i : grid)
        for (auto &j : i) cin >> j;
    
    queue<pair<int, int>> q;    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c;  j++){
            if (grid[i][j] == 2) q.push({i, j});
        }
    }
	int ans = 0;
    queue<pair<int, int>> q2;
    while(true){
		bool temp = false;
        if (q.empty() && q2.empty()) break;
        while(q.empty() == false){
            auto p = q.front();
            q.pop();
            int i = p.first; int j = p.second;
			//cout << "i = " << i << " j = " << j << endl;
            if (i+1 < r && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q2.push({i+1, j});
				temp = true;
            }
            if (i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q2.push({i-1, j});
				temp = true;
            }
            if (j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q2.push({i, j-1});
				temp = true;
            }
            if (j+1 < c && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q2.push({i, j+1});
				temp = true;
            }
        }
		swap(q, q2);
		if (temp)
		ans++;
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c;  j++){
			if (grid[i][j] == 1) {
			cout << -1 << endl;
			return 0;
			}
        }
    }
	
	cout << ans << endl;
}
