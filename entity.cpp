#pragma once
#include "entity.hpp"

Entity::Entity(AnimationManager& A, int X, int Y)
{
	anim = A; // Przypisanie menedżera animacji.
	x = X; // Ustawienie pozycji X.
	y = Y; // Ustawienie pozycji Y.
	dir = 0; // Domyślny kierunek ruchu.

	isDead = false; // Obiekt początkowo jest żywy.
	life = true; // Obiekt jest aktywny.
	timer = 0; // Zerowanie licznika czasu.
	timer_end = 0; // Zerowanie licznika końca działania.
	dx = dy = 0; // Brak początkowego ruchu.
}

void Entity::draw(RenderWindow& window)
{
	anim.draw(window, x, y + h); // Wywołanie rysowania animacji na pozycji obiektu.
}

FloatRect Entity::getRect()
{
	return FloatRect(x, y, w, h); // Prostokąt o wymiarach obiektu.
}

void Entity::option(std::string NAME, float SPEED = 0, std::string FIRST_ANIM = "")
{
	Name = NAME; // Ustawienie nazwy obiektu.
	if (FIRST_ANIM != "") anim.set(FIRST_ANIM); // Ustawienie początkowej animacji, jeśli podano.
	w = anim.getW(); // Pobranie szerokości animacji.
	h = anim.getH(); // Pobranie wysokości animacji.
	dx = SPEED; // Ustawienie prędkości ruchu w osi X.
}

Entity::~Entity() {}
