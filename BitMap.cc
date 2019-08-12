#include<iostream>
#include<vector>
using namespace std;

class BitMap
{
	public:
		BitMap(size_t bitCount)
			:_bit((bitCount>>5)+1)
			,_bitCount(bitCount)
			{}

		//置1
		void Set(size_t which)
		{
			if(which > _bitCount)
				return;

			size_t index = (which >> 5);
			size_t pos = which % 32;

			_bit[index] |= (1 << pos);
		}

		//置0
		void ReSet(size_t which)
		{
			if(which > _bitCount)
				return ;

			size_t index = (which >> 5);
			size_t pos = which % 32;
			_bit[index] &= ~(1 << pos);
		}

    //检测位图中which是否为1
		bool Test(size_t )
		{
			if(which >  _bitCount)
				return false;

			size_t index = (which >> 5);
			size_t pos = which % 32;
			return _bit[index] & (1 << pos);
		}

		//获取位图中比特的总位数
		size_t Size()const
		{
			return _bitCount;
		}
	private:
		vector<int> _bit;
		size_t _bitCount;
};
