 //12696 Cabin Baggage
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int tc, tot = 0;
	scanf("%d", &tc);
	while (tc--) {
		float l, w, d, kg;
		scanf("%f %f %f %f", &l, &w, &d, &kg);

		if (kg > 7) {
			printf("0\n");
			continue;
		}

		if (l > 56 || w > 45 || d > 25) {
			float dim = l + w + d;
			if (dim > 125) {
				printf("0\n");
				continue;
			}
		}

		tot++;
		printf("1\n");
	}
	printf("%d\n", tot);

}