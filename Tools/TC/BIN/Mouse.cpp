#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define MOUSEP 51 //mouse port
#define LEFT 1 //left button
#define RIGHT 2 //right button
#define GET 3 //code for getting mouse position and buttons
#define SHOW 1 //code for showing the mouse

union REGS in, out;

typedef struct
{
	int x;
	int y;
} coor; //structure for coordinates

void showm() //show mouse
{
	in.x.ax = SHOW;
	int86(MOUSEP, &in, &out);
}

int getb() //get mouse button
{
	in.x.ax = GET;
	int86(MOUSEP, &in, &out);

	return out.x.bx;
}

coor getcoor() //get the mouse coordinates
{
	in.x.ax = GET;
	int86(MOUSEP, &in, &out);

	coor p; //the answer
	p.x = out.x.cx;
	p.y = out.x.dx;
	return p;
}

int main()
{
	//clrscr(); //clear the screen
	showm(); //show the mouse

	while (1)
	{
		printf("The mouse is on [%d;%d], the left key is %s and the right key is %s ", getcoor().x, getcoor().y, getb() & LEFT ? "pressed" : "unpressed", getb() & RIGHT ? "pressed" : "unpressed");
		gotoxy(1, 1); //return to first position
	}
}