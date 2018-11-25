#include "Tile.h"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

Tile::Tile(sf::Vector2f pos) : m_Pos{ pos }, m_State{ State::None }
{
	m_Textures.emplace_back(std::make_unique<sf::Texture>());

	if (!m_Textures[0]->loadFromFile("res/x.png"))
	{
		std::cout << "Could not find m_Tex_X image!\n";
	}

	m_Textures.emplace_back(std::make_unique<sf::Texture>());

	if (!m_Textures[1]->loadFromFile("res/o.png"))
	{
		std::cout << "Could not find m_Tex_O image!\n";
	}

	m_Textures.emplace_back(std::make_unique<sf::Texture>());

	if (!m_Textures[2]->loadFromFile("res/none.png"))
	{
		std::cout << "Could not find m_Tex_None image!\n";
	}
}

Tile::~Tile()
{
	for (auto& texture : m_Textures)
	{
		texture.reset();
		texture = nullptr;
	}
	m_Textures.clear();
}

void Tile::render(sf::RenderWindow & renderWindow, sf::Sprite& sprite)
{
	sprite.setPosition(m_Pos);

	sprite.setTexture(*m_Textures[static_cast<int>(m_State)]);

	renderWindow.draw(sprite);
}