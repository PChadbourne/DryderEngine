#include "stdafx.h"
#include "Application.h"


void Application::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}
}

void Application::update(float deltaTime)
{
}

void Application::draw()
{
	m_Window.clear(Color::White);

	m_Window.draw(m_SplashSprite);

	m_Window.display();
}

Application::Application()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Simple Game Engine",
		Style::Fullscreen);

	// Load the background into the texture
	// Be sure to scale this image to your screen size
	m_SplashTexture.loadFromFile("splash.jpg");

	// Associate the sprite with the texture
	m_SplashSprite.setTexture(m_SplashTexture);
}

Application::~Application()
{
}

void Application::run()
{
	Clock clock;

	while (m_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		float dt = clock.restart().asMilliseconds();

		input();
		update(dt);
		draw();
	}
}
