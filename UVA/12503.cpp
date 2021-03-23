// 12503 Robot Instructions
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int steps, p = 0;
		scanf("%d\n", &steps);

		vector<int> ins(steps);
		char step[6];
		for (int i = 0; i < steps; i++) {
			scanf("%s", step);

			if (strcmp(step, "LEFT") == 0) {
				ins[i] = -1;
				p--;
			}
			else if (strcmp(step, "RIGHT") == 0) {
				ins[i] = 1;
				p++;
			}
			else {
				int stepI;
				scanf("%s", &step); // gets next word
				scanf("%d", &stepI);

				ins[i] = ins[stepI - 1];
				p += ins[stepI - 1];
			}
		}
		printf("%d\n", p);
	}
	return 0;
}