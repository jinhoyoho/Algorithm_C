#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand((unsigned int)time(NULL));
	double x, y; //�� (x, y)
	double inside_cnt = 0;
	double outside_cnt = 0; //�� ���� ���� ����, �� ���� ���� ����
	double pi; //���ϰ��� �ϴ� ��

	for (int i = 0; i < 1000; i++) //1000�� ����
	{
		x = (double)rand() / RAND_MAX; //0~1���� �Ҽ�
		x = x * 10; //������ ����� 
		y = (double)rand() / RAND_MAX; //0~1���� �Ҽ�
		y = y * 10; //������ �����
		
		if (x * x + y * y < 100) //�� ���� �� �ȿ� ������
			inside_cnt += 1;
		else //�� �ۿ� ������
			outside_cnt += 1;
	}

	pi = 4.0 * inside_cnt / (inside_cnt + outside_cnt); //��� ���ϱ�

	printf("pi = %lf", pi);

	return 0;
}