// 10038 Jolly Jumpers
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	freopen("io.txt", "r", stdin);

	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> nums;

		int m, l;
		scanf("%d", &m);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &l);
			nums.push_back(abs(m - l));
			m = l;
		}

		sort(nums.begin(), nums.end());

		bool isJolly = true;
		for (int i = 0, size = nums.size(); i < size; i++) {
			if (nums[i] != i + 1) {
				isJolly = false;
				break;
			}
		}

		if (isJolly) {
			printf("Jolly\n");
		}
		else {
			printf("Not jolly\n");
		}
	}

	return 0;
}
