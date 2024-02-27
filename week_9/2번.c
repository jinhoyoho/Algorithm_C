#include <stdio.h>
#include <stdlib.h>
#define Qsize 8

int graph[9][9] = {
	{0,0,0,0,0,0,0,0,0}, //0�� ���
	{0,0,1,1,1,0,0,0,0}, //1�� ���
	{0,1,0,0,1,1,0,1,0}, //2�� ���
	{0,1,0,0,1,0,0,0,0}, //3�� ���
	{0,1,1,1,0,0,1,0,0}, //4�� ���
	{0,0,1,0,0,0,0,1,1}, //5�� ���
	{0,0,0,0,1,0,0,0,0}, //6�� ���
	{0,0,1,0,0,1,0,0,1}, //7�� ���
	{0,0,0,0,0,1,0,1,0}  //8�� ���
};

int visited[9] = { 0 , }; //�湮��� 0

int Queue[Qsize]; //ť ��������
int first = 0; //ó��
int last = 0; //��

int isFull()
{
	//first�� 0�̰� last�� QSize-1�̰ų� first�� last���� ū ���
	return ((first == 0 && last == Qsize - 1) || (first == last + 1));
}

int isEmpty()
{
	return first == last; //first�� last�� ���� ��� empty
}

int enqueue(int v)
{
	if (!isFull()) //������ �ʴٸ�
	{
		last = (last + 1) % Qsize;
	    Queue[last] = v;
    }
	else
		return -1; //ť�� ���� á�ٸ� False
	
	return v; //v�� ť�� �־���
}

int dequeue()
{
	int v;

	if (!isEmpty())
	{
		first = (first + 1) % Qsize;
		v = Queue[first];
	}
	else
		return -1;
	return v;
}

void bfs()
{
	visited[1] = 1; //���۳�� �湮ó��
	enqueue(1); //1ť�� ����

	while (!isEmpty())
	{
		int w = dequeue(); //ť�� �ִ� �� ����
		printf("%d ", w);
		for (int i = 1; i < 9; i++)
		{
			if (graph[w][i] == 1 && visited[i] == 0) //�׷����� ����Ǿ� �ְ� �湮�� ���� ���ٸ�
			{
				visited[i] = 1; //�湮ó��
				enqueue(i); //ť�� �ֱ�
			}
		}
	}
}

int main()
{
	bfs();
	return 0;
}