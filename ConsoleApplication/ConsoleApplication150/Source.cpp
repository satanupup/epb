#include <windows.h>
#include <iostream>
#include <string>
#include <vector> 
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

class cchar
{
public:	
	cchar()
	{
		file_sum=0;
	}
	cchar(string str)	{	}
	int test(string str)
	{
		char ch; 
		int count=0;
		ifstream fin(str, ios::in | ios::binary); 
		if(!fin) { 
			cout << "無法讀取檔案" << endl; 			
		} 

		while(!fin.eof()) { 
			fin.get(ch); 		
			if(ch=='\n')  
				count++;
		} 
		fin.close(); 		
		return count;
	}
	void title(string str)
	{
		path p = str;//"D:\\c++\\Studies_Wang\\LearningKing\\trunk\\";  	
		try
		{
			if (exists(p))    // does p actually exist?
			{
				if (is_regular_file(p))        // is p a regular file?   
					cout << p << " size is " << file_size(p) << '\n';

				else if (is_directory(p))      // is p a directory?
				{
					cout << p << " is a directory containing:\n";

					typedef vector<path> vec;             // store paths,
					vec v;                                // so we can sort them later

					copy(directory_iterator(p), directory_iterator(), back_inserter(v));

					sort(v.begin(), v.end());             // sort, since directory iteration
					// is not ordered on some file systems
					int ii = v.size();
					for(int i=0;i<ii;i++)
					{
						vecstr1.push_back(v[i].string() ); 
					}
				}

				else
					cout << p << " exists, but is neither a regular file nor a directory\n";
			}
			else
				cout << p << " does not exist\n";
		}

		catch (const filesystem_error& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	void show()
	{
		int ii = vecstr1.size();
		for(int i=0;i<ii;i++)
		{
			cout<<vecstr1[i]<<endl;
		}
	}
	void test2(string str)
	{

		char buf[1000];
		SetCurrentDirectoryA(str.c_str());  //設置
		GetCurrentDirectoryA(1000,buf);
		cout<<"當前路徑 "<<buf<<endl;
		string str1;
		int ii = vecstr1.size();
		for(int i=0;i<ii;i++)
		{
			path p (vecstr1[i]); 

			cchar cc;
			ofstream outfile;	
			str1 = p.filename().string();
			str1 += ".txt";

			outfile.open (str1);
			int isum =0;
			// >> i/o operations here <<	
			outfile<<p<<endl;

			try
			{
				if (exists(p))    // does p actually exist?
				{
					if (is_regular_file(p))        // is p a regular file?   
						cout << p << " size is " << file_size(p) << '\n';

					else if (is_directory(p))      // is p a directory?
					{
						cout << p << " is a directory containing:\n";

						typedef vector<path> vec;             // store paths,
						vec v;                                // so we can sort them later

						copy(directory_iterator(p), directory_iterator(), back_inserter(v));

						sort(v.begin(), v.end());             // sort, since directory iteration
						// is not ordered on some file systems
						int iin;
						int ii = v.size();
						for(int i=0;i<ii;i++)
						{					
							if(v[i].filename().extension() == ".pas")
							{
								cout<<v[i].filename()<<","<<cc.test(v[i].string())<<endl;
								iin = cc.test(v[i].string());
								isum += iin;
								outfile << v[i].filename()<<","<<iin<<endl;
							}
						}
					}

					else
						cout << p << " exists, but is neither a regular file nor a directory\n";
				}
				else
					cout << p << " does not exist\n";
			}

			catch (const filesystem_error& ex)
			{
				cout << ex.what() << '\n';
			}

			outfile<<"sum = "<<isum<<endl;
			file_sum += isum;
			outfile.close();
		}

	}
	void fileshow()
	{
		cout<<file_sum<<endl;

		ofstream outfile;
		outfile.open ("file_sum.txt");
		outfile<<file_sum<<endl;
	}
private: 
	vector<string> vecstr1;
	int file_sum;
};
int main()
{
//	cchar cc;
	//cc.title("D:\\c++\\Studies_Wang\\ELearningCRM\\trunk\\");
	//cc.test2("C:\\Users\\naseem\\Desktop\\test\\ELearningCRM\\");
	//cc.fileshow();

//	cc.title("D:\\c++\\Studies_Wang\\Go100Book\\trunk\\");
//	cc.test2("C:\\Users\\naseem\\Desktop\\test\\Go100Book\\");
//	cc.fileshow();

	//	cc.title("D:\\c++\\Studies_Wang\\LearningBest\\trunk\\");
	//	cc.test2("C:\\Users\\naseem\\Desktop\\test\\LearningBest\\");
	//cc.fileshow();

//		cc.title("D:\\c++\\Studies_Wang\\LearningKing\\trunk\\");
//		cc.test2("C:\\Users\\naseem\\Desktop\\test\\LearningKing\\");
//	cc.fileshow();
	/*
	cc.title("D:\\c++\\Studies_Wang\\WinLearning\\trunk\\");	
		cc.test2("C:\\Users\\naseem\\Desktop\\test\\WinLearning\\");
	cc.fileshow();
	*/

	system("pause");
	return 0;
}
