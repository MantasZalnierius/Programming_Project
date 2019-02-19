
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

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default),
m_exitGame{ false }
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

	m_Gameplay.setFont(m_font);  // set the font for the text
	m_Gameplay.setCharacterSize(24); // set the text size
	m_Gameplay.setFillColor(sf::Color::White); // set the text colour
	m_Gameplay.setPosition(250, 150);  // its position on the screen
	m_Gameplay.setString("New Game: Press 1 to play the game. ");

	m_help.setFont(m_font);  // set the font for the text
	m_help.setCharacterSize(24); // set the text size
	m_help.setFillColor(sf::Color::White); // set the text colour
	m_help.setPosition(250, 300);  // its position on the screen
	m_help.setString("Controls: Press 2 to see the rules of the game. ");

	m_exit.setFont(m_font);  // set the font for the text
	m_exit.setCharacterSize(24); // set the text size
	m_exit.setFillColor(sf::Color::White); // set the text colour
	m_exit.setPosition(250, 450);  // its position on the screen
	m_exit.setString("Exit: Press 3 to exit the game ");

	m_GameObjectiveHelpText.setFont(m_font);  // set the font for the text
	m_GameObjectiveHelpText.setCharacterSize(24); // set the text size
	m_GameObjectiveHelpText.setFillColor(sf::Color::White); // set the text colour
	m_GameObjectiveHelpText.setPosition(250, 450);  // its position on the screen
	m_GameObjectiveHelpText.setString("Exit: Press 3 to exit the game ");

	m_playerHelpText.setFont(m_font);  // set the font for the text
	m_playerHelpText.setCharacterSize(24); // set the text size
	m_playerHelpText.setFillColor(sf::Color::White); // set the text colour
	m_playerHelpText.setPosition(160, 100);  // its position on the screen
	m_playerHelpText.setString("You Can Move the Player using the The arrow keys W, S, A and D \n You can shoot by pressing the spacebar Key ");

	m_enemyFollowerHelpText.setFont(m_font);  // set the font for the text
	m_enemyFollowerHelpText.setCharacterSize(24); // set the text size
	m_enemyFollowerHelpText.setFillColor(sf::Color::White); // set the text colour
	m_enemyFollowerHelpText.setPosition(120, 200);  // its position on the screen
	m_enemyFollowerHelpText.setString("This is a enemey follower.\n This will follow you and when he touches off you it will damage you.\n When you hit this enemy with a bullet it will damage it.\n When it loses all health it will respawn randomly on the top of the screen.\n This enemy will grant you 5 points when you destroy one of the enemy ");

	m_bouncingEenemyHelpText.setFont(m_font);  // set the font for the text
	m_bouncingEenemyHelpText.setCharacterSize(24); // set the text size
	m_bouncingEenemyHelpText.setFillColor(sf::Color::White); // set the text colour
	m_bouncingEenemyHelpText.setPosition(130, 400);  // its position on the screen
	m_bouncingEenemyHelpText.setString("This is a bouncing enemy. These enemies are invincable.\n They move and bounce off the walls.\n When they collide with the player, the player will lose health.\n They will absorb bullets but won't lose any life");

	m_HelpText.setFont(m_font);  // set the font for the text
	m_HelpText.setCharacterSize(24); // set the text size
	m_HelpText.setFillColor(sf::Color::White); // set the text colour
	m_HelpText.setPosition(290, 530);  // its position on the screen
	m_HelpText.setString("Press 4 to return to Menu ");

	m_highestScore.setFont(m_font);  // set the font for the text
	m_highestScore.setCharacterSize(24); // set the text size
	m_highestScore.setFillColor(sf::Color::White); // set the text colour
	m_highestScore.setPosition(250, 150);  // its position on the screen
	m_highestScore.setString("Higest Score: " + std::to_string(higestScore));

	m_currentScore.setFont(m_font);  // set the font for the text
	m_currentScore.setCharacterSize(24); // set the text size
	m_currentScore.setFillColor(sf::Color::White); // set the text colour
	m_currentScore.setPosition(250, 300);  // its position on the screen
	m_currentScore.setString("Current Score " + std::to_string(currentScore));

	m_gameOverText.setFont(m_font);  // set the font for the text
	m_gameOverText.setCharacterSize(24); // set the text size
	m_gameOverText.setFillColor(sf::Color::White); // set the text colour
	m_gameOverText.setPosition(250, 450);  // its position on the screen
	m_gameOverText.setString("Press 5 to go back to the main menu ");



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
				m_exitGame = true;// This sets the bool to true.
			}

		}
	}
}
void Game::run()
{
	
	sf::Clock clock; // This initialize's the Clock object into memory.
	sf::Time timeSinceLastUpdate = sf::Time::Zero; // This lets the Time object equal to Zero.
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	helpPlayer.setUpHelpPlayer(sf::Vector2f{ 100.0f, 100.0f });
	enemyFollowerHelp.setUpEnemeyFollowerPoistionHelp(sf::Vector2f{ 50.0f, 200.0f });
	enemiesHelp.setUpEnemyHelp(sf::Vector2f{ 70.0f, 400.0f });
		
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
	if (m_exitGame)
	{
		m_window.close();
	}
	if (GameScreen == GameStates::MainMenu)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			GameScreen = GameStates::GamePlay;
		}
	}

	if (GameScreen == GameStates::MainMenu)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			GameScreen = GameStates::Help;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			GameScreen = GameStates::Exit;
		}
	}

	if (GameScreen == GameStates::Exit)
	{
		m_exitGame = true;
	}

	if(GameScreen == GameStates::Help)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu;
		}
	}

	if (GameScreen == GameStates::GameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu;
			player.setUpPlayer();
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].setUpEnemy();
			}
			enemyFollower1.setUpEnemyFollower();
			enemyFollower2.setUpEnemyFollower();
		}
	}
	if (GameScreen == GameStates::GamePlay)
	{
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (player.getCooldown() <= 0)
			{
				for (int i = 0; i < MAX_BULLETS; i++)
				{
					if (bullets[i].setDirection(screenArea, player.getBody(), player.getLookDirection(), cooldown))
					{
						player.setCooldown(10);
						break;
					}
				}
			}
			else
			{
				player.setCooldown(player.getCooldown() - 1);
			}
		}

		if (player.getHealth() <= 0)
		{
				GameScreen = GameStates::GameOver;
				currentScore = m_score;
				if (currentScore > higestScore)
				{
					higestScore = currentScore;
					m_score = 0;
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
	
}

void Game::updateText()
{
	if (GameScreen == GameStates::GamePlay)
	{
		m_firstEnemyFollowerHealth.setString("Enemy Follower Health: " + std::to_string(enemyFollower1.getHealth()));
		m_secondEnemyFollowerHealth.setString("Second Enemy Follower Health: " + std::to_string(enemyFollower2.getHealth()));
		m_playerHealth.setString("Player Health: " + std::to_string(player.getHealth()));
		m_playerScore.setString("Player Score: " + std::to_string(m_score));
	}

	if (GameScreen == GameStates::GameOver)
	{
		m_highestScore.setString("Higest Score: " + std::to_string(higestScore));
		m_currentScore.setString("Current Score " + std::to_string(currentScore));
	}

	if (GameScreen == GameStates::MainMenu)
	{
		m_Gameplay.move(0, ySpeed);
		m_help.move(0, ySpeeds);
		m_exit.move(0, ySpeedss);

		if (m_Gameplay.getPosition().y == 130 && !changedSpeed)
		{
			ySpeed *= -1;
			changedSpeed = true;
		}
		if (m_Gameplay.getPosition().y == 150 && changedSpeed)
		{
			ySpeed *= -1;
			changedSpeed = false;
		}

		if (m_help.getPosition().y == 280 && !changedSpeedx)
		{
			ySpeeds *= -1;
			changedSpeedx = true;
		}

		if (m_help.getPosition().y == 300 && changedSpeedx)
		{
			ySpeeds *= -1;
			changedSpeedx = false;
		}

		if (m_exit.getPosition().y == 430 && !changedSpeedy)
		{
			ySpeedss *= -1;
			changedSpeedy = true;
		}

		if (m_exit.getPosition().y == 450 && changedSpeedy)
		{
			ySpeedss *= -1;
			changedSpeedy = false;
		}
	}
	

	
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	if (GameScreen == GameStates::Help)
	{
		m_window.draw(helpPlayer.getBody());
		m_window.draw(enemyFollowerHelp.getBody());
		m_window.draw(enemiesHelp.getBody());
		m_window.draw(m_playerHelpText);
		m_window.draw(m_enemyFollowerHelpText);
		m_window.draw(m_bouncingEenemyHelpText);
		m_window.draw(m_HelpText);
	}
	if (GameScreen == GameStates::GameOver)
	{
		m_window.draw(m_currentScore);
		m_window.draw(m_highestScore);
		m_window.draw(m_gameOverText);
	}
	if (GameScreen == GameStates::MainMenu)
	{
		m_window.draw(m_Gameplay);
		m_window.draw(m_help);
		m_window.draw(m_exit);
	}
	if (GameScreen == GameStates::GamePlay)
	{
		m_window.draw(player.getBody());
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			m_window.draw(enemies[i].getBody());
		}
		for (int i = 0; i < MAX_BULLETS; i++)
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
	}
	
	m_window.display();
}

