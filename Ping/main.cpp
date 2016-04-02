#include "Application.hpp"

#include <stdexcept>
#include <iostream>

int main()
{
	try
	{
		Application{}.run();
	}
	catch (const std::exception& exception)
	{
		std::cout << "EXCEPTION: " << exception.what() << std::endl;
	}	
}