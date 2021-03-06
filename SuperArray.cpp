// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include <cstring>
#include "SuperArray.h"
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	/* This is declaring a local variable, if you have data member
	 * called int* arr, the code on line ## will NOT refer to the data
	 * member, instead you created a second arr pointer, and this
	 * second pointer dies and is lost forever when the constructor ends
	 */
    lowIndex = begIndex;
    highIndex = (lowIndex + capacity) - 1;
	arr = new int[capacity];
    SuperArray::capacity = capacity;
	// Other info below
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}

/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
	stringstream ss;

	for (int i = 0; i < obj.length(); i++)
    {
        //cout << obj.arr[i] << " i " << i<<endl;
        ss << obj.arr[i] << " ";
    }
	string str = ss.str();
	size_t found;
	found = str.find_last_not_of(" ");
	if (found != string::npos)
		str.erase(found + 1);
	else
		str.clear();            // str is all whitespace

	return str;
}

/*!
 * Index operator overload
 * @param index User's index notation
 * @return Actual index notation
 */
int &SuperArray::operator[](const int index)
{
	int realIndex = index;
    if(realIndex < lowIndex)
    {
        throw "Invalid index request, too low";
    }
    if(realIndex > highIndex)
    {
        throw "Invalid index request, too high";
    }
    if(realIndex >= lowIndex && realIndex <= highIndex)
    {
        for(int x = 0; x < capacity; x++)
        {
            int temp = lowIndex;
            temp = temp + x;
            if (temp == realIndex)
            {
                realIndex = (realIndex - temp) + x;
                break;
            }

        }
    }
    return arr[realIndex];
}

/*!
 * get the low index
 * @return : the low index
 */
int SuperArray::getLowIndex() const
{
    return(lowIndex);
}

/*!
 * get the high index
 * @return : the high index
 */
int SuperArray::getHighIndex() const
{
    return(highIndex);
}

/*!
 * set the length equal to the capacity
 * @return : the length
 */
unsigned int SuperArray::length() const
{
    int length = capacity;

    return(length);
}

/*!
 * Resizing the array
 * @param begIndex : the beginning index
 * @param capacity : the capacity of the array
 */
void SuperArray::resize(const int begIndex, const unsigned int capacity)
{
    int *newArr = new int[capacity];
    int x = 0;
    for(int i = 0; i < capacity; i++)
    {
        if(i < (lowIndex - begIndex) || i > highIndex)
        {
            newArr[i] = 0;
        }
        else
        {
            newArr[i] = arr[x];
            x++;
        }
    }
    lowIndex = begIndex;
    highIndex = (lowIndex + capacity)-1;
    delete[] arr;
    arr = newArr;
    SuperArray::capacity = capacity;
    /*for(int i = 0; i < capacity; i++)
    {
        cout << arr[i] << endl;
    }*/
}
