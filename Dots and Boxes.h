#ifndef    Dots_and_Boxes_h_
#define	   Dots_and_Boxes_h_



#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<stdlib.h>
#include	<conio.h> 
#include	<time.h> 


///////////////////////////////////////////////////////////
//
//
//
//					���̱�ʾ
//
//
//
//
///////////////////////////////////////////////////////////


#define Max_deep	8				//ģ������������
#define Max_len		25				//��ȷ���������
//�������ݽṹ


//�ߵı�ʾ
typedef struct edge
{
	
	struct GRID *node[2];			//����������
	int length;			//���ȣ���ʼ����Ϊ1��Ϊ���ڼ������򻷵ĳ�����׼��
	int ismove;				//�Ƿ�ñ����Ƴ���0�����Ƴ���1�����Դ���
	struct edge *next;
	struct edge *pre;



}EDGE;

//���ӱ�ʾ
typedef struct GRID
{
	EDGE *NextEdge;
	struct GRID *NextNode;


	EDGE *edge[4];			//ָ����Χ��������
	int x,y;				//�ø��ӵ�λ������
	int	degree;				//���ɶ�
	int owner;				//��˭ռ��
	
	int ground;				//�Ƿ�����ʵ�ĸ��ӣ�1����true��0����false

}NODE;


//�߷�
typedef struct list
{
	
	int move_type;                 //�ߵ�ˮƽ���������ͣ�
	int move_ver;			   //��ֱ�߱��
	int move_hor;			   //ˮƽ�߱��

}LIST;

extern NODE Square[7][7];			//�������飬����������ӣ�ground=0
extern EDGE Horizon[6][6];			//ˮƽ��
extern EDGE Vertical[6][6];			//��ֵ��
extern int myturn;					//�ҷ������ֻ��Ǻ��֣�1�������֣�2�������
extern int Iscapture(int HorV,int x,int y,int turn);
extern int x,y;						//���صıߵ�λ��
extern LIST Bestmove;				//����з�
extern int Search(int deep,int alpha,int beta,int turn);
extern bool IsDeadGridEdge();
extern int mboxes,yboxes;
//void Final_Occupy();


#endif

















