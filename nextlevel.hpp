#pragma once
#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H

#include "entity.hpp"

/**
 * @file nextlevel.h
 * @brief Deklaracja klasy NextLevel reprezentującej obiekt przejścia do następnego poziomu.
 */

 /**
  * @class NextLevel
  * @brief Klasa reprezentująca obiekt przejścia do następnego poziomu w grze.
  *
  * Dziedziczy po klasie Entity. Obiekt ten działa jako punkt kontrolny lub miejsce,
  * które gracz musi osiągnąć, aby przejść na kolejny poziom.
  */
class NextLevel : public Entity
{
public:
    /**
     * @brief Konstruktor klasy NextLevel.
     *
     * Tworzy obiekt przejścia do następnego poziomu, ustawiając animacje,
     * pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager zarządzający animacjami obiektu.
     * @param lev Obiekt Level reprezentujący poziom, na którym znajduje się obiekt.
     * @param x Początkowa współrzędna X obiektu.
     * @param y Początkowa współrzędna Y obiektu.
     */
    NextLevel(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan obiektu przejścia do następnego poziomu.
     *
     * Funkcja obsługuje logikę obiektu, np. sprawdzanie kolizji z graczem.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);
};

#endif // NEXTLEVEL_H
