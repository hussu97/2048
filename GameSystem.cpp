#include "GameSystem.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<conio.h>
using namespace std;


GameSystem::GameSystem() {
	srand(time(0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;

		}
	}
	int _X = rand() % 4;
	int _Y = rand() % 4;
	for (int i = 0; i < 2; i++)
	{
		while (arr[_X][_Y] != 0) {
			_X = rand() % 4;
			_Y = rand() % 4;
		}
		arr[_X][_Y] = 2;
	}
	cout << "--------------------------------Welcome to 2048---------------------------------\n\n";
}
void GameSystem::playGame() {
	while (victory == true) {
		cout << "Enter a direction you want to go to(w/a/s/d): \n";
		char direction = _getch();
		int i = 0;
		i = ProcessMove(direction);
		int x = num_zero();
		if (i == 0 && x == 0) {
			victory = false;
		}
		if (i != 0 && x != 0) {
			EnemyMove(x);
		}
		system("CLS");
		print();
	}
	cout << "Thank you for playing!!\n";
	if (score >= highscore) {
		cout << "\n New highscore congratulations!!!\n\n";
		ofstream mycout("Highscore.txt");
		mycout << score;
	}
	else {
		cout << "\nNo new highscore, maybe next time\n\n";
	}
}
int GameSystem::ProcessMove(char input) {
	bool merge_check = true;
	int change = 0;
	switch (input) {
	case'w':
		for (int j = 0; j < 4; j++) {
			for (int i = 1; i < 4; i++) {
				if (arr[i][j] != 0) {
					for (int k = i - 1; k > -1; k--)
					{
						if (arr[k][j] == 0)
						{
							arr[k][j] += arr[k + 1][j];
							arr[k + 1][j] = 0;
							change++;
						}
						else if (arr[k][j] != arr[k + 1][j]) {
							break;
						}
						else if (arr[k][j] == arr[k + 1][j]) {
							while (merge_check == true) {
								arr[k][j] += arr[k + 1][j];
								arr[k + 1][j] = 0;
								score += arr[k][j];
								change++;
								break;
							}
							merge_check = change_value(merge_check);
						}
					}
				}
			}
			merge_check = true;
		}
		break;
	case's':
		for (int j = 0; j < 4; j++) {
			for (int i = 2; i > -1; i--) {
				if (arr[i][j] != 0) {
					for (int k = i + 1; k < 4; k++)
					{
						if (arr[k][j] == 0)
						{
							arr[k][j] += arr[k - 1][j];
							arr[k - 1][j] = 0;
							change++;
						}
						else if (arr[k][j] != arr[k - 1][j]) {
							break;
						}
						else if (arr[k][j] == arr[k - 1][j]) {
							while (merge_check == true) {
								arr[k][j] += arr[k - 1][j];
								arr[k - 1][j] = 0;
								score += arr[k][j];
								change++;
								break;
							}
							merge_check = change_value(merge_check);
						}
					}
				}
			}
			merge_check = true;
		}
		break;
	case'a':
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 4; j++) {
				if (arr[i][j] != 0) {
					for (int k = j - 1; k > -1; k--)
					{
						if (arr[i][k] == 0)
						{
							arr[i][k] += arr[i][k + 1];
							arr[i][k + 1] = 0;
							change++;
						}
						else if (arr[i][k] != arr[i][k + 1]) {
							break;
						}
						else if (arr[i][k] == arr[i][k + 1]) {
							while (merge_check == true) {
								arr[i][k] += arr[i][k + 1];
								arr[i][k + 1] = 0;
								score += arr[i][k];
								change++;
								break;
							}
							merge_check = change_value(merge_check);
						}
					}
				}
			}
			merge_check = true;
		}
		break;
	case'd':
		for (int i = 0; i < 4; i++) {
			for (int j = 2; j > -1; j--) {
				if (arr[i][j] != 0) {
					for (int k = j + 1; k < 4; k++)
					{
						if (arr[i][k] == 0)
						{
							arr[i][k] += arr[i][k - 1];
							arr[i][k - 1] = 0;
							change++;
						}
						else if (arr[i][k] != arr[i][k - 1]) {
							break;
						}
						else if (arr[i][k] == arr[i][k - 1]) {
							while (merge_check == true) {
								arr[i][k] += arr[i][k - 1];
								arr[i][k - 1] = 0;
								score += arr[i][k];
								change++;
								break;
							}
							merge_check = change_value(merge_check);
						}
					}
				}
			}
			merge_check = true;
		}
		break;
	}
	return change;
}
void GameSystem::EnemyMove(int number0) {
	srand(time(0));
	int _X = rand() % 4;
	int _Y = rand() % 4;
	int num[2] = { rand() % 2,rand() % 2 };
	if (number0 == 1) {
		while (arr[_X][_Y] != 0) {
			_X = rand() % 4;
			_Y = rand() % 4;
		}
		if (num[0] == 0) {
			arr[_X][_Y] = 2;
		}
		else {
			arr[_X][_Y] = 4;
		}
	}
	else {
		for (int i = 0; i < (rand() % 2 + 1); i++) {
			while (arr[_X][_Y] != 0) {
				_X = rand() % 4;
				_Y = rand() % 4;
			}
			if (num[i] == 0) {
				arr[_X][_Y] = 2;
			}
			else {
				arr[_X][_Y] = 4;
			}
		}
	}
}
void GameSystem::getHighscore() {
	ifstream mycin("Highscore.txt");
	mycin >> highscore;
	mycin.close();
}
void GameSystem::print() {
	for (int i = 0; i < 4; i++)
	{
		cout << "|  ";
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]>100)
				cout << arr[i][j] << "|  ";
			else if (arr[i][j]>10)
				cout << arr[i][j] << " |  ";
			else
				cout << arr[i][j] << "  |  ";
		}
		cout << endl;
	}
	cout << "\nCurrent score: " << score << "\n\n";
}
bool GameSystem::change_value(bool value) {
	if (value == true)
		return false;
	else
		return true;
}
int GameSystem::num_zero() {
	int numb_zero = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				numb_zero++;
			}
		}
		cout << endl;
	}
	return numb_zero;
}
