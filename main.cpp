#include <iostream>
#include "Circle.h"
using namespace std;

int main() {
	Circle donut; //객체 생성
	donut.setRadius(7);
	cout << "donut 면적은 " << donut.getArea() << endl;

	Circle pizza(30);
	double area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
