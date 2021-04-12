// 11278 One-Handed Typist
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<char, char> map = {
	{'4', 'q'},
	{'5', 'j'},
	{'6', 'l'},
	{'7', 'm'},
	{'8', 'f'},
	{'9', 'p'},
	{'0', '/'},
	{'-', '['},
	{'=', ']'},
	{'q', '4'},
	{'w', '5'},
	{'e', '6'},
	{'r', '.'},
	{'t', 'o'},
	{'y', 'r'},
	{'u', 's'},
	{'i', 'u'},
	{'o', 'y'},
	{'p', 'b'},
	{'[', ';'},
	{']', '='},
	{'a', '7'},
	{'s', '8'},
	{'d', '9'},
	{'f', 'a'},
	{'g', 'e'},
	{'h', 'h'},
	{'j', 't'},
	{'k', 'd'},
	{'l', 'c'},
	{';', 'k'},
	{'\'', '-'},
	{'z', '0'},
	{'x', 'z'},
	{'c', 'x'},
	{'v', ','},
	{'b', 'i'},
	{'n', 'n'},
	{'m', 'w'},
	{',', 'v'},
	{'.', 'g'},
	{'/', '\''},
	{'$', 'Q'},
	{'%', 'J'},
	{'^', 'L'},
	{'&', 'M'},
	{'*', 'F'},
	{'(', 'P'},
	{')', '?'},
	{'_', '{'},
	{'+', '}'},
	{'Q', '$'},
	{'W', '%'},
	{'E', '^'},
	{'R', '>'},
	{'T', 'O'},
	{'Y', 'R'},
	{'U', 'S'},
	{'I', 'U'},
	{'O', 'Y'},
	{'P', 'B'},
	{'{', ':'},
	{'}', '+'},
	{'A', '&'},
	{'S', '*'},
	{'D', '('},
	{'F', 'A'},
	{'G', 'E'},
	{'H', 'H'},
	{'J', 'T'},
	{'K', 'D'},
	{'L', 'C'},
	{':', 'K'},
	{'\"', '_'},
	{'Z', ')'},
	{'X', 'Z'},
	{'C', 'X'},
	{'V', '<'},
	{'B', 'I'},
	{'N', 'N'},
	{'M', 'W'},
	{'<', 'V'},
	{'>', 'G'},
	{'?', '\"'},
	{' ', ' '},

};

int main() {
	char s[1005];
	while (scanf("%[^\n]\n", s) != EOF) {
		int i = 0;
		while (s[i]) {
			char c = map[s[i]];
			if (!c) {
				printf("%c", s[i]);
			}
			else {
				printf("%c", c);
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}