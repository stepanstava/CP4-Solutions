// 1588 Kickdown
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void run_case(string &bottom, string &top) {
	int totalMin = bottom.size() + top.size();

	if (top.size() > bottom.size()) {
		swap(top, bottom);
	}

	// back
	for (int i = 0; i < bottom.size(); i++) {
		int levelMin = 0;
		for (int j = 0; j < top.size(); j++) {
			if (i + j >= bottom.size()) {
				break;
			}
			if (top[j] == '2' && bottom[i + j] == '2') {;
				levelMin = 0;
				break;
			}
			else {
				levelMin++;
			}
		}
		levelMin = bottom.size() - levelMin + top.size();
		totalMin = min(levelMin, totalMin);
	}

	// front
	for (int i = 0; i < top.size(); i++) {
		int levelMin = 0;
		for (int j = 0; j <= i; j++) {
			if (top[top.size() - 1 - i + j] == '2' && bottom[j] == '2') {
				levelMin = 0;
				break;
			}
			else {
				levelMin++;
			}
		}
		levelMin = bottom.size() - levelMin + top.size();
		totalMin = min(levelMin, totalMin);
	}

	cout << totalMin << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("io.txt", "r", stdin);

	string bottom, top;
	while (true) {
		getline(cin, bottom);
		getline(cin, top);

		if (bottom.size() && top.size()) {
			run_case(bottom, top);
			cout << flush;
		}
		else {
			break;
		}
	}
	return 0;
}
