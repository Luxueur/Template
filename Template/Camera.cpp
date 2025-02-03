#include "Camera.hpp"

Camera::Camera(float width, float height)
{
	view.setSize(width, height);
	view.setCenter(width/2,height/2);
}

void Camera::update(const Vector2f& playerPosition)
{
	view.setCenter(playerPosition);
}


void Camera::apply(RenderWindow& window)
{
	window.setView(view);
}