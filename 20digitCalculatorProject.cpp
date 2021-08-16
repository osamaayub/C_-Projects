#include<iostream>
#include<fstream>
using namespace std;
int main()
{

	int array1[20], array2[20], array3[20], array4[20], array5[20],array6[20];
	int sum = 0, number1 = 0, count = 0, difference = 0, cheak = 0, count2 = 0, count3 = 0, number = 0, equal=0;
	cout << "enter first 20 words for addition and subtraction:";
	for (int i = 0; i < 20; i++)
	{
		cin >> array1[i];
	}
	cout << "enter second 20 words for addition and subtraction:";
	for (int i = 0; i < 20; i++)
	{
	    cin >> array2[i];
	}
	cout << endl;
	for (int i = 19; i >= 0; i--)
	{
		if (count == 1)
		{
			sum = array1[i] + array2[i] + sum;
			count = 0;
		}
		else if (count==0)
		{
			sum = array1[i] + array2[i];
		}	
		if (sum <= 9)
		{
			array3[i] = sum;
			count = 0;
		}
		if (i == 0)
		{
			array3[i] = sum;
		}
		else if (sum>9)
		{
			number1 = sum % 10;
			array3[i] = number1;
			sum = sum / 10;
			count = 1;
		}
	}
	cout << "result of addition :";
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		cout<<array3[i];
	}
	cout << endl;
	count = 0;
	for (int i = 19; i >= 0; i--)
	{
		difference = array1[i] - array2[i];
		if (i == 0)
		{
			if (difference < 0)
			{
				cout << "first number is les then second number:";
				cout << endl;
				count3 = 1;
				break;
			}
		}
		else if (difference < 0)
		{
			count2++;
			if (count2 == 1)
			{
				cheak = i;
			}
			i--;
			while (1)
			{
				if (array1[i] - 1>=0)
				{
					array1[i] -= 1;
					break;
				}
				else
				{
					array1[i] = 9;
					i--;
				}
			}
		}
		if (count2 > 0)
		{
			i = cheak;
			array1[i] += 10;
			difference = array1[i] - array2[i];
			count2 = 0;
			cheak = 0;
		}
		array4[i] = difference;
	}
	if (count3 == 0)
	{
		cout << "result of subtraction :";
		cout << endl;
		for (int i = 0; i < 20; i++)
		{
			cout << array4[i];
		}
		cout << endl;
	}
	cout << "enter first 17 words for multiplication:";
	for (int i = 0; i < 17; i++)
	{
		cin >> array5[i];
	}
	cout << "enter second number :";
	cin >> number;
	count = 0, count2 = 0;
	for (int i = 16; i >= 0; i--)
	{
		if (count == 1)
		{
			equal = array5[i] * number;
			equal = equal + number1;
		}
		else
		{
			equal = array5[i] * number;
		}
		if (i == 0)
		{
			array6[i] = equal;
			break;
		}
		if (equal <= 9)
		{
			array6[i] = equal;
		}
		else
		{
			number1 = equal % 10;
			array6[i] = number1;
			equal = equal / 10;
			count = 1;
			number1 = equal;
		}
	}
	cout << "result of multiplication :";
	cout << endl;
	for (int i = 0; i < 17; i++)
	{
		cout << array6[i];
	}
	cout << endl;
	return 0;
}