#include "Application.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Globals.h"
#include "Map.h"

#include <iostream>

Application::Application() : m_IsRunning{true}
{
	m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "TicTacToe", sf::Style::Titlebar | sf::Style::Close);
}

Application::~Application()
{
	m_Map.reset();
	m_Window.reset();
}

void Application::init()
{
	if (m_Map)
	{
		m_Map.reset();
	}

	m_Map = std::make_unique<Map>(3, 3);
	m_PlayerTurn = false;
	m_IsFinished = false;
	m_SpotsTaken = 0;
	
	mainLoop();
}

void Application::mainLoop()
{
	while (m_IsRunning)
	{
		handleEvents();
		render();
	}
}

void Application::handleEvents()
{
	sf::Event event;
	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window->close();
		}

		if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::R || event.key.code == sf::Keyboard::Space))
		{
			init();
		}

		if (!m_IsFinished)
		{
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
			{
				if (m_Map->setPiece(sf::Mouse::getPosition(*m_Window), m_PlayerTurn))
				{
					m_PlayerTurn = !m_PlayerTurn;
					if (m_Map->isBoardFull())
					{
						m_IsFinished = true;
					}
				}
			}
		}
	}
}

void Application::render() const
{
	m_Window->clear();

	m_Map->render(*m_Window);

	m_Window->display();
}