#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "animation.hpp"
#include "level.hpp"

using namespace sf;

/**
 * @file entity.h
 * @brief Deklaracja klasy abstrakcyjnej Entity reprezentującej bazowy obiekt gry.
 */

 /**
  * @class Entity
  * @brief Klasa bazowa dla wszystkich obiektów gry.
  *
  * Klasa abstrakcyjna, która definiuje podstawowe właściwości i metody wspólne dla wszystkich
  * obiektów gry, takich jak pozycja, wymiary, kolizje, animacje i stan życia.
  */
class Entity
{
public:
    float x; /**< Współrzędna X obiektu. */
    float y; /**< Współrzędna Y obiektu. */
    float dx; /**< Prędkość w osi X. */
    float dy; /**< Prędkość w osi Y. */
    float w; /**< Szerokość obiektu. */
    float h; /**< Wysokość obiektu. */
    AnimationManager anim; /**< Menedżer animacji przypisany do obiektu. */
    std::vector<Object> obj; /**< Obiekty z poziomu gry, z którymi może wchodzić w interakcję. */
    bool life; /**< Flaga określająca, czy obiekt jest aktywny (żyje). */
    bool dir; /**< Kierunek poruszania się obiektu. */
    float timer; /**< Licznik czasu używany do różnych działań. */
    float timer_end; /**< Czas końcowy do określonych zdarzeń. */
    std::string Name; /**< Nazwa obiektu. */
    bool isDead; /**< Flaga określająca, czy obiekt jest martwy. */

    /**
     * @brief Konstruktor klasy Entity.
     *
     * Inicjalizuje obiekt na podstawie animacji oraz początkowej pozycji.
     *
     * @param A Obiekt AnimationManager zarządzający animacjami obiektu.
     * @param X Początkowa współrzędna X obiektu.
     * @param Y Początkowa współrzędna Y obiektu.
     */
    Entity(AnimationManager& A, int X, int Y);

    /**
     * @brief Wirtualna metoda aktualizująca stan obiektu.
     *
     * Funkcja musi być zdefiniowana w klasach dziedziczących.
     *
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    virtual void update(float time) = 0;

    /**
     * @brief Rysuje obiekt na ekranie.
     *
     * @param window Obiekt RenderWindow, w którym rysowany jest obiekt.
     */
    void draw(RenderWindow& window);

    /**
     * @brief Pobiera prostokąt kolizji obiektu.
     *
     * @return FloatRect Prostokąt opisujący obszar kolizji obiektu.
     */
    FloatRect getRect();

    /**
     * @brief Ustawia opcje dla obiektu.
     *
     * @param NAME Nazwa obiektu.
     * @param SPEED Szybkość poruszania się obiektu.
     * @param FIRST_ANIM Nazwa początkowej animacji obiektu.
     */
    void option(std::string NAME, float SPEED, std::string FIRST_ANIM);

    /**
     * @brief Destruktor klasy Entity.
     */
    virtual ~Entity();
};

#endif // ENTITY_H
