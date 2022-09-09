#include <stdio.h>
#include <windows.graphics.h>
#include <conio.h>
#include <stdlib.h>
void initgame();
void begingame();
void white (int i,int j);
void black (int i,int j);
void shengli(int i,int j);
void zuobiao(int i,int j);
void shuaxing();
int qipan[15][15]={0},i,j;
typedef struct
{
	int x;
	int y;
}post;//设置光标
post xy;
int main()
{
	initgame();//初始化游戏界面
	begingame();//开始游戏
	system("pause");
	return 0;
}
void initgame()
{
	initgraph(1280, 720);//打开一个窗口
	HWND hWnd = GetHWnd();//获得窗口句柄
	SetWindowText(hWnd, "双人五子棋");// 使用 API 函数修改窗口名称
	IMAGE backgrand;//加载图片
	loadimage(&backgrand, "./IMAGE/back.jpg", 1280, 720);
	putimage(0, 0, &backgrand);//加载游戏初始化界面
	setbkcolor(RGB(245 ,245 ,245));//设置背景颜色
	IMAGE ch1, ch2, ch3, ch4,ch5,ch6;//设置多张图片来显示出颜色动态效果
	loadimage(&ch1, "./IMAGE/1.jpg", 1280, 720);
	loadimage(&ch2, "./IMAGE/2.jpg", 1280, 720);
	loadimage(&ch3, "./IMAGE/3.jpg", 1280, 720);
	loadimage(&ch4, "./IMAGE/4.jpg", 1280, 720);
	loadimage(&ch5, "./IMAGE/5.jpg", 1280, 720);
	loadimage(&ch6, "./IMAGE/6.jpg", 1280, 720);

	MOUSEMSG m;// 定义鼠标消息   
	while (true)
	{
		m = GetMouseMsg();// 获取一条鼠标消息
		FlushMouseMsgBuffer();//清空鼠标消息缓冲
		putimage(0, 0, &backgrand);//在屏幕上放置背景图片
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE://鼠标移动
			if (m.x >= 636 && m.x <= 897 && m.y >= 85 && m.y <= 137)  
			{
				putimage(0, 0, &ch1);//鼠标在(636,85,897,137)内加载图片，使字体颜色改变
			}
			if (m.x >= 700 && m.x <= 960 && m.y >= 157 && m.y <= 209) 
			{
				putimage(0, 0, &ch2);
			}
			if (m.x >= 786 && m.x <= 1047 && m.y >= 238 && m.y <= 280) 
			{
				putimage(0, 0, &ch3);
			}
			if (m.x >= 854 && m.x <= 1115 && m.y >= 326 && m.y <= 378)
			{
				putimage(0, 0, &ch4);
			}			
			break;
		case WM_LBUTTONDOWN:     
			if (m.x >= 636 && m.x <= 897 && m.y >= 85 && m.y <= 137)//鼠标在(636, 85,897, 137)内点击 开始游戏
			{
				begingame();
			}
			if (m.x >= 700 && m.x <= 960 && m.y >= 157 && m.y <= 209)//鼠标在(700, 157,960, 209)内点击 游戏介绍
			{
				IMAGE call;
				loadimage(&call, "./IMAGE/back2.jpg",1280, 720);
				putimage(0, 0, &call);
				while (true)
				{
					m = GetMouseMsg();
					FlushMouseMsgBuffer();
					putimage(0, 0, &call);
					switch (m.uMsg)
					{
					case WM_MOUSEMOVE:
						if(m.x>=1012&&m.x<=1113&&m.y>=633&&m.y<=675)
						{
						IMAGE call;
						loadimage(&call,"./IMAGE/5.jpg",1280,720);
						putimage(0,0,&call);
						}
						break;
					case WM_LBUTTONDOWN:     
						if(m.x>=1012&&m.x<=1113&&m.y>=633&&m.y<=675)//鼠标在(1012，633，1113，675)内点击 返回初始界面
						{
							initgame();
						}
					}
				}
			}
			if (m.x >= 786 && m.x <= 1047&& m.y >= 238 && m.y <= 280)//鼠标在(786，238，1047，280)内点击 制作人员
			{
				IMAGE explain;
				loadimage(&explain, "./IMAGE/back3.jpg", 1280, 720);
				putimage(0, 0, &explain);
				while (true)
				{
					m = GetMouseMsg();
					FlushMouseMsgBuffer();
					putimage(0, 0, &explain);
					switch (m.uMsg)
					{
					case WM_MOUSEMOVE:
						if(m.x>=1019&&m.x<=1180&&m.y>=533&&m.y<=585)
						{
							IMAGE explain;
							loadimage(&explain,"./IMAGE/6.jpg",1280,720);
							putimage(0,0,&explain);
						}
						break;
					case WM_LBUTTONDOWN:     
						if(m.x>=1019&&m.x<=1180&&m.y>=533&&m.y<=585)//鼠标在(1019，533，1180，585)内点击 返回初始界面
						{
							initgame();
						}
					}
				}
			}
			if (m.x >= 854 && m.x <=1115 && m.y >=326 && m.y <= 378)  //鼠标在(854, 326,1115, 378)内点击 退出游戏
			{
				closegraph();
				exit(0);
			}
		}
	}
}
void begingame()
{
	IMAGE ch7;//输出背景图片
	loadimage(&ch7, "./IMAGE/back4.jpg", 1280, 720);
	putimage(0,0,&ch7);
	setlinecolor(BLACK);//设置画线的颜色
	setlinestyle(PS_SOLID);//设置画线的样式
	setfillcolor(RGB(238, 197, 145));
	fillrectangle(30,45 ,750, 720); //计算而来的
	for (i=1;i<15;i++)
	{
		for (j=1;j<15;j++)
		{
			rectangle(25+j*45,25+i*45,70+j*45,70+i*45);  //棋盘左上是70 70
		}
	}
	xy.x=385;
	xy.y=385;     // 这个坐标是推出来的 就是最中心的坐标
	setlinecolor(RED);
	setlinestyle(PS_DOT);
	rectangle(xy.x-20,xy.y-20,xy.x+20,xy.y+20);//画出光标
	int key,i=7,j=7;
	shuaxing();
	while(true)
	{
		while(_kbhit());//检查当前是否有键盘输入，若有则返回一个非0值，否则返回0。
		key=_getch();
		switch(key)
		{
		case 87://如果键盘输入了W
			zuobiao(--i,j);
			shengli(i,j);//进行胜利的判断
			break;
		case 65://如果键盘输入了A
			zuobiao(i,--j);
			shengli(i,j);
			break;
		case 83://如果键盘输入了S
			zuobiao(++i,j);
			shengli(i,j);
			break;
		case 68://如果键盘输入了D
			zuobiao(i,++j);
			shengli(i,j);
			break;
		case 32://如果键盘输入了空格
			white(i,j);//绘制白子
			shengli(i,j);
			break; 
		case 8://如果键盘输入了退格键
			shuaxing();
			begingame();
			break;
		case 27://如果键盘输入了ESC键
			main();
			break;
		case 13://如果键盘输入了ENTER键
			black(i,j);//绘制黑子
			shengli(i,j);
			break;
		case 224://如果键盘输入了方向键
			switch(_getch())
			{
			case 72://如果键盘输入了↑键
				zuobiao(--i,j);
				shengli(i,j);
				break;
			case 75://如果键盘输入了←键
				zuobiao(i,--j);
				shengli(i,j);
				break;
			case 80://如果键盘输入了↓键
				zuobiao(++i,j);
				shengli(i,j);
				break;
			case 77://如果键盘输入了→键
				zuobiao(i,++j);
				shengli(i,j);
				break;
			}
		}
	}
}
int cando(int i,int j)//用来判断是否能在该处下子的函数
{
	if(qipan[i][j])//坐标点有棋子的情况
	{
		settextcolor(BLACK);//设置字体颜色
		settextstyle(50,0,"楷体");//设置字体大小，样式
		outtextxy(900,120,"不能重复落子");
		return 0;
	}
	else//坐标点无棋子的情况
	{
		outtextxy(900,120,"此处可以落子");
		return 1;
	}
}
void rwhite (int i,int j)//用来刷新棋盘时重新绘制白色棋子的函数
{  
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillcircle(70+45*j,70+45*i,20);
	qipan[i][j]=1;
}
void rblack (int i,int j)//用来刷新棋盘时重新绘制黑色棋子的函数
{   
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	fillcircle(70+45*j,70+45*i,20);
	qipan[i][j]=2;
}
void shuaxing()//用来重新开始游戏
{
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{			
			qipan[i][j]=0;			
		}
	}
}
void zuobiao(int i,int j)
{  
	cleardevice();//清屏
	IMAGE ch7;
	loadimage(&ch7,"./IMAGE/back4.jpg",1280,720);
	putimage(0,0,&ch7);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	setfillcolor(RGB(238,197,145));
	fillrectangle(30,45,750,720); //计算而来的
	xy.x=70+45*j;
	xy.y=70+45*i;
	setlinecolor(RED);
	setlinestyle(PS_DOT);
	rectangle(xy.x-20,xy.y-20,xy.x+20,xy.y+20);//重新绘制光标
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	for (i=1;i<15;i++)//重新绘制棋盘
	{
		for (j=1;j<15;j++)
		{
			rectangle(25+j*45,25+i*45,70+j*45,70+i*45);
		}
	}
	for (i=0;i<15; i++)//重新绘制棋子
	{
		for (j=0;j<15;j++)
		{
			int a=cando(i,j);
			switch(qipan[i][j])
			{
			case 1:	
				rwhite(i,j);
				break;
			case 2:
				rblack(i,j);
				break;
			}
		}
	}	
}
void white (int i,int j)//用来绘制白子
{  
	cando(i,j);
	int a=cando(i,j);//落子时先判断
	if(a==1)
	{
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillcircle(70+45*j,70+45*i,20);
		qipan[i][j]=1;
	}
}
void black (int i,int j)//用来绘制黑子
{   
	cando(i,j);
	int a=cando(i,j);//落子时先判断
	if(a==1)
	{ 
		setfillcolor(BLACK);
		setlinecolor(BLACK);
		fillcircle(70+45*j,70+45*i,20);
		qipan[i][j]=2;
	}
}
void shengli(int i,int j)//进行胜利的判断
{
	int a,b,s1=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while(getpixel(a,b)==WHITE)
	{
		s1++;
		b-=45;
	}
	a=xy.x;
	b=xy.y;
	while(getpixel(a,b)==WHITE)
	{
		s1++;
		b += 45;
	}
	if(s1>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜白方赢得胜利");
	}
	int s2=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while(getpixel(a,b)==WHITE)
	{
		s2++;
		a-=45;
	}
	a=xy.x;
	b=xy.y;
	while(getpixel(a,b)==WHITE)
	{
		s2++;
		a+=45;
	}
	if(s2>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜白方赢得胜利");
	}
	int s3=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while(getpixel(a,b)==WHITE)
	{
		s3++;
		a-=45;
		b-=45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a,b)==WHITE)
	{
		s3++;
		a+=45;
		b+=45;
	}
	if(s3>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜白方赢得胜利");
	}
	int s4=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while (getpixel(a,b)==WHITE)
	{
		s4++;
		a-=45;
		b+=45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a,b)==WHITE)
	{
		s4++;
		a+=45;
		b-=45;
	}
	if(s4>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜白方赢得胜利");
	}
	int t1=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t1++;
		b-= 45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t1++;
		b += 45;
	}
	if(t1>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜黑方赢得胜利");
	}
	int t2=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t2++;
		a-=45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t2++;
		a+=45;
	}
	if(t2>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜黑方赢得胜利");
	}
	int t3=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t3++;
		a-=45;
		b-=45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t3++;
		a+=45;
		b+=45;
	}
	if(t3>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜黑方赢得胜利");
	}
	int t4=0;
	xy.x=70+45*j;
	xy.y=70+45*i;
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t4++;
		a-=45;
		b+=45;
	}
	a=xy.x;
	b=xy.y;
	while (getpixel(a-3,b-3)==BLACK)
	{
		t4++;
		a+=45;
		b-=45;
	}
	if(t4>5)
	{
		settextstyle(40,0,"楷体");
		outtextxy(900,200,"恭喜黑方赢得胜利");
	}
}