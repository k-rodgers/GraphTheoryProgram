#include "components/Node.h"
#include "components/Token.h"

#include <iostream>

Token::Token(Node* n)
{
	location = n;
	playerTurn = 1;
}

Token::~Token()
{
}

Node* Token::getTokenLocation()
{
	return location;
}

void Token::setTokenLocation(Node* n)
{
	location = n;
}

int Token::getCurrentPlayerTurn()
{
	return playerTurn;
}

void Token::setPlayerTurn()
{
	if (playerTurn == 1)
		playerTurn = 2;
	else
		playerTurn = 1;
}