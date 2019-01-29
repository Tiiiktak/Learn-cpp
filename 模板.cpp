/*定义模板后,编译器在需要时根据模板自动生成所需代码*/
#include <iostream>
#include <iostream>
using namespace std; 

/*函数模板
template <typename type> //typename可用class替代
ret-type func-name(形参表)
{
	//函数主体	
}
*/
//函数模板也可重载

template <typename T>	//定义了一个最大值函数模板
T Max(T& a, T& b)
{
	return a < b ? b:a; 
}

int main(int argc, char const *argv[])
{
	int i = 2; 
	int j = 5; 
	cout << "Max(i, j) = " << Max(i, j) << endl; 

	double f1 = 2.33; 
	double f2 = 3.45; 
	cout << "Max(f1, f2) = " << Max(f1, f2) << endl; 
	//也可指明如何实例化模板函数, 如
	//cout << cout << "Max(f1, f2) = " << Max<double>(f1, f2) << endl; 
	
	string s1 = "hello"; 
	string s2 = "world"; 
	cout << "Max(s1, s2) = " << Max(s1, s2) << endl; 
	
	/*运行结果
		Max(i, j) = 5
		Max(f1, f2) = 3.45
		Max(s1, s2) = world
	*/

	return 0;
}


/*类模板
template <class type> 
class class-name {
	//类
}
*/

