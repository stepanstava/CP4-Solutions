// 10887 Concatenation of Languages
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void run_case(int &tc) {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	
	vector<string> tmp(n);
	string str;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		tmp[i] = str;
	}

	set<string> langs;
	for (int i = 0; i < m; i++) {
		getline(cin, str);
		for (int j = 0; j < n; j++) {
			string concat = tmp[j] + str;
			langs.insert(concat);
		}
	}

	cout << "Case " << tc << ": " << langs.size() << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;

	for (int i = 1; i <= ttc; i++) {
		run_case(i);
		cout << flush;
	}
	return 0;
}
