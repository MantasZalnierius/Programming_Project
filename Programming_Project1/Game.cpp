
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
	Game game; // This makes an instance of the game class.
	game.loadContent();
	game.run();
	return 0;
}

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default),
m_exitGame{ false }
// Default constructor
{
	// This sets up the game.
	setUpGame();
	setUpStrings();
	setUpSoundsAndMusic();
}

Game::~Game()
{
}

/// <summary>
/// This sets up the game.
/// </summary>
void Game::setUpGame()
{
	m_ySpeedForNewGameText = -0.5; // This sets the speed of the new game text.
	m_ySpeedForHelpText = -0.5; // This sets the speed of the help text.
	m_ySpeedForExitText = -0.5; // This sets the speed of the exit text.

	m_changedSpeedOnNewGameText = false; // This sets the bool to false.
	m_changedSpeedOnHelpText = false; // This sets the bool to false.
	m_changedSpeedOnExitText = false; // This sets the bool to false.

	m_speedOfText = -1; // This sets the speed of the text.

	m_higestScore = 0; // This sets the highest score.
	m_currentScore = 0; // This sets the current score.

	m_score = 0; // This sets the score of the player.
}
/// <summary>
/// This sets up all the std::strings.
/// </summary>
void Game::setUpStrings()
{
	m_playerHealthString = "Health: " + std::to_string(player.getHealth()); // This sets a string.
	m_playerScoreString = "Player Score: " + std::to_string(m_score); // This sets a string.
	m_mainMenuHelpText = "Controls: Press 2 to see the rules of the game. "; // This sets a string.
	m_mainMenuStartGameString = "New Game: Press 1 to play the game. "; // This sets a string.
	m_mainMenuExitString = "Exit: Press 3 to exit the game "; // This sets a string.
	m_playerHelpString = "You Can Move the Player using the The arrow keys W, S, A and D \n You can shoot by pressing the spacebar Key ";
	m_enemyFollowerHelpString = "This is a enemey follower.\n This will follow you and when he touches off you it will damage you.\n When you hit this enemy with a bullet it will damage it.\n When it loses all health it will respawn randomly on the top of the screen.\n This enemy will grant you 5 points when you destroy one of the enemy "; // This sets a string.
	m_bouncingEnemyHelpString = "This is a bouncing enemy. These enemies are invincable.\n They move and bounce off the walls.\n When they collide with the player, the player will lose health.\n They will absorb bullets but won't lose any life"; // This sets a string.
	m_returnToMainMenuString = "Press 4 to return to Menu "; // This sets a string.
	m_currnetScoreString = "Higest Score: " + std::to_string(m_higestScore); // This sets a string.
	m_highestScoreString = "Current Score " + std::to_string(m_currentScore); // This sets a string.
}
/// <summary>
/// This sets up the sound and music.
/// </summary>
void Game::setUpSoundsAndMusic()
{
	if (!m_deathSoundBuffer.loadFromFile("ASSETS/SOUND/Hl2_Rebel-Ragdoll485-573931361.wav"))
	{
		std::cout << "error with the sound file"; // This sets a sound effect.
	}

	m_deathSound.setBuffer(m_deathSoundBuffer); // This sets the sound buffer to the sound effect.

	if (!m_gamePlayMusic.openFromFile("ASSETS/MUSIC/Battle Music.ogg"))
	{
		std::cout << "error with the sound file"; // This sets up music.
	}
	m_gamePlayMusic.setLoop(true); // This sets the loop to true.
	m_gamePlayMusic.setVolume(10); // This sets the voulme.

	if (!m_mainMenuMusic.openFromFile("ASSETS/MUSIC/The Elder Scrolls III - Morrowind - Main.ogg"))
	{
		std::cout << "error with the sound file"; // This sets up music.
	}
	m_mainMenuMusic.setLoop(true); // This sets the loop to true.
	m_mainMenuMusic.setVolume(10); // This sets the voulme.
}
/// <summary>
/// This loads the game.
/// </summary>
void Game::loadContent()
// load the font file & setup the message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file"; // This sets the font for the game.
	}

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "Did load floor file "; // This sets up the background texture.
	}

	m_backgroundSprite.setTexture(m_backgroundTexture); // This sets the texture to the sprite.

	SetupText(m_playerHealth, sf::Vector2f{ player.getBody().getPosition() }, m_playerHealthString);
	SetupText(m_playerScore, sf::Vector2f{ 50.0f, 530.0f }, m_playerScoreString);
	SetupText(m_Gameplay, sf::Vector2f{ 250.0f, 150.0f }, m_mainMenuStartGameString);
	SetupText(m_help, sf::Vector2f{ 250.0f, 300.0f }, m_mainMenuHelpText);
	SetupText(m_exit, sf::Vector2f{ 250.0f, 450.0f }, m_mainMenuExitString);
	SetupText(m_returnToMainMenuText, sf::Vector2f{ 250.0f, 450.0f }, m_returnToMainMenuString);
	SetupText(m_playerHelpText, sf::Vector2f{ 160.0f, 100.0f }, m_playerHelpString);
	SetupText(m_enemyFollowerHelpText, sf::Vector2f{ 120.0f, 200.0f }, m_enemyFollowerHelpString);
	SetupText(m_bouncingEenemyHelpText, sf::Vector2f{ 130.0f, 400.0f }, m_bouncingEnemyHelpString);
	SetupText(m_HelpText, sf::Vector2f{ 290.0f, 530.0f }, m_returnToMainMenuString);
	SetupText(m_highestScoreText, sf::Vector2f{ 250.0f, 150.0f }, m_highestScoreString);
	SetupText(m_currentScoreText, sf::Vector2f{ 250.0f, 300.0f }, m_currnetScoreString);
	SetupText(m_gameOverText, sf::Vector2f{ 250.0f, 450.0f }, m_returnToMainMenuString);
	m_playerHealth.setFillColor(sf::Color::Red);
}
/// <summary>
/// This sets the text up.
/// </summary>
/// <param name="t_text"></param>
/// <param name="t_position"></param>
/// <param name="t_textSentence"></param>
void Game::SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence)
{
	t_text.setFont(m_font);  // set the font for the text
	t_text.setCharacterSize(24); // set the text size
	t_text.setFillColor(sf::Color::White); // set the text colour
	t_text.setPosition(t_position);  // its position on the screen
	t_text.setString(t_textSentence); // This sets the string to the text.
}
/// <summary>
/// This process user created events.
/// </summary>
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
/// <summary>
/// This runs the game.
/// </summary>
void Game::run()
{

	sf::Clock clock; // This initialize's the Clock object into memory.
	sf::Time timeSinceLastUpdate = sf::Time::Zero; // This lets the Time object equal to Zero.
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	PlayerSpriteForTheHelpScreen.setUpPlayerForTheHelpScreen(sf::Vector2f{ 100.0f, 100.0f }); // This sets the position of the playersprite for the help screen.
	enemyFollowerHelp.setUpEnemeyFollowerPoistionHelp(sf::Vector2f{ 50.0f, 200.0f }); // This sets the position of the enemy follower sprite for the help screen.
	enemiesHelp.setUpEnemyForTheHelpScreen(sf::Vector2f{ 70.0f, 400.0f }); // This sets the position of the enemy sprite for the help screen.
	m_mainMenuMusic.play(); // This plays the main menu music.

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
/// <summary>
/// This updates the game every 60th of a second
/// </summary>
/// <param name="t_deltaTime"></param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close(); // This closes the window.
	}

	if (GameScreen == GameStates::Exit)
	{
		m_exitGame = true; // This sets the bool to true.
	}

	updateMainMenuScreen();
	updateHelpScreen();
	updateGamePlayScreen();
	updateGameOverScreen();
}
/// <summary>
/// This updates the game play screen.
/// </summary>
void Game::updateGamePlayScreen()
{
	if (GameScreen == GameStates::GamePlay)
	{
		m_playerHealth.setPosition(player.getBody().getPosition().x - 10, player.getBody().getPosition().y - 20); // This updates the player health text.
		m_playerHealth.setString("Health: " + std::to_string(player.getHealth())); // This updates the player health text.
		m_playerScore.setString("Player Score: " + std::to_string(m_score)); // This updates the player score text.
	}

	if (GameScreen == GameStates::GamePlay)
	{
		player.move();
		player.boundaryCollision();

		player.enemyFollowerCollision(enemyFollower1.getBody());
		player.enemyFollowerCollision(enemyFollower2.getBody());
		enemyFollower1.playerCollision(player.getBody());
		enemyFollower2.playerCollision(player.getBody());

		enemyFollower1.move(player.getBody().getPosition());
		enemyFollower2.move(player.getBody().getPosition());

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
					if (bullets[i].setDirection(player.getBody(), player.getLookDirection()))
					{
						player.setCooldown(10); // This sets the coldwon of the bullets.
						break;
					}
				}
			}
			else
			{
				player.setCooldown(player.getCooldown() - 1); // This subtracts the one from the coldown.
			}
		}

		if (player.getHealth() <= 0)
		{
			m_deathSound.play(); // This plays a sound effect.
			GameScreen = GameStates::GameOver; // This changes the enum.
			m_currentScore = m_score; // This sets the current score to the players score.
			if (m_currentScore > m_higestScore)
			{
				m_higestScore = m_currentScore; // This sets the higest score to the current score.
				m_score = 0; // This sets the player score to zero.
			}
		}


		for (int i = 0; i < MAX_BULLETS; i++)
		{
			bullets[i].move();
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].getStatus())
			{
				enemyFollower1.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
				enemyFollower2.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
				bullets[i].enemyFollowerCollision(enemyFollower1.getBody());
				bullets[i].enemyFollowerCollision(enemyFollower2.getBody());
			}
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
/// <summary>
/// This updates the main menu screen.
/// </summary>
void Game::updateMainMenuScreen()
{
	if (GameScreen == GameStates::MainMenu)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			GameScreen = GameStates::GamePlay; // This changes the enum.
			m_mainMenuMusic.stop(); // This stops the music.
			m_gamePlayMusic.play(); // This plays music.
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			GameScreen = GameStates::Help; // This changes the enum.
			m_mainMenuMusic.play(); // This plays music.
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			GameScreen = GameStates::Exit; // This changes the enum.
		}
	}

	if (GameScreen == GameStates::MainMenu)
	{
		m_Gameplay.move(0, m_ySpeedForNewGameText); // This moves text.
		m_help.move(0, m_ySpeedForHelpText); // This moves text.
		m_exit.move(0, m_ySpeedForExitText); // This moves text.

		if (m_Gameplay.getPosition().y == 130 && !m_changedSpeedOnNewGameText)
		{
			m_ySpeedForNewGameText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnNewGameText = true; // This sets the bool to true.
		}
		if (m_Gameplay.getPosition().y == 150 && m_changedSpeedOnNewGameText)
		{
			m_ySpeedForNewGameText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnNewGameText = false; // This sets the bool to false.
		}

		if (m_help.getPosition().y == 280 && !m_changedSpeedOnHelpText)
		{
			m_ySpeedForHelpText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnHelpText = true; // This sets the bool to true.
		}

		if (m_help.getPosition().y == 300 && m_changedSpeedOnHelpText)
		{
			m_ySpeedForHelpText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnHelpText = false; // This sets the bool to false.
		}

		if (m_exit.getPosition().y == 430 && !m_changedSpeedOnExitText)
		{
			m_ySpeedForExitText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnExitText = true; // This sets the bool to true.
		}

		if (m_exit.getPosition().y == 450 && m_changedSpeedOnExitText)
		{
			m_ySpeedForExitText *= m_speedOfText; // This reverses the way the text is going.
			m_changedSpeedOnExitText = false; // This sets the bool to false.
		}
	}
}
/// <summary>
/// This updates the help screen.
/// </summary>
void Game::updateHelpScreen()
{
	if (GameScreen == GameStates::Help)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu; // This changes the enum.
			m_mainMenuMusic.play(); // This plays music.
		}
	}
}
/// <summary>
/// This updates the game over screen.
/// </summary>
void Game::updateGameOverScreen()
{
	if (GameScreen == GameStates::GameOver)
	{
		m_highestScoreText.setString("Higest Score: " + std::to_string(m_higestScore)); // This updates the higest score.	
		m_currentScoreText.setString("Current Score " + std::to_string(m_currentScore)); // This updates the current scroe.
	}

	if (GameScreen == GameStates::GameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu; // This changes the enum.
			player.setUpPlayer();
			player.loadSpriteAndTexture();
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].setUpEnemy();
			}
			enemyFollower1.setUpEnemyFollower();
			enemyFollower2.setUpEnemyFollower();
			m_gamePlayMusic.stop(); // This stops music playing.
			m_mainMenuMusic.play(); // This plays music.
		}
	}
}
/// <summary>
/// This renders the game.
/// </summary>
void Game::render()
{
	m_window.clear(); // This clears all the screen.

	// This draws everything on screen.
	m_window.draw(m_backgroundSprite);
	drawMainMenuScreen();
	drawHelpScreen();
	drawGamePlayScreen();
	drawGameOverScreen();

	m_window.display(); // This displays everything.
}
/// <summary>
/// This draws the main menu screen.
/// </summary>
void Game::drawMainMenuScreen()
{
	if (GameScreen == GameStates::MainMenu)
	{
		m_window.draw(m_Gameplay);
		m_window.draw(m_help);
		m_window.draw(m_exit);
	}
}
/// <summary>
/// This draws the help screen.
/// </summary>
void Game::drawHelpScreen()
{
	if (GameScreen == GameStates::Help)
	{
		m_window.draw(PlayerSpriteForTheHelpScreen.getBody());
		m_window.draw(enemyFollowerHelp.getBody());
		m_window.draw(enemiesHelp.getBody());
		m_window.draw(m_playerHelpText);
		m_window.draw(m_enemyFollowerHelpText);
		m_window.draw(m_bouncingEenemyHelpText);
		m_window.draw(m_HelpText);
	}
}
/// <summary>
/// This draws the game play screen.
/// </summary>
void Game::drawGamePlayScreen()
{
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
		m_window.draw(m_playerScore);
	}
}
/// <summary>
/// This draws the gamne over screen.
/// </summary>
void Game::drawGameOverScreen()
{
	if (GameScreen == GameStates::GameOver)
	{
		m_window.draw(m_currentScoreText);
		m_window.draw(m_highestScoreText);
		m_window.draw(m_gameOverText);
	}
}
