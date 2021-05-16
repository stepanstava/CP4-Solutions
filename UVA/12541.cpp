// 12541 Birthdates
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const float dayMonthRatio = 365 / 12.0;

void run_case(int size) {
	string name;
	int d, m, y;
	vector<pair<float, string>> dates(size);
	for (int i = 0; i < size; i++) {
		cin >> name >> d >> m >> y;

		dates[i].first = (y * 365) + ((m - 1) * dayMonthRatio) + d;
		dates[i].second = name;
	}

	sort(dates.begin(), dates.end());

	cout << dates[dates.size() - 1].second << endl;
	cout << dates[0].second << endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int size;
	cin >> size;

	run_case(size);
	return 0;
}
