#include "Lab2.h"

int main() {
    Program *program = new Program(Input::ReadPositiveFloat, Input::RandomizePositiveFloat);

    program->Start();
    
    delete program;
}