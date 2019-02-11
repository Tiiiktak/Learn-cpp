/*
	BFS(宽度优先搜索)
	DFS(深度优先搜索)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

//BFS
//通过队列存储实现
vector<int> E[110]; //存图
bool vis[110]; //记录已经走过的点

void bfs(int root, int n)	//n个点的图，从root开始搜索
{
	queue<int> que; 
	memset(vis, 0, 110); //初始化
	vis[root] = 1; 
	que.push(root); //root弹入队列

	while (!que.empty())	//当队列中还有元素
	{
		int u = que.front(); //取队头元素
		que.pop(); //删队头

		int len = que.size(); 
		for (int i = 0; i < len; ++i) //遍历u点的邻接点
		{
			if (vis[E[u][i]]==0) //如点未访问过
			{
				vis[E[u][i]] = 1; 
				que.push(E[u][i]); //弹入队列
			}
		}
	}
}

//DFS
//通过递归实现
vector<int> E[110]; //存图
bool vis[110]; 
void dfs(int start) //从start点开始搜索
{
	vis[start] = 1; //start点已访问
	int len = E[start].size(); 
	for (int i = 0; i < len; ++i) //遍历start点的邻接点
	{
		if (vis[E[start][i]]==0)
			dfs(E[start][i]); //E[start][i]作为start点再次调用函数进行搜索
	}
}
