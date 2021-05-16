 //12356 Army buddies
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	freopen("io.txt", "r", stdin);

	int s, b, l, r;
	while (scanf("%d %d", &s, &b), s || b) {
		vector<int> sLeft(s + 2);
		vector<int> sRight(s + 2);

		for (int i = 0; i < s + 2; i++) {
			sLeft[i] = i - 1;
			sRight[i] = i + 1;
		}
		
		for (int i = 0; i < b; i++) {
			scanf("%d %d", &l, &r);
			if (sLeft[l] < 1) {
				printf("* ");
			}
			else {
				printf("%d ", sLeft[l]);
			}

			if (sRight[r] > s) {
				printf("*\n");
			}
			else {
				printf("%d\n", sRight[r]);
			}
			sLeft[sRight[r]] = sLeft[l];
			sRight[sLeft[l]] = sRight[r];
		}
		printf("-\n");
	}
	return 0;
}