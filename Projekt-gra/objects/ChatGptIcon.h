#include "Icons.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../ResourceManager.h"
#include "fmt/core.h"


class ChatGptIcon
        : public Icons{
public:
    ChatGptIcon(float x, float y) : Icons(x, y){
        this->icon.setPosition(x, y);
        this->icon.setTexture(ResourceManager::getTexture("../graphics/ChatGPT-Logo.png"));
        this->chat.scale((float)100/icon.getTexture()->getSize().x,(float)100/icon.getTexture()->getSize().y);
        this->chat.setPosition(425,125);
        this->windowScreen.setSize(sf::Vector2f(750, 450));
        this->windowScreen.setOutlineThickness(10);
        this->windowScreen.setOutlineColor(sf::Color::Black);
        this->windowScreen.setFillColor(sf::Color::White);
        this->windowScreen.setPosition(425, 125);
        this->icon.scale(0.55, 0.58);
        this->centerX = icon.getPosition().x + 64;
        this->centerY = icon.getPosition().y + 64;
        if(!font.loadFromFile("../graphics/PIXELAR REGULAR.OTF")) {
            fmt::println("font loading error");
        }
        currentText.setFont(font);
        currentText.setPosition(800,300);
        currentText.setFillColor(sf::Color::Black);
        chatGptOutput = {"Honestly I have no idea", "Tried googling?", "Touch grass", " Math? I only speak in memes.", "Go outside bro", "...", "Oh, you can't solve that? Shocking", "Really? You need help with this? ", "I'm not search engine"};
    }
    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    void collision() override;
    bool isActive() override;
    void drawApp(sf::RenderWindow& window) override;


private:
    sf::Sprite icon;
    sf::Sprite closeWindow;
    sf::RectangleShape windowScreen;
    sf::Sprite chat;
    std::vector<sf::Text> answers;
    std::vector<std::string> chatGptOutput;
    sf::Text currentText;
    std::string inputString;
    sf::Font font;
    float centerX;
    float centerY;
    int id = 1;
    bool active = false;
    bool keyState[sf::Keyboard::KeyCount] = {false};


};

