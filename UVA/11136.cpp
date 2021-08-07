// 11136 Hoax or what
#include <iostream>
#include <set>

using namespace std;

void run_case(int tc) {
	multiset<int> lottery;
	int tickets, ticket;
	long long cost = 0;
	for (int i = 0; i < tc; i++) {
		cin >> tickets;
		for (int j = 0; j < tickets; j++) {
			cin >> ticket;
			lottery.insert(ticket);
		}

		multiset<int>::iterator lowest = lottery.begin();
		multiset<int>::iterator highest = --lottery.end();
		cost += *highest - *lowest;
		lottery.erase(lowest);
		lottery.erase(highest);
	}
	cout << cost << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	while (cin >> tc) {
		if (tc == 0) {
			break;
		}
		run_case(tc);
		cout << flush;
	}

	return 0;
}
