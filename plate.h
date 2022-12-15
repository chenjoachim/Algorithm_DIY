#ifndef PLATE_H
#define PLATE_H

#include <iostream>
using namespace std;
class Plate
{
	public:
		Plate(int h=3,int w=3);
		~Plate();
		void printPlate();
		void setPlate(int);
		void tap_cross(int,int);
		void tap_circle(int,int);
		int getID();
	private:
		int height;
		int width;
		bool **light;
		int id;
};
#endif