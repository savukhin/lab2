#ifndef INPUT_CPP
#define INPUT_CPP

#include "Input.h"
#include "Messages.h"
#include <iostream>
#include <limits>
#include <random>
#include <ios>

namespace Input {
	namespace {
		template<class T>
		void Read(T& val, const char* errormsg) {
			T a;
			while (!(std::cin >> a)) {
				std::cout << errormsg << '\n';
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize > ::max(), '\n');
			}
			val = a;
		}
	}

	int ReadInt() {
		int a;
		Read(a, Messages::MESSAGE_INVALID_INT);
		return a;
	}

	int ReadPositiveInt() {
		unsigned int a;
		Read(a, Messages::MESSAGE_INVALID_POSITIVE_INT);
		return a;
	}

	float ReadFloat() {
		float a;
		Read(a, Messages::MESSAGE_INVALID_FLOAT);
		return a;
	}

	float ReadPositiveFloat() {
		float a;
		Read(a, Messages::MESSAGE_INVALID_POSITIVE_FLOAT);
		return a;
	}

	char ReadChar() {
		char a;
		Read(a, Messages::MESSAGE_INVALID_CHAR);
		return a;
	}

	int RandomizePositiveInt() {
		int a = rand() % 100 + 1;
		return a;
	}

	int RandomizeInt() {
		int a = rand() % 100 - 50;
		return a;
	}

	float RandomizeFloat() {
		float a = (rand() % 100 - 50) + (rand() % 10) / 10.;
		return a;
	}

	float RandomizePositiveFloat() {
		float a = (rand() % 100) + (rand() % 10) / 10.;
		return a;
	}

	char RandomizeChar() {
		char a = rand() % ('z' - 'a') + 'a';
		return a;
	}

	int Dialogue(std::vector<const char*> msgs) {
		const char *error = "";
		int choice;
		int n = msgs.size();

		do {
			std::cout << error << std::endl; 
			error = Messages::MESSAGE_INCORRECT_DIALOGUE_ANSWER;

			for (int i = 0; i < n; ++i) {
				std::cout << msgs[i] << std::endl;
			}

			std::cout << "Make your choice: ";
			choice = ReadInt();
			
		} while (choice < 0 || choice >= n);

		return choice;
	}

	int Dialogue(std::vector<const char*> msgs, std::vector< std::function<void()> > callbacks) {
		// if (callbacks.size() != msgs.size()) {
		// 	throw MyExceptions::DialogueCallbackInconsistency();
		// 	return -1;
		// }

		int choice = Dialogue(msgs);

		if (choice > 0 && choice < callbacks.size() 
				&& callbacks[choice] != nullptr)
			callbacks[choice]();

		return choice;
	}
}

#endif