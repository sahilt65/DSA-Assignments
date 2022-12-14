/*
Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    bool lchild, rchild;

    public:
    Node(){
        lchild = rchild = false;
        data = 0;
        left = right = NULL;
    }
};

class TBT{
    Node* root;

    public:
    TBT(){
        root = new Node();
        root -> data = INT_MAX;
        root -> rchild = true;
        root -> lchild = 0;

        root -> left = root;
        root -> right  = root;

    }

    void insert(int val){
        if(root -> left == root && root -> right == root){
            Node* newNode = new Node();
            newNode -> data = val;
            newNode -> left = root -> left;
            newNode -> right = root -> right;
            newNode -> lchild = root -> lchild;

            newNode-> rchild = false;
            root -> left = newNode;
            root -> lchild = true;
            return;
        }

        Node* curr = new Node();
        curr = root -> left;

        while(true){
            if(curr -> data < val){
                //right me jao
                Node* newNode = new Node();
                newNode -> data = val;
                if(curr -> rchild == 0){
                    newNode -> right = curr -> right;
                    newNode -> rchild = curr -> rchild;
                    newNode -> lchild = false;
                    newNode -> left = curr;
                    
                    curr -> rchild = true;
                    curr -> right   = newNode;
                    return;
                }else{
                    curr = curr -> right ;

                }
            }
            if(curr -> data > val){
                //left me jao
                Node* newNode = new Node();
                newNode -> data = val;
                if(curr -> lchild == 0){
                    newNode -> left = curr -> left;
                    newNode -> lchild = curr -> lchild;
                    newNode -> rchild = false;
                    newNode -> right = curr;

                    curr -> lchild = true;
                    curr -> left   = newNode;
                    return;
                }else{
                    curr = curr -> left ;

                }
            }
            if(curr -> data== val){
                cout<<"Cannot insert the same data"<<endl;
                return;
            }
        }
    }

    void inorder()
    {
        Node* temp;
        temp = root->left;
        while (temp->lchild == 1)
            temp = temp->left;
    
        // Loop to traverse the tree
        while (temp != root) {
            cout<< temp->data<<" ";
            temp = inorderSuccessor(temp);
        }
        cout<<endl;

    }
    
    Node* inorderSuccessor(Node* temp)
    {
        if (temp->rchild == false)
            return temp->right;
        else
            temp = temp->right;
        while (temp -> lchild == true) {
            temp = temp->left;
        }
        return temp;
    }

    void preorder()
    {
        Node* temp = root->left;

        while (temp != root) {
            cout<< temp->data<<" ";
            temp = preorderSuccessor(temp);
        }
        cout<<endl;
    }
    Node* preorderSuccessor(Node* temp)
    {
        if (temp->lchild == 1) {
            return temp->left;
        }
        while (temp->rchild == 0) {
            temp = temp->right;
        }
        return temp->right;
    }
};



int main() {
    TBT t;

    int ch = 0;
    while(ch != 4){
        cout<<"Enter your Choice \n1.Insert \n2.Inorder \n3.Preorder \4.Exit"<<endl;
        cin>>ch;
        switch (ch){
            case 1:
                int data;
                cout<<"Enter the value "<<endl;
                cin>>data;
                t.insert(data);
                break;
    
            case 2:
                cout<<"---------------------------------------------------------"<<endl;
                cout<<"Inorder"<<endl;
                t.inorder();
                cout<<"---------------------------------------------------------"<<endl;
                break;

            case 3:
                cout<<"---------------------------------------------------------"<<endl;
                cout<<"Preorder"<<endl;
                t.preorder();
                cout<<"---------------------------------------------------------"<<endl;
                break;
        }
    }

    return 0;
}
