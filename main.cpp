#include "game.hpp"
#include "menu.hpp"


int main()
{
	RenderWindow window(VideoMode(1024, 768), "Platformowka PGK2");

	window.setFramerateLimit(60);

	int numberLevel = 0;
	window.setMouseCursorVisible(false);
	std::ifstream fin("res/save.txt");
	fin >> numberLevel;
	if (menu(window) == 1)
	{
		numberLevel = 1;

		std::ofstream fout2("res/save.txt", std::ios_base::trunc);
		fout2.close();
		fout2.open("res/save.txt", std::ios_base::out);
		fout2 << 0;
		fout2.close();
	}

	Music m1, m2, m3;
	m1.openFromFile("res/sound/retro.mp3");
	m2.openFromFile("res/sound/neon.mp3");
	m3.openFromFile("res/sound/short.mp3");
	m1.setVolume(5); m2.setVolume(5); m3.setVolume(5);
	m1.setLoop(true); m2.setLoop(true); m3.setLoop(true);

	SoundBuffer start;
	start.loadFromFile("res/sound/start.mp3");
	Sound startSound(start);
	startSound.setVolume(70);

	if (numberLevel == 1)
	{
		text(window, numberLevel);
		startSound.play();

		m1.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 2)
	{
		m1.stop();

		text(window, numberLevel);
		startSound.play();

		m2.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 3 || numberLevel == 4)
	{
		m2.stop();

		text(window, numberLevel);
		startSound.play();

		m3.play();
		numberLevel = 4;
		RunGame(window, numberLevel);
	}

	if (numberLevel == 5 || numberLevel == 7)
	{
		m1.stop();

		text(window, numberLevel);
		startSound.play();

		m2.play();
		numberLevel = 7;
		RunGame(window, numberLevel);
	}


	if (numberLevel == 8)
	{
		m1.stop();
		end(window, numberLevel);
	}

	std::ofstream fout("res/save.txt", std::ios_base::trunc);
	fout.close();
	fout.open("res/save.txt", std::ios_base::out);
	fout << numberLevel;
	fout.close();
	return 0;
}
