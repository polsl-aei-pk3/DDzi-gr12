#ifndef Player_H_INCLUDED 
#define Player_H_INCLUDED 

using namespace sf;
class Player {
	friend class Engine;
protected:
	bool Rside;
	float x;
	float gap = 25;
	float y=(float)(720/2);
	int score=0;

	//float acceleration = 0;
	//float ySpeed;
public:
	void render(RenderWindow* okno)
	{
		if (Rside) {
			RectangleShape player1(Vector2f(25, 150));
			player1.setPosition(x + gap, y);
			okno->draw(player1);
		}
		else {
			RectangleShape player2(Vector2f(25, 150));
			player2.setPosition(1080 - gap - 25, y);
			okno->draw(player2);
		}
	}
	void move(int dir)
	{
		

		float acceleration = 0.5;
		float ySpeed = 0;
		
		if (y > 0 && y < (720 - 150)) { //JESLI GRACZE ZNAJDUJE SIE W OKNIE TO WYKONAC RUCH
			ySpeed = ySpeed + acceleration;
			y = y + ySpeed * dir;

		}
		else if (y == 0)
			y = 1;
		else if (y == (720 - 150))
			y = 720 - 151;
	}
	void checkWin()
	{
		if(score==10){
		//	 newGame();
		// addToRanking();
		}
	}


};
#endif