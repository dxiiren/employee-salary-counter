#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void input3data (string & id , string & name , int & hour )
{   
     cout<<"\nEnter employee id : ";
	 cin>>id;
	 cin.get();
	 
	 cout<<"Enter employee name : ";
	 getline(cin,name);
	 
	 cout<<"Enter total hours of work (weekly) : ";
	 cin>>hour;	
}

double calcgrosspay (int hour )
{
	 if(hour<=40)
	     return hour*8;
	 else if (hour>40 && hour<=50)
	     return 40*8 + ( (hour-40)*12 );
	 else
	     return 40*8 + 10*12 + ( (hour-50)*16 );	
}

void calchighestpaid(double grosspay , string name, double & highest , string & highestname )
{  
	if(grosspay>highest)
		     { highestname=name;
		       highest=grosspay;
		     }
}

int main(){

     //declare variable
     int hour , employee=0 , underpaid=0 ;
     double grosspay , deduction , netpay , highest=0.0 , salary ;
     string id , name , highestname ;
     char answer='N';
     
     cout<<"MNC COMPANY\n";
	 cout<<"______________\n";
	 
	 while(toupper(answer)!='Y')
	 {
	 	input3data(id,name,hour);
	 	//process
	 	grosspay=calcgrosspay(hour);
	 	deduction= (0.08*grosspay) + (0.11*grosspay) + 10 ;
	 	netpay= grosspay-deduction;
	 	
	 	salary=netpay*4;
	 	
	 	calchighestpaid( salary , name , highest , highestname );
	 	
	 	if (salary<1200)
	 	    underpaid++;
	 	//display
	 	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Employee id= "<<id<<endl;
		cout<<"Employee name= "<<name<<endl;
		cout<<"Total gross pay = RM"<<grosspay<<endl;
		cout<<"Total deduction = RM"<<deduction<<endl;
		cout<<"Total net pay = RM"<<netpay<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	 	
	 	employee++;
		cout<<"\nDo you want to stop ? (y/n) : ";
		cin>>answer;
		cout<<endl;
	}
	cout<<"______________________________________________________________\n\n";
    cout<<"The total number of employee is : "<<employee<<endl;
    cout<<"The highest paid is : "<<highestname<<" , RM"<<highest<<endl;
    cout<<"Total underpaid employee is : "<<underpaid<<endl;
    cout<<"______________________________________________________________\n";	 
    return 0;
}
         
         
         



