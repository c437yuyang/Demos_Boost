// 04_filesystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
int main()
{
	using ::boost::filesystem::path;

	const path& temp_root =
		boost::filesystem::temp_directory_path() / "caffe_test";//ȡ��ʱ·����path���д��/������
	cout << boost::filesystem::create_directory(temp_root) << endl; //����·��
	std::string s = temp_root.string(); //ת��Ϊstring

	cout << boost::filesystem::current_path() << endl; //�����ǰ·�� ��"\\"
	
	try
	{
		boost::filesystem::copy_file("a.txt", "b.jpg"); //�����ļ�,����ļ��Ѿ�����ֱ�ӱ��쳣
	}
	catch (boost::filesystem::filesystem_error& e)
	{
		cout << "Ŀ���ļ��Ѿ����ڣ�����ɾ���ļ�" << endl;
		boost::filesystem::remove("b.jpg");
		boost::filesystem::copy_file("a.txt", "b.jpg");
	}

	

	//����Ŀ¼����Ҫ��Ŀ¼�Ѿ����ڣ���Ȼֱ�ӱ��쳣
	try
	{
		cout << boost::filesystem::create_directory("./a/b"); //��Ȼ��Ҫpath��ʵ�Σ�����ͨ��string��ʽ��ʼ��һ��Ҳ����
	}
	catch (const std::exception&)
	{
		cout << "��Ҫ������Ŀ¼��Ŀ¼������!" << endl;
	}
	
	
	
	cout << boost::filesystem::basename("a:\\b\\c.jpg"); //c
	cout << boost::filesystem::basename("a:\\b\\");//.
	cout << boost::filesystem::basename("a:\\b");//b
	cout << boost::filesystem::basename("a:/b");//b
	cout << endl;
	cout << boost::filesystem::absolute(".") << endl;//�ӵ�ǰ·��ת��Ϊ����·��
	cout << boost::filesystem::change_extension("a.jpg", ".txt") << endl; //a.txt
	cout << boost::filesystem::extension("b.jpg") << endl; //.jpg
	cout << boost::filesystem::extension("a\\") << endl; //�����
	cout << boost::filesystem::exists("a.txt") << endl;
	cout << boost::filesystem::exists("E:\\caffe") << endl;
	cout << boost::filesystem::file_size("stdafx.h")<< endl;

	//���кܶ���������


	system("pause");
    return 0;
}

