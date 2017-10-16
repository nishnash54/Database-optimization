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
}B[10];
	
bool check_primary_key(char pk)
{
	for(int i = 0;i<numA;i++)
	if(A[i].ret_pk()==pk)
	return(false);
    return(true);
}

bool check_foreign_key(char fk)
{
	for(int i = 0;i<numA;i++)
	if(A[i].ret_pk()==fk)
	return(true);
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
	if(check_foreign_key(foreign_key))
	{
		numB++;
		cout<<"1 Row inserted\n";
		return(true);
	}
	else
	cout<<"Not a valid foreign key\n";
	return(false);
}
void cartesitan()
{
	for(int i = 0;i<numA;i++)
	for(int j = 0;j<numB;j++)
	if(A[i].ret_pk()==B[j].ret_fk())
	{
		cout<<"---------------------\n";
		A[i].print();
		B[j].print();
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
  
  cout<<"\nUsing Cartesian product method\n";
  cartesitan();
  
  return(0);
}
