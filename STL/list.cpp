/*list基础
	线性双向链表结构, 可快速在任意位置增删元素
	不支持随机存取，不占用连续的内存空间
	相较于vector占用更多空间
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std; 

void show(int num){		//显示整数的函数
	cout << num << " "; 
}

bool single_digit(const int& value){
	reutrn (value<10); 
}

bool is_odd(const int& value){
	return (value%2)==1; 
}

int main(int argc, char const *argv[])
{
/*定义,初始化及插入(insert)*/
	//1
	int test[5] = {1, 2, 3, 4, 5}; 
	list<int> mylist1(test, test+5); //{1, 2, 3, 4, 5}
	list<int> mylist2(2, 100); //{100, 100}
	//2
	list<int> mylist3; 
	mylist3.push_back (1); //{1}
	mylist3.push_front (0); //{0, 1} 
	//3
	list<int> mylist4; 
	mylist4.assign(mylist3.begin(), mylist3.end()); //{0, 1} 
	list<int> mylist5; 
	mylist5.assign(test, test+5); 
	//insert
	list<int>::iterator t; //迭代器 
	t = mylist1.begin(); //t指向'1'
	t++; //t指向'2'
	mylist1.insert(t, 6); //{1, 6, 2, 3, 4, 5} t指向'2' 
	t--; //t指向'6'
	mylist1.insert(t, 2, 7); //{1, 7, 7, 6, 2, 3, 4, 5} t指向'6' 
	t--; //t指向'7' 
	vector<int> myvector(2, 8); 
	mylist1.insert(t, myvector.begin(), myvector.end()); //将vector的值插入list
		//{1, 7, 8, 8, 7, 6, 2, 3, 4, 5} t指向'7'


/*输出*/
	//使用迭代器
	list<int>::iterator it; 
	it = mylist1.begin(); 
	for (; it != mylist1.end(); it++)
		cout << *it << " "; 
	//使用for_each
	for_each(mylist1.begin(), mylist1.end(), show); 
		//for_each函数将指定的函数应用于容器中每个元素
	
/*成员函数*/
	//iterator
	iterator begin(); //不能用listname.begin()+n来指向元素
	iterator end(); 
	reverse_iterator rbegin(); //指向第一个元素的逆向迭代器
	reverse_iterator rend(); //指向最后一个元素的逆向迭代器
	//capacity(获取容器大小信息)
	bool empty() const; //list为空时返回true
	size_type size() const; 
	size_type max_size() const; //list最大能容纳的元素个数
	//
	reference front(); //返回第一个元素的引用
	reference back(); //返回最后一个元素的引用
	//
  	void push_front(const value_type& val); //在list头部添加元素
  	void pop_front(); //删除头元素
  	void push_back(const value_type& val); //在尾部添加元素
  	void pop_back(); //删除尾部元素
  	//erase(可不接收返回值)
  	iterator erase (iterator position);  //删除迭代器position指向的值
	iterator erase (iterator first, iterator last);  //删除[first, last)中的值
	//swap
	void swap(list& x); 
	//resize
	void resize (size_type n, value_type val = value_type()); //重新指定长度为n，若不够补为value
	//clear
	void clear (); //清除所有元素
	//splice(将一个list中的值移植到另一个list中)
	void splice (iterator position, list& x); //将x中所有元素移到当前list中，从当前position开始，之后x变为空
	void splice (iterator position, list& x, iterator i); //将x中i指向的元素移到position指向的位置，之后i为invalid
	void splice (iterator position, list& x, iterator first, iterator last); //将x中[first,last)的元素移到list中，从当前position开始
	//remove(删除特定值)
	void remove(const value_type& val); //从list删除所有值为val的元素
	//remove_if(按条件删除)
	void remove_if(Predicate pred); //pred可以是函数，也可是class
	list<int> mylist6 (test, test+5); //{15, 36, 7, 17, 20, 39, 4, 1} 
	mylist.remove_if (single_digit); //{15, 36, 17, 20} 
	mylist1.remove_if (is_odd); //{36, 20} 
	//unique(删除重复值)
	void unique(); //只能删除相邻的两个元素，保留第一个值，故只对已排序list有用
	void unique (BinaryPredicate binary_pred);  //binary_pred可以是函数，也可以是class，需要有两个参数
	//merge(合并有序的list)
	void merge(list &x); //将x中元素按默认顺序移入当前列表中，之后x为空		
	//sort
	void sort(); //默认升序
	void sort(compare comp); 
	//reverse(逆序)
	void reverse(); //将list中元素逆序
/*get_allocator*/
	//返回一个跟该list有关的分配器对象
	allocator_type get_allocator() const;  //可以用来给数组动态分配空间


	return 0;
}
