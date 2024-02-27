#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand((unsigned int)time(NULL));
	double x, y; //점 (x, y)
	double inside_cnt = 0;
	double outside_cnt = 0; //원 안의 점의 개수, 원 밖의 점의 개수
	double pi; //구하고자 하는 값

	for (int i = 0; i < 1000; i++) //1000번 실행
	{
		x = (double)rand() / RAND_MAX; //0~1사이 소수
		x = x * 10; //정수로 만들기 
		y = (double)rand() / RAND_MAX; //0~1사이 소수
		y = y * 10; //정수로 만들기
		
		if (x * x + y * y < 100) //두 점이 원 안에 있으면
			inside_cnt += 1;
		else //원 밖에 있으면
			outside_cnt += 1;
	}

	pi = 4.0 * inside_cnt / (inside_cnt + outside_cnt); //결과 구하기

	printf("pi = %lf", pi);

	return 0;
}