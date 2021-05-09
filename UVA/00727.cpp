// 727 Equation
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getPriority(char oper) {
	switch (oper) {
		case '(': return 1; break;
		case ')': return 1; break;
		case '+': return 2; break;
		case '-': return 2; break;
		case '*': return 3; break;
		case '/': return 3; break;
	
		default: return 0;
	}
}

void run_case(int tc) {
	stack<char> s;
	string input;
	while (getline(cin, input)) {
		if (input.empty()) {
			break;
		}

		int priority = getPriority(input[0]);
		if (priority == 0) {
			cout << input;
			continue;
		}

		if (input == "(") {
			s.push(input[0]);
		}
		else if (input == ")") {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty() && priority <= getPriority(s.top())) {
				cout << s.top();
				s.pop();
			}
			
			s.push(input[0]);
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << "\n";
}



int main() {
	int tc;
	cin >> tc;
	cin.get(); cin.get();

	for (int i = 1; i <= tc; i++) {
		run_case(i);
		if (i < tc) {
			cout << "\n";
		}
		cout << flush;
	}
	return 0;
}

/*

digit -> output
'(' -> push to stack
')' -> pop out all stack items till '('
'operator' ->
  stack not empty && priority(operator) <= priority(stack.top)
  -> pop and add operator to stack
  else -> push operator

*/