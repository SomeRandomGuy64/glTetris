#pragma once

enum class GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
};

class Game {
public:
	// game state
	GameState		state{};
	bool			keys[1024]{};
	unsigned int	width{};
	unsigned int	height{};

	// constructor / desctructor
	Game(unsigned int width, unsigned int height);
	~Game();

	// initialise game state
	void init();

	// game loop
	void processInput(float dt);
	void update(float dt);
	void render();
};