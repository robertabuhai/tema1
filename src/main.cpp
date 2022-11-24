#include <iostream>

using namespace std;

int main()
{
    //initialized variables

    int length1 = 1;
    int width1 = 2;

    int length2 = 3;
    int width2 = 4;

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
            int theLength = 0;
            int theWidth = 0;

        public: Rectangle(const int& length, const int& width):
            theLength(length),
            theWidth(width)
        {
            cout << "\nRectangle constructor";
        }

        public: ~Rectangle(){
            cout << "Destructor executed.\n";
        }

        public: int getArea(){
            return this->theLength * this->theWidth;
        }

        public: int getPerimeter(){
            return this->theLength * 2 + this->theWidth * 2;
        }

        public: int getLength(){
            return this->theLength;
        }

        public: int getWidth(){
            return this->theWidth;
        }

        //item 10

        public: 
            Rectangle& operator+=(const Rectangle& rhs){
                this->theLength = this->theLength + rhs.theLength;
                this->theWidth = this->theWidth + rhs.theWidth;
                return *this;
            }

        public: 
            Rectangle& operator-=(const Rectangle& rhs){
                this->theLength = this->theLength - rhs.theLength;
                this->theWidth = this->theWidth - rhs.theWidth;
                return *this;
            }

        //item 11

        public: 
            Rectangle& operator=(const Rectangle& rhs){
                if(this == &rhs){
                    cout << "\nself-assignment";
                    return *this;
                }
                theLength = rhs.theLength;
                theWidth = rhs.theWidth;
                cout << "\ncopy-assignment";
                return *this;
            }

    };

    //item 12

    class Square: private Rectangle{
        private:
            int theLength;

        public: Square(const int& length):
            Rectangle(length, length),theLength(length)
            {
                cout << "\nSquare constructor";
            }

        public: 
            Square& operator=(const Square& rhs){
                if(this == &rhs){
                    cout << "\nSquare self-assignment";
                    return *this;
                }
                Rectangle::operator=(rhs);
                theLength = rhs.theLength;
                cout << "\nSquare copy-assignment";
                return *this;
            }

        
        public:
            int getLength(){
                return this->theLength;
            }
    };

    Rectangle rectangle1(length1, width1);
    Rectangle rectangle2(length2, width2);
    Rectangle rectangle3(length2, width2);

    cout << "\n1.";

    cout << "\nRectangle 1: L = " << rectangle1.getLength() << ", W = " << rectangle1.getWidth();
    cout << "\nArea = " << rectangle1.getArea() << "\n";
    cout << "Perimeter = " << rectangle1.getPerimeter() << "\n";

    cout << "\nRectangle 2: L = " << rectangle2.getLength() << ", W = " << rectangle2.getWidth();
    cout << "\nArea = " << rectangle2.getArea() << "\n";
    cout << "Perimeter = " << rectangle2.getPerimeter() << "\n";

    cout << "\nRectangle 3: L = " << rectangle3.getLength() << ", W = " << rectangle3.getWidth();
    cout << "\nArea = " << rectangle3.getArea() << "\n";
    cout << "Perimeter = " << rectangle3.getPerimeter() << "\n";

    rectangle3 += rectangle2 += rectangle1;
    cout << "\n2.";

    cout << "\nRectangle 1: L = " << rectangle1.getLength() << ", W = " << rectangle1.getWidth();
    cout << "\nRectangle 2: L = " << rectangle2.getLength() << ", W = " << rectangle2.getWidth();
    cout << "\nRectangle 3: L = " << rectangle3.getLength() << ", W = " << rectangle3.getWidth() << "\n";
    
    rectangle3 -= rectangle2 -= rectangle1;
    cout << "\n3.";

    cout << "\nRectangle 1: L = " << rectangle1.getLength() << ", W = " << rectangle1.getWidth();
    cout << "\nRectangle 2: L = " << rectangle2.getLength() << ", W = " << rectangle2.getWidth();
    cout << "\nRectangle 3: L = " << rectangle3.getLength() << ", W = " << rectangle3.getWidth() << "\n";
    
    cout << "\n4.";

    rectangle1 = rectangle1;
    rectangle3 = rectangle2;

    cout << "\nRectangle 1: L = " << rectangle1.getLength() << ", W = " << rectangle1.getWidth();
    cout << "\nRectangle 2: L = " << rectangle2.getLength() << ", W = " << rectangle2.getWidth();
    cout << "\nRectangle 3: L = " << rectangle3.getLength() << ", W = " << rectangle3.getWidth() << "\n\n";
    
    cout << "\n5.";

    Square square1(length1);
    Square square2(length2);

    cout << "\nSquare 1: L = " << square1.getLength();
    cout << "\nSquare 2: L = " << square2.getLength() << "\n";

    square1 = square1;
    square1 = square2;

    cout << "\nSquare 1: L = " << square1.getLength();
    cout << "\nSquare 2: L = " << square2.getLength() << "\n\n";

    return 0;
}
