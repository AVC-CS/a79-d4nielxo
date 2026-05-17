#ifndef MAIN_HPP
#define MAIN_HPP


// Vector intro: makeVector, insertVector, deleteVector


#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


void makeVector(vector<int> &);
void insertVector(vector<int> &, int);
int deleteVector(vector<int> &, int);
int randnum(void);
int getInput(void);
void printVector(vector<int>);


void makeVector(vector<int> &number)
{
    for (size_t i = 0; i < number.size(); i++)
        number[i] = randnum() % 20;

    sort(number.begin(), number.end());
}


void insertVector(vector<int> &number, int usernum)
{
    auto iter = number.begin();

    while (iter != number.end() && *iter <= usernum)
        iter++;

    number.insert(iter, usernum);
}


int deleteVector(vector<int> &number, int usernum)
{
    int deleted = 0;
    auto iter = find(number.begin(), number.end(), usernum);

    while (iter != number.end())
    {
        number.erase(iter);
        deleted++;
        iter = find(number.begin(), number.end(), usernum);
    }

    if (deleted == 0)
        return -1;

    return deleted;
}


int getInput(void)
{
    int num;
    cout << "Enter your input\n";
    cin >> num;
    return num;
}


int randnum(void)
{
    return rand() % 100;
}


void printVector(vector<int> number)
{
    for (auto iter = number.begin(); iter != number.end(); iter++)
        cout << setw(5) << *iter;
    cout << endl;
}


#endif