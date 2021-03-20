// 12250 Language Detection
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[20];
	int i = 1;
	while (true) {
		scanf("%s", s);

		if (strcmp(s, "#") == 0) {
			break;
		}

		printf("Case %d: ", i++);

		if (strcmp(s, "HELLO") == 0) {
			printf("ENGLISH");
		}
		else if (strcmp(s, "HOLA") == 0) {
			printf("SPANISH");
		}
		else if (strcmp(s, "BONJOUR") == 0) {
			printf("FRENCH");
		}
		else if (strcmp(s, "CIAO") == 0) {
			printf("ITALIAN");
		}
		else if (strcmp(s, "ZDRAVSTVUJTE") == 0) {
			printf("RUSSIAN");
		}
		else if (strcmp(s, "HALLO") == 0) {
			printf("GERMAN");
		}
		else {
			printf("UNKNOWN");
		}
		printf("\n");
	}
	return 0;
}