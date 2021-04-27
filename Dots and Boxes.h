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
//					棋盘表示
//
//
//
//
///////////////////////////////////////////////////////////


#define Max_deep	8				//模糊搜索最大深度
#define Max_len		25				//精确深度最大深度
//基本数据结构


//边的表示
typedef struct edge
{
	
	struct GRID *node[2];			//附加于两点
	int length;			//长度，初始化均为1，为后期计算链或环的长度做准备
	int ismove;				//是否该边已移除，0代表移除，1代表仍存在
	struct edge *next;
	struct edge *pre;



}EDGE;

//格子表示
typedef struct GRID
{
	EDGE *NextEdge;
	struct GRID *NextNode;


	EDGE *edge[4];			//指向周围的四条边
	int x,y;				//该格子的位置坐标
	int	degree;				//自由度
	int owner;				//被谁占领
	
	int ground;				//是否是真实的格子，1代表true，0代表false

}NODE;


//走法
typedef struct list
{
	
	int move_type;                 //边的水平，数制类型；
	int move_ver;			   //竖直边编号
	int move_hor;			   //水平边编号

}LIST;

extern NODE Square[7][7];			//格子数组，包含假想格子，ground=0
extern EDGE Horizon[6][6];			//水平边
extern EDGE Vertical[6][6];			//数值边
extern int myturn;					//我方是先手还是后手，1代表先手，2代表后手
extern int Iscapture(int HorV,int x,int y,int turn);
extern int x,y;						//返回的边的位置
extern LIST Bestmove;				//最佳招法
extern int Search(int deep,int alpha,int beta,int turn);
extern bool IsDeadGridEdge();
extern int mboxes,yboxes;
//void Final_Occupy();


#endif

















