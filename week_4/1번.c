#include <stdio.h>

int main()
{
	char str[47] = "Hello, I love Dongguk. Please love Lee Jinho!!!"; //���ڿ� �迭
	int key = 5; //Ű ��
	int idx = 0; //�迭 index��
	char encryption[47]; //��ȣȭ�� ���ڸ� ������ �迭
	char decryption[47]; //��ȣȭ�� ���ڸ� ������ �迭

	//��ȣȭ
	for(int idx = 0; idx<47; idx++)
	{
		char c = (unsigned int)str[idx]; //�迭�� �ִ� ���ڿ� �ϳ��� ������ ����
		encryption[idx] = c ^ key; //��ȣȭ�� ���� ����
	}

	//��ȣȭ�� ���ڿ� ���
	for (int idx = 0; idx < 47; idx++)
		printf("%c", encryption[idx]);
	printf("\n\n");
	
	for (int idx = 0; idx < 47; idx++)
	{
		char c = (unsigned int)encryption[idx];
		decryption[idx] = c ^ key; //��ȣȭ�� ���� ����
	}

	//��ȣȭ�� ���ڿ� ���
	for (int idx = 0; idx < 47; idx++)
		printf("%c", decryption[idx]);
	printf("\n\n");

	return 0;
}