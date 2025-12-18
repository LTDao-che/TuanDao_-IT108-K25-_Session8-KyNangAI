#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

/**
 * Struct Student: Lưu trữ thông tin sinh viên
 */
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * inputStudents: Nhập danh sách sinh viên từ bàn phím
 * Format: ID Name Age GPA (cách nhau bởi khoảng trắng)
 * 
 * @param students: Mảng lưu trữ sinh viên
 * @param count: Con trỏ tới số lượng sinh viên đã nhập
 */
void inputStudents(struct Student students[], int *count) {
    printf("Nhap thong tin toi da %d sinh vien\n", MAX_STUDENTS);
    printf("Format: ID Name Age GPA (cach nhau boi khoang trang)\n");
    printf("Vi du: 1 An 20 8.0\n");
    printf("Nhap mot dong trong de ket thuc nhap\n\n");
    
    *count = 0;
    
    while (*count < MAX_STUDENTS) {
        printf("Sinh vien %d: ", *count + 1);
        
        // Đọc ID trước
        int result = scanf("%d", &students[*count].id);
        
        // Nếu không đọc được ID, kết thúc nhập
        if (result != 1) {
            // Xóa bộ đệm nếu có lỗi
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
        
        // Đọc tên (chỉ một từ)
        scanf("%s", students[*count].name);
        
        // Đọc tuổi
        scanf("%d", &students[*count].age);
        
        // Đọc GPA
        scanf("%f", &students[*count].gpa);
        
        // Xóa ký tự newline còn lại
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        (*count)++;
    }
}

/**
 * printStudents: In danh sách sinh viên theo định dạng yêu cầu
 * 
 * @param students: Mảng sinh viên cần in
 * @param count: Số lượng sinh viên
 */
void printStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nKhong co sinh vien nao de hien thi!\n");
        return;
    }
    
    printf("\nOutput:\n\n");
    printf("%-4s %-20s %-5s %-6s\n", "ID", "Name", "Age", "GPA");
    
    for (int i = 0; i < count; i++) {
        printf("%-4d %-20s %-5d %.1f\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
}

/**
 * main: Hàm chính của chương trình
 */
int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    
    printf("=========================================\n");
    printf("   CHUONG TRINH NHAP THONG TIN SINH VIEN\n");
    printf("=========================================\n\n");
    
    // Nhập sinh viên từ bàn phím
    inputStudents(students, &studentCount);
    
    // In danh sách sinh viên
    printStudents(students, studentCount);
    
    printf("\nTong so sinh vien da nhap: %d\n", studentCount);
    
    return 0;
}

