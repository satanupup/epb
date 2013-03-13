#include "GA.h"

////////////////////////////////////////////////////////////////////

eightQ::eightQ()
{
	randQ();
}

// 隨機產生一組解
void eightQ::randQ()
{
	sit.clear();
	for(int i = 0 ; i < GEN_LENGTH ; ++i)
	{
		sit.push_back(MyRand());
	}
}

// 計算此組解的分數
int eightQ::getScore()
{
	int nScore = 0;
	for (int i = 0; i < GEN_LENGTH; ++i)
	{
		int iPosX = i;
		int iPoxY = sit[i];
		//與其他皇后比較
		for (int j = i + 1; j < GEN_LENGTH; ++j)
		{
			//若不與此皇后同ROW
			if (!(iPoxY == sit[j]))
				//若不在此皇后右斜上
				if (!(iPoxY - iPosX == sit[j] - j))
					//若不在此皇后右斜下
					if (!(iPosX + iPoxY == sit[j] + j))
						nScore++;
		}
	}
	return nScore;
}

void eightQ::show()
{
	for(int i = 0 ; i < GEN_LENGTH ; ++i)
		cout << sit[i];
	cout << endl;
}

////////////////////////////////////////////////////////////////////

GA::GA()
{
	init();
}

void GA::init()
{
	eightQ newQ;
	// 隨機產生第一代
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		newQ.randQ();
		thisGen.push_back(newQ);
	}
	theBest = newQ;
}

void GA::reproduction()
{
	DadPool.clear();
	MomPool.clear();
	int nScoreSum = 0;
	vector<int> vAccumulate;
	// 將此代所有個體的適應力累加
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		nScoreSum += thisGen[i].getScore();
		vAccumulate.push_back(nScoreSum);
	}
	// 依照適應力的比例選擇母親與父親
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		int nRand = rand() % nScoreSum;
		for(int j = 0 ; j < POPULATION_COUNT ; ++j)
			if(nRand < vAccumulate[j])
			{
				DadPool.push_back(thisGen[j]);
				break;
			}
		nRand = rand() % nScoreSum;
		for(int j = 0 ; j < POPULATION_COUNT ; ++j)
			if(nRand < vAccumulate[j])
			{
				MomPool.push_back(thisGen[j]);
				break;
			}
		
	}
}

void GA::crossover()
{
	int nPos;
	thisGen.clear();
	// 使用單點雜交
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		// 決定雜交位置 3~6
		nPos = rand()%4 + 3;
		eightQ newQ;
		// 前面使用爸爸的染色體
		for(int j = 0 ; j < nPos ; ++j)
		{
			newQ.sit[j] = DadPool[i].sit[j];
		}
		// 後面使用媽媽的染色體
		for(int j = nPos ; j < GEN_LENGTH ; ++j)
		{
			newQ.sit[j] = MomPool[i].sit[j];
		}
		thisGen.push_back(newQ);
	}
}

void GA::mutation()
{
	// 每一個染色體判斷要不要突變
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		double dRate = (double)(rand() % 10000) / 10000.0f;
		if(dRate < MUTATION_RATE)
		{
			// 決定突變位置
			int nPos = MyRand();
			thisGen[i].sit[nPos] = MyRand();
		}
		// 計算是否比最佳解更好
		if(thisGen[i].getScore() > theBest.getScore())
			theBest = thisGen[i];
	}
}

void GA::show()
{
	for(int i = 0 ; i < POPULATION_COUNT ; ++i)
	{
		thisGen[i].show();
	}
}
