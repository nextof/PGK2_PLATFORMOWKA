/**
 * @mainpage 
 *
 * @section wprowadzenie Wprowadzenie
 *
 * Gra została napisana w języku C++, oparta na bibliotece SFML, w której gracz eksploruje poziomy,
 * unika przeszkód, zbiera monety oraz stawia czoła przeciwnikom. Projekt demonstruje
 * wykorzystanie animacji, zarządzania obiektami i kolizjami w środowisku gry.
 *
 * @section funkcjonalnosci Kluczowe funkcjonalności
 * - **Sterowanie gracza:** Możliwość ruchu, skakania i interakcji z otoczeniem.
 * - **Wrogowie:** Prości przeciwnicy z logiką ruchu i kolizji.
 * - **Obiekty poziomu:** Ruchome platformy, kolce, monety i punkty kontrolne.
 * - **Animacje:** Obsługa animacji oparta na plikach XML.
 * - **Menu:** Interfejs do rozpoczęcia nowej gry, wczytania stanu gry i sterowania.
 * - **Efekty dźwiękowe:** Dźwięki interakcji, obrażeń, zbierania monet i innych zdarzeń.
 *
 * @section struktura Struktura projektu
 *
 * Projekt składa się z następujących komponentów:
 * - **game.hpp/cpp:** Główna logika gry, pętla gry, inicjalizacja zasobów i obiektów.
 * - **menu.hpp/cpp:** Obsługa menu gry i ekranów końcowych.
 * - **player.hpp/cpp:** Klasa reprezentująca gracza, jego logikę ruchu, animacje i interakcje.
 * - **enemy.hpp/cpp:** Klasa przeciwnika z podstawową logiką ruchu i interakcji.
 * - **entity.hpp/cpp:** Klasa bazowa dla wszystkich obiektów w grze, z obsługą animacji i kolizji.
 * - **animation.hpp/cpp:** Zarządzanie animacjami obiektów na podstawie plików XML.
 * - **movingplatform.hpp/cpp:** Klasy dla ruchomych platform (w osi X i Y).
 * - **spikes.hpp/cpp:** Kolce jako przeszkody na poziomie.
 * - **coin.hpp/cpp:** Monety zbierane przez gracza.
 *
 * @section sterowanie Sterowanie
 *
 * - **Strzałki lub A/D:** Ruch w lewo/prawo.
 * - **Spacja lub W:** Skok.
 * - **Shift:** Przyspieszenie.
 * - **Escape:** Pauza lub powrót do menu.
 *
 * @section autorzy Autorzy
 *
 * - Autorzy: Karol Wójcik, Jakub Sikora, Patryk Sobczyński
 * - Technologia: C++, SFML 2.6.1, TinyXML
 *

 */



/**
 * @file main.cpp
 * @brief Główna funkcja programu uruchamiająca grę.
 */

#include "game.hpp"
#include "menu.hpp"

 /**
  * @brief Funkcja główna programu.
  *
  * Tworzy okno gry, ustawia limit klatek, obsługuje zapisywanie i wczytywanie poziomów,
  * inicjalizuje muzykę i dźwięki oraz zarządza przebiegiem gry w zależności od stanu rozgrywki.
  *
  * @return int Kod zakończenia programu (0 dla powodzenia).
  */
int main()
{
    // Tworzenie okna gry
    RenderWindow window(VideoMode(1024, 768), "Platformowka PGK2");
    window.setFramerateLimit(60);

    // Wczytanie numeru poziomu z pliku
    int numberLevel = 0;
    window.setMouseCursorVisible(false);
    std::ifstream fin("res/save.txt");
    fin >> numberLevel;

    // Wyświetlenie menu głównego
    if (menu(window) == 1)
    {
        numberLevel = 1;

        // Czyszczenie i ponowne zapisanie pliku z poziomem
        std::ofstream fout2("res/save.txt", std::ios_base::trunc);
        fout2.close();
        fout2.open("res/save.txt", std::ios_base::out);
        fout2 << 0;
        fout2.close();
    }

    // Inicjalizacja muzyki
    Music m1, m2, m3;
    m1.openFromFile("res/sound/retro.mp3");
    m2.openFromFile("res/sound/neon.mp3");
    m3.openFromFile("res/sound/short.mp3");
    m1.setVolume(5); m2.setVolume(5); m3.setVolume(5);
    m1.setLoop(true); m2.setLoop(true); m3.setLoop(true);

    // Inicjalizacja dźwięku startowego
    SoundBuffer start;
    start.loadFromFile("res/sound/start.mp3");
    Sound startSound(start);
    startSound.setVolume(70);

    // Obsługa poziomów gry
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

    // Zapisanie stanu gry do pliku
    std::ofstream fout("res/save.txt", std::ios_base::trunc);
    fout.close();
    fout.open("res/save.txt", std::ios_base::out);
    fout << numberLevel;
    fout.close();

    return 0;
}
