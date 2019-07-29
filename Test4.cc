#include<mutex>
#include<iostream>
using namespace std;

class Singleton
{
	public:
		static Singleton* GetInstance()
		{
			if(_spInstance == nullptr)
			{
				//mutex.lock()
				if(_spInstance == nullptr)
				   _spInstance = new Singleton();
				//mutex.unlock()
			}
			return _spInstance;
		}

		void Print()
		{
			cout << "懒汉模式" << endl;
		}
		
		class LaJiHuiShou
		{
			public:
				~LaJiHuiShou()
				{	
						if(Singleton::_spInstance)
							delete Singleton::_spInstance;
				}

				void Print()
				{
					cout << "析构函数" << endl;
				}

				static LaJiHuiShou laJiHuiShou;
		};
	private:
	Singleton(){}

	Singleton(const Singleton& sl);

	Singleton& operator=(const Singleton& sl) = delete;

	static Singleton* _spInstance;
};


Singleton* Singleton::_spInstance = nullptr;
Singleton::LaJiHuiShou laJiHuiShou;

int main()
{
	Singleton::GetInstacne() -> Print();
	return 0;
}
