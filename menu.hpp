#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * @file menu.h
 * @brief Deklaracja funkcji związanych z menu i tekstami w grze.
 */

 /**
  * @brief Wyświetla menu główne gry.
  *
  * Funkcja obsługuje logikę i renderowanie menu głównego, umożliwiając graczowi rozpoczęcie nowej gry
  * lub kontynuowanie z zapisanego poziomu.
  *
  * @param window Obiekt sf::RenderWindow reprezentujący okno gry.
  * @return int Zwraca 1, jeśli gracz wybierze rozpoczęcie nowej gry.
  */
int menu(sf::RenderWindow& window);

/**
 * @brief Wyświetla ekran końcowy gry.
 *
 * Funkcja obsługuje renderowanie ekranu końcowego po zakończeniu gry oraz może zmieniać
 * stan gry w zależności od numeru poziomu.
 *
 * @param window Obiekt sf::RenderWindow reprezentujący okno gry.
 * @param numberLevel Referencja do numeru poziomu, który może zostać zaktualizowany.
 */
void end(sf::RenderWindow& window, int& numberLevel);

/**
 * @brief Wyświetla obrazy pomiędzy poziomami
 *
 * Funkcja obsługuje renderowanie obrazów na ekranie, które są powiązane z aktualnym poziomem gry.
 *
 * @param window Obiekt sf::RenderWindow reprezentujący okno gry.
 * @param numberLevel Referencja do numeru poziomu, którego dotyczy tekst.
 */
void text(sf::RenderWindow& window, int& numberLevel);

#endif // MENU_H
