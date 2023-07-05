#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <stdarg.h>
#include <math.h>

using namespace std;
const double PI = 3.14159265358979323846;

const double EPS = 10e-6;

class Point {
public:
    double x;
    double y;
    Point() = default;
    Point(double x, double y = 0) : x(x), y(y) {};

    bool operator == (Point a)
    {
        if (abs(this->x - a.x) < EPS && abs(this->y - a.y) < EPS)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator != (Point a)
    {
        return !(*this == a);
    }

    Point operator + (Point B) {
        Point res;
        res.x = x + B.x;
        res.y = y + B.y;
        return res;
    }
    Point operator - (Point B) {
        Point res;
        res.x = x - B.x;
        res.y = y - B.y;
        return res;
    }
    Point operator * (double k) {
        Point res;
        res.x = res.x * k;
        res.y = res.y * k;
        return res;
    }

    int operator * (Point k)
    {
        return this->x * k.x + this->y * k.y;
    }
};


// inline в силу того, что эта ф-ция как бы глобальная для всех кто полуется расстоянием
inline double dist(Point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

class Line
{
public:
    double A, B, C;

    // конструктор линии по двум точкам
    Line(Point p1, Point p2)
    {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -p1.x * p2.y + p2.x * p1.y;
    }

    // констуктор линии по общему ур-нию прямой
    Line(double A, double B, double C) {
        this->A = A;
        this->B = B;
        this->C = C;
    }

    // констуктор линии по точке и углу наклона
    Line(double coefficient, Point p1)
    {
        Point p2;
        double shift;
        shift = p1.y - p1.x * coefficient;

        if (p1.x != -1)
        {
            p2.x = p1.x + 1;
        }
        else {
            p2.x = p1.x - 1;
        }

        p2.y = coefficient * p2.x + shift;

        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -p1.x * p2.y + p2.x * p1.y;
    }

    bool operator == (Line a)
    {
        if (abs(this->A - a.A) < EPS && abs(this->B - a.B) < EPS && abs(this->C - a.C) < EPS)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator != (Line a)
    {
        return !(a == *this);
    }

    // ф-ция меняет представления прямой от общего вида к векторному
    /*
    Ax+By+C = 0 ==> r = at+b
    */
    pair<Point, Point> transform_equation_line()
    {
        // точки - они же вектора
        Point a, b;
        if (abs(this->A) < EPS) {
            a = Point(0, -this->C / this->B);
            b = Point(1, -this->C / this->B);
        }
        else
        {
            a = Point(-this->C / this->A, 0);
            b = Point(-(this->C + this->B) / A, 1);
        }
        pair<Point, Point> ans;
        ans.first = a;
        ans.second = b;

        return ans;
    }

};

class Shape
{

public:
    double perimetr();

    double area();

    // совпадает ли фигура с данной
    bool operator == (Shape& another);

    //// равна ли эта фигура в геометрическом смысле
    bool isCongruentTo(const Shape& another);

    //// подобна ли эта фигура в геометрическом смысле
    bool isSimilarTo(const Shape& another);

    //// содержит ли фигура точку
    bool containsPoint(Point point);


    void rotate(Point center, double angle);

    //// симметрия относительно линии
    void reflex(Line axis);

    //// симметрия относительно точки
    void reflex(Point center);

    void scale(Point center, double coef);
};