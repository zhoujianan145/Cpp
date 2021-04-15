
#include"vetcor.hpp"

int main()
{
	zjn::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.resize(10,6);
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	auto it=std::find(v.begin(), v.end(),3);
	//增容的时候重新开空间，虽然在函数内部解决了失效，但是在外面他有没有改变（形参传值，不影响实参），那么直接传引用就好了，但是库函数insert没有按照引用实现。
	//给insert带一个返回值，返回改变后的pos，在外面接收它
	it=v.insert(it, 6);
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	zjn::vector<int> v1(v);
	
	return 0;

}