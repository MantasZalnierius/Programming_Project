
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file

int main()
{
	srand(time(NULL)); // This is the random seed.
	Game game;
	game.loadContent();
	game.run();
	return 0;
}

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
	screenArea.setSize(sf::Vector2f{ static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT) });
	m_score = 0;
	cooldown = 0;
}

Game::~Game()
{
}

void Game::loadContent()
// load the font file & setup the message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_firstEnemyFollowerHealth.setFont(m_font);  // set the font for the text
	m_firstEnemyFollowerHealth.setCharacterSize(24); // set the text size
	m_firstEnemyFollowerHealth.setFillColor(sf::Color::White); // set the text colour
	m_firstEnemyFollowerHealth.setPosition(0, 0);  // its position on the screen
	m_firstEnemyFollowerHealth.setString("First Enemy Follower Health: " + std::to_string(enemyFollower1.getHealth()));

	m_playerHealth.setFont(m_font);  // set the font for the text
	m_playerHealth.setCharacterSize(24); // set the text size
	m_playerHealth.setFillColor(sf::Color::White); // set the text colour
	m_playerHealth.setPosition(0, 500);  // its position on the screen
	m_playerHealth.setString("Player Health: " + std::to_string(player.getHealth()));

	m_playerScore.setFont(m_font);  // set the font for the text
	m_playerScore.setCharacterSize(24); // set the text size
	m_playerScore.setFillColor(sf::Color::White); // set the text colour
	m_playerScore.setPosition(0, 350);  // its position on the screen
	m_playerScore.setString("Player Score: " + std::to_string(m_score));

	m_secondEnemyFollowerHealth.setFont(m_font);  // set the font for the text
	m_secondEnemyFollowerHealth.setCharacterSize(24); // set the text size
	m_secondEnemyFollowerHealth.setFillColor(sf::Color::White); // set the text colour
	m_secondEnemyFollowerHealth.setPosition(0, 150);  // its position on the screen
	m_secondEnemyFollowerHealth.setString("Second Enemy Follower Health: " + std::to_string(enemyFollower2.getHealth()));



	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "Did load floor file ";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);

}

void Game::processEvents()
{
	sf::Event event; // This initialize's, the Event object into memory.
	while (m_window.pollEvent(event))
	{

		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close(); // This closes the window.
		}

		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code) // This checks if the user escaped the game.
			{
				m_exitGame = true; // This sets the bool to true.
			}

		}
	}
}
void Game::run()
{
	
	sf::Clock clock; // This initialize's the Clock object into memory.
	sf::Time timeSinceLastUpdate = sf::Time::Zero; // This lets the Time object equal to Zero.
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	sf::Vector2f poistionEnemy1{ 400.0f, -400.0f };
	sf::Vector2f postiionEnemy2{ 1000.0f, 600.0f };
	cooldown = player.getCooldown();

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart(); // This adds zero to the Time object.
		while (timeSinceLastUpdate > timePerFrame)  // This while loop will run every time, the times update is greater than the time per frame of the program.
		{
			timeSinceLastUpdate -= timePerFrame; // This substracts the time per frame, from the last update of time for this program.
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::update(sf::Time t_deltaTime)
{
	updateText();
	player.move();
	player.boundaryCollision();

	enemyFollower1.move(player.getBody().getPosition());
	enemyFollower2.move(player.getBody().getPosition());
	enemyFollower1.playerCollision(player.getBody());
	enemyFollower2.playerCollision(player.getBody());

	player.enemyFollowerCollision(enemyFollower1.getBody());
	player.enemyFollowerCollision(enemyFollower2.getBody());

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemies[i].move();
	}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (player.getCooldown() <= 0)
			{
					if (bullets[i].setDirection(screenArea, player.getBody(), player.getLookDirection(), cooldown))
					{
						player.setCooldown(100);
						break;
					}
			}
			else
			{
				player.setCooldown(player.getCooldown() - 1);
			}
		}
	

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].move(screenArea, player.getBody(), player.getLookDirection());
	}
	

	


	for (int i = 0; i < MAX_BULLETS; i++)
	{
		enemyFollower1.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
		enemyFollower2.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
		bullets[i].enemyFollowerCollision(enemyFollower1.getBody());
		bullets[i].enemyFollowerCollision(enemyFollower2.getBody());
	}

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			bullets[i].enemyCollision(enemies[j].getBody());
			player.enemyCollision(enemies[j].getBody());
		}
	}
}

void Game::updateText()
{
	m_firstEnemyFollowerHealth.setString("Enemy Follower Health: " + std::to_string(enemyFollower1.getHealth()));
	m_secondEnemyFollowerHealth.setString("Second Enemy Follower Health: " + std::to_string(enemyFollower2.getHealth()));
	m_playerHealth.setString("Player Health: " + std::to_string(player.getHealth()));
	m_playerScore.setString("Player Score: " + std::to_string(m_score));
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	m_window.draw(player.getBody());
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		m_window.draw(enemies[i].getBody());
	}
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bullets[i].getStatus())
		{
			m_window.draw(bullets[i].getBody());
		}
	}
	m_window.draw(enemyFollower1.getBody());
	m_window.draw(enemyFollower2.getBody());
	m_window.draw(m_playerHealth);
	m_window.draw(m_firstEnemyFollowerHealth);
	m_window.draw(m_secondEnemyFollowerHealth);
	m_window.draw(m_playerScore);
	m_window.display();
}

