#include "GA.h"

int main()
{
	srand((unsigned)time(0));
	GA ga;
	int nCounter = 0;

	// 初始化
	ga.init();
	cout << "基因演算法開始" << endl;
	while(nCounter < GENERATION_COUNT)
	{
		ga.reproduction();
		ga.crossover();
		ga.mutation();
		//ga.show();
		++nCounter;
		//cout << "第" << nCounter << "代繁殖完成！" << endl;

		// 若最好的個體已經找到，即可結束。
		if(ga.theBest.getScore() >= 28)
			break;
	}
	cout << "第" << nCounter << "代所有個體如下所示：" << endl;
	ga.show();
	cout << "最佳解為";
	ga.theBest.show();
	cout << "其分數為" << ga.theBest.getScore() << endl;	
	system("PAUSE");
	return 0;
}