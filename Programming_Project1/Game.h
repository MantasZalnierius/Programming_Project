#ifndef GAME
#define GAME

#include "Player.h"   // include Player header file
#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.
	sf::RenderWindow m_window;
	sf::RectangleShape onScreenArea;
	Player player;
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	bool m_exitGame;
	int m_score;

public:	  // declaration of member functions	
	Game(); // default constructor
	~Game();
	void	loadContent();
	void	update(sf::Time t_deltaTime);
	void	run();
	void	render();
	void	processEvents();
};

#endif