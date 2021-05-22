#include <iostream>
#include <vector>
#include <string>

#include "histogram.h"
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

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

vector<size_t>
make_histogram(Input data) {
    size_t bin_count=data.bin_count;
    vector<size_t> bins(bin_count);
    double min, max, bin_size;
    find_minmax(data.numbers, min, max);
    bin_size = (max - min) / bin_count;
    for (double i : data.numbers)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= i) && (i < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void
show_histogram_text(const vector<size_t>& bins) {
    size_t max_count = bins[0];
    for (size_t j : bins)
    {
        if (max_count < j)
            max_count = j;
    }

    for (size_t j : bins)
    {
        if (j < 10)
            cout << "  " << j << "|";
        if (j < 100 && j>10)
            cout << " " << j << "|";
        if (j >= 100)
            cout << j << "|";
        if (max_count == j)
        {
            for (size_t i = 0; i < MAX_ASTERISK; i++)
                cout << "*";
        }
        else
        {
            size_t height = MAX_ASTERISK * (static_cast<double>(j) / max_count);
            for (size_t q = 0; q < height; q++)
                cout << "*";
        }
        cout << endl;
    }
    return;
}
