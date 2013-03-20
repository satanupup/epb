#include "table.h"


CTable::CTable()
{
	m_width=m_height=0;
	m_foodNumber=m_blockNumber=0;
	m_board=NULL;
}

CTable::~CTable()
{
	if(m_board != NULL)
	{
		SAFE_DELETE_ARRAY(m_board);
	}
}

//
//// 初始化桌子
//
void CTable::InitialTable(int w,int h)
{//初始化Table

	int i,j;
	//重新設置桌子的高度與寬度
	m_width=w;
	m_height=h;

	//其他成員變數的清空性質初始化
	m_snake.Initial();
	if(m_board != NULL)
	{
		SAFE_DELETE_ARRAY(m_board);
	}

	//根據高度和寬度創建一個新的桌子
	m_board=new int*[m_height];
	for(i=0;i<h;i++)
	{
		m_board[i]=new int[m_width];
		for(j=0;j<w;j++)
			m_board[i][j]=0;
	}

	//將桌子四周設置?牆
	//將頂部跟底部的邊緣設置?障礙物牆的狀態
	for(i=0;i<h;i++)
	{
		m_board[i][0]=TB_STATE_SBLOCK;
		m_board[i][m_width-1]=TB_STATE_SBLOCK;
	}
	//將左部和右部的邊緣設置?障礙物牆的狀態
	for(i=0;i<w;i++)
	{
		m_board[0][i]=TB_STATE_SBLOCK;
		m_board[m_height-1][i]=TB_STATE_SBLOCK;
	}
}

//
//// 在某個位置放置毒果
//
bool CTable::AddBlock(int x,int y)
{

	if( (x>=0)&&(x<m_width)&&
		(y>=0)&&(y<m_height)&&
		(m_board[y][x]==TB_STATE_OK) ) 
	{
		m_board[y][x]=TB_STATE_BLOCK;
		++m_blockNumber;
		return true;
	}
	else
	{
		return false;
	}
}

//
//// 在某個位置放置水果
//
bool CTable::AddFood(int x,int y)
{
	if( (x>=0)&&(x<m_width)&&
		(y>=0)&&(y<m_height)&&
		(m_board[y][x]==TB_STATE_OK) ) 
	{
		m_board[y][x]=TB_STATE_FOOD;
		++m_foodNumber;
		return true;
	}
	else
	{
		return false;
	}
}

//
//// 清楚某個位置的果實
//
bool CTable::ClearFood(int x,int y)
{
	m_board[y][x]=TB_STATE_OK;
	return true;
}

//
//// 獲取蛇物件
//
CSnake* CTable::GetSnake(void)
{
	return &m_snake;
}

//
//// 取桌子物件
//
int** CTable::GetBoard(void)
{
	return m_board;
}

//
//// 取桌子某個位置資料
//
int CTable::GetData(int x,int y)
{
	return m_board[y][x];
}

//
//// 蛇的移動
//
void CTable::SnakeMove(void)
{
	m_snake.Move();
}

//
//// 改變蛇的方向 
//
bool CTable::ChangeSnakeDirect(MoveState d)
{
	m_snake.ChangeDirect(d);
	return true;
} 
