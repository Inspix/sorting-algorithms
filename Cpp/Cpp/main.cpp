#include "Sorting.h"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

struct SimpleStruct {
	int x, y;
	char z;

	bool operator < (SimpleStruct other) {
		if (x == other.x)
		{
			return y != other.y ? y < other.y : false;
		}
		else
		{
			return x < other.x;
		}
	}

	bool operator > (SimpleStruct other) {
		if (x == other.x)
		{
			return y != other.y ? y > other.y : false;
		}
		else
		{
			return x > other.x;
		}
	}

	friend ostream& operator << (ostream& stream,SimpleStruct s) {
		stream << "x:" << s.x << " y:" << s.y  << "z:" << s.z << endl;
		return stream;
	}
};

int main(int argc, char** argv) {
	//array<int, 8> arr;
	srand(time_t(235));
	vector<SimpleStruct> arr(50);
	for (int i = 0; i < 50; i++)
	{
		arr[i] = SimpleStruct{ rand(),rand(),(char)rand() % 128 };
	}

	for (int i = 0; i < 50; i++)
	{
		cout << i+1 << " : " << arr[i] << endl;
	}

	Sorting::shell(arr.begin(),arr.end());
	static int counter = 0;
	for_each(arr.begin(), arr.end(), [](SimpleStruct x) { cout << ++counter << " : " << x << endl; });

	return 0;
}

