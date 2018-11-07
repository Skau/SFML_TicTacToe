#include "Tile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Tile::Tile(sf::Vector2f pos) : m_Pos{ pos }, m_State { State::None }
{
	m_Tex_None = std::make_unique<sf::Texture>();
	m_Tex_X = std::make_unique<sf::Texture>();
	m_Tex_O = std::make_unique<sf::Texture>();

	if (!m_Tex_None->loadFromFile("res/none.png"))
	{
		std::cout << "Could not find m_Tex_None image!\n";
	}

	if (!m_Tex_X->loadFromFile("res/x.png"))
	{
		std::cout << "Could not find m_Tex_X image!\n";
	}

	if (!m_Tex_O->loadFromFile("res/o.png"))
	{
		std::cout << "Could not find m_Tex_O image!\n";
	}
}

Tile::~Tile()
{
	m_Tex_None.reset();
	m_Tex_X.reset();
	m_Tex_O.reset();
}

void Tile::render(sf::RenderWindow & renderWindow, sf::Sprite& sprite)
{
	switch (m_State)
	{
	case State::None:
		sprite.setTexture(*m_Tex_None);
		break;
	case State::X:
		sprite.setTexture(*m_Tex_X);
		break;
	case State::O:
		sprite.setTexture(*m_Tex_O);
		break;
	}
	sprite.setPosition(m_Pos);
	renderWindow.draw(sprite);
}
