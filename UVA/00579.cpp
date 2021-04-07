// 579 ClockHands
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	while (true) {
		char time[8] = { 0 };
		scanf("%[^\n]", time);

		if (time[0] == '0' && time[2] == '0' && time[3] == '0') {
			break;
		}

		int h, m;

		if (isdigit(time[1])) {
			h = ((time[0] - '0') * 10) + time[1] - '0';
			m = ((time[3] - '0') * 10) + time[4] - '0';
		}
		else {
			h = time[0] - '0';
			m = ((time[2] - '0') * 10) + time[3] - '0';
		}


		double hAngle = 30 * h + (30 * m / 60.0);
		double mAngle = 6 * m;

		if (hAngle < mAngle) {
			swap(hAngle, mAngle);
		}

		double angle = hAngle - mAngle > 180 ? 360 - (hAngle - mAngle) : hAngle - mAngle;

		printf("%.3f\n", round(angle * 1000) / 1000);
		scanf("\n");

	}
	return 0;
}