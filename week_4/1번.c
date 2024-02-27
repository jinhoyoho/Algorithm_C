#include <stdio.h>

int main()
{
	char str[47] = "Hello, I love Dongguk. Please love Lee Jinho!!!"; //문자열 배열
	int key = 5; //키 값
	int idx = 0; //배열 index값
	char encryption[47]; //암호화한 문자를 저장할 배열
	char decryption[47]; //복호화한 문자를 저장할 배열

	//암호화
	for(int idx = 0; idx<47; idx++)
	{
		char c = (unsigned int)str[idx]; //배열에 있는 문자열 하나를 정수로 저장
		encryption[idx] = c ^ key; //암호화한 문자 저장
	}

	//암호화한 문자열 출력
	for (int idx = 0; idx < 47; idx++)
		printf("%c", encryption[idx]);
	printf("\n\n");
	
	for (int idx = 0; idx < 47; idx++)
	{
		char c = (unsigned int)encryption[idx];
		decryption[idx] = c ^ key; //복호화한 문자 저장
	}

	//복호화한 문자열 출력
	for (int idx = 0; idx < 47; idx++)
		printf("%c", decryption[idx]);
	printf("\n\n");

	return 0;
}