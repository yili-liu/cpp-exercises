
class Shape {
public:
    virtual Point center() const =0; // pure virtual
    virtual void move(Point to) =0;

    virtual void draw() const = 0; // draw on current "Canvas"
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {} // destructor
    // ...
};

void rotate_all(vector<Shape*>& v, int angle) // rotate v’s elements by angle degrees
{
    for (auto p : v)
        p->rotate(angle);
}

class Point {
    int x, y;
};

class Circle : public Shape {
public:
    Circle(Point p, int rr); // constructor
    Point center() const { return x; }
    void move(Point to) { x=to; }
    void draw() const;
    void rotate(int) {} // nice simple algorithm
private:
    Point x; // center
    int r; // radius
};

int main() {
}
