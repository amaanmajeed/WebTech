#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int RollNo;
    string name;
    node* next;
};

node* head = new node();    //head of the list.

void Insert(int RollNo, string name)
{
    node* temp=new node();
    temp->RollNo=RollNo;
    temp->name=name;

    if(head==NULL||(head->RollNo>=temp->RollNo))
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        node* a=head;
        while (a->next!=NULL && a->next->RollNo<temp->RollNo)
        {
            a=a->next;
        }
        temp->next=a->next;
        a->next=temp;
    }
    cout<<"Record inserted."<<endl;
}

void Search(int RollNo)
{
    if(head==NULL)
    {
        cout<<"List not found."<<endl;
    }
    else
    {
        node* b=head;
        while (b)
        {
            if (b->RollNo==RollNo)
            {
                cout<<"Roll Number:\t"<<b->RollNo<<endl;
                cout<< "Name:\t"<<b->name<<endl;
            }
            b=b->next;
        }
        if (b==NULL)
            cout<<"No Record Found."<<endl;
    }
}

void Modify(int RollNo, string name, string name1)
{
    node* temp=head;
    while(temp->RollNo!=RollNo)
    {
        temp=temp->next;
    }
    if(temp!=NULL && temp->RollNo==RollNo)
    {
        name=name1;
    }
}


void Delete(int RollNo)
{
    node* temp=head;
    node* prev=NULL;

    if(temp!=NULL && temp->RollNo==RollNo)
    {
        head=temp->next;
        delete temp;
        cout << "Record Deleted."<<endl;
    }


    while(temp!=NULL && temp->RollNo!=RollNo)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout << "Record not found"<<endl;
    }
    else
    {
        prev->next=temp->next;
        delete temp;
        cout << "Record Deleted."<<endl;
    }
}


int main()
{
    head=NULL;
    string name,name1;
    int RollNo, choice;

    cout<<"\t \t \t Student Information System"<<endl;

    do
    {
        cout<<endl;
        cout<<"Please select what do you want to do."<<endl;
        cout<<"1: Add a Record."<<endl;
        cout<<"2: Search a record."<<endl;
        cout<<"3: Modify a record."<<endl;
        cout<<"4: Delete a record."<<endl;
        cout<<"5: Exit"<<endl;
        cout<<endl;
        cin>>choice;

        switch(choice)
        {
    case 1:
        {
            cout<<"\nPlease enter the Roll Number of student."<<endl;
            cin>>RollNo;
            cout<<"\nPlease enter the Name of student."<<endl;
            cin>>name;
            Insert(RollNo,name);
            break;
        }
    case 2:
        {
            cout<<"Please enter the Roll Number you want to search."<<endl;
            cin>>RollNo;
            Search(RollNo);
            break;
        }
    case 3:
        {
            cout<<"Please enter the Roll Number you want to modify"<<endl;
            cin>>RollNo;
            cout<<"Enter the previous name."<<endl;
            cin>>name;
            cout<<"Enter the new Name."<<endl;
            cin>>name1;
            Modify(RollNo,name,name1);
            break;
        }
    case 4:
        {
            cout<<"Please enter the roll number of the record you want to delete."<<endl;
            cin>>RollNo;
            Delete(RollNo);
            break;
        }
    case 5:
        {
            break;
        }
        }
    }
    while(choice!=5);

}
