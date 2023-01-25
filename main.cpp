/*
File Name: Assign2_Q1.cpp
Name: Jacob Galvez
Course.Sect: 3358-256

This program does many things... 
1st - it finds the Arithmetic Progression recursively of given values in an array.
2nd - calculates the average recusively of an array.
3rd - finds the Standard Deviation recursively of a given array.
4th - encrypts a message by shifting letters in the alphabet by 3
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arithmeticProgression(const int, const int, int);
double averageArray(double[], int);
double sum(double[], int);
int sizeOfArray(double[]);
double sumOfSqDiff(double[], int);
double sumOfSq(double[], int);
double stdDevArray(double[], int);
string cipher(string, int);
string uppercase(string);


int main() {
  int start, diff, n, r; //start is starting value of AP, n and r are counters, diff is the difference for AP
  const int MAX = 100;
  double values[MAX] = {8.1, 9.9, 5.6, 7.8};
  r = sizeOfArray(values);
  string choice, message;
  cout << "Arithmetic Progression: " << arithmeticProgression(1, 10, 5) << endl;;
  cout << "Average: " << averageArray(values, r) << endl;
  cout << "Std Dev of Array: " << stdDevArray(values, r) << endl;
  
  //int value;

  message = "This is a simple cipher";
  message = uppercase(message);
  cout << "Encrypted Message: " << cipher(message, 0) << endl<<endl;

 
}

/*
int arithmeticProgression() - function that calculates the Arithmetic Progression of given values recursively
parameters:
const int start - the starting value of the AP
const int diff - how many numbers we want to skip each time
int n - counter for how many times we want Arithmetic Progression to happen
*/
int arithmeticProgression(const int start,const int diff, int n)
{
  if (n <= 0) // base case
  {
    return start;
  }
  else
  {
    //cout << start << endl; // getting closer, doesnt start at position 0 THO!!!

    return arithmeticProgression(start + diff, diff, n - 1);
  }
}

/*
double averageArray() - function that uses the sum() function to calculate the average of an array recursively.
parameters:
double values[] - values to be averaged
int r - # of values in array.
*/
double averageArray(double values[], int r)
{
  int counter = 0;
  if (r <=0)
  {
    return 0;
  }
  else
  {
    double avg = sum(values, r - 1) / r;
    counter ++;
    return avg / counter;
  }

}

/*
 double sum() - adds all the numbers in given array.
 parameters:
 double values[] - array of values to be summed.
 int r - counter for recursion, (num of values in array)
*/
double sum(double values[], int r)
{

  if (r >= 0)
  {
    return (sum(values, r - 1) + values[r]);
  }
  else
    return 0;
}
/*
int sizeOfArray() - function that finds the size of an array.
paremeters:
double values[] - array of values to be counted.
*/
int sizeOfArray(double values[])
{
  int counter = 0;
  while (values[counter] != 0)
  {
    counter++;
  }
 // cout << endl << counter << " counter" << endl;
  return counter;
}

/*
double stdDevArray() - function that returns the Standard Deviation of an array recursively, uses the sumOfSqDiff function as well.
parameters: 
double values[] - array of values to get Std Deviation from.
int r - num of values in array, counter.
*/
double stdDevArray(double values[], int r)
{
    int numOfValues = sizeOfArray(values);
    double sumTemp = sumOfSqDiff(values, r); //9.33;
    if (r >= 0)
    {
        //cout << "Sumtemp: " << sumTemp << endl;
        return sqrt(sumTemp / numOfValues);
    }
    else
        return 0;

}

/*
double sumOfSqDiff() - function that uses the function sumOfSq() to calculate the sumOfSqDiff recursively.
parameters:
double values[] - array of values to find the sum Of Square Difference from.
int r - num of values in array, counter.
*/
double sumOfSqDiff(double values[], int r)
{
  double sumTemp = sumOfSq(values , r);
  double avgTemp = averageArray(values, r);
  double temp;
  if (r >= 0)
  {

    temp = sumTemp - (pow(avgTemp, 2) * r) + sumOfSq(values, r - 1);
    return temp - sumOfSq(values, r);
  }
  else
    return 0;
}

/*
double sumOfSq() - helper function to find sumOfSqDiff.
parameters:
double values[] - array of values to be summed.
int r - num of values in array, counter.
*/

double sumOfSq(double values[], int r)
{
  const double avgI = 7.85;
  double temp;
  if (r >= 0)
  {
    temp = pow(values[r], 2) + sumOfSq(values, r - 1);
    return temp;
  }
  else
    return 0;
}

/*
4. Encrypt
Write a recursive function (using substr) named encrypt that takes a string, str, to be encrypted
and a string of 26 unique characters called the key. The function should return a copy of str
encrypted using the key. Every letter in str should be replaced by the corresponding character in
the key as follows: ‘A’ and ‘a’ should be replaced with key[0], ‘B’ and ‘b’ should be replaced
with key[1], etc. Do not encrypt characters that are not letters (copy them directly to the result).
Hints:
I. ‘A’-‘A’ is 0, ‘B’-‘A’ is 1, ‘C’-‘A’ is 2, ‘D’-‘A’ is 3, etc.
II. toupper(ch) converts ch to uppercase, isalpha(ch) is true if ch is a letter.
III. encrypt(“Energy!”,"XYZABCDEFGHIJKLMNOPQRSTUVW") is BKBODV!
*/

/*
string cipher() - recursive function that shifts a message to an unreadable message using the alphabet.
parameters:
string message - message that is being encrypted
int i - letter counter.
*/
string cipher(string message, int i)
{

if (i == message.length())
{
  return "";
}

else if (message[i] >= 'A' && message[i] <= 'Z') // checks for letters A-Z
{
  return (char)((message[i] - 'A' - 3) % 26 + 'A') + cipher(message, i + 1); // shifts the message back by 3 letters.
}
else
  return message[i] + cipher(message, i + 1);
}

/*
string uppercase() - function that converts lowercase letters to uppercase letters.
parameters:
string message - message to be converted to uppercase.
*/
string uppercase(string message)
{
int i = 0;

while (i < message.length())
{
  if (message[i] >= 'a' && message[i] <= 'z') 
  {
    message[i] = message[i] - 32; // if letter is lowercase it will convert to uppercase.
  }
  i++; // counts the letters.
}
return message;
}
