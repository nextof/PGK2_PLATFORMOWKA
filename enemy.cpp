﻿#pragma once
#include "enemy.hpp"

Enemy::Enemy(AnimationManager& a, Level& lev, int x, int y) :Entity(a, x, y)
{
	option("EasyEnemy", -0.1, "moveLeft");
	obj = lev.GetAllObjects(); // Pobierz wszystkie obiekty z poziomu do obsługi kolizji.
}

void Enemy::update(float time)
{
	Collision(dx, 0);

	x += dx * time;

	if (isDead == true) 
	{
		// Zatrzymaj akywnosc
		if (dx > 0)
			anim.set("deadRight"); 
		if (dx < 0)
			anim.set("deadLeft"); 
		dx = 0; 
		timer += time;
		timer_end += time;
		if (timer_end > 1000) life = false; // Dezaktywuj przeciwnika
	}

	anim.tick(time); // Aktualizuj animację przeciwnika.
}

void Enemy::Collision(float Dx, float Dy)
{
	for (int i = 0; i < obj.size(); i++)
		if (getRect().intersects(obj[i].rect)) // Sprawdź kolizję z obiektem.
		{
			if (obj[i].name == "solid" || (obj[i].name == "Spikes"))
			{
				if (Dy > 0) { y = obj[i].rect.top - h;  dy = 0; }
				if (Dy < 0) { y = obj[i].rect.top + obj[i].rect.height; dy = 0; }
				if (Dx > 0) { x = obj[i].rect.left - w; dx = -0.1; anim.set("moveLeft"); }
				if (Dx < 0) { x = obj[i].rect.left + obj[i].rect.width; dx = 0.1; anim.set("moveRight"); }
			}
		}
}
