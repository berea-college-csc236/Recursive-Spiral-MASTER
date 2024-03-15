/* File:   Recursive-Spiral.cpp
 * Author: Jesse Walker-Schadler
 * based on https://runestone.academy/runestone/books/published/cppds/Recursion/pythondsintro-VisualizingRecursion.html
 */

#include "CTurtle.hpp"
namespace ct = cturtle;
#include <iostream> //for input & output
using namespace std; //this makes it possible to use cin and cout without std:

void spiral(ct::Turtle& rt, int len) {
    if (len > 0) {
        rt.forward(len);
        rt.right(90);
        spiral(rt, len - 5);
    }
}

int main() {
    ct::TurtleScreen scr;
    ct::Turtle rt(scr);

    cout << "You need to change screens and click on the screen." << endl;

    scr.onclick([&](int x, int y) {
        rt.penup();
        rt.goTo(x, y);
        rt.pendown();
        spiral(rt, 100);
        }, ct::MOUSEB_LEFT);

    scr.mainloop();
    return 0;
}