#include <iostream>
#include <vector>
#include <string>

#include "histogram.h"
#include "svg.h"
using namespace std;

vector<double>
input_numbers(istream& in,size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in,bool prompt) {
    Input data;
if(prompt)
    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;
if(prompt)
    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
if(prompt)
     cerr << "Enter bin count: ";
     size_t bin_count;
     in >> data.bin_count;
     return data;
}


int main() {
    const auto input = read_input(cin,true);
    const auto bins = make_histogram(input);
    //show_histogram_text(bins);
     show_histogram_svg(bins);
    return 0;
}
