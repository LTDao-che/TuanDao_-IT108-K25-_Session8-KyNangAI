#include <stdio.h>

/**
 * CHƯƠNG TRÌNH ĐƠN GIẢN: TÍNH GPA TRUNG BÌNH LỚP
 */

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * Hàm tính GPA trung bình
 * Công thức: Tổng GPA / Số sinh viên
 */
float calculateAverageGPA(struct Student students[], int count) {
    // Kiểm tra danh sách rỗng
    if (count == 0) {
        printf("Danh sach rong!\n");
        return -1.0;
    }
    
    // Tính tổng GPA
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += students[i].gpa;
    }
    
    // Tính trung bình
    float average = sum / count;
    return average;
}

int main() {
    // Khởi tạo 10 sinh viên giả lập với GPA khác nhau
    struct Student students[] = {
        {1, "Nguyen Van An", 20, 8.0},
        {2, "Tran Thi Binh", 21, 7.5},
        {3, "Le Van Cuong", 19, 9.0},
        {4, "Pham Thi Dung", 22, 8.5},
        {5, "Hoang Van Em", 20, 7.0},
        {6, "Vo Thi Phuong", 21, 9.5},
        {7, "Dang Van Giang", 23, 6.5},
        {8, "Bui Thi Ha", 20, 8.8},
        {9, "Ngo Van Khanh", 22, 7.8},
        {10, "Do Thi Lan", 19, 9.2}
    };
    int count = 10;
    
    printf("=================================================\n");
    printf("  TINH GPA TRUNG BINH LOP HOC\n");
    printf("=================================================\n\n");
    
    // In danh sách sinh viên
    printf("Danh sach sinh vien (%d nguoi):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  %d. %-20s GPA: %.2f\n", 
               i + 1, students[i].name, students[i].gpa);
    }
    
    // Tính GPA trung bình
    float average = calculateAverageGPA(students, count);
    
    // In kết quả
    printf("\n=================================================\n");
    printf("  GPA trung binh cua lop la: %.2f\n", average);
    printf("=================================================\n");
    
    return 0;
}

