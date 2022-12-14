/*
Construct an Expression Tree from postfix and prefix expression. Perform recursive and nonrecursive In-order, pre-order and post-order traversals
*/

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    node *right;
    node *left;
    node *next;
    node(char ch)
    {
        data = ch;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
class Stack
{
public:
    node *top;
    Stack()
    {
        top = NULL;
    }
    void push(node *newNode)
    {
        newNode->next = top;
        top = newNode;
    }
    node *pop()
    {
        node *temp = top;
        top = top->next;
        return temp;
    }
    node *peek()
    {
        if (top == NULL)
        {
            return NULL;
        }
        else
        {
            return top;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};

class Tree
{
public:
    node *createTreeFromPostfix()
    {
        string postfix;
        cout << "Enter the postfix String " << endl;
        cin >> postfix; // Taking input of Postfix String
        Stack s1;
        for (int i = 0; i < postfix.length(); i++)
        {
            if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*')
            {
                node *temp = new node(postfix[i]);
                temp->right = s1.pop();
                temp->left = s1.pop();
                s1.push(temp);
            }
            else
            {
                node *temp = new node(postfix[i]);
                s1.push(temp);
            }
        }
        return s1.pop();
    }
    node *createTreeFromPrefix()
    {
        string prefix;
        cout << "Enter a Prefix String " << endl;
        cin >> prefix;
        Stack s1;
        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '/' || prefix[i] == '*')
            {
                node *temp = new node(prefix[i]);
                temp->left = s1.pop();
                temp->right = s1.pop();
                s1.push(temp);
            }
            else
            {
                node *temp = new node(prefix[i]);
                s1.push(temp);
            }
        }
        return s1.pop();
    }
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    void inOrder(node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }
        // Order => L P R
        inOrder(root->left);       // L : Going to left child
        cout << root->data << " "; // P : printing data to root node
        inOrder(root->right);      // R : Goung to right child
    }
    void inOrderIterative(node *root)
    {
        Stack s;
        node *temp = root;
        while (temp != NULL || s.isEmpty() == false)
        {
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.peek();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right; // after visiting the left of a node we have to visit the right of that node
        }
    }
    void preOrder(node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " "; // P : printing data to root node
        preOrder(root->left);      // L : Going to left child
        preOrder(root->right);     // R : Going to right child
    }
    void preorderIterative(node *root)
    {
        // Base Case
        if (root == NULL)
            return;
        // Create an empty stack and push root to it
        Stack nodeStack;
        nodeStack.push(root);
        while (nodeStack.isEmpty() == false)
        {
            // Pop the top item from stack and print it
            struct node *node = nodeStack.peek();
            cout << node->data << " ";
            nodeStack.pop();
            // Push right children of the popped node to stack
            if (node->right)
            {
                nodeStack.push(node->right);
            }
            // Push left children of the popped node to stack
            if (node->left)
            {
                nodeStack.push(node->left);
            }
            // Here we are pushing right child first because we have to process left child first
        }
    }
    void postOrder(node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left); // L : Going to left child

        postOrder(root->right);     // R : Going to right child
        cout << root->data << " "; // P : printing data to root node
    }
    void postOrderIterative(node *root)
    {
        if (root == NULL)
            return;
        // Create two stacks
        Stack s1, s2;
        // push root to first stack
        s1.push(root);
        node *node;
        // Run while first stack is not empty
        whil(!s1.isEmpty())
        {
            // Pop an item from s1 and push it to s2
            node = s1.peek();
            s1.pop();
            s2.push(node);
            // Push left and right children
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }
        // Print all elements of second stack which is in postorder form
        while (!s2.isEmpty())
        {
            node = s2.peek();
            s2.pop();
            cout << node->data << " ";
        }
    }
};
int main()
{
    Tree t1;
    node *root = t1.createTreeFromPostfix();
    int ch = 0;
    while (ch != 4)
    {
        cout << "1.Postorder \n2.Preorder \n3.Inorder \n4.Exit \nEnter your Choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Postorder : ";
            t1.postOrder(root);
            cout << endl;
            break;
        case 2:

            cout << "Preorder : ";
            t1.preOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "Inorder : ";
            t1.inOrderIterative(root);
            cout << endl;
            break;
        case 4:
            break;
        }
    }
    Tree t2;
    node *root2 = t2.createTreeFromPrefix();
    int ch2 = 0;
    while (ch2 != 4)
    {
        cout << "1.Postorder \n2.Preorder \n3.Inorder \n4.Exit \nEnter your Choice" << endl;
        cin >> ch2;
        switch (ch2)
        {
        case 1:
            cout << "Postorder : ";
            t2.postOrder(root);
            cout << endl;
            break;
        case 2:
            cout << "Postorder : ";
            t2.preOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "Inorder : ";
            t2.inOrder(root);
            cout << endl;
            break;
        case 4:
            break;
        }
    }
    return 0;
}
