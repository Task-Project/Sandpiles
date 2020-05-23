#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>
#include <queue>
using namespace std;

//w incrise the widht of the cells
int fx=1250,fy=1250,sx=50,sy=50,w=15,x,y,col=15,RAK=4;
int mx=(fx)/w;
int my=(fy)/w;

void draw_matrix(int x,int y,int w){
	setcolor(col);
	for(int i=0;i<=x;i++)
		line(sx+w*i,sy,sx+w*i,sy+w*y);
	for(int i=0;i<=y;i++)
		line(sx,sy+w*i,sx+w*x,sy+w*i);
}

main(){
	int n_iter;
	char ch;
	cout<<"Insert the number(n) of iteration n<=50000"<<endl;
	cin>>n_iter;
	cout<<"Type y if you wanto to see it live otherwise type n"<<endl;
	cin>>ch;
	cout<<"Insert a number between 5 and 20 to set the widht of the cells"<<endl;
	cin>>w;
	if(ch=='n'){
		cin>>w;
		initwindow(fx+100,fy+100);
		draw_matrix(mx,my,w);
		long long mat[mx][my];
		for(int i=0;i<mx;i++)
			for(int j=0;j<my;j++)
				mat[i][j]=0;
		queue<pair<int,int> > q;
		mat[mx/2][my/2]=n_iter;
		do{
			while(!q.empty()){
				x=q.front().first;
				y=q.front().second;
				mat[x+1][y]++;
				mat[x-1][y]++;
				mat[x][y-1]++;
				mat[x][y+1]++;
				mat[x][y]-=4;
				q.pop();
			}
			for(int i=0;i<mx;i++)
				for(int j=0;j<my;j++)
					if(mat[i][j]>=RAK) q.push({i,j});
		}while(!q.empty());
		for(int x=0;x<mx;x++){
			for(int y=0;y<my;y++){
				setfillstyle(SOLID_FILL,mat[x][y]+1);
				floodfill(sx+x*w+1,sy+y*w+1, col);
			}
		}
		getch();
		closegraph();
	}
	else{
		int dely;
		cout<<"Insert the delay in ms (1000 = 1sec)"<<endl;
		cin>>dely;
		initwindow(fx+100,fy+100);
		draw_matrix(mx,my,w);
		long long mat[mx][my];
		for(int i=0;i<mx;i++)
			for(int j=0;j<my;j++)
				mat[i][j]=0;
		queue<pair<int,int> > q;
		mat[mx/2][my/2]=n_iter;
		do{
			while(!q.empty()){
				x=q.front().first;
				y=q.front().second;
				mat[x+1][y]++;
				mat[x-1][y]++;
				mat[x][y-1]++;
				mat[x][y+1]++;
				mat[x][y]-=4;
				setfillstyle(SOLID_FILL,mat[x+1][y]%col);
				floodfill(sx+(x+1)*w+1,sy+y*w+1, col);
				setfillstyle(SOLID_FILL,mat[x-1][y]%col);
				floodfill(sx+(x-1)*w+1,sy+y*w+1, col);
				setfillstyle(SOLID_FILL,mat[x][y+1]%col);
				floodfill(sx+x*w+1,sy+(y+1)*w+1, col);
				setfillstyle(SOLID_FILL,mat[x][y-1]%col);
				floodfill(sx+x*w+1,sy+(y-1)*w+1, col);
				setfillstyle(SOLID_FILL,mat[x][y]%col);
				floodfill(sx+x*w+1,sy+y*w+1, col);
				q.pop();
			}
			for(int i=0;i<mx;i++)
				for(int j=0;j<my;j++)
					if(mat[i][j]>=RAK) q.push({i,j});
			_sleep(dely);
		}while(!q.empty());
		getch();
		closegraph();
	}
}
