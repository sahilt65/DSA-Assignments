/*
Consider a student database of SEIT class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)

*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

struct result{
    //Creating Struct for Students
    int roll;
    string name;
    float SGPA;
}details;


void printDetails(result details[],int n){
    //Printing The Details of Students
    for(int i = 0; i<n; i++){
        cout<<"Roll No. : "<<details[i].roll<<" Name : "<<details[i].name<<" SGPA : "<<details[i].SGPA<<endl;
    }
}

//c.Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
int partition(result *details, int s, int e){//fxn for making partion in quick sort
    float pivot = details[s].SGPA;
    int count = 0;

    for(int i = s+1; i<=e; i++){
        if(details[i].SGPA>=pivot){
            count++;
        }
    }
    //placing pivot at right place
    int pivotIndex = s + count;

    //Transefering pivot at its right place
    swap(details[s].SGPA, details[pivotIndex].SGPA);
    swap(details[s].roll, details[pivotIndex].roll);
    swap(details[s].name, details[pivotIndex].name);

    //Checking for element on both side of pivot
    int i = s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(details[i].SGPA>pivot){
            i++;
        }

        while(details[j].SGPA < pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(details[i].SGPA, details[j].SGPA);
            swap(details[i].roll, details[j].roll);
            swap(details[i].name, details[j].name);

        }
    }
    return pivotIndex;
}

void quickSort(result *details, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    int p = partition(details, s, e);

    //sorting of left part
    quickSort(details, 0, p-1); //recursively calling quick sort for one part
    quickSort(details, p+1, e); //recursively calling quick sort for another part
}

void binarySearchName(result *details, int n, string str)
{   
    // cout<<"Searching for "<<str<<endl;
    if(n<=2){
        if( details[0].name == str){
            cout<<"Roll No. : "<<details[0].roll<<" Name : "<<details[0].name<<" SGPA : "<<details[0].SGPA<<endl;

        }else if ( details[1].name == str){
            cout<<"Roll No. : "<<details[1].roll<<" Name : "<<details[1].name<<" SGPA : "<<details[1].SGPA<<endl;

        }
    }

    int lo = 0, hi = n-1, mid;
    while(hi - lo > 1){
        mid = (hi + lo)/2;
        if(str >= details[mid].name){
            lo = mid;
        }else{
            hi = mid - 1;
        }

        if( details[lo].name == str){
            cout<<"Roll No. : "<<details[lo].roll<<" Name : "<<details[lo].name<<" SGPA : "<<details[lo].SGPA<<endl;
            break;
        }else if ( details[hi].name == str){
            cout<<"Roll No. : "<<details[hi].roll<<" Name : "<<details[hi].name<<" SGPA : "<<details[hi].SGPA<<endl;
            break;
        } 
    }
}

void bubbleSort(result details[], int n){
    for(int i = 0; i<=n-1; i++){
    //for round 1 to n-1
        for(int j=0; j<n-1-i; j++){
            if(details[j].roll > details[j+1].roll){
                swap(details[j].roll, details[j+1].roll);
                swap(details[j].name, details[j+1].name);
                swap(details[j].SGPA, details[j+1].SGPA);
            }
        }
    }
}

void insertionSort(result details[], int n){
    for(int i = 0; i< n; i++){
        string temp1 = details[i].name;
        int temp2 = details[i].roll;
        float temp3 = details[i].SGPA;

        int j = i-1;
        for(; j>=0; j--){
            if(details[j].name > temp1){
                //shift
                details[j+1].name = details[j].name;
                details[j+1].roll = details[j].roll;
                details[j+1].SGPA = details[j].SGPA;

            }else{
                break;
            }
        }
        details[j+ 1].name = temp1;
        details[j+ 1].roll = temp2;
        details[j+ 1].SGPA = temp3;
    }
}


void linearSearch(result *details, int n, float searchSGPA){
    vector<int> v; //Creating vector to store the indices of all students with the given SGPA
    for(int i = 0; i<n; i++){
        if(details[i].SGPA == searchSGPA){
            v.push_back(i);
        }
    }
    if(v.size() > 0){
        //Printing the details of students as per the searched SGPA
        cout<<"Details of students having SGPA "<<searchSGPA<<" is as follows "<<endl;
        for(int i = 0; i< v.size(); i++){
            cout<<"Roll No. : "<<details[v[i]].roll<<" Name : "<<details[v[i]].name<<" SGPA : "<<details[v[i]].SGPA<<endl;
        }
    }else{
        cout<<"No student Found"<<endl;
    }
}


int main(){
    int n;
    cout<<"Enter the number of students"<<endl;
    cin>>n;
    result info[n];
    cout<<"Enter info of students"<<endl;
    for(int i = 0; i<n; i++){
        cout<<"Enter the roll number of student "<<i+1<<" : ";
        cin>>info[i].roll;
        cout<<"Enter name of the  student "<<i+1<<" : ";
        cin>>info[i].name;
        cout<<"Enter the SGPA of student number "<<i+1<<" : ";
        cin>>info[i].SGPA;
        cout<<endl;
    }
    cout<<"Details of all students is as follows : "<<endl;
    printDetails(info, n);

    cout<<endl;

// a. Arrange the list of Student in ascending order of roll number using bubble sort
    bubbleSort(info, n);
    cout<<"The list of students in ascending order of their roll number is : "<<endl;
    printDetails(info, n);
    cout<<endl;


//b. Arrange list of students alphabetically using insertion sort
    insertionSort(info, n);
    cout<<"The list of students in alphabetical order of their names : "<<endl;
    printDetails(info, n);
    cout<<endl;


//c.Arrange list of students to find out first ten toppers from a class. (Use Quick sort)

    quickSort(info, 0, n-1);
    cout<<"Details of Top 10 Students is as follows : "<<endl;
    printDetails(info, n);
    cout<<endl;


//d. binary searching for SGPA
    float searchSGPA;
    cout<<"Enter SGPA You want to search : ";
    cin>>searchSGPA;
    linearSearch(info, n, searchSGPA);
    cout<<endl;


//e. Searching For Name using Binary Search
    string temp;
    cout<<"Enter the name of student you have to search for : ";
    cin>>temp;
    //Sorting by name
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(info[i].name > info[j].name){
                swap(info[i].SGPA, info[j].SGPA);
                swap(info[i].name, info[j].name);
                swap(info[i].roll, info[j].roll);
            }
        }
    }
    binarySearchName(info, n, temp);
    cout<<endl;

    return 0;
}
/*
15
Enter info of students
Enter the roll number of student 1 : 5
Enter name of the  student 1 : Yash
Enter the SGPA of student number 1 : 7

Enter the roll number of student 2 : 8
Enter name of the  student 2 : Pratik
Enter the SGPA of student number 2 : 9.3

Enter the roll number of student 3 : 1
Enter name of the  student 3 : Ayush
Enter the SGPA of student number 3 : 9.6

Enter the roll number of student 4 : 7
Enter name of the  student 4 : Hitesh
Enter the SGPA of student number 4 : 6

Enter the roll number of student 5 : 9
Enter name of the  student 5 : Kartik
Enter the SGPA of student number 5 : 7.5

Enter the roll number of student 6 : 2 
Enter name of the  student 6 : Pranav
Enter the SGPA of student number 6 : 8.9

Enter the roll number of student 7 : 3
Enter name of the  student 7 : Sonali
Enter the SGPA of student number 7 : 9.4

Enter the roll number of student 8 : 4
Enter name of the  student 8 : Suyash
Enter the SGPA of student number 8 : 9.6

Enter the roll number of student 9 : 6 
Enter name of the  student 9 : Poonam
Enter the SGPA of student number 9 : 9.6

Enter the roll number of student 10 : 12
Enter name of the  student 10 : Sahil
Enter the SGPA of student number 10 : 9.7

Enter the roll number of student 11 : 13
Enter name of the  student 11 : Parth
Enter the SGPA of student number 11 : 9.6

Enter the roll number of student 12 : 15
Enter name of the  student 12 : Yasharth        
Enter the SGPA of student number 12 : 9.6

Enter the roll number of student 13 : 14
Enter name of the  student 13 : Piyush
Enter the SGPA of student number 13 : 9.6

Enter the roll number of student 14 : 11
Enter name of the  student 14 : Rahul
Enter the SGPA of student number 14 : 9.8

Enter the roll number of student 15 : 10
Enter name of the  student 15 : Rohan
Enter the SGPA of student number 15 : 9.6

*/

