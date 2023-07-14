#include <iostream>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point(int a , int b) {
            x = a;
            y = b;
        }
        void display() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
        Point operator ++ () {
            x =x+ 4;
            y = y+4;
        }
};

int main() {
    Point p(2, 3);
    cout << "Before increment: ";
    p.display();
    ++p;
    cout << "After increment: ";
    p.display();
    return 0;
}

