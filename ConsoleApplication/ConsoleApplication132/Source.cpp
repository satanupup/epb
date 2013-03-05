/* boost random_demo.cpp profane demo
*
* Copyright Jens Maurer 2000
* Distributed under the Boost Software License, Version 1.0. (See
* accompanying file LICENSE_1_0.txt or copy at
* http://www.boost.org/LICENSE_1_0.txt)
*
* $Id: random_demo.cpp 71018 2011-04-05 21:27:52Z steven_watanabe $
*
* A short demo program how to use the random number library.
*/

#include <iostream>
#include <fstream>
#include <ctime>            // std::time
#include <vector>
#include <string>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>

// This is a typedef for a random number generator.
// Try boost::mt19937 or boost::ecuyer1988 instead of boost::minstd_rand
typedef boost::minstd_rand base_generator_type;

void Additionalcc(int);
// This is a reproducible simulation experiment.  See main().
void experiment(base_generator_type & generator)
{
	// Define a uniform random number distribution of integer values between
	// 1 and 6 inclusive.
	typedef boost::uniform_int<> distribution_type;
	typedef boost::variate_generator<base_generator_type&, distribution_type> gen_type;
	int face=6;
	gen_type die_gen(generator, distribution_type(1, face));

	// If you want to use an STL iterator interface, use iterator_adaptors.hpp.
	boost::generator_iterator<gen_type> die(&die_gen);
	int cc=0;
	int sum=0;
	int teeth=5;
	int Adjusted=8;
	int Additional=0;
	std::vector<int> numbers; 

	for(int i = 0; i < teeth+1; i++)
	{
		numbers.push_back(*die++); 
	}
	numbers.erase(numbers.begin());

	printf("\nX 的「X」 擲了「%d d %d + %d」 ，擲出「",teeth,face,Adjusted);

	int sizz = numbers.size();
	for(int i=0;i<sizz;i++)
	{
		if(i == sizz-1)
		{
			std::cout <<numbers[i];
			sum = sum + numbers[i];
			if(numbers[i] == 6)
				Additional++;
		}
		else
		{
			std::cout <<numbers[i]<<"、";
			sum = sum + numbers[i];

			if(numbers[i] == 6)
				Additional++;
		}

	}


	boost::generator_iterator<gen_type> die2(&die_gen);
	if(Additional>0)
		printf("追加1d6 %d次:",Additional);

	int sum2=0;
	int aa=0;

	int Additional2=0;//0304
	boost::generator_iterator<gen_type> die3(&die_gen);// 0304

	
	for(int i=0;i<Additional;i++)
	{	  
		Additionalcc(1);
		aa = *die2++;
		sum2 = sum2 + aa;
		std::cout<<aa<<" ";

	}
	printf("」，總合為「%d」。\n",sum + Adjusted + sum2);


	std::cout << '\n';

}
int main()
{
	base_generator_type generator(42);
	generator.seed(static_cast<unsigned int>(std::time(0)));
	base_generator_type saved_generator = generator;
	experiment(generator);


	system("pause");
	return 0;
}

void Additionalcc(int n)
{
	base_generator_type generator(42);
	generator.seed(static_cast<unsigned int>(std::time(0)));
	base_generator_type saved_generator = generator;

	typedef boost::uniform_int<> distribution_type;
	typedef boost::variate_generator<base_generator_type&, distribution_type> gen_type;  
	gen_type die_gen(generator, distribution_type(1, 6));

	boost::generator_iterator<gen_type> die(&die_gen);
	int aa=0;
	for(int i=0;i<n;i++)
	{	  
		aa = *die++;
		std::cout<<" "<<aa<<" ";

	}

}