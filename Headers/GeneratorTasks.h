#pragma once
#include <cstdlib>
#include <ctime>

class GeneratorTasks
{
private:
    int MIN_COUNT = 1;
    int MAX_COUNT = 100; 
    int random_N;
    int random_D;

    int Randomizator(int min, int max);
    
public:

    int getDigits_N();
    int getBase_D();

    GeneratorTasks();
    ~GeneratorTasks() = default;
};
