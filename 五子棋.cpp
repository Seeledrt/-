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
}post;//���ù��
post xy;
int main()
{
	initgame();//��ʼ����Ϸ����
	begingame();//��ʼ��Ϸ
	system("pause");
	return 0;
}
void initgame()
{
	initgraph(1280, 720);//��һ������
	HWND hWnd = GetHWnd();//��ô��ھ��
	SetWindowText(hWnd, "˫��������");// ʹ�� API �����޸Ĵ�������
	IMAGE backgrand;//����ͼƬ
	loadimage(&backgrand, "./IMAGE/back.jpg", 1280, 720);
	putimage(0, 0, &backgrand);//������Ϸ��ʼ������
	setbkcolor(RGB(245 ,245 ,245));//���ñ�����ɫ
	IMAGE ch1, ch2, ch3, ch4,ch5,ch6;//���ö���ͼƬ����ʾ����ɫ��̬Ч��
	loadimage(&ch1, "./IMAGE/1.jpg", 1280, 720);
	loadimage(&ch2, "./IMAGE/2.jpg", 1280, 720);
	loadimage(&ch3, "./IMAGE/3.jpg", 1280, 720);
	loadimage(&ch4, "./IMAGE/4.jpg", 1280, 720);
	loadimage(&ch5, "./IMAGE/5.jpg", 1280, 720);
	loadimage(&ch6, "./IMAGE/6.jpg", 1280, 720);

	MOUSEMSG m;// ���������Ϣ   
	while (true)
	{
		m = GetMouseMsg();// ��ȡһ�������Ϣ
		FlushMouseMsgBuffer();//��������Ϣ����
		putimage(0, 0, &backgrand);//����Ļ�Ϸ��ñ���ͼƬ
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE://����ƶ�
			if (m.x >= 636 && m.x <= 897 && m.y >= 85 && m.y <= 137)  
			{
				putimage(0, 0, &ch1);//�����(636,85,897,137)�ڼ���ͼƬ��ʹ������ɫ�ı�
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
			if (m.x >= 636 && m.x <= 897 && m.y >= 85 && m.y <= 137)//�����(636, 85,897, 137)�ڵ�� ��ʼ��Ϸ
			{
				begingame();
			}
			if (m.x >= 700 && m.x <= 960 && m.y >= 157 && m.y <= 209)//�����(700, 157,960, 209)�ڵ�� ��Ϸ����
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
						if(m.x>=1012&&m.x<=1113&&m.y>=633&&m.y<=675)//�����(1012��633��1113��675)�ڵ�� ���س�ʼ����
						{
							initgame();
						}
					}
				}
			}
			if (m.x >= 786 && m.x <= 1047&& m.y >= 238 && m.y <= 280)//�����(786��238��1047��280)�ڵ�� ������Ա
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
						if(m.x>=1019&&m.x<=1180&&m.y>=533&&m.y<=585)//�����(1019��533��1180��585)�ڵ�� ���س�ʼ����
						{
							initgame();
						}
					}
				}
			}
			if (m.x >= 854 && m.x <=1115 && m.y >=326 && m.y <= 378)  //�����(854, 326,1115, 378)�ڵ�� �˳���Ϸ
			{
				closegraph();
				exit(0);
			}
		}
	}
}
void begingame()
{
	IMAGE ch7;//�������ͼƬ
	loadimage(&ch7, "./IMAGE/back4.jpg", 1280, 720);
	putimage(0,0,&ch7);
	setlinecolor(BLACK);//���û��ߵ���ɫ
	setlinestyle(PS_SOLID);//���û��ߵ���ʽ
	setfillcolor(RGB(238, 197, 145));
	fillrectangle(30,45 ,750, 720); //���������
	for (i=1;i<15;i++)
	{
		for (j=1;j<15;j++)
		{
			rectangle(25+j*45,25+i*45,70+j*45,70+i*45);  //����������70 70
		}
	}
	xy.x=385;
	xy.y=385;     // ����������Ƴ����� ���������ĵ�����
	setlinecolor(RED);
	setlinestyle(PS_DOT);
	rectangle(xy.x-20,xy.y-20,xy.x+20,xy.y+20);//�������
	int key,i=7,j=7;
	shuaxing();
	while(true)
	{
		while(_kbhit());//��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0��
		key=_getch();
		switch(key)
		{
		case 87://�������������W
			zuobiao(--i,j);
			shengli(i,j);//����ʤ�����ж�
			break;
		case 65://�������������A
			zuobiao(i,--j);
			shengli(i,j);
			break;
		case 83://�������������S
			zuobiao(++i,j);
			shengli(i,j);
			break;
		case 68://�������������D
			zuobiao(i,++j);
			shengli(i,j);
			break;
		case 32://������������˿ո�
			white(i,j);//���ư���
			shengli(i,j);
			break; 
		case 8://��������������˸��
			shuaxing();
			begingame();
			break;
		case 27://�������������ESC��
			main();
			break;
		case 13://�������������ENTER��
			black(i,j);//���ƺ���
			shengli(i,j);
			break;
		case 224://������������˷����
			switch(_getch())
			{
			case 72://������������ˡ���
				zuobiao(--i,j);
				shengli(i,j);
				break;
			case 75://������������ˡ���
				zuobiao(i,--j);
				shengli(i,j);
				break;
			case 80://������������ˡ���
				zuobiao(++i,j);
				shengli(i,j);
				break;
			case 77://������������ˡ���
				zuobiao(i,++j);
				shengli(i,j);
				break;
			}
		}
	}
}
int cando(int i,int j)//�����ж��Ƿ����ڸô����ӵĺ���
{
	if(qipan[i][j])//����������ӵ����
	{
		settextcolor(BLACK);//����������ɫ
		settextstyle(50,0,"����");//���������С����ʽ
		outtextxy(900,120,"�����ظ�����");
		return 0;
	}
	else//����������ӵ����
	{
		outtextxy(900,120,"�˴���������");
		return 1;
	}
}
void rwhite (int i,int j)//����ˢ������ʱ���»��ư�ɫ���ӵĺ���
{  
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillcircle(70+45*j,70+45*i,20);
	qipan[i][j]=1;
}
void rblack (int i,int j)//����ˢ������ʱ���»��ƺ�ɫ���ӵĺ���
{   
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	fillcircle(70+45*j,70+45*i,20);
	qipan[i][j]=2;
}
void shuaxing()//�������¿�ʼ��Ϸ
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
	cleardevice();//����
	IMAGE ch7;
	loadimage(&ch7,"./IMAGE/back4.jpg",1280,720);
	putimage(0,0,&ch7);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	setfillcolor(RGB(238,197,145));
	fillrectangle(30,45,750,720); //���������
	xy.x=70+45*j;
	xy.y=70+45*i;
	setlinecolor(RED);
	setlinestyle(PS_DOT);
	rectangle(xy.x-20,xy.y-20,xy.x+20,xy.y+20);//���»��ƹ��
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	for (i=1;i<15;i++)//���»�������
	{
		for (j=1;j<15;j++)
		{
			rectangle(25+j*45,25+i*45,70+j*45,70+i*45);
		}
	}
	for (i=0;i<15; i++)//���»�������
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
void white (int i,int j)//�������ư���
{  
	cando(i,j);
	int a=cando(i,j);//����ʱ���ж�
	if(a==1)
	{
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillcircle(70+45*j,70+45*i,20);
		qipan[i][j]=1;
	}
}
void black (int i,int j)//�������ƺ���
{   
	cando(i,j);
	int a=cando(i,j);//����ʱ���ж�
	if(a==1)
	{ 
		setfillcolor(BLACK);
		setlinecolor(BLACK);
		fillcircle(70+45*j,70+45*i,20);
		qipan[i][j]=2;
	}
}
void shengli(int i,int j)//����ʤ�����ж�
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�׷�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�׷�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�׷�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�׷�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�ڷ�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�ڷ�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�ڷ�Ӯ��ʤ��");
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
		settextstyle(40,0,"����");
		outtextxy(900,200,"��ϲ�ڷ�Ӯ��ʤ��");
	}
}