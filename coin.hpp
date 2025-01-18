#pragma once
#ifndef COIN_H
#define COIN_H
#include "entity.hpp"
class Coin : public Entity
{
public:
	Coin(AnimationManager& a, Level& lev, int x, int y);
	void update(float time);
};
#endif COIN_H
