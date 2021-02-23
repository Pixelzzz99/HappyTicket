#include <iostream>
#include "HappyTicket.h"
#include "SolveVersionOne.h"
#include "SolveVersionTwo.h"
#include "GeneratorTasks.h"

int testSimple()
{
    GeneratorTasks *task1 = new GeneratorTasks();
    HappyTicket *versionOne = new HappyTicket(new SolveVersionOne(task1));
    HappyTicket *versionTwo = new HappyTicket(new SolveVersionTwo(task1));

    std::cout << "N\t" << task1->getDigits_N() << std::endl;
    std::cout << "D\t" << task1->getBase_D() << std::endl;

    unsigned int time_start = clock();
    std::vector<int> resultRosterOne = versionOne->DoAlgorithm();
    double time_one = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    time_start = clock();
    std::vector<int> resultRosterTwo = versionTwo->DoAlgorithm();
    double time_two = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    std::cout << "Result roster one" << std::endl;
    for (auto element : resultRosterOne)
    {
        std::cout << element;
    }
    std::cout << "Time roster one: " << time_one << std::endl;
    std::cout << std::endl;

    std::cout << "Result roster two" << std::endl;
    for (auto element : resultRosterTwo)
    {
        std::cout << element;
    }
    std::cout << "Time roster two: " << time_two << std::endl;
    std::cout << std::endl;

    return 1;
}

int main()
{
    SolveVersionOne *solve1 = new SolveVersionOne(3, 10);
    std::vector<int> testRoster = solve1->solve();
    for (int x : testRoster)
    {
        std::cout << x;
    }

    system("pause>nul");
    return 0;
}