///*
//	Bài 12: Xét lại bài 8, Viết các hàm sau:
//	a. Tìm phân số lớn nhất/nhỏ nhất
//	b. Xóa phần tử tại vị trí k
//	c. Thêm phần tử x tại vị trí k
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// Định nghĩa cấu trúc PhanSo
//typedef struct {
//	int tu;
//	int mau;
//} PhanSo;
//
//// Hàm nhập phân số
//void nhapPhanSo(PhanSo *ps) {
//	do {
//		printf("Nhap tu so: ");
//		scanf("%d", &ps->tu);
//		printf("Nhap mau so: ");
//		scanf("%d", &ps->mau);
//		if (ps->mau == 0) {
//			printf("Mau so phai khac 0. Vui long nhap lai.\n");
//		}
//	} while (ps->mau == 0);
//}
//
//// Hàm xuất phân số
//void xuatPhanSo(PhanSo ps) {
//	printf("%d/%d\n", ps.tu, ps.mau);
//}
//
//// Hàm nhập mảng phân số
//void nhapMangPhanSo(PhanSo *mang, int n) {
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan so thu %d:\n", i + 1);
//		nhapPhanSo(&mang[i]);
//	}
//}
//
//// Hàm xuất mảng phân số
//void xuatMangPhanSo(PhanSo *mang, int n) {
//	for (int i = 0; i < n; i++) {
//		xuatPhanSo(mang[i]);
//	}
//}
//
//// Hàm xuất các phân số có mẫu > tử
//void xuatPhanSoMauLonHonTu(PhanSo *mang, int n) {
//	printf("Cac phan so co mau lon hon tu:\n");
//	for (int i = 0; i < n; i++) {
//		if (mang[i].mau > mang[i].tu) {
//			xuatPhanSo(mang[i]);
//		}
//	}
//}
//
//// Hàm đếm số phân số có tử và mẫu đều chẵn
//int demPhanSoTuMauChan(PhanSo *mang, int n) {
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (mang[i].tu % 2 == 0 && mang[i].mau % 2 == 0) {
//			count++;
//		}
//	}
//	return count;
//}
//
//// Hàm tìm ước chung lớn nhất (UCLN)
//int uocChungLonNhat(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	return uocChungLonNhat(b, a % b);
//}
//
//// Hàm rút gọn phân số
//void rutGonPhanSo(PhanSo *ps) {
//	int ucln = uocChungLonNhat(abs(ps->tu), abs(ps->mau));
//	ps->tu /= ucln;
//	ps->mau /= ucln;
//}
//
//// Hàm tính tích các phần tử của mảng phân số
//PhanSo tinhTichPhanSo(PhanSo *mang, int n) {
//	PhanSo tich = { 1, 1 };
//	for (int i = 0; i < n; i++) {
//		tich.tu *= mang[i].tu;
//		tich.mau *= mang[i].mau;
//	}
//	rutGonPhanSo(&tich);
//	return tich;
//}
//
//// Hàm so sánh hai phân số
//int soSanhPhanSo(PhanSo ps1, PhanSo ps2) {
//	return ps1.tu * ps2.mau - ps2.tu * ps1.mau;
//}
//
//// Hàm tìm phân số lớn nhất
//PhanSo timPhanSoLonNhat(PhanSo *mang, int n) {
//	PhanSo max = mang[0];
//	for (int i = 1; i < n; i++) {
//		if (soSanhPhanSo(mang[i], max) > 0) {
//			max = mang[i];
//		}
//	}
//	return max;
//}
//
//// Hàm tìm phân số nhỏ nhất
//PhanSo timPhanSoNhoNhat(PhanSo *mang, int n) {
//	PhanSo min = mang[0];
//	for (int i = 1; i < n; i++) {
//		if (soSanhPhanSo(mang[i], min) < 0) {
//			min = mang[i];
//		}
//	}
//	return min;
//}
//
//// Hàm xóa phần tử tại vị trí k
//void xoaPhanSoTaiViTri(PhanSo *mang, int *n, int k) {
//	if (k < 0 || k >= *n) {
//		printf("Vi tri khong hop le!\n");
//		return;
//	}
//	for (int i = k; i < *n - 1; i++) {
//		mang[i] = mang[i + 1];
//	}
//	(*n)--;
//}
//
//// Hàm thêm phân số x tại vị trí k
//void themPhanSoTaiViTri(PhanSo **mang, int *n, PhanSo x, int k) {
//	if (k < 0 || k > *n) {
//		printf("Vi tri khong hop le!\n");
//		return;
//	}
//	*mang = (PhanSo *)realloc(*mang, (*n + 1) * sizeof(PhanSo));
//	for (int i = *n; i > k; i--) {
//		(*mang)[i] = (*mang)[i - 1];
//	}
//	(*mang)[k] = x;
//	(*n)++;
//}
//
//int main() {
//	int n;
//
//	// Nhập số lượng phần tử của mảng
//	printf("Nhap so luong phan tu cua mang: ");
//	scanf("%d", &n);
//
//	// Cấp phát bộ nhớ cho mảng phân số
//	PhanSo *mang = (PhanSo *)malloc(n * sizeof(PhanSo));
//
//	// Nhập mảng phân số
//	nhapMangPhanSo(mang, n);
//
//	// Xuất mảng phân số
//	printf("Mang phan so vua nhap:\n");
//	xuatMangPhanSo(mang, n);
//
//	// Tìm phân số lớn nhất và nhỏ nhất
//	PhanSo max = timPhanSoLonNhat(mang, n);
//	PhanSo min = timPhanSoNhoNhat(mang, n);
//	printf("Phan so lon nhat trong mang: ");
//	xuatPhanSo(max);
//	printf("Phan so nho nhat trong mang: ");
//	xuatPhanSo(min);
//
//	// Xuất các phân số có mẫu > tử
//	xuatPhanSoMauLonHonTu(mang, n);
//
//	// Đếm số phân số có tử và mẫu đều chẵn
//	int soPhanSoChan = demPhanSoTuMauChan(mang, n);
//	printf("So phan so co tu va mau deu chan: %d\n", soPhanSoChan);
//
//	// Rút gọn các phân số trong mảng
//	for (int i = 0; i < n; i++) {
//		rutGonPhanSo(&mang[i]);
//	}
//	printf("Mang phan so sau khi rut gon:\n");
//	xuatMangPhanSo(mang, n);
//
//	// Tính tích các phần tử của mảng
//	PhanSo tich = tinhTichPhanSo(mang, n);
//	printf("Tich cac phan so trong mang: ");
//	xuatPhanSo(tich);
//
//	// Xóa phần tử tại vị trí k
//	int k;
//	printf("Nhap vi tri can xoa: ");
//	scanf("%d", &k);
//	xoaPhanSoTaiViTri(mang, &n, k);
//	printf("Mang phan so sau khi xoa tai vi tri %d:\n", k);
//	xuatMangPhanSo(mang, n);
//
//	// Thêm phân số x tại vị trí k
//	PhanSo x;
//	printf("Nhap phan so can them (tu/mau):\n");
//	nhapPhanSo(&x);
//	printf("Nhap vi tri can them: ");
//	scanf("%d", &k);
//	themPhanSoTaiViTri(&mang, &n, x, k);
//	printf("Mang phan so sau khi them tai vi tri %d:\n", k);
//	xuatMangPhanSo(mang, n);
//
//	// Giải phóng bộ nhớ đã cấp phát
//	free(mang);
//
//	system("pause");
//	return 0;
//}
