#ifndef GAME_H_
#define GAME_H_

class Graphics;

class Game {
public:
	Game();
	~Game();

private:
	void eventLoop();
	void update();
	void draw(Graphics& graphics);
};

#endif // GAME_H_
