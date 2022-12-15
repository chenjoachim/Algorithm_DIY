#include <iostream>
#include "plate.h"
#include <queue>
using namespace std;
extern int PowerDP[25];
int Pred[512];
int Dis[512];
bool Used[512];
int checker[512];
void BFS(int s,queue<int>& Q, Plate& P){
	Q.push(s);
	int next,i,j,tmp;
	while(!Q.empty()){
		next=Q.front();
		Q.pop();
		Used[next]=true;
		//if(next==0)break;
		P.setPlate(next);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++){
				
				P.tap_cross(i,j);
				tmp=P.getID();
				if(!checker[tmp]){
					Dis[tmp]=Dis[next]+1;
					Pred[tmp]=next;
					Q.push(tmp);
					checker[tmp]++;
				}
				P.setPlate(next);
				
				P.tap_circle(i,j);
				tmp=P.getID();
				if(!checker[tmp]){
					Dis[tmp]=Dis[next]+1;
					Pred[tmp]=next;
					checker[tmp]++;
					Q.push(tmp);
				}
				P.setPlate(next);
				
			}
		}
	}
}
int main()
{
	int setup = 0;
	int id;
	queue<int> Q;
	for(int i=0;i<25;i++)PowerDP[i]=-1;
	for(int i=0;i<512;i++)Pred[i]=i;
	for(int i=0;i<512;i++)Dis[i]=999;
	for(int i=0;i<512;i++)Used[i]=false;
	for(int i=0;i<512;i++)checker[i]=0;
	Plate plate;
	cout << "hello" << endl;
	plate.printPlate();
	cout << plate.getID() << endl;
	plate.setPlate(0);
	plate.printPlate();
	id=plate.getID();
	Dis[id]=0;
	Used[id]=true;
	checker[id]=true;
	int tmp;
	/*
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++){
			plate.tap_cross(i,j);
			tmp=plate.getID();
			plate.printPlate();
			cout << tmp << endl;
			plate.setPlate(id);
			plate.tap_circle(i,j);
			tmp=plate.getID();
			plate.printPlate();
			cout << tmp << endl;
			plate.setPlate(id);
			
		}
	}
	*/
	
	BFS(id,Q,plate);
	for(int i=0;i<512;i++)
	{
		cout << Dis[i] << ", ";
		if(checker[i]>=2)cout << "Fail for " << i << endl;
	}
	/*
	id=434;
	plate.setPlate(id);
	plate.printPlate();
	while(Pred[id]!=id)
	{
		cout << Pred[id];
		plate.setPlate(Pred[id]);
		id=plate.getID();
		plate.printPlate();
	}
	*/
}