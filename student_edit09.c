#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

/**
 * Struct Student: Lưu trữ thông tin của một sinh viên
 * @field id: Mã số sinh viên (duy nhất)
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

// Mảng toàn cục lưu danh sách sinh viên
struct Student students[MAX_STUDENTS];
int studentCount = 0;

/**
 * addStudent: Thêm một sinh viên mới vào danh sách
 * 
 * Chức năng:
 *   - Kiểm tra danh sách đã đầy chưa (MAX_STUDENTS)
 *   - Kiểm tra ID đã tồn tại hay chưa (tránh trùng lặp)
 *   - Nếu hợp lệ, thêm sinh viên mới vào cuối mảng
 *   - Tăng biến đếm studentCount
 * 
 * @param id: Mã số sinh viên cần thêm
 * @param name: Tên sinh viên
 * @param age: Tuổi sinh viên
 * @param gpa: Điểm trung bình
 * 
 * @return: 1 nếu thêm thành công, 0 nếu thất bại
 * 
 * Test cases:
 *   - Thêm sinh viên mới (ID chưa tồn tại): Trả về 1, studentCount tăng
 *   - Thêm sinh viên trùng ID: Trả về 0, không thay đổi danh sách
 *   - Thêm khi danh sách đầy: Trả về 0, hiển thị cảnh báo
 */
int addStudent(int id, char name[], int age, float gpa) {
    // Kiểm tra danh sách đã đầy
    if (studentCount >= MAX_STUDENTS) {
        printf("❌ Loi: Danh sach da day! Khong the them sinh vien.\n");
        return 0;
    }
    
    // Kiểm tra ID đã tồn tại
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("❌ Loi: ID %d da ton tai! Khong the them sinh vien trung.\n", id);
            return 0;
        }
    }
    
    // Thêm sinh viên mới
    students[studentCount].id = id;
    strcpy(students[studentCount].name, name);
    students[studentCount].age = age;
    students[studentCount].gpa = gpa;
    studentCount++;
    
    printf("✓ Da them sinh vien: %d %s %d %.1f\n", id, name, age, gpa);
    return 1;
}

/**
 * deleteStudent: Xóa sinh viên theo ID
 * 
 * Chức năng:
 *   - Tìm sinh viên có ID cần xóa trong danh sách
 *   - Nếu tìm thấy, dịch chuyển các phần tử phía sau lên trước
 *   - Giảm biến đếm studentCount
 *   - Nếu không tìm thấy, hiển thị thông báo lỗi
 * 
 * @param id: Mã số sinh viên cần xóa
 * 
 * @return: 1 nếu xóa thành công, 0 nếu không tìm thấy ID
 * 
 * Thuật toán:
 *   1. Duyệt mảng để tìm vị trí có id trùng khớp
 *   2. Nếu tìm thấy (found != -1):
 *      - Dịch các phần tử từ vị trí found+1 đến cuối về trước 1 vị trí
 *      - Giảm studentCount
 *   3. Nếu không tìm thấy: Trả về 0
 * 
 * Test cases:
 *   - Xóa sinh viên tồn tại: Trả về 1, studentCount giảm 1
 *   - Xóa sinh viên không tồn tại: Trả về 0, danh sách không đổi
 *   - Xóa khi danh sách rỗng: Trả về 0, hiển thị cảnh báo
 */
int deleteStudent(int id) {
    // Kiểm tra danh sách rỗng
    if (studentCount == 0) {
        printf("❌ Loi: Danh sach rong! Khong co sinh vien de xoa.\n");
        return 0;
    }
    
    // Tìm vị trí sinh viên cần xóa
    int found = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    
    // Nếu không tìm thấy
    if (found == -1) {
        printf("❌ Loi: Khong tim thay sinh vien co ID %d!\n", id);
        return 0;
    }
    
    // Lưu thông tin sinh viên trước khi xóa
    printf("✓ Da xoa sinh vien: %d %s %d %.1f\n", 
           students[found].id, 
           students[found].name, 
           students[found].age, 
           students[found].gpa);
    
    // Dịch chuyển các phần tử phía sau lên
    for (int i = found; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    
    studentCount--;
    return 1;
}

/**
 * printStudents: In danh sách tất cả sinh viên
 */
void printStudents() {
    if (studentCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d %s %d %.1f\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
}

/**
 * runTestCases: Chạy các test case để kiểm tra hàm add và delete
 */
void runTestCases() {
    printf("\n");
    printf("=================================================\n");
    printf("           CHAY CAC TEST CASE\n");
    printf("=================================================\n");
    
    // Test Case 1: Thêm sinh viên bình thường
    printf("\n--- TEST 1: Them sinh vien binh thuong ---\n");
    addStudent(1, "An", 20, 8.0);
    addStudent(2, "Binh", 21, 7.5);
    addStudent(3, "Chi", 19, 9.0);
    printStudents();
    
    // Test Case 2: Thêm sinh viên trùng ID
    printf("\n--- TEST 2: Them sinh vien trung ID ---\n");
    addStudent(2, "Trung Lap", 22, 8.5);  // ID 2 đã tồn tại
    printStudents();
    
    // Test Case 3: Thêm sinh viên mới hợp lệ
    printf("\n--- TEST 3: Them sinh vien moi hop le ---\n");
    addStudent(4, "Dung", 22, 6.5);
    printStudents();
    
    // Test Case 4: Xóa sinh viên tồn tại
    printf("\n--- TEST 4: Xoa sinh vien ton tai (ID = 2) ---\n");
    deleteStudent(2);
    printStudents();
    
    // Test Case 5: Xóa sinh viên không tồn tại
    printf("\n--- TEST 5: Xoa sinh vien khong ton tai (ID = 99) ---\n");
    deleteStudent(99);
    printStudents();
    
    // Test Case 6: Xóa tiếp sinh viên khác
    printf("\n--- TEST 6: Xoa sinh vien khac (ID = 1) ---\n");
    deleteStudent(1);
    printStudents();
    
    printf("\n=================================================\n");
    printf("           KET THUC TEST CASE\n");
    printf("=================================================\n");
}

/**
 * main: Hàm chính
 */
int main() {
    printf("=================================================\n");
    printf("    CHUONG TRINH QUAN LY SINH VIEN - EDIT\n");
    printf("=================================================\n");
    
    // Chạy các test case tự động
    runTestCases();
    
    // Kết quả cuối cùng
    printf("\n\n");
    printf("=================================================\n");
    printf("           KET QUA CUOI CUNG\n");
    printf("=================================================\n");
    printStudents();
    printf("\nTong so sinh vien: %d\n", studentCount);
    
    return 0;
}

