#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <fstream>
using namespace std;

struct acc
{
    string name;
    int accno;
    float balance;
};
void saveacc(acc a)
{
    ofstream file("Account.txt");
    file << a.name<<" "<<a.accno<<" "<<a.balance<< endl;
    file.close();
}
void appacc(acc a)
{
    ofstream file("Account.txt",ios::app);
    file << a.name<<" "<<a.accno<<" "<<a.balance<< endl;
    file.close();

}
int loadacc(acc customer[])
{
    ifstream file("Account.txt");
    int count=0; while (file >> customer[count].name >> customer[count].accno >> customer[count].balance) {
        count++;
    }
    file.close();
    return count;
}
void accdetails(acc &a)
{
    
     
    
    

    
    
        cout<<"Enter name: ";
        cin>>a.name;
        cout<<"Enter intial Balance: ";
        cin>>a.balance;
        a.accno=rand() % (5000 - 1000 + 1) + 1000;
        cout<<"Acc no: "<<a.accno<< endl;
    
}
void addamt(acc &a,float added)
{
    a.balance+=added;
    cout<<"Amount added successfully. New amount: "<<a.balance<<endl;
}
void withdraw(acc &a,float remove)
{
    if(remove<=a.balance)
    {
        a.balance=a.balance-remove;
        cout<<"Amount successfully transacted. Remaining amount "<<a.balance<<endl;
    }
    else
    {
        cout<<"Insufficient balance";
    }
}
void showacc(acc a)
{
     cout<<"ID No: "<<a.accno<< endl;
    cout<<"Name: "<<a.name<< endl;
     cout<<"Current Balance: "<<a.balance<< endl;
}
int search(acc a[],int c,int id)
{
  int i,j=0;
  for(i=0;i<c;i++)
  {
    if(a[i].accno==id)
    {
        j++;
        return i;
    }
    
  }
  if(j==0)  
  {
    return -1;
  }
    
}


int main()
{
        system("color 0A"); 
       srand(time(0));
    acc customer[20];
     int count=0;
     count=loadacc(customer);
       cout << count << " account(s) loaded from file.\n";
    
    int choice;
    cout<<"Enter "<<"1"<<" for "<<"Adding account"<< endl;
     cout<<"Enter "<<"2"<<" for "<<"Adding amount"<< endl;
      cout<<"Enter "<<"3"<<" for "<<"Transacting money"<< endl;
       cout<<"Enter "<<"4"<<" for "<<"Display acc details"<< endl;
        cout<<"Enter "<<"5"<<" for "<<"Exit"<< endl;
    choice=1;
   
    do
    {
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            
            if(count<20)
            {
                accdetails(customer[count]);
                appacc(customer[count]); 
                count++;
            }
            else
            {
                cout<<"Limit Reached";
            }
            break;
            case 2:
            {
            cout<<"Give ID No in which you want to add: ";
            int idn;
            cin>>idn;
            int searched=search(customer,count,idn);
            if(searched!=-1)
            { 
              cout<<"Enter amount: ";
              float amt;
              cin>>amt;
              addamt(customer[searched],amt);
              saveacc(customer[searched]);

            }
            else
            {
                cout<<"No such ID found.";
            }
            break;}
            case 3:
            {
            cout<<"Give ID No in which you want to transact: ";
            int idn2;
            cin>>idn2;
            int searched2=search(customer,count,idn2);
            if(searched2!=-1)
            { 
              cout<<"Enter amount: ";
              float amt2;
              cin>>amt2;
              
              withdraw(customer[searched2],amt2);
              saveacc(customer[searched2]);

            }
            else
            {
                cout<<"No such ID found.";
            }
            break;
        }
            case 4:
            {
            cout<<"Give ID No whose detail you wannna check: ";
            int idn3;
            cin>>idn3;
             int searched3=search(customer,count,idn3);
            if(searched3!=-1)
            { 
                showacc(customer[searched3]);
             

            }
            else
            {
                cout<<"No such ID found.";
            }
            break;
        }
            case 5:
            {
            cout<<"Exit";
            break;
            }
            default:
            {
            cout<<"Wrong Input";
            }






        }
        

    }
    while(choice!=5);

    system("pause");
    return 0;
}
