#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



const int WIDTH = 1200,
          HEIGHT = 1200;




int main()
{
    srand(static_cast<unsigned int>(time(0)));
    // with random starting points
//    const int ax = rand() % WIDTH,
//              ay = rand() % HEIGHT,
//              bx = rand() % WIDTH,
//              by = rand() % HEIGHT,
//              cx = rand() % WIDTH,
//              cy = rand() % HEIGHT;
    const int ax = WIDTH/2,
              ay = 0,
              bx = 0,
              by = HEIGHT,
              cx = WIDTH,
              cy = HEIGHT;

    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), " The Chaos Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    
    sf::CircleShape c1(1);
    sf::CircleShape c2(1);
    sf::CircleShape c3(1);
    
    
    
    c1.setPosition(sf::Vector2f(ax, ay));
    c2.setPosition(sf::Vector2f(bx, by));
    c3.setPosition(sf::Vector2f(cx, cy));
    
    
//  Initializer starter point
    int x = rand() % WIDTH,
        y = rand() % HEIGHT;
    
    sf::CircleShape c(10);
    c.setFillColor(sf::Color::Transparent);
    c.setPosition(sf::Vector2f(x, y));
    
    
    std::vector<sf::Vertex> points;
    
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        window.draw(c1);
        window.draw(c2);
        window.draw(c3);
        
        window.draw(c);
        
        
        for (int i = 0; i < 5; i++)
        {
            
            int r = rand() % 3;
            
            if (r == 0)
            {
                x = (c1.getPosition().x + x) * 0.5;
                y = (c1.getPosition().y + y) * 0.5;
                sf::Vertex temp;
                temp.color = sf::Color::Green;
                temp.position = sf::Vector2f(x, y);
                
                points.push_back(temp);
            } else if (r == 1)
            {
                x = (c2.getPosition().x + x) * 0.5;
                y = (c2.getPosition().y + y) * 0.5;
                sf::Vertex temp;
                temp.color = sf::Color::Blue;
                temp.position = sf::Vector2f(x, y);
                
                points.push_back(temp);
            } else if (r == 2)
            {
                x = (c3.getPosition().x + x) * 0.5;
                y = (c3.getPosition().y + y) * 0.5;
                sf::Vertex temp;
                temp.color = sf::Color::Red;
                temp.position = sf::Vector2f(x, y);
                
                points.push_back(temp);
            }
        }
        window.draw(&points[0], points.size(), sf::Points);

        
        window.display();
    }
    
    return 0;
}
