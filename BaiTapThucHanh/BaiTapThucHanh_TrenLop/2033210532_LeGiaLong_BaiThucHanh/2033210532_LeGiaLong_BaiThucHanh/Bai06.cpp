/*
	Bài 06: Viết chương trình nhập họ tên, ngày sinh và giới tính của người lao động. Hãy tính thời 
	gian người lao động được nghỉ hưu, biết rằng tuổi hưu của nam là đủ 62 tuổi, và nữ là đủ 60 
	tuổi. 
	Lưu ý: Xét năm hiện tại, nếu tuổi nhập vào không nằm trong tuổi lao động (18->60 hoặc 62
	theo đúng giới tính) và giới tính không phải nam/nữ thì phải xử lý ngoại lệ. Cụ thể:
	- Nếu tuổi không thuộc trong tuổi lao động thì “ném” lỗi mã 101
	- Nếu giới tính không phải chuỗi nam/nữ thì “ném” lỗi là chuỗi errcode.
	Ví dụ: 
	- Nguyễn Văn An, giới tính nam, sinh ngày 20/03/1990. Hiện tại (năm 2021) An đã 31 
	tuổi. Thời gian An được nghỉ hưu là tháng 03/2052.
	- Lê Thị Hoa, giới tính nữ, sinh ngày 14/12/1995. Hiện tại (năm 2021) Hoa đã 26 tuổi. 
	Thời gian Hoa được nghỉ hưu là tháng 01/2056.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void xuLyNgoaiLe(const char* errcode) {
	printf("Loi: ");
	if (strcmp(errcode, "101") == 0) {
		printf("Tuoi khong nam trong do tuoi lao dong!\n");
	}
	else {
		printf("Ma loi khong hop le!\n");
	}
}

void kiemTraTuoiVaGioiTinh(int tuoi, char gioiTinh[], int ngay, int thang, int namSinh, const char* hoTen) {
	if (!((tuoi >= 18 && tuoi <= 60) || (tuoi == 62))) {
		xuLyNgoaiLe("101");
		return;
	}

	gioiTinh[strcspn(gioiTinh, "\n")] = '\0'; // Loại bỏ ký tự '\n' nếu có

	if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
		xuLyNgoaiLe("errcode");
		return;
	}

	// Tính toán năm nghỉ hưu
	int namNghiHuu = namSinh + 60;
	if (strcmp(gioiTinh, "nu") == 0) {
		namNghiHuu = namSinh + 55;
	}

	// Hiển thị thông tin
	printf("Thong tin nguoi dung:\n");
	printf("Ho ten: %s\n", hoTen);
	printf("Gioi tinh: %s\n", gioiTinh);
	printf("Ngay sinh: %d/%02d/%d\n", ngay, thang, namSinh);
	printf("Tuoi: %d\n", tuoi);
	printf("Nam nghi huu du kien: Thang 03/%d\n", namNghiHuu);
}

int main() {
	int tuoi, ngay, thang, namSinh;
	char gioiTinh[10];
	char hoTen[50];

	printf("Nhap ho ten cua nguoi dung: ");
	fgets(hoTen, sizeof(hoTen), stdin);
	hoTen[strcspn(hoTen, "\n")] = '\0'; // Loại bỏ ký tự '\n' nếu có

	printf("Nhap ngay sinh cua nguoi dung:\n");
	printf("Nhap ngay: ");
	scanf("%d", &ngay);
	printf("Nhap thang: ");
	scanf("%d", &thang);
	printf("Nhap nam sinh: ");
	scanf("%d", &namSinh);

	printf("Nhap gioi tinh (nam/nu): ");
	scanf(" %s", gioiTinh); // Để loại bỏ dấu kết thúc dòng

	// Tính tuổi hiện tại của người dùng (năm 2021)
	time_t now;
	struct tm *localTime;
	time(&now);
	localTime = localtime(&now);
	int currentYear = localTime->tm_year + 1900;
	tuoi = currentYear - namSinh;

	kiemTraTuoiVaGioiTinh(tuoi, gioiTinh, ngay, thang, namSinh, hoTen);

	system("pause");
	return 0;
}

