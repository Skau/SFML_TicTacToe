#include "Application.h"
#include "Globals.h"
#include <SFML/Graphics.hpp>

#include "Map.h"

Application::Application()
{
	m_Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TicTacToe");
}

Application::~Application()
{
	m_Window.reset();
}

void Application::init()
{
	if (m_Map)
		m_Map.reset();

	m_Map = std::make_unique<Map>();
	m_PlayerTurn = false;
	m_IsFinished = false;
	m_SpotsTaken = 0;
	beginPlay();
}

void Application::beginPlay()
{
	mainLoop();
}

void Application::mainLoop()
{
	while (!m_IsFinished)
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
			m_Window->close();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
		{
			init();
		}

		if (m_IsFinished) { return; }


		if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
		{
			if (m_Map->setPiece(sf::Mouse::getPosition(*m_Window), m_PlayerTurn))
			{
				m_PlayerTurn = !m_PlayerTurn;
				m_SpotsTaken++;
				if (m_SpotsTaken == 9 || m_Map->checkWin())
				{
					m_IsFinished = true;
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
