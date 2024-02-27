#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 38 //null빼고 38

unsigned int encryption[MESSAGE_LENGTH]; //암호화된 문자들 저장
char decryption[MESSAGE_LENGTH]; //복호화된 문자들 저장

char message[] = { 'H', 'e', 'l', 'l', 'o', ' ', //6개
    'D', 'o', 'n', 'g', 'g', 'u', 'k', '.', ' ', //9개
	'M', 'y', ' ' , 'n', 'a', 'm', 'e', ' ' , 'i', 's', ' ', //11개
	'W','o','o','n','g','s','u','p',' ', 'K','i','m', '\0' }; //13개 (null빼면 12개)

unsigned int do_exp(int c, int key, int N)
{
	unsigned int prod = 1;

	for (int i = 0; i < key; i++) //key번 제곱하기
		prod = (prod * c) % N; //곱할때마다 나머지 연산 해주기

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
		return n1;
	}
}

int main()
{
	int p = 11, q = 17, e = 3;
	int N = p * q; //공개키(N, e)
	
	int d; //비밀키

	struct _node* n;
	n = (struct _node*)malloc(sizeof(struct _node));
	int a = e;
	int b = (p - 1) * (q - 1);
	
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
	d = n->x + (p - 1) * (q - 1); //음수가 나오므로 더하기 -> 키값은 107
	
	for (int i = 0; i < MESSAGE_LENGTH; i++)
	{
		char ch = message[i]; //문자 하나를 변수에 저장
		int c = (unsigned int)ch; //문자를 정수로 변환
		encryption[i] = do_exp(c, e, N);
	}

	print_encryption(encryption); //출력

	for (int i = 0; i < MESSAGE_LENGTH; i++)
	{
		int c = encryption[i]; //정수 전달
		decryption[i] = (char)do_exp(c, d, N); //복호화 진행
	}

	print_decryption(decryption); //복호화 출력

	return 0;
}