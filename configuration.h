// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes
#include <iostream>
using namespace std;

class Configuration
{
private:
	int noChoices;
	int noQuestions;
	int noFlagNames;
	string* flagNames;

public:
	Configuration();
	Configuration(string* value, int noFlagNames);
	~Configuration();
	Configuration(const Configuration& config);
	bool setNoChoices(int no_choices);
	bool setNoQuestions(int no_questions);
	void setFlagNameAt(string flagName, int position);
	string getFlagNameAt(int index);
	string* getAllFlagNames();
	void setNoFlagNames(int noFlagNames);
	int getNoChoices();
	int getNoQuestions();
	int getNoFlagNames();

}; 
#pragma once

