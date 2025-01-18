#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

/**
 * @file enemy.h
 * @brief Deklaracja klasy Enemy reprezentującej przeciwnika w grze.
 */

 /**
  * @class Enemy
  * @brief Klasa reprezentująca przeciwnika w grze.
  *
  * Dziedziczy po klasie Entity. Reprezentuje wrogów poruszających się po poziomie gry,
  * którzy mogą wchodzić w interakcję z graczem.
  */
class Enemy : public Entity
{
public:
    /**
     * @brief Konstruktor klasy Enemy.
     *
     * Tworzy obiekt przeciwnika, ustawiając animacje, pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager do zarządzania animacjami przeciwnika.
     * @param lev Obiekt Level reprezentujący poziom, na którym przeciwnik się znajduje.
     * @param x Współrzędna X początkowej pozycji przeciwnika.
     * @param y Współrzędna Y początkowej pozycji przeciwnika.
     */
    Enemy(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan przeciwnika w grze.
     *
     * Funkcja odpowiedzialna za obsługę logiki przeciwnika, w tym ruchu i zachowań.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);

    /**
     * @brief Obsługuje kolizję przeciwnika z innymi obiektami.
     *
     * Funkcja wykrywa i obsługuje kolizje w zależności od kierunku ruchu przeciwnika.
     *
     * @param Dx Przesunięcie w osi X.
     * @param Dy Przesunięcie w osi Y.
     */
    void Collision(float Dx, float Dy);
};

#endif // ENEMY_H
