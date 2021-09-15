#ifndef PROGRAM_CPP
#define PROGRAM_CPP

#include "Program.h"

class Program {
private:
    float (*readerFunction)();
    float (*randomizerFunction)();

    Deltoid* RandomizeDeltoid() {
        return new Deltoid(Input::RandomizeFloat());
    }

    Deltoid* CinDeltoid() {
        std::cout << "Input radius of smaller round: ";
        return new Deltoid(Input::ReadFloat());
    }

    Deltoid* InputDeltoid() {
        std::cout << "How do you want to initialize deltoid?";
        std::vector<const char*> options = {
            "0. Randomize", 
            "1. Input from keyboard"};

        Deltoid *deltoid;

        int inputChoice = Input::Dialogue(options);

        if (inputChoice == 0)
            deltoid = RandomizeDeltoid();
        else
            deltoid = CinDeltoid();

        std::cout << deltoid->ToString();
        return deltoid;
    }

    void GetLenWithTangent(Deltoid &deltoid) {
        std::cout << deltoid.LenWithTangent();
    }

    void GetLen(Deltoid &deltoid) {
        std::cout << deltoid.Len();
    }

    void GetParameter(Deltoid &deltoid) {
        std::cout << "Input parameter t: ";
        auto ans = deltoid.Parameter(Input::ReadInt());
        std::cout << "X = " << ans.first << "Y = " << ans.second << std::endl;
    }

    void GetSquare(Deltoid &deltoid) {
        std::cout << deltoid.Square();
    }
    
    void GetEqualation(Deltoid &deltoid) {
        std::cout << deltoid.GetEqualation();
    }

public:
    Program(float (*readerFunction)(), float (*randomizerFunction)()) {
        this->readerFunction = readerFunction;
        this->randomizerFunction = randomizerFunction;
    }

    void Start() {
        Deltoid *deltoid = InputDeltoid();

        std::vector<const char*> options = {
            "0. Quit", 
            "1. Get length of intersection area between deltoida and tangent", 
            "2. Get length of curve",
            "3. Get square",
            "4. Get x and y with param t",
            "5. Get euqalation in decart coordinates"};

        std::vector<std::function<void()>> callbacks {
            nullptr,
            std::bind(&Program::GetLenWithTangent, this, *deltoid),
            std::bind(&Program::GetLen, this, *deltoid),
            std::bind(&Program::GetSquare, this, *deltoid),
            std::bind(&Program::GetParameter, this, *deltoid),
            std::bind(&Program::GetEqualation, this, *deltoid),
        };

        int choice;
        while (choice = Input::Dialogue(options, callbacks) != 0);

        delete deltoid;
    }

    ~Program() {
        
    }
};

#endif