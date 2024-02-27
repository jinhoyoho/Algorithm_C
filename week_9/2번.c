#include <stdio.h>
#include <stdlib.h>
#define Qsize 8

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

int Queue[Qsize]; //큐 만들어야함
int first = 0; //처음
int last = 0; //끝

int isFull()
{
	//first가 0이고 last가 QSize-1이거나 first가 last보다 큰 경우
	return ((first == 0 && last == Qsize - 1) || (first == last + 1));
}

int isEmpty()
{
	return first == last; //first와 last가 같은 경우 empty
}

int enqueue(int v)
{
	if (!isFull()) //차있지 않다면
	{
		last = (last + 1) % Qsize;
	    Queue[last] = v;
    }
	else
		return -1; //큐가 가득 찼다면 False
	
	return v; //v를 큐에 넣었음
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
	visited[1] = 1; //시작노드 방문처리
	enqueue(1); //1큐에 저장

	while (!isEmpty())
	{
		int w = dequeue(); //큐에 있는 수 제거
		printf("%d ", w);
		for (int i = 1; i < 9; i++)
		{
			if (graph[w][i] == 1 && visited[i] == 0) //그래프가 연결되어 있고 방문한 적이 없다면
			{
				visited[i] = 1; //방문처리
				enqueue(i); //큐에 넣기
			}
		}
	}
}

int main()
{
	bfs();
	return 0;
}