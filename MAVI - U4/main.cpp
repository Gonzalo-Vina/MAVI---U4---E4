#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
	//////Variables//////
	Texture textureSquare, textureCircle;
	Sprite square, circle;

	Vector2f positionObjects(336, 236);
	int timeBetweenChange = 0;
	bool isSquare = true;

	//Cargamos la textura del archivo
	textureSquare.loadFromFile("assets/cuad_yellow.png");
	textureCircle.loadFromFile("assets/rcircleg.png");

	//Cargamos el material del sprite
	square.setTexture(textureSquare);
	circle.setTexture(textureCircle);

	//Redimensionamos el cuadrado para que tenga el tamaño del circulo
	square.setScale(0.25, 0.25);

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");

	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;	
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();

			if (Keyboard::isKeyPressed(Keyboard::Space) == true && timeBetweenChange == 0) {
				if (isSquare) {
					isSquare = false;
					timeBetweenChange = 700;
				}
				else {
					isSquare = true;
					timeBetweenChange = 700;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Up) == true && positionObjects.y >= 0) {
				positionObjects.y -= 10;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) == true && positionObjects.y <= 472) {
				positionObjects.y += 10;
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) == true && positionObjects.x >= 0) {
				positionObjects.x -= 10;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) == true && positionObjects.x <= 672) {
				positionObjects.x += 10;
			}
		}	

		if (timeBetweenChange > 0) {
			timeBetweenChange -= 1;
		}

		square.setPosition(positionObjects.x, positionObjects.y);
		circle.setPosition(positionObjects.x, positionObjects.y);

		App.clear();

		if (isSquare) {
			App.draw(square);
		}
		else {
			App.draw(circle);
		}

		App.display();
	}
	return 0;
}

