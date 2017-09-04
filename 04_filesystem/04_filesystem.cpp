// 04_filesystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
int main()
{
	using ::boost::filesystem::path;

	const path& temp_root =
		boost::filesystem::temp_directory_path() / "caffe_test";//取临时路径，path类改写了/操作符
	cout << boost::filesystem::create_directory(temp_root) << endl; //创建路径
	std::string s = temp_root.string(); //转化为string

	cout << boost::filesystem::current_path() << endl; //输出当前路径 ，"\\"
	
	try
	{
		boost::filesystem::copy_file("a.txt", "b.jpg"); //拷贝文件,如果文件已经存在直接报异常
	}
	catch (boost::filesystem::filesystem_error& e)
	{
		cout << "目标文件已经存在，将先删除文件" << endl;
		boost::filesystem::remove("b.jpg");
		boost::filesystem::copy_file("a.txt", "b.jpg");
	}

	

	//创建目录，需要父目录已经存在，不然直接报异常
	try
	{
		cout << boost::filesystem::create_directory("./a/b"); //虽然需要path的实参，但是通过string隐式初始化一个也可以
	}
	catch (const std::exception&)
	{
		cout << "需要创建的目录父目录不存在!" << endl;
	}
	
	
	
	cout << boost::filesystem::basename("a:\\b\\c.jpg"); //c
	cout << boost::filesystem::basename("a:\\b\\");//.
	cout << boost::filesystem::basename("a:\\b");//b
	cout << boost::filesystem::basename("a:/b");//b
	cout << endl;
	cout << boost::filesystem::absolute(".") << endl;//从当前路径转换为绝对路径
	cout << boost::filesystem::change_extension("a.jpg", ".txt") << endl; //a.txt
	cout << boost::filesystem::extension("b.jpg") << endl; //.jpg
	cout << boost::filesystem::extension("a\\") << endl; //输出空
	cout << boost::filesystem::exists("a.txt") << endl;
	cout << boost::filesystem::exists("E:\\caffe") << endl;
	cout << boost::filesystem::file_size("stdafx.h")<< endl;

	//还有很多其他方法


	system("pause");
    return 0;
}

