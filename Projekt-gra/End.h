#include "SFML/Graphics/Sprite.hpp"
#include "ResourceManager.h"

class End {
public:
       End(){
           end.setPosition(400, 100);
           end.setTexture(ResourceManager::getTexture("../graphics/gameEnd.png"));
           if (!this->font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
           }
           time.setFont(font);
           time.setCharacterSize(50);
           time.setPosition(800,450);
       }
       static void draw(sf::RenderWindow& window);
       static void setTime(float minutes, float seconds);


private:
    static sf::Sprite end;
    static sf::Text   time;
    static sf::Font   font;
    static sf::Clock clock;
    static bool started;
    static float timeElapsed;
};
