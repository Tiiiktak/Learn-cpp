/*
	stack(容器适配器)
	元素的插入(入栈)和删除(出栈)都只能在容器尾部进行
 */
#include <iostream>
#include <stack>
using namespace std; 

int main(int argc, char const *argv[])
{
	stack<int> st1; 
	stack<int, std::vector<int> > st2; //使用vector容纳元素
	st1.push(x); //入栈
	st1.top(); //返回stack中的栈顶元素(reference类型)
	st1.pop(); //删除栈顶元素，无返回值
	str1.size(); 
	str1.empty(); 
	return 0;
}
