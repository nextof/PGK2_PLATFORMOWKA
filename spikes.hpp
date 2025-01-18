#pragma once
#ifndef SPIKES_H
#define SPIKES_H

#include "entity.hpp"

/**
 * @file spikes.h
 * @brief Deklaracja klasy Spikes reprezentującej kolce w grze.
 */

 /**
  * @class Spikes
  * @brief Klasa reprezentująca kolce jako przeszkodę w grze.
  *
  * Dziedziczy po klasie Entity. Obiekt kolców działa jako przeszkoda,
  * która może zadawać obrażenia graczowi w przypadku kolizji.
  */
class Spikes : public Entity
{
public:
    /**
     * @brief Konstruktor klasy Spikes.
     *
     * Tworzy obiekt kolców, ustawiając animacje, pozycję oraz poziom, na którym się znajdują.
     *
     * @param a Obiekt AnimationManager zarządzający animacjami kolców.
     * @param lev Obiekt Level reprezentujący poziom, na którym kolce się znajdują.
     * @param x Początkowa współrzędna X kolców.
     * @param y Początkowa współrzędna Y kolców.
     */
    Spikes(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Aktualizuje stan kolców w grze.
     *
     * Funkcja obsługuje logikę obiektu, np. animacje, i ewentualne interakcje z innymi obiektami.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);
};

#endif // SPIKES_H
