#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Application
{
private:
	RenderWindow m_Window;

	Sprite m_SplashSprite;
	Texture m_SplashTexture;

	void input();
	void update(float deltaTime);
	void draw();
public:
	Application();
	~Application();

	void run();
};

