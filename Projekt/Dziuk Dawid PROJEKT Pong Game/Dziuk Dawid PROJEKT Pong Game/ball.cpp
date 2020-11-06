#include "engine.h"
using namespace std;
using namespace sf;

void Ball::render(RenderWindow* okno) {
	CircleShape ball(radius, 50);
	ball.setPosition(x, y);
	okno->draw(ball);

}
void Ball::move() {
	x += xSpeed;
	y += ySpeed;

}
void Ball::wallBounce() {
	if (y < radius / 2 || y>720 - 10)
		ySpeed = ySpeed * (-1);
	if (x > 1080)
		p2Scores();
	if (x < 0)
		p1Scores();

}

void Ball::playerBounce(Player p) {
	if (p.Rside)	//DLA GRACZA Z PRAWEJ STRONKY
		if ((x + radius * 2 < 1080) && (x + 2 * radius > 1080 - p.szer - p.gap) && (y+radius/2 > p.y) && (y+radius/2 < p.y + p.wys) && (xSpeed > 0))
			xSpeed = xSpeed * acc; //ZMIEN KIERUNEK
	if (!p.Rside)	//DLA GRACZA Z LEWEJ STRONY
		if ((x - radius < p.szer) && (x > radius) && (y+radius/2 > p.y) && (y+radius/2 < p.y + p.wys) && (xSpeed < 0))
			xSpeed = xSpeed * acc;		//ZMIEN KIERUNEK
}
void Ball::p2Scores() {
	//USTAW PILKE NA SRODEK EKRANU
	x = 1080 / 2;
	y = 720 / 2;
	//DODAJ PUNKT
	player1_pointer->pkt++;
	
	//GENERATOR LOSOWYCH PREDKOSCI
	float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
	float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));
	xSpeed = xRandom;
	ySpeed = yRandom;
}
void Ball::p1Scores() {
	x = 1080 / 2;
	y = 720 / 2;

	player2_pointer->pkt++;


	float xRandom = xLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (xHI - xLOW)));
	float yRandom = yLOW + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (yHI - yLOW)));

	xSpeed = xRandom * (-1);
	ySpeed = yRandom * (-1);
}
