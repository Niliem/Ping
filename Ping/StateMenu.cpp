#include "StateMenu.hpp"


StateMenu::StateMenu()
{
	std::cout << "State Menu - Constructor" << std::endl;
}

StateMenu::~StateMenu()
{
	std::cout << "State Menu - Destructor" << std::endl;
}

void StateMenu::handleEvent()
{
}

void StateMenu::update(float ft)
{
	std::cout << "State Menu - Update" << std::endl;
}

void StateMenu::render(sf::RenderWindow* window)
{
	std::cout << "State Menu - Render" << std::endl;
}
