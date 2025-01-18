#pragma once
#include "game.hpp"

void showGameOverScreen(RenderWindow& window, int finalScore, int numberLevel)
{
	// Ustawienie czcionki i tekstu
	Font font;
	if (!font.loadFromFile("res/7526.ttf")) {
		// Błąd ładowania czcionki
		return;
	}

	// Tekst "GAME OVER"
	Text gameOverText("GAME OVER", font);
	gameOverText.setFillColor(Color::Red);

	// Tekst z wynikiem
	Text scoreText("Your Score: " + std::to_string(finalScore), font);
	scoreText.setFillColor(Color::White);

	// Tekst z instrukcjami
	Text restartText("Press ENTER to Restart or ESC to Exit", font);
	restartText.setFillColor(Color::Yellow);

	// Dopasowanie rozmiaru czcionki do okna
	float windowWidth = window.getSize().x;
	float windowHeight = window.getSize().y;

	// Ustawienie bazowego rozmiaru czcionki w zależności od szerokości okna
	float baseWidth = 1024.0f;
	float scaleFactor = windowWidth / baseWidth;

	gameOverText.setCharacterSize(50 * scaleFactor);  // Czcionka dla "GAME OVER"
	scoreText.setCharacterSize(30 * scaleFactor);     // Czcionka dla "Your Score"
	restartText.setCharacterSize(25 * scaleFactor);   // Czcionka dla instrukcji

	// Ustawienie widoku gry
	View view(FloatRect(0, 0, windowWidth, windowHeight));  // Widok dostosowany do okna
	window.setView(view);

	// Pętla wyświetlająca ekran
	bool waitingForInput = true;
	while (waitingForInput)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();  // Zamknięcie gry
				waitingForInput = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				RunGame(window, numberLevel);
				waitingForInput = false;
			}
		}

		// Pozycjonowanie tekstów w zależności od rozmiaru okna
		gameOverText.setPosition(windowWidth / 2 - gameOverText.getLocalBounds().width / 2, windowHeight / 4);
		scoreText.setPosition(windowWidth / 2 - scoreText.getLocalBounds().width / 2, windowHeight / 2);
		restartText.setPosition(windowWidth / 2 - restartText.getLocalBounds().width / 2, windowHeight * 3 / 4);

		// Rysowanie tekstów
		window.clear();
		window.draw(gameOverText);
		window.draw(scoreText);
		window.draw(restartText);
		window.display();
	}
}


float CheckX = 0, CheckY = 0;
bool RunGame(RenderWindow& window, int& numberLevel)
{
	View view(FloatRect(0, 0, 640, 480));  // Ustaw widok gry.

	Level lvl;

	// Ładowanie dźwięków do gry.
	SoundBuffer damage;
	damage.loadFromFile("res/sound/damage.wav");
	Sound damageSound(damage);
	damageSound.setVolume(50);

	SoundBuffer kill;
	kill.loadFromFile("res/sound/hit.mp3");
	Sound killSound(kill);
	killSound.setVolume(50);

	SoundBuffer coin;
	coin.loadFromFile("res/sound/coin.ogg");
	Sound coinSound(coin);
	coinSound.setVolume(10);

	// Ładowanie poziomu.
	changeLevel(lvl, numberLevel);

	// Ładowanie grafik tła i innych zasobów.
	Image background;
	background.loadFromFile("res/images/black.png");
	Texture backgroundTexture;
	backgroundTexture.loadFromImage(background);
	Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setOrigin(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2);

	Image background2;
	background2.loadFromFile("res/images/blue.png");
	Texture background2Texture;
	background2Texture.loadFromImage(background2);
	Sprite background2Sprite(background2Texture);
	background2Sprite.setOrigin(background2Texture.getSize().x / 2, background2Texture.getSize().y / 2);

	Image heroImage;
	heroImage.loadFromFile("res/images/Ugandatest.png");
	Texture heroTexture;
	//heroTexture.setSmooth(true);
	heroTexture.loadFromImage(heroImage);

	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("res/images/Shrek.png");
	Texture easyEnemyTexture;
	//easyEnemyTexture.setSmooth(true);
	easyEnemyTexture.loadFromImage(easyEnemyImage);

	Image doorImage;
	doorImage.loadFromFile("res/images/door.png");
	Texture doorTexture;
	doorTexture.setSmooth(true);
	doorTexture.loadFromImage(doorImage);

	Image spikesImage;
	spikesImage.loadFromFile("res/images/spikes.png");
	Texture spikesTexture;
	spikesTexture.setSmooth(true);
	spikesTexture.loadFromImage(spikesImage);

	Image movePlatformImage;
	movePlatformImage.loadFromFile("res/images/movingPlatform.png");
	Texture movePlatformTexture;
	movePlatformTexture.setSmooth(true);
	movePlatformTexture.loadFromImage(movePlatformImage);

	Image movePlatformImageY;
	movePlatformImageY.loadFromFile("res/images/movingPlatformY.png");
	Texture movePlatformTextureY;
	movePlatformTextureY.setSmooth(true);
	movePlatformTextureY.loadFromImage(movePlatformImageY);


	Image coinImage;
	coinImage.loadFromFile("res/images/bitcoin.png");
	Texture coinTexture;
	coinTexture.setSmooth(true);
	coinTexture.loadFromImage(coinImage);

	//Wczytywanie animacji z XML 
	AnimationManager anim;
	anim.loadFromXML("res/player.xml", heroTexture);
	anim.animList["jump"].loop = 0;

	AnimationManager anim2;
	anim2.loadFromXML("res/enemy.xml", easyEnemyTexture);
	anim2.animList["dead"].loop = 0;

	AnimationManager anim3;
	anim3.loadFromXML("res/spikes.xml", spikesTexture);

	AnimationManager anim4;
	anim4.loadFromXML("res/nextlevel.xml", doorTexture);

	AnimationManager anim5;
	anim5.loadFromXML("res/movingPlatform.xml", movePlatformTexture);

	AnimationManager anim6;
	anim6.loadFromXML("res/movingPlatformY.xml", movePlatformTextureY);

	AnimationManager anim9;
	anim9.loadFromXML("res/Coin.xml", coinTexture);

	// Konfiguracja tekstu HUD
	Font font;
	font.loadFromFile("res/7526.ttf");
	Text text("", font, 30);
	text.setFillColor(Color(218, 165, 32));

	
	// Tworzenie listy wszystkich obiektów w grze
	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator it2;


	// Dodawanie obiektów do listy
	std::vector<Object> e = lvl.GetObjects("EasyEnemy");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Enemy(anim2, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("Coin");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Coin(anim9, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("Spikes");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Spikes(anim3, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("NextLevel");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new NextLevel(anim4, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("MovingPlatform");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new MovingPlatform(anim5, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("MovingPlatformY");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new MovingPlatformY(anim6, lvl, e[i].rect.left, e[i].rect.top));


	// Tworzenie gracza i przypisanie pozycji.
	Object pl = lvl.GetObject("player");
	Player p(anim, lvl, pl.rect.left, pl.rect.top);
	if ((CheckX != 0) && (CheckY != 0)) {
		p.x = CheckX;
		p.y = CheckY;
	}

	std::ifstream fin("res/save.txt");
	fin >> p.cash;

	Clock clock;

	// Główna pętla gry.
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;  

		if (time > 40) time = 40; // Ograniczenie czasu aktualizacji.

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Obsługa zamknięcia okna.
				window.close(); 
		}

		// Obsługa klawiszy sterowania.
		if (Keyboard::isKeyPressed(Keyboard::Left)) p.key["L"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Right)) p.key["R"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Space)) p.key["Space"] = true;
		if (Keyboard::isKeyPressed(Keyboard::LShift)) p.key["Shift"] = true;
		if (Keyboard::isKeyPressed(Keyboard::A)) p.key["A"] = true;
		if (Keyboard::isKeyPressed(Keyboard::D)) p.key["D"] = true;
		if (Keyboard::isKeyPressed(Keyboard::W)) p.key["W"] = true;

		// Aktualizacja stanu wszystkich obiektów.
		for (it = entities.begin(); it != entities.end();)
		{
			Entity* b = *it;
			b->update(time);
			it++;
		}
		if (p.isDead == true)
		{
			// Zapisz pozycję gracza
			CheckX = p.sx;
			CheckY = p.sy;

			// Wywołanie ekranu z wynikiem
			showGameOverScreen(window, p.cash, numberLevel);  // Przekazujemy liczbę monet

			return false;  // Kończy grę i zamyka okno gry
		}

		// Sprawdzenie kolizji gracza z innymi obiektami.
		for (it = entities.begin(); it != entities.end(); it++)
		{

			if ((*it)->life == false)
			{
				Entity* b = *it;
				it = entities.erase(it);
				delete b;
			}

			if ((*it)->getRect().intersects(p.getRect()))
			{
				if ((*it)->Name == "EasyEnemy") {

					if ((p.y - 1 < (*it)->y) && (p.dy > 0))
					{
						if ((*it)->isDead != true)
						{
							p.dy = -0.3;

							(*it)->isDead = true; killSound.play();
						}
					}
					else
					{
						if ((*it)->dx < 0)
						{
							//(*it)->dx = 0;
							if (p.lifeCooldown <= 0.0f) {
								p.minusLife(); p.lifeCooldown = 400;
								damageSound.play();
							}
						}
						if ((*it)->dx > 0)
						{
							//(*it)->dx = 0;
							if (p.lifeCooldown <= 0.0f) {
								p.minusLife(); p.lifeCooldown = 400;
								damageSound.play();
							}
						}
					}
				}
			}
			if ((((*it)->Name == "MovingPlatform") || (((*it)->Name == "MovingPlatformY"))) && ((*it)->getRect().intersects(p.getRect())))
			{
				Entity* movPlat = *it;
				if (p.dy > 0)
					if (p.y + p.h < movPlat->y + movPlat->h)
					{
						p.y = movPlat->y - p.h + 3; p.x += movPlat->dx * time; p.dy = 0; p.STATE = Player::stay;
					}
			}
			if (((*it)->Name == "NextLevel") && ((*it)->getRect().intersects(p.getRect())))
			{
				numberLevel++;
				std::ofstream fout("res/save.txt", std::ios_base::trunc);
				fout.close();
				fout.open("res/save.txt", std::ios_base::out);
				fout << numberLevel;
				fout.close();

				std::ofstream fout2("res/save.txt", std::ios_base::trunc);
				fout2.close();
				fout2.open("res/save.txt", std::ios_base::out);
				fout2 << p.cash;
				fout2.close();

				return false;
			}
			if (((*it)->Name == "Spikes") && ((*it)->getRect().intersects(p.getRect())))
			{
				if ((p.x - ((*it)->x)) <= -5 || (p.x - ((*it)->x)) >= 5)
				{
					if (p.lifeCooldown <= 0.0f) {
						p.minusLife(); p.lifeCooldown = 400;
						damageSound.play();
					}
				}
			}
			if (((*it)->Name == "Coin") && ((*it)->getRect().intersects(p.getRect())))
			{
				if ((*it)->isDead != true)
				{
					coinSound.play();
					p.cash++;
					(*it)->isDead = true;
				}
			}
			for (it2 = entities.begin(); it2 != entities.end(); it2++)
			{
				if ((*it)->getRect() != (*it2)->getRect())
					if (((*it)->getRect().intersects((*it2)->getRect())) && ((*it)->Name == "EasyEnemy") && ((*it2)->Name == "EasyEnemy"))
					{
						(*it)->dx *= -1;
						if ((*it)->dx < 0)
							(*it)->anim.set("moveLeft");
						if ((*it)->dx > 0)
							(*it)->anim.set("moveRight");
					}
			}
			if (p.getLife() <= 0) p.isDead = true; // Sprawdzenie stanu życia gracza.
			if (p.isDead == true)
			{
				CheckX = p.sx;
				CheckY = p.sy;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }
		p.update(time);
		// Aktualizacja pozycji kamery i tła.
		view.setCenter(p.x, p.y);
		window.setView(view);

		backgroundSprite.setPosition(view.getCenter());
		background2Sprite.setPosition(view.getCenter());
		if (numberLevel == 3)
			window.draw(background2Sprite);
		else
			window.draw(backgroundSprite);

		lvl.Draw(window); // Rysowanie poziomu.

		for (it = entities.begin(); it != entities.end(); it++)
			(*it)->draw(window);

		p.draw(window);

		// Wyświetlanie liczby monet.
		std::ostringstream playerCash;
		playerCash << p.cash;
		text.setString("MONETY " + playerCash.str());
		text.setPosition(view.getCenter().x + 145, view.getCenter().y - 240);

		window.draw(text);

		// Wyświetlanie liczby żyć.
		std::ostringstream playerLife;
		playerLife << p.getLife();
		text.setString("HP " + playerLife.str());
		text.setPosition(view.getCenter().x - 305, view.getCenter().y - 240);

		window.draw(text);

		window.display();
	}

}


