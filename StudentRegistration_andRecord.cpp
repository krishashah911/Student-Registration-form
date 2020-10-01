#include<iostream>
#include<string.h>

using namespace std;

struct student
{
char name[20];
int maths;
int science;
int english;
int entryTest;
student* next;
};

struct list
{
char name[20];
double aggr;
list* next;
};

double calculate_aggregiate(student* stud)
{
student*s= stud;
double aggr;
aggr=(s->maths*25/100)+(s->science*25/100)+(s->english*10/100)+(s->entryTest*40/100);
return aggr;
}

void addToList(student* stud,list* l)
{

    list* head= l;
while(head->next!=NULL)
{
head=head->next;
}
head->next=new list;
head=head->next;
    strcpy(head->name,stud->name);
    head->aggr=calculate_aggregiate(stud);
    head->next=NULL;

}

bool register_student(student* stud,list* ls)
{
student* s=stud;
cout<<"\nWrite name of the Student\n";
cin>>s->name;
cout<<"\nEnter the marks for Maths Science and English\n";
cout<<"Maths:";
cin>>s->maths;
cout<<"Science:";
cin>>s->science;
cout<<"English:";
cin>>s->english;
cout<<"Enter marks scored in Entrance Exam: ";
cin>>s->entryTest;
double aggregiate;
aggregiate=calculate_aggregiate(s);
cout<<"\nAggregiate percentage is: "<< aggregiate<<"\n";
    if (aggregiate >= 70)
    {
        cout<<"\nCongratulations! You are eligible for Computers, Electronics or Mechanical\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >= 60)
    {
        cout<<"\nCongratulations! You are eligible for Electronics or Mechanical\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregiate >=50)
    {
        cout<<"\nCongratulations! You are eligible for Mechanical\n";
        addToList(s,ls);
        return true;
    }
    else
    {
        cout<<"\nSORRY, the student can't be registered in engineering\n";
        return false;
    }
}

void deleteFromList(list* l)
{
list*head=l;
list*ptr= new list;
list*prev= new list;
list*temp= new list;
char k[20];
char sure='n';

cout<<"\nEnter the name of the student to be deleted:\n";
cin>>k;

prev=ptr=head;
while(strcmp(ptr->name,k)!=0)
{
prev=ptr;
ptr=ptr->next;
if(ptr==NULL)
break;

}

if(ptr!=NULL)
{
cout<<"\nAre you sure you want to delete...Confirm[y/n]:";
cin>>sure;

if(sure=='y')
{
if(ptr==head)
{
temp=head->next;
delete head;
head=temp;
}

temp=ptr->next;
delete ptr;
prev->next=temp;

cout<<"\nRecord Deleted\n";
}

else if(sure=='n')
{
cout<<"\nRecord not Deleted\n";
}
}

else
{
cout<<"\nNo Matching Registration Found\n";
}


}

void showList(student* stud,list* l)
{
list* head=l;
int count= 7032100;
   if(head->next==NULL)
   {
       cout<<"\nNo student registered yet!\n";
   }
   else
   {

       cout<<"\nStudent Registration List:\n";
       cout<<"Course: B-Tech (INTEGRATED)";
       cout<<"Year: 2018-19"<<endl;
       cout<<"\nStudent Name\tStudent Number\tAggregiate\tEligible Courses\n\n";
       while(head->next!=NULL)
       {
           count++;
           head=head->next;
           //cout<<"-----------------------------------------------------------------\n";
           cout<<head->name<<"\t\t";
           cout<<count<<"\t\t";
           cout<<head->aggr<<"\t\t";
           if (head->aggr >= 70)
    {
        cout<<"CS EXTC MECH\n";
    }
    else if (head->aggr >= 60)
    {
        cout<<"EXTC MECH\n";
    }
    else if (head->aggr >=50)
    {
        cout<<"MECH\n";
    }
    //cout<<"-----------------------------------------------------------------\n";

       }
   }

}
/*******************Main Function*******************/
int main()
{
    cout<<"\t\tSHRI VILE PARLE KELAVANI MANDAL'S\n\t\tNarsee Monjee Institute of Management Studies\n";
    cout<<"\n";
    cout<<"Student Registration\n";
    cout<<"Course: B-Tech (INTEGRATED) ";
    cout<<"Year: 2018-19\n";
student* s=new student;
list* ls=new list;
ls->aggr=0;
ls->next=NULL;
int choice;

do
{
   cout<<"\n---------------------MENU---------------------";
   cout<<"\nPress\n 1] to register a new student\n 2] to display the list of registered students\n 3] to delete registration\n 4] to quit\n";
   cout<<"----------------------------------------------\n";
   cout<<"Enter your choice:";
   cin>>choice;

   switch(choice)
   {
   case 1:
    register_student(s,ls);
    break;

   case 2:
    showList(s,ls);
    break;

   case 3:
    deleteFromList(ls);
    break;

   }
}while(choice!=4);

return 0;
}
/**************************PROGRAM ENDS***********************/
