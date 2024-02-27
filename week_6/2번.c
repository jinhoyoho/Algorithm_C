#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) //swap�Լ�
{
	int temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

int partition(int A[], int p, int r)
{
	int pivot = A[p]; //��Ƽ���� ó�� ���� A[p]�� pivot���� �Ѵ�
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
		int q = partition(A, p, r); //��Ƽ��
		quickSort(A, p, q - 1); //���� ��Ƽ�� ���ȣ��
		quickSort(A, q + 1, r); //���� ��Ƽ�� ���ȣ��
	}
}

int main()
{
	FILE* fp = fopen("input.txt", "r");
	char buffer[1024]; //���� ����
	int num[50] = { 0, }; //50���� ���� ����

	int idx = 0; //num�� ���� index
	int j = 0; //input_num�� ���� index
	int input[2] = { 0, }; //������ ��

	while (fgets(buffer, 1024, fp)) //buffer�� ����
	{
		for (int i = 0; i < 1024; i++)
		{
			if (buffer[i] == NULL)
				break;
			else if (48 <= buffer[i] && buffer[i] <= 57)
			{
				input[j] = (int)buffer[i] - 48; //�� ����
				j++;
			}
			else if (buffer[i] == '\t')
			{
				if (j == 2) //���ڸ��� ���
				{
					num[idx] = input[0] * 10 + input[1];
				}
				else
				{
					num[idx] = input[0]; //���ڸ��� ���
				}
				j = 0;
				input[0] = 0;
				input[1] = 0; //�ʱ�ȭ
				idx++; //�ε��� ����
			}
		}
	}
	//������ �� ����
	if (j == 2) //���ڸ��� ���
	{
		num[idx] = input[0] * 10 + input[1];
	}
	else
	{
		num[idx] = input[0]; //���ڸ��� ���
	}

	fclose(fp);

	//���� �� �迭
	printf("#####���� �� �迭#####\n");
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	quickSort(num, 0, 49);

	//���� �� �迭
	printf("\n#####���� �� �迭#####\n");
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	return 0;
}