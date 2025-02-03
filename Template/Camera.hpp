#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Camera
{
public:
	Camera(float width, float height);
	void update(const Vector2f& playerPosition);
	void apply(RenderWindow& window);
	

	

private:
	View view;
};



