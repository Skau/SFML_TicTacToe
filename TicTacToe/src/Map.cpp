#include "Map.h"
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Tile.h"

#include <iostream>

Map::Map()
{

	m_Sprite = std::make_unique<sf::Sprite>();

	m_Grid.resize(3, std::vector<std::shared_ptr<Tile>>(3));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_Grid[i][j] = std::make_shared<Tile>(sf::Vector2f((float)i * OFFSET, (float)j * OFFSET));
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_Grid[i][j].reset();
		}
	}

	m_Grid.clear();
}

bool Map::setPiece(sf::Vector2i mousePos, bool playerTurn)
{
	auto newState = static_cast<State>(playerTurn);
	auto oldState = m_Grid[mousePos.x / OFFSET][mousePos.y / OFFSET]->getState();

	if (oldState == State::None)
	{
		m_Grid[mousePos.x / OFFSET][mousePos.y / OFFSET]->setState(newState);
		return true;
	}
	return false;
}

void Map::render(sf::RenderWindow& renderWindow) const
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_Grid[i][j]->render(renderWindow, *m_Sprite);
		}
	}
}

bool Map::checkWin()
{
	return false;
}
