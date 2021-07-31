////1.简单，没有线程安全问题
////2.假如有多个单例，会使得程序启动慢。顺序不能保证
////class sigleInstance
////{
////public:
////	static sigleInstance* GetInstance()
////	{
////		return &_sit;
////	}
////private:
////	sigleInstance()
////	{}
////	sigleInstance(const sigleInstance&) = delete;
////	sigleInstance& operator=(const sigleInstance&) = delete;
////	static sigleInstance _sit;
////};
////sigleInstance sigleInstance::_sit;
//#include<mutex>
//using namespace std;
////1.线程安全，需要的时候才去加载出所需要的实例
////2.实现较为复杂
//class sigleInstance
//{
//public:
//	static sigleInstance* GetInstance()
//	{
//		if (_sit == nullptr)
//		{
//			unique_lock<mutex> lock(mtx);
//			if (_sit == nullptr)
//			{
//				return _sit;
//			}
//		}
//		return _sit;
//	}
//private:
//	sigleInstance()
//	{}
//	sigleInstance(const sigleInstance&) = delete;
//	sigleInstance& operator=(const sigleInstance&) = delete;
//	
//	static sigleInstance* _sit;
//	static mutex mtx;
//};
//sigleInstance* sigleInstance::_sit = nullptr;
//mutex sigleInstance::mtx;