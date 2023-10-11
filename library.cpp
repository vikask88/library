#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<istream>
#include<ostream>
#include<stdlib.h>
#include<string>
using namespace std;
class Student
{
    public:
        char name[50];
        int id;
        char address[50];
        char kaksha[50];
        void setdata()
        {
            cout<<"Enter Student Name :";
            cin.ignore();
            cin.getline(name,50);
            cout<<"Enter Student id :";
            cin>>id;
            cout<<"Enter Student Address :";
            cin.ignore();
            cin.getline(address,50);
            cout<<"Enter Student Class :";
            cin.ignore();
            cin.getline(kaksha,50);
            ofstream file;
            file.open("record",ios::app);
            file.write((char*)this,sizeof(*this));
            file.close();
        }

        void del()
        {
            int x,local=0;
            cout<<"Enter Student ID :";
            cin>>x;
            ifstream file;
            ofstream New;
            file.open("record",ios::in|ios::binary);
            New.open("temporary",ios::out|ios::binary);
            if(!file)
            {
                cout<<"File Not Found";
            }
            else
            {
                file.read((char*)this,sizeof(*this));
                while(!file.eof())
                {
                    if(x==id)
                    {
                        ++local;
                    }
                    else
                    {
                        New.write((char*)this,sizeof(*this));
                    }
                     file.read((char*)this,sizeof(*this));
                }
            }

            New.close();
            file.close();
            remove("record");
            rename("temporary","record");
            if(local==0)
            {
                cout<<"Student Not Found";
            }
            else
            {
                cout<<"Account delete successfully";
            }
        }

        void modify()
        {
            int num,cont=0;
            cout<<"Enter Student Id :";
            cin>>num;
            ifstream r;
            ofstream w;
            w.open("local",ios::out|ios::binary);
            r.open("record",ios::in|ios::binary);
            r.read((char*)this,sizeof(*this));
            while(!r.eof())
            {
                if(num==id)
                {
                    ++cont;
                   cout<<"Enter Student Name :";
                    cin.ignore();
                    cin.getline(name,50);
                    cout<<"Enter Student id :";
                    cin>>id;
                    cout<<"Enter Student Address :";
                    cin.ignore();
                    cin.getline(address,50);
                    cout<<"Enter Student Class :";
                    cin.ignore();
                    cin.getline(kaksha,50);
                }
                w.write((char*)this,sizeof(*this));
                r.read((char*)this,sizeof(*this));
            }
            w.close();
            r.close();
            remove("record");
            rename("local","record");
            if(cont==0)
            {
                cout<<"< Record not found >"<<endl;

            }
            else
            {
                cout<<"Record Update successful";
            }
        }

        void show()
        {
            int i=0;
            ifstream f;
            f.open("record",ios::in);
            if(f){
                    f.read((char*)this,sizeof(*this));
                    while(!f.eof())
                    {
                        ++i;
                        cout<<id<<"\t"<<name<<"\t"<<address<<endl;
                        f.read((char*)this,sizeof(*this));
                    }
                    if(i==0)
                    {
                        cout<<"Sorry ! No Record Found";
                    }
                    f.close();
            }
            else{
                cout<<"< empty record >"<<endl;
            }
        }

        void deleteAll_record()
        {
            ofstream local("help",ios::out|ios::binary);
            local.close();
            remove("record");
            rename("help","record");
        }

        void search_student()
        {
            int n,cont=0;
            cout<<"Enter Student ID :";
            cin>>n;
            ifstream file;
            file.open("record",ios::in|ios::binary);
            file.read((char*)this,sizeof(*this));
            while(!file.eof())
            {
                if(n==id)
                {
                    cout<<id<<"\t"<<name<<"\t"<<address;
                    ++cont;
                    break;
                }
                file.read((char*)this,sizeof(*this));
            }
            if(cont==0)
            {
                cout<<"Record not found";
            }
            file.close();
        }

};
void menu();
int main()
{
    while(true)
    {
        system("cls");
        menu();
    }
    return 0;
}
void menu()
{
    Student temp;
    char status;
    int val;
    cout<<endl<<"//*===========WELCOME TO SPM COLLEGE===========*//"<<endl;
    cout<<endl<<"//*===========DEPARTMENT OF BCA===========*//"<<endl;
    cout<<endl<<"//*===========STUDENT RECORD MANAGEMENT===========*//"<<endl<<endl;
    cout<<"1. ADD STUDENT RECORD"<<endl;
    cout<<"2. DELETE STUDENT RECORD"<<endl;
    cout<<"3. MODIFY STUDENT RECORD"<<endl;
    cout<<"4. VIEW STUDENT RECORD"<<endl;
    cout<<"5. DELETE ALL STUDENT RECORD"<<endl;
    cout<<"6. SEARCH STUDENT RECORD"<<endl;
    cout<<"7. EXIT"<<endl<<endl;
    cout<<"ENTER CHOICE : ";
    cin>>val;
    switch(val)
    {
        case 1:
            temp.setdata();
            cout<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
            break;
        case 2:
            temp.del();
            cout<<endl<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
        case 3:
            temp.modify();
            cout<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
        case 4:
            temp.show();
            cout<<endl<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
        case 5:
            temp.deleteAll_record();
            cout<<"All Student Recored Deleted , successful"<<endl;
            cout<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
        case 6:
            temp.search_student();
            cout<<endl<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
        case 7:
            exit(0);
        default:
            cout<<"Invalid Choice, Try again "<<endl;
            cout<<"Do you want to continue [y/n] :" <<(status=(char)getch());
            if(status=='y'|| status=='Y')
                break;
            else
                exit(0);
    }
}