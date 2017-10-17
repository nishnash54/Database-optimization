#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;
char setname[][2] = {"0", "1", "2", "3" ,"4" ,"5" ,"6"};
int numA, numB;

class tableA
{
  char primary_key[20];
  int value;
  public:
    bool insert(char key[20], int val);
    void print()
    {
      cout<<primary_key<<"\t\t"<<value<<"\n";
    }
    char* ret_pk()
    {
		return(primary_key);
	}
}A[8001];

class tableB
{
	char foreign_key[20];
	int value;
	tableA *ptr = NULL;
	public:
	bool insert(char key[20], int val);
	void print()
    {
      cout<<foreign_key<<"\t\t"<<value<<"\n";
    }
    char* ret_fk()
    {
		return(foreign_key);
	}
	tableA* ret_ptr()
	{
		return(ptr);
	}
}B[8001];
	
bool check_primary_key(char pk[20])
{
	for(int i = 0;i<numA;i++)
	if(strcmp(A[i].ret_pk(), pk)==0)
	return(false);
    return(true);
}

bool check_foreign_key(char fk[20], tableA **ptr)
{
	for(int i = 0;i<numA;i++)
	if(strcmp(A[i].ret_pk(), fk)==0)
	{
		*ptr = &A[i];
		return(true);
	}
	return(false);
}

bool tableA :: insert(char key[20], int val)
{
      strcpy(primary_key, key);
      value = val;
      if(check_primary_key(primary_key))
      {
        numA++;
        //cout<<"1 Row inserted\n";
        return(true);
      }
      /*else
      cout<<"Primary key already in table\n";*/
      return(false);
}

bool tableB :: insert(char key[20], int val)
{
	strcpy(foreign_key, key);
	value = val;
	if(check_foreign_key(foreign_key, &ptr))
	{
		numB++;
		//cout<<"1 Row inserted\n";
		return(true);
	}
	/*else
	cout<<"Not a valid foreign key\n";*/
	return(false);
}

void direct_method()
{
	for(int i = 0;i<numB;i++)
	{
		/*cout<<"---------------------\n";
		B[i].print();
		(B[i].ret_ptr())->print();*/
	}
}

int main()
{
	ofstream fout;
	fout.open("Data/extime_direct.txt",ios::out);
  for(int set = 0;set<7;set++)
  {
	  char filename[] = "Data/set_";
	  strcat(filename, setname[set]);
	  strcat(filename, ".txt");
	  cout<<filename<<"\n";
	  fout<<filename<<"\n";
  for(int test = 0;test<10;test++)
  {
  numA = 0;
  numB = 0;
  int num_objA, num_objB, val;
  char key[20];
  ifstream fin;
  fin.open(filename, ios::in);
  clock_t start = clock();
  fin>>num_objA;
  for(int i = 0;i<num_objA;i++)
  {
	  fin>>key>>val;
	  if(!A[i].insert(key, val))
	  i--;
  }
  /*cout<<"Table A\nPrimary key\tValue\n";
  for(int i = 0;i<num_objA;i++)
  A[i].print();*/
  
  fin>>num_objB;
  for(int i = 0;i<num_objB;i++)
  {
	  fin>>key>>val;
	  if(!B[i].insert(key, val))
	  i--;
  }
  /*cout<<"Table B\nForeign key\tValue\n";
  for(int i = 0;i<num_objB;i++)
  B[i].print();
  
  cout<<"Using Direct method\n";*/
  direct_method();
  clock_t end = clock();
  float tim = end - start;
  fout<<tim<<"\n";
  cout<<"Execution time : "<<tim<<"\n";
  fin.close();
  }
  }
  fout.close();
  return(0);
}
