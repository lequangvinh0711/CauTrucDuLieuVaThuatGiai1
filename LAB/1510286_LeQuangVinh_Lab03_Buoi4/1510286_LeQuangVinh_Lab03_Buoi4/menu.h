void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, Hocvien a[], int& n);

void XuatMenu()
{
	cout << "\n========= HE THONG CHUC NANG =========\n";
	cout << "\n1. Tao danh sach hoc vien.";
	cout << "\n2. Xem danh sach hoc vien.";
	cout << "\n3. Tang dan theo ma NV (chon truc tiep).";
	cout << "\n4. Tang dan theo dia chi (chen truc tiep).";
	cout << "\n5. Tang dan theo tien luong (doi cho truc tiep).";
	cout << "\n6. Giam dan theo ma NV (chen nhi phan).";
	cout << "\n7. Tang dan theo tien luong (heap sort).";
	cout << "\n8. Tang dan theo nam sinh (quick sort).";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int menu;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang >> ";
		cin >> menu;

		if (0 <= menu && menu <= somenu)
			break;
	}

	return menu;
}

void XuLyMenu(int menu, Hocvien a[], int& n)
{

	char filename[MAX];
	int kq;
	int r;
	switch (menu)
	{
	case 1:
		cout << "\n1. Doc danh sach hoc vien tu file";
		cout << "\nNhap ten file de mo >> ";
		cin >> filename;

		kq = File_Array(filename, a, n);
		if (kq != 0)
		{
			cout << "\nDanh sach hoc vien hien tai: (co " << n << " hoc vien).\n";
			Output_Arr(a, n);
		}

		break;
	case 2:
		cout << "\n2. Xuat danh sach hoc vien";
		cout << "\nDanh sach hoc vien hien tai: (co " << n << " hoc vien).\n";
		Output_Arr(a, n);
		break;
	case 3:
		cout << "\n3. Quicksort .";
		cout << "\nDanh sach hoc vien truoc khi sap xep: \n";
		Output_Arr(a, n);

		cout << "\nDanh sach hoc vien sau khi quicksort \n";
		QuickSort(a, n);
		Output_Arr(a, n);
		break;
	case 4:
		cout << "\n4. Partition.";
		cout << "\nDanh sach hoc vien truoc khi sap xep: \n";
		Output_Arr(a, n);

		cout << "\nDanh sach hoc vien sau khi phan hoạch: \n";
		/*Partition(a, n, r);*/
		Output_Arr(a, n);
		break;
	case 5:
		cout << "\n5. Heapsort.";
		cout << "\nDanh sach hoc vien truoc khi sap xep: \n";
		Output_Arr(a, n);

		cout << "\nDanh sach hoc vien sau khi Heapsort \n";
		HeapSort(a, n);
		Output_Arr(a, n);
		break;
	case 6:
		cout << "\n6. MergeSort";
		Output_Arr(a, n);
		cout << "\nDanh sach hoc vien sau khi MergeSort \n";
		MergeSort(a, n);
		Output_Arr(a, n);
		break;	case 7:
		cout << "\n7. Tang dan theo tien luong (heap sort).";
		break;
	case 0:
		cout << "\nThoat chuong trinh!\n";
		break;
	}

	system("pause");
}