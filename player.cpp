#pragma once
#include "player.hpp"

Player::Player(AnimationManager& a, Level& lev, int x, int y) :Entity(a, x, y)
{
	option("Player", 0, "stay"); // Ustaw nazwę, prędkość początkową i animację "stay".
	STATE = stay; // Początkowy stan gracza: "stay".
	cash = 0; // Liczba zebranych monet.
	obj = lev.GetAllObjects(); // Pobierz wszystkie obiekty z poziomu dla detekcji kolizji.
	life = 5; // Ustaw początkową liczbę żyć.
	lifeCooldown = 0.0f; // Czas między otrzymywaniem obrażeń.
}

void Player::Keyboard()
{
	// Obsługa ruchu
	if (key["L"] || key["A"])
	{
		dir = 1;
		dx = -0.1;
		if (key["Shift"]) dx = -0.15;
		if (STATE == stay) STATE = walk;
	}

	if (key["R"] || key["D"])
	{
		dir = 0;
		dx = 0.1;
		if (key["Shift"]) dx = 0.15;
		if (STATE == stay) STATE = walk;
	}
	if (key["Space"] || key["W"])
	{
		if (STATE == stay || STATE == walk) { dy = -0.3; STATE = jump; anim.play("jump"); }
	}

	if (!(key["R"] || key["L"] || key["A"] || key["D"]))
	{
		dx = 0;
		if (STATE == walk) STATE = stay;
	}

	// Resetowanie stanów klawiszy.
	key["R"] = key["L"] = key["Space"] = key["Shift"] = key["A"] = key["D"] = key["W"] =  false;
}

void Player::Animation(float time)
{
	// Ustawienie odpowiedniej animacji na podstawie stanu gracza.
	if (STATE == stay) anim.set("stay");
	if (STATE == walk) anim.set("walk");
	if (STATE == jump) anim.set("jump");

	if (dir) anim.flip(1); // Odwrócenie animacji w lewo.
	 
	// Obsługa animacji i logiki śmierci gracza.
	if (isDead == true) {
		dx = 0;
		dy = 0;
		timer += time;
		if (timer > 1000) { life = false; timer = 0; }
		anim.set("hit");
	}

	anim.tick(time); // Aktualizuj animację.
}

void Player::update(float time)
{
	Keyboard();  // Obsługa klawiatury.

	Animation(time); // Aktualizacja animacji.


	dy += 0.00065 * time;	// Dodanie grawitacji do ruchu w osi Y.

	//Aktualizacja pozycji
	x += dx * time;
	Collision(0);

	y += dy * time;
	Collision(1);

	if (lifeCooldown > 0.0f) lifeCooldown -= time;

}

void Player::Collision(int num)
{
	// Kolizja z obiektami 
	for (int i = 0; i < obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{

			if (obj[i].name == "solid")
			{
				if (dy > 0 && num == 1) { y = obj[i].rect.top - h;  dy = 0;   STATE = stay; }
				if (dy < 0 && num == 1) { y = obj[i].rect.top + obj[i].rect.height;  dy = 0; }
				if (dx > 0 && num == 0) { x = obj[i].rect.left - w; }
				if (dx < 0 && num == 0) { x = obj[i].rect.left + obj[i].rect.width; }
			}

			if (obj[i].name == "SlopeLeft")
			{
				FloatRect r = obj[i].rect;
				int y0 = (x + w / 2 - r.left) * r.height / r.width + r.top - h;
				if (y > y0)
					if (x + w / 2 > r.left)
					{
						y = y0; dy = 0; STATE = stay;
					}
			}

			if (obj[i].name == "SlopeRight")
			{
				FloatRect r = obj[i].rect;
				int y0 = -(x + w / 2 - r.left) * r.height / r.width + r.top + r.height - h;
				if (y > y0)
					if (x + w / 2 < r.left + r.width)
					{
						y = y0; dy = 0; STATE = stay;
					}
			}
			if (obj[i].name == "CheckPoint")
			{
				sx = x;
				sy = y;
			}

		}
}

int Player::getLife()
{
	return life;
}

void Player::minusLife()
{
	life--;

}

void Player::addLife()
{
	if (life < 3) life++;
}
