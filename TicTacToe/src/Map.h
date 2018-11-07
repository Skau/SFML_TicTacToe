#pragma once

#include <vector>
#include <memory>
#include "SFML/System.hpp"

namespace sf 
{ 
	class RenderWindow; 
	class Sprite;
	class Texture;
}

class Tile;

class Map
{
public:
	Map();
	~Map();

	bool setPiece(sf::Vector2i mousePos, bool playerTurn);

	void render(sf::RenderWindow& renderWindow) const;

	bool checkWin();
private:
	std::unique_ptr<sf::Sprite> m_Sprite;
	std::vector<std::vector<std::shared_ptr<Tile>>> m_Grid;
};

