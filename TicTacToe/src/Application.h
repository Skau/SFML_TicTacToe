#pragma once

#include <memory>
#include <vector>

namespace sf { class RenderWindow; }

class Map;

class Application
{
public:
	Application();
	~Application();

	void init();

private:
	void beginPlay();
	void mainLoop();
	void handleEvents();
	void render() const;

	std::unique_ptr<sf::RenderWindow> m_Window;
	std::unique_ptr<Map> m_Map;
	
	bool m_PlayerTurn;
	bool m_IsFinished;
	int m_SpotsTaken;
};

