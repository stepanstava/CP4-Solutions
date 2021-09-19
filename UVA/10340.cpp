// 10340 All in All
#include <iostream>
#include <string>

using namespace std;

void run_case(string& sub, string& str) {
	
	int subIdx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == sub[subIdx]) {
			subIdx++;
		}
	}

	cout << (subIdx == sub.size() ? "Yes" : "No") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sub, str;
	while (cin >> sub >> str) {
		if (cin.eof()) {
			break;
		}
		run_case(sub, str);
		cout << flush;
	}

	return 0;
}
