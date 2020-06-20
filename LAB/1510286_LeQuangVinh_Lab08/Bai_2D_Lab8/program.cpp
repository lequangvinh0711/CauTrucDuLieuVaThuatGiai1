#include <iostream>
#include <fstream>

using namespace std;

#include "bstree.h"
#include "list.h"


void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}
void ChayChuongTrinh()
{
	char* filename;
	filename = new char[50];
	BSTree root;
	int kq;
	do
	{
		cout << "\nFilename : ";
		cin >> filename;
		kq = File_BST(root, filename);
	} while (!kq);
	cout << "\n\nXuat BST theo thu tu truoc:\n";
	PreOrder(root);
	cout << "\n\nXuat BST theo thu tu giua:\n";
	InOrder(root);
	cout << "\n\nXuat BST theo thu tu sau:\n";
	PosOrder(root);
	cout << "\n\nXuat BST theo chieu sau :\n";
	DFS(root);
	system("PAUSE");
	cout << "\n\nXuat BST theo chieu rong :\n";
	BFS(root);
	system("PAUSE");
	BFS_TheoMuc(root);
	system("PAUSE");
}