#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> nums(n, 0);
    for (int &i : nums) cin >> i;
    
    int best = nums[0];
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    
    for (int i = 1; i < nums.size(); i++){
        int val = nums[i];
        int Max_so_far = max_so_far;
        max_so_far = max(val, max(max_so_far * val, min_so_far * val));
        min_so_far = min(val, min(Max_so_far * val, min_so_far * val));
        best = max(best, max_so_far);
    }
    cout << best << endl;
}