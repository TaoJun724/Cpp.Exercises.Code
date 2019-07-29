#include<iostream>
using namespace std;

class Singleton
{
	public:
		static Singleton* GetInstance()
		{
			return &_sInstance;
		}

		void Print()
		{
			cout << "饿汉模式" << endl;
		}
	private:
		Singleton(){}

		Singleton(Singleton const& sl);
    
		Singleton& operator=(Singleton const& sl) = delete;
		static Singleton _sInstance;
};

Singleton Singleton::_sInstance;

int main()
{
	Singleton::GetInstance()->Print();
	return 0;
}
