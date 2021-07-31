#include<iostream>
using namespace std;

namespace zjn
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* _ptr)
			:ptr(_ptr)
		{}
		~unique_ptr()
		{
			if (ptr)
			{
				delete ptr;
			}
		}
		T& operator*()
		{
			return *ptr;
		}
		T* operator->()
		{
			return ptr;
		}
	private:
		unique_ptr(const unique<T>&) = delete;
		unique_ptr<T>& operator=(const unique<T>&) = delete;

		T* ptr;
	};
}

int main()
{
	return 0;
}