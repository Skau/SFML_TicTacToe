#include "Map.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Globals.h"
#include "Tile.h"

Map::Map(int rows, int columns) 
	: m_Rows{rows}, m_Columns{columns}
{
	m_Sprite = std::make_unique<sf::Sprite>();

	m_Grid.resize(m_Rows, std::vector<std::shared_ptr<Tile>>(m_Columns));

	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Grid[i][j] = std::make_shared<Tile>(sf::Vector2f((float)i * OFFSET, (float)j * OFFSET));
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Grid[i][j].reset();
			m_Grid[i][j] = nullptr;
		}
	}
	m_Grid.clear();

	m_Sprite.reset();
	m_Sprite = nullptr;
}

bool Map::setPiece(sf::Vector2i mousePos, bool playerTurn)
{
	auto tile = m_Grid[mousePos.x / OFFSET][mousePos.y / OFFSET];
	if (!tile) { return false; }

	if (tile->isNone())
	{
		tile->setState(static_cast<State>(playerTurn));
		m_SpotsTaken++;
		return true;
	}
	return false;
}

void Map::render(sf::RenderWindow& renderWindow) const
{
	for (int i = 0; i < m_Rows; ++i)
	{
		for (int j = 0; j < m_Columns; ++j)
		{
			m_Grid[i][j]->render(renderWindow, *m_Sprite);
		}
	}
}