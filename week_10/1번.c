#include <stdio.h>
#include <stdlib.h>
#define VERTEX_SIZE 8 //the number of vertices
#define MAX 9999 //MAX is 9999
#define TRUE 1
#define FALSE 0

int dist[VERTEX_SIZE]; //start vertex와 특정 정점과의 거리 저장

int toBechecked[VERTEX_SIZE]; //특정 정점에서 최종거리가 계산되었는지 나타내는 배열

int prev[VERTEX_SIZE]; //경로에서 바로 앞의 정점을 나타내는 배열

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
		if (graph[start][i] != MAX) //i가 인접하다면
		{
			if (dist[i] > dist[start] + graph[start][i]) //기존의 값보다 새로운 값이 더 작다면
			{
				dist[i] = dist[start] + graph[start][i]; //값 갱신
				prev[i] = start+1; //i로 가는 노드에 이전노드 저장
			}
		}
	}
}

int main()
{
	int FIRST = 0; //출발 노드

	for (int i = 0; i < VERTEX_SIZE; i++)
	{
		dist[i] = MAX; //거리값 초기화
		toBechecked[i] = TRUE; //확인여부 초기화
	}

	dist[FIRST] = 0; //출발 노드 distance값을 0으로 초기화
	prev[FIRST] = 0; //출발 노드 prev값을 0으로 초기화

	while (TRUE) //1. toBechecked 배열에 TRUE인 값을 가지는 원소가 있을 경우
	{
		int min = MAX;
		int min_index = MAX; //최솟값 찾기
		int count = 0;

		for (int i = 0; i < VERTEX_SIZE; i++)
		{
			if (toBechecked[i]) //해당 tobechecked값이 참이라면
			{
				int value = dist[i];
				if (min > value) //기존 dist보다 작다면
				{
					min = value; //최소값 갱신
					min_index = i; //최소 인덱스 갱신
				}
			}
			else //해당 값이 False라면
				count++; //count값 증가
		}

		if (toBechecked[min_index])
		{
			dijkstra(min_index); //해당 인덱스에 대해서 다익스트라 실행
			toBechecked[min_index] = FALSE;
		}

		if (count >= VERTEX_SIZE-1)
			break;
	}

	for (int i = 0; i < VERTEX_SIZE; i++)
		printf("Node %d: distance %d: %d\n", i + 1, dist[i], prev[i]);

	return 0;
}