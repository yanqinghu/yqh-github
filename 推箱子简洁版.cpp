/*
���ǵĵ����ʵ����������С��Ϸ��
������ѧ����˽���Ϸ�ı�̣�
��ᵽ�Լ���д��Ϸ����Ȥ��
��������Ӧ���ڽ�ѧ�ĺ��ڲŹ������ʵ��ģ�
���ǿ��ǵ�ѧ���ʵ�����
������ǰ�������Դ����ƻ��԰汾��
��������ս����о��׶Σ�
���������Ľ׶Σ��ͱȽ�����ȥ������������ˡ�
*/


/*
ʵ��Ҫ��
1.��Щ������ƶ����ܹ�����Ҫ����ܹ���Ľ��жԱ��о����޸ģ�
ȷ���ĸ��������ƶ������ֽ�����Ҫ�Ż���
2.���������й��ϣ���Ҫ���ʵ��Ч���ҵ�������֮��
3.��ӵ��Ĺغ͵���صĻ���ݲ�ʹ֮�������ʼ�����������ȫ�����ϡ�
4.��ϸ�о����ҵ�������ܴ��ڵ�bug�������޸ġ�
5.��չ����Ӻ��һ���Ĺ��ܡ�
*/
//������С��ϷC��
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
const roomsize=9;                          //��Ʒ����ڲ�Ϊ���Σ��߳�Ϊ9
int map[roomsize+2][roomsize+2];           //�����ӷ��䲼�ֵ���ݽṹ����ά����
int data;                                  //��¼��̲�����Ŀ                               
int times=0;                               
int array[2]={100,100};                    //��¼��óɼ�
char string[30]="����װ��..................";
//����Ϊǰ������Ϸ������ϸ�ڲ��ֵ���ݽṹ����ά�����ʵ������
int map1[roomsize+2][roomsize+2]= 
{   //0,1,2,3,4,5,6,7,8,9,10
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//0
	{-1,1,1,1,1,1,1,1,1,-1,-1},        //1
	{-1,1,4,0,0,0,1,1,1,-1,-1},        //2
	{-1,1,0,3,3,0,0,0,1,-1,-1},        //3
	{-1,1,0,2,1,2,0,0,1,-1,-1},        //4
	{-1,1,0,0,1,1,3,0,1,-1,-1},        //5
	{-1,1,0,0,1,1,2,1,1,-1,-1},        //6
	{-1,1,0,0,0,0,0,1,1,-1,-1},        //7
	{-1,1,1,1,1,1,1,1,1,-1,-1},        //8
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//9
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //10
};
int map2[roomsize+2][roomsize+2]=
{   //0,1,2,3,4,5,6,7,8,9,10
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//0
	{-1,0,1,1,1,1,0,0,0,-1,-1},        //1
	{-1,0,1,4,0,1,1,1,0,-1,-1},        //2  
	{-1,0,1,0,3,0,0,1,0,-1,-1},        //3
	{-1,1,1,1,0,1,0,1,1,-1,-1},        //4  
	{-1,1,2,1,0,1,0,0,1,-1,-1},        //5
	{-1,1,2,3,0,0,1,0,1,-1,-1},        //6
	{-1,1,2,0,0,0,3,0,1,-1,-1},        //7
	{-1,1,1,1,1,1,1,1,1,-1,-1},        //8
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},//9
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //10
};
int map3[roomsize+2][roomsize+2]=
{   //0,1,2,3,4,5,6,7,8,9,10
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, //0
	{-1,0,0,0,0,1,1,1,1,1,-1},          //1
	{-1,0,0,0,0,1,0,0,0,1,-1},          //2 
	{-1,1,1,1,0,1,0,0,0,1,-1},          //3
	{-1,1,2,1,0,1,0,0,0,1,-1},          //4
	{-1,1,2,1,0,1,0,3,0,1,-1},          //5
	{-1,1,2,1,1,1,0,3,0,1,-1},          //6
	{-1,1,0,0,0,0,3,4,0,1,-1},          //7
	{-1,1,0,0,1,0,0,0,0,1,-1},          //8
	{-1,1,1,1,1,1,1,1,1,1,-1},          //9 
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //10
};

int positionh;//�˵�λ�������
int positionl;//�˵�λ�ú����
int conti;//ѯ���Ƿ����
int flag;//��־λ����¼����Ŀ��λ����
int gate;//��¼����
int step;//��¼����
void initbox();//��ʼ������
void begin();//��ʼ����
void choose_gate();//ѡ����ʾ
void choose();//��Ϸʱcѡ�����ʾ
void replay();//����
void playing();//����Ϸʱ����
void display();//��ʾ��ͼ
void moveleft();//��������
void moveright();//�����ҷ���
void movedown();//�����·���
void moveup();//�����Ϸ���
void test_flag();//�����ʾ
void record();//�ɼ����а�
//=====
void playing()//Ascii����̼�λ����Ϊ75 ��Ϊ77 ��Ϊ72 ��Ϊ80
{
	int choice;
	step=0;
	printf("��ʼ��Ϸ��");
	while(1)
	{
		display();
		switch(getch())
		{
		case 72:
			moveup();
			step++;
			break;
		case 80:
			movedown();
			step++;
			break;
		case 75:
			moveleft();
			step++;
			break;
		case 77:
			moveright();
			step++;
			break;
		case 'q':
		case 'Q':
            exit(0);
            break;
		case 'c':
		case 'C':
			choose();
			break;

			printf("  �q���������������������������r\n");
			printf(" �����˳���Ϸ���Ƿ��ص������? ��\n");
			printf(" ��   1. ���������            ��\n");
			printf(" ��   2. �˳���Ϸ              ��\n");
			printf(" �t�����������������������������s\n");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				step=0;
				Sleep(500);
				system("cls");
				begin();
				break;
			case 2:
				exit(0);
			}
			default:
				break;
		}
		system("cls");
	}
}
void display()
{
	printf("\n\n\n\n\n");
	for(int i=1;i<=roomsize;i++)
	{
		printf("         ");
		for(int j=1;j<=roomsize;j++)
		{
			if(map[i][j]==0) printf("  ");//�յ�
			if(map[i][j]==1) printf("��");//ǽ
			if(map[i][j]==2) printf("��");//Ŀ��λ��
			if(map[i][j]==3) printf("��");//����
			if(map[i][j]==4) printf("��");//��
            if(map[i][j]==5) printf("�I");//������Ŀ��λ����
		}
		printf("\n");
	}
	printf("\n\n");
	printf("ѡ��(c),�˳�(q),��һ��(b) ����%d\n",step);
}
void moveleft()
{
	if(map[positionh][positionl-1]==0)//��հ�λ���ƶ�
	{
		map[positionh][positionl-1]=4;
		if(flag==1)
		{
			map[positionh][positionl]=2; flag=0; }
		 else 
			map[positionh][positionl]=0;
		 positionl--;
	}
	else if(map[positionh][positionl-1]==2)//��Ҫ��Ŀ��λ����
	{
		map[positionh][positionl-1]=4;
		if(flag==1)//����Ŀ��λ����
			map[positionh][positionl]=2;//�ָ�Ŀ��λ��
		else
		{
			map[positionh][positionl]=0;//�ָ�ԭ���״̬
			flag=1;//��־λ����¼����Ŀ��λ����
		}

		positionl--;
	}
	else if(map[positionh][positionl-1]==3&&map[positionh][positionl-2]==0)//�������Ƶ��հ�λ����
	{
		map[positionh][positionl-2]=3;
		map[positionh][positionl-1]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else
			map[positionh][positionl]=0; 
		positionl--;
	}
	else if(map[positionh][positionl-1]==5&&map[positionh][positionl-2]!=1)//Ҫ�����Ӵ�Ŀ��λ�����Ƴ�
	{
		if(map[positionh][positionl-2]==2)//��һ��λ�û���Ŀ��λ��
		{
			map[positionh][positionl-2]=5;
			map[positionh][positionl-1]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		else if(map[positionh][positionl-2]==0)//��һ��λ���ǿհ�
		{
			map[positionh][positionl-2]=3;
			map[positionh][positionl-1]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		positionl--;
	}
	else if(map[positionh][positionl-1]==3&&map[positionh][positionl-2]==2)//Ҫ�������Ƶ�Ŀ��λ����
	{
		map[positionh][positionl-2]=5;//������Ŀ��λ����
		map[positionh][positionl-1]=4;
		if(flag==1)//����Ŀ��λ����
		{ map[positionh][positionl]=2; flag=0; }
		else //�˲���Ŀ��λ����
			map[positionh][positionl]=0;
		positionl--;
	}
	else step--;//�����˲��������
	test_flag();
}

void moveright()
{
	if(map[positionh][positionl+1]==0)//��հ�λ���ƶ�
	{
		map[positionh][positionl+1]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else 
			map[positionh][positionl]=0;
		positionl++;
	}
	else if(map[positionh][positionl+1]==2)//��Ҫ��Ŀ��λ����
	{
		map[positionh][positionl+1]=4;
		if(flag==1)//����Ŀ��λ����
			map[positionh][positionl]=2;//�ָ�Ŀ��λ��
		else
		{
			map[positionh][positionl]=0;//�ָ�ԭ���״̬
			flag=1;//��־λ����¼����Ŀ��λ����
		}
		positionl++;
	}
	else if(map[positionh][positionl+1]==3&&map[positionh][positionl+2]==0)//�������Ƶ��հ�λ����
	{
		map[positionh][positionl+2]=3;
		map[positionh][positionl+1]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else
			map[positionh][positionl]=0; 
		positionl++;
	}
	else if(map[positionh][positionl+1]==5&&map[positionh][positionl+2]!=1)//Ҫ�����Ӵ�Ŀ��λ�����Ƴ�
	{
		if(map[positionh][positionl+2]==2)//��һ��λ�û���Ŀ��λ��
		{
			map[positionh][positionl+2]=5;
			map[positionh][positionl+1]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		else if(map[positionh][positionl+2]==0)//��һ��λ���ǿհ�
		{
			map[positionh][positionl+2]=3;
			map[positionh][positionl+1]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		positionl++;
	}
	else if(map[positionh][positionl+1]==3&&map[positionh][positionl+2]==2)//Ҫ�������Ƶ�Ŀ��λ����
	{
		map[positionh][positionl+2]=5;//������Ŀ��λ����
		map[positionh][positionl+1]=4;
		if(flag==1)//����Ŀ��λ����
		{ map[positionh][positionl]=2; flag=0; }
		else //�˲���Ŀ��λ����
			map[positionh][positionl]=0;
		positionl++;
	}
	else step--;//�����˲��������
	test_flag();
}



void moveup()
{ 
	if(map[positionh-1][positionl]==0)//��հ�λ���ƶ�
	{
		map[positionh-1][positionl]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else 
			map[positionh][positionl]=0;
		positionh--;
	}
	else if(map[positionh-1][positionl]==2)//��Ҫ��Ŀ��λ����
	{
		map[positionh-1][positionl]=4;
		if(flag==1)//����Ŀ��λ����
			map[positionh][positionl]=2;//�ָ�Ŀ��λ��
		else
		{
			map[positionh][positionl]=0;//�ָ�ԭ���״̬
			flag=1;//��־λ����¼����Ŀ��λ����
		}
		positionh--;
	}
	else if(map[positionh-1][positionl]==3&&map[positionh-2][positionl]==0)//�������Ƶ��հ�λ����
	{
		map[positionh-2][positionl]=3;
		map[positionh-1][positionl]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else
			map[positionh][positionl]=0; 
		positionh--;
	}
	else if(map[positionh-1][positionl]==5&&map[positionh-2][positionl]!=1)//Ҫ�����Ӵ�Ŀ��λ�����Ƴ�
	{
		if(map[positionh-2][positionl]==2)//��һ��λ�û���Ŀ��λ��
		{
			map[positionh-2][positionl]=5;
			map[positionh-1][positionl]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		else if(map[positionh-2][positionl]==0)//��һ��λ���ǿհ�
		{
			map[positionh-2][positionl]=3;
			map[positionh-1][positionl]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		positionh--;
	}
	else if(map[positionh-1][positionl]==3&&map[positionh-2][positionl]==2)//Ҫ�������Ƶ�Ŀ��λ����
	{
		map[positionh-2][positionl]=5;//������Ŀ��λ����
		map[positionh-1][positionl]=4;
		if(flag==1)//����Ŀ��λ����
		{ map[positionh][positionl]=2; flag=0; }
		else //�˲���Ŀ��λ����
			map[positionh][positionl]=0;
		positionh--;
	}
	else step--;//�����˲��������
	test_flag();
}  



void movedown()
{
	if(map[positionh+1][positionl]==0)//��հ�λ���ƶ�
	{
		map[positionh+1][positionl]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else 
			map[positionh][positionl]=0;
		positionh++;
	}
	else if(map[positionh+1][positionl]==2)//��Ҫ��Ŀ��λ����
	{
		map[positionh+1][positionl]=4;
		if(flag==1)//����Ŀ��λ����
			map[positionh][positionl]=2;//�ָ�Ŀ��λ��
		else
		{
			map[positionh][positionl]=0;//�ָ�ԭ���״̬
			flag=1;//��־λ����¼����Ŀ��λ����
		}
		positionh++;
	}
	else if(map[positionh+1][positionl]==3&&map[positionh+2][positionl]==0)//�������Ƶ��հ�λ����
	{
		map[positionh+2][positionl]=3;
		map[positionh+1][positionl]=4;
		if(flag==1)
		{	map[positionh][positionl]=2; flag=0; }
		else
			map[positionh][positionl]=0; 
		positionh++;
	}
	else if(map[positionh+1][positionl]==5&&map[positionh-2][positionl]!=1)//Ҫ�����Ӵ�Ŀ��λ�����Ƴ�
	{
		if(map[positionh+2][positionl]==2)//��һ��λ�û���Ŀ��λ��
		{
			map[positionh+2][positionl]=5;
			map[positionh+1][positionl]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		}
		else if(map[positionh+2][positionl]==0)//��һ��λ���ǿհ�
		{
			map[positionh+2][positionl]=3;
			map[positionh+1][positionl]=4;
			if(flag==1)
				map[positionh][positionl]=2;
			else
			{ map[positionh][positionl]=0; flag=1; }
		};
		positionh++;
	}
	else if(map[positionh+1][positionl]==3&&map[positionh+2][positionl]==2)//Ҫ�������Ƶ�Ŀ��λ����
	{
		map[positionh+2][positionl]=5;//������Ŀ��λ����
		map[positionh+1][positionl]=4;
		if(flag==1)//����Ŀ��λ����
		{ map[positionh][positionl]=2; flag=0; }
		else //�˲���Ŀ��λ����
			map[positionh][positionl]=0;
		positionh++;
	}
	else step--;//�����˲��������
	test_flag();
}



void initbox()//��ʼ������
{
	positionh=0;
	positionl=0;
	flag=0;
	step=0;
	gate=0;
}
void begin()
{
	printf("  �q�����������������������������������������������������������������r\n");
	printf(" ��                                                                  ��\n");
	printf(" ��              ����           ������          ����             ��\n");                      
	printf(" ��                           �q�����������r                         ��\n");
	printf(" ��                          ��  ��Ϸ���  ��                        ��\n");
	printf(" ��                          �t�������������s                        ��\n");
	printf(" ����������Ϸ:����Ŀ���ǲ���һ����(��)������(��)�Ƶ�Ŀ��λ��(��)�ϡ� ��\n");
	printf(" ����������Ŀ��λ����ʱ��ʾ�I.                                       ��\n");
	printf(" ��                           �q�����������r                         ��\n");
	printf(" ��                          ��  ����˵��  ��                        ��\n");
	printf(" ��                          �t�������������s                        ��\n");
	printf(" ����������ƶ���'c'ѡ�'b'���һ����'q'�˳�                                   ��\n");
	printf(" ��(����ʹ����󻯴��ڣ�����Ч��Ϻá�)                              ��\n");
	printf(" ��                                                                  ��\n");
	printf(" �t�������������������������������������������������������������������s\n");
	choose_gate();//ѡ�����
	printf("%s\n",string);
	Sleep(500);
	system("cls");
	playing();
}
void choose_gate()
{
	int j,k;
	printf(" �q�������������r\n");
	printf("�� 1.��һ��     ��\n");
	printf("�� 2.�ڶ���     ��\n");
	printf("�� 3.�����     ��\n");
	printf("�� 4.���Ĺ�     ��\n");
	printf("�t���������������s\n");
	printf("��ѡ��");
	scanf("%d",&gate);
	do
	{
		switch(gate)
		{
		case 1:
			for(j=0;j<roomsize+2;j++)//�˴� j�����У�k������
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map1[j][k];
				positionh=2;positionl=2;
				break;
		
		case 2:
			for(j=0;j<roomsize+2;j++)
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map2[j][k];
				positionh=2; positionl=3;
				break;
        case 3:
			for(j=0;j<roomsize+2;j++)
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map3[j][k];
				positionh=7; positionl=7;
				break;
		default:
			printf("���������������");
			scanf("%d",&gate);
		}
	}while(gate>4);   
}
void choose()//ѡ��
{
	int choice;
	printf(" �q������������--�r\n");
	printf("�� 1. ����        ��\n");
	printf("�� 2. ���������  ��\n");
	printf("�� 3. ��Ѽ�¼    ��\n");
	printf("�� 4. �˳�        ��\n");
	printf("�t�����������������s\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		system("cls");
		replay();
		break;
	case 2:
		system("cls");
		begin();
		break;
	case 3:
		record();
		system("cls");
		playing();
		break;
	case 4:
		exit(0);
	}
}
void replay()
{
	int j,k;
	step=0;
	flag=0;
	do
	{
		switch(gate)
		{
		case 1:
				for(j=0;j<roomsize+2;j++)
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map1[j][k];
				positionh=2; positionl=2;
				break;
		
		case 2:
			    for(j=0;j<roomsize+2;j++)
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map2[j][k];
				positionh=2; positionl=3;
				break;
        case 3:
			    for(j=0;j<roomsize+2;j++)
				for(k=0;k<roomsize+2;k++)
					map[j][k]=map3[j][k];
				positionh=7; positionl=7;
				break;

		}
	}while(gate>4);
	playing();
}
void test_flag()
{
	int choice;
	for(int i=1;i<=roomsize;i++)
		for(int j=1;j<=roomsize;j++)
		{
			if(map[i][j]==3)
				return;
		}
		system("cls");
		step++;
		data=step;
		times++;
		display();
		printf(" �q���������������������������r\n");
		printf("�� ��ϲ�㣡���Ѿ�ͨ������ء� ��\n");
		printf("���ǲ��Ǻ��гɾ͸У��Ƿ����\n");
		printf("��1. ����                     ��\n");
		printf("��2. ��Ѽ�¼                 ��\n");
		printf("��3. �˳�                     ��\n");
		printf("�t�����������������������������s\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			step=0;
			Sleep(500);
			system("cls");
			begin();
			break;
		case 2:
			record();
			system("cls");
			printf("�������������...\n");
			begin();
			break;
		case 3:
			printf("��ӭ����棡\n");
			printf("��������˳�...\n");
			getchar();
			exit(0);
		} 
}
void record()//��Ѽ�¼
{
	int rhigh;
	if(times%2)
		array[0]=data;
	else
		array[1]=data;
	if(array[0]>array[1])
		rhigh=array[1];
	else
		rhigh=array[0];
	if(times%2)
		array[0]=rhigh;
	else
		array[1]=rhigh;
	printf("��Ѽ�¼��%d\n",rhigh);
	system("pause");
}
//����
void main(void)
{
	system("color f0");//������ɫ
	SetConsoleTitle("������С��Ϸ��C�棩"); //���ñ���
	initbox();//��ʼ��
	begin();//��ʼ��Ϸ
}