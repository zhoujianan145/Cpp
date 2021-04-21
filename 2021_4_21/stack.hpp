#pragma once
//  ≈‰∆˜ƒ£ Ω
namespace zjn{

	template <class T, class Container = deque<T> >
	class stack{
	public:
		void push_back(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}

		const T& top()const
		{
			return _con.back();
		}
		bool empty()const
		{
			return _con.empty();
		}
		size_t size()const
		{
			return _con.size();
		}


	private:

		Container _con;
	};
}
