#pragma once

#include "Game.h"
#include "Rules.h"

class Rule1 
{
public:

	bool openTheDoor(const Game<Rule1>* game) const;
};

class Rule2 
{
public:

	bool openTheDoor(const Game<Rule2>* game) const;
};

class Rule3 
{
public:

	bool openTheDoor(const Game<Rule3>* game) const;
};