#include <stdio.h>

/**
 * CHƯƠNG TRÌNH ĐƠN GIẢN: ĐỌC DỮ LIỆU TỪ FILE
 */

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * Hàm đọc sinh viên từ file
 * Trả về số lượng sinh viên đọc được
 */
int readFromFile(struct Student students[], int maxCount) {
    // Mở file
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Loi: Khong the mo file!\n");
        return -1;
    }
    
    // Đọc số lượng sinh viên
    int count;
    fscanf(file, "%d", &count);
    
    // Đọc từng sinh viên
    for (int i = 0; i < count && i < maxCount; i++) {
        fscanf(file, "%d %s %d %f",
               &students[i].id,
               students[i].name,
               &students[i].age,
               &students[i].gpa);
    }
    
    fclose(file);
    return count;
}

/**
 * Hàm tạo file mẫu (chạy 1 lần đầu)
 */
void createSampleFile() {
    FILE *file = fopen("students.txt", "w");
    
    fprintf(file, "5\n");  // Số lượng
    fprintf(file, "1 An 20 8.0\n");
    fprintf(file, "2 Binh 21 7.5\n");
    fprintf(file, "3 Chi 19 9.0\n");
    fprintf(file, "4 Dung 22 8.5\n");
    fprintf(file, "5 Em 20 7.0\n");
    
    fclose(file);
    printf("Da tao file students.txt\n\n");
}

int main() {
    printf("=================================================\n");
    printf("  DOC DU LIEU SINH VIEN TU FILE\n");
    printf("=================================================\n\n");
    
    // Tạo file mẫu (comment dòng này nếu file đã có)
    createSampleFile();
    
    // Đọc từ file
    struct Student students[100];
    int count = readFromFile(students, 100);
    
    if (count > 0) {
        // In danh sách
        printf("Danh sach doc tu file:\n");
        for (int i = 0; i < count; i++) {
            printf("%d %s %d %.1f\n",
                   students[i].id,
                   students[i].name,
                   students[i].age,
                   students[i].gpa);
        }
        printf("\nTong so: %d sinh vien\n", count);
    } else {
        printf("Khong doc duoc du lieu!\n");
    }
    
    printf("\n=================================================\n");
    
    return 0;
}

