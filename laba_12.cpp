#include "Polygon.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"

int main()
{
    Point A(7, 2), B(1, 1), C(9, 4), inside(-10, -20);
    Triangle ABC(A, B, C);
    cout << "Площадь треугольника: " << ABC.area() <<
    "\nПериметр треугольника: " << ABC.perimetr() <<
    "\nЛежит ли тестовая точка внутри треугольника: " << ABC.containsPoint(inside) <<
    "\nКоличество вершин треугольника: " <<
    ABC.getCountVertex() << "\nКоординаты вершин:\n";
    for (int i = 0; i < ABC.getVertex().size(); ++i) {
        cout << ABC.getVertex()[i].x << ' ' << ABC.getVertex()[i].y << '\n';
    }

    Point A1(2, 10), C1(10, 18);
    Square ABCD(A1, C1);
    cout << "\nПлощадь квадрата: " << ABCD.area() <<
    "\nПериметр квадрата: " << ABCD.perimetr() <<
    "\nВыпуклый ли квадрат " << ABCD.isConvex_v2() <<
    "\nЛежит ли тестовая точка внутри квадрата: " << ABCD.containsPoint(inside) <<
    "\nКоординаты центра квадрата: " << ABCD.getCenter().x << ' ' << ABCD.getCenter().y <<
    "\nКоличество вершин квадрата: " <<
    ABCD.getCountVertex() << "\nКоординаты вершин:\n";
    for (int i = 0; i < ABCD.getVertex().size(); ++i) {
        cout << ABCD.getVertex()[i].x << ' ' << ABCD.getVertex()[i].y << '\n';
    }

    Point A2(2, 11), C2(14, 18);
    Rectangle ABCD1(A2, C2);
    cout << "\nПлощадь прямоугольника: " << ABCD1.area() <<
    "\nПериметр прямоугольника: " << ABCD1.perimetr() <<
    "\nВыпуклый ли прямоугольник " << ABCD1.isConvex_v2() <<
    "\nЛежит ли тестовая точка внутри прямоугольника: " << ABCD1.containsPoint(inside) <<
    "\nКоординаты центра прямоугольника: " << ABCD1.getCenter().x << ' ' << ABCD1.getCenter().y <<
    "\nКоличество вершин прямоугольника: " <<
    ABCD1.getCountVertex() << "\nКоординаты вершин:\n";
    for (int i = 0; i < ABCD1.getVertex().size(); ++i) {
        cout << ABCD1.getVertex()[i].x << ' ' << ABCD1.getVertex()[i].y << '\n';
    }

    vector <Point> G(5);
    G[0] = {1, 3};
    G[1] = {2, 6};
    G[2] = {4, 8};
    G[3] = {-1, 10};
    G[4] = {15, 0};
    Polygon Pol(G);
    cout << "\nПлощадь многоугольника: " << Pol.area() <<
    "\nПериметр многоугольника: " << Pol.perimetr() <<
    "\nВыпуклый ли многоугольник " << Pol.isConvex_v2() <<
    "\nЛежит ли тестовая точка внутри многоугольника: " << Pol.containsPoint(inside) <<
    "\nКоличество вершин многоугольника: " <<
    Pol.getCountVertex() << "\nКоординаты вершин:\n";
    for (int i = 0; i < Pol.getVertex().size(); ++i) {
        cout << Pol.getVertex()[i].x << ' ' << Pol.getVertex()[i].y << '\n';
    }
    cout << '\n';

    Circle Circumscribed_circle = ABCD.getCircumscribedCircle();
    cout << "Центр описанной вокруг квадрата окружности совпадает с центром самого квадрата: " <<
    Circumscribed_circle.getCenter().x << " " << Circumscribed_circle.getCenter().y <<
    "\nПлощадь окружности: " << Circumscribed_circle.area() <<
    "\nПериметр окружности: " << Circumscribed_circle.perimetr() <<
    "\nРадиус окружности: " << Circumscribed_circle.getRadius() << '\n';
    cout << '\n';

    Circle Circ({5,5}, 5);
    cout << "Центр окружности: " <<
    Circ.getCenter().x << " " << Circ.getCenter().y <<
    "\nПлощадь окружности: " << Circ.area() <<
    "\nПериметр окружности: " << Circ.perimetr() <<
    "\nРадиус окружности: " << Circ.getRadius() << '\n';
    cout << '\n';

    Point B3(5, 10), C3(10, 10);
    Ellipse Ellip(B3, C3, 5);
    cout << "Площадь эллипса: " << Ellip.area() <<
    "\nПериметр эллипса: " << Ellip.perimetr() <<
    "\nЕго эксцентриситет: "<< Ellip.getEccentricity() <<
    "\nКоординаты центра эллипса: " << Ellip.getCenter().x << ' ' << Ellip.getCenter().y <<
    "\nЕго фокусы: \n" << Ellip.first_focuse().x << ' ' << Ellip.first_focuse().y <<
    '\n' << Ellip.second_focuse().x << ' ' << Ellip.second_focuse().y;

    Circle comparison1({0, 0}, 5), comparison2({3, 3}, 5);
    cout << "\n\nСравниваем две одинаковых окружности, ожидается 1: " << comparison1.isCongruentTo(comparison2);
}
