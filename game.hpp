#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include "level.hpp"
#include "animation.hpp"
#include "changelevel.hpp"
#include "coin.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "movingplatform.hpp"
#include "movingplatformY.hpp"
#include "nextlevel.hpp"
#include "spikes.hpp"

using namespace sf;

/**
 * @file game.h
 * @brief Deklaracja funkcji i zmiennych globalnych związanych z uruchamianiem gry.
 */

 /**
  * @var CheckX
  * @brief Globalna zmienna przechowująca współrzędną X punktu kontrolnego.
  */
extern float CheckX;

/**
 * @var CheckY
 * @brief Globalna zmienna przechowująca współrzędną Y punktu kontrolnego.
 */
extern float CheckY;

/**
 * @brief Uruchamia główną pętlę gry dla danego poziomu.
 *
 * Funkcja obsługuje logikę gry, renderowanie oraz interakcje użytkownika dla
 * konkretnego poziomu, zmieniając stan gry w zależności od wydarzeń.
 *
 * @param window Obiekt RenderWindow reprezentujący okno gry.
 * @param numberLevel Referencja do numeru poziomu, który ma być uruchomiony.
 *
 * @return bool Zwraca wartość logiczną wskazującą powodzenie wykonania gry.
 */
bool RunGame(RenderWindow& window, int& numberLevel);

#endif // GAME_H
