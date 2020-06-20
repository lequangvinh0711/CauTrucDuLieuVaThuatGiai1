//Thu vien cai dat du lieu, mcac thao tac he thong toi thieu de tao duoc du lieu, xuat du lieu
#define MAX_MENU 20

//Dinh nghia kieu du lieu cua thanh phan du lieu cua nut - kieu cau truc : hocvien
struct hocvien //data
{
	char maHV[8];
	char hoHV[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	char lop[6];
	
	double dbt1;
	double dbt2;
	double dgk;
	double dcc;
	double dqt;
};

struct  tagNODE //tagNODE
{
	hocvien info;; //thanh phan du lieu
	tagNODE* pNext;	//thanh phan moi lien ket
};

//Doi ten svNODE thanh NODE
typedef tagNODE NODE;

//DN kiieu LIST
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

//=============================================
//Khai bao nguyen mau
//Cac thao tac he thong
NODE* GetNODE(hocvien x);
void CreatLIST(LIST& l);
void InsertHead(LIST& l, hocvien x);
void  InsertTail(LIST& l, hocvien x);

//Cac thao tac nhap xuat
int Chuyen_TapTin_List(char* filename, LIST& l); //chuyen filename vao l
void TieuDe();
void Xuat_DSHV(LIST l);
void Xuat_HV(hocvien x);
// cac thao tac
int SoNut(LIST l);
int RemoveNode_First(LIST& l, hocvien x);
void XoaNamSinh_HocVien(LIST& l, hocvien x);
bool TimHV_TheoLop(LIST l, hocvien  x);
NODE* SuaTichLuy_Hocvien(LIST l);
void XuatDsHocVien_TheoLop(LIST l, hocvien  x);
//============================================
//Cai dat cac ham
//=============================================
//Cac thao tac he thong
//Ham tao nut
NODE* GetNODE(hocvien x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

//Ham tao ds rong
void CreatLIST(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

//Ham chen 1 hv vao dau ds hoc vien
void InsertHead(LIST& l, hocvien x)
{
	NODE* new_ele = GetNODE(x);
	if (new_ele == NULL)
		return;
	if (l.pHead == NULL) //DS rong  
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;  //cheen vao dau DS
		l.pHead = new_ele;
	}
}

//Ham chen 1 hv vao dau cuoi hoc vien

void  InsertTail(LIST& l, hocvien x)
{
	NODE* new_ele = GetNODE(x);
	if (new_ele == NULL)
		return;
	if (l.pHead == NULL)//ds rong
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

//Chuyen tap tin cau truc sang LIST l
//Thanh cong : tra ve 1; không thanh cong : tra ve 0
int Chuyen_TapTin_List(char* filename, LIST& l)
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}
	hocvien x;
	CreatLIST(l); //tao ds l rong

	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.namSinh;
		in >> x.lop;
		
		in >> x.dbt1;
		in >> x.dbt2;
		in >> x.dgk;
		in >> x.dcc;
		//double dqt;
		//dqt = 0.1;

		//in>>x.dqt;

		InsertTail(l, x);//chen x vao cuoi ds l
	}
	in.close();
	return 1;
}

//Xuat tieu de
void TieuDe()
{
	cout << "\n:==========================================================================================:\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "MaSV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Tenlot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(6) << "NS"
		<< ':'

		<< setw(8) << "Lop"
		<< ':'
		<< setw(6) << "BT1"
		<< ':'
		<< setw(6) << "BT2"
		<< ':'
		<< setw(6) << "GK"
		<< ':'
		<< setw(10) << "CC"
		<< ':';
	cout << "\n:===========================================================================================:";
}

//Xuat 1 s1nh vien
void Xuat_HV(hocvien x)
{

	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << x.maHV
		<< ':'
		<< setw(10) << x.hoHV
		<< setw(10) << x.tenLot
		<< setw(10) << x.ten
		<< ':'
		<< setw(6) << x.namSinh
		<< ':'
		<< setw(8) << x.lop
		<< ':'
		
		<< setw(6) << setprecision(2) << x.dbt1 << ':'
		<< setw(6) << setprecision(2) << x.dbt2 << ':'
		<< setw(6) << setprecision(2) << x.dgk << ':'
		<< setw(6) << setprecision(2) << x.dcc << ':'
		;
		//<< setw(10) << x.dbt2
		//<< ':'
		//<< setw(10) << x.dgk
		//<< ':'
		//<< setw(10) << x.dcc
		//<< ':';
}


//Xuat danh sach s1nh vien voi thong tin day du
void Xuat_DSHV(LIST l)
{
	TieuDe();
	NODE* p;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\ndanh sach rong";
		return;
	}
	while (p != NULL)
	{
		cout << '\n';
		Xuat_HV(p->info);
		p = p->pNext;
	}
	cout << "\n:=========================================================================:\n";
}

//Dem so luong nut
int SoNut(LIST l)
{
	NODE* p;
	int i = 0;
	p = l.pHead;
	while (p != NULL)
	{
		p = p->pNext;
		i++;
	}
	return i;
}
int RemoveNode_First(LIST& l, hocvien x)
{
	NODE* p = l.pHead;
	NODE* q = NULL;

	while (p != NULL)
	{
		if (p->info.namSinh == x.namSinh)
			break;
		q = p; p = p->pNext;
	}

	if (p == NULL)
		return 0;
	//xoa nut sau q : la p

	if (q != NULL)
	{
		if (p == l.pTail)	 //xoa nut cuoi
			l.pTail = q;
		q->pNext = p->pNext;
	}
	else //xoa nut dau
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
void XoaNamSinh_HocVien(LIST& l, hocvien x)
{
	while (RemoveNode_First(l, x));
}

bool TimHV_TheoLop(LIST l, hocvien  x)
{
	NODE* p;
	p = l.pHead;
	while (p != NULL) {
		if (strcmp(p->info.lop, x.lop) == 0)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}
NODE* SuaTichLuy_Hocvien(LIST l)
{
	NODE* p;
	p = l.pHead;
	while (p != NULL) {
		if ((strcmp(p->info.maHV, "DL23452") == 0))
		{
			p->info.dbt1 = 35;
			break;
		}
		p = p->pNext;
	}

	return p;
}
void XuatDsHocVien_TheoLop(LIST l, hocvien  x)
{
	NODE* p;
	if (!TimHV_TheoLop(l, x))
	{
		cout << endl << x.lop << " khong co trong danh sach, danh sach ko doi";
		return;
	}
	TieuDe();
	cout << endl;
	p = l.pHead;
	while (p != NULL)
	{
		if (strcmp(p->info.lop, x.lop) == 0)
		{
			Xuat_HV(p->info);
			cout << endl;

		}
		p = p->pNext;
	}
}


