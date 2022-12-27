#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
 
typedef struct coordinate
{
int x,y;
char code[4];
}PT;
 
void drawwindow();
void drawline(PT p1,PT p2);
PT setcode(PT p);
int visibility(PT p1,PT p2);
PT resetendpt(PT p1,PT p2);
 
void main()
{
int gd=DETECT,v,gm;
PT p1,p2,p3,p4,ptemp;
cout<<"\nEnter x1 and y1\n";
cin>>p1.x>>p1.y;
cout<<"\nEnter x2 and y2\n";
cin>>p2.x>>p2.y;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
drawwindow();
delay(500);
drawline(p1,p2);
delay(500);
cleardevice();
delay(500);
p1=setcode(p1);
p2=setcode(p2);
v=visibility(p1,p2);
delay(500);
switch(v)
{
case 0: drawwindow();
delay(500);
drawline(p1,p2);
break;
case 1: drawwindow();
delay(500);
break;
case 2: p3=resetendpt(p1,p2);
p4=resetendpt(p2,p1);
drawwindow();
delay(500);
drawline(p3,p4);
break;
}
delay(5000);
closegraph();
}
 
void drawwindow()
{
line(150,100,450,100);
line(450,100,450,350);
line(450,350,150,350);
line(150,350,150,100);
}
 
void drawline(PT p1,PT p2)
{
line(p1.x,p1.y,p2.x,p2.y);
}
 
PT setcode(PT p) //for setting the 4 bit code
{
PT ptemp;
if(p.y<100)
ptemp.code[0]='1'; //Top
else
ptemp.code[0]='0';
if(p.y>350)
ptemp.code[1]='1'; //Bottom
else
ptemp.code[1]='0';
if(p.x>450)
ptemp.code[2]='1'; //Right
else
ptemp.code[2]='0';
if(p.x<150)
ptemp.code[3]='1'; //Left
else
ptemp.code[3]='0';
ptemp.x=p.x;
ptemp.y=p.y;
return(ptemp);
}
 
int visibility(PT p1,PT p2)
{
int i,flag=0;
for(i=0;i<4;i++)
{
if((p1.code[i]!='0') || (p2.code[i]!='0'))
flag=1;
}
if(flag==0)
return(0);
for(i=0;i<4;i++)
{
if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
flag='0';
}
if(flag==0)
return(1);
return(2);
}
 
PT resetendpt(PT p1,PT p2)
{
PT temp;
int x,y,i;
float m,k;
if(p1.code[3]=='1')
x=150;
if(p1.code[2]=='1')
x=450;
if((p1.code[3]=='1') || (p1.code[2]=='1'))
{
m=(float)(p2.y-p1.y)/(p2.x-p1.x);
k=(p1.y+(m*(x-p1.x)));
temp.y=k;
temp.x=x;
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
if(temp.y<=350 && temp.y>=100)
return (temp);
}
if(p1.code[0]=='1')
y=100;
if(p1.code[1]=='1')
y=350;
if((p1.code[0]=='1') || (p1.code[1]=='1'))
{
m=(float)(p2.y-p1.y)/(p2.x-p1.x);
k=(float)p1.x+(float)(y-p1.y)/m;
temp.x=k;
temp.y=y;
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
return(temp);
}
else
return(p1);
}
/*
//Cohen Sutherland Line clipping Algorithm

#include<iostream>
#include<graphics.h>
using namespace std;

class lineClip 
{
private :
	int RIGHT = 2,LEFT = 1,TOP = 8,BOTTOM = 4;
	int x1,x2,y1,y2,xl,yl,xh,yh,x,y;
public : 
	int getcode(int x,int y);
	void process();
};
int lineClip :: getcode(int x,int y) 
{
	int code = 0;
	if(y>yh)
		code |= TOP;
	if(y<yl)			
		code |= BOTTOM;
	if(x<xl)
		code |= LEFT;
	if(x>xh)
		code |= RIGHT;
	return code;
}

void lineClip :: process() 
{
	int code1,code2;

	cout<<"Enter the botttom left and upper right coordinate of the rectangle : ";
	cin>>xl>>yl>>xh>>yh;

	setcolor(YELLOW);
	rectangle(xl,yl,xh,yh);

	cout<<"Enter the line coordinate :";
	cout<<"Starting Coordinate :";
	cin>>x1>>y1;
	cout<<"Ending coordinate : ";
	cin>>x2>>y2;

	setcolor(WHITE);
	line(x1,y1,x2,y2);
	delay(1000);

	code1 = getcode(x1,y1);
	code2 = getcode(x2,y2);
	int temp;

	float m;
	int flag = 0;
	while(1) 
	{
		m = (float)(y2-y1)/(x2-x1);
		if(code1 == 0 && code2 ==0) 
		{
			flag = 1;
			break;	
		} 
		else if((code1 & code2) != 0)
		{
			break;
		} 
		else 
		{
			if(code1 == 0)
				temp = code2;
			else
				temp = code1;

			if(temp & TOP)
			 {
				x = x1 + (yh-y1)/m;
				y = yh;
			}
			else if(temp & BOTTOM) 
			{
				x = x1 + (yl-y1)/m;
				y = yl;	
			}	
			else if(temp & LEFT)
			{
				y = y1 + m*(xl-x1);
				x = xl; 	
			}
			else if(temp & RIGHT)
			{
				y = y1 + m*(xh-x1);
				x = xh; 	
			}
			if(temp == code1)
			{
				x1 = x;
				y1 = y;
				code1 = getcode(x1,y2);  
			}		
			else 
			{	
				x2 = x;
				y2 = y;
				code2 = getcode(x2,y2);
			}
	     	}
	   }
	cleardevice();
	rectangle(xl,yl,xh,yh);
	setcolor(YELLOW);

	if(flag == 1)
		line(x1,y1,x2,y2);
		delay (100000);
	closegraph();
}

int main() 
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	lineClip l1;
	l1.process();
	return 0;
}

//50,150,200,450
//50,200,250,400

*/

 
 




 

