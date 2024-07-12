/*
	Bài 07. Xét bài tập 4, viết các hàm sau theo dạng thao tác trên con trỏ
	a. Tìm phần tử lớn nhất của a, xuất ra phần tử lớn nhất và địa chỉ của nó thông qua con trỏ
	mảng.
	b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất, nếu không có thì báo không 
	có phần tử chẵn/lẻ trong mảng.
	c. Xóa phần tử có giá trị 0.
	d. Thêm phần tử x vào sao phần tử đầu tiên.
	e. Tính tổng các phần tử là số chính phương.
	f. Xuất các số cực đại trong a. Biết rằng số cực đại là số lớn hơn các số quanh nó.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm nhập mảng 1 chiều số nguyên
void nhapMang(int *& mang, int & kichThuoc)
{
	printf("Nhap so luong phan tu cua mang: ");
	scanf("%d", &kichThuoc);

	mang = (int *)malloc(kichThuoc * sizeof(int)); // Cấp phát bộ nhớ cho mảng

	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < kichThuoc; i++)
	{
		printf("Phan tu thu %d: ", i);
		scanf("%d", mang + i); // Nhập giá trị cho từng phần tử của mảng
	}
}

// Hàm xuất mảng 1 chiều số nguyên
void xuatMang(int * mang, int kichThuoc)
{
	printf("Cac phan tu cua mang la:\n");
	for (int i = 0; i < kichThuoc; i++)
	{
		printf("%d ", *(mang + i)); // Xuất giá trị của từng phần tử của mảng
	}
	printf("\n");
}

// a. Tìm phần tử lớn nhất của mảng và xuất ra giá trị và địa chỉ của nó
void timPhanTuLonNhat(int * mang, int kichThuoc)
{
	if (kichThuoc <= 0)
	{
		printf("Mang khong co phan tu.\n");
		return;
	}

	int lonNhat = *mang; // Giả sử phần tử đầu tiên là lớn nhất
	int * diaChiLonNhat = mang;

	for (int i = 1; i < kichThuoc; i++)
	{
		if (*(mang + i) > lonNhat)
		{
			lonNhat = *(mang + i);
			diaChiLonNhat = mang + i;
		}
	}

	printf("Phan tu lon nhat trong mang: %d, dia chi: %p\n", lonNhat, diaChiLonNhat);
}

// b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
void timDiaChiPhanTuChanLonNhatVaLeNhoNhat(int * mang, int kichThuoc)
{
	if (kichThuoc <= 0)
	{
		printf("Mang khong co phan tu.\n");
		return;
	}

	int * diaChiChanLonNhat = NULL;
	int * diaChiLeNhoNhat = NULL;
	int timChan = 0, timLe = 0;

	for (int i = 0; i < kichThuoc; i++)
	{
		if (*(mang + i) % 2 == 0)
		{
			if (!timChan || *(mang + i) > *diaChiChanLonNhat)
			{
				diaChiChanLonNhat = mang + i;
				timChan = 1;
			}
		}
		else
		{
			if (!timLe || *(mang + i) < *diaChiLeNhoNhat)
			{
				diaChiLeNhoNhat = mang + i;
				timLe = 1;
			}
		}
	}

	if (timChan)
		printf("Dia chi cua phan tu chan lon nhat: %p, gia tri: %d\n", diaChiChanLonNhat, *diaChiChanLonNhat);
	else
		printf("Khong co phan tu chan trong mang.\n");

	if (timLe)
		printf("Dia chi cua phan tu le nho nhat: %p, gia tri: %d\n", diaChiLeNhoNhat, *diaChiLeNhoNhat);
	else
		printf("Khong co phan tu le trong mang.\n");
}

// c. Xóa phần tử có giá trị 0
void xoaPhanTuCoGiaTriBangKhong(int *& mang, int & kichThuoc)
{
	for (int i = 0; i < kichThuoc; i++)
	{
		if (*(mang + i) == 0)
		{
			for (int j = i; j < kichThuoc - 1; j++)
			{
				*(mang + j) = *(mang + j + 1);
			}
			kichThuoc--;
			i--; // Kiểm tra lại phần tử mới đổi vị trí
		}
	}

	mang = (int *)realloc(mang, kichThuoc * sizeof(int)); // Giải phóng bộ nhớ khi xóa phần tử

	printf("Mang sau khi xoa cac phan tu co gia tri bang 0:\n");
	xuatMang(mang, kichThuoc);
}

// d. Thêm phần tử x vào sau phần tử đầu tiên
void themPhanTuVaoSauPhanTuDauTien(int *& mang, int & kichThuoc, int x)
{
	kichThuoc++;
	mang = (int *)realloc(mang, kichThuoc * sizeof(int)); // Cấp phát lại bộ nhớ để chứa phần tử mới

	// Dời các phần tử về phía sau
	for (int i = kichThuoc - 1; i > 1; i--)
	{
		*(mang + i) = *(mang + i - 1);
	}

	*(mang + 1) = x; // Thêm phần tử x vào sau phần tử đầu tiên

	printf("Mang sau khi them phan tu %d vao sau phan tu dau tien:\n", x);
	xuatMang(mang, kichThuoc);
}

// e. Tính tổng các phần tử là số chính phương
int laSoChinhPhuong(int x)
{
	int canBacHai = sqrt(x * 1.0);
	return (canBacHai * canBacHai == x);
}

int tinhTongSoChinhPhuong(int * mang, int kichThuoc)
{
	int tong = 0;
	for (int i = 0; i < kichThuoc; i++)
	{
		if (laSoChinhPhuong(*(mang + i)))
		{
			tong += *(mang + i);
		}
	}
	return tong;
}

// f. Xuất các số cực đại trong mảng
void xuatSoCucDai(int * mang, int kichThuoc)
{
	if (kichThuoc <= 0)
	{
		printf("Mang khong co phan tu.\n");
		return;
	}

	printf("Cac so cuc dai trong mang:\n");

	for (int i = 1; i < kichThuoc - 1; i++)
	{
		if (*(mang + i) > *(mang + i - 1) && *(mang + i) > *(mang + i + 1))
		{
			printf("%d ", *(mang + i));
		}
	}
	printf("\n");
}

int main()
{
	int * mang;
	int kichThuoc;

	nhapMang(mang, kichThuoc);
	xuatMang(mang, kichThuoc);

	timPhanTuLonNhat(mang, kichThuoc);
	timDiaChiPhanTuChanLonNhatVaLeNhoNhat(mang, kichThuoc);
	xoaPhanTuCoGiaTriBangKhong(mang, kichThuoc);
	themPhanTuVaoSauPhanTuDauTien(mang, kichThuoc, 999); // Ví dụ như thêm x = 999
	printf("Tong cac phan tu la so chinh phuong: %d\n", tinhTongSoChinhPhuong(mang, kichThuoc));
	xuatSoCucDai(mang, kichThuoc);

	free(mang);

	system("pause");
	return 0;
}
