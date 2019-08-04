#include "vector.h"

class Test
{
public:
	Test()
	{
		std::cout << "Test()" << std::endl;
	}
	
	Test(const Test& other)
	{
		std::cout << "Test(const Test& other)" << std::endl;
	}
	
	Test& operator=(const Test other)
	{
		std::cout << "Test& operator=(const Test other)" << std::endl;
	}
	
	Test(Test&& other)
	{
		std::cout << "Test(Test&& other)" << std::endl;
	}

	Test& operator=(Test&& other)
	{
		std::cout << "Test& operator=(Test&& other)" << std::endl;
	}

	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};

int main(void)
{

	vector<Test> v;
	Test t;
	v.push_back(t);
	//v.push_back(Test());
	//v.emplace_back(Test());
}
