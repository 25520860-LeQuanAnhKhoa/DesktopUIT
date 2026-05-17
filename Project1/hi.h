#include <iostream>
using namespace std;

int speed = 200;

void draw() {
    cout << "DRAW OLD VERSION" << endl;
}

void moveBlock() {
    cout << "MOVE BLOCK" << endl;
}

int main() {

    draw();

    moveBlock();

    cout << "Speed = " << speed << endl;

    return 0;
}