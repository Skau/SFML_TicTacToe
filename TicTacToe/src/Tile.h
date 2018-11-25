#pragma once

#include <memory>
#include <vector>

#include <SFML/System/Vector2.hpp>

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

	inline sf::Vector2f getPosition() const { return m_Pos; }

	inline State getState() const { return m_State; }
	inline void setState(State newState) { m_State = newState; }

	inline bool isNone() const { return m_State == State::None; }

private:
	State m_State;

	sf::Vector2f m_Pos;

	std::vector<std::unique_ptr<sf::Texture>> m_Textures;
};