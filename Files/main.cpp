#include <iostream>
#include "HappyTicket.h"
#include "SolveVersionOne.h"
#include "SolveVersionTwo.h"
#include "GeneratorTasks.h"
#include <fstream>

int testSimple()
{
    GeneratorTasks *task1 = new GeneratorTasks(5, 5);
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
    std::cout << std::endl;
    std::cout << "Time roster one: " << time_one << std::endl;

    std::cout << "Result roster two" << std::endl;
    for (auto element : resultRosterTwo)
    {
        std::cout << element;
    }
    std::cout << std::endl;
    std::cout << "Time roster two: " << time_two << std::endl;

    delete task1;
    delete versionOne;
    delete versionTwo;

    return 1;
}

int testExcelTable()
{
    std::ofstream ExcelFile;
    ExcelFile.open("D:\\projects\\HappyTicket\\ExcelTable\\Table.csv");

    if (ExcelFile.is_open())
    {
        ExcelFile << "N ;"
                  << "D ;"
                  << "Time Optimized ;"
                  << "Time not Optimized ;"
                  << "Answer Optimized ;"
                  << "Answer not Optimized" << std::endl;

        for (int i = 1; i <= 7; i++)
        {
            for (int j = 2; j <= 8; j++)
            {

                GeneratorTasks *task1 = new GeneratorTasks(i, j);
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
                std::cout << std::endl;
                std::cout << "Time roster one: " << time_one << std::endl;

                std::cout << "Result roster two" << std::endl;
                for (auto element : resultRosterTwo)
                {
                    std::cout << element;
                }
                std::cout << std::endl;
                std::cout << "Time roster two: " << time_two << std::endl;
                ExcelFile << task1->getDigits_N() << ";"
                          << task1->getBase_D() << ";"
                          << time_one << ";"
                          << time_two << ";";
                for (auto element : resultRosterOne)
                {
                    ExcelFile << element;
                }
                ExcelFile << ";";
                for (auto element : resultRosterTwo)
                {
                    ExcelFile << element;
                }
                ExcelFile << std::endl;

                delete task1;
                delete versionOne;
                delete versionTwo;
            }
        }
    }

    return 1;
}

int main()
{
    testExcelTable();
    system("pause>nul");
    return 0;
}