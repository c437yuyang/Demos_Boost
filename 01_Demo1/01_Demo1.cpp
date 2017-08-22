// 01_Demo1.cpp : 定义控制台应用程序的入口点。
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
	// 建立一个 Mersenne twister 随机数产生器  
	// 使用 Unix 时间设定 seed  
	static mt19937 rng(static_cast<unsigned> (std::time(0)));

	// 选择高斯机率分布  
	normal_distribution<double> norm_dist(mean, sigma);

	// 使用 function 的形式，生成随机数据产生器  
	variate_generator<mt19937&, normal_distribution<double> > normal_sampler(rng, norm_dist);

	// 传回样本分布结果  
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