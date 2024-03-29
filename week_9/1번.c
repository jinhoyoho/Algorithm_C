#include <stdio.h>
#include <stdlib.h>

int graph[9][9] = {
	{0,0,0,0,0,0,0,0,0}, //0번 노드
	{0,0,1,1,1,0,0,0,0}, //1번 노드
	{0,1,0,0,1,1,0,1,0}, //2번 노드
	{0,1,0,0,1,0,0,0,0}, //3번 노드
	{0,1,1,1,0,0,1,0,0}, //4번 노드
	{0,0,1,0,0,0,0,1,1}, //5번 노드
	{0,0,0,0,1,0,0,0,0}, //6번 노드
	{0,0,1,0,0,1,0,0,1}, //7번 노드
	{0,0,0,0,0,1,0,1,0}  //8번 노드
};

int visited[9] = { 0 , }; //방문기록 0

void dfs(int v)
{
	visited[v] = 1; //노드 방문
	printf("%d ", v); //방문한 노드 출력

	for (int i = 1; i < 9; i++)
	{
		if (graph[v][i] == 1 && visited[i] == 0) //방문할 수 있고 방문한 적이 없다면
		{
			dfs(i); //dfs실행
		}
	}
}

int main()
{
	dfs(1);
	return 0;
}