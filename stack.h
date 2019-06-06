#include<iostream>
#include<string>

template< typename T >
class Stack{
private:
    int stackSize;
    T *stackValues;
    int top;
public:
    Stack(int = 10);
    ~Stack();
    void push( T );
    void pop();
    void extendSize(int = 10);
    void display();
    T topElement();
    void reset();
    bool isEmpty();
    bool isFull();
};

template< typename T > Stack<T>::Stack(int x): stackSize(x), stackValues(new T[stackSize]), top(-1){}

template< typename T > Stack<T>::~Stack() {
    delete [] stackValues;
}

template< typename T > bool Stack<T>::isFull()
{
    if((top + 1) == stackSize )
        return true;
    else
        return false;
}

template< typename T > bool Stack<T>::isEmpty()
{
    if( top  == -1 )
        return true;
    else
        return false;
}

template< typename T > void Stack<T>::push(T x)
{
    if(!Stack<T>::isFull())
    {
        stackValues[++top] = x;
    }
    else{
        extendSize();
        stackValues[++top] = x;
    }
}
template< typename T > void Stack<T>::pop()
{
    if(!Stack<T>::isEmpty())
    {
        top --;
    }
    else
    {
        top=-1;
    }
}
template< typename T > void Stack<T>::extendSize( int size) {
    T *S = new T[stackSize + size];
    for (int i = 0; i < stackSize; i++) {
        S[i] = stackValues[i];
    }
    stackSize += size;
    delete[] stackValues;
    stackValues = S;
}
template< typename T > void Stack<T>::display(){
    if(!Stack<T>::isEmpty()){
        std::cout<<"\nStack: "<<std::endl;
        for( int i=top; i>=0; i-- ){
            std::cout << stackValues[i] << std::endl;
        }
    }
    else
    {
        std::cout<< "\nStack is Empty\n";
    }
}
template< typename T > T Stack<T>::topElement() {
    if (!Stack<T>::isEmpty()) {
        return stackValues[top];
    }
    else {
        return 0;
    }
}
template< typename T > void Stack<T>::reset() {
    top = -1;
}

bool IsOperand(char C) {
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C) {
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

int GetOperatorWeight(char op) {
    int weight = -1;
    switch(op) {
        case '+':
        case '-': {
            weight = 1;
            break;
        }
        case '*':
        case '/': {
            weight = 2;
            break;
        }
    }
    return weight;
}

bool HasHigherPrecedence(char op1, char op2) {
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    if(op1Weight == op2Weight)
    {
        return true;
    }
    return op1Weight > op2Weight ?  true: false;
}

std::string InfixToPostfix(std::string expression) {
    Stack<char> S;
    std::string postfix = "";
    for(int i = 0;i< expression.size();i++) {

        if(IsOperator(expression[i])) {
            while(!S.isEmpty() && S.topElement() != '(' && HasHigherPrecedence(S.topElement(),expression[i]))
            {
                postfix+= S.topElement();
                S.pop();
            }
            S.push(expression[i]);
        }
        else if(IsOperand(expression[i])) {
            postfix +=expression[i];
        }

        else if (expression[i] == '(') {
            S.push(expression[i]);
        }

        else if(expression[i] == ')') {
            while(!S.isEmpty() && S.topElement() !=  '(') {
                postfix += S.topElement();
                S.pop();
            }
            S.pop();
        }
    }

    while(!S.isEmpty()) {
        postfix += S.topElement();
        S.pop();
    }

    return postfix;
}

bool IsNumericDigit(char C) {
    if(C >= '0' && C <= '9'){
        return true;
    }
    return false;
}

int PerformOperation(char operation, int operand1, int operand2) {
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;

    else std::cout<<"Unknown operand\n";
    return -1;
}

int EvaluatePostfix(std::string expression) {
    Stack<int> S;
    for(int i = 0;i< expression.length();i++) {

        if(IsNumericDigit(expression[i])){
            S.push(expression[i]-'0');
        }
        else if(IsOperator(expression[i])) {
            int operand2 = S.topElement();
            S.pop();
            int operand1 = S.topElement();
            S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
    }
    return S.topElement();
}
