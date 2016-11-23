//For single person
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

void swap(char [],char []);

int card1[] = { 20,20 , 80,20 , 80,100 , 20,100 , 20,20 };
int card2[] = { 90,20 , 150,20 , 150,100 , 90,100 , 90,20 };
int card3[] = { 160,20 , 220,20 , 220,100 , 160,100 , 160,20 };

char val[3][2]={ "1" , "2", "3" };

void main()
   {
   clrscr();

   char count[2]="0";
   int swapnum=0;         //for number of times to swap the cards
   int driver,mode;

   driver=DETECT;

   initgraph(&driver , &mode , "c:\tc\bgi");
   settextstyle(SMALL_FONT,HORIZ_DIR,4);
	moveto(20,380);
	outtext("THE BLUE CARDS ARE SWAPPED LEAVING WHITE");

   setfillstyle(SOLID_FILL,WHITE);
   fillpoly(5,card1);
   fillpoly(5,card2);
   fillpoly(5,card3);

   settextstyle(GOTHIC_FONT,HORIZ_DIR, 6);
   setcolor(GREEN);
   moveto(40,25);
   outtext(val[0]);
   moveto(110,25);
   outtext(val[1]);
   moveto(180,25);
   outtext(val[2]);
	int k=0;
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
      moveto(20,150);
      outtext("How many Times you want to swap:");
      cin>>k;
   do
      {
      int num=0;
      int choice[2];
      count[0]++;

      delay(1500);

      settextstyle(DEFAULT_FONT,HORIZ_DIR,1.5);
      moveto(20,200);
      outtext("No. of Times Cards have been swapped:");
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1.5);
      moveto(20 + swapnum*20,250);
      outtext(count);
      setfillstyle(SOLID_FILL,WHITE);
      fillpoly(5,card1);
      fillpoly(5,card2);
      fillpoly(5,card3);

      do
	 {
	 randomize();
	 choice[num]= (rand() + num) % 3;

	 switch(choice[num])
	    {
	    case 0:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card1);
	       break;
	    case 1:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card2);
	       break;
	    case 2:
	       setfillstyle(CLOSE_DOT_FILL,BLUE);
	       fillpoly(5,card3);
	       break;
	    }
	 num++;
	 }while(num<2);

      swap(val[(choice[0])],val[(choice[1])]);

      // cin>>k;
      }while(swapnum++ < k-1);

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   moveto(20,300);
   outtext("FIND CARD NO 2 ?");
   char ans;
   ans=getch();
   cout<<val[0][0]<<val[1][0]<<val[2][0]<<endl;
   if(ans==val[1][0])
      {
      moveto(20,350);
      outtext("HURRAY! YOU WON");
      }
   else
      {
      moveto(20,350);
      outtext("SORRY! YOU LOST");
      }

   getch();
   closegraph();
   }

void swap(char a[], char b[])
   {
   char c;
   c=a[0];
   a[0]=b[0];
   b[0]=c;
   }
