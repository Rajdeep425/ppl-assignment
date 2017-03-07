#include<iostream>
#include<fstream>
using namespace std;


void result(char ch) 
{
	bool line1=true;
	ifstream fin("infile.txt");
	ofstream fout("result.txt",ios::out);
	string line;
	string comp="\"";
	comp +=ch;
	comp +="\"";
	
	while(!fin.eof()) 
	{
		getline(fin,line);
		if(line.find(comp)!= string::npos)
		{
			if(line1==true)
			{
				line1=false;
				fout<<line;
			}
			else
				fout<<endl<<line;
		}
			
	}
	fin.close();
	fout.close();
}

void clean(char ch)
{
	bool line1=true;
	ifstream fin("result.txt");
	ofstream fout("cleaned.txt",ios::out);
	string line;
	string comp="\"";
	comp +=ch;
	comp +="\":";
	
	while(!fin.eof()) 
	{
		getline(fin,line);
		line.replace(0,13,"");
		if(line.find (',') != string::npos)
		{
			int pos=line.find (',');
			line.replace(pos,1,"");
		}
		if(line1==true)
			{
				line1=false;
				fout<<line;
			}
			else
				fout<<endl<<line;
	}
	fin.close();
	fout.close();
}

void batfile(string st)
{
	bool line1=true;
	ifstream fin("cleaned.txt");
	ofstream fout("final.bat",ios::out);
	string line;
	
	while(!fin.eof()) 
	{
		getline(fin,line);
		
			if(line1==true)
			{
				line1=false;
				fout<<st<<' '<<line;
			}
			else
				fout<<endl<<st<<' '<<line;
	}
	fin.close();
	fout.close();
}


int main() 
{
	char ch;
	cout<<" Enter the key  : "<<flush;
	cin>>ch;
	if(ch=='f' ||ch=='F'||ch=='r'||ch=='R'||ch=='s'||ch=='S'||ch=='m'||ch=='M')
	{
	
		result(ch);
		cout<<"\n result.txt created";
		
		//Clean file creation
		
		clean(ch);
		cout<<"\n cleaned.txt created";
		//Batch file creation
		
		string st;
		cout<<"\n Enter the associated program : "<<flush;
		cin>>st;
		batfile(st);
		cout<<"\n final.bat created";
		cout<<"\n Check your your folder for these files";
	}
	else
		cout<<"\n You Entered Invalid key";
}
