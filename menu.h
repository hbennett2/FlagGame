#include <iostream>
#include "configuration.h"
using namespace std;

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