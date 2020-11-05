#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
void ekran_f(char[][]);
void ekran_f21(char[][],char*[][],int,int);
void ekran_f22(char[][],int,int,char*[],char[],char[]);
void ekran_f3(char[][][40],char[],char*,char*[],char*[]);
void ekran_up(char[][][40],int,int*,char[],char*,char*[],char*[]);
void ekran_down(char[][][40],int,int*,char*[]);
void ekran_copy(char[][][40]);
int goat_f(int[],char*[][],int,int);
int wolf_f(int[],char*[][],int,int,int[],char[],int,int[]);
int crocodile_f(int[],char*[][],int,int,int[],char[],int,int[]);
int hedgehog_f(int[],char*[][],int,int,int*);
void armor_f(int*,char*[]);
void print(char[][]);
void konsol(char*[][],char,char[],char,char*[],int*,int*);
void aksiyon(char*[], char*[][],int,int,char[],char*[]);
void mekan_f(char*[][],int[][],int[][],int[][], int [][]);
void weather(int*);
char day[7];
int dark = 0;
int main()  
{
	struct game
	{
		int x,y;
		char *mekan[4][2000];
		char ekran[2][15][40];
		char yon[4];
		char oyuncu;
		char *env[5];
		char health[3];
		int armor;
		char *body[3];
		int goat[16][72];
		int wolf[16][24];
		int crocodile [16][100];
		int hedgehog[16][100];
	}lol;
	strcpy(day,"DAY");
	lol.x=500,lol.y=1000;
	for(int i=0;i<5;i++)
	lol.env[i]=(char*)malloc(sizeof(7));
	for(int i=0;i<3;i++)
	lol.body[i]=(char*)malloc(sizeof(7));
	strcpy(lol.env[0],"CAMP FIRE");
	strcpy(lol.env[1],"TORCH  ");
	strcpy(lol.env[2],"EMPTY   ");
	strcpy(lol.env[3],"EMPTY   ");
	strcpy(lol.env[4],"EMPTY   ");   
	lol.health[0]='O';
	lol.health[1]='O';
	lol.health[2]='O';
	lol.health[3]=' ';
	lol.health[4]=' ';
	lol.health[5]=' ';
	strcpy(lol.body[0],"EMPTY");
	strcpy(lol.body[1],"EMPTY");
	strcpy(lol.body[2],"EMPTY");
	lol.yon[0]='w';
	lol.yon[1]='a';
	lol.yon[2]='s';
	lol.yon[3]='d';
	lol.oyuncu='o';
	mekan_f(lol.mekan,lol.goat,lol.wolf,lol.hedgehog, lol.crocodile);
	ekran_f(lol.ekran[0]);
	clock_t zaman=clock();
	clock_t zaman2=clock();
	clock_t zaman3=clock();
	clock_t zaman4=clock();
	clock_t zaman5=clock();
	int early=0;
	lol.mekan[1][lol.y][lol.x ]='o';
	ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
	ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
	int speed=120000;
	while(lol.health[0]=='O')
	{
		armor_f(&lol.armor,lol.body);
		if(clock()>(zaman3+1000000000)||early==1)
		{
			if(clock()>zaman3+5000000)
			{
			weather(&early);
			ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
			ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
			zaman3=clock();
			}
		}
		if(clock()>(zaman+2000000))
		{
			for(int i=0;i<16;i++)
			if(lol.goat[i][0]!=-1)
			if(goat_f(lol.goat[i],lol.mekan,lol.x,lol.y))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
			}
			zaman=clock();
		}
		
		if(clock()>(zaman4+speed))
		{
			for(int i=0;i<16;i++)
			if(lol.hedgehog[i][0]!=-1)
			if(hedgehog_f(lol.hedgehog[i],lol.mekan,lol.x,lol.y,&speed))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
			}
			zaman4=clock();
		}
		
		if(clock()>(zaman2+500000)&&strncmp(day,"DAY",3)==0)
		{
			int w_spec[3];
        	w_spec[0]=5;
        	w_spec[1]=16;
        	w_spec[2]=8;
        	for(int i=0;i<16;i++)
        	if(lol.wolf[i][0]!=-1)
			if(wolf_f(lol.wolf[i],lol.mekan,lol.x,lol.y,lol.goat,lol.health,lol.armor,w_spec))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
				ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
			}
			zaman2=clock();
		}
		
		else if(clock()>(zaman2+200000)&&strncmp(day,"NIGHT",5)==0)
		{
			int w_spec[3];
        	w_spec[0]=25;
        	w_spec[1]=128;
	        w_spec[2]=32;
	        for(int i=0;i<16;i++)
	        if(lol.wolf[i][0]!=-1)
			if(wolf_f(lol.wolf[i],lol.mekan,lol.x,lol.y,lol.goat,lol.health,lol.armor,w_spec))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
				ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
			}
			zaman2=clock();
		}
		if(clock()>(zaman5+400000)&&strncmp(day,"DAY",3)==0)
		{
			int c_spec[3];
        	c_spec[0]=80;
        	c_spec[1]=6;
        	c_spec[2]=6;
        	for(int i=0;i<16;i++)
        	if(lol.crocodile[i][0]!=-1)
			if(crocodile_f(lol.crocodile[i],lol.mekan,lol.x,lol.y,lol.goat,lol.health,lol.armor,c_spec))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
				ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
			}
			zaman5=clock();
		}
		
			if(clock()>(zaman5+300000)&&strncmp(day,"NIGHT",5)==0)
		{
			int c_spec[3];
        	c_spec[0]=80;
        	c_spec[1]=5;
        	c_spec[2]=5;
        	for(int i=0;i<16;i++)
        	if(lol.crocodile[i][0]!=-1)
			if(crocodile_f(lol.crocodile[i],lol.mekan,lol.x,lol.y,lol.goat,lol.health,lol.armor,c_spec))
			{
				ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
				ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
			}
			zaman5=clock();
		}
		
		if(kbhit())
		{
		char eylem=getch();	
		
	    if(eylem=='x')
	    {
		    ekran_f3(lol.ekran,lol.yon,&lol.oyuncu,lol.env,lol.body);
	    }
	    
		else if(eylem=='z')
	    {
	    	aksiyon(lol.env,lol.mekan,lol.x,lol.y,lol.health,lol.body);
	    	ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
	    	ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
    	}
    	
    	else
    	{
    		    for(int i=lol.y-4;i<=lol.y+4;i++)
    			for(int j=lol.x-8;j<=lol.x+8;j++)
    			{
    				if(lol.mekan[3][i][j]=='1'||lol.mekan[3][i][j]=='5')
    				lol.mekan[3][i][j]='0';
    			}
        	konsol(lol.mekan[0],eylem,lol.yon,lol.oyuncu,lol.env,&lol.x,&lol.y);
        	if(lol.mekan[2][lol.y][lol.x]=='4')
        	{
        		for(int i=0;i<3;i++)
        		lol.health[i]='X';
        	}
    		if(strncmp(lol.env[4],"TORCH",5)==0)
    		{
    			for(int i=lol.y-2;i<=lol.y+2;i++)
    			for(int j=lol.x-4;j<=lol.x+4;j++)
    			{
    				if(lol.mekan[3][i][j]=='0')
    				lol.mekan[3][i][j]='1';
    			}
    		}
    		
    		ekran_f21(lol.ekran,lol.mekan,lol.x,lol.y);
    		ekran_f22(lol.ekran,lol.x,lol.y,lol.env,lol.health,day);
    	}
		}
	}
	printf("Game Over");
}
void ekran_f(char ekran[15][40])
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<40;j++)
		{
			if((i==1||i==11)&&(j>2&&j<20))
			ekran[i][j]='-';
			else if((j==2||j==20)&&(i>1&&i<11))
			ekran[i][j]='|';
			else if(j==39)
			ekran[i][j]='\n';
			else
			ekran[i][j]=' ';
		}
	}
	ekran[1][2]='/';
	ekran[1][20]='\\';
	ekran[11][2]='\\';
	ekran[11][20]='/';
	strcpy(&ekran[3][26],"ITEM  ");
	strcpy(&ekran[5][26],"MENU  ");
	strcpy(&ekran[7][26],"BODY  ");
	strcpy(&ekran[9][26],"EMPTY ");
}

void konsol(char *mekan[3][2000],char a,char tus[],char oyuncu,char *env[4],int *m,int *n)
{
	int x=*m,y=*n;
	char yon=a;
	if(yon==tus[0]&&y!=4)
	{
		if(mekan[1][y-1][x]==' ')
		{
		mekan[1][y][x]=' ';
		mekan[1][--y][x]=oyuncu;
		}
	}
	else if(yon==tus[1]&&x!=8)
	{
		if(mekan[1][y][x-1]==' ')
		{
		mekan[1][y][x]=' ';
		mekan[1][y][--x]=oyuncu;
		}
	}
	else if(yon==tus[2]&&y!=2995)
	{
		if(mekan[1][y+1][x]==' ')
		{
		mekan[1][y][x]=' ';
		mekan[1][++y][x]=oyuncu;
		}
	}
	else if(yon==tus[3]&&x!=2991)
	{
		if(mekan[1][y][x+1]==' ')
		{
		mekan[1][y][x]=' ';
		mekan[1][y][++x]=oyuncu;
		}
	}
		if(mekan[0][y][x]=='_'&&strncmp(env[4],"EMPTY",5)==0)
		{
			mekan[0][y][x]=' ';
			strcpy(env[4],"WOOD      ");
		}
	else if(mekan[0][y][x]=='<'||mekan[0][y][x]=='x')
		{
			if(rand()%4==0)
			{
			for(int i=0;i<4;i++)
			{
				if(strncmp(env[i],"EMPTY",5)==0)
				{
					if(mekan[0][y][x]=='<')
					strcpy(env[i],"PINE CONE");
					else if(mekan[0][y][x]=='x')
					strcpy(env[i],"SAPLING");
					break;
				}
			}
			}
			mekan[0][y][x]=' ';
		}
	*m=x,*n=y;
}

void ekran_f21(char ekran[15][40],char*mekan[4][2000],int x,int y)
{
		printf("\e[H");
		for(int i=0;i<3;i++)
		for(int j=0;j<=8;j++)
		{
			for(int k=0;k<=16;k++)
			{
				if(((j<dark||j>(8-dark)||k<2*dark||k>(16-2*dark))&&mekan[3][y-4+j][x-8+k]=='0'))
				{
					ekran[j+2][k+3]=' ';
				}
				else
				{
				if(i!=0&&mekan[i][y-4+j][x-8+k]==' ')
				{
					int a=0;
					while(i-a!=0&&mekan[i-a][y-4+j][x-8+k]==' ')
					a++;
					ekran[j+2][k+3]=mekan[i-a][y-4+j][x-8+k];
				}
				else
				ekran[j+2][k+3]=mekan[i][y-4+j][x-8+k];
			}
			}
		}	
		print(ekran);
}
void ekran_f22(char ekran[15][40],int x,int y,char*env[5],char health[5],char day[7])
{
		printf("\e[H");
		strcpy(&ekran[9][26],env[4]);
		ekran[13][3]=health[0];
		ekran[13][5]=health[1];
		ekran[13][7]=health[2];
		strncpy(&ekran[13][12],day,7);
		print(ekran);
}
void print(char ekran[15][40])
{
	printf("\e[H");
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(i>1&&i<11&&j>2&&j<20)
			{
				if(strncmp(day,"DAY",3)==0||dark<5)
				{
			if(ekran[i][j]=='M'||ekran[i][j]=='W'||ekran[i][j]=='~'||ekran[i][j]=='.')
			printf("\e[33m%c\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='4')
			printf("\e[36m~\e[0m");
			else if(ekran[i][j]=='5')
			printf("\e[1;30m~\e[0m");
			else if(ekran[i][j]=='x')
			printf("\e[1;32mx\e[0m");
			else if(ekran[i][j]=='k')
			printf("\e[1m*\e[0m");
			else if(ekran[i][j]=='j')
			printf("\e[1m=\e[0m");
			else if(ekran[i][j]=='J')
			printf("\e[1m-\e[0m");
			else if(ekran[i][j]=='0')
			printf("\e[33mV\e[0m");
			else if(ekran[i][j]=='1')
			printf("\e[33mv\e[0m");
			else if(ekran[i][j]=='2')
			printf("\e[32mV\e[0m");
			else if(ekran[i][j]=='3')
			printf("\e[32mv\e[0m");
			else if(ekran[i][j]=='*')
			printf("\e[93m*\e[0m");
			else if(ekran[i][j]=='^'||ekran[i][j]=='<'||ekran[i][j]=='#'||ekran [i][j]=='='||ekran [i][j]==','||ekran [i][j]=='-')
			printf("\e[32m%c\e[0m",ekran[i][j]);
			else if (ekran [i][j]=='8')
			printf("\e[32m¥\e[0m");
			else if(ekran[i][j]=='I'||ekran[i][j]=='|'||ekran[i][j]=='\\'||ekran[i][j]=='/'||ekran[i][j]=='='||ekran[i][j]=='+'||ekran[i][j]=='c')
			printf("\e[2;31m%c\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='7')
			printf("\e[2;31mI\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='o'||ekran[i][j]=='6'||ekran[i][j]=='9')
			printf("\e[35m%c\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='_')
			printf("\e[31m_\e[0m");
			else if(ekran[i][j]=='O')
			printf("\e[1;30mO\e[0m");
			else if(ekran[i][j]=='X')
			printf("\e[90mX\e[0m");
			else if(ekran[i][j]=='G')
			printf("\e[1;33mG\e[0m");
			else if(ekran[i][j]=='q'||ekran[i][j]=='p'||ekran[i][j]=='u'||ekran[i][j]=='b')
			printf("\e[1;30m%c\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='d'||ekran[i][j]=='n')
			printf("\e[1;30m%c\e[0m",ekran[i][j]);
			else
			printf("%c",ekran[i][j]);
			}
			else if(strncmp(day,"NIGHT",5)==0&&dark==5)
			{
			if(ekran[i][j]=='4')
			printf("\e[36m~\e[0m");
			else if(ekran[i][j]=='5')
			printf("\e[36m~\e[0m");
			else if(ekran[i][j]=='0')
			printf("\e[36mV\e[0m");
			else if(ekran[i][j]=='1')
			printf("\e[36mv\e[0m");
			else if(ekran[i][j]=='2')
			printf("\e[36mV\e[0m");
			else if(ekran[i][j]=='3')
			printf("\e[36mv\e[0m");
			else if(ekran[i][j]=='7')
			printf("\e[36mI\e[0m");
			else if(ekran[i][j]=='8')
			printf("\e[36m¥\e[0m");
			else
			printf("\e[1;36m%c\e[0m",ekran[i][j]);
			}
			}
			else
			{
			if(ekran[i][j]=='O'&&j<8)
			printf("\e[31m%c\e[0m",ekran[i][j]);
			else if(ekran[i][j]=='X'&&j<8)
			printf("\e[1;30m%c\e[0m",ekran[i][j]);
			else
			printf("%c",ekran[i][j]);
			}
		}
		
	}
}

void ekran_f3(char ekran[][15][40],char yon[4],char *oyuncu,char *env[5],char *body[3])
{
	static int h=0;
	ekran_copy(ekran);
	strcpy(&ekran[1][3][23],"->");
	print(ekran[1]);
	int z=3;
	while(1)
	{
		char a=getch();
		if(a=='s'&&ekran[1][z+2][27]!=' ')
		{
			strcpy(&ekran[1][z][23],"  ");
			strcpy(&ekran[1][z=z+2][23],"->");
			print(ekran[1]);
		}
		else if(a=='w'&&ekran[1][z-2][27]!=' ')
		{
			strcpy(&ekran[1][z][23],"  ");
			strcpy(&ekran[1][z=z-2][23],"->");
			print(ekran[1]);
		}
		else if(a=='x')
		{
			strcpy(&ekran[1][z][23],"  ");
			ekran_up(ekran,z,&h,yon,oyuncu,env,body);
			z=3;
			strcpy(&ekran[1][z][23],"->");
			print(ekran[1]);
		}
		else if(a=='e'&&(h!=0||z==9))
		{
			strcpy(&ekran[1][z][23],"  ");
			ekran_down(ekran,z,&h,env);
			z=3;
			strcpy(&ekran[1][z][23],"->");
			print(ekran[1]);
		}
		else if(a=='e'&&h==0)
		{
			strcpy(&ekran[1][z][23],"  ");
			print(ekran[1]);
			break;
		}
	}
}
void ekran_up(char ekran[][15][40],int z,int *h,char yon[],char *oyuncu,char *env[5],char*body[3])
{
	ekran_copy(ekran);
	if(z==3&&*h==0)
	{
		strcpy(&ekran[1][3][26],env[0]);
		strcpy(&ekran[1][5][26],env[1]);
		strcpy(&ekran[1][7][26],env[2]);
		strcpy(&ekran[1][9][26],env[3]);
		*h=10;
	}
	else if(*h==10)
	{
		char temp[7]="       ";
		strcpy(temp,env[4]);
		if(z==3)
		{
		strcpy(env[4],env[0]);
		strcpy(env[0],temp);
		}
		else if(z==5)
		{
		strcpy(env[4],env[1]);
		strcpy(env[1],temp);
		}
		else if(z==7)
		{
		strcpy(env[4],env[2]);
		strcpy(env[2],temp);
		}
		else if(z==9)
		{
		strcpy(env[4],env[3]);
		strcpy(env[3],temp);
		}
		*h=0;
	}
	else if(z==5&&*h==0)
	{
		strcpy(&ekran[1][3][26],"MOVE  ");
		strcpy(&ekran[1][5][26],"PLAYER");
		strcpy(&ekran[1][7][26],"SCREEN");
		strcpy(&ekran[1][9][26],"            ");
		*h=1;
	}
	else if(z==3&&*h==1)
	{
		strcpy(&ekran[1][3][26],"UP        ");
		strcpy(&ekran[1][5][26],"LEFT    ");
		strcpy(&ekran[1][7][26],"DOWN  ");
		strcpy(&ekran[1][9][26],"RIGHT  ");
		*h=2;
	}
	else if(z==7&&*h==1)
	{
		strcpy(&ekran[1][3][26],"SQUARE");
		strcpy(&ekran[1][5][26],"FISHEYE");
		strcpy(&ekran[1][7][26],"            ");
		strcpy(&ekran[1][9][26],"            ");
		*h=4;
	}
	else if(*h==4)
	{
		if(z==3)
		{
		for(int i=0;i<15;i++)
    	{
		for(int j=0;j<35;j++)
		{
			if((i==1||i==11)&&(j>2&&j<20))
			ekran[0][i][j]='-';
			else if((j==2||j==20)&&(i>1&&i<11))
			ekran[0][i][j]='|';
		}
    	}
    	*h=0;
		}
		if(z==5)
		{
			for(int i=0;i<15;i++)
    	{
		for(int j=0;j<40;j++)
		{
			if((i==1||i==11)&&(j>2&&j<20))
			ekran[0][i][j]=' ';
			else if((j==2||j==20)&&(i>1&&i<11))
			ekran[0][i][j]=' ';
		}
    	}
		}
		*h=0;
	}
	else if(*h==2)
	{
		printf("gir:");
		if(z==3)
		scanf("%c",&yon[0]);
		else if(z==5)
		scanf("%c",&yon[1]);
		else if(z==7)
		scanf("%c",&yon[2]);
		else if(z==9)
		scanf("%c",&yon[3]);
		*h=0;
	}
	else if(z==5&&*h==1)
	{
		strcpy(&ekran[1][3][26],"NORMAL");
		strcpy(&ekran[1][5][26],"CLASSIC");
		strcpy(&ekran[1][7][26],"VIRTUAL");
		strcpy(&ekran[1][9][26],"            ");
		*h=3;
	}
	else if(*h==3)
	{
		if(z==3)
		*oyuncu='o';
		else if(z==5)
		*oyuncu='#';
		else if(z==7)
		*oyuncu='@';
		*h=0;
	}
	else if(*h==0&&z==9)
	{
		for(int i=0;i<4;i++)
		{
			if(strncmp(env[i],"EMPTY",5)==0)
			{
				strcpy(env[i],env[4]);
				strcpy(env[4],"EMPTY    ");
				*h=0;
				break;
			}
		}
	}
	else if(*h==0&&z==7)
	{
		if(strncmp(body[0],"EMPTY",5)==0)
		strcpy(&ekran[1][3][26],"HEAD ");
		else
		strcpy(&ekran[1][3][26],body[0]);
		if(strncmp(body[1],"EMPTY",5)==0)
		strcpy(&ekran[1][5][26],"BODY ");
		else
		strcpy(&ekran[1][5][26],body[1]);
		if(strncmp(body[2],"EMPTY",5)==0)
		strcpy(&ekran[1][7][26],"BOTS  ");
		else
		strcpy(&ekran[1][7][26],body[2]);
		strcpy(&ekran[1][9][26],"            ");
		*h=8;
	}
	else if(*h==8&&strncmp(env[4],"EMPTY",5)==0)
	{
		if(z==3)
		{
			strcpy(env[4],body[0]);
			strcpy(body[0],"EMPTY");
		}
		if(z==5)
		{
			strcpy(env[4],body[1]);
			strcpy(body[1],"EMPTY");
		}
		if(z==7)
		{
			strcpy(env[4],body[2]);
			strcpy(body[2],"EMPTY");
		}
		*h=0;
	}
}

void ekran_down(char ekran[][15][40],int z,int *h,char*env[5])
{
	ekran_copy(ekran);
	if(*h==2||*h==3)
	{
		strcpy(&ekran[1][3][26],"MOVE  ");
		strcpy(&ekran[1][5][26],"PLAYER");
		strcpy(&ekran[1][7][26],"SCREEN");
		strcpy(&ekran[1][9][26],"            ");
		*h=1;
	}
	else if(*h==10||*h==1||*h==8)
	{
		strcpy(&ekran[1][3][26],"ITEM  ");
		strcpy(&ekran[1][5][26],"MENU");
		strcpy(&ekran[1][7][26],"BODY ");
		strcpy(&ekran[1][9][26],env[4]);
		*h=0;
	}
	else if(*h==0&&z==9)
	{
		strcpy(env[4],"EMPTY    ");
		*h=0;
	}
}
void ekran_copy(char ekran[][15][40])
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<40;j++)
		ekran[1][i][j]=ekran[0][i][j];
	}
}

void mekan_f(char*mekan[3][2000],int goat[16][72],int wolf[16][24],int hedgehog[16][100], int crocodile [16][100])
{
	srand(time(NULL));
	printf(" Loading...\n ");
	for(int i=0;i<3;i++)
	for(int j=0;j<2000;j++)
	{
		mekan[i][j]=(char*)malloc(2000);
		for(int k=0;k<40;k++)
		strcat(mekan[i][j],"                                                  ");
	}
	for(int j=0;j<2000;j++)
	{
		mekan[3][j]=(char*)malloc(2000);
		for(int k=0;k<40;k++)
		strcat(mekan[3][j],"00000000000000000000000000000000000000000000000000");
	}
	for(int m=0;m<4;m++)
	for(int n=0;n<4;n++)
	{
		int biome=m;
		if(biome==3)
		{
		for(int i=0;i<20000;i++)
    	{
    		int flower1=m*500 + rand()%505 - 5;
    		int flower2=n*500 + rand()%500;
    		mekan[0][flower1][flower2]='.';
    	}
    	for(int i=0;i<5000;i++)
    	{
    		int cactus1 = m*500 + rand()%480 +10;
    		int cactus2 = n*500 + rand()%500;
    		mekan[1][cactus1][cactus2]='#';
    	}
    	for(int i=0;i<100;i++)
        	{
        		int rock1=m*500 + 50+rand()%400;
        		int rock2=n*500 + 50+rand()%400;
        		for(int j=0;j<3;j++)
        		{
        		    int rock3=rock1+rand()%2;
    		    	int rock4=rock2+rand()%4;
    	    		mekan[2][rock3][rock4]='5';
    		    	mekan[2][rock3+1][rock4]='5';
    	    		mekan[2][rock3-1][rock4]='5';
    		    	mekan[2][rock3][rock4+1]='5';
    	    		mekan[2][rock3][rock4-1]='5';
    	    		strncpy(&mekan[1][rock1-1][rock2-1],"   ",3);
    	            strncpy(&mekan[1][rock1-2][rock2-1],"   ",3);
        		}
        	}
		hedgehog[4*m+n][0]=-1;
		crocodile [4*m+n][0]=-1;
		wolf[4*m+n][0]=-1;
    	goat[4*m+n][0]=-1;
		}
		else if(biome==2)
		{
    	for(int i=0;i<40;i++)
    	{
    		int merkez1=20 + m*500 + rand()%460;
    		int merkez2=20 + n*500 + rand()%460;
    		mekan[1][merkez1+1][merkez2+1]='c';
		
    		int h=8+rand()%3;
    		for(int i=0;i<h;i++)
    		mekan[1][merkez1][merkez2+i]='X';
    		int z=h;
		
    		h=3+rand()%2;
    		for(int i=0;i<h;i++)
    		mekan[1][merkez1+i][merkez2+z]='X';
    		z=h;
		
    		h=5+rand()%2;
    		for(int i=0;i<h;i++)
    		mekan[1][merkez1+i][merkez2]='X';
    		z=h;
		
    		h=5+rand()%3;
    		for(int i=0;i<h;i++)
    		mekan[1][merkez1+z][merkez2+i]='X';
    	}
    		for(int i=0;i<200;i++)
        	{
        		int rock1=m*500 + 50+rand()%400;
        		int rock2=n*500 + 50+rand()%400;
        		for(int j=0;j<3;j++)
        		{
        		    int rock3=rock1+rand()%2;
    		    	int rock4=rock2+rand()%4;
    	    		mekan[1][rock3][rock4]='O';
    		    	mekan[1][rock3+1][rock4]='O';
    	    		mekan[1][rock3-1][rock4]='O';
    		    	mekan[1][rock3][rock4+1]='O';
    	    		mekan[1][rock3][rock4-1]='O';
    		    	if(rand()%3==0)
    	    		mekan[1][rock3][rock4]='G';
        		}
    	}
    	
    	for(int i=0;i<8000;i++)
    	{
    		int grass1=m*500 + rand()%510 -5;
    		int grass2=n*500 + rand()%499;
    		mekan[2][grass1][grass2] = '0';
    		mekan[2][grass1][grass2+1] = '1';
    	}
    	
    	for(int i=0;i<200;i++)
    	{
    		int tree1=m*500 + rand()%500;
    		int tree2=n*500 + rand()%480 +10;
    		mekan[1][tree1][tree2]='I';
    		strncpy(&mekan[2][tree1-1][tree2-1],"\\|/",3);
    		mekan[2][tree1-2][tree2]='|';
    	}
    	
    	for(int i=0;i<24;i+=2)
    	{
    	wolf[4*m+n][i]=m*500+20+rand()%460;
    	wolf[4*m+n][i+1]=n*500+20+rand()%460;
    	strncpy(&mekan[1][wolf[4*m+n][i]][wolf[4*m+n][i+1]],"dn",2);
    	}
    	
    	for(int i=0;i<72;i+=2)
    	{
    	goat[4*m+n][i]=m*500+20+rand()%460;
    	goat[4*m+n][i+1]=n*500+20+rand()%460;
    	strncpy(&mekan[1][goat[4*m+n][i]][goat[4*m+n][i+1]],"6qq",3);
    	}
    	
    	for(int i=0;i<20;i++)
    	{
    		int fossil1=m*500 + rand()%510 -5;
    		int fossil2=n*500 + rand()%499;
    		mekan[1][fossil1][fossil2] = 'j';
    		mekan[1][fossil1][fossil2+1] = 'k';
    		mekan[0][fossil1][fossil2+3] = 'j';
    		mekan[0][fossil1][fossil2+5] = 'J';
    		mekan [0][fossil1][fossil2+6] = 'J';
    	}
 
    	hedgehog[4*m+n][0]=-1;
    	crocodile [4*m+n][0]=-1;
		}
		
    	else if(biome==0)
    	{
    	for(int i=0;i<5000;i++)
    	{
    		int flower1=m*500 + rand()%505;
    		int flower2=n*500 + rand()%500;
    		mekan[0][flower1][flower2]='*';
    	}
	
	
    	for(int i=0;i<40;i++)
    	{
    		int rock1=m*500 + 50+rand()%400;
    		int rock2=n*500 + 50+rand()%400;
    		for(int j=0;j<3;j++)
    		{
    		    int rock3=rock1+rand()%2;
    			int rock4=rock2+rand()%4;
    			mekan[1][rock3][rock4]='O';
		    	mekan[1][rock3+1][rock4]='O';
    			mekan[1][rock3-1][rock4]='O';
    			mekan[1][rock3][rock4+1]='O';
    			mekan[1][rock3][rock4-1]='O';
    		}
    	}
    	
    	for(int i=0;i<2000;i++)
    	{
    		int tree1=m*500 + rand()%480+10;
    		int tree2=n*500 + rand()%480+10;
    		if(strncmp(&mekan[2][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[2][tree1-1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[2][tree1-2][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[1][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[1][tree1-1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[1][tree1-2][tree2-1],"   ",3)==0)
    		{
    		mekan[1][tree1][tree2]='I';
    		strncpy(&mekan[2][tree1-1][tree2-1],"^^^",3);
    		mekan[2][tree1-2][tree2]='^';
    		}
    	}
    	
    	for(int i=0;i<100;i+=2)
    	{
    	hedgehog[4*m+n][i]=m*500+20+rand()%460;
    	hedgehog[4*m+n][i+1]=n*500+20+rand()%460;
    	strncpy(&mekan[1][hedgehog[4*m+n][i]][hedgehog[4*m+n][i+1]],"oM",2);
    	}
    	wolf[4*m+n][0]=-1;
    	goat[4*m+n][0]=-1;
    	crocodile [4*m+n][0]=-1;
	}
	else if(biome==1 && (n == 1 || n == 3))
	{
        for(int i=0;i<10000;i++)
    	{
    		int grass1=m*500 + rand()%510-5;
    		int grass2=n*500 + rand()%499;
    		if(strncmp(&mekan[1][grass1][grass2],"  ",2)==0)
    		if(strncmp(&mekan[2][grass1][grass2],"  ",2)==0)
    		{
    		mekan[2][grass1][grass2] = '2';
    		mekan[2][grass1][grass2+1] = '3';
    		}
    	}
    	for(int i=0;i<8000;i++)
    	{
    		int tree1=m*500 + rand()%480+10;
    		int tree2=n*500 + rand()%480+10;
    		if(strncmp(&mekan[2][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[2][tree1-1][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[2][tree1-2][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[1][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[1][tree1-1][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[1][tree1-2][tree2-2],"     ",5)==0)
    		{
    		mekan[1][tree1][tree2]='I';
    	    strncpy(&mekan[2][tree1-1][tree2-1],"xxx",3);
    	    strncpy(&mekan[2][tree1-2][tree2-1],"xxx",3);
    		}
    	}
    		for(int i=0;i<5000;i++)
    	{
    		int hemp1=m*500 + 10 + rand()%480;
    		int hemp2=n*500 + rand()%499;
    		if(mekan[1][hemp1][hemp2]==' ')
    		if(mekan[2][hemp1][hemp2]==' ')
    		{
    		mekan[2][hemp1][hemp2] = '8';
    		}
    	}
		hedgehog[4*m+n][0]=-1;
		wolf[4*m+n][0]=-1;
    	goat[4*m+n][0]=-1;
    	crocodile [4*m+n][0]=-1;
	}
	
	else if(biome==1 && (n == 0 || n == 2))
	{
    	for(int i=0;i<3000;i++)
        	{
        		int rock1=m*500 + 10+rand()%480;
        		int rock2=n*500 + 10+rand()%480;
        		for(int j=0;j<3;j++)
        		{
        		    int rock3=rock1+rand()%2;
    		    	int rock4=rock2+rand()%4;
    	    		mekan[2][rock3][rock4]='4';
    		    	mekan[2][rock3+1][rock4]='4';
    	    		mekan[2][rock3-1][rock4]='4';
    		    	mekan[2][rock3][rock4+1]='4';
    	    		mekan[2][rock3][rock4-1]='4';
        		}
        	}
        for(int i=0;i<20000;i++)
    	{
    		int grass1=m*500 + rand()%510-5;
    		int grass2=n*500 + rand()%499;
    		if(strncmp(&mekan[1][grass1][grass2],"  ",2)==0)
    		if(strncmp(&mekan[2][grass1][grass2],"  ",2)==0)
    		{
    		mekan[2][grass1][grass2] = '2';
    		mekan[2][grass1][grass2+1] = '3';
    		}
    	}
    	for(int i=0;i<2000;i++)
    	{
    		int tree1=m*500 + rand()%480+10;
    		int tree2=n*500 + rand()%480+10;
    		if(strncmp(&mekan[2][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[2][tree1-1][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[2][tree1-2][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[1][tree1][tree2-1],"   ",3)==0)
    		if(strncmp(&mekan[1][tree1-1][tree2-2],"     ",5)==0)
    		if(strncmp(&mekan[1][tree1-2][tree2-2],"     ",5)==0)
    		{
    		mekan[1][tree1][tree2]='I';
    	    strncpy(&mekan[2][tree1-1][tree2-1],"xxx",3);
    	    strncpy(&mekan[2][tree1-2][tree2-1],"xxx",3);
    		}
    	}
    
    	
		hedgehog[4*m+n][0]=-1;
		wolf[4*m+n][0]=-1;
    	goat[4*m+n][0]=-1;
    	for(int i=0;i<100;i+=2)
    	{
    	crocodile[4*m+n][i]=m*500+20+rand()%460;
    	crocodile[4*m+n][i+1]=n*500+20+rand()%460;
    	strncpy(&mekan[1][crocodile[4*m+n][i]][crocodile[4*m+n][i+1]],"=*,=,--",7);
    	}
	}
	}
}

void aksiyon(char *env[5],char*mekan[4][2000],int x,int y, char health[3],char*body[3])
{
	if(strncmp(env[4],"WOOD",4)==0&&mekan[0][y-1][x]=='~')
	{
		mekan[1][y-1][x]='+';
		for(int i=y-4;i<=y+2;i++)
		for(int j=x-6;j<=x+6;j++)
		mekan[3][i][j]='2';
		strcpy(env[4],"EMPTY");
	}
	else if(strncmp(env[4],"WOOD",4)==0&&mekan[1][y-1][x]==' ')
	{
		mekan[1][y-1][x]='7';
		strcpy(env[4],"EMPTY");
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&mekan[1][y-1][x]=='7')
	{
				strcpy(env[4],"WOOD ");
				mekan[1][y-1][x]=' ';
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&mekan[1][y-1][x]=='k')
	{
				strcpy(env[4],"SKULL");
				mekan[1][y-1][x]=' ';
				mekan[1][y-1][x-1]=' ';
	}
	else if(mekan[1][y-1][x]=='c')
	{
		srand(time(NULL));
		mekan[1][y-1][x]=' ';
		int esya=rand()%5;
		char item[7];
		if(esya==0)
		strcpy(item,"AXE  ");
		if(esya==1)
		strcpy(item,"MINE  ");
		if(esya==2)
		strcpy(item,"SAPLING");
		if(esya==3)
		strcpy(item,"PAPER");
		if(esya==4)
		strcpy(item,"SHOVEL");
		for(int i=0;i<4;i++)
		{
			if(strncmp(env[i],"EMPTY",5)==0)
			{
			strcpy(env[i],item);
			break;
			}
		}
	}
	else if(strncmp(env[4],"AXE",3)==0&&mekan[1][y-1][x]=='I'&&mekan[2][y-2][x]=='x')
	{
		mekan[1][y-1][x]=' ';
		strncpy(&mekan[2][y-3][x-1],"   ",3);
		strncpy(&mekan[2][y-2][x-1],"   ",3);
		strncpy(&mekan[0][y-1][x-2],"xx_",3);
	}
	else if(strncmp(env[4],"AXE",3)==0&&mekan[1][y-1][x]=='I'&&mekan[2][y-2][x]=='^')
	{
		mekan[2][y-3][x]=' ';
		mekan[1][y-1][x]=' ';
		strncpy(&mekan[2][y-2][x-1],"   ",3);
		strncpy(&mekan[0][y-1][x-2],"<<_",3);
	}
	 else if(strncmp(env[4],"AXE",3)==0&&mekan[1][y-1][x]=='I'&&mekan[2][y-2][x]=='|')
	{
		mekan[2][y-3][x]=' ';
		mekan[1][y-1][x]=' ';
		mekan[0][y-2][x-1]='_';
		strncpy(&mekan[0][y-1][x-2],"_ _",3);
		strncpy(&mekan[2][y-2][x-1],"   ",3);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&mekan[2][y-1][x]=='8')
	{
		strcpy(env[4],"HEMP  ");
		mekan[2][y-1][x]=' ';
	}
	else if (strncmp (env [4],"HEMP",4)==0)
	{
		strcpy (env [4],"EMPTY   ");
		int bar=2;
		while(health[bar]!='O')
		bar--;
		health[bar]='X';
		printf("\e[H\e[J");
		printf("----------------------\n");
		printf("\nSMOKE WEED EVERY DAY!\n\n\n");
		printf ("            ~                  \n");
		printf ("          ~            \n");
		printf ("            ~                 \n");
		printf ("      /\\___o__            \n");
		printf (" ¥     /            ¥   \n");
		printf ("      /           ¥        \n");
		printf("----------------------\n");
		if (strncmp (day,"NIGHT",5)==0)
		{
			strcpy (day,"DAY");
			dark = 0;
		}
		else
		{
			strcpy (day,"NIGHT");
			dark = 5;
		}
		clock_t sleep = clock ();
		while (clock () < sleep + 4000000)
		{}
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&mekan[2][y-1][x]=='0')
	{
		strcpy(env[4],"GRASS");
		mekan[2][y-1][x]='1';
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&mekan[2][y-1][x]=='2')
	{
		strcpy(env[4],"GRASS");
		mekan[2][y-1][x]='3';
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[0][y-1][x],"~",1)==0)
	{
		strcpy(env[4],"GRASS");
		strncpy(&mekan[0][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"GRASS",5)==0&&strncmp(&mekan[1][y-1][x]," ",1)==0)
	{
		strcpy(env[4],"EMPTY");
		strncpy(&mekan[0][y-1][x],"~",1);
	}
	else if(strncmp(env[4],"AXE",3)==0)
	{
		if(strncmp(&mekan[1][y-1][x],"6qq",3)==0)
		strncpy(&mekan[1][y-1][x],"bb9",3);
		else if(strncmp(&mekan[1][y+1][x],"6qq",3)==0)
		strncpy(&mekan[1][y+1][x],"bb9",3);
		else if(strncmp(&mekan[1][y][x+1],"6qq",3)==0)
		strncpy(&mekan[1][y][x+1],"bb9",3);
		
		else if(strncmp(&mekan[1][y-1][x],"dn",2)==0)
		strncpy(&mekan[1][y-1][x],"qu",2);
		else if(strncmp(&mekan[1][y-1][x-1],"nb",2)==0)
		strncpy(&mekan[1][y-1][x],"up",2);
		else if(strncmp(&mekan[1][y+1][x],"dn",2)==0)
		strncpy(&mekan[1][y+1][x],"qu",2);
		else if(strncmp(&mekan[1][y+1][x-1],"nb",2)==0)
		strncpy(&mekan[1][y+1][x],"up",2);
		else if(strncmp(&mekan[1][y][x+1],"dn",2)==0)
		strncpy(&mekan[1][y][x+1],"qu",2);
		else if(strncmp(&mekan[1][y][x-2],"nb",2)==0)
		strncpy(&mekan[1][y][x-2],"up",2);
		
		else if(strncmp(&mekan[1][y-1][x],"oM",2)==0)
		strncpy(&mekan[1][y-1][x]," W",2);
		else if(strncmp(&mekan[1][y-1][x-1],"Mo",2)==0)
		strncpy(&mekan[1][y-1][x],"W ",2);
		else if(strncmp(&mekan[1][y+1][x],"oM",2)==0)
		strncpy(&mekan[1][y+1][x]," W",2);
		else if(strncmp(&mekan[1][y+1][x-1],"Mo",2)==0)
		strncpy(&mekan[1][y+1][x],"W ",2);
		else if(strncmp(&mekan[1][y][x+1],"oM",2)==0)
		strncpy(&mekan[1][y][x+1]," W",2);
		else if(strncmp(&mekan[1][y][x-2],"Mo",2)==0)
		strncpy(&mekan[1][y][x-2],"W ",2);
		
		else if(mekan[1][y-1][x]=='M')
		{
		int i=3;
		while(health[i]!='O')
		i--;
		health[i]='X';
		}
		else if(mekan[1][y+1][x]=='M')
		{
		int i=3;
		while(health[i]!='O')
		i--;
		health[i]='X';
		}
		else if(mekan[1][y][x+1]=='M')
		{
		int i=3;
		while(health[i]!='O')
		i--;
		health[i]='X';
		}
		else if(mekan[1][y][x-1]=='M')
		{
		int i=3;
		while(health[i]!='O')
		i--;
		health[i]='X';
		}
		
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x-1],"bb",2)==0)
	{
		strcpy(env[4],"MEAT ");
		strncpy(&mekan[1][y-1][x-1],"  ",2);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x],"9",1)==0)
	{
		strcpy(env[4],"*GOAT HEAD");
		strncpy(&mekan[1][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x],"p",1)==0)
	{
		strcpy(env[4],"*WOLF HEAD");
		strncpy(&mekan[1][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x],"q",1)==0)
	{
		strcpy(env[4],"*WOLF HEAD");
		strncpy(&mekan[1][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x],"u",1)==0)
	{
		strcpy(env[4],"&WOLF FUR");
		strncpy(&mekan[1][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"EMPTY",5)==0&&strncmp(&mekan[1][y-1][x],"W",1)==0)
	{
		strcpy(env[4],"&THORNMAIL");
		strncpy(&mekan[1][y-1][x]," ",1);
	}
	else if(strncmp(env[4],"*",1)==0&&strncmp(body[0],"EMPTY",5)==0)
		{
			strcpy(body[0],env[4]);
			strcpy(env[4],"EMPTY     ");
		}
	else if(strncmp(env[4],"&",1)==0&&strncmp(body[1],"EMPTY",5)==0)
		{
			strcpy(body[1],env[4]);
			strcpy(env[4],"EMPTY     ");
		}
	else if(strncmp(env[4],"SHOVEL",6)==0&&mekan[1][y-1][x]==' '&&mekan[0][y-1][x]==' ')
	{
		mekan[0][y-1][x]='=';
	}
	else if(strncmp(env[4],"SHOVEL",6)==0&&mekan[0][y-1][x]=='*')
	{
		mekan[0][y-1][x]=' ';
		for(int i=0;i<4;i++)
		{
			if(strncmp(env[i],"EMPTY",5)==0)
			{
			strncpy(env[i],"FLOWER",6);
			break;
			}
		}
	}
	else if(strncmp(env[4],"CAMP FIRE",9)==0&&mekan[1][y-1][x]==' ')
	{
		mekan[1][y-1][x]='+';
		for(int i=y-4;i<=y+2;i++)
		for(int j=x-6;j<=x+6;j++)
		mekan[3][i][j]='2';
		strcpy(env[4],"EMPTY     ");
	}
	else if(strncmp(env[4],"WOOD",4)==0&&mekan[1][y-1][x]=='+')
	{
		strcpy(env[4],"TORCH");
	}
	else if(strncmp(env[4],"FLOWER",6)==0&&mekan[0][y-1][x]==' ')
	{
		mekan[0][y-1][x]='*';
		strcpy(env[4],"EMPTY");
	}
	else if(strncmp(env[4],"MEAT",4)==0&&mekan[1][y-1][x]=='+')
	{
		strncpy(env[4],"COOKED MEAT",11);
	}
	else if(strncmp(env[4],"COOKED MEAT",11)==0)
	{
		int i=0;
		while(health[i]!='X'&&i<3)
		i++;
		health[i]='O';
		strcpy(env[4],"EMPTY     ");
	}
	else if(strncmp(env[4],"SEED",4)==0&&mekan[0][y-1][x]=='=')
	{
		mekan[0][y-1][x]='-';
		strcpy(env[4],"EMPTY");
	}
	else if(strncmp(env[4],"PINE CONE",7)==0&&mekan[1][y-1][x]==' ')
	{
		mekan[1][y-1][x]='I';
		mekan[2][y-2][x]='^';
		mekan[2][y-2][x-1]='^';
		mekan[2][y-2][x+1]='^';
		mekan[2][y-3][x]='^';
		strcpy(env[4],"EMPTY    ");
	}
	else if(strncmp(env[4],"SAPLING",7)==0&&mekan[1][y-1][x]==' ')
	{
		mekan[1][y-1][x]='I';
		strncpy(&mekan[2][y-2][x-1],"xxx",3);
		strncpy(&mekan[2][y-3][x-1],"xxx",3);
		strcpy(env[4],"EMPTY    ");
	}
	else if(strncmp(env[4],"MINE",4)==0)
	{
		for(int i=0;i<4;i++)
		{
			if(strncmp(env[i],"EMPTY",5)==0)
			{
				if(mekan[1][y-1][x]=='O')
				{
				strcpy(env[i],"ROCK   ");
				mekan[1][y-1][x]=' ';
				break;
				}
				if(mekan[1][y-1][x]=='X')
				{
				strcpy(env[i],"WALL   ");
				mekan[1][y-1][x]=' ';
				break;
				}
				if(mekan[1][y-1][x]=='G')
				{
				strcpy(env[i],"GOLD   ");
				mekan[1][y-1][x]=' ';
				break;
				}
			}
		}
	}
	else if(strncmp(env[4],"ROCK",4)==0&&mekan[1][y-1][x]==' ')
	{
		strcpy(env[4],"EMPTY");
		mekan[1][y-1][x]='O';
	}
	else if(strncmp(env[4],"WALL",4)==0&&mekan[1][y-1][x]==' ')
	{
		strcpy(env[4],"EMPTY");
		mekan[1][y-1][x]='X';
	}
	else if(strncmp(env[4],"PAPER",5)==0)
	{
		printf("\e[H\e[J");
		printf("----------------------\n");
		printf("Not:\n\nThey did came...\nThey did killed...\nAnd They did gone...");
		printf("\n\n\n\n\n\n\n\n         Priest Albert\n\n----------------------");
		while(1)
		if(kbhit())
		break;
	}
}

int goat_f(int goat[72],char*mekan[3][2000],int x,int y)
{
	srand(time(NULL));
	int test2=0;
	for(int i=0;i<72;i+=2)
	{
	if(mekan[1][goat[i]][goat[i+1]]=='6')
	if(fabs(y-goat[i])<5&&fabs(x-goat[i+1])<10)
	{
		test2=1;
		int test=0;
	int yon=rand()%4;
	if(yon==1)
	goto iki;
	if(yon==2)
	goto uc;
	if(yon==3)
	goto dort;
	bas:
	if(strncmp(&mekan[1][goat[i]-1][goat[i+1]],"   ",3)==0)
	{
	strncpy(&mekan[1][goat[i]][goat[i+1]],"   ",3);
	goat[i]--;
	strncpy(&mekan[1][goat[i]][goat[i+1]],"6qq",3);
	continue;
	}
	if(++test==4)
	continue;
	iki:
	if(mekan[1][goat[i]][goat[i+1]-1]==' ')
	{
	strncpy(&mekan[1][goat[i]][goat[i+1]],"   ",3);
	goat[i+1]--;
	strncpy(&mekan[1][goat[i]][goat[i+1]],"6qq",3);
	continue;
	}
	if(++test==4)
	continue;
	uc:
	if(strncmp(&mekan[1][goat[i]+1][goat[i+1]],"   ",3)==0)
	{
	strncpy(&mekan[1][goat[i]][goat[i+1]],"   ",3);
	goat[i]++;
	strncpy(&mekan[1][goat[i]][goat[i+1]],"6qq",3);
	continue;
	}
	if(++test==4)
	continue;
	dort:
	if(mekan[1][goat[i]][goat[i+1]+3]==' ')
	{
	strncpy(&mekan[1][goat[i]][goat[i+1]],"   ",3);
	goat[i+1]++;
	strncpy(&mekan[1][goat[i]][goat[i+1]],"6qq",3);
	continue;
	}
	if(++test==4)
	continue;
	goto bas;
	}
	}
	return test2;
}

int wolf_f(int wolf[24],char*mekan[3][2000],int x,int y,int goat[72],char health[3],int armor,int w_spec[3])
{
	int test3=0;
	for(int i=0;i<24;i+=2)
	{
    	if(mekan[1][wolf[i]][wolf[i+1]]=='d'||mekan[1][wolf[i]][wolf[i+1]]=='n')
    	if(fabs(y-wolf[i])<w_spec[1]/2&&fabs(x-wolf[i+1])<w_spec[1])
    	{
	    	test3=1;
    		int test2=0;
    		if(fabs(wolf[i]-y)<w_spec[2]/2&&fabs(wolf[i+1]-x)<w_spec[2])
    		{
				test2++;
				if(wolf[i]>y&&(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"o",1)==0))
				{
					if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
	            if(mekan[1][wolf[i]][wolf[i+1]]=='d')
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"dn",2);
            	else
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"nb",2);
            	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"  ",2);
					}
				}
				if(wolf[i]<y&&(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"o",1)==0))
				{
					if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				if(mekan[1][wolf[i]][wolf[i+1]]=='d')
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"dn",2);
            	else
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"nb",2);
            	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"  ",2);
				}
				}
				if(wolf[i+1]>x&&(mekan[1][wolf[i]][wolf[i+1]-1]==' '||mekan[1][wolf[i]][wolf[i+1]-1]=='o'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]-1],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	            wolf[i+1]--;
	            strncpy(&mekan[1][wolf[i]][wolf[i+1]],"dn",2);
					}
				}
				if(wolf[i+1]<x&&(mekan[1][wolf[i]][wolf[i+1]+2]==' '||mekan[1][wolf[i]][wolf[i+1]+2]=='o'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]+2],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	            wolf[i+1]++;
            	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"nb",2);
					}
				}
			}
    		else
    		{
    		for(int j=0;j<72;j++)
    		{
    		    if(fabs(goat[j]-wolf[i])<8&&fabs(goat[j+1]-wolf[i+1])<16&&mekan[1][goat[j]][goat[j+1]]=='6')
			{
				test2++;
				if(wolf[i]>goat[j]&&(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"6qq",3)==0))
				{
					if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"6qq",3)==0)
					{
						strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"bb9",3);
						break;
					}
					else
					{
	            if(mekan[1][wolf[i]][wolf[i+1]]=='d')
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"dn",2);
            	else
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"nb",2);
            	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"  ",2);
				break;
					}
				}
				else if(wolf[i]<goat[j]&&(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"6qq",3)==0))
				{
					if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"6qq",3)==0)
					{
						strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"bb9",3);
						break;
					}
					else
					{
				if(mekan[1][wolf[i]][wolf[i+1]]=='d')
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"dn",2);
            	else
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"nb",2);
            	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"  ",2);
				break;
				}
				}
				else if(wolf[i+1]>goat[j+1]&&(mekan[1][wolf[i]][wolf[i+1]-1]==' '||mekan[1][wolf[i]][wolf[i+1]-1]=='q'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]-1],"q",1)==0)
					{
						strncpy(&mekan[1][wolf[i]][wolf[i+1]-3],"bb9",3);
						break;
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	            wolf[i+1]--;
	            strncpy(&mekan[1][wolf[i]][wolf[i+1]],"dn",2);
				break;
					}
				}
				else if(wolf[i+1]<goat[j+1]&&(mekan[1][wolf[i]][wolf[i+1]+2]==' '||mekan[1][wolf[i]][wolf[i+1]+2]=='6'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]+2],"6",1)==0)
					{
						strncpy(&mekan[1][wolf[i]][wolf[i+1]+2],"bb9",3);
						break;
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	            wolf[i+1]++;
            	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"nb",2);
				break;
					}
				}
			}
		}
    		}
		if(test2==0)
		{
	int test=0;
	srand(time(NULL));
	int yon=rand()%4;
	if(yon==1)
	goto bes;
	if(yon==2)
	goto alti;
	if(yon==3)
	goto yedi;
	bas2:
	if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"  ",2)==0)
	{
	if(mekan[1][wolf[i]][wolf[i+1]]=='d')
	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"dn",2);
	else
	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"nb",2);
	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"  ",2);
	continue;
	}
	if(++test==4)
	continue;
	bes:
	if(mekan[1][wolf[i]][wolf[i+1]-1]==' ')
	{
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	wolf[i+1]--;
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"dn",2);
	continue;
	}
	if(++test==4)
	continue;
	alti:
	if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"  ",2)==0)
	{
	if(mekan[1][wolf[i]][wolf[i+1]]=='d')
	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"dn",2);
	else
	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"nb",2);
	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"  ",2);
	continue;
	}
	if(++test==4)
	continue;
	yedi:
	if(mekan[1][wolf[i]][wolf[i+1]+2]==' ')
	{
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"  ",2);
	wolf[i+1]++;
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"nb",2);
	continue;
	}
	if(++test==4)
	continue;
	goto bas2;
	}
	}
	}
	return test3;
}



int crocodile_f(int wolf[100],char*mekan[3][2000],int x,int y,int goat[72],char health[3],int armor,int w_spec[3])
{
	int test3=0;
	for(int i=0;i<100;i+=2)
	{
    	if(mekan[1][wolf[i]][wolf[i+1]]=='='||mekan[1][wolf[i]][wolf[i+1]]=='-')
    	if(fabs(y-wolf[i])<w_spec[1]/2&&fabs(x-wolf[i+1])<w_spec[1])
    	{
	    	test3=1;
    		int test2=0;
    		if(fabs(wolf[i]-y)<w_spec[2]/2&&fabs(wolf[i+1]-x)<w_spec[2])
    		{
				test2++;
		if(wolf[i]>y&&(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"       ",7)==0||
		strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"o",1)==0))
				{
					if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
	            if(mekan[1][wolf[i]][wolf[i+1]]=='=')
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"=*,=,--",7);
            	else
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"--,=,*=",7);
            	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"       ",7);
					}
				}
				if(wolf[i]<y&&(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"       ",7)==0||
				strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"o",1)==0))
				{
					if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				if(mekan[1][wolf[i]][wolf[i+1]]=='=')
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"=*,=,--",7);
            	else
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"--,=,*=",7);
            	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"       ",7);
				}
				}
				if(wolf[i+1]>x&&(mekan[1][wolf[i]][wolf[i+1]-1]==' '||mekan[1][wolf[i]][wolf[i+1]-1]=='o'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]-1],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	            wolf[i+1]--;
	            strncpy(&mekan[1][wolf[i]][wolf[i+1]],"=*,=,--",7);
					}
				}
				if(wolf[i+1]<x&&(mekan[1][wolf[i]][wolf[i+1]+7]==' '||mekan[1][wolf[i]][wolf[i+1]+2]=='o'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]+2],"o",1)==0)
					{
						if(rand()%armor<w_spec[0])
						{
						int bar=2;
						while(health[bar]!='O')
						bar--;
						health[bar]='X';
						}
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	            wolf[i+1]++;
            	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"--,=,*=",7);
					}
				}
			}
    		else
    		{
    		for(int j=0;j<72;j++)
    		{
    		    if(fabs(goat[j]-wolf[i])<8&&fabs(goat[j+1]-wolf[i+1])<16&&mekan[1][goat[j]][goat[j+1]]=='6')
			{
				test2++;
				if(wolf[i]>goat[j]&&(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"6qq",3)==0))
				{
					if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"6qq",3)==0)
					{
						strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"bb9",3);
						break;
					}
					else
					{
	            if(mekan[1][wolf[i]][wolf[i+1]]=='=')
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"=*,=,--",7);
            	else
            	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"--,=,*=",7);
            	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"       ",7);
				break;
					}
				}
				else if(wolf[i]<goat[j]&&(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"   ",3)==0||strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"6qq",3)==0))
				{
					if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"6qq",3)==0)
					{
						strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"bb9",3);
						break;
					}
					else
					{
				if(mekan[1][wolf[i]][wolf[i+1]]=='=')
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"=*,=,--",7);
            	else
            	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"--,=,*=",7);
            	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"       ",7);
				break;
				}
				}
				else if(wolf[i+1]>goat[j+1]&&(mekan[1][wolf[i]][wolf[i+1]-1]==' '||mekan[1][wolf[i]][wolf[i+1]-1]=='q'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]-1],"q",1)==0)
					{
						strncpy(&mekan[1][wolf[i]][wolf[i+1]-3],"bb9",3);
						break;
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	            wolf[i+1]--;
	            strncpy(&mekan[1][wolf[i]][wolf[i+1]],"=*,=,--",7);
				break;
					}
				}
				else if(wolf[i+1]<goat[j+1]&&(mekan[1][wolf[i]][wolf[i+1]+2]==' '||mekan[1][wolf[i]][wolf[i+1]+2]=='6'))
				{
					if(strncmp(&mekan[1][wolf[i]][wolf[i+1]+2],"6",1)==0)
					{
						strncpy(&mekan[1][wolf[i]][wolf[i+1]+2],"bb9",3);
						break;
					}
					else
					{
				strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	            wolf[i+1]++;
            	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"--,=,*=",7);
				break;
					}
				}
			}
		}
    		}
		if(test2==0)
		{
	int test=0;
	srand(time(NULL));
	int yon=rand()%4;
	if(yon==1)
	goto bes;
	if(yon==2)
	goto alti;
	if(yon==3)
	goto yedi;
	bas2:
	if(strncmp(&mekan[1][wolf[i]-1][wolf[i+1]],"       ",7)==0)
	{
	if(mekan[1][wolf[i]][wolf[i+1]]=='=')
	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"=*,=,--",7);
	else
	strncpy(&mekan[1][--wolf[i]][wolf[i+1]],"--,=,*=",7);
	strncpy(&mekan[1][wolf[i]+1][wolf[i+1]],"       ",7);
	continue;
	}
	if(++test==4)
	continue;
	bes:
	if(mekan[1][wolf[i]][wolf[i+1]-1]==' ')
	{
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	wolf[i+1]--;
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"=*,=,--",7);
	continue;
	}
	if(++test==4)
	continue;
	alti:
	if(strncmp(&mekan[1][wolf[i]+1][wolf[i+1]],"       ",7)==0)
	{
	if(mekan[1][wolf[i]][wolf[i+1]]=='=')
	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"=*,=,--",7);
	else
	strncpy(&mekan[1][++wolf[i]][wolf[i+1]],"--,=,*=",7);
	strncpy(&mekan[1][wolf[i]-1][wolf[i+1]],"       ",7);
	continue;
	}
	if(++test==4)
	continue;
	yedi:
	if(mekan[1][wolf[i]][wolf[i+1]+2]==' ')
	{
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"       ",7);
	wolf[i+1]++;
	strncpy(&mekan[1][wolf[i]][wolf[i+1]],"--,=,*=",7);
	continue;
	}
	if(++test==4)
	continue;
	goto bas2;
	}
	}
	}
	return test3;
}


int hedgehog_f(int hedgehog[100],char*mekan[3][2000],int x,int y,int*speed)
{
	int test3=0;
	for(int i=0;i<100;i+=2)
	{
    	if(mekan[1][hedgehog[i]][hedgehog[i+1]]=='o'||mekan[1][hedgehog[i]][hedgehog[i+1]]=='M')
    	if(fabs(y-hedgehog[i])<5&&fabs(x-hedgehog[i+1])<10)
    	{
	    	test3=1;
    		int test2=0;
    		if(fabs(hedgehog[i]-y)<2&&fabs(hedgehog[i+1]-x)<4)
    		{
    			*speed=400000;
				test2++;
				if(hedgehog[i]<y&&(strncmp(&mekan[1][hedgehog[i]-1][hedgehog[i+1]],"   ",3)==0))
				{
	            if(strncmp(&mekan[1][hedgehog[i]][hedgehog[i+1]],"oM",2)==0)
            	strncpy(&mekan[1][--hedgehog[i]][hedgehog[i+1]],"oM",2);
            	else
            	strncpy(&mekan[1][--hedgehog[i]][hedgehog[i+1]],"Mo",2);
            	strncpy(&mekan[1][hedgehog[i]+1][hedgehog[i+1]],"  ",2);
				}
				if(hedgehog[i]>y&&(strncmp(&mekan[1][hedgehog[i]+1][hedgehog[i+1]],"   ",3)==0))
				{
				if(strncmp(&mekan[1][hedgehog[i]][hedgehog[i+1]],"oM",2)==0)
            	strncpy(&mekan[1][++hedgehog[i]][hedgehog[i+1]],"oM",2);
            	else
            	strncpy(&mekan[1][++hedgehog[i]][hedgehog[i+1]],"Mo",2);
            	strncpy(&mekan[1][hedgehog[i]-1][hedgehog[i+1]],"  ",2);
				}
				if(hedgehog[i+1]<x&&(mekan[1][hedgehog[i]][hedgehog[i+1]-1]==' '))
				{
				strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"  ",2);
	            hedgehog[i+1]--;
	            strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"oM",2);
				}
				if(hedgehog[i+1]>x&&(mekan[1][hedgehog[i]][hedgehog[i+1]+2]==' '))
				{
				strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"  ",2);
	            hedgehog[i+1]++;
            	strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"Mo",2);
				}
			}
		if(test2==0)
		{
	*speed=1200000;
	int test=0;
	srand(time(NULL));
	int yon=rand()%4;
	if(yon==1)
	goto bes;
	if(yon==2)
	goto alti;
	if(yon==3)
	goto yedi;
	bas2:
	if(strncmp(&mekan[1][hedgehog[i]-1][hedgehog[i+1]],"  ",2)==0)
	{
	if(mekan[1][hedgehog[i]][hedgehog[i+1]]=='o')
	strncpy(&mekan[1][--hedgehog[i]][hedgehog[i+1]],"oM",2);
	else
	strncpy(&mekan[1][--hedgehog[i]][hedgehog[i+1]],"Mo",2);
	strncpy(&mekan[1][hedgehog[i]+1][hedgehog[i+1]],"  ",2);
	continue;
	}
	if(++test==4)
	continue;
	bes:
	if(mekan[1][hedgehog[i]][hedgehog[i+1]-1]==' ')
	{
	strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"  ",2);
	hedgehog[i+1]--;
	strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"oM",2);
	continue;
	}
	if(++test==4)
	continue;
	alti:
	if(strncmp(&mekan[1][hedgehog[i]+1][hedgehog[i+1]],"  ",2)==0)
	{
	if(mekan[1][hedgehog[i]][hedgehog[i+1]]=='o')
	strncpy(&mekan[1][++hedgehog[i]][hedgehog[i+1]],"oM",2);
	else
	strncpy(&mekan[1][++hedgehog[i]][hedgehog[i+1]],"Mo",2);
	strncpy(&mekan[1][hedgehog[i]-1][hedgehog[i+1]],"  ",2);
	continue;
	}
	if(++test==4)
	continue;
	yedi:
	if(mekan[1][hedgehog[i]][hedgehog[i+1]+2]==' ')
	{
	strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"  ",2);
	hedgehog[i+1]++;
	strncpy(&mekan[1][hedgehog[i]][hedgehog[i+1]],"Mo",2);
	continue;
	}
	if(++test==4)
	continue;
	goto bas2;
	}
	}
	}
	return test3;
}

void armor_f(int*armor,char*body[])
{
	*armor=1;
		for(int i=0;i<3;i++)
		{
			if(strncmp(body[i],"*GOAT HEAD",10)==0)
			*armor+=10;
			else if(strncmp(body[i],"&ROCK PLATE",11)==0)
			*armor+=3500;
			else if(strncmp(body[i],"&WOLF FUR",9)==0)
			*armor+=15;
			else if(strncmp(body[i],"*WOLF HEAD",10)==0)
			*armor+=5;
			else if(strncmp(body[i],"&IRON PLATE",11)==0)
			*armor+=50;
		}
}
void weather(int*early)
{
	static int up;
	if(dark==0)
	up=1;
	if(dark==5)
	up=0;
	if(up==1)
	{
	dark+=1;
	strcpy(day,"NIGHT");
	}
	if(up==0)
	{
	dark-=1;
	strcpy(day,"DAY");
	}
	if(dark==0||dark==5)
	*early=0;
	else
	*early=1;
}