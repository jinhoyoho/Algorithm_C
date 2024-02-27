#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 541
#define NAME_SIZE 20
#define EMPTY 0
#define FALSE 0
#define TRUE 1

struct hash {
	char name[NAME_SIZE];
	unsigned short collision;
};

struct hash hash_table1[TABLE_SIZE];
struct hash hash_table2[TABLE_SIZE];

//hash1
int hash1(char str[])
{
	int i, h;
	for (i = 0, h = 0; i < strlen(str); i++)
	{
		h = ((int)str[i] + h) % TABLE_SIZE;
	}
	return h;
}
//hash2
int hash2(char str[])
{
	int i, h;
	for (i = 0, h = 0; i < strlen(str); i++)
	{
		h = (str[i] + h * h) % TABLE_SIZE;
	}
	return h;
}
//hash1 입력
int hash_insert1(char name[])
{
	int number = 0; // for collision
	int key = hash1(name); //hash1함수 사용

	while (strcmp(hash_table1[key].name, "") != 0)
	{
		hash_table1[key].collision++; //collision 기록
		number++; //현재 collision이 발생한 횟수
		key = (number + key) % TABLE_SIZE; //충돌이 없는 슬롯찾기
	}
	strcpy(hash_table1[key].name, name);
}
//hash2 입력
int hash_insert2(char name[])
{
	int number = 0; // for collision
	int key = hash2(name); //hash1함수 사용

	while (strcmp(hash_table2[key].name, "") != 0)
	{
		hash_table2[key].collision++; //collision 기록
		number++; //현재 collision이 발생한 횟수
		key = (number + key) % TABLE_SIZE; //충돌이 없는 슬롯찾기
	}
	strcpy(hash_table2[key].name, name);
}
//hash1 초기화
void initialize_table1()
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		strcpy(hash_table1[i].name, ""); //이름없음
		hash_table1[i].collision = 0; //충돌없음
	}
}
//hash2 초기화
void initialize_table2()
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		strcpy(hash_table2[i].name, ""); //이름없음
		hash_table2[i].collision = 0; //충돌없음
	}
}

int main()
{
	initialize_table1(); //해쉬 테이블1 초기화
	
	FILE* fp = fopen("names.txt", "r");
	char input1[NAME_SIZE]; //한줄씩 입력받을 이름 데이터
	int total_collision_hash1 = 0; //hash1 총 충돌 횟수

	while (EOF != fscanf(fp, "%s", input1))
	{
		hash_insert1(input1); //해쉬테이블1 입력
	}
	fclose(fp);

	printf("Hash1 출력결과 :\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("table[%d]: %s \t %d\n", i, hash_table1[i].name, hash_table1[i].collision);
		total_collision_hash1 += hash_table1[i].collision;
	}

	initialize_table2(); //해쉬 테이블2 초기화
	FILE* fp2 = fopen("names.txt", "r");
	char input2[NAME_SIZE]; //한줄씩 입력받을 이름 데이터
	int total_collision_hash2 = 0; //hash1 총 충돌 횟수

	while (EOF != fscanf(fp2, "%s", input2))
	{
		hash_insert2(input2); //해쉬테이블1 입력
	}
	fclose(fp2);

	printf("\n\n\nHash2 출력결과 :\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("table[%d]: %s \t %d\n", i, hash_table2[i].name, hash_table2[i].collision);
		total_collision_hash2 += hash_table2[i].collision;
	}

	printf("\n\nTotal collision number is Hash1 is %d\n", total_collision_hash1);
	printf("Total collision number is Hash2 is %d\n", total_collision_hash2);

	return 0;
}