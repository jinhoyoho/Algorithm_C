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

	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) // strtok �� ������ ����
		if (sscanf(s, "%d", &num[cnt]) < 1)
			break;

	int dot[50][2]; //50���� �� (����, ����)
	int idx = 0; //���� ������ idx��
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

	//�� ��ǥ ����
	for (int i = 0; i < idx-1; i++)
	{
		for (int j = i; j < idx; j++)
		{
			if (dot[i][1] > dot[j][1]) //�ڿ� �ִ� ���� �� �۴ٸ�
			{
				int tmp[2] = { dot[i][0], dot[i][1] };
				dot[i][0] = dot[j][0];
				dot[i][1] = dot[j][1];
				dot[j][0] = tmp[0];
				dot[j][1] = tmp[1];
			}
		}
	}

	//�� ��ǥ ����
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = i; j < idx; j++)
		{
			if (dot[i][0] > dot[j][0]) //�ڿ� �ִ� ���� �� �۴ٸ�
			{
				int tmp[2] = { dot[i][0], dot[i][1] };
				dot[i][0] = dot[j][0];
				dot[i][1] = dot[j][1];
				dot[j][0] = tmp[0];
				dot[j][1] = tmp[1];
			}
		}
	}
	
	int final = -1; //������ ���� ��ǥ
	int result = 0; //��� ����

	for (int i = 0; i < idx; i++)
	{
		if (dot[i][0] >= final) //�������� �������� ������ ���̺��� ũ�ٸ�
		{
			result++;
			final = dot[i][1];
		}
	}

	printf("%d", result);
}