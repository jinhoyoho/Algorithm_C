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
	int num[100], i, cnt = 0; //num�� ����, cnt�� ������ ����

	for (s = strtok(str, " "); s; s = strtok(NULL, " "), cnt++) // strtok �� ������ ����
		if (sscanf(s, "%d", &num[cnt]) < 1)
			break;
    
	int idx = 0;
	while (idx < cnt)
	{
		int bottle = num[idx]; //����뷮
		int cup_300 = 0; //300ml�� ��� Ƚ��
		int cup_500 = 0; //500ml�� ��� Ƚ��
		int result = 9876543210; //��� ����
		for (int i = bottle / 500; i >= 0; i--)
		{
			if (((bottle - i * 500) % 300) == 0)
			{
				cup_300 = (bottle - i * 500) / 300;
				cup_500 = i;
			}
			if (result > cup_300 + cup_500 && cup_300 + cup_500 != 0) //0�� �ƴϰ� ���� ������� �۴ٸ�
				result = cup_300 + cup_500; //��� ����
		}
		if ((cup_300 == 0) && (cup_500 == 0))
			printf("-1 ");
		else
			printf("%d ", result);

		idx++;
	}

}