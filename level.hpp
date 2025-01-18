#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml.h"

/**
 * @struct Object
 * @brief Reprezentuje pojedynczy obiekt na poziomie.
 *
 * Obiekt może zawierać właściwości, takie jak nazwa, typ, pozycja oraz dodatkowe parametry.
 */
struct Object
{
    /**
     * @brief Pobiera wartość właściwości jako int.
     * @param name Nazwa właściwości.
     * @return Wartość właściwości jako int.
     */
    int GetPropertyInt(std::string name);

    /**
     * @brief Pobiera wartość właściwości jako float.
     * @param name Nazwa właściwości.
     * @return Wartość właściwości jako float.
     */
    float GetPropertyFloat(std::string name);

    /**
     * @brief Pobiera wartość właściwości jako string.
     * @param name Nazwa właściwości.
     * @return Wartość właściwości jako string.
     */
    std::string GetPropertyString(std::string name);

    std::string name; /**< Nazwa obiektu. */
    std::string type; /**< Typ obiektu. */
    sf::Rect<float> rect; /**< Prostokąt określający pozycję i rozmiar obiektu. */
    std::map<std::string, std::string> properties; /**< Mapa właściwości obiektu. */
    sf::Sprite sprite; /**< Sprite reprezentujący obiekt graficznie. */
};

/**
 * @struct Layer
 * @brief Reprezentuje warstwę kafelków na poziomie.
 */
struct Layer
{
    int opacity; /**< Przezroczystość warstwy (0-255). */
    std::vector<sf::Sprite> tiles; /**< Wektory kafelków na warstwie. */
};

/**
 * @class Level
 * @brief Klasa reprezentująca poziom gry.
 *
 * Obsługuje wczytywanie poziomów z plików, rysowanie poziomów oraz zarządzanie obiektami i warstwami.
 */
class Level
{
public:
    int levelNumber; /**< Numer poziomu. */

    /**
     * @brief Wczytuje poziom z pliku.
     * @param filename Ścieżka do pliku poziomu.
     * @return true Jeśli poziom został wczytany pomyślnie, false w przeciwnym razie.
     */
    bool LoadFromFile(std::string filename);

    /**
     * @brief Pobiera obiekt o podanej nazwie.
     * @param name Nazwa obiektu.
     * @return Obiekt o podanej nazwie.
     */
    Object GetObject(std::string name);

    /**
     * @brief Pobiera listę obiektów o podanej nazwie.
     * @param name Nazwa obiektów do pobrania.
     * @return Wektor obiektów o podanej nazwie.
     */
    std::vector<Object> GetObjects(std::string name);

    /**
     * @brief Pobiera listę obiektów o dwóch podanych nazwach.
     * @param name Pierwsza nazwa obiektów.
     * @param name2 Druga nazwa obiektów.
     * @return Wektor obiektów pasujących do podanych nazw.
     */
    std::vector<Object> GetObjects2(std::string name, std::string name2);

    /**
     * @brief Pobiera wszystkie obiekty z poziomu.
     * @return Wektor wszystkich obiektów.
     */
    std::vector<Object> GetAllObjects();

    /**
     * @brief Pobiera rozmiar pojedynczego kafelka na poziomie.
     * @return Wektor dwuwymiarowy określający szerokość i wysokość kafelka.
     */
    sf::Vector2i GetTileSize();

    /**
     * @brief Rysuje poziom na ekranie.
     * @param window Okno, w którym poziom ma być rysowany.
     */
    void Draw(sf::RenderWindow& window);

private:
    int width; /**< Szerokość poziomu w kafelkach. */
    int height; /**< Wysokość poziomu w kafelkach. */
    int tileWidth; /**< Szerokość pojedynczego kafelka. */
    int tileHeight; /**< Wysokość pojedynczego kafelka. */
    int firstTileID; /**< ID pierwszego kafelka w zestawie. */
    sf::Rect<float> drawingBounds; /**< Obszar rysowania poziomu. */
    sf::Texture tilesetImage; /**< Tekstura zestawu kafelków. */
    std::vector<Object> objects; /**< Wektor wszystkich obiektów na poziomie. */
    std::vector<Layer> layers; /**< Wektor wszystkich warstw poziomu. */
};

#endif // LEVEL_H
