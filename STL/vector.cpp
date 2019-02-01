/*vector基础入门*/

#include <vector>
#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
/*初始化及输出*/
	vector<int> a; //声明int型向量a 
	cout << "a.size()=" << a.size() << endl; //0
	
	vector<int> b(5); //声明初始大小为5的向量b
	cout << "b.size()=" << b.size() << endl; //5
	
	vector<int> c(5, 1); //声明初始大小为5,初始值都为1的向量
	cout << "c.size()=" << c.size() << endl; //5
	vector<int>::iterator t = c.begin(); 
	while(t!=c.end())
	{
		cout << *t << " "; 
		t++; 
	}
	cout << endl; //1 1 1 1 1

	vector<int> d(b); //用b初始化d, 同vector<int> d=b; 
	cout << "d.size()=" << d.size() << endl; //5
	
	vector<int> e(c.begin(), c.begin()+3); //用c前3项初始化e
	cout << "e.size()=" << e.size() << endl; //3
	for (int i = 0; i < e.size(); ++i)
	{
		cout << e.at(i) << " "; 
	}
	cout << endl; //1 1 1

	int n[] = {1, 2, 3}; 
	vector<int> f(n, n+3); //用数组初始化


/*插入*/
	c.insert(c.begin(), 0); //在首位前面插入0
		//0 1 1 1 1 1
	c.insert(c.begin(), 2, 3); //在首位前面插入2个3
		//3 3 0 1 1 1 1 1
	c.insert(c.end(), 6); //在末尾插入6
		//3 3 0 1 1 1 1 1 6
	c.push_back(3); //在末尾插入3
		//3 3 0 1 1 1 1 1 6 3

/*删除*/
	c.erase(c.begin()); //删除首位
		//3 0 1 1 1 1 1 6
	c.erase(c.begin(), c.end()-1); 
		//6
	

/*交换及比较*/
	a.swap(c); //同swap(a, c); 
	//适用==, !=, >, <, >=, <= 


/*二维向量*/
	ector< vector<int> > h (2, vector<int>(3, 1)); //2*3
	for (int i = 0; i < h.size(); ++i)
	{
		for (int j = 0; j < h[i].size(); ++j)
		{
			cout << h[i][j]; 
		}
		cout << endl; 
	}
		//1 1 1
		//1 1 1
	

/*成员函数*/
	c.empty(); //是否为空
	c.back(); //返回最后一个数据
	c.capacity(); //容器当前能容纳元素个数 
	c.clear(); //清除容器中所有元素
	c.end(); //指向最后一个元素的下一位，非当前最后一个元素
	c.back(); //返回最后一个数据，不检查是否存在
	c.max_size(); //返回最大容积
	c.popback(); //删除最后一个元素
	c.rbegin(); //反向迭代器，返回倒数第一个
	c.rend(); //反向迭代器，返回倒数最后一个
	c.resize(n, value); //重新指定长度为n，若不够补为value
	c.reserve(); //要求 容器 重新分配内存
	operator[]; //返回容器中指定位置的一个引用。
	

/*析构函数*/
	c.~vector(); 

	return 0;
}