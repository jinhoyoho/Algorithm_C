#include <stdio.h>
#include <stdlib.h>
#define VERTEX_SIZE 8 //the number of vertices
#define MAX 9999 //MAX is 9999
#define TRUE 1
#define FALSE 0

int dist[VERTEX_SIZE]; //start vertex�� Ư�� �������� �Ÿ� ����

int toBechecked[VERTEX_SIZE]; //Ư�� �������� �����Ÿ��� ���Ǿ����� ��Ÿ���� �迭

int prev[VERTEX_SIZE]; //��ο��� �ٷ� ���� ������ ��Ÿ���� �迭

int graph[VERTEX_SIZE][VERTEX_SIZE] = {
	{0,6,3,2,MAX,MAX,MAX,MAX},		//node1
	{6,0,MAX,2,3,MAX,2,MAX},		//node2
	{3,MAX,0,1,MAX,7,MAX,MAX},		//node3
	{2,2,1,0,MAX,4,3,MAX},			//node4
	{MAX,3,MAX,MAX,0,MAX,7,9},		//node5
	{MAX,MAX,7,4,MAX,0,MAX,MAX},	//node6
	{MAX,2,MAX,3,7,MAX,0,4},		//node7
	{MAX,MAX,MAX,MAX,9,MAX,4,0}		//node8
};

void dijkstra(int start)
{
	for (int i = 0; i < VERTEX_SIZE; i++)
	{
		if (graph[start][i] != MAX) //i�� �����ϴٸ�
		{
			if (dist[i] > dist[start] + graph[start][i]) //������ ������ ���ο� ���� �� �۴ٸ�
			{
				dist[i] = dist[start] + graph[start][i]; //�� ����
				prev[i] = start+1; //i�� ���� ��忡 ������� ����
			}
		}
	}
}

int main()
{
	int FIRST = 0; //��� ���

	for (int i = 0; i < VERTEX_SIZE; i++)
	{
		dist[i] = MAX; //�Ÿ��� �ʱ�ȭ
		toBechecked[i] = TRUE; //Ȯ�ο��� �ʱ�ȭ
	}

	dist[FIRST] = 0; //��� ��� distance���� 0���� �ʱ�ȭ
	prev[FIRST] = 0; //��� ��� prev���� 0���� �ʱ�ȭ

	while (TRUE) //1. toBechecked �迭�� TRUE�� ���� ������ ���Ұ� ���� ���
	{
		int min = MAX;
		int min_index = MAX; //�ּڰ� ã��
		int count = 0;

		for (int i = 0; i < VERTEX_SIZE; i++)
		{
			if (toBechecked[i]) //�ش� tobechecked���� ���̶��
			{
				int value = dist[i];
				if (min > value) //���� dist���� �۴ٸ�
				{
					min = value; //�ּҰ� ����
					min_index = i; //�ּ� �ε��� ����
				}
			}
			else //�ش� ���� False���
				count++; //count�� ����
		}

		if (toBechecked[min_index])
		{
			dijkstra(min_index); //�ش� �ε����� ���ؼ� ���ͽ�Ʈ�� ����
			toBechecked[min_index] = FALSE;
		}

		if (count >= VERTEX_SIZE-1)
			break;
	}

	for (int i = 0; i < VERTEX_SIZE; i++)
		printf("Node %d: distance %d: %d\n", i + 1, dist[i], prev[i]);

	return 0;
}