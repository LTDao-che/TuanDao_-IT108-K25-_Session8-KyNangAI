#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 50
#define MAX_FILENAME 100

/**
 * Struct Student: Lưu trữ thông tin sinh viên
 * @field id: Mã số sinh viên
 * @field name: Tên sinh viên
 * @field age: Tuổi
 * @field gpa: Điểm trung bình (thang 10)
 */
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

/**
 * createSampleClassFiles: Tạo 3 file lớp mẫu với dữ liệu giả lập
 * 
 * Chức năng:
 *   - Tạo file classA.txt với 5 sinh viên lớp A
 *   - Tạo file classB.txt với 4 sinh viên lớp B
 *   - Tạo file classC.txt với 6 sinh viên lớp C
 * 
 * Format file: Mỗi dòng chứa: id name age gpa
 * Dòng đầu tiên: Số lượng sinh viên trong lớp
 * 
 * Return: void
 */
void createSampleClassFiles() {
    FILE *file;
    
    // ====================================================
    // BƯỚC 1: Tạo file classA.txt
    // ====================================================
    printf("Dang tao file classA.txt...\n");
    file = fopen("classA.txt", "w");
    if (file == NULL) {
        printf("Loi: Khong the tao file classA.txt!\n");
        return;
    }
    
    // Ghi số lượng sinh viên (dòng đầu tiên)
    fprintf(file, "5\n");
    
    // Ghi thông tin từng sinh viên (mỗi sinh viên 1 dòng)
    fprintf(file, "1 An 20 8.0\n");
    fprintf(file, "2 Binh 21 7.5\n");
    fprintf(file, "3 Chi 19 9.0\n");
    fprintf(file, "4 Dung 22 8.5\n");
    fprintf(file, "5 Em 20 7.0\n");
    
    fclose(file);  // Đóng file sau khi ghi xong
    printf("✓ Da tao file classA.txt thanh cong!\n\n");
    
    // ====================================================
    // BƯỚC 2: Tạo file classB.txt
    // ====================================================
    printf("Dang tao file classB.txt...\n");
    file = fopen("classB.txt", "w");
    if (file == NULL) {
        printf("Loi: Khong the tao file classB.txt!\n");
        return;
    }
    
    fprintf(file, "4\n");
    fprintf(file, "11 Phong 21 8.2\n");
    fprintf(file, "12 Giang 20 9.5\n");
    fprintf(file, "13 Ha 22 7.8\n");
    fprintf(file, "14 Khanh 19 8.8\n");
    
    fclose(file);
    printf("✓ Da tao file classB.txt thanh cong!\n\n");
    
    // ====================================================
    // BƯỚC 3: Tạo file classC.txt
    // ====================================================
    printf("Dang tao file classC.txt...\n");
    file = fopen("classC.txt", "w");
    if (file == NULL) {
        printf("Loi: Khong the tao file classC.txt!\n");
        return;
    }
    
    fprintf(file, "6\n");
    fprintf(file, "21 Lan 20 9.2\n");
    fprintf(file, "22 Mai 21 8.7\n");
    fprintf(file, "23 Nam 19 7.5\n");
    fprintf(file, "24 Oanh 22 9.0\n");
    fprintf(file, "25 Phuong 20 8.3\n");
    fprintf(file, "26 Quan 21 7.9\n");
    
    fclose(file);
    printf("✓ Da tao file classC.txt thanh cong!\n\n");
    
    printf("=================================================\n");
    printf("Da tao xong 3 file lop: classA.txt, classB.txt, classC.txt\n");
    printf("=================================================\n\n");
}

/**
 * readClassFile: Đọc dữ liệu sinh viên từ file lớp học
 * 
 * Chức năng:
 *   - Mở file với tên được chỉ định
 *   - Đọc số lượng sinh viên từ dòng đầu tiên
 *   - Đọc thông tin từng sinh viên vào mảng
 *   - Xử lý các lỗi: file không tồn tại, file rỗng, format sai
 * 
 * @param filename: Tên file cần đọc (ví dụ: "classA.txt")
 * @param students: Mảng để lưu dữ liệu sinh viên đọc được
 * @param count: Con trỏ để lưu số lượng sinh viên đọc được
 * 
 * @return: 1 nếu đọc thành công, 0 nếu thất bại
 * 
 * Các bước xử lý:
 *   1. Mở file ở chế độ đọc ("r")
 *   2. Kiểm tra file có mở được không
 *   3. Đọc số lượng sinh viên từ dòng đầu
 *   4. Duyệt vòng lặp đọc từng sinh viên
 *   5. Đóng file
 *   6. Trả về kết quả
 */
int readClassFile(char filename[], struct Student students[], int *count) {
    // ====================================================
    // BƯỚC 1: Mở file ở chế độ đọc
    // ====================================================
    printf("\n--- Bat dau doc file: %s ---\n", filename);
    FILE *file = fopen(filename, "r");
    
    // ====================================================
    // BƯỚC 2: Kiểm tra file có mở được không
    // ====================================================
    if (file == NULL) {
        printf("❌ Loi: Khong the mo file '%s'!\n", filename);
        printf("   Nguyen nhan co the:\n");
        printf("   - File khong ton tai\n");
        printf("   - Khong co quyen doc file\n");
        printf("   - Duong dan file sai\n");
        return 0;
    }
    printf("✓ Mo file thanh cong!\n");
    
    // ====================================================
    // BƯỚC 3: Đọc số lượng sinh viên từ dòng đầu tiên
    // ====================================================
    if (fscanf(file, "%d", count) != 1) {
        printf("❌ Loi: Khong doc duoc so luong sinh vien!\n");
        fclose(file);
        return 0;
    }
    printf("✓ So luong sinh vien trong lop: %d\n", *count);
    
    // Kiểm tra số lượng hợp lệ
    if (*count < 0 || *count > MAX_STUDENTS) {
        printf("❌ Loi: So luong sinh vien khong hop le (%d)\n", *count);
        fclose(file);
        return 0;
    }
    
    // ====================================================
    // BƯỚC 4: Đọc thông tin từng sinh viên
    // ====================================================
    printf("✓ Bat dau doc thong tin tung sinh vien...\n");
    for (int i = 0; i < *count; i++) {
        // Đọc 1 dòng: id name age gpa
        int result = fscanf(file, "%d %s %d %f", 
                           &students[i].id, 
                           students[i].name, 
                           &students[i].age, 
                           &students[i].gpa);
        
        // Kiểm tra đọc đủ 4 trường thông tin chưa
        if (result != 4) {
            printf("❌ Loi: Doc thong tin sinh vien thu %d that bai!\n", i + 1);
            fclose(file);
            *count = i;  // Cập nhật số sinh viên đọc được
            return 0;
        }
        
        // In thông tin sinh viên vừa đọc (debug)
        printf("   [%d] ID=%d, Name=%s, Age=%d, GPA=%.1f\n", 
               i + 1, students[i].id, students[i].name, 
               students[i].age, students[i].gpa);
    }
    
    // ====================================================
    // BƯỚC 5: Đóng file
    // ====================================================
    fclose(file);
    printf("✓ Dong file thanh cong!\n");
    printf("✓ Doc file hoan tat: %d sinh vien\n", *count);
    
    return 1;
}

/**
 * printStudents: Hiển thị danh sách sinh viên
 * 
 * @param students: Mảng sinh viên cần in
 * @param count: Số lượng sinh viên
 * @param className: Tên lớp (để hiển thị tiêu đề)
 */
void printStudents(struct Student students[], int count, char className[]) {
    printf("\n");
    printf("=================================================\n");
    printf("     DANH SACH SINH VIEN LOP %s\n", className);
    printf("=================================================\n");
    
    if (count == 0) {
        printf("Lop khong co sinh vien!\n");
        return;
    }
    
    // In header bảng
    printf("%-5s %-20s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    printf("-------------------------------------------------\n");
    
    // In từng sinh viên
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %.1f\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
    
    printf("=================================================\n");
    printf("Tong so sinh vien: %d\n", count);
    printf("=================================================\n");
}

/**
 * calculateClassStats: Tính toán thống kê của lớp
 * 
 * @param students: Mảng sinh viên
 * @param count: Số lượng sinh viên
 */
void calculateClassStats(struct Student students[], int count) {
    if (count == 0) {
        printf("\nKhong co du lieu de tinh thong ke!\n");
        return;
    }
    
    // Tính điểm trung bình của lớp
    float sumGPA = 0;
    float maxGPA = students[0].gpa;
    float minGPA = students[0].gpa;
    int maxIndex = 0, minIndex = 0;
    
    for (int i = 0; i < count; i++) {
        sumGPA += students[i].gpa;
        
        if (students[i].gpa > maxGPA) {
            maxGPA = students[i].gpa;
            maxIndex = i;
        }
        
        if (students[i].gpa < minGPA) {
            minGPA = students[i].gpa;
            minIndex = i;
        }
    }
    
    float avgGPA = sumGPA / count;
    
    printf("\n");
    printf("=================================================\n");
    printf("              THONG KE LOP HOC\n");
    printf("=================================================\n");
    printf("GPA trung binh lop: %.2f\n", avgGPA);
    printf("GPA cao nhat: %.2f (%s)\n", maxGPA, students[maxIndex].name);
    printf("GPA thap nhat: %.2f (%s)\n", minGPA, students[minIndex].name);
    printf("=================================================\n");
}

/**
 * listAvailableFiles: Liệt kê các file lớp có sẵn
 */
void listAvailableFiles() {
    printf("\n");
    printf("=================================================\n");
    printf("         CAC FILE LOP CO SAN\n");
    printf("=================================================\n");
    printf("1. classA.txt\n");
    printf("2. classB.txt\n");
    printf("3. classC.txt\n");
    printf("=================================================\n");
}

/**
 * main: Hàm chính của chương trình
 */
int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    char filename[MAX_FILENAME];
    int choice;
    
    printf("=================================================\n");
    printf("    CHUONG TRINH QUAN LY NHIEU LOP HOC\n");
    printf("=================================================\n\n");
    
    // ====================================================
    // BƯỚC 1: Tạo các file lớp mẫu
    // ====================================================
    printf("BUOC 1: Khoi tao du lieu mau\n");
    printf("-------------------------------------------------\n");
    createSampleClassFiles();
    
    // ====================================================
    // BƯỚC 2: Menu chính - Vòng lặp xử lý
    // ====================================================
    do {
        printf("\n");
        printf("=================================================\n");
        printf("                 MENU CHINH\n");
        printf("=================================================\n");
        printf("1. Doc du lieu tu file lop\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xem thong ke lop\n");
        printf("4. Liet ke cac file co san\n");
        printf("0. Thoat\n");
        printf("=================================================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();  // Xóa ký tự newline
        
        switch (choice) {
            case 1:
                // ====================================================
                // Đọc dữ liệu từ file
                // ====================================================
                printf("\n--- Chuc nang: Doc file lop ---\n");
                printf("Nhap ten file (vi du: classA.txt): ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Xóa newline
                
                // Gọi hàm đọc file
                if (readClassFile(filename, students, &studentCount)) {
                    printf("\n✓✓✓ Doc file thanh cong! ✓✓✓\n");
                    
                    // Tự động hiển thị danh sách sau khi đọc
                    char className[50];
                    // Lấy tên lớp từ tên file (bỏ .txt)
                    strncpy(className, filename, strlen(filename) - 4);
                    className[strlen(filename) - 4] = '\0';
                    printStudents(students, studentCount, className);
                } else {
                    printf("\n✗✗✗ Doc file that bai! ✗✗✗\n");
                }
                break;
                
            case 2:
                // ====================================================
                // Hiển thị danh sách
                // ====================================================
                if (studentCount == 0) {
                    printf("\nChua co du lieu! Vui long doc file truoc (chon 1).\n");
                } else {
                    printStudents(students, studentCount, "Hien Tai");
                }
                break;
                
            case 3:
                // ====================================================
                // Xem thống kê
                // ====================================================
                if (studentCount == 0) {
                    printf("\nChua co du lieu! Vui long doc file truoc (chon 1).\n");
                } else {
                    calculateClassStats(students, studentCount);
                }
                break;
                
            case 4:
                // ====================================================
                // Liệt kê các file
                // ====================================================
                listAvailableFiles();
                break;
                
            case 0:
                printf("\nCam on ban da su dung chuong trinh!\n");
                printf("Tam biet!\n");
                break;
                
            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }
        
    } while (choice != 0);
    
    return 0;
}

