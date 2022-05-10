#include "main.h"

int main(int argc, char * argv[]) {

    // Init Game engine
    Game game;

    //Create a window
    sf::RenderWindow w(sf::VideoMode(800, 600), "TourmaWorld", sf::Style::Default);

    sf::Texture texture;
    if (!texture.loadFromFile("../resources/textures/peter.png")) {
        return 0;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    //Main loop
    while (game.running()) {

        game.update();
        //Do logical updates here

        game.render();
    }
    //Ensure the window is closed
}
