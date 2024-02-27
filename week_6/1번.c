#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int n)
{
	int i, j, tmp;

	for (i = 1; i < n; i++)
	{
		tmp = A[i];

		for (j = i; A[j - 1] > tmp && j > 0; j--)
		{
			 A[j] = A[j-1]; //앞에 더 큰 값을 뒤에 수에 저장
		}
		A[j] = tmp; //tmp값을 A[j]에 할당
	}
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	char buffer[1024]; //파일 저장
	int num[50] = { 0, }; //50개의 숫자 저장

	int idx = 0; //num에 넣을 index
	int j = 0; //input_num에 넣을 index
	int input[2] = { 0, }; //각각의 수

	while (fgets(buffer, 1024, fp)) //buffer에 저장
	{
		for (int i = 0; i < 1024; i++)
		{
			if (buffer[i] == NULL)
				break;
			else if (48 <= buffer[i] && buffer[i] <= 57)
			{
				input[j] = (int)buffer[i] - 48; //수 저장
				j++;
			}
			else if (buffer[i] == '\t')
			{
				if (j == 2) //두자리일 경우
				{
					num[idx] = input[0] * 10 + input[1]; 
				}
				else
				{
					num[idx] = input[0]; //한자리일 경우
				}
				j = 0;
				input[0] = 0;
				input[1] = 0; //초기화
				idx++; //인덱스 증가
			}
		}
	}
	//마지막 수 저장
	if (j == 2) //두자리일 경우
	{
		num[idx] = input[0] * 10 + input[1];
	}
	else
	{
		num[idx] = input[0]; //한자리일 경우
	}

	fclose(fp);

	//정렬 전 배열
	printf("#####정렬 전 배열#####\n");
	for (int i = 0; i<50; i++)
		printf("%d\t", num[i]);

	insertion_sort(num, 50);

    //정렬 후 배열
	printf("\n#####정렬 후 배열#####\n");
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	return 0;
}