// 10954 Add All
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void run_case(int n) {
	priority_queue<int, vector<int>, greater<int>> minQue;
	
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		minQue.push(num);
	}

	int total = 0;
	while (minQue.size() != 1) {
		int a = minQue.top();
		minQue.pop();
		int b = minQue.top();
		minQue.pop();

		total += a + b;
		minQue.push(a + b);
	}
	cout << total << "\n";
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
