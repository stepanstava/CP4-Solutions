// 151 Power Crisis 
#include <iostream>
#include <vector>

using namespace std;

void run_case(int n) {
	int m = 1;

	while (true) {
		vector<int> nums(n - 1);
		for (int i = 1; i <= nums.size(); i++) {
			nums[i - 1] = i + 1;
		}

		int pos= 0;
		while (nums.size() != 1) {
			pos = (pos + m - 1) % nums.size();
			nums.erase(nums.begin() + pos);
			
		}

		if (nums[0] == 13) {
			break;
		}
		else {
			m++;
		}
	}
	cout << m << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0) { 
			break; 
		}		
		run_case(n);
		cout << flush;
	}
		
	return 0;
}
