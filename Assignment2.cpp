/*
Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)
*/


#include <bits/stdc++.h>
using namespace std;

class Queue{
    int rear, front;
    int size;
    string *arr;
    


    public:
    Queue(int s){
        front = rear = -1;
        size = s;

        arr = new string[size];

    }

    void enQueue(string data){
        if((front == 0 && rear == (size -1)) || rear == (front -1)%(size -1)){
            cout<<"The Circular queue is full"<<endl;
            return ;
        }else if (front == -1) //Insert First Element 
        {
            front = rear = 0;
            arr[rear] = data;
        }else if (rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }else
        {
            rear++;
            arr[rear] = data;
        }   
    }

    string frontElement(){
        return arr[front];
    }

    void deQueue(){
        if(front == -1 || rear == -1){
            cout<<"The given queue is empty"<<endl;
            return ;
        }

        string data = arr[front];
        cout<<endl<<"***********************************************************************"<<endl;
        cout<<"The element "<<data<<" is deleted"<<endl;
        if(front == rear){ // If only one element is prsent in the queue
            front = rear = -1;
        }else if(front == size -1){
            front = 0;
        }else{
            front++;
        }
        cout<<endl<<"***********************************************************************"<<endl;
        


        return;
    }

    void displayCircularQueue(){
        if(front == -1 || rear == -1){
            cout<<"The given queue is empty"<<endl;
            return ;
        } 
        cout<<endl<<"***********************************************************************"<<endl;

        cout<<"Printing Queue"<<endl;
        if (rear >= front){
            for (int i = front; i <= rear; i++){//traversing from front to rear
                cout<<arr[i]<<" ";
            }
        }
        else{
            for (int i = front; i < size; i++)//traversing from front to end
            {
                cout<<arr[i]<<" ";
            }
                
            for (int i = 0; i <= rear; i++)//traversing from first to rear
            {
                cout<<arr[i]<<" ";
            }  
        }
        cout<<endl<<"***********************************************************************"<<endl;
    }

};


int main(){

    int n;
    cout<<"Enter the size of Queue"<<endl;
    cin>>n;

    Queue q(n);
    string temp ;
    int choice;
    while(choice != 4){
        cout<<"Enter the choice"<<endl;
        cout<<"Choice 1 : Add Elements to Queue"<<endl;
        cout<<"Choice 2 : Pop an Element from the que"<<endl;
        cout<<"Choice 3 : Display the que"<<endl;
        cout<<"Choice 4 : Exit"<<endl;

        cin>>choice;

        switch(choice){
            case 1: 
                cout<<"Enter the number of element  you want to add in the queue"<<endl;
                int num;
                cin>>num;
                for(int i = 0; i<num; i++){
                    string str;
                    cin>>str;
                    q.enQueue(str);
                }
                cout<<endl;
                break;

            case 2:
                q.deQueue();
                cout<<endl;
                break;

            case 3:
                q.displayCircularQueue();
                cout<<endl;
                break;

            case 4:
                break;

        }
    }
cout<<"You have exited"<<endl;
    
    return 0;
}
