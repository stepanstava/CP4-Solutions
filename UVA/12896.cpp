// 12896 Mobile SMS
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<int, string> map = {
	{ 0, " " },
	{ 1, ".,?\"" },
	{ 2, "abc" },
	{ 3, "def" },
	{ 4, "ghi" },
	{ 5, "jkl" },
	{ 6, "mno" },
	{ 7, "pqrs" },
	{ 8, "tuv" },
	{ 9, "wxyz" },
	{ 10, "*" },
	{ 11, "#" },
};

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int t;
		scanf("%d", &t);

		vector<int> keys(t);
		vector<int> times(t);
		int n;
		for (int i = 0; i < t; i++) {
			scanf("%d", &n);
			keys[i] = n;
		}
		for (int i = 0; i < t; i++) {
			scanf("%d", &n);
			times[i] = n;
		}

		char res[105];

		for (int i = 0; i < t; i++) {
			int key = keys[i];
			int time = times[i] - 1;

			res[i] = map[key][time];
		}
		res[t] = '\0';
		printf("%s\n", res);
	}
	return 0;
}