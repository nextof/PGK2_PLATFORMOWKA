#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <list>
#include <fstream>
#include <sstream>

#include "level.hpp"
#include "animation.hpp"
#include "changelevel.hpp"
#include "coin.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "movingplatform.hpp"
#include "movingplatformY.hpp"
#include "nextlevel.hpp"
#include "spikes.hpp"

using namespace sf;
extern float CheckX, CheckY;
bool RunGame(RenderWindow& window, int& numberLevel);

#endif GAME_H