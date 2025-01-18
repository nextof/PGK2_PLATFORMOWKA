#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"

/**
 * @file player.h
 * @brief Deklaracja klasy Player reprezentującej gracza w grze.
 */

 /**
  * @class Player
  * @brief Klasa reprezentująca gracza w grze.
  *
  * Dziedziczy po klasie Entity. Odpowiada za logikę ruchu, kolizji oraz interakcji gracza
  * z otoczeniem w grze.
  */
class Player : public Entity
{
public:
    /**
     * @enum STATE
     * @brief Definiuje stany, w jakich może znajdować się gracz.
     *
     * - `stay` - Gracz stoi.
     * - `walk` - Gracz chodzi.
     * - `jump` - Gracz skacze.
     */
    enum { stay, walk, jump } STATE;

    int cash; /**< Liczba monet zebranych przez gracza. */
    float sx; /**< Prędkość w osi X. */
    float sy; /**< Prędkość w osi Y. */
    std::map<std::string, bool> key; /**< Mapa stanów klawiszy kontrolujących ruch gracza. */
    int life; /**< Liczba żyć gracza. */
    float lifeCooldown; /**< Czas od ostatniej utraty życia. */

    /**
     * @brief Konstruktor klasy Player.
     *
     * Tworzy obiekt gracza, ustawiając animacje, pozycję oraz poziom, na którym się znajduje.
     *
     * @param a Obiekt AnimationManager zarządzający animacjami gracza.
     * @param lev Obiekt Level reprezentujący poziom, na którym gracz się znajduje.
     * @param x Początkowa współrzędna X gracza.
     * @param y Początkowa współrzędna Y gracza.
     */
    Player(AnimationManager& a, Level& lev, int x, int y);

    /**
     * @brief Obsługuje wciśnięcia klawiszy przez gracza.
     *
     * Funkcja rejestruje i przetwarza stany klawiszy sterujących ruchem gracza.
     */
    void Keyboard();

    /**
     * @brief Aktualizuje animacje gracza na podstawie stanu i czasu.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void Animation(float time);

    /**
     * @brief Aktualizuje stan gracza.
     *
     * Odpowiada za obsługę logiki ruchu, kolizji i interakcji gracza z otoczeniem.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void update(float time);

    /**
     * @brief Obsługuje kolizje gracza z innymi obiektami.
     *
     * @param num Numer identyfikujący typ kolizji.
     */
    void Collision(int num);

    /**
     * @brief Pobiera liczbę żyć gracza.
     *
     * @return int Liczba żyć gracza.
     */
    int getLife();

    /**
     * @brief Zmniejsza liczbę żyć gracza o 1.
     */
    void minusLife();

    /**
     * @brief Zwiększa liczbę żyć gracza o 1.
     */
    void addLife();
};

#endif // PLAYER_H
