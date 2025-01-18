#pragma once
#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "entity.hpp"

class MovingPlatform : public Entity
{
public:
	MovingPlatform(AnimationManager& a, Level& lev, int x, int y);

	void update(float time);
};

#endif MOVINGPLATFORM_H
