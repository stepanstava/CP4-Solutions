// 1586 Molar mass
#include <cstdio>
#include <cctype>
using namespace std;

double getWeight(char& element, int& n1, int& n2);

int main() {
	int tc;
	scanf("%d\n", &tc);
	while (tc--) {
		char str[85] = { 0 };
		int strLength = 0;
		char c;
		while (scanf("%c", &c), c != '\n') {
			str[strLength] = c;
			strLength++;
		}

		char element = str[0];
		int n1 = 0, n2 = 0;
		double weight = 0;
		for (int i = 1; i < strLength; i++) {
			if (isdigit(str[i])) {
				if (n1 == 0) {
					n1 = str[i] - '0';
				}
				else {
					n2 = str[i] - '0';
				}
			}
			else {
				weight += getWeight(element, n1, n2);
				element = str[i];
				n1 = 0;
				n2 = 0;
			}
		}
		weight += getWeight(element, n1, n2);

		printf("%.3f\n", weight);
	}
	return 0;
}

double getWeight(char& element, int& n1, int& n2) {
	double elWeight = 0;

	switch (element) {
		case 'C':
			elWeight = 12.01;
			break;
		case 'H':
			elWeight = 1.008;
			break;
		case 'O':
			elWeight = 16.0;
			break;
		case 'N':
			elWeight = 14.01;
			break;
		default:
			elWeight = 0;
	}
	if (n1 == 0) {
		return elWeight;
	}

	if (n2 > 0) {
		return elWeight * (n1 * 10 + n2);
	}
	else {
		return elWeight * n1;
	}
}