// 12015 - Google is Feeling Lucky
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int tc, c = 1;
	scanf("%d", &tc);
	while (tc--) {
		char page[100];
		vector<string> pages;
		int rank, maxRank = 0;
		for (int i = 0; i < 10; i++) {
			scanf("%s %d", &page, &rank);
			if (rank > maxRank) {
				maxRank = rank;
				pages.clear();
			}

			if (rank == maxRank) {
				pages.push_back(page);
			}
		}
		printf("Case #%d:\n", c++);
		for (auto& item : pages) {
			//! use of printF
			cout << item << endl;
		}
	}
	return 0;
}