#include <stdio.h>


double taylor(int x, int cnt)
{
	if (cnt == 31) // 30??
		return;

	return 1.0 + (double)x / cnt * taylor(x, cnt + 1);
}

int main() 
{
	for (int i = 1; i < 11; i++)
	{
		printf("e^%d = %lf\n", i, taylor(i, 1));
	}
}