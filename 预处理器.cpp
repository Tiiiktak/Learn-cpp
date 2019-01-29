预处理器是指令，均以#开头，不以分号结尾
#define 宏
	#define PI 3.14
	#define MAX(a, b) (a > b ? a:b)
#和##运算符
	#define TEST1( x ) #x
		cout<< TEST1( hello world ) <<endl; 
		会被转换成cout<< "hello world" <<endl; 
	#define TEST2(x, y) x ## y
		int ab = 10; 
		cout<< TEST2(a, b) <<endl; 
		会被转换成cout<< ab <<endl; 
预定义宏
	__LINE__ 当前行号
	__FILE__ 当前文件名
	__DATE__ 把源文件转换为目标代码的日期(m/d/y)
	__TIME__ 程序被编译的时间(h:m:s)