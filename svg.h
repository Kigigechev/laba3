#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

using namespace std;
void
svg_begin(double width, double height);
void
svg_end();
void
svg_text(double left, double baseline, string text);
void
svg_rect(double x, double y, double width, double height, string stroke="black", string fill="red");
void
svg_text1(double left, double baseline, string text);
void
show_histogram_svg(const vector<size_t>& bins);
string
make_info_text();


#endif // SVG_H_INCLUDED
