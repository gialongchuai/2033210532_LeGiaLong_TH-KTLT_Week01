/*
	Bài 11: Xét tiếp bài số 7. Viết các hàm sau, chú ý xử ngoại lệ (nếu có)
	a. Xuất các số cực tiểu trong a. Biết rằng số cực tiểu là số nhỏ hơn các số quanh nó.
	b. Xóa phần tử tại vị trí k
	c. Thêm phần tử x tại vị trí k
	d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng.
	e. Kiểm tra mảng có chứa chẵn lẻ xen kẻ không?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm nhập mảng 1 chiều số nguyên
void nhapMang(int *&mang, int &kichThuoc)
{
	printf("Nhap so luong phan tu cua mang: ");
	while (scanf("%d", &kichThuoc) != 1 || kichThuoc <= 0)
	{
		printf("Gia tri khong hop le. Vui long nhap lai: ");
		// Xóa bộ nhớ đệm đầu vào
		while (getchar() != '\n')
			;
	}

	mang = (int *)malloc(kichThuoc * sizeof(int)); // Cấp phát bộ nhớ cho mảng

	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < kichThuoc; i++)
	{
		printf("Phan tu thu %d: ", i);
		while (scanf("%d", mang + i) != 1)
		{
			printf("Gia tri khong hop le. Vui long nhap lai phan tu thu %d: ", i);
			// Xóa bộ nhớ đệm đầu vào
			while (getchar() != '\n')
				;
		}
	}
}

// Hàm xuất mảng 1 chiều số nguyên
void xuatMang(int *mang, int kichThuoc)
{
	printf("Cac phan tu cua mang la:\n");
	for (int i = 0; i < kichThuoc; i++)
	{
		printf("%d ", *(mang + i)); // Xuất giá trị của từng phần tử của mảng
	}
	printf("\n");
}

// a. Xuất các số cực tiểu trong mảng
void xuatSoCucTieu(int *mang, int kichThuoc)
{
	if (kichThuoc <= 0)
	{
		printf("Mang khong co phan tu.\n");
		return;
	}

	printf("Cac so cuc tieu trong mang:\n");

	for (int i = 0; i < kichThuoc; i++)
	{
		if ((i == 0 || *(mang + i) < *(mang + i - 1)) &&
			(i == kichThuoc - 1 || *(mang + i) < *(mang + i + 1)))
		{
			printf("%d ", *(mang + i));
		}
	}
	printf("\n");
}

// b. Xóa phần tử tại vị trí k
void xoaPhanTuTaiViTri(int *&mang, int &kichThuoc, int k)
{
	if (k < 0 || k >= kichThuoc)
	{
		printf("Vi tri k khong hop le.\n");
		return;
	}

	for (int i = k; i < kichThuoc - 1; i++)
	{
		*(mang + i) = *(mang + i + 1);
	}
	kichThuoc--;

	mang = (int *)realloc(mang, kichThuoc * sizeof(int)); // Cấp phát lại bộ nhớ khi xóa phần tử

	printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
	xuatMang(mang, kichThuoc);
}

// c. Thêm phần tử x tại vị trí k
void themPhanTuTaiViTri(int *&mang, int &kichThuoc, int x, int k)
{
	if (k < 0 || k > kichThuoc)
	{
		printf("Vi tri k khong hop le.\n");
		return;
	}

	kichThuoc++;
	mang = (int *)realloc(mang, kichThuoc * sizeof(int)); // Cấp phát lại bộ nhớ để chứa phần tử mới

	// Dời các phần tử về phía sau từ vị trí k
	for (int i = kichThuoc - 1; i > k; i--)
	{
		*(mang + i) = *(mang + i - 1);
	}

	*(mang + k) = x; // Thêm phần tử x vào vị trí k

	printf("Mang sau khi them phan tu %d tai vi tri %d:\n", x, k);
	xuatMang(mang, kichThuoc);
}

// d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLenDauLeXuongCuoi(int *mang, int kichThuoc)
{
	if (kichThuoc <= 0)
	{
		printf("Mang khong co phan tu.\n");
		return;
	}

	int *mangMoi = (int *)malloc(kichThuoc * sizeof(int)); // Tạo mảng mới để chứa kết quả
	int chiSo = 0;

	// Chuyển các số chẵn lên đầu mảng
	for (int i = 0; i < kichThuoc; i++)
	{
		if (*(mang + i) % 2 == 0)
		{
			*(mangMoi + chiSo) = *(mang + i);
			chiSo++;
		}
	}

	// Chuyển các số lẻ xuống cuối mảng
	for (int i = 0; i < kichThuoc; i++)
	{
		if (*(mang + i) % 2 != 0)
		{
			*(mangMoi + chiSo) = *(mang + i);
			chiSo++;
		}
	}

	// Sao chép mảng mới vào mảng cũ
	for (int i = 0; i < kichThuoc; i++)
	{
		*(mang + i) = *(mangMoi + i);
	}

	free(mangMoi); // Giải phóng bộ nhớ tạm thời

	printf("Mang sau khi chuyen so chan len dau, so le xuong cuoi:\n");
	xuatMang(mang, kichThuoc);
}

// e. Kiểm tra mảng có chứa chẵn lẻ xen kẽ không?
void kiemTraChanLeXenKe(int *mang, int kichThuoc)
{
	if (kichThuoc <= 1)
	{
		printf("Mang khong co du phan tu de kiem tra.\n");
		return;
	}

	int xenKe = 1; // Giả sử mảng là xen kẽ

	for (int i = 1; i < kichThuoc; i++)
	{
		if (*(mang + i) % 2 == *(mang + i - 1) % 2)
		{
			xenKe = 0; // Tìm thấy hai phần tử liên tiếp cùng chẵn hoặc cùng lẻ
			break;
		}
	}

	if (xenKe)
	{
		printf("Mang co chua cac phan tu chan le xen ke.\n");
	}
	else
	{
		printf("Mang khong chua cac phan tu chan le xen ke.\n");
	}
}

int main()
{
	int *mang;
	int kichThuoc;

	nhapMang(mang, kichThuoc);
	xuatMang(mang, kichThuoc);

	xuatSoCucTieu(mang, kichThuoc);
	xoaPhanTuTaiViTri(mang, kichThuoc, 2); // Ví dụ xóa phần tử tại vị trí 2
	themPhanTuTaiViTri(mang, kichThuoc, 777, 3); // Ví dụ thêm phần tử 777 tại vị trí 3
	chuyenChanLenDauLeXuongCuoi(mang, kichThuoc);
	kiemTraChanLeXenKe(mang, kichThuoc);

	free(mang);

	system("pause");
	return 0;
}
