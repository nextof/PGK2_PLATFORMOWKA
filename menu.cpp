#pragma once
#include "menu.hpp"

using namespace sf;

int menu(sf::RenderWindow& window)
{
	Music musicMenu;
	musicMenu.openFromFile("res/sound/menu.wav");
	musicMenu.play();
	musicMenu.setLoop(true);
	musicMenu.setVolume(20);

	SoundBuffer click;
	click.loadFromFile("res/sound/click.wav");
	Sound clickSound(click);
	clickSound.setVolume(40);

	SoundBuffer open;
	open.loadFromFile("res/sound/open.wav");
	Sound openSound(open);
	openSound.setVolume(40);

	SoundBuffer back;
	back.loadFromFile("res/sound/return.wav");
	Sound backSound(back);

	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, keyTexture, menuBackground;
	menuTexture1.loadFromFile("res/images/nowagra.png");
	menuTexture3.loadFromFile("res/images/sterowanie.png");
	menuTexture4.loadFromFile("res/images/zamknij.png");
	menuTexture2.loadFromFile("res/images/wczytaj.png");

	keyTexture.loadFromFile("res/images/controls.png");
	menuBackground.loadFromFile("res/images/menuBack.jpg");

	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), key(keyTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	sf::Color color(255, 168, 65);
	menu1.setPosition(270, 150);
	menu2.setPosition(250, 250);
	menu3.setPosition(250, 350);
	menu4.setPosition(240, 550);

	int newgame = 0;
	int position = 1;

	sf::Event event;
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menu4.setColor(Color::White);

		menuNum = 0;
		window.clear(Color(129, 181, 221));

		while (window.pollEvent(event))
		{
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
			{
				clickSound.play();
				position++;
			}
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
			{
				clickSound.play();
				position--;
			}
		}

		if (position == 1) { menu1.setColor(color); menuNum = 1; }
		if (position == 2) { menu2.setColor(color); menuNum = 2; }
		if (position == 3) { menu3.setColor(color); menuNum = 3; }
		if (position == 4) { menu4.setColor(color); menuNum = 4; }


		if (position == 0) { position = 4; }
		if (position == 5) { position = 1; }

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			openSound.play();
			if (menuNum == 1) { newgame = 1; isMenu = false; }
			if (menuNum == 2) { isMenu = false; }
			if (menuNum == 3) { window.draw(key); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); if (Keyboard::isKeyPressed(Keyboard::Escape))backSound.play(); }
			if (menuNum == 4) { exit(0); } 

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);


		window.display();
	}

	return newgame;
}

void end(sf::RenderWindow& window, int& numberLevel)
{
	Music musicEnd;
	musicEnd.openFromFile("res/sound/end.ogg");
	musicEnd.setVolume(50);
	musicEnd.setLoop(true);
	musicEnd.play();

	Texture endTexture;
	endTexture.loadFromFile("res/images/end.jpg");

	Sprite end(endTexture);
	bool isMenu = 1;

	View view; view.reset(FloatRect(0, 0, 1024, 768));
	window.setView(view);

	while (isMenu)
	{
		window.clear(Color(77, 83, 140));

		if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); isMenu = false; numberLevel--; }

		window.draw(end);

		window.display();
	}

}

void text(sf::RenderWindow& window, int& numberLevel)
{
	Music musicText;
	musicText.openFromFile("res/sound/text.ogg");
	musicText.play();
	musicText.setLoop(true);
	musicText.setVolume(50);

	Texture p1, p2, p3, p4;
	p1.loadFromFile("res/images/1.png");
	p2.loadFromFile("res/images/2.png");
	p3.loadFromFile("res/images/3.png");
	p4.loadFromFile("res/images/4.png");
	Sprite sp1(p1), sp2(p2), sp3(p3), sp4(p4);

	bool isMenu = 1;

	View view; view.reset(FloatRect(0, 0, 1024, 768));
	window.setView(view);

	while (isMenu)
	{

		window.clear(Color(77, 83, 140));

		if (Keyboard::isKeyPressed(Keyboard::Return)) { isMenu = false; }

		if (numberLevel == 1)
			window.draw(sp1);
		if (numberLevel == 2)
			window.draw(sp2);

		if (numberLevel == 3 || numberLevel==4)
			window.draw(sp3);
		if (numberLevel == 7 || numberLevel==5)
			window.draw(sp4);

		window.display();
	}

}

