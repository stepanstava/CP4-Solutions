// 12136 Schedule of a Married Man
#include <cstdio>
using namespace std;

int main() {
	int tc, count = 1;
	scanf("%d\n", &tc);

	while (tc--) {
		char wife[15];
		char meeting[15];
		scanf("%[^\n]\n", wife);
		scanf("%[^\n]\n", meeting);

		int wH1 = ((wife[0] - '0') * 10) + (wife[1] - '0');
		int wM1 = ((wife[3] - '0') * 10) + (wife[4] - '0');
		int wMin1 = wH1 * 60 + wM1;

		int wH2 = ((wife[6] - '0') * 10) + (wife[7] - '0');
		int wM2 = ((wife[9] - '0') * 10) + (wife[10] - '0');
		int wMin2 = wH2 * 60 + wM2;

		int mH1 = ((meeting[0] - '0') * 10) + (meeting[1] - '0');
		int mM1 = ((meeting[3] - '0') * 10) + (meeting[4] - '0');
		int mMin1 = mH1 * 60 + mM1;

		int mH2 = ((meeting[6] - '0') * 10) + (meeting[7] - '0');
		int mM2 = ((meeting[9] - '0') * 10) + (meeting[10] - '0');
		int mMin2 = mH2 * 60 + mM2;

		printf("Case %d: ", count++);
		// before meeting || after meeting
		if ((wMin1 < wMin2 && wMin2 < mMin1) || (mMin2 < wMin1 && wMin1 < wMin2)) {
			printf("Hits Meeting\n");
		}
		else {
			printf("Mrs Meeting\n");
		}
	}
	return 0;
}