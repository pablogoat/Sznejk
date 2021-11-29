#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

struct kom
{
	bool czyw=false;
	int x,y;
	char kierunek;
};

struct wisnia
{
	int x,y;
};

bool czyk(kom t[],int a,int b);
void rus(kom t[],char k);
void zwieksz(kom t[],int dlug);


int main(int argc, char** argv) {
	
	srand(time(NULL));
	kom t[200];
	wisnia pray;
	bool z=false,zle=false;
	char kier='w',xd;
	int dlu=0,p,punkty=0;
	
	t[0].x=10;
	t[0].y=10;
	t[0].kierunek='w';
	t[0].czyw=true;
	
	cin >> xd;
	

	do
	{
	  	pray.x=rand()%38+1;
		pray.y=rand()%18+1;
		for(p=0;p<=dlu;p++) if(t[p].x==pray.x && t[p].y==pray.y) break;
	}while(p<dlu);
	
	do
	{
        if(kbhit())
        {
			kier=getch();
		}

		if(t[0].kierunek == 'w' && kier == 's') kier = 'w';
		else if(t[0].kierunek == 's' && kier == 'w') kier = 's';
		else if(t[0].kierunek == 'a' && kier == 'd') kier = 'a';
		else if(t[0].kierunek == 'd' && kier == 'a') kier = 'd';
		
  		rus(t,kier);
  		
  		if(t[0].x<0||t[0].x>39 || t[0].y<0||t[0].y>19) break;
  		for(int i=1;i<=dlu;i++) if(t[0].x==t[i].x && t[0].y==t[i].y) zle=true;
  		if(dlu==198) z=true;
  		
  		p=0;
  		
		if(t[0].x==pray.x && t[0].y==pray.y)
		{
			dlu++;
			zwieksz(t,dlu);
			punkty+=dlu;
			Beep(392.0,50);
			
			do
			{
				pray.x=rand()%38+1;
				pray.y=rand()%18+1;
				for(p=0;p<=dlu;p++) if(t[p].x==pray.x && t[p].y==pray.y) break;
			}while(p<dlu);
			
		}
		
	    for(int i=0;i<=20;i++)
	    {
		    for(int j=0;j<=40;j++)
		    {
			    if(i==20) cout << "`";
			    else
			    {
				    if(t[0].x==j && t[0].y==i) cout << "D";
				    else if(czyk(t,j,i)) cout << "x";
				    else if(pray.x==j && pray.y==i) cout << "8";
				    else cout << " ";
					if(j==40) cout << "|";
		    	}
	    	}
		    cout << '\n';
        }
        
        cout << dlu+1 << '\n';
        
        Sleep(15);
        system("cls");
        
	}while(!z && !zle);
	
	if(z) cout << "barwo" << '\n';
	else cout << "xd" << '\n';
	
	cout << "Skor: " << punkty << '\n';
	
	getch();
	return 0;
}

bool czyk(kom t[],int a,int b)
{
	for(int i=1;i<100;i++)
	{
		if(t[i].czyw)
		{
			if(t[i].x==a && t[i].y==b) return true;
		}
	}
	return false;
}

void rus(kom t[],char k)
{
	for(int i=99;i>=0;i--)
	{
		if(t[i].czyw)
		{
			switch(t[i].kierunek)
			{
				case 'w':
					t[i].y-=1;
					break;
				case 's':
					t[i].y+=1;
					break;
				case 'a':
					t[i].x-=1;
					break;
				case 'd':
					t[i].x+=1;
					break;
			}
			if(i>0) t[i].kierunek=t[i-1].kierunek;
			else t[i].kierunek=k;
		}
	}
	
}

void zwieksz(kom t[],int dlug)
{
	t[dlug].czyw=true;
	t[dlug].kierunek=t[dlug-1].kierunek;
	switch (t[dlug-1].kierunek)
	{
		case 'w':
			t[dlug].x=t[dlug-1].x;
			t[dlug].y=t[dlug-1].y+1;
			break;
		case 's':
			t[dlug].x=t[dlug-1].x;
			t[dlug].y=t[dlug-1].y-1;
			break;
		case 'a':
			t[dlug].x=t[dlug-1].x+1;
			t[dlug].y=t[dlug-1].y;
			break;
		case 'd':
			t[dlug].x=t[dlug-1].x-1;
			t[dlug].y=t[dlug-1].y;
			break;
	}
}




