#pragma once
#ifndef CHANGELEVEL_H
#define CHANGELEVEL_H

#include "level.hpp"

/**
 * @file changelevel.h
 * @brief Deklaracja funkcji zmieniającej poziom gry.
 */

 /**
  * @brief Zmienia poziom gry na podstawie przekazanego numeru poziomu.
  *
  * Funkcja aktualizuje obiekt poziomu oraz numer poziomu w grze.
  * Może być wykorzystywana do przechodzenia pomiędzy różnymi etapami rozgrywki.
  *
  * @param lvl Obiekt klasy Level reprezentujący aktualny poziom.
  * @param numberLevel Numer poziomu, na który gra ma zostać zmieniona (referencja).
  */
void changeLevel(Level& lvl, int& numberLevel);

#endif // CHANGELEVEL_H
