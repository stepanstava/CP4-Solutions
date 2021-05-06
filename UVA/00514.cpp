// 514 Rails
#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int trains;
	int res[1005];
	while (true) {
		scanf("%d", &trains); 
		if (trains == 0) {
			break;
		}

		while (true) {
			// input
			scanf("%d", &res[0]);
			if (res[0] == 0) {
				printf("\n");
				break;
			}
			for (int i = 1; i < trains; i++) {
				scanf("%d", &res[i]);
			}

			// stack
			stack<int> stc;
			int n = 1;
			for (int i = 0; i < trains; i++) {
				if (stc.empty()) {
					stc.push(n);
					n++;
				}

				while (res[i] != stc.top() && n <= trains) {
					stc.push(n);
					n++;
				}

				if (res[i] == stc.top()) {
					stc.pop();
				}
			}

			// output
			if (stc.empty()) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}