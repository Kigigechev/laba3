#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

void
svg_begin(double width, double height);
void
svg_end();
void
svg_text(double left, double baseline, string text);
void
svg_rect(double x, double y, double width, double height,
    string stroke="black", string fill="red");
void
svg_text1(double left, double baseline, string text,string font_size="12px");
void
show_histogram_svg(const vector<size_t>& bins,size_t font_size);


#endif // SVG_H_INCLUDED
