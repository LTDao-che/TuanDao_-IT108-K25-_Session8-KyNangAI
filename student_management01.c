#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc Student
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Hàm in header của bảng
void printHeader() {
    printf("\n");
    printf("+------+-------------------------+------+------+\n");
    printf("| %-4s | %-23s | %-4s | %-4s |\n", "ID", "Name", "Age", "GPA");
    printf("+------+-------------------------+------+------+\n");
}

// Hàm in thông tin một sinh viên
void printStudent(struct Student st) {
    printf("| %-4d | %-23s | %-4d | %.2f |\n", st.id, st.name, st.age, st.gpa);
}

// Hàm in footer của bảng
void printFooter() {
    printf("+------+-------------------------+------+------+\n");
}

int main() {
    // Khởi tạo sẵn 3 sinh viên
    struct Student students[3] = {
        {1, "Nguyen Van A", 20, 3.75},
        {2, "Tran Thi B", 21, 3.90},
        {3, "Le Van C", 19, 3.50}
    };
    
    // In tiêu đề chương trình
    printf("========================================\n");
    printf("    CHUONG TRINH QUAN LY SINH VIEN     \n");
    printf("========================================\n");
    
    // In danh sách sinh viên dưới dạng bảng
    printHeader();
    for (int i = 0; i < 3; i++) {
        printStudent(students[i]);
    }
    printFooter();
    
    printf("\nTong so sinh vien: %d\n", 3);
    
    return 0;
}

