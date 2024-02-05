//This is a code designed to check whether or not the string inputted by the user is a palindrome or not. A palindrome is a word that is spelt the same forwards and backwards. The code uses a stack to check whether or not the string is a palindrome by pushing and poping the ltters on the stakc in reverse order and cross checking the strings to see if they match//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100; // Maximum size for the stack and string

class Check //class declaration
{
private:
    char str[MAX]; 
    int front;

    void push(char* stack, char ch) //void function to push the value onto the stack
    { 
        if(front == MAX - 1) //check to see if the stack has been overfilled
        {
            cout << "Overflow" << endl; //print out message to indicat stack has been overfilled
            return;
        }
        stack[++front] = ch; // add value to the stack
    }

    char pop(char* stack) //character function to pop the value from the stack
    {
        if(front == -1) //check to see if the stack has no values in it
        {
            cout << "Underflow" << endl; //print out message to indicate stack in underfilled
            return 0; //return function
        }
        return stack[front--]; //return the value from the stack
    }

public:
    Check() : front(-1) {} // Constructor initializing front to -1

    void get() //void function to read value from user
    {
        cout << "Please Enter a String" << endl; //prompts user for string input
        cin.getline(str, MAX);
    }

    void check() //check function to determine wether or not the input was a palindrome
    {
        char stack[MAX]; //create a stack
        int length = strlen(str); //declare calue for length of string
        int count = 0; //declare value to contain the count of the values in the string

        // Push all characters of the string into the stack
        for(int i = 0; i < length; i++) 
        {
            push(stack, str[i]); //push value onto the stack 
        }

        // Check if the string is a palindrome
        for(int i = 0; i < length; i++) 
        {
            if(str[i] == pop(stack)) //pop value from stack if it matches the value in the string
            {
                count++; //increase count value
            }
        }

        if(count == length) 
        {
            cout << "Is Palindrome" << endl;
        } 
        else 
        {
            cout << "Not A Palindrome" << endl;
        }
    }

    void print() //prints the string 
    {
      {
        for(int i = strlen(str) - 1; i >= 0; i--) 
        {
            cout << str[i];
        }
        cout << endl;
      }
    }
};

int main() 
{
    Check stack1; 
    stack1.get(); //get the inputted value
    stack1.print(); //print the inputted value
    stack1.check(); //check to see if the inputted value is a palindrome
    return 0;
}
