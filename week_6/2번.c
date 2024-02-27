#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) //swap함수
{
	int temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

int partition(int A[], int p, int r)
{
	int pivot = A[p]; //파티션의 처음 값인 A[p]를 pivot으로 한다
	int h = p;
	for (int k = p + 1; k <= r; k++)
	{
		if (A[k] < pivot)
		{
			h = h + 1;
			swap(&A[h], &A[k]);
		}
	}
	swap(&A[p], &A[h]);

	return h;
}


void quickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r); //파티션
		quickSort(A, p, q - 1); //좌측 파티션 재귀호출
		quickSort(A, q + 1, r); //우측 파티션 재귀호출
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
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	quickSort(num, 0, 49);

	//정렬 후 배열
	printf("\n#####정렬 후 배열#####\n");
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	return 0;
}