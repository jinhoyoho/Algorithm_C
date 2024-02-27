#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 38 //null���� 38

unsigned int encryption[MESSAGE_LENGTH]; //��ȣȭ�� ���ڵ� ����
char decryption[MESSAGE_LENGTH]; //��ȣȭ�� ���ڵ� ����

char message[] = { 'H', 'e', 'l', 'l', 'o', ' ', //6��
    'D', 'o', 'n', 'g', 'g', 'u', 'k', '.', ' ', //9��
	'M', 'y', ' ' , 'n', 'a', 'm', 'e', ' ' , 'i', 's', ' ', //11��
	'W','o','o','n','g','s','u','p',' ', 'K','i','m', '\0' }; //13�� (null���� 12��)

unsigned int do_exp(int c, int key, int N)
{
	unsigned int prod = 1;

	for (int i = 0; i < key; i++) //key�� �����ϱ�
		prod = (prod * c) % N; //���Ҷ����� ������ ���� ���ֱ�

	return prod; 
}

void print_encryption(int e[])
{
	for (int i = 0; i < MESSAGE_LENGTH; i++)
		printf("%d", e[i]);
	printf("\n");
}

void print_decryption(char e[])
{
	for (int i = 0; i < MESSAGE_LENGTH; i++)
		printf("%c", e[i]);
	printf("\n");
}

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
		return n1;
	}
}

int main()
{
	int p = 11, q = 17, e = 3;
	int N = p * q; //����Ű(N, e)
	
	int d; //���Ű

	struct _node* n;
	n = (struct _node*)malloc(sizeof(struct _node));
	int a = e;
	int b = (p - 1) * (q - 1);
	
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
	d = n->x + (p - 1) * (q - 1); //������ �����Ƿ� ���ϱ� -> Ű���� 107
	
	for (int i = 0; i < MESSAGE_LENGTH; i++)
	{
		char ch = message[i]; //���� �ϳ��� ������ ����
		int c = (unsigned int)ch; //���ڸ� ������ ��ȯ
		encryption[i] = do_exp(c, e, N);
	}

	print_encryption(encryption); //���

	for (int i = 0; i < MESSAGE_LENGTH; i++)
	{
		int c = encryption[i]; //���� ����
		decryption[i] = (char)do_exp(c, d, N); //��ȣȭ ����
	}

	print_decryption(decryption); //��ȣȭ ���

	return 0;
}