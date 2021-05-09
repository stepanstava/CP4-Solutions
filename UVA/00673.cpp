// 673 Parentheses Balance
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void runCase(int tc) {
	string str;
	getline(cin, str);

	stack<char> s;
	bool isCorrect = true;
	for (char c : str) {
		if (c == ' ') {
			continue;
		}

		if (c == '(' || c == '[') {
			s.push(c);
		}
		else {
			if (!s.empty() && c == ')' && s.top() == '(') {
				s.pop();
			}
			else if (!s.empty() && c == ']' && s.top() == '[') {
				s.pop();
			}
			else {
				isCorrect = false;
				break;
			}
		}
	}

	cout << (isCorrect && s.empty() ? "Yes" : "No") << "\n";
}


int main() {
	int tc;
	cin >> tc;
	cin.get();

	for (int i = 1; i <= tc; i++) {
		runCase(i);
		cout << flush;
	}
	return 0;
}