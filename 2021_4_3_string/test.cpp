#include"string.h"

using namespace zjn;
int main()
{
	zjn::string s = "12345";
	zjn::string s1(s);
	string s2 = "zj";
	s1 = s2;
	
	s1.push_back('x');
	s1.append("hello");
	s1 += "bi";
	s1 += "t";
	s1 += s;
	s.insert(0,"");
	s1.erase(4);
	
	int n=s1.find('x');
	bool a= s1 > s2;
	bool b= s1 == s2;

	string s4;
	std::cin >> s4 ;
	s4.resize(5);
	std::cout << s4 << std::endl;
	std::cout << (s1 > s2) << std::endl;
	std::cout << (s1 <= s2) << std::endl;
	std::cout << s1.size() << std::endl;
	std::cout << s2.capacity()<< std::endl;
	return 0;
}