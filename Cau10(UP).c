#include <stdio.h>
#include <string.h>
typedef struct
{
	int ngay, thang, nam;
} Date;
typedef struct
{
	char msp[10];
	int sl;
	char ten[30];
	float gia;
	Date ngaynhap;
} SanPham;
void DocFile(SanPham *cacsp, int *n);
void InThongTin(SanPham sp, int i, int LC);
void NhapThongTin(SanPham *sp);
int timKiem(SanPham *cacsp, int n);
void InThongKe(SanPham sp, int i);
void Menu(SanPham *cacsp);

int main()
{
	SanPham csp[100];
	int n = 0;
	Menu(csp);
	return 0;
}
void NhapThongTin(SanPham *sp)
{
	printf("\nNhap ma san pham: ");
	scanf("%s", sp->msp);
	fflush(stdin);
	printf("\nNhap ten san pham: ");
	scanf("%s", sp->ten);
	fflush(stdin);
	printf("\nNhap so luong san pham: ");
	scanf("%d", &sp->sl);
	fflush(stdin);
	printf("\nNhap gia cua san pham: ");
	scanf("%f", &sp->gia);
	fflush(stdin);
	printf("\nNhap ngay cap nhat cua san pham: ");
	scanf("%d %d %d", &sp->ngaynhap.ngay, &sp->ngaynhap.thang, &sp->ngaynhap.nam);
	fflush(stdin);
	printf("\n----------------------------------------------------------------");
}
void InThongTin(SanPham sp, int i, int lC)
{
	if (lC == 1)
	{
		printf("\n------------------------");
		printf("\nPhieu thong tin san pham thu %d", i + 1);
		printf("\nMa san pham: %s", sp.msp);
		printf("\nTen san pham: %s", sp.ten);
		printf("\nSo luong san pham dang co: %d", sp.sl);
		printf("\nGia cua san pham: %0.1f", sp.gia);
		printf("\nNgay san pham duoc cap nhat: %d/%d/%d", sp.ngaynhap.ngay, sp.ngaynhap.thang, sp.ngaynhap.nam);
		printf("\n------------------------");
	}
	else if (lC == 2)
	{

		printf("\n%-10s %-30s %-10d %-10.1f %d/%d/%d", sp.msp, sp.ten, sp.sl, sp.gia, sp.ngaynhap.ngay, sp.ngaynhap.thang, sp.ngaynhap.nam);
	}
}
void DocFile(SanPham *cacsp, int *n)
{
	FILE *f;
	f = fopen("San_Pham.txt", "r");
	int i = *n;
	for (; fscanf(f, "%s", cacsp[i].msp) != EOF; i++)
	{
		fscanf(f, " %d", &cacsp[i].sl);
		fscanf(f, " %[^\n]", cacsp[i].ten);
		fscanf(f, " %f", &cacsp[i].gia);
		fscanf(f, " %d %d %d", &cacsp[i].ngaynhap.ngay, &cacsp[i].ngaynhap.thang, &cacsp[i].ngaynhap.nam);
	}
	*n = i;
	fclose(f);
}
int timKiem(SanPham *cacsp, int n)
{
	char tim[50];
	int luaChon;

	while (1)
	{
		printf("\nLua chon cach thuc tim san pham:\n[1]Tim theo ma san pham.\n[2]Tim theo ten san pham.\nLua chon cua ban: ");
		scanf("%d", &luaChon);
		fflush(stdin);
		if (luaChon == 1 || luaChon == 2)
			break;
		else
			printf("\nLua chon khong hop le!!");
	}
	printf("\nNhap thong tin ban can tim: ");
	scanf("%s", &tim);
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		if (luaChon == 1)
		{
			if (strcmp(cacsp[i].msp, tim) == 0)
			{
				return i;
			}
		}
		else if (luaChon == 2)
		{
			if (strcmp(cacsp[i].ten, tim) == 0)
			{
				return i;
			}
		}
	}
	return -1;
}
void InThongKe(SanPham sp, int i)
{
	printf("\n%-30s %-10d %-10.1f %-15.1f", sp.ten, sp.sl, sp.gia, sp.gia * sp.sl);
}
void Menu(SanPham *cacsp)
{
	int soLuong = 0, n;
	while (1)
	{
		int lChon;
		printf("\n==========Lua chon chuc nang==========");
		printf("\n[1] Nhap danh sach san pham.\t[2] In danh sach.\n[3] Sap xep san pham.\t\t[4] Tim san pham.\n[5] Sua doi thong tin san pham.\t[6] Thong ke san pham.\n[7] cap nhat so luong san pham.\t[8] Ket thuc chuong trinh.");
		printf("\nLua chon: ");
		scanf("%d", &n);
		fflush(stdin);
		printf("\n----------------------------------------------------------------");
		if (n == 1)
		{
			printf("\n==========Lua chon cach thuc nhap==========");
			printf("\n[1] Nhap tu ban phim.\t[2] Nhap tu file.\nLua chon: ");
			scanf("%d", &lChon);
			fflush(stdin);
			if (lChon == 1)
			{
				printf("\n------Nhap danh sach san pham------");
				printf("\nNhap so luong san pham: ");
				scanf("%d", &soLuong);
				fflush(stdin);
				for (int i = 0; i < soLuong; i++)
				{
					printf("\nNhap thong tin san pham thu %d: ", i + 1);
					NhapThongTin(&cacsp[i]);
				}
			}
			else if (lChon == 2)
			{
				printf("\n------Da nhap danh sach san pham tu file------");
				DocFile(cacsp, &soLuong);
				printf("\nDa nhap duoc %d san pham tu file.\n", soLuong);
			}
		}
		else if (n == 2)
		{
			printf("\n------In danh sach san pham------");
			while (1)
			{
				printf("\nLua chon cach in danh sach san pham:\n[1] In theo phieu.\n[2] In theo danh sach.\nLua chon: ");
				scanf("%d", &lChon);
				fflush(stdin);
				if (lChon == 1 || lChon == 2)
					break;
				else
					printf("\nLua chon khong hop le!!");
			}
			if (lChon == 2)
			{
				printf("\n%-10s %-30s%-10s %-10s %-15s", "Ma SP", "Ten SP", "So luong", "Don gia", "Ngay cap nhat");
			}
			for (int i = 0; i < soLuong; i++)
			{
				InThongTin(cacsp[i], i, lChon);
			}
		}
		else if (n == 3)
		{
			printf("\n------Sap xep san pham------");
			while (1)
			{
				printf("\nLua chon cach sap xep:\n[1] Sap xep theo don gia.\n[2] Sap xep theo ten san pham.\n[3] Sap xep theo so luong.\nLua chon: ");
				scanf("%d", &lChon);
				fflush(stdin);
				if (lChon == 1 || lChon == 2 || lChon == 3)
					break;
				else
					printf("\nLua chon khong hop le!!");
			}
			if (lChon == 1)
			{
				SanPham dem;
				for (int i = 0; i < soLuong - 1; i++)
				{
					for (int j = i + 1; j < soLuong; j++)
					{
						if ((cacsp[i].gia) > cacsp[j].gia)
						{
							dem = cacsp[i];
							cacsp[i] = cacsp[j];
							cacsp[j] = dem;
						}
					}
				}
			}
			else if (lChon == 2)
			{
				SanPham dem;
				for (int i = 0; i < soLuong - 1; i++)
				{
					for (int j = i + 1; j < soLuong; j++)
					{
						if (strcmp(cacsp[i].ten, cacsp[j].ten) > 0)
						{
							dem = cacsp[i];
							cacsp[i] = cacsp[j];
							cacsp[j] = dem;
						}
					}
				}
			}
			else if (lChon == 3)
			{
				SanPham dem;
				for (int i = 0; i < soLuong - 1; i++)
				{
					for (int j = i + 1; j < soLuong; j++)
					{
						if ((cacsp[i].sl) > cacsp[j].sl)
						{
							dem = cacsp[i];
							cacsp[i] = cacsp[j];
							cacsp[j] = dem;
						}
					}
				}
			}
			printf("\nDa sap xep xong san pham theo lua chon cua ban!!");
		}
		else if (n == 4)
		{
			printf("\n------Tim san pham------");
			char tim[50];
			int timthay = 0;

			int kq = timKiem(cacsp, soLuong);
			if (kq != -1)
			{
				printf("\nDa tim thay san pham o vi tri thu %d trong danh sach!!", kq + 1);
			}
			else
			{
				printf("\nKhong tim thay san pham!!");
				printf("\n------------------------");
			}
		}
		else if (n == 5)
		{
			printf("\n------Sua doi thong tin------");
			int muc;
			int tim2 = timKiem(cacsp, soLuong);
			if (tim2 == -1)
			{
				printf("\nKhong tim thay san pham!!");
				printf("\n------------------------");
				continue;
			}
			while (1)
			{
				printf("\nChinh sua thong tin san pham thu %d", tim2);
				printf("\nChon muc ban can sua doi:\n[1] Ma san pham.\n[2] Ten san pham.\n[3] So luong.\n[4] Don gia.\nLua chon cua ban: ");
				scanf("%d", &muc);
				fflush(stdin);
				if (muc == 1 || muc == 2 || muc == 3 || muc == 4)
					break;
				else
					printf("\nLua chon khong hop le!!");
			}
			printf("\nThong tin sua doi ban nhap: ");
			if (muc == 1)
			{
				scanf("%s", &cacsp[tim2].msp);
			}
			else if (muc == 2)
			{
				scanf("%s", &cacsp[tim2].ten);
			}
			else if (muc == 3)
			{
				scanf("%d", &cacsp[tim2].sl);
			}
			else if (muc == 4)
			{
				scanf("%f", &cacsp[tim2].gia);
			}
		}
		else if (n == 6)
		{
			printf("\n------Thong ke san pham------");
			float tong = 0;
			printf("\nThong ke tat ca san pham: ");
			printf("\n%-30s %-10s %-10s %-15s", "Ma SP", "So luong", "Don gia", "Tong gia tien");
			for (int i = 0; i < n; i++)
			{
				InThongKe(cacsp[i], i);
				tong += cacsp[i].gia * cacsp[i].sl;
			}
			printf("\nTong gia tien tat ca san pham: %0.1f", tong);
			for (int i = 0; i < n; i++)
			{
				if ((cacsp[i].gia * cacsp[i].sl) > tong / n)
				{
					printf("\nSan pham co tong gia tien cao hon trung binh: %s", cacsp[i].ten);
				}
			}
		}
		else if (n == 7)
		{
			printf("\n------Cap nhat so luong san pham------");
			char tim3[50];
			int slCapNhat;
			int kq = timKiem(cacsp, n);
			if (kq != -1)
			{
				printf("\nTim thay san pham o vi tri thu %d", kq + 1);
				printf("\nNhap so luong san pham can them: ");
				scanf("%d", &slCapNhat);
				cacsp[kq].sl += slCapNhat;
			}
			else
			{
				printf("\nKhong tim thay san pham!!");
				printf("\nban co muon them san pham moi khong?\n[1] Co\n[2] Khong\nLua chon cua ban: ");
				int luaChon;
				scanf("%d", &luaChon);
				fflush(stdin);
				if (luaChon == 1)
				{
					if (soLuong >= 100)
					{
						printf("\nDanh sach san pham da day, khong the them san pham moi!!");
						return;
					}
					soLuong++;
					NhapThongTin(&cacsp[soLuong - 1]);
				}
				else if (luaChon == 2)
				{
					printf("\nBan da chon khong them san pham moi!!");
				}
				else
				{
					printf("\nLua chon khong hop le!!");
				}
			}
		}
		else if (n == 8)
		{
			printf("\n-----=======Ket thuc chuong trinh=======-----");
			break;
		}
		else
		{
			printf("\nLua chon khong hop le!!");
		}
	}
}