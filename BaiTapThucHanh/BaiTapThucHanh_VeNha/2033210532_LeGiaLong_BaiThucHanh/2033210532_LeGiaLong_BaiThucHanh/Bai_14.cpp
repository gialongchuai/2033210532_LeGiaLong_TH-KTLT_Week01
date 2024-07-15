/*
	Bài 14: xét lại bài 6, viết chương trình nhập họ tên, ngày sinh và giới tính của người lao động. 
	Hãy tính thời gian người lao động được nghỉ hưu dựa theo quy định của Bộ luật lao động Việt 
	Nam 2019
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void tinhThoiGianNghiHuu(int namSinh, char gioiTinh[]) {
    int tuoiNghiHuu = 0;
    int thangNghiHuu = 0;

    // Tính toán tuổi nghỉ hưu dựa trên quy định
    if (strcmp(gioiTinh, "nam") == 0) {
        if (namSinh <= 1960) {
            tuoiNghiHuu = 60;
            thangNghiHuu = 3;
        } else if (namSinh == 1961) {
            tuoiNghiHuu = 60;
            thangNghiHuu = 6;
        } else if (namSinh == 1962) {
            tuoiNghiHuu = 60;
            thangNghiHuu = 9;
        } else if (namSinh == 1963) {
            tuoiNghiHuu = 61;
            thangNghiHuu = 0;
        } else if (namSinh == 1964) {
            tuoiNghiHuu = 61;
            thangNghiHuu = 3;
        } else if (namSinh == 1965) {
            tuoiNghiHuu = 61;
            thangNghiHuu = 6;
        } else {
            tuoiNghiHuu = 62;
            thangNghiHuu = 0;
        }
    } else if (strcmp(gioiTinh, "nu") == 0) {
        if (namSinh <= 1965) {
            tuoiNghiHuu = 55;
            thangNghiHuu = 4;
        } else if (namSinh == 1966) {
            tuoiNghiHuu = 55;
            thangNghiHuu = 8;
        } else if (namSinh == 1967) {
            tuoiNghiHuu = 56;
            thangNghiHuu = 0;
        } else if (namSinh == 1968) {
            tuoiNghiHuu = 56;
            thangNghiHuu = 4;
        } else if (namSinh == 1969) {
            tuoiNghiHuu = 56;
            thangNghiHuu = 8;
        } else if (namSinh == 1970) {
            tuoiNghiHuu = 57;
            thangNghiHuu = 0;
        } else if (namSinh == 1971) {
            tuoiNghiHuu = 57;
            thangNghiHuu = 4;
        } else if (namSinh == 1972) {
            tuoiNghiHuu = 57;
            thangNghiHuu = 8;
        } else if (namSinh == 1973) {
            tuoiNghiHuu = 58;
            thangNghiHuu = 0;
        } else if (namSinh == 1974) {
            tuoiNghiHuu = 58;
            thangNghiHuu = 4;
        } else if (namSinh == 1975) {
            tuoiNghiHuu = 58;
            thangNghiHuu = 8;
        } else {
            tuoiNghiHuu = 60;
            thangNghiHuu = 0;
        }
    } else {
        printf("Loi: Ma gioi tinh khong hop le!\n");
        return;
    }

    // In ra thông tin
    printf("Thong tin nguoi dung:\n");
    printf("Nam sinh: %d\n", namSinh);
    printf("Gioi tinh: %s\n", gioiTinh);
    printf("Tuoi nghi huu du kien: %d tuoi %d thang\n", tuoiNghiHuu, thangNghiHuu);
}

int main() {
    int namSinh;
    char gioiTinh[10];

    printf("Nhap nam sinh cua nguoi dung: ");
    scanf("%d", &namSinh);

    printf("Nhap gioi tinh (nam/nu): ");
    scanf("%s", gioiTinh);

	tinhThoiGianNghiHuu(namSinh, gioiTinh);

	system("pause");
    return 0;
}
