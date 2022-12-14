/*
Implement stack as an abstract data type using singly linked list and use this ADT for conversion of
infix expression to postfix, prefix and evaluation of postfix and prefix expression.
*/

#include<bits/stdc++.h>
using namespace std;

template<class T>
class node {
    public:
    T data;
    node<T>* next;
}; 

template<class T>
class Stack{
    private:
    node<T>* top;

    public:
    Stack() {
        top = NULL;
    }


    void push(int x){
        node<T>* newNode = new node<T> ;

        if(!newNode){
            cout<<"Stack overflow"<<endl;
        }

        newNode -> data = x;
        newNode -> next = top;
        top = newNode;
    }

    int isEmpty()
    {
        return top == NULL;
    }

    void print(){
        node<T>* temp;
        temp = top;
        if(top == NULL){
            // cout<<"Stack is empty"<<endl;
            return ;
        }else{
            while(temp != NULL){
                cout<<temp -> data <<" -> ";
                temp = temp -> next;
            }
        }
    cout<<endl;
    }

    void pop(){
        node<T>* temp;
        temp = top;

        if(top == NULL){
            // cout<<"Stack is empty"<<endl;
            return ;
        }else{
            // cout<<"The element "<<top -> data<<" is removed"<<endl;
            top = top -> next ;
            delete temp;
        }
    }

    int peek(){
        if(top == NULL){
            // cout<<"stack is empty"<<endl;
            return -1;
        }else{
            return top -> data;
        }
    }

};


//infix to postfix expression
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
 

string infixToPostfix(string s)
{
 
    Stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')){
            result += c;
        }else if (c == '('){
            st.push('(');
        }else if (c == ')') {
            while (st.peek() != '(') {
                result += st.peek();
                st.pop();
            }
            st.pop();
        }else {
            while (!st.isEmpty()
                   && prec(s[i]) <= prec(st.peek())) {
                result += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }
 
    while (!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
 
    return result;
}

//infix to Prefix
string infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());
 
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}


//Evaluate prefix Expression
bool isOperand(char c)
{
    return isdigit(c);
}
 
double evaluatePrefix(string exprsn)
{
    Stack<double> s;
 
    for (int j = exprsn.size() - 1; j >= 0; j--) {
 
        if (isOperand(exprsn[j]))
            s.push(exprsn[j] - '0');
 
        else {
            double o1 = s.peek();
            s.pop();
            double o2 = s.peek();
            s.pop();

            switch (exprsn[j]) {
            case '+':
                s.push(o1 + o2);
                break;
            case '-':
                s.push(o1 - o2);
                break;
            case '*':
                s.push(o1 * o2);
                break;
            case '/':
                s.push(o1 / o2);
                break;
            }
        }
    }
 
    return s.peek();
}

//Evaluate PostFix Expression
int evaluatePostfixExpression(string expression) {
    Stack<double> st;

    for (int i = 0; i < expression.length(); i++){
        char c = expression[i];

        if (c >= '0' && c <= '9'){
            int temp = (int)(c - '0');
            st.push(temp);
        }

        else{
            int op1 = st.peek();
            st.pop();

            int op2 = st.peek();
            st.pop();

            switch(c){
                case '+':
                    st.push(op2 + op1);
                    break;
                case '-':
                    st.push(op2 - op1);
                    break;
                case '*':
                    st.push(op2 * op1);
                    break;    
                case '/':
                    st.push(op2 / op1);
                    break;
            }
        }
    }
    
    return st.peek();
}

int main() {

    string str ;
    cout<<"Enter the Infix Expression"<<endl;
    cin>>str;

    int ch;


    while(ch!=4){
        cout<<endl;
        cout<<"Choose from th following option"<<endl;
        cout<<"1. Infix to Prefix"<<endl;
        cout<<"2. Infix to Postfix"<<endl;
        cout<<"3. Evaluate by using postfix or prefix"<<endl;
        cout<<"4. Exit"<<endl;
        

        cin>>ch;
        switch(ch){
            case 1:
                cout<<endl<<"-----------------------------------------------------------------"<<endl;
                cout<<"Prefix Expression is : "<<infixToPrefix(str)<<endl;
                cout<<"-----------------------------------------------------------------"<<endl;

                break;

            case 2:
                cout<<endl<<"-----------------------------------------------------------------"<<endl;
                cout<<"Postfix Expression is : "<<infixToPostfix(str)<<endl;
                cout<<"-----------------------------------------------------------------"<<endl;
                break;

            case 3:
                cout<<endl<<"-----------------------------------------------------------------"<<endl;
                cout<<"Evaluation of the given expression by prefix is : "<<evaluatePrefix(infixToPrefix(str))<<endl;
                cout<<"Evaluation of the given expression by postfix is : "<< evaluatePostfixExpression(infixToPostfix(str))<<endl;
                cout<<"-----------------------------------------------------------------"<<endl;
                break;
        }
    }

    cout<<"Exited"<<endl;
    

    return 0;
}

//2*3/(2-1)+5*3
