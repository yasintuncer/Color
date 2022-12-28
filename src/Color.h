#ifndef COLOR_H
#define COLOR_H
namespace Color
{

    typedef struct Rgb
    {
        double r;
        double g;
        double b;
        Rgb() : r(0), g(0), b(0) {}
        Rgb(double r, double g, double b) : r(r), g(g), b(b) {}
        ~Rgb() {}
        Rgb &operator=(Rgb &other)
        {
            r = other.r;
            g = other.g;
            b = other.b;
            return *this;
        }
        template <typename TColor>
        TColor To();

        template <typename TColor>
        Rgb From(TColor &other);
    } Rgb;

    typedef struct Cmyk
    {
        double c;
        double m;
        double y;
        double k;
        Cmyk() : c(0), m(0), y(0), k(0) {}
        Cmyk(double c, double m, double y, double k) : c(c), m(m), y(y), k(k) {}
        ~Cmyk() {}
        Cmyk &operator=(Cmyk &other)
        {
            c = other.c;
            m = other.m;
            y = other.y;
            k = other.k;
            return *this;
        }
        template <typename TColor>
        TColor To();

        template <typename TColor>
        Cmyk From(TColor &other);
    } Cmyk;

    typedef struct Hsv
    {
        double h;
        double s;
        double v;
        Hsv() : h(0), s(0), v(0) {}
        Hsv(double h, double s, double v) : h(h), s(s), v(v) {}
        ~Hsv() {}
        Hsv &operator=(Hsv &other)
        {
            h = other.h;
            s = other.s;
            v = other.v;
            return *this;
        }
        template <typename TColor>
        TColor To();

        template <typename TColor>
        Hsv From(TColor &other);
    } Hsv;
    
    typedef struct Lab
    {
        double l;
        double a;
        double b;
        Lab() : l(0), a(0), b(0) {}
        Lab(double l, double a, double b) : l(l), a(a), b(b) {}
        ~Lab() {}
        Lab &operator=(Lab &other)
        {
            l = other.l;
            a = other.a;
            b = other.b;
            return *this;
        }
        template <typename TColor>
        TColor To();

        template <typename TColor>
        Lab From(TColor &other);
    } Lab;

    struct Xyz
    {
        double x;
        double y;
        double z;
        double kappa;
        double epsilon;
        double whitePoint[3];
        Xyz() : x(0), y(0), z(0) {}
        Xyz(double x, double y, double z) : x(x), y(y), z(z) {}
        ~Xyz() {}
        Xyz &operator=(Xyz &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        template <typename TColor>
        TColor To();

        template <typename TColor>
        Xyz From(TColor &other);

    };
    
    
    

}
#endif // COLOR_H
