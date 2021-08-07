// 12504 Updating a Dictionary
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void buildDictionary(string line, map<string, string>& dic) {
	string key, value;
	bool isKey = true;
	bool isValue = false;
	for (char c : line) {
		if (c == '{') {
			continue;
		}

		if (c == ':') {
			isValue = true;
			isKey = false;
			continue;
		}

		if (c == ',' || c == '}') {
			isValue = false;
			isKey = true;
			if (key != "") {
				dic[key] = value;
			}
			key = "";
			value = "";
			continue;
		}

		if (isKey) {
			key += c;
		}

		if (isValue) {
			value += c;
		}

	}
};

void printChanges(set<string>& keys, const char& mark) {
	cout << mark;
	for (auto it = keys.begin(); it != keys.end(); it++) {
		if (it != keys.begin()) {
			cout << ",";
		}

		cout << *it;
	}
	cout << "\n";
};

void run_case(int tc) {
	cin.ignore();
	string oldStr, newStr;
	getline(cin, oldStr);
	getline(cin, newStr);

	map<string, string> oldDic;
	map<string, string> newDic;
	buildDictionary(oldStr, oldDic);
	buildDictionary(newStr, newDic);

	set<string> newKeys;
	set<string> removedKeys;
	set<string> changedValues;
	auto oldPointer = oldDic.begin();
	auto newPointer = newDic.begin();

	
	while (!(oldPointer == oldDic.end() && newPointer == newDic.end())) {
		if (oldPointer == oldDic.end() && newPointer != newDic.end()) {
			newKeys.insert(newPointer->first);
			newPointer++;
			continue;
		}
		if (newPointer == newDic.end() && oldPointer != oldDic.end()) {
			removedKeys.insert(oldPointer->first);
			oldPointer++;
			continue;
		}

		//key and values are same
		if (oldPointer->first == newPointer->first && oldPointer->second == newPointer->second) {
			oldPointer++;
			newPointer++;
			continue;
		}

		// values changed
		if (oldPointer->first == newPointer->first) {
			changedValues.insert(newPointer->first);
			oldPointer++;
			newPointer++;
			continue;
		}

		if (oldPointer->first < newPointer->first) {
			removedKeys.insert(oldPointer->first);
			oldPointer++;
		}
		else {
			newKeys.insert(newPointer->first);
			newPointer++;
		}

	}
	int a = 0;

	bool noChanges = true;
	if (newKeys.size()) {
		printChanges(newKeys, '+');
		noChanges = false;
	}
	if (removedKeys.size()) {
		printChanges(removedKeys, '-');
		noChanges = false;
	}
	if (changedValues.size()) {
		printChanges(changedValues, '*');
		noChanges = false;
	}

	if (noChanges) {
		cout << "No changes\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;

	for (int i = 1; i <= ttc; i++) {
		run_case(i);
		cout << "\n";
		cout << flush;
	}
	return 0;
}
