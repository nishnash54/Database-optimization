#include <iostream>
using namespace std;
int numA = 0, numB = 0;

class tableA
{
  char primary_key;
  int value;
  public:
    bool insert();
    void print()
    {
      cout<<primary_key<<"\t\t"<<value<<"\n";
    }
    char ret_pk()
    {
		return(primary_key);
	}
}A[10];

class tableB
{
	char foreign_key;
	int value;
	tableA *ptr = NULL;
	public:
	bool insert();
	void print()
    {
      cout<<foreign_key<<"\t\t"<<value<<"\n";
    }
    char ret_fk()
    {
		return(foreign_key);
	}
	tableA* ret_ptr()
	{
		return(ptr);
	}
}B[10];
	
bool check_primary_key(char pk)
{
	for(int i = 0;i<numA;i++)
	if(A[i].ret_pk()==pk)
	return(false);
    return(true);
}

bool check_foreign_key(char fk, tableA **ptr)
{
	for(int i = 0;i<numA;i++)
	if(A[i].ret_pk()==fk)
	{
		*ptr = &A[i];
		return(true);
	}
	return(false);
}

bool tableA :: insert()
{
      cout<<"Enter key : ";
      cin>>primary_key;
      cout<<"Enter value : ";
      cin>>value;
      if(check_primary_key(primary_key))
      {
        numA++;
        cout<<"1 Row inserted\n";
        return(true);
      }
      else
      cout<<"Primary key already in table\n";
      return(false);
}

bool tableB :: insert()
{
	cout<<"Enter key : ";
	cin>>foreign_key;
	cout<<"Enter value : ";
	cin>>value;
	if(check_foreign_key(foreign_key, &ptr))
	{
		numB++;
		cout<<"1 Row inserted\n";
		return(true);
	}
	else
	cout<<"Not a valid foreign key\n";
	return(false);
}

void direct_method()
{
	for(int i = 0;i<numB;i++)
	{
		cout<<"---------------------\n";
		B[i].print();
		(B[i].ret_ptr())->print();
	}
}

int main()
{
  int num_objA, num_objB;
  cout<<"Enter number of objects in TableA : ";
  cin>>num_objA;
  for(int i = 0;i<num_objA;i++)
  if(!A[i].insert())
  i--;
  cout<<"Table A\nPrimary key\tValue\n";
  for(int i = 0;i<num_objA;i++)
  A[i].print();
  
  cout<<"Enter number of objects in TableB : ";
  cin>>num_objB;
  for(int i = 0;i<num_objB;i++)
  if(!B[i].insert())
  i--;
  cout<<"Table B\nForeign key\tValue\n";
  for(int i = 0;i<num_objB;i++)
  B[i].print();
  
  cout<<"Using Direct method\n";
  direct_method();
  return(0);
}
