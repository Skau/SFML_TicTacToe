#pragma once

#include <vector>
#include <memory>

#include <SFML/System/Vector2.hpp>

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
	Map(int rows, int columns);
	~Map();

	bool setPiece(sf::Vector2i mousePos, bool playerTurn);

	void render(sf::RenderWindow& renderWindow) const;

	bool isBoardFull() { return m_SpotsTaken >= m_Rows * m_Columns; }

private:
	int m_Rows, m_Columns;

	int m_SpotsTaken;

	std::unique_ptr<sf::Sprite> m_Sprite;
	std::vector<std::vector<std::shared_ptr<Tile>>> m_Grid;
};

