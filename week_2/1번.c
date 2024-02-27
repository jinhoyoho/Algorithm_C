#include <stdio.h>

long combination(int n, int r) //����
{
	if (r == 0 || r == n) //r�� 0 �̰ų� n�� ��
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