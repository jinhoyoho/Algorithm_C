#include <stdio.h>
#include <stdlib.h>

int result[9] = { 0, }; //����� ������ ����Ʈ

void sort(int a[], int n) //������������ ����
{
	int i, j, tmp, tmp_index;

	for (i = 1; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (a[i] < a[j]) // �տ� �ִ� ���� �� �۴ٸ�
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp; //������ swap

				tmp_index = result[i];
				result[i] = result[j];
				result[j] = tmp_index;
			}
		}
	}
}

int graph[9][9] = {
	{0,0,0,0,0,0,0,0,0}, //0�� ���
	{0,0,0,1,0,0,0,0,0}, //1�� ���
	{0,1,0,0,0,1,0,0,0}, //2�� ���
	{0,0,0,0,1,0,0,1,0}, //3�� ���
	{0,0,0,0,0,0,0,0,0}, //4�� ���
	{0,0,0,0,1,0,1,0,0}, //5�� ���
	{0,0,0,0,0,0,0,0,1}, //6�� ���
	{0,0,0,0,0,0,0,0,0}, //7�� ���
	{0,0,0,0,0,0,0,1,0}  //8�� ���
};

int visited[9] = { 0 , }; //�湮��� 0
int pre[9] = { 0, }; //���۽� pre
int post[9] = { 0, }; //����� post
int count = 1; // pre, post�� ������ ��
int idx = 1; //result�� ������ �ε���

void dfs(int v)
{
	pre[v] = count++;
	visited[v] = 1; //��� �湮

	for (int i = 1; i < 9; i++)
	{
		if (graph[v][i] == 1 && visited[i] == 0) //�湮�� �� �ְ� �湮�� ���� ���ٸ�
		{
			dfs(i); //dfs����
			post[i] = count++;
		}
	}
}

void topologicalSort()
{
	for (int i = 1; i < 9; i++)
	{
		if (visited[i] == 0) //�湮�� ���� ������
		{
			dfs(i); //dfs����
			if (post[i] == 0)
			{
				post[i] = count++;
			}
		}
	}

	for (int i = 1; i < 9; i++)
	{
		printf("pre: %d, post: %d\n", pre[i], post[i]);
		result[i] = i; //index�� ������� �ֱ�
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