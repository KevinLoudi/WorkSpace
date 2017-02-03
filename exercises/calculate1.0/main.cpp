//
//  main.cpp
//  exercise
//
//  Created by KevinLiu on 17/2/3.
//  Copyright © 2017 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    double num1,num2;
    char operation;

    //to decide whether continue or not
    char redo = 'N';

    cout << "Welcome to Calculator v1.0 by Shirley!" << endl;

    do
    {
    cout << "Please enter the operation you want to calculate('+'or'-'or'*'or'/'):" << endl;
    cin >> operation;
    cout << "Please enter the first number:" << endl;
    cin >> num1;
    cout << "Please enter the second number:" << endl;
    cin >> num2;

    //calculate
    switch(operation)
    {
    case '+':
        cout << num1 << " + " << num2 << " = ";
        cout << (num1+num2) << endl;
        break;
    case '-':
        cout << num1 << " - " << num2 << " = ";
        cout << (num1-num2) << endl;
        break;
    case '*':
        cout << num1 << " * " << num2 << " = ";
        cout << (num1*num2) << endl;
        break;
    case '/':
        cout << num1 << " / " << num2 << " = ";
        if(num2==0)
            cout << "not valid" << endl;
        else
            cout << (num1/num2) << endl;
        break;
    default:
        cout << "unknown command" << endl;
        break;
    }

    //reset the value of redo
    cout << "enter 'Y' or 'y' to continue:" << endl;
    cin >> redo;

    }while(redo == 'Y'|| redo == 'y');

    return 0;
}
