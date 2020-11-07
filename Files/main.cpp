#include <iostream>
#include "SolveVersionOne.h"
int main()
{
    SolveVersionOne *solve1 = new SolveVersionOne(3, 10);
    std::vector<int> testRoster = solve1->solve();
    for (int x : testRoster)
    {
        std::cout<<x;
    }
    
    system("pause>nul");
    return 0;
}