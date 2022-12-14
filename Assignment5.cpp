/*
Implement binary search tree and perform following operations:
a) Insert (Handle insertion of duplicate entry)
b) Delete
c) Search
d) Display tree (Traversal)
e) Display - Depth of tree
f) Display - Mirror image
g) Create a copy
h) Display all parent nodes with their child nodes
i) Display leaf nodes
j) Display tree level wise
(Note: Insertion, Deletion, Search and Traversal are compulsory, from rest of operations, perform
Any three)
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    public:
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST{
    public:
    Node* root;

    BST(){
        root = NULL;
    }

    Node* insert(Node* root,int data){
        Node* nodeToInsert = new Node(data);

        if(root == NULL){
            root = nodeToInsert;
            return root;
        }

        if(root -> data > data){
            root -> left = insert(root -> left, data);
        }else if(root -> data < data){
            root -> right = insert(root -> right, data);
        }else{
            cout<<"Cannot insert same data"<<endl;
        }
        return root;
    }

    Node* minVal(Node* root){
        Node* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }

        return temp;
    }

    Node* mmaxVal(Node* root){
        Node* temp = root;
        while(temp -> right != NULL){
            temp = temp -> right;
        }

        return temp;
    }

    void inOrder(Node* root){
        if(root == NULL){
            return;
        }

        inOrder(root -> left);
        cout<<root -> data<<" ";
        inOrder(root -> right);
    }

    void search(Node* root, int val){
        if(root == NULL){
            cout<<"Not Found"<<endl;
            return;
        }

        if(root -> data > val){
            search(root -> left, val);
        }else if(root -> data < val){
            search(root -> right, val);
        }else if( root -> data == val){
            cout<<"The data is Found"<<endl;
        }
    }

    Node* deleteNode(Node* root, int val){
        if(root == NULL){
            return NULL;
        }

        if(root -> data > val){
            root -> left = deleteNode(root -> left, val );
        }else if(root -> data < val){
            root -> right = deleteNode(root -> right, val);
        }else{
            //Case 1 : No child is present
            if( root -> left == NULL && root -> right == NULL){
                return NULL;
            }

            //Case 2 : Left Child is Present
            if( root -> right == NULL && root -> left != NULL){
                Node* temp = root -> left;
                delete(root);
                return temp;
            }

            //Case 3 : Right Child is present
            if( root -> right == NULL && root -> left != NULL){
                Node* temp = root -> right;
                delete(root);
                return temp;
            }

            //Cae 4 : If Both Child is present
            if(root -> right != NULL && root -> left != NULL ){
                Node* temp = minVal(root -> right);
                root -> data = temp -> data;

                root -> right = deleteNode(root -> right , temp -> data);
                return root;
            }

        }

        return root;
    }
    
    int height(Node* root){
        if(root == NULL){
            return 0;
        }

        else{
            int left = height(root -> left);
            int right = height(root -> right);
            
            if( left > right ){
                return (left + 1);
            }else{
                return (right + 1);
            }

        }
    }

    void printCurrLevelNodes(Node* root, int level){
        if(root == NULL){
            return ;
        }

        if(level == 1){
            cout<<root -> data<<" ";
        }
        if(level > 1){
            printCurrLevelNodes(root -> left , level - 1);
            printCurrLevelNodes(root -> right , level - 1); 
        }
        
    }


    void levelorderTraversal(Node* root){
        int n = height(root);
        cout<<"Printing Level order Traversal"<<endl;
        for(int i = 1; i<= n; i++){
            printCurrLevelNodes(root, i);
            cout<<endl;
        }
    }

    void mirrorimage(Node* root){
        if(root==NULL)
        {
            return;
        }
        Node* temp = root;
        mirrorimage(temp->left);
        mirrorimage(temp->right);
        Node* temp1;
        temp1=root->left;
        root->left=root->right;
        root->right=temp1;
    }

    void displayLeafNode(Node* root){
        if(root == NULL){
            return;
        }
        
        if(root -> right == NULL && root -> left == NULL){
            cout<<root -> data<<" ";
        }
        if(root -> left)
            displayLeafNode(root -> left);
        
        if(root -> right)
            displayLeafNode(root -> right);
        
    }

};

int main(){
    BST b;
    Node* root;
    cout<<"Enter the first element for Binary Search tree : "<<endl;
    int firstEle;
    cin>>firstEle;
    b.root = b.insert(b.root,firstEle);   

    int ch;
    do{
        cout<<"Enter your Choice:"<<endl;
        cout<<"1.Insert \n2.Delete \n3.Search Node \n4.Inorder Traversal \n5.Level Order Traversal \n6.Display Leaf Nodes \n7.Mirror Image. \n8.Exit"<<endl;
        cin>>ch;
        switch (ch){
            case 1 :
                int n;
                cout<<"Enter the number of element of you want to Insert in the Binary Search Tree"<<endl;
                cin>>n;
                cout<<"Enter the elements :"<<endl;
                for(int i = 0; i<n; i++){
                    int temp;
                    cin>>temp;
                    b.insert(b.root, temp);
                }
                break;

            case 2 :
                cout<<"Enter the value of Node you want to delet from the Binary Search Tree : "<<endl;
                int del;
                cin>>del;
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                b.deleteNode(b.root, del);
                cout<<"The node having value "<<del<<" has been deleted."<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 3:
                cout<<"Enter the value of Node you want to search for : "<<endl;
                int val;
                cin>>val;
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                b.search(b.root, val);
                cout<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 4:
                cout<<"The Inorder Traversal is : "<<endl;
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                b.inOrder(b.root);
                cout<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 5:
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Level order Traversal is : "<<endl;
                b.levelorderTraversal(b.root);
                cout<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 6 :
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"The Leaf Nodes of the given Binary Search Tree are : "<<endl;
                b.displayLeafNode(b.root);
                cout<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 7 :
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"The Mirror Image of the Binary Search Tree(Displaying in Level Order Traversal) is : ";
                b.mirrorimage(b.root);
                b.levelorderTraversal(b.root);
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                break;

        }
    }while(ch!=8);

    return 0;
}
