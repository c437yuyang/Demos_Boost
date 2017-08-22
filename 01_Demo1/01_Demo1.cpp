// 01_Demo1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <boost/random.hpp>  
#include <ctime>  
using namespace std;

using namespace boost;

double SampleNormal(double mean, double sigma)
{
	// ����һ�� Mersenne twister �����������  
	// ʹ�� Unix ʱ���趨 seed  
	static mt19937 rng(static_cast<unsigned> (std::time(0)));

	// ѡ���˹���ʷֲ�  
	normal_distribution<double> norm_dist(mean, sigma);

	// ʹ�� function ����ʽ������������ݲ�����  
	variate_generator<mt19937&, normal_distribution<double> > normal_sampler(rng, norm_dist);

	// ���������ֲ����  
	return normal_sampler();
}

int main() 
{
	const int randNum = 100;
	int mean = 10; double sigma = 2;
	std::vector<double> dVec;
	double sum = 0.0;
	for (int i=0;i!= randNum;++i)
	{
		double d = SampleNormal((double)mean, sigma);
		sum += d;
		dVec.push_back(d);
	}
	
	cout << (sum /= (randNum*1.0)) << endl;;



	system("pause");
	return 0;
}