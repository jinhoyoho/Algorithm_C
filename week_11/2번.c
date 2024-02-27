#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp;
	fp = fopen("input_2.txt", "r");
	char str[50];
	fgets(str, 50, fp);
	fclose(fp);
		
	char* s;
	int num[100], i, cnt = 0; 

	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) // strtok 에 구분자 지정
		if (sscanf(s, "%d", &num[cnt]) < 1)
			break;

	int dot[50][2]; //50개의 점 (시작, 종료)
	int idx = 0; //점의 개수는 idx개
	for (int i = 0; i < cnt; i++)
	{
		if (i % 2 == 0)
			dot[idx][0] = num[i];
		else
		{
			dot[idx][1] = num[i];
			idx++;
		}
	}

	//뒤 좌표 정렬
	for (int i = 0; i < idx-1; i++)
	{
		for (int j = i; j < idx; j++)
		{
			if (dot[i][1] > dot[j][1]) //뒤에 있는 수가 더 작다면
			{
				int tmp[2] = { dot[i][0], dot[i][1] };
				dot[i][0] = dot[j][0];
				dot[i][1] = dot[j][1];
				dot[j][0] = tmp[0];
				dot[j][1] = tmp[1];
			}
		}
	}

	//앞 좌표 정렬
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i; j < idx; j++)
		{
			if (dot[i][0] > dot[j][0]) //뒤에 있는 수가 더 작다면
			{
				int tmp[2] = { dot[i][0], dot[i][1] };
				dot[i][0] = dot[j][0];
				dot[i][1] = dot[j][1];
				dot[j][0] = tmp[0];
				dot[j][1] = tmp[1];
			}
		}
	}
	
	int final = -1; //끝나는 선의 좌표
	int result = 0; //결과 개수

	for (int i = 0; i < idx; i++)
	{
		if (dot[i][0] >= final) //시작점이 마지막에 끝나는 길이보다 크다면
		{
			result++;
			final = dot[i][1];
		}
	}

	printf("%d", result);
}