#include <stdio.h>
#include <stdlib.h>

struct _node
{
	int x; //x��
	int y; //y��
	int c; //c��
};

struct _node* extended_Euclid(int a, int b) // a >= b
{
	struct _node* n1, * n2;
	n1 = (struct _node*)malloc(sizeof(struct _node)); //������ ��
	n2 = (struct _node*)malloc(sizeof(struct _node)); //temp����

	if (b == 0) //Ż������ ����
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
	int a, b; //�Է¹޴� ���� 2���� ��
	printf("\n\n Type two positive integers -> ");
	scanf("%d %d", &a, &b);
	n->x = a;
	n->y = b;

	if (b < 0 || a < 0) //�Է��� ������ ���
	{
		printf("Error\n"); //����
		exit(-1); //����
	}
	else if (a == 0 || b == 0) //a�� b �� �߿� �ϳ��� 0�� ���
	{
		if (a == 0) //a�� 0�ΰ��
			n->c = b; //gcd�� b
		else
			n->c = a; // gcd�� a
	}

	n = extended_Euclid(a, b); //Ȯ�� ��Ŭ���� ����
	
	printf("x is %d, y is %d, and c is %d \n", n->x, n->y, n->c);

	return 0;
}