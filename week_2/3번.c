#include <stdio.h>

void move(n, start, help, target) // a���� c�� �ű�µ� b�� �߰��� �ִ�
{
	if (n == 1)
		printf("Move disk0 from tray%d to tray%d\n", start, target);
	else {
		move(n - 1, start, target, help);
		printf("Move disk%d from tray%d to tray%d\n", n-1, start, target);
		move(n - 1, help, start, target);
	}
}

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);
		move(n, 1, 2, 3);
	}

	return 0;
}