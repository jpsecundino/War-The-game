#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 640), "WAR");
   
    sf::Texture texture;
    
    if (!texture.loadFromFile("mapa.jpg"))
        return EXIT_FAILURE;
    
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("FreeSans.ttf"))
        return EXIT_FAILURE;
 

    sf::Text text;

	text.setFont(font); 

	
	text.setString("GUERRA");

	
	text.setFillColor(sf::Color::Red);

	
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(sprite);
	window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}

