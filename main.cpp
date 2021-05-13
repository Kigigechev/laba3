#include <iostream>
#include <vector>
#include <string>

#include "histogram.h"
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height,
    string stroke="black", string fill="blue") {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}

void
show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    size_t max_bin = bins[0];
    for (size_t j : bins)
    {
        if (max_bin < j)
            max_bin = j;
    }

    double top = 0;
    for (size_t bin : bins) {
         if(bin==max_bin){
                svg_text(TEXT_LEFT, top+TEXT_BASELINE, to_string(max_bin));
                svg_rect(TEXT_WIDTH, top,IMAGE_WIDTH, BIN_HEIGHT);
        }
             else{
                svg_text(TEXT_LEFT, top+TEXT_BASELINE, to_string(bin));
                svg_rect(TEXT_WIDTH, top,IMAGE_WIDTH*bin/max_bin , BIN_HEIGHT,"black","green");
             }
        top += BIN_HEIGHT;
    }
    svg_end();

}

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
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);
    //show_histogram_text(bins);
     show_histogram_svg(bins);
    return 0;
}
