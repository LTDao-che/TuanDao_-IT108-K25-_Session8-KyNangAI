#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

int saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    
    if (file == NULL) {
        printf("Loi: Khong the mo file de ghi!\n");
        return 0;
    }
    
    fprintf(file, "%d\n", count);
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d|%s|%d|%.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].age, 
                students[i].gpa);
    }
    
    fclose(file);
    
    printf("\nThanh cong: Da luu %d sinh vien vao file 'students.txt'\n", count);
    return 1;
}

int main() {
    // Tạo dữ liệu test
    struct Student students[3] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };
    
    printf("=========================================\n");
    printf("   TEST HAM SAVETOFILE\n");
    printf("=========================================\n");
    
    printf("\nDu lieu test:\n");
    for (int i = 0; i < 3; i++) {
        printf("  %d: %s, %d tuoi, GPA %.1f\n", 
               students[i].id, students[i].name, 
               students[i].age, students[i].gpa);
    }
    
    printf("\n--- Bat dau luu vao file ---\n");
    int result = saveToFile(students, 3);
    
    if (result == 1) {
        printf("\n=== TEST THANH CONG ===\n");
        printf("Vui long kiem tra file students.txt\n");
    } else {
        printf("\n=== TEST THAT BAI ===\n");
    }
    
    return 0;
}

