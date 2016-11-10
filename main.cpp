#include<iostream>
#include"GameSystem.h"
using namespace std;

void main()
{
	GameSystem game;
	game.getHighscore();
	game.print();
	game.playGame();
	cout << "\nWould you like to play another game?(Y/N): \n";
	char a;
	cin >> a;
	if (a == 'N' || a == 'n')
		exit(0);
}