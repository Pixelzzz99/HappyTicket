#include "GeneratorTasks.h"

GeneratorTasks::GeneratorTasks()
{
    srand(time(nullptr));
    random_N = Randomizator(MIN_COUNT, MAX_COUNT);
    random_D = Randomizator(MIN_COUNT, MAX_COUNT);
}

GeneratorTasks::GeneratorTasks(int n, int d)
{
    random_N = n;
    random_D = d;
}

int GeneratorTasks::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int GeneratorTasks::getDigits_N()
{
    return random_N;
}

int GeneratorTasks::getBase_D()
{
    return random_D;
}