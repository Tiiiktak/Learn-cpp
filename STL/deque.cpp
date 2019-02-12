/*
	deque(双端队列)(双端能进能出)
	支持高效插入和删除容器的头(尾)部元素
 */
#include <iostream>
#include <deque>
using namespace std; 

int main(int argc, char const *argv[])
{
/*定义(构造)*/
	deque<int> deq1; //新建一个空deque
	deque<int> deq2(5); //新建一个元素个数为5的deque(0, 0, 0, 0, 0)
	deque<int> deq3(5, 6); //新建一个元素个数为5,全为6的deque(6, 6, 6, 6, 6) 
	deque<int> deq4(deq3); //拷贝构造(6, 6, 6, 6, 6)
		//或deque deq4; 
		//deq4.assign(deq3.begin(), deq3.end()); 
	deque<int> deq5 = deq2; //赋值拷贝(0, 0, 0, 0, 0)
	deque<int> deq6(deq3.begin(), deq3.end()-2); //指定区间创建(6, 6, 6)
	deque<int> deq7({1, 2, 3, 4}); //指定初始化列表创建(1, 2, 3, 4)
	deque<int> deq8({2, 3, 4, 5}); //指定初始化列表创建(2, 3, 4, 5) 

/*插入*/
	deq1.push_back(6); //从尾部插入(6) 
	deq1.push_front(8); //从头部插入(8, 6)
	deq1.insert(deq1.begin(), 2); //从指定位置前插入(2, 8, 6)
	deq1.emplace(deq1.begin()+1, 100); //从指定位置前插入(C++11新增)(2, 100, 8, 6)
	deq1.emplace_front(111); //从头部插入(111, 2, 100, 8, 6)
	deq1.emplace_back(112); //从尾部插入(111, 2, 100, 8, 6, 112)

/*删除,弹出*/
	deq1.pop_back(); //弹出尾部元素(111, 2, 100, 8, 6)
	deq1.pop_front(); //弹出头部元素(2, 100, 8, 6)
	deq1.erase(deq1.begin()+1); //删除指定位置元素(2, 8, 6)
	deq1.clear(); //清空

/*函数及操作*/
	deq1.swap(deq3); //交换
	deq1.front(); 
	deq1.back(); 
	deq1.at(x); 
	deq1[x]; 
	deq1.size(); 
	deq1.resize(); //多退少补
	deq1.max_size(); 
	deq1.empty(); 
	deq1.shrink_to_fit(); //清空内存(C++11新增) 
    cout << *deq1.begin() << endl; //指向第一个元素的迭代器   
    cout << *deq1.end() << endl; //指向最后一个元素的下一个位置的迭代器   
    cout << *deq1.rbegin() << endl; //反向deque的第一个元素的迭代器
    cout << *deq1.rend() << endl; //反向deque的第一个元素的上一个位置迭代器 
    cout << *deq1.cbegin() << endl; //指向第一个元素的迭代器
    cout << *deq1.cend() << endl; //指向最后一个元素的下一个位置的迭代器  
    cout << *deq1.crbegin() << endl; //反向deque的第一个元素的迭代器
    cout << *deq1.crend() << endl; //反向deque的第一个元素的上一个位置迭代器

	return 0;
}