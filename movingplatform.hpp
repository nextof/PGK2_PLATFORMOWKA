#pragma once
#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "entity.hpp"

/**
 * @file movingplatform.h
 * @brief Deklaracja klasy MovingPlatform reprezentującej poruszającą się platformę w grze.
 */

 /**
  * @class MovingPlatform
  * @brief Klasa reprezentująca poruszającą się platformę w grze.
  *
  * Dziedziczy po klasie Entity. Platforma ta może poruszać się w określonym kierunku,
  * umożliwiając graczowi interakcję, np. przemieszczanie się po niej.
  */
class MovingPlatform : public Entity
{
public:
    /**
     * @brief Konstruktor klasy MovingPlatform.
     *
     * Tworzy obiekt poruszającej się platformy, ustawiając animacje, pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager zarządzający animacjami platformy.
     * @param lev Obiekt Level reprezentujący poziom, na którym platforma się znajduje.
     * @param x Początkowa współrzędna X platformy.
     * @param y Początkowa współrzędna Y platformy.
     */
    MovingPlatform(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan poruszającej się platformy.
     *
     * Funkcja obsługuje logikę ruchu platformy oraz jej interakcję z innymi obiektami.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);
};

#endif // MOVINGPLATFORM_H
