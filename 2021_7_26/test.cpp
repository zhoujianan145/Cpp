#include<iostream>
#include<mutex>
using namespace std;

////懒汉
//class signalInstance
//{
//public:
//	static signalInstance* GetInstance()
//	{
//		return  &_ist;
//	}
//private:
//	signalInstance()
//	{};
//	signalInstance(const signalInstance&) = delete;
//	signalInstance& operator=(const signalInstance&) = delete;
//
//	static signalInstance _ist;
//};
//signalInstance signalInstance::_ist;

//饿汉
class signalInstance
{
public:
	static signalInstance* GetInstance()
	{
		////这样写下一个线程来还需要加锁，才能判断
		//_mtx.lock();
		//if (_sit == nullptr)
		//{
		//	_sit = new signalInstance;
		//}
		//_mtx.unlock();
		if (_sit == nullptr)
		{
			_mtx.lock();
			if (_sit == nullptr)
			{
				_sit = new signalInstance;
			}
			_mtx.unlock();
		}
		return _sit;
	}
	class Gabhandle
	{
	public:
		~Gabhandle()
		{
			if (signalInstance::_sit)
			{
				delete signalInstance::_sit;
			}
		}
	};
	static Gabhandle _gab;

private:
	signalInstance()
	{}
	signalInstance(const signalInstance&)=delete;
	signalInstance operator=(const signalInstance&) = delete;

	static signalInstance* _sit;
	static mutex _mtx;
};
signalInstance* signalInstance::_sit = nullptr;
mutex signalInstance::_mtx;


int main()
{
	signalInstance::GetInstance();

	
	return 0;
}