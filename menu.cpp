#include <iostream>
using namespace std;
#include "Menu.h"
#include "graph1.h"

Menu::Menu()
{
    choices = NULL;
    selection = 0;
}

Menu::~Menu()
{
    delete[] choices;
}

Menu::Menu(const Menu& menu)
{

    this->setConfig(menu.config);
    this->selection = menu.selection;

    // copys choices
    for (int i = 0; i < config.getNoChoices(); i++)
    {
        this->choices[i] = menu.choices[i]; 
    }
}

void Menu::setConfig(Configuration config)
{
    this->config.setNoQuestions(config.getNoQuestions());
    this->config.setNoChoices(config.getNoChoices());
    this->config.setNoFlagNames(config.getNoFlagNames());

    // sets flag names
    for (int i = 0; i < this->config.getNoFlagNames(); i++)
    {
        this->config.setFlagNameAt(config.getFlagNameAt(i), i);
    }

    this->choices = new string[config.getNoChoices()];
}

void Menu::setSelection(int selection)
{
    this->selection = selection;
}

void Menu::setChoice(int index, string flag_name)
{
    choices[index] = flag_name;
}

string Menu::getChoice(int index)
{
    return choices[index];
}

int Menu::getSelection()
{
    return selection;
}

Configuration Menu::getConfig()
{
    return config;
}

int Menu::displayMenu()
{
    int uchoice = 0;
    int rec = 0;
    int y = 235;
    
    // user input
    gout << setPos(200, 220) << "Choose from the following: " << endg;
    // draws rectangles and displays choices
    for (int j = 0; j < config.getNoChoices(); j++)
    {
        rec = drawRect(200, y, 300, 20);
        setColor(rec, 128, 128, 128);
        gout << setPos(200, y + 10) << j + 1 << ": " << getChoice(j) << endg;
        y += 30;
    }

    gout << setPos(200, y + 50) << "Enter choice on console" << endg;
    return uchoice;
}

// 
void Menu::displayFlag(string flag_name)
{
    displayBMP(flag_name + ".bmp", 200, 50);
}