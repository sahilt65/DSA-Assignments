/*
Department maintains student’s database. The file contains roll number, name, division and address.
Write a program to create a sequential file to store and maintain student data. It should allow the
user to add, delete information of student. Display information of particular student. If record of
student does not exist an appropriate message is displayed. If student record is found it should
display the student details.
 */

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Student
{
   int rollNo, div;
   string name, address;
};

class FileHandeling
{
public:
    Student s;
    void createDatabase(){
        ifstream file("Student.txt");

        fstream file1("Student.txt", ios :: out | ios :: binary);
        cout<<"Database created succefully"<<endl;
        file1.close();
    }

    void addStudent(){
        cout<<"Enter Student Details"<<endl;
        cout<<"Name : ";
        cin>>s.name;
        cout<<"Roll Number : ";
        cin>>s.rollNo;
        cout<<"Div : ";
        cin>>s.div;
        cout<<"Enter address : ";
        cin>>s.address;

        fstream writeinFile("Student.txt", ios :: app | ios :: binary);
        writeinFile.write((char*)&s, sizeof(s));
        cout<<"Record added successfully"<<endl;
        writeinFile.close();
    }

    void DisplayFileContent(){
        fstream read_file;
        read_file.open("Student.txt", ios::in | ios::binary);
        if(!read_file){
            cout<<"\nFile Not Found";
            return;
        }
        else{
            read_file.read((char*)&s, sizeof(s)); 
            while(!read_file.eof()) 
            {
                cout<<"\n"<<s.rollNo<<"\t"<<s.name<<"\t"<<s.address<<"\t"<<s.div;
                read_file.read((char*)&s, sizeof(s)); 
            }
        }

        cout<<endl;
        read_file.close();
    }

    void deleteInfo(){
        int roll;
        cout<<endl<<"Enter the roll Number of student"<<endl;
        cin>>roll;
        int flag = 0;

        fstream readFile("Student.txt", ios :: in | ios :: binary);
        fstream newFile("new.txt", ios :: out | ios :: binary);

        if(!readFile){
            cout<<"Some errro occured"<<endl;
            return;
        }else{
            readFile.read((char*)&s, sizeof(s));

            while(!readFile.eof()){
                if(s.rollNo != roll){
                    newFile.write((char*)&s, sizeof(s));
                }else{
                    cout<<"Record Found"<<endl;
                    flag = 1;
                }
                readFile.read((char*)&s, sizeof(s));
            }

            readFile.close();
            newFile.close();
            remove("Student.txt");
            rename("new.txt","Student.txt");

            if(flag == 1){
                cout<<"Data deleted successfully"<<endl;
            }
            if(flag == 0){
                cout<<"Data not found"<<endl;
            }
        }
    }

    void search(){
        string searchName;
        cout<<endl<<"Enter the Name of student"<<endl;
        cin>>searchName;
        int flag = 0;
        

        fstream readFile("Student.txt", ios :: in | ios :: binary);

        if(!readFile){
            cout<<"Some errro occured"<<endl;
            return;
        }else{
            readFile.read((char*)&s, sizeof(s));

            while(!readFile.eof()){
                if(s.name == searchName){
                    cout<<"Data Found"<<endl;
                    flag = 1;
                    cout<<"\n"<<s.rollNo<<"\t"<<s.name<<"\t"<<s.address<<"\t"<<s.div;
                    cout<<endl;
                    break;
                }
                readFile.read((char*)&s, sizeof(s));
            }
            readFile.close();
            if(flag == 0){
                cout<<"Data not found"<<endl;
            }
        }
    }
    
    void updateInfo(){
        int roll;
        cout<<endl<<"Enter the roll Number of student whose information you want to update"<<endl;
        cin>>roll;
        int flag = 0;
        Student temp;

        fstream readFile("Student.txt", ios :: in | ios :: binary);
        fstream newFile("new.txt", ios :: out | ios :: binary);

        if(!readFile){
            cout<<"Some errror occured"<<endl;
            return;
        }else{
            readFile.read((char*)&s, sizeof(s));
            while(!readFile.eof()){
                if(s.rollNo != roll){
                    newFile.write((char*)&s, sizeof(s));
                }else{
                    cout<<"Record Found : "<<endl;
                    cout<<"Enter the name of student : ";
                    cin>>temp.name;
                    cout<<"Enter Division of the student : ";
                    cin>>temp.div;
                    temp.rollNo = roll;
                    cout<<"Enter the address of the student : ";
                    cin>>temp.address;
                    newFile.write((char*)&temp, sizeof(temp));
                    flag = 1;
                }
                readFile.read((char*)&s, sizeof(s));
            }
            readFile.close();
            newFile.close();
            remove("Student.txt");
            rename("new.txt","Student.txt");

            if(flag == 1){
                cout<<"Data Updated successfully"<<endl;
            }
            if(flag == 0){
                cout<<"Data not found"<<endl;
            }
        }
    }
};

int main()
{

    FileHandeling f;
    int ch = 0;

    while(ch != 6){
        cout<<"Enter your choice \n1.Create Database of Student \n2.Add Student in the Database \n3.Delete Information from the Database \n4.Search in Database\n5.Display Content of Database \n6.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1 :
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                f.createDatabase();
                cout<<"------------------------------------------------------------------------------------------"<<endl; 

                break;

            case 2 :
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                f.addStudent();
                cout<<"------------------------------------------------------------------------------------------"<<endl; 

                break;

            case 3 :
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                f.deleteInfo();
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                break;

            case 4 :
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                f.search();
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                break;

            case 5 :
                cout<<"------------------------------------------------------------------------------------------"<<endl; 
                f.DisplayFileContent();
                cout<<"------------------------------------------------------------------------------------------"<<endl; 

                break;       
        }
    }



    return 0;
}


void updateInfo(){
        int roll;
        cout<<endl<<"Enter the roll Number of student whose information you want to update"<<endl;
        cin>>roll;
        int flag = 0;
        Student temp;

        fstream readFile("Student.txt", ios :: in | ios :: binary);
        fstream newFile("new.txt", ios :: out | ios :: binary);

        if(!readFile){
            cout<<"Some errror occured"<<endl;
            return;
        }else{
            readFile.read((char*)&s, sizeof(s));
            while(!readFile.eof()){
                if(s.rollNo != roll){
                    newFile.write((char*)&s, sizeof(s));
                }else{
                    cout<<"Record Found : "<<endl;
                    cout<<"Enter the name of student : ";
                    cin>>temp.name;
                    cout<<"Enter Division of the student : ";
                    cin>>temp.div;
                    temp.rollNo = roll;
                    cout<<"Enter the address of the student : ";
                    cin>>temp.address;
                    newFile.write((char*)&temp, sizeof(temp));
                    flag = 1;
                }
                readFile.read((char*)&s, sizeof(s));
            }
            readFile.close();
            newFile.close();
            remove("Student.txt");
            rename("new.txt","Student.txt");

            if(flag == 1){
                cout<<"Data Updated successfully"<<endl;
            }
            if(flag == 0){
                cout<<"Data not found"<<endl;
            }
        }
    }
