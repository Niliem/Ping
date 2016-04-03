#include "StateMenu.hpp"


StateMenu::StateMenu(sf::RenderWindow* window)
	:actor{10, 10, 40, 100, 0.1, 0.2}
{
	mWindow = window;
	std::cout << "State Menu - Constructor" << std::endl;
}

StateMenu::~StateMenu()
{
	std::cout << "State Menu - Destructor" << std::endl;
}

void StateMenu::handleEvent()
{
	actor.isRun = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void StateMenu::update(float ft)
{
	actor.update(mWindow);
	std::cout << "State Menu - Update" << std::endl;
}

void StateMenu::render()
{
	mWindow->draw(actor.shape);
	std::cout << "State Menu - Render" << std::endl;
}
