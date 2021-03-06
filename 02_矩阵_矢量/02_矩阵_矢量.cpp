// 02_矩阵_矢量.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/numeric/ublas/vector.hpp>  
#include <boost/numeric/ublas/matrix.hpp>  
#include <boost/numeric/ublas/io.hpp>  
#include <iostream>  

using namespace boost::numeric::ublas;

/* 举例 "y = Ax" */
int main()
{
	vector<double> x(2);
	x(0) = 1; x(1) = 2;

	matrix<double> A(2, 2);
	A(0, 0) = 0; A(0, 1) = 1;
	A(1, 0) = 2; A(1, 1) = 3;

	vector<double> y = prod(A, x);

	std::cout << y << std::endl;
	return 0;
}

