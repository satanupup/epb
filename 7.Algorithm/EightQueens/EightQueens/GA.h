#ifndef GA_H
#define GA_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// 染色體長度
#define GEN_LENGTH 8
// 每一代的數量
#define POPULATION_COUNT 50
// 繁衍代數
#define GENERATION_COUNT 10000
// 突變機率
#define MUTATION_RATE 0.1
// 隨機產生0~7的數字
#define MyRand() (rand()%8)

class eightQ
{
public:
	eightQ();
	void randQ();
	int getScore();
	void show();
	vector<int> sit;
};


class GA
{
public:
	GA();
	void init();
	void reproduction();
	void crossover();
	void mutation();
	void show();
	eightQ theBest;
private:
	vector<eightQ> thisGen;
	vector<eightQ> DadPool;
	vector<eightQ> MomPool;
};
#endif