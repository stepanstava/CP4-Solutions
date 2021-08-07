// 10815 Andy’s First Dictionary
#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

void run_case(int tc) {
	set<string> dictionary;
	string input;
	while (cin >> input) {
		if (cin.eof()) { 
			break; 
		}

		string word;
		for (char c : input) {
			if (isalpha(c)) {
				word += tolower(c);
			}
			else {
				if (word != "") {
					dictionary.insert(word);
					word = "";
				}
			}
		}
		if (word != "") {
			dictionary.insert(word);
		}
	}

	for (auto& w : dictionary) {
		cout << w << "\n";
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	run_case(1);
	cout << flush;

	return 0;
}
