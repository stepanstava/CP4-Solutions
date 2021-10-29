// 507 Jill Rides Again
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rsq(int i, int j, vector<int>& nums) {
	int sum = 0;
	for (i; i <= j; i++) {
		sum += nums[i];
	}
	return sum;
}

void run_case(int tc) {
	int size;
	cin >> size;
	size -= 1;

	vector<int> nums(size);
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}

	// O(n^3)
	// Complete search - tries all possible O(n^2) pairs
	int maxSum = INT_MIN, maxI = 0, maxJ = size - 1;
	//for (int i = 0; i < size; i++) {
	//	for (int j = i; j < size; j++) {
	//		int sum = rsq(i, j, nums);
	//		if (sum > maxSum) {
	//			maxSum = sum;
	//			maxI = i;
	//			maxJ = j;
	//		} 
	//		if (sum == maxSum) {
	//			if (j - i > maxJ - maxI) {
	//				maxI = i;
	//				maxJ = j;
	//			}
	//		}
	//	}
	//}

	// O(n^2)
	// Pre-process array containing prefix sum 
	//vector<int> processSum(size);
	//processSum[0] = nums[0];
	//for (int i = 1; i < size; i++) {
	//	processSum[i] = processSum[i - 1] + nums[i];
	//}

	//for (int i = 1; i < size; i++) {
	//	for (int j = i; j < size; j++) {
	//		int sum = processSum[j] - processSum[i - 1];
	//		if (sum > maxSum) {
	//			maxSum = sum;
	//			maxI = i;
	//			maxJ = j;
	//		} 
	//		if (sum == maxSum) {
	//			if (j - i > maxJ - maxI) {
	//				maxI = i;
	//				maxJ = j;
	//			}
	//		}
	//	}
	//}

	// O(n) - Kadane's Algorithm - greedy or DP solution
	int sum = 0; int i = 0;
	for (int j = 0; j < size; j++) {
		sum += nums[j];

		if (sum < 0) {
			sum = 0;
			i = j + 1;
			continue;
		}

		if (sum > maxSum) {
			maxSum = sum;
			maxI = i;
			maxJ = j;
		} 
		if (sum == maxSum) {
			if (j - i > maxJ - maxI) {
				maxI = i;
				maxJ = j;
			}
		}
	}

	if (maxSum > 0) {
		cout << "The nicest part of route " << tc << " is between stops " << maxI + 1 << " and " << maxJ + 2 << "\n";
	}
	else {
		cout << "Route " << tc << " has no nice parts" << "\n";
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;
	for (int tc = 1; tc <= ttc; tc++) {
		run_case(tc);
		cout << flush;
	}
	return 0;
}
