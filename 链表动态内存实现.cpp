/*链表用动态内存实现(无函数版)*/
#include <iostream>
using namespace std; 

typedef struct node
{
	int num; //节点编号
	int data; //节点数据
	struct node *next; 
}NODE; 

int main(int argc, char const *argv[])
{	
	char p; 
	int nowdata;

	//节点初始化
	NODE *head, *lastnode, *nownode; 
	head = lastnode = NULL; 
	nownode = new node; 
	nownode->next = NULL; 
	nownode->num = 1; 

	//头节点
	cout << "please enter the data of no.1 node: "; 
	cin >> nowdata; 
	nownode->data = nowdata; 
	head = nownode;

	//节点输入
	do{
		lastnode = nownode; //把当前节点赋为上一节点
		nownode = new node; //为新节点分配空间
		nownode->next = NULL; 
		lastnode->next = nownode; 
		nownode->num = lastnode->num+1; 

		cout << "please enter the data of no."<<nownode->num<<" node: " << endl; 
		cin >> nowdata; //赋值当前节点
		nownode->data = nowdata; 

		cout << "add more node?(y/n) "; 
		cin >> p; 
	}while(p=='y');
	
	//节点输出
	nownode = head; 
	lastnode = NULL; 
	while (1)
	{
		cout << "nodenum:" << nownode->num << " "; 
		cout << "nodedata: " << nownode->data <<endl; 
		if (nownode->next == NULL)	//判断当前节点是否为尾节点
			break; 
		nownode = nownode->next; 
	}

	//释放内存
	lastnode = head; 
	nownode = lastnode; 
	while (lastnode->next != NULL)
	{
		lastnode = nownode; 
		nownode = lastnode->next; 
		delete lastnode;		
	}
	return 0;
}