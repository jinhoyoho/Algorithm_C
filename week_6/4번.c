#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//insertSort
void insertion_sort(int A[], int n)
{
	int i, j, tmp;
	int comp = 0; //비교연산 개수세기

	for (i = 1; i < n; i++)
	{
		tmp = A[i];

		comp++;
		for (j = i; A[j - 1] > tmp && j > 0; j--)
		{
			comp++;
			A[j] = A[j - 1]; //앞에 더 큰 값을 뒤에 수에 저장
		}
		A[j] = tmp; //tmp값을 A[j]에 할당
	}
	printf("Insertion Sort Count: %d\n", comp);
}

void swap(int* a, int* b) //swap함수
{
	int temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

int quick_sort_comp = 0;

int partition(int A[], int p, int r)
{
	int pivot = A[p]; //파티션의 처음 값인 A[p]를 pivot으로 한다
	int h = p;
	for (int k = p + 1; k <= r; k++)
	{
		quick_sort_comp++; //if 조건식 비교연산
		if (A[k] < pivot)
		{
			h = h + 1;
			swap(&A[h], &A[k]);
		}
	}
	swap(&A[p], &A[h]);

	return h;
}

//QuickSort
void quickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r); //파티션
		quickSort(A, p, q - 1); //좌측 파티션 재귀호출
		quickSort(A, q + 1, r); //우측 파티션 재귀호출
	}
}

int random_comp = 0;
int ranomized_partition(int A[], int p, int r)
{
	int random_value = rand() % (r - p + 1) + p; //p와 r사이에 랜덤한 값 생성
	swap(&A[p], &A[random_value]); //A[p]의 값과 A[random_value]값 변경

	int pivot = A[p]; //파티션의 처음 값인 A[p]를 pivot으로 한다
	int h = p;

	for (int k = p + 1; k <= r; k++)
	{
		random_comp++; //데이터 값 비교
		if (A[k] < pivot)
		{
			h = h + 1;
			swap(&A[h], &A[k]);
		}
	}
	swap(&A[p], &A[h]);

	return h;
}

//Ramdomized_quickSort
void Randomized_quickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = ranomized_partition(A, p, r); //파티션
		Randomized_quickSort(A, p, q - 1); //좌측 파티션 재귀호출
		Randomized_quickSort(A, q + 1, r); //우측 파티션 재귀호출
	}
}

int main()
{
	srand(time(NULL));
	int num1[100];
	int num2[100];
	int num3[100]; //100개의 같은 데이터 저장

	for (int i = 0; i < 100; i++)
	{
		num1[i] = rand();
		num2[i] = num1[i];
		num3[i] = num1[i];
	}
	
	insertion_sort(num1, 100);
	quickSort(num2, 0, 99);
	printf("Quick Sort count: %d\n", quick_sort_comp);
	Randomized_quickSort(num3, 0, 99);
	printf("Randomized Quick Sort count: %d\n", random_comp);

	return 0;
}