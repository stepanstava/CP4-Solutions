// 1585 Score
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int TC;
	string s;
	
	scanf("%d\n", &TC);
	while (TC--)
	{
		getline(cin, s);
		int score = 0, streak = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'O')
			{
				streak++;
				score += streak;
			}
			else streak = 0;
		}
		printf("%d\n", score);
	}

	return 0;
}