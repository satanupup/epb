#include "snake.h"
CSnake::CSnake(int x_pos,int y_pos,int len)
{
	if(len<1) len=1;
	int i;

	m_length=len;  //蛇的身體體長

	//初始化蛇的座標位置
	m_pPos=new SPoint[m_length+2];
	m_pPos[0].x=x_pos;m_pPos[0].y=y_pos;
	for(i=1;i<m_length+2;i++)
	{
		m_pPos[i].x=0;m_pPos[i].y=0;
	}

	//初始化蛇的運動狀態
	m_newSnake.head=S_NONE;
	m_oldSnake.head=S_NONE;
	m_newSnake.body=new MoveState[m_length];
	m_oldSnake.body=new MoveState[m_length];
	for(i=0;i<m_length;i++)
	{
		m_newSnake.body[i]=S_NONE;
		m_newSnake.body[i]=S_NONE;
	}
	m_newSnake.tail=S_NONE;
	m_oldSnake.tail=S_NONE;

	//初始化蛇的點陣圖顯示狀態
	m_pStateArray=new BitmapState[m_length+2];
	for(i=0;i<m_length+2;i++)
		m_pStateArray[i]=M_NONE;
}

CSnake::~CSnake()
{
	SAFE_DELETE_ARRAY(m_pStateArray);
	SAFE_DELETE_ARRAY(m_pPos);
}

//
//根據新舊兩個身體的運動趨勢情況，返回當前應當顯示的身體狀態
//
BitmapState CSnake::GetRightState(MoveState oldDirect,MoveState newDirect)
{
	BitmapState res = M_NONE;
	switch(oldDirect)
	{
	case S_NONE:
		switch(newDirect)
		{
		case S_NONE:
			res=M_NONE;
			break;
		case S_UP:
			res=M_UP_UP;
			break;
		case S_DOWN:
			res=M_DOWN_DOWN;
			break;
		case S_LEFT:
			res=M_LEFT_LEFT;
			break;
		case S_RIGHT:
			res=M_RIGHT_RIGHT;
			break;
		}
		break;
	case S_UP:
		switch(newDirect)
		{
		case S_UP:
			res=M_UP_UP;
			break;
		case S_LEFT:
			res=M_UP_LEFT;
			break;
		case S_RIGHT:
			res=M_UP_RIGHT;
			break;
		}
		break;
	case S_DOWN:
		switch(newDirect)
		{
		case S_DOWN:
			res=M_DOWN_DOWN;
			break;
		case S_LEFT:
			res=M_DOWN_LEFT;
			break;
		case S_RIGHT:
			res=M_DOWN_RIGHT;
			break;
		}
		break;
	case S_LEFT:
		switch(newDirect)
		{
		case S_LEFT:
			res=M_LEFT_LEFT;
			break;
		case S_UP:
			res=M_LEFT_UP;
			break;
		case S_DOWN:
			res=M_LEFT_DOWN;
			break;
		}
		break;
	case S_RIGHT:
		switch(newDirect)
		{
		case S_RIGHT:
			res=M_RIGHT_RIGHT;
			break;
		case S_UP:
			res=M_RIGHT_UP;
			break;
		case S_DOWN:
			res=M_RIGHT_DOWN;
			break;
		}
		break;
	}
	return res;
}

//
//改變方向
//
void CSnake::ChangeDirect(MoveState d)
{
	//  改變方向的條件：非對立方向
	//  只能?其左，前，右方
	switch(d)
	{
	case S_NONE:
		m_newSnake.head=d;
		break;
	case S_UP:
		if(m_newSnake.head!=S_DOWN) m_newSnake.head=d;
		break;
	case S_DOWN:
		if(m_newSnake.head!=S_UP) m_newSnake.head=d;
		break;
	case S_LEFT:
		if(m_newSnake.head!=S_RIGHT) m_newSnake.head=d;
		break;
	case S_RIGHT:
		if(m_newSnake.head!=S_LEFT) m_newSnake.head=d;
		break;
	}
}

//
//蛇移動
//
void CSnake::Move(void)
{
	int i;
	//1.計算新狀態各個節點的狀態
	//保存蛇身體各個部位的形狀
	for(i=0;i<m_length;i++)
	{
		m_oldSnake.body[i]=m_newSnake.body[i];
	}	

	//將蛇身體的狀態根據前面的狀態變動一次
	m_newSnake.tail=m_newSnake.body[m_length-1];
	for(i=m_length-1;i>0;i--)
	{
		m_newSnake.body[i]=m_newSnake.body[i-1];
	}
	m_newSnake.body[0]=m_newSnake.head;	

	//根據新舊狀態特性取正確的狀態
	m_pStateArray[0]=GetRightState(m_oldSnake.head,m_newSnake.head);
	for(i=0;i<m_length;i++)
		m_pStateArray[i+1]=GetRightState(m_oldSnake.body[i],m_newSnake.body[i]);
	m_pStateArray[m_length+1]=GetRightState(m_oldSnake.tail,m_newSnake.tail);


	//2.將整個蛇的座標移動
	//除蛇頭外，其他部分的新位置?其前一部分的原來位置
	for(i=m_length+1;i>0;i--)
		m_pPos[i]=m_pPos[i-1];
	//蛇頭的新位置根據蛇的運動方向判斷做相應偏移
	switch(m_newSnake.head)
	{
	case S_UP:
		m_pPos[0].y-=SNAKE_MOVE;
		break;
	case S_DOWN:
		m_pPos[0].y+=SNAKE_MOVE;
		break;
	case S_LEFT:
		m_pPos[0].x-=SNAKE_MOVE;
		break;
	case S_RIGHT:
		m_pPos[0].x+=SNAKE_MOVE;
		break;
	}

}

//
//蛇的身體增長
//
void CSnake::AddBody(int n)
{

	//  分配臨時的"save類型"變數，用作保留
	//  蛇的各種資料狀態
	int i;
	Snake_Struct saveOldSnake,saveNewSnake;
	BitmapState *savestateArray;
	SPoint *savePos;

	//保存蛇的位置資訊 
	// pos
	savePos=new SPoint[m_length+2];
	for(i=0;i<m_length+2;i++)
		savePos[i]=m_pPos[i];

	//保存蛇的狀態資訊
	//  1.oldSnake
	//  2.newSnake
	//  3.stateArray

	//1
	saveOldSnake.head=m_oldSnake.head;
	saveOldSnake.body=new MoveState[m_length];
	for(i=0;i<m_length;i++)
		saveOldSnake.body[i]=m_oldSnake.body[i];
	saveOldSnake.tail=m_oldSnake.tail;
	//2
	saveNewSnake.head=m_newSnake.head;
	saveNewSnake.body=new MoveState[m_length];
	for(i=0;i<m_length;i++)
		saveNewSnake.body[i]=m_newSnake.body[i];
	saveNewSnake.tail=m_newSnake.tail;
	//3
	savestateArray=new BitmapState[m_length+2];
	for(i=0;i<m_length+2;i++)
		savestateArray[i]=m_pStateArray[i];

	//將長度增長
	m_length+=n;

	//釋放所有蛇的身體存儲資料空間
	delete[] m_oldSnake.body;m_oldSnake.body=NULL;
	delete[] m_newSnake.body;m_newSnake.body=NULL;
	delete[] m_pStateArray;m_pStateArray=NULL;
	delete[] m_pPos;m_pPos=NULL;

	//創建並初始化增長後的蛇的存儲資料空間

	m_newSnake.head=S_NONE;
	m_oldSnake.head=S_NONE;
	m_newSnake.body=new MoveState[m_length];
	m_oldSnake.body=new MoveState[m_length];
	for(i=0;i<m_length;i++)
	{
		m_newSnake.body[i]=S_NONE;
		m_newSnake.body[i]=S_NONE;
	}
	m_newSnake.tail=S_NONE;
	m_oldSnake.tail=S_NONE;

	m_pStateArray=new BitmapState[m_length+2];
	for(i=0;i<m_length+2;i++)
		m_pStateArray[i]=M_NONE;
	m_pPos=new SPoint[m_length+2];
	for(i=0;i<m_length+2;i++)
	{
		m_pPos[i].x=0;
		m_pPos[i].y=0;
	}

	//恢復原來長度的資料(新的用初始化的資料)
	//a. newSnake ,oldSnake狀態
	//b. stateArray
	//c. pos

	//a
	m_newSnake.head=saveNewSnake.head;
	m_oldSnake.head=saveOldSnake.head;

		
	for(i=0;i<m_length-n;i++)
	{
		m_newSnake.body[0]=saveNewSnake.body[0];
		m_oldSnake.body[0]=saveOldSnake.body[0];
	}
	m_newSnake.tail=saveNewSnake.tail;
	m_oldSnake.tail=saveOldSnake.tail;
	
	//b
	for(i=0;i<m_length-n+2;i++)
		m_pStateArray[i]=savestateArray[i];

	//c
	for(i=0;i<m_length-n+2;i++)
		m_pPos[i]=savePos[i];
}

//
//設置蛇頭的座標
//
void CSnake::SetHeadPos(int x,int y)
{
	m_pPos[0].x=x;m_pPos[0].y=y;
}

//
//取蛇的狀態標識陣列
//
BitmapState* CSnake::GetStateArray(void)
{
	return m_pStateArray;
}

//
//取蛇的位置陣列
//
SPoint* CSnake::GetPos(void)
{
	return m_pPos;
}

//
//取蛇身的長度
//
int CSnake::GetLength(void)
{
	return m_length+2;
}

//
//檢測蛇頭是否觸碰到其身體
//
bool CSnake::IsHeadTouchBody(int x,int y)
{
	int i;
	for(i=1;i<m_length+2;i++)
		if(m_pPos[i].x==x&&m_pPos[i].y==y) return true;
	return false;
}

//
//初始化 用作遊戲結束後重新開始
//
void CSnake::Initial(void )
{
	//釋放以前的所有存儲空間
	SAFE_DELETE_ARRAY(m_pStateArray);
	SAFE_DELETE_ARRAY(m_pPos);

	//創建蛇身長度?1的蛇，並做各種初始化
	int i;
	int x = 0;
	int y = 0;

	//初始化蛇的座標位置
	m_length=1;
	m_pPos=new SPoint[m_length+2];
	m_pPos[0].x=x;m_pPos[0].y=y;
	for(i=1;i<m_length+2;i++)
	{
		m_pPos[i].x=0;m_pPos[i].y=0;
	}

	//初始化蛇的運動狀態
	m_newSnake.head=S_NONE;
	m_oldSnake.head=S_NONE;
	m_newSnake.body=new MoveState[m_length];
	m_oldSnake.body=new MoveState[m_length];
	for(i=0;i<m_length;i++)
	{
		m_newSnake.body[i]=S_NONE;
		m_newSnake.body[i]=S_NONE;
	}
	m_newSnake.tail=S_NONE;
	m_oldSnake.tail=S_NONE;

	//初始化蛇的點陣圖顯示狀態
	m_pStateArray=new BitmapState[m_length+2];
	for(i=0;i<m_length+2;i++)
		m_pStateArray[i]=M_NONE;
} 
