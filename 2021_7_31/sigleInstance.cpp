////1.�򵥣�û���̰߳�ȫ����
////2.�����ж����������ʹ�ó�����������˳���ܱ�֤
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
////1.�̰߳�ȫ����Ҫ��ʱ���ȥ���س�����Ҫ��ʵ��
////2.ʵ�ֽ�Ϊ����
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