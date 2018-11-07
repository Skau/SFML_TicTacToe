#pragma once

#include <memory>
#include "SFML/System.hpp"

namespace sf 
{ 
	class RenderWindow;
	class Texture;
	class Sprite;
}

enum class State
{
	X,
	O,
	None
};

class Tile
{
public:
	Tile(sf::Vector2f pos);
	~Tile();

	void render(sf::RenderWindow& renderWindow, sf::Sprite& sprite);

	sf::Vector2f getPosition() { return m_Pos; }

	State getState() const { return m_State; }
	void setState(State newState) { m_State = newState; }

	bool isNone() const { return m_IsNone; }

private:
	State m_State;

	sf::Vector2f m_Pos;
	bool m_IsNone;
	std::unique_ptr<sf::Texture> m_Tex_None;
	std::unique_ptr<sf::Texture> m_Tex_X;
	std::unique_ptr<sf::Texture> m_Tex_O;
};

