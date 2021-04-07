#include <cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int s, d;
		scanf("%d %d", &s, &d);

		if (s < d) {
			printf("impossible\n");
			continue;
		}

		if ((s - d) % 2 == 1) {
			printf("impossible\n");
			continue;
		}

		// b = s - a
		// b = s - (d + b)
		// b = (s - d) / 2
		int b = (s - d) / 2;

		// a - b = d;
		// a = d + b
		int a = d + b;

		if (a < 0 || b < 0 || b > a) {
			printf("impossible\n");
		}
		else {
			printf("%d %d\n", a, b);
		}
	}

	return 0;
}