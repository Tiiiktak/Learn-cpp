/*map基础
	关联式容器
	提供一对一的数据处理能力(第一个为关键字key，每个关键字只能在map中出现一次，第二个可能称为关键字的值)
	key和value可以是任意数据类型，自动建立key-value的对应
	map内部自建一颗红黑树，能对数据自动排序
 	对于迭代器，可修改实值，不能修改key
 */
#include <iostream>
#include <map>
#include <string>
using namespace std; 

int main(int argc, char const *argv[])
{
/*构造*/
 	map<int, string> mapStudent; 
/*插入数据*/
 	//insert插入pair数据
 		//可判断是否插入数据成功
 	pair<map<int, string>::iterator, bool> insert_pair; 
	insert_pair = mapStudent.insert(pair<int, string>(1, "first_student")); 
 	if (insert_pair.second == true)
 		cout << "insert successfully" << endl; 
 	else
 		cout << "insert failure" << endl; 
 	cout << "mapStudent[1] : " << mapStudent[1] << endl; //first_student
 	//insert插入value_type数据
 		//不可判断是否插入数据成功
 	mapStudent.insert(map<int, string>::value_type(2, "second_student")); 
 	//数组方式
 		//可以覆盖以前该关键字对应的值
 	mapStudent[1] = "new_first_student"; 
 	cout << "mapStudent[1] : " << mapStudent[1] << endl; //new_first_student
 	mapStudent[3] = "third_student"; 
/*map的大小*/
 	cout << "size of mapStudent: " << mapStudent.size() << endl; 
/*遍历*/
 	//迭代器
 	map<int, string>::iterator t; 
 	t = mapStudent.begin(); 
 	cout << "use iterator" << endl; 
 	for (; t != mapStudent.end(); t++)
 		cout << t->first << " " << t->second << endl; 
 	//数组
 	cout << "use array" << endl; 
 	for (int i = 1; i <= mapStudent.size(); ++i)	//注意从1开始
 		cout << "mapStudent["<<i<<"] " << mapStudent[i] << endl; 
/*查找并获取元素*/
 	//count(无法定位，返回0/1)
 	if (mapStudent.count(2))
 		cout << "'2' is in the map" << endl; 
 	//find(返回数据所在位置迭代器，没有则返回end()函数返回的迭代器)
 	if (mapStudent.find(1) != mapStudent.end()){
	 	cout << "'1' is in the map  " << mapStudent.find(1)->second << endl; 
 	}
 	//使用equal_range函数
/*删除元素*/
 	//使用迭代器删除
 	map<int, string>::iterator iter; 
 	iter = mapStudent.find(1); 
 	mapStudent.erase(iter); 
 	//使用关键字删除(返回1/0)
 	if (mapStudent.erase(1))
 		cout << "erase successfully" << endl; 
 	else
 		cout << "erase failed" << endl; 
 	//删除一个范围(前闭后开)
 	mapStudent.erase(mapStudent.begin(), mapStudent.end()); //同mapStudent.clear(); 
/*swap*/
 	//map中swap是两个容器的所有元素交换
/*基本函数*/
 	empty() //如果map为空则返回true
 	lower_bound() //返回键值>=给定元素的第一个位置
 	upper_bound() //返回键值>给定元素的第一个位置
 	value_comp() //返回比较元素value的函数
 	return 0;
} 