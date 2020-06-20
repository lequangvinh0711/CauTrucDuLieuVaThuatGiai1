void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);
void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Dua gia tri nho nhat ve dau mang";
	cout << "\n4. chen PT hien hanh vao mang con ben trai tang dan";
	cout << "\n5.  Doi cho truc tiep :Tai moi buoc dua gia tri nho nhat ve dau mang";
	cout << "\n6. Buble: Tai moi buoc dua GTNN ve dau mang";
	cout << "\n7.Chen nhi phan";
	cout << "\n8.Sap theo co so";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
//Hàm xử lý menu
void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq;
	int x;
	char filename[MAX];
	switch (menu)
	{
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		Output(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu";
		cout << "\nMang vua tao:\n";
		Output(a, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3.Dua gia tri nho nhat ve dau mang";
		
		Selection_L(a, n);
		Output(a, n);
		cout << endl;
		break;
	case 4:
		cout << "\n4. chen PT hien hanh vao mang con ben trai tang dan";
		Insertion_L(a, n);
		cout << "\nMang du lieu :\n";
		Output(a, n);
		break;
	case 5:
		cout << "\n5.  Doi cho truc tiep :Tai moi buoc dua gia tri nho nhat ve dau mang";
		cout << "\nMang du lieu ban dau:\n";
		Interchange_L(a, n);
		Output(a, n);
		
		
		cout << endl;
		break;
	case 6:
		cout << "\n6. Buble: Tai moi buoc dua GTNN ve dau mang";
		cout << "\nMang du lieu ban dau:\n";
		
		cout << endl;
		break;
	case 7:
		cout << "\n7.Chen nhi phan";
		cout << "\nMang du lieu ban dau:\n";
		Binary_Insertion(a, n);
		Output(a, n);
		cout << endl;
		break;
	case 8:
		cout << "\n8.Sap theo co so";
		cout << "\nMang du lieu ban dau:\n";

		cout << endl;
		break;
	}

}