/*
C/C++编译的程序占用的内存分为以下部分：
	栈(stack): 编译器自动分配释放，函数内声明的变量存放于此
	堆(heap): 一般由程序员分配释放(若未释放，程序结束可能被OS回收)
	全局(静态)区(static):  全局变量与静态变量存放在一块(程序结束系统释放)
	文字常量区: 存放常量字符串(程序结束系统释放)
	程序代码区: 存放函数体的二进制代码
*/
#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
/*new & delete*/
	//使用new运算符分配空间地址，如果分配失败，会返回NULL，所以要判断是否为NULL
	double* pvalue = NULL; //初始化为NULL的指针
	try {
		if ( !(pvalue = new double))	//为变量请求内存
			throw("Error: out of memory.");
	}catch (char *msg){
		cerr << msg << endl; 
		exit(1); 
	}

	*pvalue = 233; 
	cout << "value of pvalue : " << *pvalue << endl; 

	delete pvalue; //使用delete运算符释放pvalue占用的内存


/*数组的动态内存分配*/
	//一维数组
	char* pvalue = new char[5]; 

	delete [] pvalue;  
	delete pvalue; 
		//以上两者均可(原因: 分配简单数据类型(int/char/long/int*/struct..)内存时，
		//					内存大小已确定，系统可记忆并进行管理)

	//二维数组
	char **array; //3*4
	array = new int *[3]; 
	for (int i = 0; i < 3; ++i)
		array[i] = new int [4]; 

	for (int i=0; i<3; i++)
		delete [] array[i]; 
	delete [] array; 


/*对象的动态内存分配*/
	class TEST
	{
	public:
		TEST(){
			cout << "调用构造函数" << endl; 
		}
		~TEST(){
			cout << "调用析构函数" << endl; 
		}	
	};
	TEST* array = new TEST[5]; 

	delete [] TEST; 

	return 0;
}