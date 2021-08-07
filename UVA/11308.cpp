// 11308 Bankrupt Baker
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

void run_case(int tc) {
	string title;
	cin.ignore();
	getline(cin, title);

	int m, n, budget;
	cin >> m >> n >> budget;

	unordered_map<string, int> ingredients;
	string ingredient;
	int price;
	for (int i = 0; i < m; i++) {
		cin >> ingredient >> price;
		ingredients[ingredient] = price;
	}

	set<pair<int, string>> recipes;
	string recipe;
	int recipeIngreds, units;
	for (int i = 0; i < n; i++) {
		int recipeCost = 0;
		cin.ignore();
		getline(cin, recipe);
		cin >> recipeIngreds;

		for (int j = 0; j < recipeIngreds; j++) {
			cin >> ingredient >> units;
			recipeCost += ingredients[ingredient] * units;
		}
		if (recipeCost <= budget) {
			recipes.insert({ recipeCost, recipe });
		}
	}

	// output
	transform(title.begin(), title.end(), title.begin(), [](char c) { return toupper(c); });
	cout << title << "\n";

	if (recipes.size()) {
		for (auto& item : recipes) {
			cout << item.second << "\n";
		}
	}
	else {
		cout << "Too expensive!\n";
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
