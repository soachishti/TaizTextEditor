#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
#include<process.h>

class level_2{
private :
	int m;
	int life2;
public:
	char aray2[5][10];


		level_2(){
	 aray2[5][10];
	 life2=3;

	//int m=0;
	strcpy(aray2[0],"adjlq7");
	strcpy(aray2[1],"m5s2q9");
	strcpy(aray2[2],"qgnio");
	strcpy(aray2[3],"qazedc");
	strcpy(aray2[4],"mgzpq");

	}

friend class Game;
};
class level_1{
private :
	int m;
	int life;
public:
	char aray[5][10];


		level_1(){
	 aray[5][10];
	 life=3;

	//int m=0;
	strcpy(aray[0],"this");
	strcpy(aray[1],"is");
	strcpy(aray[2],"my");
	strcpy(aray[3],"Style");
	strcpy(aray[4],"mehroz");

	}

friend class Game;
};


class Game{
private:
	int m;
public:
	void getInput(char *str) {
	char ch;
	int j = 0;
	ch=getche();
	while (ch != ' ')
	{
		str[j++] = ch;
		ch = getche();
	}
}

void check(level_1 g){
		 m=0;
	//	cout << "Press any key to start.\n ";

		int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");

	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(100,50,"PRESS ANY KEY TO START THIS GAME");

			getch();
			system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<"\t";

for(int j=0;j<5;j++){
cout << g.aray[j] << " ";

}
cout<<endl<<endl<<endl;
int start = time(NULL);
int end;

int px,py;
cout << "\t" ;
for(int i=0;i<=4;i++){

	char name[10] = {' '};
 getInput(name);
	//cout<<"-";
	//cout << "!" << name << "!";


	if(!strcmp(g.aray[i],name)) {

	//cout<<"ri8";
//	name;
	}
	else
	{
	//cout<<"\a";
	 //	cout<<" \n mistake RIGHT word is \""<<g.aray[i]<<"\"" <<" your"<<++m<<" life was gone start ";
	  //	if(i<4)
	   //	{cout<<"now start typing this word \" "<<g.aray[i+1]<<" \" \n \t" ;}

		g.life--;

	}
	if(g.life < 1){


		goto exit;


	}
	px = wherex();
	py = wherey();
	gotoxy(10,15);

	cout << "Correct: " << g.life << " - Chances: " << m;

	end = time(NULL);
	cout << " - Time elapse: " << end - start << " seconds";
	 gotoxy(px,py);
}


	cout << time(NULL) - start;

//int end = time(NULL);
//cout << end-start << endl;


if(g.life>0){
cout<<"you win \n your total life remaining  is "<<g.life;
	int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");


	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(240,170,"YOU WIN...!");

getch();
}
else{
exit:
cout<<"sorry you lose";


int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");


	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(240,170,"YOU LOSE...!");

		   getch();
}





	}



void check2(level_2 g2){
		 m=0;
     //		cout << "Press any key to start.\n ";


		int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");

	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(100,50,"PRESS ANY KEY TO START THIS GAME");

			getch();
			system("cls");


cout<<endl<<endl<<"   ";
for(int j=0;j<5;j++){
	cout << g2.aray2[j] << " ";
}
cout<<endl<<endl;

for(int i=0;i<=4;i++){
	char name[10] = {' '};
      cout<<"    " ;	getInput(name);
	cout<<"-";
	cout << "!" << name << "!";
	if(!strcmp(g2.aray2[i],name)) {

	cout<<"ri8";
//	name;
	//cin.ignore();
	//cin.clear();
	}
	else
	{
	cout<<"\a";
		cout<<" \n mistake RIGHT word is \""<<g2.aray2[i]<<"\"" <<" your"<<++m<<" life was gone start ";
		if(i<4)
		{cout<<"now start typing this word \" "<<g2.aray2[i+1]<<" \" \n \t" ;}

		g2.life2--;

	}
	if(g2.life2<1){
		goto exit;

	}
}


	//cout << time(NULL) - start;

//int end = time(NULL);
//cout << end-start << endl;


if(g2.life2>0){
cout<<"you win \n your total life remaining  is "<<g2.life2;
	int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");


	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(240,170,"YOU WIN...!");

getch();
}
else{
exit:
cout<<"sorry you lose";


int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");


	setcolor(13);
	settextstyle(8,0,2);
	outtextxy(240,170,"YOU LOSE...!");

		   getch();
}
	}

	//friend class B;
};




void main()
{
cout<<"\n \t***GAME***";
char ch='5',n[10];
Game g1,m1;
	level_1 le1;
	level_2 le2;
	int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");

while(ch!='1'||ch!='2'||ch!='3'){
     //	sy  // stem("CLS");

	int y=DETECT,m;
	initgraph(&y,&m,"\..\\bgi");
		setcolor(15);
	settextstyle(8,0,5);
	outtextxy(180,70,"TYPING TUTOR");
	setcolor(15);
	setbkcolor(4);
	settextstyle(8,0,2);
	outtextxy(240,150,"1) LEVEL 1");
	setcolor(15);
	settextstyle(8,0,2);
	outtextxy(240,190,"2) LEVEL 2");
	setcolor(15);
	settextstyle(8,0,2);
	outtextxy(240,230,"3) EXPERT LEVEL ");
	setcolor(15);
	settextstyle(8,0,2);
	outtextxy(240,270,"4) EXIT");




      //	cout<<"press 1 for simple game \n press 2 for medium level \n press 3 for expert level";

ch=getch();

switch(ch){
case '1':
 system("cls");
g1.check(le1);
break;
case '2':
system("cls");
m1.check2(le2);
break;
case '3':
	exit(1);
break;

}

}

getch();


cout<<"\n";
}

