#include<stdio.h>
#include<conio.h>

void main()
{
	char ch = 'A';
	int i,j;
	clrscr();
	for(j=1;j<=80;j++)
	{
		for(i=0;i<25;i++)
		{
			sound(i*10);
			delay(20);
			nosound();
			textcolor(i);
			gotoxy(j,i+1);
			cprintf("%c",ch+i);
		}
	}

	getch();
}