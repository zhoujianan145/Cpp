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
//////		cout << "����"<< endl;
//////	}
//////	
//////};
//////class Bmw :public car
//////{
//////public:
//////	virtual void Drive()
//////	{
//////		cout << "�ܵÿ�"<< endl;
//////	}
//////
//////};
//////int main()
//////{
//////	//���Զ���ָ�룬��Ϊû���漰��car����
//////	/*car* a;
//////	car* b = new Benz;*/
//////	//car* a=new car�ǲ��е�,��Ϊnew�����car�Ĺ��캯��������car��������ʵ���������󣬹��캯����ʼ��Ҳ����
//////
//////
//////	//��ʼ��дcar& d���������ñ���Ҫָ��һ����������car����û�У�����һ���������
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
////	//�϶�����ֱ�Ӱ�b����ת��int*
////    //cout << (int*)b << endl;
////	//��ȡ��ַ������ת��4���ֽڣ��ڽ�����
////
////
////	/*char* str = "sacs";*/
////	//a��Ȼ����Ԫ�ص�ַ����������ӡ�Ὣa�����ַ�����
////	//cout << str << endl;
////	char* str = "1234";
////	printf("�����:%p\n", str);
////	
////	static int d = 0;
////	printf("���ݶ�:%p\n",&d);
////
////	int* a = new int;
////	printf("��:%p\n", a);
////	
////	printf("ջ:%p\n", &a);
////
////	//�϶�����ֱ�Ӱ�b����ת��int*
////	//cout << (int*)b << endl;
////	//��ȡ��ַ������ת��4���ֽڣ��ڽ�����
////	Base b;
////	printf("�麯����ָ��:����˭,������:%p", *((int*)&b));
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
//		cout << "ȫ��" << endl;
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
//		cout << "���" << endl;
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
////ָ������
//int(*a)[];
////void�ͺ�����ָ������
//void(*(*p)[])()������д̫�Ѷ�

//��void(*)()���͵ĺ���ָ��typedef��VFUNC
typedef void(*VFUNC)();


//����ָ�����飬����������
//void PrintVFT(VFUNC(*a)[])

//�����������,����ָ�����͵�����
//void PrintfVFT(VFUNC vftable[])
//
////����̫�󣬴���ָ��
void PrintfVFT(VFUNC* vftable)
{
	printf("�麯����ָ��:%p\n",vftable);

	//����ָ�����飬��nulptr��β
	for (int i = 0; vftable[i] != nullptr; i++)
	{
		printf("vftable[%d]:%p --->", i, vftable[i]);

		//������ַ()
		//Func1(),Func2().....
		vftable[i]();
		//������(*vftable[i])()Ҳ���ԣ��������ÿ�
		cout << endl;
	}
}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	cout << "����Base" << endl;
//	PrintfVFT((VFUNC*)(*((int*)&b)));
//
//	//   (VFUNC*)(*(int*(&d)))
//	//ȡ��ͷ��ָ��ĵ�ַ������ת��ǿת��VFUNC*
//	cout << "����Derive" << endl;
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
	//�麯����ָ�밴����˳�����Կ���̳е�Base�ṹ�壬�͵���Base1���麯����ָ��
	
	//��ת��char*,һ�μ�һ���ֽڣ����ͷ�ϵĽṹ�壬�ҵ�Base1���麯����ָ�롣Ȼ����ִ��֮ǰ���Ǹ���ȡ��ָ�����ĸ��ֽڵĲ���
	PrintfVFT((VFUNC*)(*(int*)((char*)&d+sizeof(Base))));
	
	printf("Derive::Func1 : %p\n", &Base::Func2);
	return 0;
}