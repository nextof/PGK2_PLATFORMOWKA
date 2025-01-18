#pragma once
#ifndef COIN_H
#define COIN_H

#include "entity.hpp"

/**
 * @file coin.h
 * @brief Deklaracja klasy Coin reprezentującej monetę w grze.
 */

 /**
  * @class Coin
  * @brief Klasa reprezentująca monetę jako element gry.
  *
  * Dziedziczy po klasie Entity. Reprezentuje obiekt monety, który gracz może zebrać.
  */
class Coin : public Entity
{
public:
    /**
     * @brief Konstruktor klasy Coin.
     *
     * Tworzy obiekt monety, ustawiając animacje, pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager do zarządzania animacjami monety.
     * @param lev Obiekt Level reprezentujący poziom, na którym moneta się znajduje.
     * @param x Współrzędna X początkowej pozycji monety.
     * @param y Współrzędna Y początkowej pozycji monety.
     */
    Coin(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan monety w grze.
     *
     * Funkcja odpowiedzialna za aktualizację logiki monety, np. sprawdzanie kolizji z graczem.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);
};

#endif // COIN_H
