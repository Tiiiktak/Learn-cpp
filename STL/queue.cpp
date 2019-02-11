/*
	队列queue
	只允许在一端进行插入工作(队尾), 而在另一端进行删除操作(队头)的线性表(先进先出) 
*/
#include <iostream>
#include <queue>
using namespace std; 

int main(int argc, char const *argv[])
{
/*定义*/	
	queue<int> q1; 
	queue<double> q2; 
	
/*基本操作*/
	q1.push(6); //将6弹入队列
	q1.pop(6); //将6弹出队列(不会返回弹出元素的值)
	q.front(); //返回队头元素
	q.back(); //返回队尾元素
	q.empty(); //队列为空，返回true
	q.size(); //队列中元素个数

	return 0;
}