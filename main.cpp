#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "histogram.h"
#include "svg.h"
using namespace std;

string
make_info_text() {
    stringstream buffer;
    // TODO: получить версию системы, записать в буфер.
    // TODO: получить имя компьютера, записать в буфер.
    return buffer.str();
}
vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

int main() {
    size_t number_count;
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);
    //show_histogram_text(bins);
     show_histogram_svg(bins);
    return 0;
}
