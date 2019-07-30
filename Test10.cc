#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
	public:
		//构造时获取资源
		SmartPtr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		//析构时释放资源
		~SmartPtr()
		{
			if(_ptr)
				delete _ptr;
		}
		//像指针一样
		//重载operator*与operator->
		T& operatro*()
		{
			return *_ptr;
		}
		//当该指针指向结构体时
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
};

struct Date
{
	int _year;
	int _month;
	int _date;
}

int main()
{
	SmartPtr<Date> ptr(new Date);
	ptr->_year = 2019;
	ptr->_month = 1;
	ptr->_date = 1;
	return 0;
}
