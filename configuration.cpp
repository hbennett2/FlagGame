#include "configuration.h"
#include <iostream>
using namespace std;

Configuration::Configuration()
{
	noChoices = 4;
	noQuestions = 10;
	noFlagNames = 224;
	flagNames = new string[noFlagNames];
}

Configuration::Configuration(string* value, int noFlagNames)
{
	this->noFlagNames = noFlagNames;
	this->flagNames = new string[noFlagNames];
	this->noChoices = noChoices;
	this->noQuestions = noQuestions;

	for (int i = 0; i < noFlagNames; i++)
	{
		this->flagNames[i] = value[i];
	}
}

Configuration::~Configuration()
{
    delete[] flagNames;
}

Configuration::Configuration(const Configuration& config)
{
    noChoices = config.noChoices;
    noQuestions = config.noQuestions;
    noFlagNames = config.noFlagNames;
    flagNames = new string[noFlagNames];

    for (int i = 0; i < noFlagNames; i++)
    {
        flagNames[i] = config.flagNames[i];
    }
}

// choice parameters
bool Configuration::setNoChoices(int no_choices)
{
    if (no_choices < 2)
    {
        this->noChoices = 2;
        return false;
    }
    else if (no_choices > 6)
    {
        this->noChoices = 6;
        return false;
    }
    else
    {
        noChoices = no_choices;
        return true;
    }
}

// question parameters
bool Configuration::setNoQuestions(int no_questions)
{
    if (no_questions < 3)
    {
        this->noQuestions = 3;
        return false;
    }
    else if (no_questions > 20)
    {
        this->noQuestions = 20;
        return false;
    }
    else
    {
        noQuestions = no_questions;
        return true;
    }
}

void Configuration::setFlagNameAt(string flagName, int position)
{
    flagNames[position] = flagName;
}

// no flag name parameters
void Configuration::setNoFlagNames(int noFlagNames)
{
    if (noFlagNames < 5)
        this->noFlagNames = 5;
    else if (noFlagNames > 224)
        this->noFlagNames = 224;
    else
        this->noFlagNames = noFlagNames;
}

int Configuration::getNoChoices()
{
    return noChoices;
}

int Configuration::getNoFlagNames()
{
    return noFlagNames;
}

int Configuration::getNoQuestions()
{
    return noQuestions;
}

string Configuration::getFlagNameAt(int index)
{
    return flagNames[index];
}

string* Configuration::getAllFlagNames()
{
    return flagNames;
}