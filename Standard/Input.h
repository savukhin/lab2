#ifndef INPUT
#define INPUT

#include "MyExceptions.h"

namespace Input {
	int ReadInt();
	int ReadPositiveInt();
	float ReadFloat();
	float ReadPositiveFloat();
	char ReadChar();

	int RandomizeInt();
	int RandomizePositiveInt();
	float RandomizeFloat();
	float RandomizePositiveFloat();
	char RandomizeChar();

	int Dialogue(std::vector<char*> msgs);
	int Dialogue(std::vector<char*> msgs, std::vector< std::function<void()> >);
}

#include "Input.cpp"

#endif