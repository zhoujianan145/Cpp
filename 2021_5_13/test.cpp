//////#include<iostream>
//////
//////using namespace std;
//////
//////class car 
//////{
//////public:
//////	virtual void Drive() = 0;
//////};
//////class Benz :public car
//////{
//////public:
//////	virtual void Drive()
//////	{
//////		cout << "舒适"<< endl;
//////	}
//////	
//////};
//////class Bmw :public car
//////{
//////public:
//////	virtual void Drive()
//////	{
//////		cout << "跑得快"<< endl;
//////	}
//////
//////};
//////int main()
//////{
//////	//可以定义指针，因为没有涉及到car对象
//////	/*car* a;
//////	car* b = new Benz;*/
//////	//car* a=new car是不行的,因为new想调用car的构造函数，但是car根本不能实例化出对象，构造函数初始化也不行
//////
//////
//////	//开始还写car& d，但是引用必须要指向一个对象，所以car对象没有，引用一个子类对象。
//////	//car& d = bz;
//////	
//////	Benz bz;
//////	Bmw bw;
//////	car *a;
//////	a = &bz;
//////	a->Drive();
//////	a = &bw;
//////	a->Drive();
//////
//////	return 0;
//////}
////#include<iostream>
////using namespace std;
////class Base
////{
////public:
////	virtual void Func1()
////	{
////		cout << "Func1()" << endl;
////	}
////	virtual void Func2()
////	{
////		cout << "Func2()" << endl;
////	}
////	virtual void Func3()
////	{
////		cout << "Func3()" << endl;
////	}
////    void Func4()
////	{
////		cout << "Func4()" << endl;
////	}
////private:
////	int _b = 1;
////	
////};
////int main()
////{
////	/*cout << sizeof(Base) << endl;*/
////	/*Base b;*/
////	//肯定不能直接把b对象转成int*
////    //cout << (int*)b << endl;
////	//先取地址，把它转成4个字节，在解引用
////
////
////	/*char* str = "sacs";*/
////	//a虽然是首元素地址，但这样打印会将a当成字符串，
////	//cout << str << endl;
////	char* str = "1234";
////	printf("代码段:%p\n", str);
////	
////	static int d = 0;
////	printf("数据段:%p\n",&d);
////
////	int* a = new int;
////	printf("堆:%p\n", a);
////	
////	printf("栈:%p\n", &a);
////
////	//肯定不能直接把b对象转成int*
////	//cout << (int*)b << endl;
////	//先取地址，把它转成4个字节，在解引用
////	Base b;
////	printf("虚函数表指针:我是谁,我在哪:%p", *((int*)&b));
////
////	return 0;
////}
//
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价" << endl;
//	}
//	virtual void func1()
//	{
//		
//	}
//};
//class Student:public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "半价" << endl;
//	}
//	void func1()
//	{
//
//	}
//};
//
//
//int main()
//{
//	Person p1;
//	Student s1;
//
//
//	p1.BuyTicket();
//
//	Person &p = s1;
//	p.BuyTicket();
//	p.func1();
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" ;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" ;
//	}
//
//private:
//	int _b = 1;
//	
//};
//
//class Derive:public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" ;
//	}
//
//	virtual void Func3()
//	{
//		cout << "Derive::Func3()" ;
//	}
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" ;
//	}
//private:
//	int _d = 2;
//
//};


#include<iostream>
using namespace std;
////指针数组
//int(*a)[];
////void型函数，指针数组
//void(*(*p)[])()，这样写太难懂

//将void(*)()类型的函数指针typedef成VFUNC
typedef void(*VFUNC)();


//函数指针数组，可以这样用
//void PrintVFT(VFUNC(*a)[])

//但最好这样用,函数指针类型的数组
//void PrintfVFT(VFUNC vftable[])
//
////数组太大，传递指针
void PrintfVFT(VFUNC* vftable)
{
	printf("虚函数表指针:%p\n",vftable);

	//函数指针数组，以nulptr结尾
	for (int i = 0; vftable[i] != nullptr; i++)
	{
		printf("vftable[%d]:%p --->", i, vftable[i]);

		//函数地址()
		//Func1(),Func2().....
		vftable[i]();
		//或者先(*vftable[i])()也可以，不过不好看
		cout << endl;
	}
}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	cout << "我是Base" << endl;
//	PrintfVFT((VFUNC*)(*((int*)&b)));
//
//	//   (VFUNC*)(*(int*(&d)))
//	//取出头上指针的地址，把它转成强转成VFUNC*
//	cout << "我是Derive" << endl;
//	PrintfVFT((VFUNC*)(*((int*)&d)));
//
//
//
//
//	return 0;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()";
	}
	virtual void Func2()
	{
		cout << "Base::Func2()";
	}

private:
	int _b = 1;

};

class Base1
{
public:
	virtual void Func1()
	{
		cout << "Base1::Func1()";
	}
	virtual void Func2()
	{
		cout << "Base1::Func2()";
	}

private:
	int _b1 = 2;
};
class Derive :public Base,public Base1
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()";
	}

	virtual void Func3()
	{
		cout << "Derive::Func3()";
	}

private:
	int _d = 2;

};

int main()
{
	Derive d;

	//Base* b=&d;

	//Base1* b1=&d;

	//b->Func1();
	//b1->Func1();

	PrintfVFT((VFUNC*)(*((int*)&d)));

	cout << endl;
	//虚函数表指针按声明顺序，所以跨过继承的Base结构体，就到了Base1的虚函数表指针
	
	//先转成char*,一次加一个字节，跨过头上的结构体，找到Base1的虚函数表指针。然后在执行之前的那个获取到指针那四个字节的操作
	PrintfVFT((VFUNC*)(*(int*)((char*)&d+sizeof(Base))));
	
	printf("Derive::Func1 : %p\n", &Base::Func2);
	return 0;
}