#ifndef _GREED_SNAKE_
#define _GREED_SNAKE_

#define SNAKE_MOVE 1
#define SAFE_DELETE(p) {delete (p);(p)=NULL;}
#define SAFE_DELETE_ARRAY(p) {delete[](p);(p)=NULL;}

#include <stdio.h>

//節點圖像顯示運動狀態(方向)
enum BitmapState{M_NONE,M_UP_UP,M_DOWN_DOWN,M_LEFT_LEFT,M_RIGHT_RIGHT,
	M_UP_LEFT,M_UP_RIGHT,M_LEFT_UP,M_LEFT_DOWN,
	M_RIGHT_UP,M_RIGHT_DOWN,M_DOWN_RIGHT,M_DOWN_LEFT};

//節點運動狀態(方向)
enum MoveState{S_NONE,S_UP,S_DOWN,S_LEFT,S_RIGHT};

//座標位置結構
struct SPoint
{
	int x;
	int y;
};

class CSnake
{
	struct Snake_Struct//定義蛇體狀態
	{
		MoveState head;  //頭部
		MoveState *body; //身體
		MoveState tail; //尾部
	};

private:
	int m_length;                 //蛇的長度
	Snake_Struct m_newSnake;      //蛇的新態的所有節點運動狀態
	Snake_Struct m_oldSnake;      //蛇的原態的所有節點運動狀態
	BitmapState *m_pStateArray;   //蛇的所有節點顯示點陣圖的狀態
	SPoint *m_pPos;                //蛇體座標

private:
	BitmapState GetRightState(MoveState oldDirect,MoveState newDirect);

public:

	void Move(void);          
	void ChangeDirect(MoveState d);
	void AddBody(int n=1);
	void SetHeadPos(int x,int y);
	BitmapState* GetStateArray(void);
	SPoint* GetPos(void);
	bool IsHeadTouchBody(int x,int y);
	int GetLength( void );
	void Initial( void );

public:
	CSnake(int x_pos=0,int y_pos=0,int len=1);
	~CSnake();
};


#endif //_GREED_SNAKE_ 
