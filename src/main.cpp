#include <iostream>

using namespace std;

int main()
{
    //initialized variables

    int length1 = 1;
    int width1 = 2;

    int length2 = 4;
    int width2 = 5;

    //item 6 - disallowed the use of the copy constructor
    //         and the copy assignment operator

    class Uncopyable{
        protected:
            Uncopyable(){}
            ~Uncopyable(){}

        private:
            Uncopyable(const Uncopyable&);
            Uncopyable& operator=(const Uncopyable&);
    };

    //item 4 and item 5
    // - used member initialization list in the Constructor
    // - notification for the silent call of the Destructor

    class Rectangle: private Uncopyable{
        private:
            int theLength;
            int theWidth;

        public: Rectangle(const int& length, const int& width):
            theLength(length),
            theWidth(width)
        {}

        public: ~Rectangle(){
            cout << "Destructor executed.\n";
        }

        public: int getArea(){
            return this->theLength * this->theWidth;
        }

        public: int getPerimeter(){
            return this->theLength * 2 + this->theWidth * 2;
        }

    };

    Rectangle rectangle1(length1, width1);
    Rectangle rectangle2(length2, width2);

    cout << "Area rectangle1: " << rectangle1.getArea() << "\n";
    cout << "Perimeter rectangle1: " << rectangle1.getPerimeter() << "\n";

    cout << "Area rectangle2: " << rectangle2.getArea() << "\n";
    cout << "Perimeter rectangle2: " << rectangle2.getPerimeter() << "\n";
    
    return 0;
}
