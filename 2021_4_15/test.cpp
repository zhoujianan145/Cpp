
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
	//���ݵ�ʱ�����¿��ռ䣬��Ȼ�ں����ڲ������ʧЧ����������������û�иı䣨�βδ�ֵ����Ӱ��ʵ�Σ�����ôֱ�Ӵ����þͺ��ˣ����ǿ⺯��insertû�а�������ʵ�֡�
	//��insert��һ������ֵ�����ظı���pos�������������
	it=v.insert(it, 6);
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	zjn::vector<int> v1(v);
	
	return 0;

}