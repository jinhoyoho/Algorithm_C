#include <stdio.h>

long combination(int n, int r) //조합
{
	if (r == 0 || r == n) //r이 0 이거나 n일 때
		return 1L;
	
	//n-1Cr-1 + n-1Cr
	return combination(n - 1, r - 1) + combination(n - 1, r);
}


int main()
{
	int n, c = 0;
	while (scanf("%d %d", &n, &c) != EOF)
	{
		printf("%dC%d = %d\n", n, c, combination(n, c));
	}

	return 0;
}