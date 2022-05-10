#include "Game.h"

//Private Functions
void Game::initVariables()
{
    this->window = nullptr;

}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 400;
    //this->videoMode.getDesktopMode();
    this->window = new sf::RenderWindow(this->videoMode, "TourmaWorld", sf::Style::Default);
}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running()
{
    return this->window->isOpen();
}


//Function

void Game::pollEvents()
{
    //Basic event loop
    while (this->window->pollEvent(this->ev)) {
        switch(this->ev.type) {
            case sf::Event::Resized:
                this->window->setView(sf::View(sf::FloatRect(0, 0, ev.size.width, ev.size.height)));
                continue;
            case sf::Event::Closed:
                this->window->close();
                continue;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    /*
     * Renders the game object
     */
    this->window->clear(sf::Color::Black);
    this->window->display();
}
