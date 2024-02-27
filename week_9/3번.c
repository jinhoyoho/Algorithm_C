#include <stdio.h>
#include <stdlib.h>

int result[9] = { 0, }; //결과를 저장할 리스트

void sort(int a[], int n) //내림차순으로 정렬
{
	int i, j, tmp, tmp_index;

	for (i = 1; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (a[i] < a[j]) // 앞에 있는 수가 더 작다면
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp; //기존값 swap

				tmp_index = result[i];
				result[i] = result[j];
				result[j] = tmp_index;
			}
		}
	}
}

int graph[9][9] = {
	{0,0,0,0,0,0,0,0,0}, //0번 노드
	{0,0,0,1,0,0,0,0,0}, //1번 노드
	{0,1,0,0,0,1,0,0,0}, //2번 노드
	{0,0,0,0,1,0,0,1,0}, //3번 노드
	{0,0,0,0,0,0,0,0,0}, //4번 노드
	{0,0,0,0,1,0,1,0,0}, //5번 노드
	{0,0,0,0,0,0,0,0,1}, //6번 노드
	{0,0,0,0,0,0,0,0,0}, //7번 노드
	{0,0,0,0,0,0,0,1,0}  //8번 노드
};

int visited[9] = { 0 , }; //방문기록 0
int pre[9] = { 0, }; //시작시 pre
int post[9] = { 0, }; //종료시 post
int count = 1; // pre, post에 저장할 값
int idx = 1; //result에 저장할 인덱스

void dfs(int v)
{
	pre[v] = count++;
	visited[v] = 1; //노드 방문

	for (int i = 1; i < 9; i++)
	{
		if (graph[v][i] == 1 && visited[i] == 0) //방문할 수 있고 방문한 적이 없다면
		{
			dfs(i); //dfs실행
			post[i] = count++;
		}
	}
}

void topologicalSort()
{
	for (int i = 1; i < 9; i++)
	{
		if (visited[i] == 0) //방문한 적이 없으면
		{
			dfs(i); //dfs실행
			if (post[i] == 0)
			{
				post[i] = count++;
			}
		}
	}

	for (int i = 1; i < 9; i++)
	{
		printf("pre: %d, post: %d\n", pre[i], post[i]);
		result[i] = i; //index에 순서대로 넣기
	}
}

int main()
{
	topologicalSort();
	sort(post, 9);
	for (int i = 1; i < 9; i++)
		printf("%d ", result[i]);
	return 0;
}