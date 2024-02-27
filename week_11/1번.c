#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp;
	fp = fopen("input.txt", "r");
	char str[50];
	fgets(str, 50, fp);
	fclose(fp);
	
	char * s;
	int num[100], i, cnt = 0; //num은 물통, cnt는 물통의 개수

	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) // strtok 에 구분자 지정
		if (sscanf(s, "%d", &num[cnt]) < 1)
			break;
    
	int idx = 0;
	while (idx < cnt)
	{
		int bottle = num[idx]; //물통용량
		int cup_300 = 0; //300ml컵 사용 횟수
		int cup_500 = 0; //500ml컵 사용 횟수
		int result = 9876543210; //결과 저장
		for (int i = bottle / 500; i >= 0; i--)
		{
			if (((bottle - i * 500) % 300) == 0)
			{
				cup_300 = (bottle - i * 500) / 300;
				cup_500 = i;
			}
			if (result > cup_300 + cup_500 && cup_300 + cup_500 != 0) //0이 아니고 기존 결과보다 작다면
				result = cup_300 + cup_500; //결과 갱신
		}
		if ((cup_300 == 0) && (cup_500 == 0))
			printf("-1 ");
		else
			printf("%d ", result);

		idx++;
	}

}