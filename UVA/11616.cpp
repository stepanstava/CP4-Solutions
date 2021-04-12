// 11616 Roman Numerals
#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

void convertToRoman(int n);
void converToArabic(string& roman);

unordered_map<char, int> map = {
	{'M', 1000},
	{'D', 500},
	{'C', 100},
	{'L', 50},
	{'X', 10},
	{'V', 5},
	{'I', 1},
};

int main() {
	char str[25];
	while (scanf("%s", str) != EOF) {
		string s = string(str);

		if (isdigit(s[0])) {
			int n = stoi(s);
			convertToRoman(n);
		}
		else {
			converToArabic(s);
		}
	}
	return 0;
}

void converToArabic(string& roman) {
	int num = 0;
	for (int i = 0, size = roman.size(); i < size; i++) {
		int c1 = map[roman[i]];
		int c2 = 0;
		if (i + 1 != size) {
			c2 = map[roman[i + 1]];
		}

		if (c1 < c2) {
			num += c2 - c1;
			i++;
		}
		else {
			num += c1;
		}
	}
	printf("%d\n", num);
}

void convertToRoman(int n) {
	while (n != 0) {
		if (n >= 1000) {
			printf("M");
			n -= 1000;
		}
		else if (n >= 900) {
			printf("CM");
			n -= 900;
		}
		else if (n >= 500) {
			printf("D");
			n -= 500;
		}
		else if (n >= 400) {
			printf("CD");
			n -= 400;
		}
		else if (n >= 100) {
			printf("C");
			n -= 100;
		}
		else if (n >= 90) {
			printf("XC");
			n -= 90;
		}
		else if (n >= 50) {
			printf("L");
			n -= 50;
		}
		else if (n >= 40) {
			printf("XL");
			n -= 40;
		}
		else if (n >= 10) {
			printf("X");
			n -= 10;
		}
		else if (n >= 9) {
			printf("IX");
			n -= 9;
		}
		else if (n >= 5) {
			printf("V");
			n -= 5;
		}
		else if (n >= 4) {
			printf("IV");
			n -= 4;
		}
		else {
			printf("I");
			n -= 1;
		}
	}
	printf("\n");
}