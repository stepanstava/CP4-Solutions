// 902 Password Search
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void run_case(int n, string &line) {
	unordered_map<string, int> map;

	int size = line.size() - n + 1;
	int max = 0;
	string password;
	for (int i = 0; i < size; i++) {
		string sub = line.substr(i, n);
		map[sub] += 1;
		
		if (map[sub] > max) {
			max++;
			password = sub;
		}
	}
	cout << password << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string line;
	while (cin >> n) {
		cin >> line;	
		run_case(n, line);

		cout << flush;
	}

	return 0;
}
