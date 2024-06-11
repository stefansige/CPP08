#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	try
	{
		std::cout << "Vector: " << *easyfind(vec, 1) << std::endl;
		std::cout << "List: " << *easyfind(lst, 5) << std::endl;
		std::cout << "Deque: " << *easyfind(deq, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return 0;
}
