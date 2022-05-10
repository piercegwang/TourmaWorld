#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
 * Wrapper class for all functionality of Game.
 */
class Game
{
private:
    //Variables
    //Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;

    // Private functions
    void initVariables();
    void initWindow();

public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running();

    //Functions
    void pollEvents();
    void update();
    void render();
};


#endif // GAME_H_
