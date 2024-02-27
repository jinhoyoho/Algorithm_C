#include <stdio.h>
#include <stdlib.h>
#define VERTEX_SIZE 8 //the number of vertices
#define MAX 9999 //MAX is 9999
#define TRUE 1
#define FALSE 0

int dist[VERTEX_SIZE]; //start vertex와 특정 정점과의 거리 저장

int toBechecked[VERTEX_SIZE]; //특정 정점에서 최종거리가 계산되었는지 나타내는 배열

int prev[VERTEX_SIZE]; //경로에서 바로 앞의 정점을 나타내는 배열


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
				if (graph[from][i] != MAX) //i가 인접하다면
				{
					if (dist[i] > dist[from] + graph[from][i]) //기존의 값보다 새로운 값이 더 작다면
					{
						dist[i] = dist[from] + graph[from][i]; //값 갱신
						push(i);
						prev[i] = from + 1; //i로 가는 노드에 이전노드 저장
					}
				}
			}
		}
	}

}

void main()
{
	int FIRST = 0; //출발 노드

	for (int i = 0; i < VERTEX_SIZE; i++)
	{
		dist[i] = MAX; //거리값 초기화
		toBechecked[i] = TRUE; //확인여부 초기화
	}

	dist[FIRST] = 0; //출발 노드 distance값을 0으로 초기화
	prev[FIRST] = 0; //출발 노드 prev값을 0으로 초기화

	dijkstra(FIRST);

	for (int i = 0; i < VERTEX_SIZE; i++)
		printf("Node %d: distance %d: %d\n", i + 1, dist[i], prev[i]);

	return 0;
}