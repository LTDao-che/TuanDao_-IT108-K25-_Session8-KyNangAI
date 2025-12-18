#include <stdio.h>

/**
 * CHƯƠNG TRÌNH ĐƠN GIẢN: TRA CỨU SINH VIÊN THEO ID
 */

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * Hàm tìm kiếm sinh viên theo ID
 * Trả về vị trí nếu tìm thấy, -1 nếu không tìm thấy
 */
int searchStudentByID(struct Student students[], int count, int searchID) {
    // Kiểm tra ID hợp lệ
    if (searchID < 0) {
        printf("Loi: ID khong hop le!\n");
        return -1;
    }
    
    // Tìm kiếm
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchID) {
            return i;  // Tìm thấy
        }
    }
    
    return -1;  // Không tìm thấy
}

int main() {
    // Danh sách sinh viên
    struct Student students[] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0},
        {4, "Dung", 22, 8.5},
        {5, "Em", 20, 7.0}
    };
    int count = 5;
    
    printf("=================================================\n");
    printf("  TRA CUU SINH VIEN\n");
    printf("=================================================\n");
    
    // Hiển thị danh sách
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("  %d. ID=%d, %s\n", i+1, students[i].id, students[i].name);
    }
    
    // Nhập ID cần tìm
    int searchID;
    printf("\nNhap ID can tim: ");
    scanf("%d", &searchID);
    
    // Tìm kiếm
    int index = searchStudentByID(students, count, searchID);
    
    // Hiển thị kết quả
    if (index != -1) {
        printf("\nKet qua tim kiem:\n");
        printf("ID: %d, Name: %s, Age: %d, GPA: %.1f\n", 
               students[index].id,
               students[index].name,
               students[index].age,
               students[index].gpa);
    } else {
        printf("\nKhong tim thay sinh vien co ID = %d\n", searchID);
    }
    
    printf("\n=================================================\n");
    
    return 0;
}

