#include <stdio.h>
#include <stdlib.h>

struct _node
{
	int x; //x값
	int y; //y값
	int c; //c값
};

struct _node* extended_Euclid(int a, int b) // a >= b
{
	struct _node* n1, * n2;
	n1 = (struct _node*)malloc(sizeof(struct _node)); //저장할 값
	n2 = (struct _node*)malloc(sizeof(struct _node)); //temp역할

	if (b == 0) //탈출지점 정의
	{
		n1->x = 1;
		n1->y = 0;
		n1->c = a;

		return n1;
	}
	else
	{
		n2 = extended_Euclid(b, a % b);
		n1->x = n2->y;
		n1->y = n2->x - (a / b) * n2->y;
		n1->c = n2->c;
		printf("%d %d %d\n", n1->x, n1->y, n1->c);
		return n1;
	}
}

int main()
{
	struct _node* n;
	n = (struct _node*)malloc(sizeof(struct _node));
	int a, b; //입력받는 정수 2개의 값
	printf("\n\n Type two positive integers -> ");
	scanf("%d %d", &a, &b);
	n->x = a;
	n->y = b;

	if (b < 0 || a < 0) //입력이 음수인 경우
	{
		printf("Error\n"); //에러
		exit(-1); //종료
	}
	else if (a == 0 || b == 0) //a와 b 둘 중에 하나가 0인 경우
	{
		if (a == 0) //a가 0인경우
			n->c = b; //gcd는 b
		else
			n->c = a; // gcd는 a
	}

	n = extended_Euclid(a, b); //확장 유클리드 실행
	
	printf("x is %d, y is %d, and c is %d \n", n->x, n->y, n->c);

	return 0;
}