#include<stdio.h>
#include<conio.h>
void main()
{
	char ch = 'A';
	int i;
	textbackground(CYAN);
	clrscr();
	for(i=0;i<23;i++)
	{
		textcolor(i);
		gotoxy(5,i+1);
		sound(i*10);
		delay(200);
		nosound();
		cprintf("%c",ch+i);
	}

	getch();
}