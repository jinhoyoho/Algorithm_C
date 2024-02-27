#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//insertSort
void insertion_sort(int A[], int n)
{
	int i, j, tmp;
	int comp = 0; //�񱳿��� ��������

	for (i = 1; i < n; i++)
	{
		tmp = A[i];

		comp++;
		for (j = i; A[j - 1] > tmp && j > 0; j--)
		{
			comp++;
			A[j] = A[j - 1]; //�տ� �� ū ���� �ڿ� ���� ����
		}
		A[j] = tmp; //tmp���� A[j]�� �Ҵ�
	}
	printf("Insertion Sort Count: %d\n", comp);
}

void swap(int* a, int* b) //swap�Լ�
{
	int temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

int quick_sort_comp = 0;

int partition(int A[], int p, int r)
{
	int pivot = A[p]; //��Ƽ���� ó�� ���� A[p]�� pivot���� �Ѵ�
	int h = p;
	for (int k = p + 1; k <= r; k++)
	{
		quick_sort_comp++; //if ���ǽ� �񱳿���
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
		int q = partition(A, p, r); //��Ƽ��
		quickSort(A, p, q - 1); //���� ��Ƽ�� ���ȣ��
		quickSort(A, q + 1, r); //���� ��Ƽ�� ���ȣ��
	}
}

int random_comp = 0;
int ranomized_partition(int A[], int p, int r)
{
	int random_value = rand() % (r - p + 1) + p; //p�� r���̿� ������ �� ����
	swap(&A[p], &A[random_value]); //A[p]�� ���� A[random_value]�� ����

	int pivot = A[p]; //��Ƽ���� ó�� ���� A[p]�� pivot���� �Ѵ�
	int h = p;

	for (int k = p + 1; k <= r; k++)
	{
		random_comp++; //������ �� ��
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
		int q = ranomized_partition(A, p, r); //��Ƽ��
		Randomized_quickSort(A, p, q - 1); //���� ��Ƽ�� ���ȣ��
		Randomized_quickSort(A, q + 1, r); //���� ��Ƽ�� ���ȣ��
	}
}

int main()
{
	srand(time(NULL));
	int num1[100];
	int num2[100];
	int num3[100]; //100���� ���� ������ ����

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