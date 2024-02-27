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
			 A[j] = A[j-1]; //�տ� �� ū ���� �ڿ� ���� ����
		}
		A[j] = tmp; //tmp���� A[j]�� �Ҵ�
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
	for (int i = 0; i<50; i++)
		printf("%d\t", num[i]);

	insertion_sort(num, 50);

    //���� �� �迭
	printf("\n#####���� �� �迭#####\n");
	for (int i = 0; i < 50; i++)
		printf("%d\t", num[i]);

	return 0;
}