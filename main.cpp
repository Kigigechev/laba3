#include <iostream>
#include <vector>
#include <string>

#include "histogram.h"
#include "svg.h"
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t>
make_histogram(const vector<double>& numbers, size_t bin_count) {
    vector<size_t> bins(bin_count);
    double min, max, bin_size;
    find_minmax(numbers, min, max);
    bin_size = (max - min) / bin_count;
    for (double i : numbers)
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

int main() {
    size_t number_count;
    cerr<<"Enter number count:";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr<<"Enter bin count:";
    cin >> bin_count;
    size_t font_size=30;
    cerr<<"Enter font size:";
    cin >> font_size;
    while(font_size<8 || font_size>32)
    {
        cerr<<"The font size can have values from 8 to 32!!!!!!"<<endl
        <<"Enter the font size:";
        cin >> font_size;
    }

    const auto bins = make_histogram(numbers, bin_count);
    //show_histogram_text(bins);
     show_histogram_svg(bins,font_size);
    return 0;
}
