# Geometry
The eleventh laboratory work in the first year of the Faculty of Mathematics of YarSU on the basics of programming in C++

Write a hierarchy of classes for working with geometric shapes on a plane.
* The Point structure is a point on the plane. A point can be set with two numbers
of the double type. The fields x and y must be open. The points can be compared with the operators
== and !=.
* Line class — straight line. A straight line can be defined by two points, it can be two
numbers (angular coefficient and shift), it can be a point and a number (angular
coefficient). Lines can be compared using the == and != operators.
* Abstract class Shape — shape.
* The Polygon class is a polygon. A polygon is a special case of phi-
gurus. For a polygon, you can ask verticesCount() — the number of vertices and
std::vector<Point> getVertices — the vertexes themselves without the possibility of modification. You can
ask isConvex() if it is convex. You can construct a polygon from
a vector of vertex points in the order of traversal. You can construct a polygon from
points passed as parameters separated by commas (i.e. an unspecified number
of arguments). For simplicity, we will assume that polygons with self-intersections
never arise.
* The Ellipse class is an ellipse. An ellipse is a special case of a figure. At the ellipse , you can
ask std::pair<Point,Point> focuses() — its foci; std::pair<Line, Line> directrices()
— a pair of its directrices; double eccentricity() — its eccentricity, Point center() — its
center. An ellipse can be constructed from two points and a double (two foci and the sum
of the distances from the ellipse to them);
* Circle class — circle. A circle is a special case of an ellipse. For a circle, you can ask double radius() - radius.
A circle can be defined by a point and a number (center and radius).
* Rectangle class — rectangle. Rectangle is a special case of many-
the polygon. You can ask the rectangle Point center() — its center; std::pair<Line,
Line> diagonals() — a pair of its diagonals. A rectangle can be constructed
by two points (its opposite vertices) and a number (the ratio of adjacent
sides), and from two such rectangles, the one with the
shorter side located on the left side of the diagonal is selected, if viewed from
the first given point in the direction of the second.
* The Square class is a square. A square is a special case of a rectangle. 
You can ask the square Circle circumscribedCircle(), Circle inscribedCircle(). Quad-
the rat can be set by two points — opposite vertices.
* The Triangle class is a triangle. A triangle is a special case of a polygon
. For a triangle, you can ask Circle circumscribedCircle(), Circle inscribedCircle(),
Point centroid() is its center of mass, Point orthocenter() is its orthocenter, Line EulerLine()
is its Euler line, Circle ninePointsCircle() is its Euler circle.


You can ask any shape:
* double perimeter() — perimeter;
* double area() — area;
* operator==(const Shape& another) — whether this shape coincides with another;
* isCongruentTo(const Shape& another) — is this shape equal to the other in
a geometric sense;
* isSimilarTo(const Shape& another) — is this shape similar to another;
* containsPoint(Point point) — whether the point is inside the shape.

  
With any shape, you can do:
* rotate(Point center, double angle) — rotate by an angle (in degrees, against
the right arrow) relative to the point;
* reflex(Point center) — symmetry with respect to a point;
* reflex(Line axis) — symmetry with respect to a straight line;
* scale(Point center, double coefficient) — homotopy with coefficient coefficient
and center center.
