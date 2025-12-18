#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// =====================================================
// ĐỊNH NGHĨA CẤU TRÚC STUDENT
// =====================================================
/**
 * Struct Student: Lưu trữ thông tin của một sinh viên
 * - id: Mã số sinh viên (duy nhất)
 * - name: Họ và tên sinh viên
 * - age: Tuổi của sinh viên
 * - gpa: Điểm trung bình tích lũy (thang điểm 4.0)
 */
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Biến toàn cục
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// =====================================================
// CÁC HÀM TIỆN ÍCH
// =====================================================

/**
 * clearBuffer: Xóa bộ đệm input để tránh lỗi nhập liệu
 */
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * printHeader: In header của bảng danh sách sinh viên
 */
void printHeader() {
    printf("\n+------+-------------------------+------+------+\n");
    printf("| %-4s | %-23s | %-4s | %-4s |\n", "ID", "Name", "Age", "GPA");
    printf("+------+-------------------------+------+------+\n");
}

/**
 * printStudent: In thông tin một sinh viên theo định dạng bảng
 * @param st: Sinh viên cần in
 */
void printStudent(struct Student st) {
    printf("| %-4d | %-23s | %-4d | %.2f |\n", st.id, st.name, st.age, st.gpa);
}

/**
 * printFooter: In footer của bảng
 */
void printFooter() {
    printf("+------+-------------------------+------+------+\n");
}

/**
 * printMenu: Hiển thị menu chính của chương trình
 */
void printMenu() {
    printf("\n");
    printf("===== Student Manager =====\n");
    printf("1. Nhap sinh vien\n");
    printf("2. In danh sach\n");
    printf("3. Ghi file\n");
    printf("4. Doc file\n");
    printf("5. Tim kiem\n");
    printf("6. Sap xep\n");
    printf("7. Them sinh vien\n");
    printf("8. Xoa sinh vien\n");
    printf("0. Thoat\n");
    printf("===========================\n");
    printf("Chon chuc nang: ");
}

// =====================================================
// CÁC HÀM CHỨC NĂNG CHÍNH
// =====================================================

/**
 * initSampleData: Khởi tạo 10 sinh viên mẫu để test chương trình
 * Hàm này tạo dữ liệu giả lập với các thông tin đa dạng
 */
void initSampleData() {
    struct Student samples[10] = {
        {1001, "Nguyen Van An", 20, 3.75},
        {1002, "Tran Thi Binh", 21, 3.90},
        {1003, "Le Van Cuong", 19, 3.50},
        {1004, "Pham Thi Dung", 22, 3.85},
        {1005, "Hoang Van Em", 20, 3.20},
        {1006, "Vo Thi Phuong", 21, 3.95},
        {1007, "Dang Van Giang", 23, 2.80},
        {1008, "Bui Thi Ha", 20, 3.65},
        {1009, "Ngo Van Khanh", 22, 3.40},
        {1010, "Do Thi Lan", 19, 3.88}
    };
    
    for (int i = 0; i < 10; i++) {
        students[i] = samples[i];
    }
    studentCount = 10;
    printf("Da khoi tao 10 sinh vien mau thanh cong!\n");
}

/**
 * inputStudent: Nhập thông tin một sinh viên mới từ bàn phím
 * Hàm này yêu cầu người dùng nhập đầy đủ thông tin: ID, tên, tuổi, GPA
 * Kiểm tra tránh trùng ID và giới hạn số lượng sinh viên
 */
void inputStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Danh sach da day! Khong the them sinh vien.\n");
        return;
    }
    
    struct Student newStudent;
    
    printf("\n--- Nhap thong tin sinh vien ---\n");
    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);
    clearBuffer();
    
    // Kiểm tra ID đã tồn tại chưa
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newStudent.id) {
            printf("ID da ton tai! Vui long nhap ID khac.\n");
            return;
        }
    }
    
    printf("Nhap ten: ");
    fgets(newStudent.name, 50, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Xóa ký tự newline
    
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    
    printf("Nhap GPA: ");
    scanf("%f", &newStudent.gpa);
    clearBuffer();
    
    students[studentCount] = newStudent;
    studentCount++;
    
    printf("Them sinh vien thanh cong!\n");
}

/**
 * printAllStudents: In toàn bộ danh sách sinh viên dưới dạng bảng
 * Nếu danh sách rỗng, hiển thị thông báo
 */
void printAllStudents() {
    if (studentCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    printHeader();
    for (int i = 0; i < studentCount; i++) {
        printStudent(students[i]);
    }
    printFooter();
    printf("Tong so sinh vien: %d\n", studentCount);
}

/**
 * saveToFile: Ghi danh sách sinh viên ra file
 * File sẽ lưu dạng text với định dạng: id name age gpa
 */
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    
    fprintf(file, "%d\n", studentCount);
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d|%s|%d|%.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].age, 
                students[i].gpa);
    }
    
    fclose(file);
    printf("Da luu %d sinh vien vao file 'students.txt'\n", studentCount);
}

/**
 * loadFromFile: Đọc danh sách sinh viên từ file
 * Ghi đè lên danh sách hiện tại trong bộ nhớ
 */
void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file hoac file khong ton tai!\n");
        return;
    }
    
    fscanf(file, "%d\n", &studentCount);
    
    for (int i = 0; i < studentCount; i++) {
        fscanf(file, "%d|%[^|]|%d|%f\n", 
               &students[i].id, 
               students[i].name, 
               &students[i].age, 
               &students[i].gpa);
    }
    
    fclose(file);
    printf("Da doc %d sinh vien tu file 'students.txt'\n", studentCount);
}

/**
 * searchStudent: Tìm kiếm sinh viên theo ID hoặc tên
 * Người dùng chọn cách tìm kiếm và nhập từ khóa
 */
void searchStudent() {
    if (studentCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    int choice;
    printf("\n--- Tim kiem sinh vien ---\n");
    printf("1. Tim theo ID\n");
    printf("2. Tim theo ten\n");
    printf("Chon: ");
    scanf("%d", &choice);
    clearBuffer();
    
    int found = 0;
    
    if (choice == 1) {
        int searchId;
        printf("Nhap ID can tim: ");
        scanf("%d", &searchId);
        clearBuffer();
        
        printHeader();
        for (int i = 0; i < studentCount; i++) {
            if (students[i].id == searchId) {
                printStudent(students[i]);
                found = 1;
            }
        }
        printFooter();
    } else if (choice == 2) {
        char searchName[50];
        printf("Nhap ten can tim: ");
        fgets(searchName, 50, stdin);
        searchName[strcspn(searchName, "\n")] = 0;
        
        printHeader();
        for (int i = 0; i < studentCount; i++) {
            if (strstr(students[i].name, searchName) != NULL) {
                printStudent(students[i]);
                found = 1;
            }
        }
        printFooter();
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien!\n");
    }
}

/**
 * sortStudents: Sắp xếp danh sách sinh viên
 * Cho phép sắp xếp theo ID, tên, hoặc GPA
 * Sử dụng thuật toán bubble sort
 */
void sortStudents() {
    if (studentCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    int choice;
    printf("\n--- Sap xep danh sach ---\n");
    printf("1. Sap xep theo ID\n");
    printf("2. Sap xep theo ten\n");
    printf("3. Sap xep theo GPA\n");
    printf("Chon: ");
    scanf("%d", &choice);
    clearBuffer();
    
    // Bubble sort
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            int shouldSwap = 0;
            
            if (choice == 1) {
                shouldSwap = students[j].id > students[j + 1].id;
            } else if (choice == 2) {
                shouldSwap = strcmp(students[j].name, students[j + 1].name) > 0;
            } else if (choice == 3) {
                shouldSwap = students[j].gpa < students[j + 1].gpa; // GPA giảm dần
            }
            
            if (shouldSwap) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("Da sap xep xong!\n");
    printAllStudents();
}

/**
 * addStudent: Thêm sinh viên mới vào cuối danh sách
 * Tương tự inputStudent nhưng đơn giản hơn
 */
void addStudent() {
    inputStudent(); // Sử dụng lại hàm inputStudent
}

/**
 * deleteStudent: Xóa sinh viên theo ID
 * Dịch chuyển các phần tử phía sau lên để lấp chỗ trống
 */
void deleteStudent() {
    if (studentCount == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    int deleteId;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &deleteId);
    clearBuffer();
    
    int found = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteId) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Khong tim thay sinh vien co ID %d\n", deleteId);
        return;
    }
    
    // Dịch chuyển các phần tử về phía trước
    for (int i = found; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    
    studentCount--;
    printf("Da xoa sinh vien thanh cong!\n");
}

// =====================================================
// HÀM MAIN - ĐIỂM BẮT ĐẦU CHƯƠNG TRÌNH
// =====================================================
/**
 * main: Hàm chính của chương trình
 * - Khởi tạo dữ liệu mẫu
 * - Hiển thị menu và xử lý lựa chọn của người dùng
 * - Lặp lại cho đến khi người dùng chọn thoát
 */
int main() {
    int choice;
    
    printf("============================================\n");
    printf("  CHUONG TRINH QUAN LY SINH VIEN\n");
    printf("============================================\n");
    
    // Khởi tạo 10 sinh viên mẫu
    initSampleData();
    
    // Vòng lặp menu chính
    do {
        printMenu();
        scanf("%d", &choice);
        clearBuffer();
        
        switch (choice) {
            case 1:
                inputStudent();
                break;
            case 2:
                printAllStudents();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                addStudent();
                break;
            case 8:
                deleteStudent();
                break;
            case 0:
                printf("\nTam biet! Hen gap lai.\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }
        
    } while (choice != 0);
    
    return 0;
}

