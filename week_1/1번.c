#include <stdio.h>

int main()
{
	int input; //숫자입력

	do {
		scanf("%d", &input);

		if (input == 1)
			printf("Welcome to Woong-Sup's Algorithm Class\n");
		else if (input == 2)
			printf("Good Luck for 2022 class\n");

	} while (input != 3);

	return 0;
}