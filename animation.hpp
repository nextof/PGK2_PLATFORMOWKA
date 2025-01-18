#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "tinyxml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * @file animation.h
 * @brief Deklaracja klas Animation oraz AnimationManager do zarządzania animacjami w grze.
 */

 /**
  * @class Animation
  * @brief Klasa reprezentująca pojedynczą animację.
  *
  * Przechowuje informacje o klatkach animacji, szybkości odtwarzania,
  * orientacji (normalna/odwrócona) oraz stan odtwarzania.
  */
class Animation
{
public:
    std::vector<IntRect> frames;        /**< Wektory klatek animacji. */
    std::vector<IntRect> frames_flip;  /**< Wektory klatek odwróconych animacji. */
    float currentFrame;                /**< Aktualna klatka animacji. */
    float speed;                       /**< Szybkość odtwarzania animacji. */
    bool loop;                         /**< Czy animacja jest zapętlona. */
    bool flip;                         /**< Czy animacja jest odwrócona. */
    bool isPlaying;                    /**< Czy animacja jest aktualnie odtwarzana. */
    Sprite sprite;                     /**< Obiekt Sprite używany do wyświetlania animacji. */

    /**
     * @brief Konstruktor domyślny klasy Animation.
     */
    Animation();

    /**
     * @brief Aktualizuje stan animacji na podstawie upływu czasu.
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void tick(float time);
};

/**
 * @class AnimationManager
 * @brief Klasa zarządzająca wieloma animacjami.
 *
 * Umożliwia wczytywanie animacji z pliku XML, zarządzanie ich stanami
 * i rysowanie na ekranie.
 */
class AnimationManager
{
public:
    std::string currentAnim;                    /**< Nazwa aktualnie odtwarzanej animacji. */
    std::map<std::string, Animation> animList; /**< Lista wszystkich animacji. */

    /**
     * @brief Konstruktor domyślny klasy AnimationManager.
     */
    AnimationManager();

    /**
     * @brief Destruktor klasy AnimationManager.
     */
    ~AnimationManager();

    /**
     * @brief Wczytuje animacje z pliku XML.
     * @param fileName Ścieżka do pliku XML z definicją animacji.
     * @param t Tekstura używana przez animacje.
     */
    void loadFromXML(std::string fileName, Texture& t);

    /**
     * @brief Ustawia aktualną animację na podstawie jej nazwy.
     * @param name Nazwa animacji.
     */
    void set(std::string name);

    /**
     * @brief Rysuje aktualną animację w oknie gry.
     * @param window Obiekt RenderWindow, w którym animacja będzie rysowana.
     * @param x Pozycja X rysowanej animacji.
     * @param y Pozycja Y rysowanej animacji.
     */
    void draw(RenderWindow& window, int x, int y);

    /**
     * @brief Ustawia, czy animacja ma być odwrócona.
     * @param b Wartość logiczna wskazująca odwrócenie.
     */
    void flip(bool b);

    /**
     * @brief Aktualizuje stan animacji na podstawie upływu czasu.
     * @param time Czas, który upłynął od ostatniej aktualizacji.
     */
    void tick(float time);

    /**
     * @brief Zatrzymuje aktualną animację.
     */
    void pause();

    /**
     * @brief Wznawia odtwarzanie aktualnej animacji.
     */
    void play();

    /**
     * @brief Odtwarza wskazaną animację.
     * @param name Nazwa animacji do odtworzenia.
     */
    void play(std::string name);

    /**
     * @brief Sprawdza, czy aktualna animacja jest odtwarzana.
     * @return true Jeśli animacja jest odtwarzana.
     * @return false Jeśli animacja jest zatrzymana.
     */
    bool isPlaying();

    /**
     * @brief Pobiera wysokość aktualnej animacji.
     * @return float Wysokość animacji.
     */
    float getH();

    /**
     * @brief Pobiera szerokość aktualnej animacji.
     * @return float Szerokość animacji.
     */
    float getW();
};

#endif // ANIMATION_H
