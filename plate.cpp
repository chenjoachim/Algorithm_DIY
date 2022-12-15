#include <iostream>
#include "plate.h"
using namespace std;
int PowerDP[25];
int Power2(int n){
	if(n==0)return 1;
	if(PowerDP[n]!=-1)return PowerDP[n];
	PowerDP[n]=2*Power2(n-1);
	return PowerDP[n];
}
Plate::Plate(int h,int w){
	height=h;
	width=w;
	id=0;
	light = new bool* [h];
	if(h!=0&&w!=0)
	{
		for(int i=0;i<h;i++)
		{
			light[i] = new bool [w];
			for(int j=0;j<w;j++)
			{
				light[i][j]=false;
			}
		}
	}
}
Plate::~Plate(){
	for(int i=0;i<height;i++)
	{
		delete[] light[i];
	}
	delete[] light;
	height=0;
	width=0;
	id=0;
}
void Plate::printPlate()
{
	int i,j;
	for(i=0;i<2*width+3;i++)
	{
		cout << "-";
	}
	cout << endl;
	for(i=0;i<height;i++)
	{
		cout << "| ";
		for(j=0;j<width;j++)
		{
			cout << (light[i][j]?'O':'X') << " ";
		}
		cout << "|" << endl;
	}
	for(i=0;i<2*width+3;i++)
	{
		cout << "-";
	}
	cout << endl;
}
void Plate::setPlate(int setup)
{
	int i,j,tmp=setup;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			light[i][j]=tmp%2;
			tmp=tmp/2;
		}
	}
	id=setup;
}
void Plate::tap_cross(int x,int y){
	int x_move[4]={1,0,-1,0};
	int y_move[4]={0,-1,0,1};
	int i,j;
	light[x][y]=!light[x][y];
	for(i=0;i<4;i++)
	{
		if(x+x_move[i]<width&&x+x_move[i]>=0&&y+y_move[i]>=0&&y+y_move[i]<height){
			light[x+x_move[i]][y+y_move[i]]=!light[x+x_move[i]][y+y_move[i]];
		}
	}
	id=0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			id+=light[i][j]*(Power2(width*i+j));
		}
	}                                  
}
void Plate::tap_circle(int x,int y){
	int x_move[8]={1,1,0,-1,-1,-1,0,1};
	int y_move[8]={0,-1,-1,-1,0,1,1,1};
	int i,j;
	light[x][y]=!light[x][y];
	for(i=0;i<8;i++)
	{
		if(x+x_move[i]<width&&x+x_move[i]>=0&&y+y_move[i]>=0&&y+y_move[i]<height){
			light[x+x_move[i]][y+y_move[i]]=!light[x+x_move[i]][y+y_move[i]];
		}
	}
	id=0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			id+=light[i][j]*(Power2(width*i+j));
		}
	}
}
int Plate::getID(){
	return id;
};