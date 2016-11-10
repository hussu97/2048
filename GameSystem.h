#pragma once
class GameSystem {
private:
	int arr[4][4];
	int score = 0;
	bool victory = true;
	int highscore;//previous highscore from text file
public:
	//constructor
	GameSystem();
	void getHighscore();//from text file

	void playGame();
	
	int ProcessMove(char input);//moves board in input direction
	void EnemyMove(int number0);//adds 2 or 4 at random places after player move
	bool change_value(bool value);//to avoid double merging
	int num_zero();//if num_zero==0, game over
	void print();//prints board to console

};
