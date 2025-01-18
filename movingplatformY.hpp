#pragma once
#ifndef MOVINGPLATFORMY_H
#define MOVINGPLATFORMY_H

#include "entity.hpp"

/**
 * @file movingplatformy.h
 * @brief Deklaracja klasy MovingPlatformY reprezentującej poruszającą się platformę w osi Y.
 */

 /**
  * @class MovingPlatformY
  * @brief Klasa reprezentująca platformę poruszającą się w osi Y w grze.
  *
  * Dziedziczy po klasie Entity, umożliwiając graczowi interakcję, np. przemieszczanie się po niej.
  */
class MovingPlatformY : public Entity
{
public:
    /**
     * @brief Konstruktor klasy MovingPlatformY.
     *
     * Tworzy obiekt platformy poruszającej się w osi Y, ustawiając animacje,
     * pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager zarządzający animacjami platformy.
     * @param lev Obiekt Level reprezentujący poziom, na którym platforma się znajduje.
     * @param x Początkowa współrzędna X platformy.
     * @param y Początkowa współrzędna Y platformy.
     */
    MovingPlatformY(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan poruszającej się platformy.
     *
     * Funkcja obsługuje logikę ruchu platformy w osi Y oraz jej interakcję z innymi obiektami.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);
};

#endif // MOVINGPLATFORMY_H
