// 11565 - Simple Equations
#include <iostream>

using namespace std;

void run_case(int tc) {
	int a, b, c;
	cin >> a >> b >> c;
	
	for (int x = -100; x <= 100; x++) {
		for (int y = -100; y <= 100; y++) {
			for (int z = -100; z <= 100; z++) {
				// distinct
				if (z != y && z != x && x != y) {
					if ((x + y + z == a) && 
						(x * y * z == b) &&
						(x * x + y * y + z * z == c)
						) {
						cout << x << " " << y << " " << z << "\n";;
						return;
					}
				}
			}
		}
	}
	cout << "No solution." << "\n";;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ttc;
	cin >> ttc;

	for (int i = 1; i <= ttc; i++) {
		run_case(i);
		cout << flush;
	}
	return 0;
}
