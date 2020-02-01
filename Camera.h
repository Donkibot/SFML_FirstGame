#pragma once
#include <SFML\Graphics.hpp>

class Camera
{
private:
	sf::View view;
public:
	Camera() {

	}

	sf::View* getView() {
		return &view;
	}

	void setViewCoord(float x, float y) {
		view.setCenter(x, y);
	}
	 


	void update() {

	}

};

