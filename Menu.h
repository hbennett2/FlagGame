// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes
#include <iostream>
using namespace std;
#include "configuration.h"

class Menu
{
private:
    Configuration config;
    string* choices;
    int selection;



public:
    Menu();
    ~Menu();
    Menu(const Menu& menu);
    void setConfig(Configuration config);
    Configuration getConfig();
    void setSelection(int selection);
    void setChoice(int index, string flag_name);
    string getChoice(int index);
    int getSelection();
    int displayMenu();
    void displayFlag(string flag_name);
};
#pragma once