#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;
int numA, numB;
char setname[][2] = {"0", "1", "2", "3" ,"4" ,"5" ,"6"};
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
}B[8001];
	
bool check_primary_key(char pk[20])
{
	for(int i = 0;i<numA;i++)
	if(strcmp(A[i].ret_pk(), pk)==0)
	return(false);
    return(true);
}

bool check_foreign_key(char fk[20])
{
	for(int i = 0;i<numA;i++)
	if(strcmp(A[i].ret_pk(), fk)==0)
	return(true);
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
	strcpy(foreign_key,key);
	value = val;
	if(check_foreign_key(foreign_key))
	{
		numB++;
		//cout<<"1 Row inserted\n";
		return(true);
	}
	/*else
	cout<<"Not a valid foreign key\n";*/
	return(false);
}
void cartesitan()
{
	for(int i = 0;i<numA;i++)
	for(int j = 0;j<numB;j++)
	if(strcmp(A[i].ret_pk(), B[j].ret_fk())==0)
	{
		/*cout<<"---------------------\n";
		A[i].print();
		B[j].print();*/
	}
}
int main()
{
  int num_objA, num_objB, val;
  char key[20];
  for(int set = 0; set<7;set++)
  {
	  char filename[] = "Data/set_";
	  strcat(filename, setname[set]);
	  strcat(filename, ".txt");
	  cout<<filename<<"\n";
  for(int test = 0;test<10;test++)
  {
  numA = 0;
  numB = 0;
  clock_t start = clock();
  ifstream fin;
  fin.open(filename, ios::in);
  
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
  
  cout<<"\nUsing Cartesian product method\n";*/
  cartesitan();
  clock_t end = clock();
  cout<<"Execution time : "<<end - start<<"\n";
  fin.close();
  }
  }
  return(0);
}
