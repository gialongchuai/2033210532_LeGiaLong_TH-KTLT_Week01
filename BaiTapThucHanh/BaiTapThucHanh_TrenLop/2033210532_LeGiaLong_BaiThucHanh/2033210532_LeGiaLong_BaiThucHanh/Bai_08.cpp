/*
	Bài 08: Tạo cấu trúc Phân số chứa 2 thành phần tử và mẫu số (mẫu !=0). Tạo con trỏ mảng 1 
	chiều chứa các phân số. Viết các hàm:
	a. Nhập/xuất các phần tử của mảng. Lưu ý ngoại lệ khi mẫu là 0.
	b. Xuất các phân số có mẫu>tử.
	c. Đếm số phần số có mẫu và tử chẵn.
	d. Rút gọn phân số.
	e. Tính tích các phần tử của mảng.
	f. Tìm phần tử lớn nhất.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Định nghĩa cấu trúc PhanSo
typedef struct {
	int tu;
	int mau;
} PhanSo;

// Hàm nhập phân số
void nhapPhanSo(PhanSo *ps) {
	do {
		printf("Nhap tu so: ");
		while (scanf("%d", &ps->tu) != 1) {
			while (getchar() != '\n'); // Xóa bỏ các ký tự không hợp lệ
			printf("Gia tri nhap vao khong hop le. Vui long nhap lai tu so: ");
		}
		printf("Nhap mau so: ");
		while (scanf("%d", &ps->mau) != 1 || ps->mau == 0) {
			while (getchar() != '\n'); // Xóa bỏ các ký tự không hợp lệ
			if (ps->mau == 0) {
				printf("Mau so phai khac 0. Vui long nhap lai mau so: ");
			}
			else {
				printf("Gia tri nhap vao khong hop le. Vui long nhap lai mau so: ");
			}
		}
	} while (ps->mau == 0);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
	printf("%d/%d\n", ps.tu, ps.mau);
}

// Hàm nhập mảng phân số
void nhapMangPhanSo(PhanSo *mang, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan so thu %d:\n", i + 1);
		nhapPhanSo(&mang[i]);
	}
}

// Hàm xuất mảng phân số
void xuatMangPhanSo(PhanSo *mang, int n) {
	for (int i = 0; i < n; i++) {
		xuatPhanSo(mang[i]);
	}
}

// Hàm xuất các phân số có mẫu > tử
void xuatPhanSoMauLonHonTu(PhanSo *mang, int n) {
	printf("Cac phan so co mau lon hon tu:\n");
	for (int i = 0; i < n; i++) {
		if (mang[i].mau > mang[i].tu) {
			xuatPhanSo(mang[i]);
		}
	}
}

// Hàm đếm số phân số có tử và mẫu đều chẵn
int demPhanSoTuMauChan(PhanSo *mang, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (mang[i].tu % 2 == 0 && mang[i].mau % 2 == 0) {
			count++;
		}
	}
	return count;
}

// Hàm tìm ước chung lớn nhất (UCLN)
int uocChungLonNhat(int a, int b) {
	if (b == 0) {
		return a;
	}
	return uocChungLonNhat(b, a % b);
}

// Hàm rút gọn phân số
void rutGonPhanSo(PhanSo *ps) {
	int ucln = uocChungLonNhat(abs(ps->tu), abs(ps->mau));
	ps->tu /= ucln;
	ps->mau /= ucln;
}

// Hàm tính tích các phần tử của mảng phân số
PhanSo tinhTichPhanSo(PhanSo *mang, int n) {
	PhanSo tich = { 1, 1 };
	for (int i = 0; i < n; i++) {
		tich.tu *= mang[i].tu;
		tich.mau *= mang[i].mau;
	}
	rutGonPhanSo(&tich);
	return tich;
}

// Hàm so sánh hai phân số
int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
	return ps1.tu * ps2.mau - ps2.tu * ps1.mau;
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo *mang, int n) {
	PhanSo max = mang[0];
	for (int i = 1; i < n; i++) {
		if (soSanhPhanSo(mang[i], max) > 0) {
			max = mang[i];
		}
	}
	return max;
}

int main() {
	int n;

	// Nhập số lượng phần tử của mảng
	printf("Nhap so luong phan tu cua mang: ");
	while (scanf("%d", &n) != 1 || n <= 0) {
		while (getchar() != '\n'); // Xóa bỏ các ký tự không hợp lệ
		printf("So luong phan tu phai la so nguyen duong. Vui long nhap lai: ");
	}

	// Cấp phát bộ nhớ cho mảng phân số
	PhanSo *mang = (PhanSo *)malloc(n * sizeof(PhanSo));

	// Nhập mảng phân số
	nhapMangPhanSo(mang, n);

	// Xuất mảng phân số
	printf("Mang phan so vua nhap:\n");
	xuatMangPhanSo(mang, n);

	// Xuất các phân số có mẫu > tử
	xuatPhanSoMauLonHonTu(mang, n);

	// Đếm số phân số có tử và mẫu đều chẵn
	int soPhanSoChan = demPhanSoTuMauChan(mang, n);
	printf("So phan so co tu va mau deu chan: %d\n", soPhanSoChan);

	// Rút gọn các phân số trong mảng
	for (int i = 0; i < n; i++) {
		rutGonPhanSo(&mang[i]);
	}
	printf("Mang phan so sau khi rut gon:\n");
	xuatMangPhanSo(mang, n);

	// Tính tích các phần tử của mảng
	PhanSo tich = tinhTichPhanSo(mang, n);
	printf("Tich cac phan so trong mang: ");
	xuatPhanSo(tich);

	// Tìm phân số lớn nhất
	PhanSo max = timPhanSoLonNhat(mang, n);
	printf("Phan so lon nhat trong mang: ");
	xuatPhanSo(max);

	// Giải phóng bộ nhớ đã cấp phát
	free(mang);

	system("pause");
	return 0;
}
