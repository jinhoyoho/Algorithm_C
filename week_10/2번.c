#include <stdio.h>
#include <stdlib.h>
#define VERTEX_SIZE 8 //the number of vertices
#define MAX 9999 //MAX is 9999
#define TRUE 1
#define FALSE 0

int dist[VERTEX_SIZE]; //start vertex�� Ư�� �������� �Ÿ� ����

int toBechecked[VERTEX_SIZE]; //Ư�� �������� �����Ÿ��� ���Ǿ����� ��Ÿ���� �迭

int prev[VERTEX_SIZE]; //��ο��� �ٷ� ���� ������ ��Ÿ���� �迭


int heap[MAX], heapSize;

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

void push(int data)
{
	int idx = ++heapSize;
	while (idx > 1)
	{
		if (dist[data] < dist[heap[(idx >> 1) - 1]])
		{
			heap[idx - 1] = heap[(idx >> 1) - 1];
			idx >>= 1;
		}
		else
			break;
	}
	heap[idx - 1] = data;
}
void pop(void)
{
	int idx = 1;
	int last = heap[--heapSize];
	for (;;)
	{
		if ((heapSize >> 1) < idx)
			break;
		idx <<= 1;
		if ((heapSize >> 1) == idx && !(heapSize & 1))
		{}
		else if (dist[heap[idx]] < dist[heap[idx - 1]])
			++idx;
		
		if (dist[heap[idx - 1]] < dist[last])
			heap[(idx >> 1) - 1] = heap[idx - 1];
		else
		{
			idx >>= 1;
			break;
		}
	}
	heap[idx - 1] = last;
}
void dijkstra(int start)
{
	push(start);
	int from, to, cost;
	
	while (heapSize > 0)
	{
		from = heap[0];
		pop();
		
		if (toBechecked[from])
		{
			toBechecked[from] = FALSE;
			
			for (int i = 0; i < VERTEX_SIZE; i++)
			{
				if (graph[from][i] != MAX) //i�� �����ϴٸ�
				{
					if (dist[i] > dist[from] + graph[from][i]) //������ ������ ���ο� ���� �� �۴ٸ�
					{
						dist[i] = dist[from] + graph[from][i]; //�� ����
						push(i);
						prev[i] = from + 1; //i�� ���� ��忡 ������� ����
					}
				}
			}
		}
	}

}

void main()
{
	int FIRST = 0; //��� ���

	for (int i = 0; i < VERTEX_SIZE; i++)
	{
		dist[i] = MAX; //�Ÿ��� �ʱ�ȭ
		toBechecked[i] = TRUE; //Ȯ�ο��� �ʱ�ȭ
	}

	dist[FIRST] = 0; //��� ��� distance���� 0���� �ʱ�ȭ
	prev[FIRST] = 0; //��� ��� prev���� 0���� �ʱ�ȭ

	dijkstra(FIRST);

	for (int i = 0; i < VERTEX_SIZE; i++)
		printf("Node %d: distance %d: %d\n", i + 1, dist[i], prev[i]);

	return 0;
}