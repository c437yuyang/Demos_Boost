// 05_lexical_cast.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace boost;
void test1() {
	int x = lexical_cast<int>("100");
	long y = lexical_cast<long>("2000");
	float pai = lexical_cast<float>("3.14159e5");
	double e = lexical_cast<double>("2.71828");
	cout << x << " " << y << " " << pai << " " << e << endl;

	string str = lexical_cast<string>(456);
	cout << str << endl;
	cout << lexical_cast<string>(0.6810) << endl;
	cout << lexical_cast<string>(0x10) << endl;
}
int main() {
	test1();

	system("pause");
	return 0;
}

