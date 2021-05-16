// 10107 What is the Median ?
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> nums;
	while (scanf("%d", &n) != EOF) {
		nums.push_back(n);

		sort(nums.begin(), nums.end());

		int size = nums.size();
		int median = size % 2 == 0 ? (nums[size / 2 - 1] + nums[size / 2]) / 2 : nums[size / 2];
		printf("%d\n", median);
	}
	return 0;
}