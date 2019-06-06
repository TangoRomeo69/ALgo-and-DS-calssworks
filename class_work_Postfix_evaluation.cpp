#include "stack.h"

int main() {
    using namespace std;
    string expression;
    cout<<"Enter Postfix Expression \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout<<"Output = "<<result<<"\n";
}
