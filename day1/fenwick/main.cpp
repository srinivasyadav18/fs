#include <iostream>
#include <vector>

using namespace std;

class Solution{
	private:
		vector<int> arr, input;
		int n;
	public:
		Solution(vector<int> &nums){
			input = nums;
			n = nums.size() + 1;
			arr = vector<int>(n);
			for (int i = 1; i < n; i++){
				cout << "updating " << i-1 << endl;
				update(i, nums[i-1]);
				print();
			}
		}
		void update(int idx, int val){
			int lb = (idx & -idx);
			while (idx < n) {
				cout << "got lb = " << lb << " with idx = " << idx << endl;
				arr[idx] += val;
				idx += lb;
				lb = idx & -idx;
			}
		}
		void query(int idx){
			cout << "Sum upto " << idx << " is " << get_sum(idx+1) << endl;
		}
		
		int get_sum(int idx){
			int lb = (idx & -idx);
			int sum = 0;
			while (idx > 0){
				cout << "got lb = " << lb << " with index = " << idx << endl;
				sum += arr[idx];
				idx -= lb;
				lb = idx & -idx;
			}
			return sum;
		}
		void print(){
			cout << "Fenwick : ";
			for (int i : arr) cout << i << " ";
			cout << endl;
		}

		void brute(int l, int r){
			long sum = 0;
			for (int i = l; i <= r; i++) sum += input[i];
			cout << "brute : " << sum << endl;
			
		}
		int query(int l, int r){
			brute(l, r);
			return get_sum(r+1) - get_sum(l);
		}
};

int main(){
	int n;
	cin >> n;
	int l, r;
	cin >> l >> r;
	vector<int> nums(n);
	for (int &i : nums) cin >> i;

	Solution s(nums);
	cout  << s.query(l, r) << endl;;
	s.print();
}
