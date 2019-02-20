
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

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "Did load floor file ";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);

	SetupText(m_playerHealth, sf::Vector2f{ 0.0f, 500.0f }, playerHealthString);
	SetupText(m_playerScore,  sf::Vector2f{ 0.0f, 350.0f }, playerScoreString);
	SetupText(m_Gameplay,   sf::Vector2f{ 250.0f, 150.0f }, mainMenuStartGameString);
	SetupText(m_help, sf::Vector2f{ 250.0f, 300.0f }, MainMenuHelpText);
	SetupText(m_exit, sf::Vector2f{ 250.0f, 450.0f }, mainMenuExitString);
	SetupText(m_GameObjectiveHelpText, sf::Vector2f{ 250.0f, 450.0f }, returnToMainMenuString);
	SetupText(m_playerHelpText, sf::Vector2f{ 160.0f, 100.0f }, PlayerHelpString);
	SetupText(m_enemyFollowerHelpText, sf::Vector2f{ 120.0f, 200.0f }, EnemyFollowerHelpString);
	SetupText(m_bouncingEenemyHelpText, sf::Vector2f{ 130.0f, 400.0f }, bouncingEnemyHelpString);
	SetupText(m_HelpText, sf::Vector2f{ 290.0f, 530.0f }, returnToMainMenuString);
	SetupText(m_highestScore, sf::Vector2f{ 250.0f, 150.0f }, highestScoreString);
	SetupText(m_currentScore, sf::Vector2f{ 250.0f, 300.0f }, currnetScoreString);
	SetupText(m_gameOverText, sf::Vector2f{ 250.0f, 450.0f }, returnToMainMenuString);
}


void Game::SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence)
{
	t_text.setFont(m_font);  // set the font for the text
	t_text.setCharacterSize(24); // set the text size
	t_text.setFillColor(sf::Color::White); // set the text colour
	t_text.setPosition(t_position);  // its position on the screen
	t_text.setString(t_textSentence);
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

