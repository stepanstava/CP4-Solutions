// 1062 Containers
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	int count = 1;
	while (true) {
		cin >> str;
		if (str == "end") {
			break;
		}

		int stacks = 1;
		vector<char> arr = { 'Z' };
		for (char c : str) {

			bool newStack = true;
			for (int i = 0; i < arr.size() && newStack; i++) {
				if (c <= arr[i]) {
					arr[i] = c;
					newStack = false;
				}
			}
			if (newStack) {
				arr.push_back(c);
			}		
		}

		cout << "Case " << count++ << ": " << arr.size() << endl;
	}
	return 0;
}