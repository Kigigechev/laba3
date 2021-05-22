#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>

#include "histogram.h"
#include "svg.h"

using namespace std;

string
make_info_text() {
    stringstream buffer;
    DWORD info= GetVersion();
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD version_major = version & 0x00ff;
    DWORD version_minor = version>>8;
    DWORD build;
    if((platform&0x80000000)==0 ) build=platform;

    char DNS[MAX_COMPUTERNAME_LENGTH+1];
    DWORD size=MAX_COMPUTERNAME_LENGTH+1;
    GetComputerName(DNS,&size);
    cout<<"Windows v"<<version_major<<"."<<version_minor<<" (build "<<build<<")"
    <<endl<<"\nComputer name "<<DNS;
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
    make_info_text();/*
    size_t number_count;
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);
    //show_histogram_text(bins);
     show_histogram_svg(bins);*/
    return 0;
}
