#include <iostream>
#include <fstream>
#include "RBtree.h"
using namespace std;

template<class T>
void project();
int main()
{
	project<int>();
	/*RBtree<int> bst;
	bst.insert(1);
	bst.insert(2);
	bst.insert(3);
	bst.insert(4);
	bst.insert(4);
	bst.insert(4);
	bst.insert(5);
	bst.insert(5);
	bst.displayParent();*/

}

template<class T>
void project()
{
	int choice = 0;
	RBtree<T> rbt;
	while (choice != 17)
	{
		
		system("CLS");
		cout << "Press 1 to insert values in the tree\n";
		cout << "Press 2 to delete a value from the tree\n";
		cout << "Press 3 for searching a value from the tree\n";
		cout << "Press 4 for pre-order traversal NLR\n";
		cout << "Press 5 for in-order traversal LNR\n";
		cout << "Press 6 for post-order traversal LRN\n";
		cout << "Press 7 for pre-order traversal 2 NRL\n";
		cout << "Press 8 for in-order traversal 2 RNL\n";
		cout << "Press 9 for post-order traversal 2 RLN\n";
		cout << "Press 10 to destroy the tree\n";
		cout << "Press 11 to delete all values in the tree greater than X\n";
		cout << "Press 12 for displaying parent of a node present in Tree\n";
		cout << "Press 13 to read integer values from the file\n";
		cout << "Press 14 to delete all duplicate values from the tree\n";
		cout << "Press 15 to create copy of the tree\n";
		cout << "Press 16 to destroy the complete tree\n";
		cout << "Press 17 to EXIT\n";
		cout << "Enter here: ";
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			int n, temp;
			cout << "How many values you want to insert? ";
			cin >> n;
			for (int i = 0;i < n;i++)
			{
				cout << "Enter value: ";
				cin >> temp;
				rbt.insert(temp);
			}
		}
		if (choice == 2)
		{
			system("CLS");
			int n;
			cout << "Enter value that you want to delete: ";
			cin >> n;
			rbt.deletion(n);
		}
		if (choice == 3)
		{
			system("CLS");
			int n;
			cout << "Enter value that you want to search: ";
			cin >> n;
			if (rbt.search(n))
				cout << "Value exists!\n";
			else
				cout << "Value does not exist!\n";
		}
		if (choice == 4)
		{
			system("CLS");
			rbt.NLR();
		}
			
		if (choice == 5)
		{
			system("CLS");
			rbt.LNR();
		}
			
		if (choice == 6)
		{
			system("CLS");
			rbt.LRN();
		}
			
		if (choice == 7)
		{
			system("CLS");
			rbt.NRL();
		}
			
		if (choice == 8)
		{
			system("CLS");
			rbt.RNL();
		}
			
		if (choice == 9)
		{
			system("CLS");
			rbt.RLN();
		}
			
		if (choice == 10)
		{
			system("CLS");
			rbt.destroyTree();
			cout << "Tree has been destroyed!\n";
		}
			

		if (choice == 11)
		{
			system("CLS");
			int x;
			cout << "Enter value of x: ";
			cin >> x;
			rbt.DeleteX(x);
		}
		if (choice == 12)
		{
			system("CLS");
			rbt.displayParent();
		}
		if (choice == 13)
		{
			system("CLS");
			ifstream fin;
			fin.open("input.txt");
			int n;
			while (fin >> n)
			{
				rbt.insert(n);
			}
			fin.close();
			cout << "Values inserted successfully!\n";
		}
		if (choice == 14)
		{
			system("CLS");
			rbt.removeDuplicates();
			cout << "Duplicate values have been removed!\n";
		}
		if (choice == 15)
		{
			system("CLS");
			RBtree<T> copied(rbt);
			cout << "\t\t\tOriginal Tree\n";
			rbt.LNR();
			cout << "\t\t\tCopied Tree\n";
			copied.LNR();
		}
		if (choice == 16)
		{
			system("CLS");
			rbt.~RBtree();
			cout << "Tree has been destroyed!\n";
		}
			

		system("pause");
	}
}

