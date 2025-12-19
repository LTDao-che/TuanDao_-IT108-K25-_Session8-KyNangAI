#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_EMPLOYEE 100
#define MAX_RECORDS 500
	
struct Employee{
	char empId[20];
	char name[50];
	char position[15];
	double baseSalary;
	int workDay;
};

struct TimeSheet{
	char logId[20];
	char empId[20];
	char date[20];
	char status[10];
};

struct Employee employeeList[MAX_EMPLOYEE];
int employeeCount = 6;

struct TimeSheet timeSheetList[MAX_RECORDS];
int timeSheetCount = 1;
int nextLogId = 2;

void addNewEmployee(struct Employee list[],int *empCount);
void updateEmployee();
void EMS();
void displayEmployee();
void searchEmpolyeeByName();
void sortChoiceEmployeeListByBaseSalary();
void timeKeeping();
void viewPersonalTimeSheet();

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateToInt(char *dateStr) {
    int day, month, year;
    
    if (sscanf(dateStr, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0;
	}
    return year * 10000 + month * 100 + day;
}

int main(){
	{
    strcpy(employeeList[0].empId, "NV001");
	strcpy(employeeList[0].name, "Nguyen Van A");
	strcpy(employeeList[0].position, "Manager");
	employeeList[0].baseSalary = 25000000.0;
	employeeList[0].workDay = 22;

    strcpy(employeeList[1].empId, "NV002");
	strcpy(employeeList[1].name, "Tran Thi B");
	strcpy(employeeList[1].position, "Staff");
	employeeList[1].baseSalary = 8000000.0;
	employeeList[1].workDay = 15;

	strcpy(employeeList[2].empId, "NV003");
	strcpy(employeeList[2].name, "Le Hoang P");
	strcpy(employeeList[2].position, "Developer");
	employeeList[2].baseSalary = 15000000.0;
	employeeList[2].workDay = 25;

	strcpy(employeeList[3].empId, "NV004");
	strcpy(employeeList[3].name, "Nguyen Thanh Van");
	strcpy(employeeList[3].position, "Team Lead");
	employeeList[3].baseSalary = 18000000.0;
	employeeList[3].workDay = 20;

	strcpy(employeeList[4].empId, "NV005");
	strcpy(employeeList[4].name, "Pham Thi D");
	strcpy(employeeList[4].position, "Intern");
	employeeList[4].baseSalary = 4000000.0;
	employeeList[4].workDay = 21;
	
	strcpy(employeeList[5].empId, "NV006");
	strcpy(employeeList[5].name, "Duong Viet E");
	strcpy(employeeList[5].position, "Staff");
	employeeList[5].baseSalary = 9500000.0;
	employeeList[5].workDay = 22;
	
	strcpy(employeeList[6].empId, "NV007");
	strcpy(employeeList[6].name, "Hoang My Chi");
	strcpy(employeeList[6].position, "Analyst");
	employeeList[6].baseSalary = 12500000.0;
	employeeList[6].workDay = 18;

	strcpy(employeeList[7].empId, "NV008");
	strcpy(employeeList[7].name, "Bui Duc Tri");
	strcpy(employeeList[7].position, "Developer");
	employeeList[7].baseSalary = 16000000.0;
	employeeList[7].workDay = 24;

	strcpy(employeeList[8].empId, "NV009");
	strcpy(employeeList[8].name, "Phan Gia Linh");
	strcpy(employeeList[8].position, "HR");
	employeeList[8].baseSalary = 11000000.0;
	employeeList[8].workDay = 10;

	strcpy(employeeList[9].empId, "NV010");
	strcpy(employeeList[9].name, "Cao Minh Khoa");
	strcpy(employeeList[9].position, "Intern");
	employeeList[9].baseSalary = 3500000.0;
	employeeList[9].workDay = 26;

	strcpy(employeeList[10].empId, "NV011");
	strcpy(employeeList[10].name, "Doan Thi Thu");
	strcpy(employeeList[10].position, "Accountant");
	employeeList[10].baseSalary = 10200000.0;
	employeeList[10].workDay = 23;

	strcpy(employeeList[11].empId, "NV012");
	strcpy(employeeList[11].name, "Vo Thanh Hai");
	strcpy(employeeList[11].position, "Tester");
	employeeList[11].baseSalary = 14500000.0;
	employeeList[11].workDay = 19;

	strcpy(employeeList[12].empId, "NV013");
	strcpy(employeeList[12].name, "Ly Nhat Minh");
	strcpy(employeeList[12].position, "Team Lead");
	employeeList[12].baseSalary = 20500000.0;
	employeeList[12].workDay = 22;

	strcpy(employeeList[13].empId, "NV014");
	strcpy(employeeList[13].name, "Trinh Quang");
	strcpy(employeeList[13].position, "Staff");
	employeeList[13].baseSalary = 7500000.0;
	employeeList[13].workDay = 18;

	strcpy(employeeList[14].empId, "NV015");
	strcpy(employeeList[14].name, "Vu Cat Tuong");
	strcpy(employeeList[14].position, "Manager");
	employeeList[14].baseSalary = 32000000.0;
	employeeList[14].workDay = 25;

    strcpy(employeeList[15].empId, "NV016");
    strcpy(employeeList[15].name, "Mai Anh Dung");
    strcpy(employeeList[15].position, "Intern");
    employeeList[15].baseSalary = 4200000.0;
    employeeList[15].workDay = 17;

	employeeCount = 16;
    
    strcpy(timeSheetList[0].logId, "LOG001");
	strcpy(timeSheetList[0].empId, "NV001");
	strcpy(timeSheetList[0].date, "01/12/2025");
	strcpy(timeSheetList[0].status, "Di Lam");
    
    strcpy(timeSheetList[1].logId, "LOG002");
    strcpy(timeSheetList[1].empId, "NV001");
    strcpy(timeSheetList[1].date, "02/12/2025");
    strcpy(timeSheetList[1].status, "Di Lam");

    strcpy(timeSheetList[2].logId, "LOG003");
    strcpy(timeSheetList[2].empId, "NV003");
    strcpy(timeSheetList[2].date, "01/12/2020");
    strcpy(timeSheetList[2].status, "Di Lam");
    
    strcpy(timeSheetList[3].logId, "LOG004");
	strcpy(timeSheetList[3].empId, "NV004");
    strcpy(timeSheetList[3].date, "15/11/2025");
	strcpy(timeSheetList[3].status, "Di Lam");

    strcpy(timeSheetList[4].logId, "LOG005");
	strcpy(timeSheetList[4].empId, "NV005");
    strcpy(timeSheetList[4].date, "01/01/2024");
	strcpy(timeSheetList[4].status, "Di Lam");

    strcpy(timeSheetList[5].logId, "LOG006"); 
	strcpy(timeSheetList[5].empId, "NV005");
    strcpy(timeSheetList[5].date, "02/01/2024"); 
	strcpy(timeSheetList[5].status, "Di Lam");

    strcpy(timeSheetList[6].logId, "LOG007"); 
	strcpy(timeSheetList[6].empId, "NV007");
    strcpy(timeSheetList[6].date, "10/12/2025"); 
	strcpy(timeSheetList[6].status, "Di Lam");

    strcpy(timeSheetList[7].logId, "LOG008"); 
	strcpy(timeSheetList[7].empId, "NV008");
    strcpy(timeSheetList[7].date, "05/11/2025"); 
	strcpy(timeSheetList[7].status, "Di Lam");

    strcpy(timeSheetList[8].logId, "LOG009"); 
	strcpy(timeSheetList[8].empId, "NV008");
    strcpy(timeSheetList[8].date, "06/11/2025"); 
	strcpy(timeSheetList[8].status, "Di Lam");

    strcpy(timeSheetList[9].logId, "LOG010"); 
	strcpy(timeSheetList[9].empId, "NV008");
    strcpy(timeSheetList[9].date, "07/11/2025"); 
	strcpy(timeSheetList[9].status, "Di Lam");

    strcpy(timeSheetList[10].logId, "LOG011"); 
	strcpy(timeSheetList[10].empId, "NV010");
    strcpy(timeSheetList[10].date, "01/03/2024"); 
	strcpy(timeSheetList[10].status, "Di Lam");

    strcpy(timeSheetList[11].logId, "LOG012"); 
	strcpy(timeSheetList[11].empId, "NV011");
    strcpy(timeSheetList[11].date, "20/12/2025"); 
	strcpy(timeSheetList[11].status, "Di Lam");
    
    strcpy(timeSheetList[12].logId, "LOG013"); 
	strcpy(timeSheetList[12].empId, "NV012");
    strcpy(timeSheetList[12].date, "10/12/2024"); 
	strcpy(timeSheetList[12].status, "Di Lam");
    
    strcpy(timeSheetList[13].logId, "LOG014"); 
	strcpy(timeSheetList[13].empId, "NV012");
    strcpy(timeSheetList[13].date, "11/12/2024"); 
	strcpy(timeSheetList[13].status, "Di Lam");

    strcpy(timeSheetList[14].logId, "LOG015"); 
	strcpy(timeSheetList[14].empId, "NV012");
    strcpy(timeSheetList[14].date, "12/12/2024"); 
	strcpy(timeSheetList[14].status, "Di Lam");
    
    strcpy(timeSheetList[15].logId, "LOG016"); 
	strcpy(timeSheetList[15].empId, "NV013");
    strcpy(timeSheetList[15].date, "05/12/2025"); 
	strcpy(timeSheetList[15].status, "Di Lam");

    strcpy(timeSheetList[16].logId, "LOG017"); 
	strcpy(timeSheetList[16].empId, "NV013");
    strcpy(timeSheetList[16].date, "06/12/2025"); 
	strcpy(timeSheetList[16].status, "Di Lam");
    
    strcpy(timeSheetList[17].logId, "LOG018"); 
	strcpy(timeSheetList[17].empId, "NV015");
    strcpy(timeSheetList[17].date, "01/01/2023"); 
	strcpy(timeSheetList[17].status, "Di Lam");
    
    strcpy(timeSheetList[18].logId, "LOG019"); 
	strcpy(timeSheetList[18].empId, "NV015");
    strcpy(timeSheetList[18].date, "02/01/2023"); 
	strcpy(timeSheetList[18].status, "Di Lam");
    
    strcpy(timeSheetList[19].logId, "LOG020"); 
	strcpy(timeSheetList[19].empId, "NV016");
    strcpy(timeSheetList[19].date, "25/11/2025"); 
	strcpy(timeSheetList[19].status, "Di Lam");
	
	timeSheetCount = 20;
	nextLogId = 21;
}
	
	int choice;
	char inputBuffer[10];
	do{
	
		printf("\n==================== MENU QUAN LY NHAN VIEN ====================\n");
    	printf("1. Them nhan vien moi.\n");
    	printf("2. Cap nhat ho so nhan vien.\n");
    	printf("3. Quan ly nhan su(Sa thai nhan vien).\n");
    	printf("4. Hien thi danh sach.\n");
    	printf("5. Tra cuu(Tim kiem).\n");
    	printf("6. Sap xep danh sach.\n");
    	printf("7. Cham cong.\n");
    	printf("8. Xem bang cong.\n");
    	printf("9. Thoat\n");
    	printf("==================================================================\n");
    	printf("Nhap lua chon cua ban: ");
    	if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
    	choice =0;
    	continue;
		}
		inputBuffer[strcspn(inputBuffer, "\n")] = 0;
		int valid = 1;
		if(strlen(inputBuffer)==0){
		valid = 0;
		}else{
			for (int i = 0; inputBuffer[i] != '\0'; i++){
				if (i == 0 && inputBuffer[i] == '-'){
					continue;
				}
				if(inputBuffer[i] == '.'){
					continue;
            		}
            	if (!isdigit((unsigned char)inputBuffer[i])){
    			valid = 0;
				}	
			}
		}
		if(valid){
    		choice = atoi(inputBuffer);
		}else{
			choice = 0;
		}
    	if (choice < 1 || choice > 9) {
    	printf("LOI: Lua chon khong hop le. Vui long nhap so tu 1 den 9.\n");
    	choice = 0;
		}
    	switch(choice){
    		case 1:{
    			addNewEmployee(employeeList,&employeeCount);
			break;
		}
    	case 2:{
    		updateEmployee();
			break;
		}
		case 3:{
			EMS();
			break;
		}
		case 4:{
			displayEmployee();
			break;
		}
		case 5:{
			searchEmpolyeeByName();
			break;
		}
		case 6:{
			sortChoiceEmployeeListByBaseSalary();
			break;
		}
		case 7:{
			timeKeeping();
			break;
		}
		case 8:{
			viewPersonalTimeSheet();
			break;
		}
		case 9:{
			printf("Thoat chuong trinh.\n");
			break;
		}
		default:
			printf("Lua chon khong hop le.Vui long nhap so tu 1 den 9\n");
		}
    	
    	
	}while(choice != 9);
	return 0;
}




//F01
	void addNewEmployee(struct Employee list[],int *empCount){
		struct Employee newEmployee;
		char tempId[20];
		int Valid =0;
		
		if(*empCount >= MAX_EMPLOYEE){
        printf("Danh sach nhan vien da day. Khong the them moi.\n");
        return;
    }
		printf("Nhap thong tin cua nhan vien thu %d.\n", *empCount +  1);
	do{
		
		printf("Nhap ID nhan vien: ");
		fgets(tempId,sizeof(tempId), stdin);
		tempId[strcspn(tempId, "\n")] = 0;
		
		int Duplicate = 0;
		for(int i = 0; i< *empCount;i++){
			if(strcmp(list[i].empId,tempId)==0){
				Duplicate = 1;
				break;
			}
		}
		if(strlen(tempId)==0){
			printf("Khong duoc nhap rong ID nhan vien\n");
		}else if(Duplicate){
			printf("ID nhan vien da ton tai\n");
		}else{
			strcpy(newEmployee.empId, tempId);
			Valid = 1;
		}
	}while(!Valid);
		Valid =0;
	do{
		printf("Nhap ten nhan vien: ");
		fgets(newEmployee.name,sizeof(newEmployee.name),stdin);
		newEmployee.name[strcspn(newEmployee.name,"\n")] = 0;
		if(strlen(newEmployee.name)==0){
			printf("Khong duoc nhap rong ten nhan vien\n");
		}else{
			Valid =1;
		}
	}while(!Valid);
	Valid =0;
	do{
		printf("Nhap chuc vu nhan vien: ");
		fgets(newEmployee.position,sizeof(newEmployee.position),stdin);
		newEmployee.position[strcspn(newEmployee.position,"\n")] = 0;
		if(strlen(newEmployee.position)==0){
			printf("Khong duoc nhap rong chuc vu nhan vien\n");
		}else{
			Valid =1;
		}
	}while(!Valid);
		Valid = 0;
		char inputBuffer[50];
	do{
		printf("Nhap luong co ban: ");
		if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            printf("Loi doc input.\n");
            Valid = 0;
            continue;
        }
        inputBuffer[strcspn(inputBuffer, "\n")] = 0;
        
		double tempSalary = 0.0;
        
        if (!isdigit(inputBuffer[0]) && inputBuffer[0] != '-') {
            tempSalary = -1.0; 
        } else {
            tempSalary = atof(inputBuffer);
        }

        if (tempSalary <= 0.0) {
            printf("LOI: Luong co ban khong hop le (phai la so duong hoac bang 0).\n");
            Valid = 0;
        } else {
            newEmployee.baseSalary = tempSalary;
            Valid = 1;
        }
	}while(!Valid);		
		newEmployee.workDay = 0;
		list[*empCount] = newEmployee;
    	(*empCount)++;
    	printf("Them nhan vien thanh cong\n");
	}



//F02
void updateEmployee(){
	char tempId[20];
	int Valid = 0;
	int index = -1;
	int Update =0;
	printf("Nhap Ma nhan vien can cap nhat: ");
	
	do{
	fgets(tempId, sizeof(tempId), stdin);
	tempId[strcspn(tempId, "\n")] = 0;
	if (strlen(tempId) == 0){
		printf("Khong duoc nhap rong ID nhan vien\n");
	}else{
		Valid = 1;
	}
}while(!Valid);
	
	for (int i = 0; i < employeeCount; i++){
        if (strcmp(employeeList[i].empId, tempId) == 0){
        	index = i;
        	break;
        }
    }
    
	if (index == -1) {
        printf("Khong tim thay nhan vien co ma %s.\n", tempId);
        return;
    }
    
    struct Employee *emp = &employeeList[index];
    double newSalary;
    char temp[50];
    
    
    Valid = 0;
	do{
	printf("Nhap chuc vu moi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = 0;
    if (strlen(temp) > 0){
    	strcpy((*emp).position,temp);
    	Update = 1;
    	Valid =1;
	}else{
		printf("Khong duoc nhap rong chuc vu nhan vien\n");
	}
	}while (!Valid);
    
	Valid = 0;
	char salaryInput[50];
	do{
	printf("Nhap luong co ban moi: ");
    if (fgets(salaryInput, sizeof(salaryInput), stdin) == NULL) {
			Valid = 0;
			continue;
	}
	salaryInput[strcspn(salaryInput, "\n")] = 0;
	int is_valid = 1;
	char *endPtr;
	newSalary = strtod(salaryInput, &endPtr);
	if (strlen(salaryInput) == 0 || *endPtr != '\0') {
			is_valid = 0;
		}
		if (is_valid && newSalary <= 0.0) {
			is_valid = 0;
		}
	if (is_valid) {
			(*emp).baseSalary = newSalary;
			Update = 1;
			Valid = 1;
		}else{
		printf("Loi nhap luong co ban nhan vien nhan vien\n");
		Valid = 0;
	}
	}while (!Valid);
    	if (Update) {
        printf("Cap nhat ho so nhan vien thanh cong.\n");
    }
	
}


//F03
void EMS(){
	char tempId[20];
	int Valid = 0;
	int index = -1;
	int deleted = 0;
	char choice[10];
	printf("Nhap Ma nhan vien can xoa: ");
	do{
	fgets(tempId, sizeof(tempId), stdin);
	tempId[strcspn(tempId, "\n")] = 0;
	if (strlen(tempId) == 0){
		printf("Khong duoc nhap rong ID nhan vien\n");
	}else{
		Valid = 1;
	}
	}while(!Valid);
	
	for (int i = 0; i < employeeCount; i++){
        if (strcmp(employeeList[i].empId, tempId) == 0){
        	index = i;
        	break;
        }
    }
    
	if (index == -1) {
        printf("Khong tim thay nhan vien co ma %s.\n", tempId);
        return;
    }
    for(int i = 0;i<timeSheetCount;i++){
    	if(strcmp(timeSheetList[i].empId,tempId) == 0){
    		printf("Nhan vien nay da duoc cham cong khong the xoa");
    		return;	
		}	
	}
    
    
    printf("Xac nhan xa thai nhan vien [Y/N]");
    fgets(choice, sizeof(choice), stdin);
	choice[strcspn(choice, "\n")] = 0;
	if(choice[0] == 'y' || choice[0] == 'Y'){
	for(int i =index;i<employeeCount-1;i++){
    	employeeList[i] = employeeList[i+1];
	}
	employeeCount--;
	printf("Xoa nhan vien ma [%s] thanh cong.\n", tempId);
}else if(choice[0] == 'n' || choice[0] == 'N'){
	printf("Huy bo thao tac sa thai.\n");
}else {
        printf("Lua chon khong hop le. Huy bo thao tac sa thai.\n");  
}
}
	

//F04	
void displayEmployee(){
	int pageSize =5;
	int totalPages = (employeeCount + pageSize - 1) / pageSize;
	int currentPage = 1;
	int startIndex;
    int endIndex;
    int valid = 1;
	int choice;
    char choice_char[10];
    
	if (employeeCount == 0) {
        printf("Danh sach nhan vien hien dang trong\n");
		return;  
	}
	while(1){
	startIndex = (currentPage - 1) * pageSize;
    endIndex = startIndex + pageSize;

	if (endIndex > employeeCount) {
        endIndex = employeeCount;
    }
		printf("\n==================================================================\n");
        printf("= DANH SACH NHAN VIEN (Trang %d/%d) =\n", currentPage, totalPages);
        printf("==================================================================\n");
		printf("---------------------------------------------------------------------------------------------------\n");
        printf("| %-4s | %-15s | %-25s | %-12s | %-12s | %-12s |\n", 
               "STT", "Ma NV", "Ten", "Chuc vu", "Luong co ban", "So ngay Cong");
        printf("---------------------------------------------------------------------------------------------------\n");
        
        for (int i = startIndex; i < endIndex; i++) {
            printf("| %-4d | %-15s | %-25s | %-12s | %-12.2lf | %-12d |\n", i + 1, employeeList[i].empId, employeeList[i].name, employeeList[i].position, employeeList[i].baseSalary, employeeList[i].workDay);
        }
        printf("---------------------------------------------------------------------------------------------------\n");		
		printf("\n=== THAO TAC PHAN TRANG (Trang %d/%d) ===\n", currentPage, totalPages);
        printf("1. Trang tiep theo (>)\n");
        printf("2. Trang truoc (<)\n");
        printf("3. Nhap so trang cu the\n");
        printf("0. Quay lai Menu chinh\n");
        printf("Nhap lua chon cua ban: ");
        
		if (fgets(choice_char, sizeof(choice_char), stdin) == NULL) {
            choice = 0; 
    		continue;
        }
        choice_char[strcspn(choice_char, "\n")] = 0;
        if (strlen(choice_char) == 0) {
    	valid = 0; 
		}else{
			for (int i = 0; choice_char[i] != '\0'; i++){
				if (!isdigit((unsigned char)choice_char[i])) { 
            	valid = 0;
            	break; 
        		}	
			}
		}
		if(valid){
			choice = atoi(choice_char);
		}else{
			choice = 0;
		}
		
		switch (choice) {
            case 0:
                printf("Quay lai Menu chinh.\n");
                return; 
            
            case 1: 
                if (currentPage < totalPages) {
                    currentPage++;
                } else {
                    printf("LOI: Ban dang o trang cuoi cung.\n");
                }
                break;
                
            case 2:
                if (currentPage > 1) {
                    currentPage--;
                } else {
                    printf("LOI: Ban dang o trang dau tien.\n");
                }
                break;
                
            case 3: {
                int targetPage;
                char pageInput[10];
    			int valid = 1;
                printf("Nhap so trang muon xem (1 - %d): ", totalPages);
                
                if (fgets(pageInput, sizeof(pageInput), stdin) == NULL) {
        		break;
    			}
                pageInput[strcspn(pageInput, "\n")] = 0;
                
                if (strlen(pageInput) == 0) {
        		valid = 0;
    			}else{
    				for (int i = 0; pageInput[i] != '\0'; i++){
    					if (!isdigit((unsigned char)pageInput[i])){
    						valid = 0;
                			break;
						}
					}
				}
				if (valid){
					targetPage = atoi(pageInput);
					if (targetPage >= 1 && targetPage <= totalPages) {
            		currentPage = targetPage;
        			}else{
						printf("LOI: So trang khong hop le (%d ngoai pham vi).\n", targetPage);	
					}
				}else{
					printf(" LOI: Dinh dang so trang khong hop le.\n");
				}
                break;
            }
                
            default:
                printf("LOI: Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\nNhan Enter de tiep tuc...");
    }		
}


//F05
void searchEmpolyeeByName(){
	char tempName[50];
	int Valid = 0;
	int index = 0;
	
		if (employeeCount == 0) {
        printf("Danh sach nhan vien hien dang trong\n");
		return;  
}

	printf("Nhap ten nhan vien can tim kiem: ");
	do{
	fgets(tempName, sizeof(tempName), stdin);
	tempName[strcspn(tempName, "\n")] = 0;
	if (strlen(tempName) == 0){
		printf("Khong duoc trong\n");
	}else{
		Valid = 1;
	}
}while(!Valid);

		
	for (int i = 0; i < employeeCount; i++){
		if(index ==0){
			printf("---------------------------------------------------------------------------------------------------\n");
	    printf("| %-4s | %-15s | %-25s | %-12s | %-10s | %-8s |\n", "STT", "Ma NV", "Ten", "Chuc vu", "Luong co ban", "So ngay Cong");
	    printf("---------------------------------------------------------------------------------------------------\n");
		}
		
        if (strstr(employeeList[i].name, tempName) != NULL){    	
	    printf("| %-4d | %-15s | %-25s | %-12s | %-12.2lf | %-12d |\n", i + 1, employeeList[i].empId, employeeList[i].name, employeeList[i].position, employeeList[i].baseSalary, employeeList[i].workDay);  
        	index = 1;
        } 
    }
    if(index == 0){
        	printf("Khong tim thay");
		}else{
    printf("---------------------------------------------------------------------------------------------------\n");			
		}
}


//F06	
void sortChoiceEmployeeListByBaseSalary(){
	int sortChoice;
	char choice_char[10];
	int valid = 0;
	if (employeeCount == 0) {
        printf("Danh sach nhan vien hien dang trong\n");
		return;  
	}
	do{
		printf("Chon thu tu sap xep:\n");
   		printf("1. Tang dan\n");
   		printf("2. Giam dan\n");
		printf("Nhap lua chon (tang hay giam): ");
		if (fgets(choice_char, sizeof(choice_char), stdin) == NULL) {
			valid = 0; 
			continue;
		}
		choice_char[strcspn(choice_char, "\n")] = 0;
		
		int is_valid_input = 1;
		if (strlen(choice_char) == 0) {
			is_valid_input = 0;
		}else{
			for (int i = 0; choice_char[i] != '\0'; i++) {
				if (!isdigit((unsigned char)choice_char[i])) { 
					is_valid_input = 0;
					break; 
				}
			}
		}
		if (is_valid_input){
			sortChoice = atoi(choice_char);
			if (sortChoice == 1 || sortChoice == 2) {
				valid = 1;
			}else{
				printf("LOI: Lua chon phai la 1 hoac 2.\n");
			}
		}else{
			printf("LOI: Dinh dang lua chon khong hop le. Vui long nhap 1 hoac 2.\n");
		}
	}while(!valid);
	
		struct Employee temp;
		int swapped;
					
				for (int i = 0; i < employeeCount - 1; i++) {
						swapped = 0; 
					for (int j = 0; j < employeeCount - i - 1; j++) {
						int Sort = 0;
						if (sortChoice == 1){
							Sort = (employeeList[j].baseSalary > employeeList[j + 1].baseSalary);
						}else{
							Sort = (employeeList[j].baseSalary < employeeList[j + 1].baseSalary);
						}
						if (Sort) {
                			temp = employeeList[j];
                			employeeList[j] = employeeList[j + 1];
              				employeeList[j + 1] = temp;
             			   	swapped = 1;
            }
		}
		if (swapped == 0) break;		
	}

		displayEmployee();

}



	



//F07
void timeKeeping(){
	char checkInEmpId[20];
	char checkInDate[20]; 
	char logIdStr[20];
    int empIndex = -1;
    
    int day;
    int month;
    int year;
	int valid = 0;
	int maxDaysInMonth;
	
	do {
        printf("Nhap Ma NV can cham cong: ");
        if (fgets(checkInEmpId, sizeof(checkInEmpId), stdin) == NULL){
        	return;	
		}
        checkInEmpId[strcspn(checkInEmpId, "\n")] = 0;
        if (strlen(checkInEmpId) == 0) {
            printf("LOI: Ma NV khong duoc de trong.\n");
            continue;
        }
        
        for (int i = 0; i < employeeCount; i++) {
            if (strcmp(employeeList[i].empId, checkInEmpId) == 0) {
                empIndex = i;
                break;
            }
        }

        if (empIndex == -1) {
            printf("LOI: Khong tim thay nhan vien co ma [%s].\n", checkInEmpId);
        }
    } while (empIndex == -1);
    
    do {
        printf("Nhap Ngay cham cong (dd/mm/yyyy): ");
        if (fgets(checkInDate, sizeof(checkInDate), stdin) == NULL){
       	 	return;	
		}
        checkInDate[strcspn(checkInDate, "\n")] = 0;
		valid =1;

        if (strlen(checkInDate) != 10 || checkInDate[2] != '/' || checkInDate[5] != '/') {
            printf("LOI: Dinh dang ngay khong hop le. Phai la dd/mm/yyyy.\n");
            valid =0;
	        }
        
        
        if(valid){
		if (sscanf(checkInDate, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("LOI: Khong the doc duoc gia tri ngay thang.\n");
        valid =0;
   		}else if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("LOI: Gia tri Ngay (%d) hoac Thang (%d) khong hop le (ngoai pham vi 1-12/1-31).\n", day, month);
        valid =0;
	    }else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("LOI: Thang %d chi co toi da 30 ngay.\n", month);
        valid =0;
	    }else if (month == 2) {
        	maxDaysInMonth = isLeap(year) ? 29 : 28;
	    }else{
	    	maxDaysInMonth = 31;
		}
		if (day > maxDaysInMonth){
			printf("LOI: Ngay [%d/%d/%d] khong ton tai. Thang %d chi co toi da %d ngay.\n", day, month, year, month, maxDaysInMonth);
                    valid = 0;
		}
        	

        if (valid) {
        	for (int i = 0; i < timeSheetCount; i++) {
            if (strcmp(timeSheetList[i].empId, checkInEmpId) == 0 &&
                strcmp(timeSheetList[i].date, checkInDate) == 0) {
                printf("LOI: Nhan vien [%s] da duoc cham cong vao ngay [%s] roi.\n", checkInEmpId, checkInDate);
            	printf("Vui long nhap lai ngay khac.\n");
            	valid =0;
                break;
            }
        }
    }
}
	    
        
        
        
    } while (valid == 0);
    
    employeeList[empIndex].workDay++;
    snprintf(logIdStr, sizeof(logIdStr), "LOG%03d", nextLogId);
    
    struct TimeSheet newRecord;
    strcpy(newRecord.logId, logIdStr);
    strcpy(newRecord.empId, checkInEmpId);
    strcpy(newRecord.date, checkInDate);
    strcpy(newRecord.status, "Di Lam");
    
    if (timeSheetCount < MAX_RECORDS) {
        timeSheetList[timeSheetCount++] = newRecord;
        nextLogId++;
        
        printf("\nCham cong ngay [%s] cho nhan vien [%s] thanh cong.\n", checkInDate, checkInEmpId);
        printf("Thong tin: Log ID [%s] | Ten: %s | Ngay cong moi: %d.\n", newRecord.logId, employeeList[empIndex].name, employeeList[empIndex].workDay);
    } else {
        printf(" LOI: Danh sach bang cong da day. Khong the ghi nhan them.\n");
    }
}


//F08
void viewPersonalTimeSheet(){
	struct TimeSheet personalRecords[MAX_RECORDS];
	
	char viewEmpId[20];
    int empIndex = -1;
    int foundRecords = 0;
    
    char yearInput[5];
    int viewYear = 0;
    int validYear = 0;
    
    
    
    if (employeeCount == 0) {
        printf("LOI: Danh sach nhan vien hien dang trong. Khong the xem bang cong.\n");
        return;
    }
    do {
        printf("Nhap Ma NV can xem bang cong: ");
        if (fgets(viewEmpId, sizeof(viewEmpId), stdin) == NULL){
        return;	
		}
        viewEmpId[strcspn(viewEmpId, "\n")] = 0;

        if (strlen(viewEmpId) == 0) {
            printf("LOI: Ma NV khong duoc de trong.\n");
            continue;
        }

        for (int i = 0; i < employeeCount; i++) {
            if (strcmp(employeeList[i].empId, viewEmpId) == 0) {
                empIndex = i;
                break;
            }
        }

        if (empIndex == -1) {
            printf("LOI: Khong tim thay nhan vien co ma [%s].\n", viewEmpId);
        }
    } while (empIndex == -1);

    do {
        printf("Nhap Nam can xem (yyyy, de trong de xem tat ca): ");
        if (fgets(yearInput, sizeof(yearInput), stdin) == NULL){
        	return;	
		}
        yearInput[strcspn(yearInput, "\n")] = 0;

        validYear = 1;

        if (strlen(yearInput) == 0) {
            viewYear = 0;
            break;
        }

        if (strlen(yearInput) != 4 || sscanf(yearInput, "%d", &viewYear) != 1 || viewYear < 1900 || viewYear > 2100) {
            printf("LOI: Nam khong hop le. Vui long nhap 4 chu so (yyyy) trong pham vi 1900-2100.\n");
            validYear = 0; 
            viewYear = -1;
        }
    } while (validYear == 0);
    
    for (int i = 0; i < timeSheetCount; i++) {
        if (strcmp(timeSheetList[i].empId, viewEmpId) == 0) {
        	int storedYear;
        	if (sscanf(timeSheetList[i].date, "%*d/%*d/%d", &storedYear) == 1){
        		if (viewYear == 0 || storedYear == viewYear){
        			personalRecords[foundRecords] = timeSheetList[i];
            		foundRecords++;
				}
			}
        	
            
            if (foundRecords >= MAX_RECORDS) {
                break;
        }
    }
}
		if (foundRecords > 1) {
        struct TimeSheet temp;
        for (int i = 0; i < foundRecords - 1; i++){
            for (int j = 0; j < foundRecords - i - 1; j++){
                int date1 = dateToInt(personalRecords[j].date);
                int date2 = dateToInt(personalRecords[j+1].date);
                
                if (date1 > date2) {
                    temp = personalRecords[j];
                    personalRecords[j] = personalRecords[j+1];
                    personalRecords[j+1] = temp;
                }
            }
        }
   	 }

    printf("\n======================================================\n");
    printf("BANG CONG CUA NHAN VIEN: %s\n", employeeList[empIndex].name);
    if (viewYear > 0) {
        printf("Loc theo Nam: %d | ", viewYear);
    } else {
        printf("Loc theo Nam: Tat ca | ");
    }
    printf("Ma NV: %s | Chuc vu: %s | Tong ngay cong: %d\n", employeeList[empIndex].empId, employeeList[empIndex].position, employeeList[empIndex].workDay);
    printf("======================================================\n");
    printf("| %-8s | %-15s | %-15s |\n", "ID Log", "Ngay Cham Cong", "Trang Thai");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < foundRecords; i++) {
            printf("| %-8s | %-15s | %-15s |\n", personalRecords[i].logId, personalRecords[i].date, personalRecords[i].status);
    }
    printf("---------------------------------------------------\n");
       
        
	    if (foundRecords == 0) {
	    	if(viewYear > 0){
	        printf("Thong bao: Nhan vien [%s] chua co bat ky ban ghi cham cong nao.\n", viewEmpId);
		} else {
		printf("Thong bao: Nhan vien [%s] chua co bat ky ban ghi cham cong nao.\n", viewEmpId);	
    	}
		}else{
        printf("Thong bao: Hien thi %d ban ghi cham cong thanh cong.\n", foundRecords);		
		}
}
