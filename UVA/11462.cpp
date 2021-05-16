// 11462 Age Sort
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("io.txt", "r", stdin);
	int size, n;
	while (scanf("%d", &size), size != 0) {
		int count[110] = {};

		for (int i = 0; i < size; i++) {
			scanf("%d", &n);
			count[n] += 1;
		}

		bool sep = false;
		for (int i = 0; i < 100; i++) {
			while (count[i]--) {
				if (sep) {
					printf(" ");
				}
				printf("%d", i);
				sep = true;
			}
		}
		printf("\n");
	}
}