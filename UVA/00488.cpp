// 488 Triangle Wave
#include <cstdio>
using namespace std;

int main() {
	int tc, a, f;
	scanf("%d\n", &tc);
	while (tc--) {
		scanf("%d\n%d\n", &a, &f);

		while (f--) {
			for (int i = 1, count = a * 2; i < count; i++) {
				int repeat = i < a ? i : count - i;

				for (int j = 0; j < repeat; j++) {
					printf("%d", repeat);
				}
				printf("\n");
			}
			if (!(tc == 0 && f == 0)) {
				printf("\n");
			}
		}
	}
}