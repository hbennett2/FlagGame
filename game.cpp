#include <iostream>
#include "Game.h"
#include "graph1.h"
#include "Menu.h"
using namespace std;

Game::Game()
{
	no_correct = 0;
}

void Game::setMenu(Menu menu)
{
	this->menu.setSelection(menu.getSelection());
	this->menu.setConfig(menu.getConfig());
}

int Game::play() 
{
	srand(time(0)); // random
	
	int no_correct = 0;
	int select = 0;

	// 
	for (int i = 0; i < menu.getConfig().getNoQuestions(); i++)
	{
		for (int j = 0; j < menu.getConfig().getNoChoices(); j++)
		{
			int index = rand() % menu.getConfig().getNoFlagNames();
			string flagName = menu.getConfig().getFlagNameAt(index);
			menu.setChoice(j, flagName);
		}

		// finds correct flag 
		int correctFlag = rand() % menu.getConfig().getNoChoices();
		string correctFlagName = menu.getChoice(correctFlag);

		//
		menu.displayFlag(correctFlagName);

		// display
		gout << setPos(200, 30) << "Question #" << i + 1 << endg;
		menu.displayMenu();

		// user input 
		cout << "Enter selection: ";
		cin >> select;
		menu.getSelection();

		// 
		if (select - 1 == correctFlag)
		{
			no_correct += 1;
			gout << setPos(200, 450) << "CORRECT!!" << endg;
			Sleep(5000);
		}
		else
		{
			gout << setPos(200, 450) << "INCORRECT!!, The name of the correct flag is " << correctFlagName << endg;
			Sleep(5000);
		}

		clearGraphics(); // clear
	}

	return no_correct;
}

Menu Game::getMenu()
{
	return menu;
}

int Game::getNoCorrect()
{
	return no_correct;
}