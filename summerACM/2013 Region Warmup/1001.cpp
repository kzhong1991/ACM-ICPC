#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char key[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char map[20][20];
	int ix = 0;
	for(int n = 3; n <= 10; n++)
	{
		memset(map, 0, sizeof(map));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if (i == 1 || i == n) {
					map[j][i] = key[ix];
					ix = (ix + 1) % 26;
				}
				else if (j == n + 1 - i) {
					map[j][i] = key[ix];
					ix = (ix + 1) % 26;
				}
				else {
					map[j][i] = ' ';
				}
			}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				printf("%c", map[i][j]);
			printf("\n");
		}
	}
	return 0;
}
