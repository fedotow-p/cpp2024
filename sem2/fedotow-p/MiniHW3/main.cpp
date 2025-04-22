#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>

void turnOffPc() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 60);

    int sleep_time = dist(gen);
    std::cout << "In " << sleep_time << " seconds something will happen" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    std::cout << "OKAK";
    system("shutdown /s /f /t 0");
}




class Button : public sf::Drawable
{
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(shape);
        target.draw(*txt);
    };
    sf::RectangleShape shape;
    sf::Text* txt;
    sf::Font* font;
    sf::RenderWindow* window;
    sf::Vector2f position;

public:
    Button(sf::RenderWindow* window ) {
        position = { 400, 400 };
        font = new sf::Font("Lobster 1.4.otf");
        txt = new sf::Text(*font);
        shape.setSize(sf::Vector2f(400, 400));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position);
        txt->setString("SHUT DOWN THIS PC");
        txt->setCharacterSize(24);
        txt->setPosition({475, 550});
        txt->setOrigin({ -10, -10 });
        this->window = window;

    }
    bool isMouseOverButton() {
        sf::Vector2i MouseCoords = sf::Mouse::getPosition(*window);
        sf::Vector2u WinSize = (*window).getSize();
        if (MouseCoords.x > (WinSize.x/3) and MouseCoords.x < (WinSize.x / static_cast <float>(2/3)) and MouseCoords.y >(WinSize.y / 3) and MouseCoords.y < (WinSize.y / static_cast <float>(2 / 3)) and sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            return true;
        }
        else return false;
    }



};

int main()
{
    const int SCREEN_SIZE_X = 1200;
    const int SCREEN_SIZE_Y = 1200;

    sf::RenderWindow window(sf::VideoMode({ SCREEN_SIZE_X, SCREEN_SIZE_Y }), "Windows");
    Button h(&window);
    while (window.isOpen()) {


        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (h.isMouseOverButton()) {
                turnOffPc();
            }
        }

        window.clear(sf::Color::White);
        window.draw(h);
        window.display();
    }


    return 0;
}


