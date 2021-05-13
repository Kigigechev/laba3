#include <iostream>
#include <vector>
#include <string>
using namespace std;

void
find_minmax(vector<double> numbers, double& min, double& max) {
    if(numbers.size()>0){

    min = numbers[0];
    max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
            min = x;

        if (x > max)
            max = x;
    }
    }
    else
        ;
    return;
}
