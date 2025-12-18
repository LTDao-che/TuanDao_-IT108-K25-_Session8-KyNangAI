#include <stdio.h>

/**
 * CHƯƠNG TRÌNH ĐỐN GIẢN: SẮP XẾP SINH VIÊN THEO GPA GIẢM DẦN
 * 
 * Sử dụng Bubble Sort
 * Dễ hiểu, dễ sử dụng cho người mới học
 */

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * Hàm sắp xếp theo GPA giảm dần (cao → thấp)
 */
void sortByGPA(struct Student students[], int count) {
    // Vòng lặp ngoài: số lượt duyệt
    for (int i = 0; i < count - 1; i++) {
        // Vòng lặp trong: so sánh các cặp
        for (int j = 0; j < count - i - 1; j++) {
            // Nếu GPA bên trái < GPA bên phải → Đổi chỗ
            if (students[j].gpa < students[j+1].gpa) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

/**
 * In danh sách sinh viên
 */
void printStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d %s %d %.1f\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
}

int main() {
    // Khởi tạo danh sách sinh viên
    struct Student students[] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };
    int count = 3;
    
    printf("=================================================\n");
    printf("  SAP XEP SINH VIEN THEO GPA GIAM DAN\n");
    printf("=================================================\n");
    
    // In danh sách ban đầu
    printf("\nDanh sach ban dau:\n");
    printStudents(students, count);
    
    // Sắp xếp theo GPA
    sortByGPA(students, count);
    
    // In danh sách sau khi sắp xếp
    printf("\nDanh sach sau khi sap xep:\n");
    printStudents(students, count);
    
    printf("\n=================================================\n");
    printf("Giai thich:\n");
    printf("- GPA cao nhat (9.0) len dau\n");
    printf("- GPA trung binh (8.0) o giua\n");
    printf("- GPA thap nhat (7.5) o cuoi\n");
    printf("=================================================\n");
    
    return 0;
}

