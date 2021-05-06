// 612 DNA Sorting
#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
//!ostranit
#include <iostream>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	freopen("io.txt", "r", stdin);
	int tc, sLen, n;
	scanf("%d", &tc);

	while (tc--) {
		scanf("\n");
		scanf("%d %d", &sLen, &n);

		char str[55] = "";
		vector<string> strs;
		vector<pair<int, int>> pairs;
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			
			// inversions
			int inversions = 0;
			for (int i = 0; i < sLen; i++) {
				for (int j = i + 1; j < sLen; j++) {
					if (str[i] > str[j]) {
						inversions++;
					}
				}
			}

			strs.push_back(str);
			pairs.push_back(make_pair(inversions, i));
		}

		// sort
		stable_sort(pairs.begin(), pairs.end(), comp);

		// output
		for (auto pair : pairs) {
			int i = pair.second;
			cout << strs[i] << endl;
		}

		if (tc > 0) {
			printf("\n");
		}
	}

	return 0;
}




