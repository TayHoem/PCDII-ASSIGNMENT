#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <windows.h>
#pragma warning(disable:4996)
#define MAX_MEMBERS 1000 //define max_member number to fread

void logo();

//// Staff
void staffPage();
int loginStaff(int* y); 
int displayMenu(int menu);
void displayStaffInfo(int arr);
void displayStaffBenefit(int y);
void displayStaffJurisdiction(int y);
int changesInStaff();
void addStaffInfo();
void modifyStaffInfo();
void deleteStaffInfo();
void searchStaffInfo(int y);
void attendanceTake();
void attendanceReport();
int validateDate(int day, int month, int year);


typedef struct {
	int day;
	int month;
	int year;
} date;

typedef struct {
	date absentDate;
	char id[4];
	char name[30];
} absent;

typedef struct {
	char id[4];
	char ps[20];
	char name[30];
	char position[8];
	char gender;
	double salary;
	date entryDate;
} staff;

typedef struct {
	date attendanceDate;
	char attStfName[30];
	int attStaffNum;
	int totalStaffNum;
} attendance;
////Staff 


////STOCK
typedef struct {
	double totalPrice;
	int reorderQuan;
}Reorder;

typedef struct {
	int day, month, year;
	char prodCode[10], prodName[30], category[20];
	int remainStock;
	double price;
	Reorder reorderList;
}product;

void stockPage();
void searchProduct(product prodList[], int numProducts);
void addProduct(product prodList[], int numProducts);
void modify(product prodList[], int numProducts);
void delete(product prodList[], int numProducts);
int monthcount(int day, int month, int year);
void display(product prodList[], int numProducts);
void reorder(product prodList[], int numProducts);
////STOCK 

///SALES & ORDER
void salesAndOrderPage();
void addOrder();
void displayProduct();
void searchOrder();
void modifyOrder();
void searchItems();
void payment();
void sales();
void deleteOrdered();

typedef struct {
	char code[6];
	char name[20];
	double price;
} Item;

typedef struct {
	char username[20];
	int pas;
	char bank[30];
}Payment;

typedef struct {
	char name[20];
	char code[6];
	char memType;
	int quantity;
	char orderName[20];
	double price;
}Add;

typedef struct {
	char newName[20];
	char newOrderName[20];
	int newQuantity;
}MODI;
////SALES & ORDER


//////MEMBER
void memberPage();
void menuMember();
void signUpMember();
void displayMemberAll();
void CheckReturn(int* found, int* i);
void checkLengthMemberId(char memberID[], int* j); 
void checkLengthPassword(char password[], int* j);
void loginMember();
int checkMemberIDExists(char id[], char password[]);
void searchMOrderHis(char tempMbId[]);
void displayDiscountMember(char tempMbId[]);
void modifyMember(char tempMbId[]);
void deleteMember();

////MemberAcount ID , password & details data
//Global initialize structure MEMBER
typedef struct {
	char memberId[10];
	char passwordM[11];
	char memberName[21];
	char gender;
	int phoneNum;
	char email[45];
	char memberType;
	int period;
	double fee;
}MEMBER;
//////MEMBER

void main() {
	int sOrM = 0, sOrT = 0, member = 0, salesAndOrder = 0;
   
    do {
		printf("\n");
		logo();
		printf("\t<<<<<------------------------------------------>>>>>\n");
		printf("\t\t\t1. STAFF\n");
		printf("\t\t\t2. CUSTOMER\n");
		printf("\t\t\t3. SALES & ORDER\n");
		printf("\t\t\t4. Exit program\n");
		printf("\t<<<<<------------------------------------------>>>>>\n");
        printf("\t\t\tChoose :");
        scanf("%d", &sOrM);
        switch (sOrM)
        {
        case 1:
			do {
				printf("\n===================\n");
				printf("|1. STAFF PAGE      |\n");
				printf("|2. STOCK PAGE      |\n");
				printf("|3. Return MAIN PAGE|\n");
				printf("=====================\n");
				printf("Choose 1 you want :");
				scanf("%d", &sOrT);
				switch (sOrT) {
				case 1:
					staffPage(); 
					break;
				case 2:
					stockPage(); 
					break;
				case 3:
					printf("\n<<<--------------------------->>>\n");
					printf("\tRETURN MAIN PAGE\n");
					printf("<<<--------------------------->>>\n\n");
					break;
				default:
					printf("PLEASE key in 1,2 and 3 only.....");
					break;
				}

			} while (sOrT != 3);
            break;
        case 2:
			do {
				printf("\n==========================\n");
				printf("|1. MEMBER PAGE          |\n");
				printf("|2. Return MAIN PAGE     |\n");
				printf("==========================\n");
				printf("Choose 1 you want :");
				scanf("%d", &member);
				switch (member) {
				case 1:
					memberPage();
					break;
				case 2:
					printf("\n<<<--------------------------->>>\n");
					printf("\tRETURN MAIN PAGE\n");
					printf("<<<--------------------------->>>\n\n");
					break;
				default:
					printf("PLEASE key in 1,2 and 3 only.....");
					break;
				}

			} while (member != 2);
			break;
        case 3:
			do {
				printf("\n==========================\n");
				printf("|1. SALES AND ORDER PAGE |\n");
				printf("|2. Return MAIN PAGE     |\n");
				printf("==========================\n");
				printf("Choose 1 you want :");
				scanf("%d", &salesAndOrder);
				switch (salesAndOrder) {
				case 1:
					printf("\n\n");
					salesAndOrderPage();
					break;
				case 2:
					printf("\n<<<--------------------------->>>\n");
					printf("\tRETURN MAIN PAGE\n");
					printf("<<<--------------------------->>>\n\n");
					break;
				default:
					printf("PLEASE key in 1,2 and 3 only.....");
					break;
				}

			} while (salesAndOrder != 2); 
			break;
		case 4:
			printf("\n\n======================\n");
			printf("| PROGRAM END -w-    |\n");
			printf("| HAVE A NICE DAY !!!|\n");
			printf("======================");
			exit(-1); 
        default:
            printf("Key IN 1 to 3 only......");
            break;
        }

    } while (sOrM != 4);

}

//display the logo for grocery
void logo() {
	printf("\t\t  _____         _     _         \n");
	printf("\t\t |_   _|____  _| |_  (_) ___    \n");
	printf("\t\t   | |/ _ \\ \\/ / | |/ / |/ _ \\  \n");
	printf("\t\t   | |  __/>  <| |   <| |  __/  \n");
	printf("\t\t   |_|\\___/_/\\_\\_|\\_\\_|\\___|  \n\n");
	printf("\t\t       Welcome to O^w^O\n");
	printf("\t\t      The Daily Market!!!\n");
	printf("\t\t       Happy shopping!!!\n");
}

//Staff Page
void staffPage() {
	int y;
	int stfmenu, stfaction, stfChangesAction;
	char newAction, confirmAction;


	stfmenu = loginStaff(&y); 

	do {
		stfaction = displayMenu(stfmenu);

		switch (stfaction) {
		case 0: printf("You exit the program.");  return 0; break;
		case 1: displayStaffInfo(y); break;
		case 2: displayStaffBenefit(y); break;
		case 3: displayStaffJurisdiction(y); break;
		case 4:
			stfChangesAction = changesInStaff();
			switch (stfChangesAction) {
			case 1: addStaffInfo(); break;
			case 2: modifyStaffInfo(); break;
			case 3: deleteStaffInfo(); break;
			default: printf("System error\n");
				exit(-1);
			}
			break;
		case 5: searchStaffInfo(y); break;
		case 6: attendanceTake(); break;
		case 7: attendanceReport(); break;
		default: printf("Unknown Errors\n");
		}

		do {
			printf("\nNew Action? (E for exit / Y for yes) :");
			rewind(stdin);
			scanf("%c", &newAction);
			confirmAction = 'Y';
			if (newAction == 'E')
				exit(-1);
			else if (newAction != 'E' && newAction != 'Y') {
				confirmAction = 'X';
				printf("Invalid Selection.Please enter the order according the instruction.\n");
			}
		} while (confirmAction == 'X');
	} while (newAction == 'Y');

	return 0;
}

int loginStaff(int* y) { 

	char loginID[10];
	char loginPs[20];
	char confirmID, confirmPs, confirmLogin;
	int menu, i, z;

	staff stf[100];


	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}


	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}

	printf("\n========================================================\n");
	printf("\t\t STAFF LOGIN");
	printf("\n========================================================\n");

	do {
		confirmID = 'X';
		confirmPs = 'X';
		confirmLogin = 'X';
		do {
			printf("Enter your ID to login(3 digits) : ");
			rewind(stdin);
			scanf("%[^\n]", loginID);
		} while (strlen(loginID) > 3);


		for (i = 0; i < z; i++) {

			if (strcmp(loginID, stf[i].id) == 0) {
				confirmID = 'Y';
				printf("Enter your password to login     : ");
				scanf("%s", loginPs);
				if (strcmp(loginPs, stf[i].ps) == 0) {
					confirmPs = 'Y';
					printf("\n========================================================\n");
					printf("\t\tLOGIN SUCCESSFUL");
					printf("\n========================================================\n");
					*y = i;




					if (strcmp(stf[i].position, "Staff") == 0) {
						menu = 0;
						return menu;
					}
					else if (strcmp(stf[i].position, "Manager") == 0) {
						menu = 1;
						return menu;
					}
					else if (strcmp(stf[i].position, "Boss") == 0) {
						menu = 2;
						return menu;
					}
					confirmLogin = 'Y';
				}
			}
		}
		if (confirmID == 'X')
			printf("Your ID is not exist.Please try to enter your ID and password again\n");
		if (confirmID == 'Y' && confirmPs == 'X')
			printf("Your password is not match.Please try to enter your ID and password again.\n");
	} while (confirmLogin == 'X');

	fclose(ptr2);
}

int displayMenu(int menu) {
	int action;
	char confirm1;

	if (menu == 0) {
		printf("\n\n    <<<-------------- Staff Menu -------------->>>\n");
		printf("\t  0. Exit the Program\n");
		printf("\t  1. Display Personal Infomation\n");
		printf("\t  2. Display Benefits for you\n");
		printf("\t  3. Display Personal jurisdiction\n");
		printf("\n    <<<-------------- Staff Menu -------------->>>\n");
	}
	else if (menu == 1) {
		printf("\n\n    <<<------------- Manager Menu ------------->>>\n");
		printf("\t  0. Exit the Program\n");
		printf("\t  1. Display Personal Infomation\n");
		printf("\t  2. Display Benefits for you\n");
		printf("\t  3. Display Personal jurisdiction\n");
		printf("\t  4. Change Staff Personal Infomation\n");
		printf("\t  5. Search Staff Personal Information\n");
		printf("\t  6. Take Attendance\n");
		printf("\n    <<<------------- Manager Menu ------------->>>\n");
	}

	else if (menu == 2) {
		printf("\n\n    <<<---------- Boss Menu ---------->>>\n");
		printf("\t  0. Exit the Program\n");
		printf("\t  1. Display Personal Infomation\n");
		printf("\t  2. Display Benefits for you\n");
		printf("\t  3. Display Personal jurisdiction\n");
		printf("\t  4. Change Staff Personal Infomation\n");
		printf("\t  5. Search Staff Personal Information\n");
		printf("\t  6. Take Attendance\n");
		printf("\t  7. Generate Attendance Report\n");
		printf("\n    <<<---------- Boss Menu ---------->>>\n");
	}
	do {
		do {
			printf("Please select Your Action : ");
			rewind(stdin);
			scanf("%d", &action);
		} while (isalpha(action));
		confirm1 = 'r';
		if (menu == 0) {
			if (action < 0 || action > 3) {
				printf("Unvalid Action! Please Select another action.\n");
				confirm1 = 'w';
			}
		}
		if (menu == 1) {
			if (action < 0 || action >6) {
				printf("Unvalid Action! Please Select another action.\n");
				confirm1 = 'w';
			}

		}
		if (menu == 2) {
			if (action < 0 || action > 7) {
				printf("Unvalid Action! Please Select another action.\n");
				confirm1 = 'w';
			}
		}
	} while (confirm1 == 'w');

	return action; 
}

void displayStaffInfo(int arr) {

	char displayGender[7],name[30],orderName[30];
	char memType;
	double commission, commissionRate, totalSalary,totalSales=0,price;
	printf("\n\n========================================================\n");
	printf("\t\t   Personal Info");
	printf("\n========================================================\n\n");
	staff stf[100];


	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	FILE* forder;
	forder = fopen("Orders.txt", "r");
	if (forder == NULL) {
		printf("Opening file errors...\n");
		return;
	}
	while (fscanf(forder, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", name, &memType, orderName, &price) != EOF) {
		totalSales += price;
	}
	fclose(forder);

	int z;
	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}
	if (stf[arr].gender == 'M')
		strcpy(displayGender, "Male");
	else if (stf[arr].gender == 'F')
		strcpy(displayGender, "Female");

	printf("%-10s : %s\n", "ID", stf[arr].id);
	printf("%-10s : %s\n", "Password", stf[arr].ps);
	printf("%-10s : %s\n", "Name", stf[arr].name);
	printf("%-10s : %s\n", "Gender", displayGender);
	printf("%-10s : %s\n", "Position", stf[arr].position);
	printf("%-10s : %02d-%02d-%4d\n", "Entry Date", stf[arr].entryDate.day, stf[arr].entryDate.month, stf[arr].entryDate.year);
	if (strcmp(stf[arr].position, "Boss") == 0)
		printf("%-10s : %s\n", "Salary", "NULL");
	else {
		//salary display

		if (strcmp(stf[arr].position, "Staff") == 0) {
			if (totalSales >= 1500 && totalSales < 3000) {
				commissionRate = 0.05;
			}
			else if (totalSales >= 3000 && totalSales < 6000) {
				commissionRate = 0.10;
			}
			else if (totalSales >= 6000) {
				commissionRate = 0.15;
			}
			else
				commissionRate = 0;
		}

		if (strcmp(stf[arr].position, "Manager") == 0) {
			if (totalSales >= 1500 && totalSales < 3000) {
				commissionRate = 0.10;
			}
			else if (totalSales >= 3000 && totalSales < 6000) {
				commissionRate = 0.15;
			}
			else if (totalSales >= 6000) {
				commissionRate = 0.20;
			}
			else
				commissionRate = 0;
		}
		commission = commissionRate * stf[arr].salary;
		totalSalary = commission + stf[arr].salary;
		printf("=============================\n");
		printf("%-15s : %04.2f\n", "Basic Salary", stf[arr].salary);
		printf("%-15s : %04.2f\n", "Commission Rate", commissionRate);
		printf("%-15s : %04.2f\n", "Commission", commission);
		printf("%-15s : %04.2f\n", "Total Salary", totalSalary);
		printf("=============================\n\n");
	}


	fclose(ptr2);

	printf("\n========================================================\n");
	printf("\t\t   Personal Info");
	printf("\n========================================================\n");

}


void displayStaffBenefit(int arr) {

	//read all data from staff.dat binary file
	staff stf[100];

	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	int z;
	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}

	if (strcmp(stf[arr].position, "Staff") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Staff");
		printf("\n========================================================\n\n\n");
		printf("1. Company provide residence for staff.\n");
		printf("2. Staff can get commission when the total sales over some spesific total sales amount.\n");
		printf("3. Company will organise company trip at least biannual.\n");
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Staff");
		printf("\n========================================================\n");
	}

	else if (strcmp(stf[arr].position, "Manager") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Manager");
		printf("\n========================================================\n\n\n");
		printf("1. Company will provide residence for manager.\n");
		printf("2. Company will provide allowance for house purchase to manager.\n");
		printf("3. Manager can get higher commission rate when total sales over some spesific total sales amount\n");
		printf("4. Company will organise company trip al least biannual.\n");
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Manager");
		printf("\n========================================================\n\n\n");
	}

	else if (strcmp(stf[arr].position, "Boss") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Boss");
		printf("\n========================================================\n\n\n");
		printf("You already is the boss of company.What benefits you want man?\n");
		printf("\n\n========================================================\n");
		printf("\t\tBenefits of Boss");
		printf("\n========================================================\n\n\n");
	}

	fclose(ptr2);
}


void displayStaffJurisdiction(int arr) {

	//read all data from staff.dat binary file
	staff stf[100];

	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	int z;
	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}
	printf("\n\n");
	if (strcmp(stf[arr].position, "Staff") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Staff");
		printf("\n========================================================\n\n\n");
		printf("1. Staff are allowed to check their personal information.\n");
		printf("2. Staff are allowed to check their benefits and jurisdiction.\n");
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Staff");
		printf("\n========================================================\n\n\n");
	}

	else if (strcmp(stf[arr].position, "Manager") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Manager");
		printf("\n========================================================\n\n\n");
		printf("1. Manager are allowed to check their personal information.\n");
		printf("2. Manager are allowed to check their benefits and jurisdiction.\n");
		printf("3. Manager are allowed to make some changes like add,modify or delete employee personal information except boss.\n");
		printf("4. Manager are allowed to check staff information.\n");
		printf("5. Manager are allowed to take attendance for all the staff.\n");
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Manager");
		printf("\n========================================================\n\n\n");
	}

	else if (strcmp(stf[arr].position, "Boss") == 0) {
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Boss");
		printf("\n========================================================\n\n\n");
		printf("You already is the boss of company.You want to do anything also up to you la bro\n");
		printf("\n\n========================================================\n");
		printf("\t\tJurisdiction of Boss");
		printf("\n========================================================\n\n\n");
	}

	fclose(ptr2);
}


int changesInStaff() {

	int modifyAction;
	char confirmModify;
	do {
		confirmModify = 'Y';
		printf("\n========================================================\n");
		printf("\t\t MODIFICATION STAFF");
		printf("\n========================================================\n");
		printf("1. Add Staff Personal Info\n");
		printf("2. Modify Staff Personal Info\n");
		printf("3. Delete Staff Personal Info\n");
		printf("\n========================================================\n");
		printf("\t\t MODIFICATION STAFF");
		printf("\n========================================================\n");

		printf("Please select your action(1-3) : ");
		scanf("%d", &modifyAction);
		if (modifyAction < 1 || modifyAction > 3) {
			printf("Invalid Selection.Please select between 1 to 3!\n");
			confirmModify = 'X';
		}
	} while (confirmModify == 'X');
	return modifyAction;
}


void addStaffInfo() {

	char confirmAdd;
	int staffNum;
	printf("\n\n    <<----------- Add Staff Infomation ----------->>\n");

	staff stf[100];
	staff temp;

	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	FILE* ptr13;
	ptr13 = fopen("staffNumber.dat", "rb");
	if (ptr13 == NULL) {
		printf("Unable to open ptr13\n");
		exit(-1);
	}
	fread(&staffNum, sizeof(int), 1, ptr13);

	fclose(ptr13);


	int z;

	for (z = 0; z < staffNum; z++) {
		fread(&stf[z], sizeof(staff), 1, ptr2);
	}
	fclose(ptr2);


	do {
		printf("Enter the new Staff ID           : ");
		rewind(stdin);
		scanf("%s", temp.id);
	} while (strlen(temp.id) > 3);

	printf("Enter the new Staff Password     : ");
	rewind(stdin);
	scanf("%[^\n]", temp.ps);
	printf("Enter the new Staff Name         : ");
	rewind(stdin);
	scanf("%[^\n]", temp.name);

	do {
		printf("Enter the new Staff Position     : ");
		rewind(stdin);
		scanf("%s", temp.position);
	} while ((strcmp(temp.position, "Staff") != 0) && (strcmp(temp.position, "Manager") != 0));

	do {
		printf("Enter the new Staff Gender(M/F)  : ");
		rewind(stdin);
		scanf("%c", &temp.gender);
	} while (temp.gender != 'M' && temp.gender != 'F');

	printf("Enter the new Staff Salary       : ");
	rewind(stdin);
	scanf("%lf", &temp.salary);


	do {
		printf("Enter the Entry Date(DD-MM-YYYY) : ");
		rewind(stdin);
		scanf("%d-%d-%d", &temp.entryDate.day, &temp.entryDate.month, &temp.entryDate.year);
	} while (validateDate(temp.entryDate.day, temp.entryDate.month, temp.entryDate.year));

	printf("\n\n");
	printf("\t  New Staff Infomation\n");
	printf("     --------------------------------\n");
	printf("     |%-10s : %-15s  |\n", "ID", temp.id);
	printf("     |%-10s : %-15s  |\n", "Password", temp.ps);
	printf("     |%-10s : %-15s  |\n", "Name", temp.name);
	printf("     |%-10s : %c\t\t    |\n", "Gender", temp.gender);
	printf("     |%-10s : %-15s  |\n", "Position", temp.position);
	printf("     |%-10s : %02d-%02d-%4d\t    |\n", "Entry Date", temp.entryDate.day, temp.entryDate.month, temp.entryDate.year);
	if (strcmp(temp.position, "Boss") == 0)
		printf("     |%-10s : %-15s|\n", "Salary", "NULL");
	else
		//salary display
		printf("     |%-10s : %04.2f\t    |\n", "Salary", temp.salary);
	printf("     --------------------------------");
	printf("\n\n");
	do {
		printf("Confirm to add new staff?(Y = yes / N = no) :");
		rewind(stdin);
		scanf("%c", &confirmAdd);
		if (confirmAdd != 'Y' && confirmAdd != 'N')
			printf("Invalid Action.Please select your action according the intruction.\n");
	} while (confirmAdd != 'Y' && confirmAdd != 'N');

	if (confirmAdd == 'X') {
		printf("You have cancel the Add action\n");
	}


	else if (confirmAdd == 'Y') {

		staffNum++;


		strcpy(stf[z].id, temp.id);
		strcpy(stf[z].ps, temp.ps);
		strcpy(stf[z].name, temp.name);
		strcpy(stf[z].position, temp.position);
		stf[z].gender = temp.gender;
		stf[z].salary = temp.salary;
		stf[z].entryDate.day = temp.entryDate.day;
		stf[z].entryDate.month = temp.entryDate.month;
		stf[z].entryDate.year = temp.entryDate.year;



		FILE* ptr7;
		ptr7 = fopen("staff.dat", "wb");
		if (ptr7 == NULL) {
			printf("Unable to open file.");
			exit(-1);
		}

		fwrite(&stf, sizeof(stf[0]), staffNum, ptr7);
		fclose(ptr7);

		printf("\n========================================================\n");
		printf("\t ADD A NEW STAFF SUCCESSFULLY!!!");
		printf("\n========================================================\n");



		FILE* ptr14;
		ptr14 = fopen("staffNumber.dat", "wb");
		if (ptr14 == NULL) {
			printf("Unable to open file.");
			exit(-1);
		}
		fwrite(&staffNum, sizeof(staffNum), 1, ptr14);
		fclose(ptr14);


	}
}


void modifyStaffInfo() {
	printf("\n\n    <<----------- Modify Staff Infomation ----------->>\n");

	staff stf[100];
	int staffNum;
	staff temp;
	char confirmModify;
	int match;

	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	FILE* ptr13;
	ptr13 = fopen("staffNumber.dat", "rb");
	if (ptr13 == NULL) {
		printf("Unable to open ptr13\n");
		exit(-1);
	}
	fread(&staffNum, sizeof(int), 1, ptr13);

	fclose(ptr13);


	int z;

	for (z = 0; z < staffNum; z++) {
		fread(&stf[z], sizeof(staff), 1, ptr2);
	}
	fclose(ptr2);


	do {
		printf("Please enter employee ID that need to Modify(XXX) : ");
		scanf("%s", temp.id);
		match = 0;

		for (int i = 0; i < staffNum; i++) {
			if (strcmp(stf[i].id, temp.id) == 0) {
				match++;

				printf("\n\n\t  Old Staff Infomation\n");
				printf("     --------------------------------\n");
				printf("     |%-10s : %-15s  |\n", "ID", stf[i].id);
				printf("     |%-10s : %-15s  |\n", "Password", stf[i].ps);
				printf("     |%-10s : %-15s  |\n", "Name", stf[i].name);
				printf("     |%-10s : %c\t\t    |\n", "Gender", stf[i].gender);
				printf("     |%-10s : %-15s  |\n", "Position", stf[i].position);
				printf("     |%-10s : %02d-%02d-%4d\t    |\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
				if (strcmp(stf[i].position, "Boss") == 0)
					printf("     |%-10s : %-15s  |\n", "Salary", "NULL");
				else
					//salary display
					printf("     |%-10s : %04.2f\t    |\n", "Salary", stf[i].salary);
				printf("     --------------------------------");
				printf("\n\n");

				printf("Enter the new Staff Password     : ");
				rewind(stdin);
				scanf("%[^\n]", temp.ps);
				printf("Enter the new Staff Name         : ");
				rewind(stdin);
				scanf("%[^\n]", temp.name);

				do {
					printf("Enter the new Staff Position     : ");
					rewind(stdin);
					scanf("%s", temp.position);
				} while ((strcmp(temp.position, "Staff") != 0) && (strcmp(temp.position, "Manager") != 0));

				do {
					printf("Enter the new Staff Gender(M/F)  : ");
					rewind(stdin);
					scanf("%c", &temp.gender);
				} while (temp.gender != 'M' && temp.gender != 'F');

				printf("Enter the new Staff Salary       : ");
				rewind(stdin);
				scanf("%lf", &temp.salary);

				do {
					printf("Enter the Entry Date(DD-MM-YYYY) : ");
					rewind(stdin);
					scanf("%d-%d-%d", &temp.entryDate.day, &temp.entryDate.month, &temp.entryDate.year);
				} while (validateDate(temp.entryDate.day, temp.entryDate.month, temp.entryDate.year));

				printf("\n\n\t  New Staff Infomation\n");
				printf("     --------------------------------\n");
				printf("     |%-10s : %-15s  |\n", "ID", temp.id);
				printf("     |%-10s : %-15s  |\n", "Password", temp.ps);
				printf("     |%-10s : %-15s  |\n", "Name", temp.name);
				printf("     |%-10s : %c\t\t    |\n", "Gender", temp.gender);
				printf("     |%-10s : %-15s  |\n", "Position", temp.position);
				printf("     |%-10s : %02d-%02d-%4d\t    |\n", "Entry Date", temp.entryDate.day, temp.entryDate.month, temp.entryDate.year);
				if (strcmp(temp.position, "Boss") == 0)
					printf("     |%-10s : %-15s  |\n", "Salary", "NULL");
				else
					//salary display
					printf("     |%-10s : %04.2f\t    |\n", "Salary", temp.salary);
				printf("     --------------------------------\n\n");

				do {
					printf("Confirm the modification(Y for yes/N for no)? :");
					rewind(stdin);
					scanf("%c", &confirmModify);

					if (confirmModify == 'Y') {
						strcpy(stf[i].id, temp.id);
						strcpy(stf[i].ps, temp.ps);
						strcpy(stf[i].name, temp.name);
						strcpy(stf[i].position, temp.position);
						stf[i].gender = temp.gender;
						stf[i].salary = temp.salary;
						stf[i].entryDate.day = temp.entryDate.day;
						stf[i].entryDate.month = temp.entryDate.month;
						stf[i].entryDate.year = temp.entryDate.year;



						FILE* ptr7;
						ptr7 = fopen("staff.dat", "wb");
						if (ptr7 == NULL) {
							printf("Unable to open file.");
							exit(-1);
						}

						fwrite(&stf, sizeof(stf[0]), staffNum, ptr7);
						fclose(ptr7);
						printf("\n========================================================\n");
						printf("\t MODIFY STAFF INFORMATION SUCCESSFULLY!!!");
						printf("\n========================================================\n");

					}

					else if (confirmModify == 'N')
						printf("You have cancel the modification.\n");

					else
						printf("Invalid Selection.Please select again.\n");
				} while (confirmModify != 'Y' && confirmModify != 'N');


			}
		}
		if (match == 0)
			printf("The id you had entered is not exist.Please enter another ID.\n");

	} while (match == 0);
}


void deleteStaffInfo() {

	int staffNum, match;
	staff stf[100];
	char searchID[4];
	char confirmDelete;


	printf("\n\n    <<----------- Delete Staff Infomation ----------->>\n");


	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	FILE* ptr13;
	ptr13 = fopen("staffNumber.dat", "rb");
	if (ptr13 == NULL) {
		printf("Unable to open ptr13\n");
		exit(-1);
	}
	fread(&staffNum, sizeof(int), 1, ptr13);
	fclose(ptr13);


	int z;

	for (z = 0; z < staffNum; z++) {
		fread(&stf[z], sizeof(staff), 1, ptr2);
	}
	fclose(ptr2);
	match = 0;
	do {
		printf("Please enter employee ID that need to be delete(XXX) : ");
		scanf("%s", searchID);


		for (int i = 0; i < staffNum; i++) {
			if (strcmp(stf[i].id, searchID) == 0) {
				match++;
				printf("\n\n\tStaff Information\n");
				printf("     --------------------------------\n");
				printf("     |%-10s : %-15s  |\n", "ID", stf[i].id);
				printf("     |%-10s : %-15s  |\n", "Password", stf[i].ps);
				printf("     |%-10s : %-15s  |\n", "Name", stf[i].name);
				printf("     |%-10s : %c\t\t    |\n", "Gender", stf[i].gender);
				printf("     |%-10s : %-15s  |\n", "Position", stf[i].position);
				printf("     |%-10s : %02d-%02d-%4d\t    |\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
				if (strcmp(stf[i].position, "Boss") == 0)
					printf("     |%-10s : %-15s  |\n", "Salary", "NULL");
				else
					//salary display
					printf("     |%-10s : %04.2f\t    |\n", "Salary", stf[i].salary);
				printf("     --------------------------------\n\n");

				do {
					printf("Confirm to delete this employee?(Y for yes/N for no) :");
					rewind(stdin);
					scanf("%c", &confirmDelete);

					if (confirmDelete == 'Y') {
						staffNum = staffNum - 1;


						for (int k = 0; (k + i) < staffNum; k++) {
							strcpy(stf[i + k].id, stf[i + k + 1].id);
							strcpy(stf[i + k].ps, stf[i + k + 1].ps);
							strcpy(stf[i + k].name, stf[i + k + 1].name);
							strcpy(stf[i + k].position, stf[i + k + 1].position);
							stf[i + k].gender = stf[i + k + 1].gender;
							stf[i + k].entryDate.day = stf[i + k + 1].entryDate.day;
							stf[i + k].entryDate.month = stf[i + k + 1].entryDate.month;
							stf[i + k].entryDate.year = stf[i + k + 1].entryDate.year;
							stf[i + k].salary = stf[i + k + 1].salary;
						}


						printf("%-10s : %s\n", "ID", stf[i].id);
						printf("%-10s : %s\n", "Password", stf[i].ps);
						printf("%-10s : %s\n", "Name", stf[i].name);
						printf("%-10s : %c\n", "Gender", stf[i].gender);
						printf("%-10s : %s\n", "Position", stf[i].position);
						printf("%-10s : %02d-%02d-%04d\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
						if (strcmp(stf[i].position, "Boss") == 0)
							printf("%-10s : %s\n", "Salary", "NULL");
						else
							//salary display
							printf("%-10s : %04.2f\n", "Salary", stf[i].salary);


						FILE* ptr7;
						ptr7 = fopen("staff.dat", "wb");
						if (ptr7 == NULL) {
							printf("Unable to open file.");
							exit(-1);
						}

						fwrite(&stf, sizeof(stf[0]), staffNum, ptr7);
						fclose(ptr7);
						printf("\n========================================================\n");
						printf("\t DELETE STAFF INFORMATION SUCCESSFULLY!!!");
						printf("\n========================================================\n");


						FILE* ptr14;
						ptr14 = fopen("staffNumber.dat", "wb");
						if (ptr14 == NULL) {
							printf("Unable to open file.");
							exit(-1);
						}
						fwrite(&staffNum, sizeof(staffNum), 1, ptr14);
						fclose(ptr14);
					}

					else if (confirmDelete == 'N') {
						printf("You have cancel the deletion of the employee.\n");
					}
					else
						printf("Invalid action.Please enter again.\n");
				} while (confirmDelete != 'Y' && confirmDelete != 'N');
			}
		}
		if (match == 0)
			printf("This ID is not exist.\n");
	} while (match == 0);
}


void searchStaffInfo(int arr) {

	char searchID[4], searchName[30], searchPosition[8], searchMinID[4], searchMaxID[4], displayGender[7];
	int searchAction, match, number;
	char searchRange, confirmSearch, confirmRangeSearch, confirmName, confirmPosition;

	printf("\n\n========================================================\n");
	printf("\t\tSearch Staff Information");
	printf("\n========================================================\n\n");


	//read all data from staff.dat binary file
	staff stf[100];

	FILE* ptr2;
	ptr2 = fopen("staff.dat", "rb");
	if (ptr2 == NULL) {
		printf("Unable to open staff.dat.");
		exit(-1);
	}

	int z;
	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}
	do {

		confirmSearch = 'Y';
		printf("\n    <<----------- Add Staff Infomation ----------->>\n");
		printf("\t  1. ID \n");
		printf("\t  2. Name \n");
		printf("\t  3. Position \n");
		printf("Your Selection(1-3) : ");
		scanf("%d", &searchAction);
		rewind(stdin);

		switch (searchAction) {
		case 1: do {
			confirmRangeSearch = 'Y';
			printf("\nSearch For One Person(p) or A range(r) ? ");
			rewind(stdin);
			scanf("%c", &searchRange);
			if (searchRange == 'p') {
				match = 0;
				do {
					printf("Please enter the search ID :");
					rewind(stdin);
					scanf("%s", searchID);
					for (int i = 0; i < z; i++) {
						if (strcmp(stf[i].id, searchID) == 0) {
							match++;
							if (strcmp(stf[arr].position, "Manager") == 0 && strcmp(stf[i].position, "Boss") == 0) {
								printf("You have not access to search Information about this Person.\n");
							}
							else {
								if (stf[i].gender == 'M')
									strcpy(displayGender, "Male");
								else if (stf[i].gender == 'F')
									strcpy(displayGender, "Female");
								printf("\n\n");
								printf("  <<<============ (1) ============>>>\n");
								printf("\t%-10s : %s\n", "ID", stf[i].id);
								printf("\t%-10s : %s\n", "Password", stf[i].ps);
								printf("\t%-10s : %s\n", "Name", stf[i].name);
								printf("\t%-10s : %s\n", "Gender", displayGender);
								printf("\t%-10s : %s\n", "Position", stf[i].position);
								printf("\t%-10s : %02d-%02d-%4d\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
								if (strcmp(stf[i].position, "Boss") == 0)
									printf("\t%-10s : %s\n", "Salary", "NULL");
								else
									//salary display
									printf("\t%-10s : %04.2f\n", "Salary", stf[i].salary);
							}
						}
					}
					if (match == 0)
						printf("This ID does not exist.Please enter another ID.\n");
				} while (match == 0);
			}
			else if (searchRange == 'r') {
				do {
					match = 0;
					printf("Please enter the Min range of search ID :");
					scanf("%s", searchMinID);
					printf("Please enter the Max range of search ID :");
					scanf("%s", searchMaxID);
					for (int i = 0; i < z; i++) {
						if ((strcmp(searchMinID, stf[i].id) <= 0) && (strcmp(searchMaxID, stf[i].id) >= 0)) {
							match++;
							printf("\n\n");
							printf("  <<<============ (%d) ============>>>\n", match);
							printf("\t%-10s : %s\n", "ID", stf[i].id);
							printf("\t%-10s : %s\n", "Password", stf[i].ps);
							printf("\t%-10s : %s\n", "Name", stf[i].name);
							printf("\t%-10s : %c\n", "Gender", stf[i].gender);
							printf("\t%-10s : %s\n", "Position", stf[i].position);
							printf("\t%-10s : %02d-%02d-%04d\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
							if (strcmp(stf[i].position, "Boss") == 0)
								printf("\t%-10s : %s\n", "Salary", "NULL");
							else
								//salary display
								printf("\t%-10s : %04.2f\n", "Salary", stf[i].salary);
						}
					}
					if (match == 0)
						printf("This range does not include any staff.Please re-enter ID again.\n");
				} while (match == 0);
			}
			else {
				printf("Invalid Selection.Please select p(person) or r(range) for your search range.\n");
				confirmRangeSearch = 'X';
			}
		} while (confirmRangeSearch == 'X');
		break;


		case 2:
			do {
				printf("Please enter the search Name :");
				rewind(stdin);
				scanf("%s", searchName);
				confirmName = 'X';
				for (int i = 0; i < z; i++) {
					if (strcmp(stf[i].name, searchName) == 0) {
						confirmName = 'Y';
						if (strcmp(stf[arr].position, "Manager") == 0 && strcmp(stf[i].position, "Boss") == 0) {
							printf("You have not access to search Information about this Person.\n");
						}
						else {
							if (stf[i].gender == 'M')
								strcpy(displayGender, "Male");
							else if (stf[i].gender == 'F')
								strcpy(displayGender, "Female");
							printf("\n\n");
							printf("  <<<============ (1) ============>>>\n");
							printf("\t%-10s : %s\n", "ID", stf[i].id);
							printf("\t%-10s : %s\n", "Password", stf[i].ps);
							printf("\t%-10s : %s\n", "Name", stf[i].name);
							printf("\t%-10s : %s\n", "Gender", displayGender);
							printf("\t%-10s : %s\n", "Position", stf[i].position);
							printf("\t%-10s : %02d-%02d-%4d\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
							if (strcmp(stf[i].position, "Boss") == 0)
								printf("\t%-10s : %s\n", "Salary", "NULL");
							else
								//salary display
								printf("\t%-10s : %04.2f\n", "Salary", stf[i].salary);
						}
					}
				}
				if (confirmName == 'X')
					printf("Search Name is not exist.Please enter another name.\n");
			} while (confirmName == 'X');
			break;

		case 3:

			do {
				number = 0;
				printf("Please enter the search Position :");
				rewind(stdin);
				scanf("%s", searchPosition);
				confirmPosition = 'X';
				for (int i = 0; i < z; i++) {
					if (strcmp(stf[i].position, searchPosition) == 0) {
						confirmPosition = 'Y';
						if (strcmp(stf[arr].position, "Manager") == 0 && strcmp(stf[i].position, "Boss") == 0) {
							printf("You have not access to search Information about this Person.\n");
						}
						else {
							if (stf[i].gender == 'M')
								strcpy(displayGender, "Male");
							else if (stf[i].gender == 'F')
								strcpy(displayGender, "Female");

							number++;
							printf("\n\n  <<<============ (%d) ============>>>\n", number);
							printf("\t%-10s : %s\n", "ID", stf[i].id);
							printf("\t%-10s : %s\n", "Password", stf[i].ps);
							printf("\t%-10s : %s\n", "Name", stf[i].name);
							printf("\t%-10s : %s\n", "Gender", displayGender);
							printf("\t%-10s : %s\n", "Position", stf[i].position);
							printf("\t%-10s : %02d-%02d-%4d\n", "Entry Date", stf[i].entryDate.day, stf[i].entryDate.month, stf[i].entryDate.year);
							if (strcmp(stf[i].position, "Boss") == 0)
								printf("\t%-10s : %s\n", "Salary", "NULL");
							else
								//salary display
								printf("\t%-10s : %04.2f\n", "Salary", stf[i].salary);
						}
					}
				}
				if (confirmPosition == 'X')
					printf("Search Position is not exist.Please enter another position.\n");
			} while (confirmPosition == 'X');

			break;

		default: printf("Invalid Search Category.Please select again.\n");
			confirmSearch = 'X';
		}



	} while (confirmSearch == 'X');
	fclose(ptr2);

	printf("\n\n========================================================\n");
	printf("\t\tSearch Staff Information");
	printf("\n========================================================\n\n");

}


void attendanceTake() {

	char absentask, absentask2, confirmAtt;
	int p, staffNum, sumAtt, z, m, j, absentNum, totalAbsent;
	absent absentStf[300];
	attendance att[100];
	attendance tempAtt;
	absent tempAbsent[10];

	FILE* ptr13;
	ptr13 = fopen("staffNumber.dat", "rb");
	if (ptr13 == NULL) {
		printf("Unable to open ptr13\n");
		exit(-1);
	}
	fread(&staffNum, sizeof(int), 1, ptr13);
	fclose(ptr13);


	FILE* ptr14;
	ptr14 = fopen("attendanceNum.dat", "rb");
	if (ptr14 == NULL) {
		printf("Unable to open ptr14.");
		exit(-1);
	}
	fread(&sumAtt, sizeof(int), 1, ptr14);
	fclose(ptr14);


	FILE* ptr15;
	ptr15 = fopen("attendance.dat", "rb");
	if (ptr15 == NULL) {
		printf("Unable to open ptr15.");
		exit(-1);
	}
	for (z = 0; z < sumAtt; z++) {
		fread(&att[z], sizeof(attendance), 1, ptr15);
	}
	fclose(ptr15);




	FILE* ptr12;
	ptr12 = fopen("absentNum.dat", "rb");
	if (ptr12 == NULL) {
		printf("Unable to open ptr12\n");
		exit(-1);
	}
	fread(&totalAbsent, sizeof(int), 1, ptr12);
	fclose(ptr12);

	FILE* ptr11;
	ptr11 = fopen("absent.dat", "rb");
	if (ptr11 == NULL) {
		printf("Unable to open ptr11\n");
		exit(-1);
	}
	for (j = 0; j < totalAbsent; j++) {
		fread(&absentStf[j], sizeof(absent), 1, ptr11);
	}
	fclose(ptr11);


	printf("\n\n========================================================\n");
	printf("\t\tTAKE ATTENDANCE");
	printf("\n========================================================\n\n");






	do {
		printf("Enter the Today Date(DD-MM-YYYY)   : ");
		scanf("%d-%d-%d", &tempAtt.attendanceDate.day, &tempAtt.attendanceDate.month, &tempAtt.attendanceDate.year);
	} while (validateDate(tempAtt.attendanceDate.day, tempAtt.attendanceDate.month, tempAtt.attendanceDate.year));

	printf("Enter Attendance Taking Staff Name : ");
	rewind(stdin);
	scanf("%[^\n]", tempAtt.attStfName);
	do {
		printf("Number Staff of attend Today       : ");
		scanf("%d", &tempAtt.attStaffNum);
	} while (tempAtt.attStaffNum > staffNum);
	tempAtt.totalStaffNum = staffNum;
	absentNum = staffNum - tempAtt.attStaffNum;
	for (int k = 0; k < absentNum; k++) {

		printf("\n\n ABSENT STAFF %d---> \n", k + 1);
		printf("Enter the absent staff id   : ");
		rewind(stdin);
		scanf("%s", tempAbsent[k].id);

		printf("Enter the absent staff name : ");
		rewind(stdin);
		scanf("%s", tempAbsent[k].name);
		tempAbsent[k].absentDate.day = tempAtt.attendanceDate.day;
		tempAbsent[k].absentDate.month = tempAtt.attendanceDate.month;
		tempAbsent[k].absentDate.year = tempAtt.attendanceDate.year;
	}




	printf("\n\n    <<<------- Today Attendance Situation ------->>>\n\n");
	printf("\t%-25s: %02d-%02d-%04d\n", "Date", tempAtt.attendanceDate.day, tempAtt.attendanceDate.month, tempAtt.attendanceDate.year);
	printf("\t%-25s: %s\n", "Attendance Taking Staff", tempAtt.attStfName);
	printf("\t%-25s: %d\n", "Total Staff", tempAtt.totalStaffNum);
	printf("\t%-25s: %d\n", "Attend Staff ", tempAtt.attStaffNum);
	printf("\nAbsent Staff------>>\n");
	printf("Today Absent Staff Number: %d\n\n", absentNum);
	for (m = 0; m < absentNum; m++) {

		printf("%d. Absent Staff ID   : %s\n", m + 1, tempAbsent[m].id);
		printf("   Absent Staff Name : %s\n\n", tempAbsent[m].name);

	}

	do {
		printf("Confirm today's attendance ?(Y=yes/N=no) : ");
		rewind(stdin);
		scanf("%c", &confirmAtt);
		if (confirmAtt == 'Y') {

			att[sumAtt].attendanceDate.day = tempAtt.attendanceDate.day;
			att[sumAtt].attendanceDate.month = tempAtt.attendanceDate.month;
			att[sumAtt].attendanceDate.year = tempAtt.attendanceDate.year;
			strcpy(att[sumAtt].attStfName, tempAtt.attStfName);
			att[sumAtt].totalStaffNum = tempAtt.totalStaffNum;
			att[sumAtt].attStaffNum = tempAtt.attStaffNum;

			for (int o = 0; o < absentNum; o++) {
				absentStf[totalAbsent + o].absentDate.day = tempAbsent[o].absentDate.day;
				absentStf[totalAbsent + o].absentDate.month = tempAbsent[o].absentDate.month;
				absentStf[totalAbsent + o].absentDate.year = tempAbsent[o].absentDate.year;
				strcpy(absentStf[totalAbsent + o].id, tempAbsent[o].id);
				strcpy(absentStf[totalAbsent + o].name, tempAbsent[o].name);

			}

			sumAtt++;
			totalAbsent = totalAbsent + absentNum;



			FILE* ptr18;
			ptr18 = fopen("attendance.dat", "wb");
			if (ptr18 == NULL) {
				printf("Unable to open ptr18.\n");
				exit(-1);
			}


			fwrite(&att, sizeof(att[0]), sumAtt, ptr18);
			fclose(ptr18);


			FILE* ptr19;
			ptr19 = fopen("absent.dat", "wb");
			if (ptr19 == NULL) {
				printf("Unable to open ptr19.\n");
				exit(-1);
			}
			fwrite(&absentStf, sizeof(absentStf[0]), totalAbsent, ptr19);
			fclose(ptr19);

			FILE* ptr20;
			ptr20 = fopen("attendanceNum.dat", "wb");
			if (ptr20 == NULL) {
				printf("Unable to open ptr20.\n");
				exit(-1);
			}
			fwrite(&sumAtt, sizeof(int), 1, ptr20);
			fclose(ptr20);

			FILE* ptr21;
			ptr21 = fopen("absentNum.dat", "wb");
			if (ptr21 == NULL) {
				printf("Unable to open ptr21.\n");
				exit(-1);
			}
			fwrite(&totalAbsent, sizeof(int), 1, ptr21);
			fclose(ptr21);
			printf("\n\n========================================================\n");
			printf("\t ENTER ATTENDANCE SUCCESSFULLY");
			printf("\n========================================================\n\n");
		}
		else if (confirmAtt == 'N')
			printf("You have cancel the attendance confirm.\n");
	} while (confirmAtt != 'Y' && confirmAtt != 'N');
}


void attendanceReport() {
	attendance attRe[100];
	absent absentRe[300];
	char checkSearch;

	SYSTEMTIME t;
	GetLocalTime(&t);

	int searchMonth, searchYear, totalStaff, totalAtt, totalAbsent, totalday, y, z;
	double attRate;

	FILE* ptr22;
	ptr22 = fopen("attendance.dat", "rb");
	if (!ptr22) {
		printf("Unable to open ptr22.\n");
		exit(-1);
	}
	for (z = 0; !feof(ptr22); z++) {
		fread(&attRe[z], sizeof(attendance), 1, ptr22);
	}
	fclose(ptr22);
	/*int z;
	for (z = 0; !feof(ptr2); z++) {
		if (fread(&stf[z], sizeof(staff), 1, ptr2) != 1) break;
	}*/



	FILE* ptr23;
	ptr23 = fopen("absent.dat", "rb");
	if (!ptr23) {
		printf("Unable to open ptr23.\n");
		exit(-1);
	}
	for (y = 0; !feof(ptr23); y++) {
		fread(&absentRe[y], sizeof(absent), 1, ptr23);
	}
	fclose(ptr23);

	printf("\n========================================================\n");
	printf("\t\t ATTENDANCE REPORT");
	printf("\n========================================================\n");
	printf("\n\nAttendance Report---->\n");

	do {
		printf("Enter the year of the attendance report(exp:2023) : ");
		scanf("%d", &searchYear);
		if (searchYear > t.wYear)
			printf("The attendance of this year haven't start.\n");
	} while (searchYear > t.wYear);
	do {
		printf("Enter the month of the attendance report(exp:3)   : ");
		scanf("%d", &searchMonth);
		if (searchMonth < 0 || searchMonth > 13)
			printf("Invalid Month.Please re-enter again.\n");
	} while (searchMonth < 0 || searchMonth > 13);

	printf("   ----------------------------------------------------------------------------------------------------------------\n");
	printf("   |                                          \t                                                                  |\n");
	printf("   |\t\t\t\t      <<-------Attendance Report in %02d/%04d------->>  \t                          |\n", searchMonth, searchYear);
	printf("   |                                          \t                                                                  |\n");
	printf("   |                                          \t                                                                  |\n");
	totalAtt = 0;
	totalStaff = 0;
	totalday = 0;
	checkSearch = 'X';
	for (int x = 0; x < z; x++) {
		if (attRe[x].attendanceDate.month == searchMonth && attRe[x].attendanceDate.year == searchYear) {

			totalAtt = totalAtt + attRe[x].attStaffNum;
			totalStaff = totalStaff + attRe[x].totalStaffNum;
			totalday++;
			checkSearch = 'Y';
		}
	}

	totalAbsent = totalStaff - totalAtt;
	attRate = (double)totalAtt / totalStaff * 100;
	if (checkSearch == 'X') {
		printf("   |\t\t\t\t\tDo not have attendance record in this time.\t\t\t\t  |\n");
	}

	else if (checkSearch == 'Y') {
		printf("   |\t\t\t\t\t    %-30s: %2d Day\t\t\t\t  |\n", "Total Work Day of this month", totalday);
		printf("   |\t\t\t\t\t    %-30s: %2d People\t\t\t\t  |\n", "Total Attend Staff", totalAtt);
		printf("   |\t\t\t\t\t    %-30s: %2d People\t\t\t\t  |\n", "Total Absent Staff", totalAbsent);
		printf("   |\t\t\t\t\t    %-30s: %2d People\t\t\t\t  |\n", "Total Amount Staff", totalStaff);
		printf("   |\t\t\t\t\t    %-30s: %.2f%%\t\t\t\t  |\n", "Percentage of Attendance", attRate);
		printf("   |                                          \t                                                                  |\n");
		printf("   |                                          \t                                                                  |\n");
		printf("   |\t\t\t\t      <<<=============== ABSENT LIST ===============>>>\t\t\t\t  | \n");
		printf("   |\t\t\t%-20s \t %16s \t %20s\t\t\t  |\n", "Absent Date", "Absent Staff ID", "Absent Staff Name");

		for (int w = 0; w < y; w++) {
			if (absentRe[w].absentDate.month == searchMonth && absentRe[w].absentDate.year == searchYear)
				printf("   |\t\t\t%02d-%02d-%04d \t\t %12s \t\t\t %-20s\t\t  |\n", absentRe[w].absentDate.day, absentRe[w].absentDate.month, absentRe[w].absentDate.year, absentRe[w].id, absentRe[w].name);
		}

	}
	printf("   |                                                            \t                                          |\n");
	printf("   |                                                            \t                                          |\n");
	printf("   ----------------------------------------------------------------------------------------------------------------\n\n\n");
}


int validateDate(int day, int month, int year) {
	SYSTEMTIME t; 
	GetLocalTime(&t);

	if (year > t.wYear)
		return 1;

	else if (month > 12 || month < 0)
		return 1;

	else if (day < 0)
		return 1;

	if (year % 4 == 0) {
		if (month == 2) {
			if (day > 29)
				return 1;
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) {
		if (day > 31)
			return 1;
	}
	if (month == 2) {
		if (day > 28)
			return 1;
	}
	else {
		if (day > 30)
			return 1;
	}
	return 0;
}

////STAFF PART END

////STOCK 
void stockPage() {
	product prodList[100];
	int pCount, numProducts = 0, valid = 0;
	char function = ' ';

	FILE* fptr;

	fptr = fopen("productList.txt", "r");

	if (fptr == NULL) {
		printf("Unable to open the file. Please check the file name!\n");
		exit(-1);
	}

	while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%d/%d/%d|%d|%lf|%d|%lf\n", prodList[numProducts].prodCode, prodList[numProducts].prodName, prodList[numProducts].category, &prodList[numProducts].day, &prodList[numProducts].month, &prodList[numProducts].year, &prodList[numProducts].remainStock, &prodList[numProducts].price, &prodList[numProducts].reorderList.reorderQuan, &prodList[numProducts].reorderList.totalPrice) != EOF)
	{
		numProducts++;
	}

	do {
		printf("\n\t=======================\n");
		printf("\t STOCK FUNCTION MENU\n");
		printf("\t=======================\n");
		printf("\t0.Exit\n");
		printf("\t1.Search Stock\n");
		printf("\t2.Add Stock\n");
		printf("\t3.Modify Stock\n");
		printf("\t4.Delete Stock\n");
		printf("\t5.Display Stock\n");
		printf("\t6.Reorder Stock\n");
		printf("\t=======================\n\n");

		do {
			printf("Enter Valid Selection (1-6) > ");
			scanf("%d", &valid);
			rewind(stdin);

			switch (valid) {
			case 0:
				return 0;
				break;
			case 1:
				searchProduct(prodList, numProducts);
				break;
			case 2:
				addProduct(prodList, numProducts);
				break;
			case 3:
				modify(prodList, numProducts);
				break;
			case 4:
				delete(prodList, numProducts);
				break;
			case 5:
				display(prodList, numProducts);
				break;
			case 6:
				reorder(prodList, numProducts);
				break;
			default:
				printf("Invalid selection...Please re-enter (1-6)\n\n");
			}
		} while (valid < 0 || valid>6);

		do {
			printf("Continue with another function ? (Y=YES|N=NO) > ");
			scanf("%c", &function);
			rewind(stdin);
			if (toupper(function) == 'Y');
			else if (toupper(function) == 'N') {
				fclose(fptr);
				exit(-1);
			}
			else {
				printf("Unrecognized character...Please enter valid (Y=YES|N=NO)!!!\n\n");
			}
		} while (toupper(function) != 'Y' && toupper(function) != 'N');
	} while (toupper(function) == 'Y');

	return 0;
}

void addProduct(product prodList[], int numProducts) {
	char addProdCode[10], addCategory[20], addProdName[20];
	int addRemainStock, addReorderQuan, addDay, addMonth, addYear, count = 1, pCount = 1;
	double addPrice, totalPrice = 0;
	char comfirm = ' ', another = ' ', undo = ' ', yesNo = ' ';

	printf("\n===================================\n");
	printf("|Welcome to ADD STOCK Function....|\n");
	printf("===================================\n\n");

	do {

		printf("Comfirm to add product ? (Y=YES|N=NO) > ");
		scanf("%c", &comfirm);
		rewind(stdin);
		do {
			if (toupper(comfirm) == 'Y') {
				for (int i = numProducts - 1; i < numProducts; i++) {
					printf("\n");
					printf("========================================\n");
					printf("\tADD RECORD %d\n", pCount);
					printf("========================================\n");
					printf("i)New Product Code > ");
					scanf("%[^\n]", addProdCode);
					rewind(stdin);
					strcpy(prodList[i].prodCode, addProdCode);
					printf("----------------------------------------\n");
					printf("ii)New Product Name > ");
					scanf("%[^\n]", addProdName);
					rewind(stdin);
					strcpy(prodList[i].prodName, addProdName);
					printf("----------------------------------------\n");
					printf("iii)New Product Category > ");
					scanf("%[^\n]", addCategory);
					rewind(stdin);
					strcpy(prodList[i].category, addCategory);
					printf("----------------------------------------\n");
					printf("iv)New Product Expiry Date (dd/mm/yy):\n");
					do {
						printf("Enter New Day (1-31) > ");
						scanf("%d", &addDay);
						rewind(stdin);
						prodList[i].day = addDay;
						if (addDay >= 1 && addDay <= 31) {
							do {
								printf("Enter New Month (1-12) > ");
								scanf("%d", &addMonth);
								rewind(stdin);
								prodList[i].month = addMonth;
								if (addMonth >= 1 && addMonth <= 12) {
									do {
										printf("Enter New Year > ");
										scanf("%d", &addYear);
										rewind(stdin);
										prodList[i].year = addYear;
										if (addYear < 0) {
											printf("Invalid Year...Re-enter again!!!\n\n");
										}
									} while (addYear < 0);
								}
								else {
									printf("Month must be in range of (1-12)...Re-enter again!!!\n\n");
								}
							} while (addMonth < 1 || addMonth > 12);
						}
						else {
							printf("Day must be in range of (1-31)...Re-enter again!!!\n\n");
						}
					} while (addDay < 1 || addDay > 31);
					printf("----------------------------------------\n");
					printf("v)New Product Available Stock > ");
					scanf("%d", &addRemainStock);
					prodList[i].remainStock = addRemainStock;
					rewind(stdin);
					printf("----------------------------------------\n");
					printf("vi)New Product Unit Price(RM) > ");
					scanf("%lf", &addPrice);
					prodList[i].price = addPrice;
					rewind(stdin);
					printf("----------------------------------------\n");
					addReorderQuan = 150 - prodList[i].remainStock;
					printf("vii)New Product Reorder Quantity > %d\n", addReorderQuan);
					prodList[i].reorderList.reorderQuan = addReorderQuan;
					printf("----------------------------------------\n");
					totalPrice = prodList[i].price * prodList[i].reorderList.reorderQuan;
					printf("viii)New Product Total Price > %.2lf\n", totalPrice);
					prodList[i].reorderList.totalPrice = totalPrice;
					printf("========================================\n");

					do {
						printf("\nUndo Added Stock Product? (Y=YES||N=NO) > ");
						scanf("%c", &undo);
						rewind(stdin);
						if (toupper(undo) == 'Y') {
							pCount++;
							count--;
							numProducts--;
							printf("Added Product have been deleted...Be ready to proceed!!!\n\n");
							break;
						}
						else if (toupper(undo) == 'N') {
							pCount++;
						}
						else {
							printf("Invalid character to (Undo Added Stock Product)...Please re-enter again!!!\n\n");
						}
					} while (toupper(undo) != 'N' && toupper(undo) != 'Y');

					do {
						printf("Any Other Record to ADDED ? > ");
						scanf("%c", &yesNo);
						rewind(stdin);
						if (toupper(yesNo) == 'Y') {
							numProducts++;
							count++;
						}
						else if (toupper(yesNo) == 'N') {
							FILE* ptr1;

							ptr1 = fopen("productList.txt", "a");

							if (ptr1 == NULL) {
								printf("Unable to open the file. Please check the file name!\n");
								exit(-1);
							}

							for (int j = numProducts - count; j < numProducts; j++) {
								fprintf(ptr1, "%s|%s|%s|%02d/%02d/%04d|%d|%.2lf|%d|%.2lf\n", prodList[j].prodCode, prodList[j].prodName, prodList[j].category, prodList[j].day, prodList[j].month, prodList[j].year, prodList[j].remainStock, prodList[j].price, prodList[j].reorderList.reorderQuan, prodList[j].reorderList.totalPrice);
							}

							printf("\n");
							printf("\t\t\t\t\t\t  ADDED RECORD\n");
							printf("======================================================================================================================\n");
							printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY \t EXPIRY DATE\tAVAILABLE STOCK\t  PRICE(RM)\tREORDER STOCK\n");
							printf("======================================================================================================================\n");
							for (int k = numProducts - count; k < numProducts; k++) {
								printf("%s \t\t %-20s %-18s %02d-%02d-%04d %13d %15.2lf %15d\n", prodList[k].prodCode, prodList[k].prodName, prodList[k].category, prodList[k].day, prodList[k].month, prodList[k].year, prodList[k].remainStock, prodList[k].price, prodList[k].reorderList.reorderQuan);
							}
							printf("======================================================================================================================\n");
							printf("\t\t\t\t\t     %d products have added.\n\n", count);
							fclose(ptr1);
						}
						else {
							printf("Invalid character to (Undo Other Record)...Please re-enter again!!!\n");
						}
					} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');
					break;
				}
			}
			else if (toupper(comfirm) == 'N') {
				break;
			}
			else {
				printf("Invalid character to (Comfirm to add product )...Please re-enter again!!!\n\n");
			}
		} while (toupper(yesNo) == 'Y');
	} while (toupper(comfirm) != 'Y' && toupper(comfirm) != 'N');
}

void delete(product prodList[], int numProducts) {
	char delProdCode[9];
	int i = 0, found = 0, indexToDelete = -1, success = 0, record = 1;
	char choice = ' ', sure = ' ';

	printf("\n======================================\n");
	printf("|Welcome to DELETE STOCK Function....|\n");
	printf("======================================\n\n");

	do {
		do {
			printf("Enter product code to delete > ");
			scanf("%9s", delProdCode);
			rewind(stdin);

			found = 0;
			for (i = 0; i < numProducts; i++) {
				if (strcmp(prodList[i].prodCode, delProdCode) == 0) {
					found = 1;
					printf("Product Code Found...Be Ready to Proceed!!!\n");
					break;
				}
			}

			if (!found) {
				printf("Product code not found...Please re-enter again!!!\n\n");
			}
		} while (!found);

		do {
			printf("\nSure to delete Stock Product %s ? > ", delProdCode);
			rewind(stdin);
			scanf("%c", &sure);
			rewind(stdin);

			if (toupper(sure) == 'N') {
				printf("Deletion not Completed...Please Try Again\n\n");
			}
			else if (toupper(sure) == 'Y') {
				success++;
				for (i = 0; i < numProducts; i++) {
					if (strcmp(prodList[i].prodCode, delProdCode) == 0) {
						indexToDelete = i;
						printf("Stock Product %s has successfully deleted...\n\n", delProdCode);
						break;
					}
				}
				// move the last element of the array to the index to be deleted, and then decrement numProducts
				prodList[indexToDelete] = prodList[numProducts - 1];
				(numProducts)--;

				FILE* ptr1;

				ptr1 = fopen("productList.txt", "w");

				if (ptr1 == NULL) {
					printf("Unable to open the file. Please check the file name!\n");
					exit(-1);
				}

				printf("\t\t\t\t\t    REMAINING STOCK RECORD %d \n", record++);
				printf("======================================================================================================================\n");
				printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY \t EXPIRY DATE\tAVAILABLE STOCK\t UNIT PRICE(RM)\tREORDER STOCK\n");
				printf("======================================================================================================================\n");
				for (i = 0; i < numProducts; i++) {
					printf("%s \t\t %-20s %-18s %02d-%02d-%04d %13d %15.2lf %15d\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].day, prodList[i].month, prodList[i].year, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan);
					fprintf(ptr1, "%s|%s|%s|%02d/%02d/%04d|%d|%.2lf|%d|%.2lf\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].day, prodList[i].month, prodList[i].year, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan, prodList[i].reorderList.totalPrice);
				}
				printf("======================================================================================================================\n");
				printf("\t\t\t\t\t   TOTAL OF %d STOCK REMAINING\n\n", numProducts);

				fclose(ptr1);
			}
			else {
				printf("Character Not Correct...Please re-enter (Y=YES/N=NO) !!!\n");
			}
		} while (toupper(sure) != 'Y' && toupper(sure) != 'N');

		do {
			printf("Do you want to delete another Product Stock ? (Y=YES/N=NO) > ");
			scanf("%c", &choice);
			rewind(stdin);

			if (toupper(choice) == 'Y') {
				printf("\n");
			}
			else if (toupper(choice) == 'N') {
				printf("Total %d deletion have made...Ready to Exit!!!\n", success);
				break;
			}
			else {
				printf("Character Input Error...Please re-enter (Y=YES/N=NO) !!!\n\n");
			}
		} while (toupper(choice) != 'N' && toupper(choice) != 'Y');
	} while (toupper(choice) == 'Y');
}

void display(product prodList[], int numProducts) {
	int expiryDate, current, diff, countExpired = 0, countAlmostExpired = 0, now, expiry;
	int select = 0, countNotEnough = 0, countAvailable = 0;
	char other = ' ';
	SYSTEMTIME t;
	GetLocalTime(&t);

	printf("\n=======================================\n");
	printf("|Welcome to DISPLAY STOCK Function....|\n");
	printf("=======================================\n\n");

	do {
		printf("\n\t=====================\n");
		printf("\t  DISPLAY SELECTION\n");
		printf("\t=====================\n");
		printf("\t1.EXPIRY STOCK\n");
		printf("\t2.ALMOST EXIPRY STOCK\n");
		printf("\t3.NOT ENOUGH STOCK\n");
		printf("\t4.AVAILABLE STOCK\n");
		printf("\t=====================\n\n");

		do {
			printf("Choose Your Selection (1-4) > ");
			scanf("%d", &select);
			rewind(stdin);

			switch (select) {
			case 1:
				printf("\n");
				printf("\t\t       EXPIRED PRODUCTS LIST - as at %02d-%02d-%d\n", t.wDay, t.wMonth, t.wYear);
				printf("======================================================================================\n");
				printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY\tEXPIRED(DAYS)     EXPIRY DATE \n");
				printf("======================================================================================\n");
				for (int i = 0; i < numProducts; i++) {
					expiryDate = monthcount(prodList[i].day, prodList[i].month, prodList[i].year);
					current = monthcount(t.wDay, t.wMonth, t.wYear);
					diff = current - expiryDate;

					if (expiryDate < current) {
						printf("%s \t\t %-20s %-18s %5d AGO \t  %02d-%02d-%04d\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, diff, prodList[i].day, prodList[i].month, prodList[i].year);
						countExpired++;
					}
				}
				printf("======================================================================================\n");
				printf("\t\t\t  Total %d products stock EXPIRED !!!\n", countExpired);
				break;
			case 2:
				printf("\n");
				printf("\t\t       ALMOST EXPIRED PRODUCTS LIST - as at %02d-%02d-%d\n", t.wDay, t.wMonth, t.wYear);
				printf("======================================================================================\n");
				printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY \t  EXPIRED ON \t EXPIRY DATE \n");
				printf("======================================================================================\n");
				for (int i = 0; i < numProducts; i++) {
					expiry = monthcount(prodList[i].day, prodList[i].month, prodList[i].year);
					now = monthcount(t.wDay, t.wMonth, t.wYear);

					if ((expiry - now) >= 1 && (expiry - now) <= 5) {
						printf("%s \t\t %-20s %-18s %4d DAY \t  %02d-%02d-%04d\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, expiry - now, prodList[i].day, prodList[i].month, prodList[i].year);
						countAlmostExpired++;
					}
				}
				printf("======================================================================================\n");
				printf("\t\t\t  Total %d products stock ALMOST EXPIRED !!!\n", countAlmostExpired);
				break;
			case 3:
				printf("\n");
				printf("\t\t\t\t       NOT ENOUGH PRODUCTS LIST\n");
				printf("=======================================================================================================\n");
				printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY \tAVAILABLE STOCK (MIN : 150)     REORDER STOCK\n");
				printf("=======================================================================================================\n");
				for (int i = 0; i < numProducts; i++) {
					if (prodList[i].remainStock < 150) {
						printf("%s \t\t %-20s %-10s %12d (REQUIRED : %03d) %16d\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].remainStock, 150 - prodList[i].remainStock, prodList[i].reorderList.reorderQuan);
						countNotEnough++;
					}
				}
				printf("=======================================================================================================\n");
				printf("\t\t\t\t  Total %d products stock NOT ENOUGH !!!\n", countNotEnough);
				break;
			case 4:
				printf("\n");
				printf("\t\t\t\t\t\tAVAILABLE STOCK LIST\n");
				printf("======================================================================================================================\n");
				printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY\tEXPIRY DATE\tAVAILABLE STOCK\t UNIT PRICE(RM)\t REORDER STOCK\n");
				printf("======================================================================================================================\n");
				for (int z = 0; z < numProducts; z++) {
					printf("%s \t\t %-20s %-18s %02d-%02d-%04d %13d %15.2lf %15d\n", prodList[z].prodCode, prodList[z].prodName, prodList[z].category, prodList[z].day, prodList[z].month, prodList[z].year, prodList[z].remainStock, prodList[z].price, prodList[z].reorderList.reorderQuan);
					countAvailable++;
				}
				printf("======================================================================================================================\n");
				printf("\t\t\t\t\tTotal %d products have recorded.\n", countAvailable);
				break;
			default:
				printf("Invalid selection to display...Re-enter Again!!!\n\n");
			}
		} while (select < 1 || select > 4);

		do {
			printf("\nDisplay Other to View ? (Y=YES|N=NO) > ");
			scanf("%c", &other);
			rewind(stdin);
			if (toupper(other) == 'Y') {
				countNotEnough -= countNotEnough;
				countAvailable -= countAvailable;
				countAlmostExpired -= countAlmostExpired;
				countExpired -= countExpired;
			}
			else if (toupper(other) == 'N') {
				break;
			}
			else {
				printf("Invalid Character to View...Please re-enter again!!!\n");
			}
		} while (toupper(other) != 'Y' && toupper(other) != 'N');
	} while (toupper(other) == 'Y');
}

void modify(product prodList[], int numProducts) {
	char searchCategory[20], searchCode[10], modiProdCode[10], modiProdName[20], modiProdCategory[20], oldCategory[20], oldProdCode[10], oldProdName[20];
	double modiProdPrice, oldPrice;
	char yesNo = ' ', another = ' ', undo = ' ', next = ' ';
	int modiRemainStock, modiRedorderQuan, modiDay, modiMonth, modiYear, found = 0, i = 0, select = 0, change = 0, oldReorderQuan, oldRemainStock, oldDay, oldMonth, oldYear;

	printf("\n======================================\n");
	printf("|Welcome to MODIFY STOCK Function....|\n");
	printf("======================================\n\n");

	do {
		printf("Enter Product Category to Modify > ");
		scanf("%[^\n]", searchCategory);
		rewind(stdin);

		printf("Enter Product Code to Modify > ");
		scanf("%s", searchCode);
		rewind(stdin);

		found = 0; // Set found to 0 before searching for the product

		for (i = 0; i < numProducts; i++) {
			if (strcmp(prodList[i].category, searchCategory) == 0 && strcmp(prodList[i].prodCode, searchCode) == 0) {
				strcpy(oldProdCode, prodList[i].prodCode);
				strcpy(oldProdName, prodList[i].prodName);
				strcpy(oldCategory, prodList[i].category);
				oldDay = prodList[i].day;
				oldMonth = prodList[i].month;
				oldYear = prodList[i].year;
				oldRemainStock = prodList[i].remainStock;
				oldPrice = prodList[i].price;
				found = 1;

				printf("\n");

				printf("\t=======================\n");
				printf("\t Modify List Selection\n");
				printf("\t=======================\n");
				printf("\t1.Product Code\n");
				printf("\t2.Product Name\n");
				printf("\t3.Product Category\n");
				printf("\t4.Expiry Date (dd/mm/yy)\n");
				printf("\t5.Remaining Stock\n");
				printf("\t6.Unit Price\n");
				printf("\t=======================\n\n");

				do {
					printf("Continue to Modify? (Y=Yes/N=No) > ");
					scanf("%c", &yesNo);
					rewind(stdin);

					if (toupper(yesNo) == 'Y') {
						do {
							do {
								printf("\n");
								printf("Enter Your Selection > ");
								scanf("%d", &select);
								rewind(stdin);
								switch (select) {
								case 1:
									printf("Enter New Product Code to Modify > ");
									scanf("%[^\n]", modiProdCode);
									rewind(stdin);
									strcpy(prodList[i].prodCode, modiProdCode);
									break;
								case 2:
									printf("Enter New Product Name to Modify > ");
									scanf("%[^\n]", modiProdName);
									rewind(stdin);
									strcpy(prodList[i].prodName, modiProdName);
									break;
								case 3:
									printf("Enter New Product Category to Modify > ");
									scanf("%[^\n]", modiProdCategory);
									rewind(stdin);
									strcpy(prodList[i].category, modiProdCategory);
									break;
								case 4:
									printf("\n");
									printf("Modify New Exipry Date :\n");
									do {
										printf("Enter New Day (1-31) > ");
										scanf("%d", &modiDay);
										rewind(stdin);
										if (modiDay >= 1 && modiDay <= 31) {
											do {
												printf("Enter New Month > ");
												scanf("%d", &modiMonth);
												rewind(stdin);
												if (modiMonth >= 1 && modiMonth <= 12) {
													do {
														printf("Enter New Year > ");
														scanf("%d", &modiYear);
														rewind(stdin);
														if (modiYear < 0) {
															printf("Invalid Year...Re-enter again!!!\n\n");
														}
													} while (modiYear < 0);
												}
												else {
													printf("Month must be in range of (1-12)...Re-enter again!!!\n\n");
												}
											} while (modiMonth < 1 || modiMonth > 12);
										}
										else {
											printf("Day must be in range of (1-31)...Re-enter again!!!\n\n");
										}
									} while (modiDay < 1 || modiDay > 31);
									prodList[i].day = modiDay;
									prodList[i].month = modiMonth;
									prodList[i].year = modiYear;
									break;
								case 5:
									printf("Enter New Remaining Stock to Modify > ");
									scanf("%d", &modiRemainStock);
									rewind(stdin);
									prodList[i].remainStock = modiRemainStock;
									break;
								case 6:
									printf("Enter New Product Price to Modify > ");
									scanf("%lf", &modiProdPrice);
									prodList[i].price = modiProdPrice;
									rewind(stdin);
									break;
								default:
									printf("Invalid selection! Please select the correct option (1-6)\n\n");
								}
							} while (select < 1 || select > 6);

							printf("\nDo you want to modify another field? (Y=Yes/N=No) > ");
							scanf("%c", &next);
							rewind(stdin);
							change++;
						} while (toupper(next) == 'Y');

						do {
							printf("Confirm Modify Product Code %s ? (Y=Yes/N=No) > ", searchCode);
							rewind(stdin);
							scanf("%c", &undo);
							rewind(stdin);
							if (toupper(undo) == 'Y') {
							}
							else if (toupper(undo) == 'N') {
								strcpy(prodList[i].prodCode, oldProdCode);
								strcpy(prodList[i].prodName, oldProdName);
								strcpy(prodList[i].category, oldCategory);
								prodList[i].day = oldDay;
								prodList[i].month = oldMonth;
								prodList[i].year = oldYear;
								prodList[i].remainStock = oldRemainStock;
								prodList[i].price = oldPrice;
								change = 0;
							}
							else {
								printf("Invalid character to Undo...Re-enter again!!!\n\n");
							}
							FILE* ptr1;

							ptr1 = fopen("productList.txt", "w");

							if (ptr1 == NULL) {
								printf("Unable to open the file. Please check the file name!\n");
								exit(-1);
							}

							printf("\n");
							printf("\t\t\t\t\t\tUpdated Record\n");
							printf("======================================================================================================================\n");
							printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY    EXPIRY DATE    AVAILABLE STOCK\tUNIT PRICE(RM)\t REORDER STOCK\n");
							printf("======================================================================================================================\n");
							printf("%s \t\t %-20s %-15s %02d-%02d-%04d %13d %15.2lf %15d\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].day, prodList[i].month, prodList[i].year, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan);
							printf("======================================================================================================================\n");
							printf("\t\t\tProduct code %s (%s) has made %d modification.\n\n", searchCode, prodList[i].prodName, change);

							for (i = 0; i < numProducts; i++)
							{
								fprintf(ptr1, "%s|%s|%s|%02d/%02d/%04d|%d|%.2lf|%d|%.2lf\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].day, prodList[i].month, prodList[i].year, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan, prodList[i].reorderList.totalPrice);
							}
							fclose(ptr1);
						} while (toupper(undo) != 'Y' && toupper(undo) != 'N');
					}
					else if (toupper(yesNo) == 'N') {
					}
					else {
						printf("Invalid character to (Continue to Modify?)...Re-enter again!!!\n\n");
					}
				} while (toupper(yesNo) != 'N' && toupper(yesNo) != 'Y');

				if (change > 0) {
					printf("Modification completed successfully!\n\n");
				}
				else {
					printf("Modification was not completed!\n\n");
				}
				break;
			}
		}
		if (!found) {
			printf("Product not found. Please re-enter again!!!\n\n");
		}

		do {
			printf("Do you want to modify another product? (Y=Yes/N=No) > ");
			scanf("%c", &another);
			rewind(stdin);

			if (toupper(another) == 'Y') {
				printf("\n");
			}
			else if (toupper(another) == 'N') {
			}
			else {
				printf("Invalid selection to (Modify Another Product?)...Re-enter again!!!\n\n");
			}
		} while (toupper(another) != 'Y' && toupper(another) != 'N');
	} while (toupper(another) == 'Y');
}

void searchProduct(product prodList[], int numProducts) {
	char searchProdCode[10], viewCategory[20];
	int i = 0, count = 1, selection = 0, found = 0, k = 0, pCount = 0;
	char another = ' ', anotherSearch = ' ', search = ' ';

	printf("\n======================================\n");
	printf("|Welcome to SEARCH STOCK Function....|\n");
	printf("======================================\n\n");

	do {
		printf("\n\t=====================\n");
		printf("\t SEARCH SELECTION\n");
		printf("\t=====================\n");
		printf("\t1.STOCK DETAILS\n");
		printf("\t2.CATEGORY\n");
		printf("\t=====================\n\n");

		do {
			printf("Please Choose Your Selection > ");
			scanf("%d", &selection);
			rewind(stdin);

			if (selection == 1) {
				do {
					do {
						printf("Enter Product Code to Search: ");
						scanf("%s", searchProdCode);
						rewind(stdin);
						found = 0;

						for (i = 0; i < numProducts; i++) {
							if (strcmp(searchProdCode, prodList[i].prodCode) == 0) {
								found = 1;
								printf("Product Found!\n\n");
								printf("\t\tSTOCK DETAILS %d\n", count);
								printf("====================================================\n");
								printf("PRODUCT CODE             : %s\n", prodList[i].prodCode);
								printf("PRODUCT NAME             : %s\n", prodList[i].prodName);
								printf("PRODUCT CATEGORY         : %s\n", prodList[i].category);
								printf("PRODUCT EXPIRY DATE      : %d/%d/%d\n", prodList[i].day, prodList[i].month, prodList[i].year);
								printf("PRODUCT AVAILABLE STOCK  : %d\n", prodList[i].remainStock);
								printf("PRODUCT UNIT PRICE       : RM %.2lf\n", prodList[i].price);
								printf("PRODUCT REORDER QUANTITY : %d\n", prodList[i].reorderList.reorderQuan);
								printf("====================================================\n");
								break;
							}
						}
						if (!found) {
							printf("Product Not Found...Re-enter again!!!\n");
						}
						printf("\n");
					} while (!found);

					do {
						printf("View another Product Stock Details ? (Y=Yes|N=No) > ");
						scanf("%c", &another);
						rewind(stdin);
						if (toupper(another) == 'Y') {
							count++;
						}
						else if (toupper(another) == 'N') {
							printf("\n");
						}
						else {
							printf("Invalid character to (Search for another Product)...Re-enter(Y=Yes|N=No)!!!\n\n");
						}
					} while (toupper(another) != 'Y' && toupper(another) != 'N');
				} while (toupper(another) == 'Y');
			}

			else if (selection == 2) {
				do {
					do {
						printf("\nEnter Product Category to View > ");
						scanf(" %19[^\n]", viewCategory);
						rewind(stdin);

						found = 0;
						for (k = 0; k < numProducts; k++) {
							if (strcmp(prodList[k].category, viewCategory) == 0) {
								found = 1;
							}
						}

						if (!found) {
							printf("Product code not found...Please re-enter again!!!\n");
						}
					} while (!found);

					printf("\t\t\t\t\t\t%s STOCK LIST\n", viewCategory);
					printf("======================================================================================================================\n");
					printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY\tEXPIRY DATE\tAVAILABLE STOCK\t UNIT PRICE(RM)\t REORDER STOCK\n");
					printf("======================================================================================================================\n");
					for (k = 0; k < numProducts; k++) {
						if (strcmp(prodList[k].category, viewCategory) == 0) {
							found = 1;
							printf("%s \t\t %-20s %-18s %02d-%02d-%04d %13d %15.2lf %15d\n", prodList[k].prodCode, prodList[k].prodName, prodList[k].category, prodList[k].day, prodList[k].month, prodList[k].year, prodList[k].remainStock, prodList[k].price, prodList[k].reorderList.reorderQuan);
							pCount++;
						}
					}
					printf("======================================================================================================================\n");
					printf("\t\t\t\t\tTotal of %d %s Products Stock Listed...\n\n", pCount, viewCategory);

					do {
						printf("View Another Category of Stock List ? (Y=YES|N=NO) > ");
						scanf("%c", &anotherSearch);
						rewind(stdin);
						if (toupper(anotherSearch) == 'Y') {
							pCount -= pCount;
							printf("\n");
						}
						else if (toupper(anotherSearch) == 'N') {
							printf("\n");
						}
						else {
							printf("Invalid character to (Search for another Category)...Re-enter(Y=Yes|N=No)!!!\n\n");
						}
					} while (toupper(anotherSearch) != 'Y' && toupper(anotherSearch) != 'N');
				} while (toupper(anotherSearch) == 'Y');
			}

			else {
				printf("Invalid input, please enter a valid selection (1-2)\n\n");
			}
		} while (selection < 1 || selection > 2);

		do {
			printf("Continue Search ? (Y=YES|N=NO) > ");
			scanf("%c", &search);
			rewind(stdin);
			if (toupper(search) == 'Y');
			else if (toupper(search) == 'N') {
				break;
			}
			else {
				printf("Invalid Character to (Continue Search)...Please input (Y=YES|N=NO)\n\n");
			}
		} while (toupper(search) != 'Y' && toupper(search) != 'N');
	} while (toupper(search) == 'Y');
}

int monthcount(int day, int month, int year)
{
	int daysInMonth[] = { 31, 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDays = day; // add days in current month
	for (int i = 0; i < month - 1; i++) {
		totalDays += daysInMonth[i]; // add days in previous months
	}
	//add days in previous years
	for (int y = 1; y < year; y++) {
		totalDays += 365 + ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
	}
	return totalDays;
}

void reorder(product prodList[], int numProducts) {
	int supplier, found = 0, k, count = 0, countReorder = 0, totalReorderQuan = 0, reorderQuan = 0, newReorder = 0, newTotalReorderQuan = 0, oldReorder = 0;
	char category[20], supplierName[30];
	double totalPrice = 0, unitPrice = 0, newPrice = 0, newTotalPrice = 0;
	char more = ' ', another = ' ';

	printf("\n=======================================\n");
	printf("|Welcome to REORDER STOCK Function....|\n");
	printf("=======================================\n\n");

	do {
		printf("Enter Category to Reorder > ");
		scanf("%s", category);
		rewind(stdin);

		found = 0;
		for (k = 0; k < numProducts; k++) {
			if (strcmp(prodList[k].category, category) == 0) {
				found = 1;
				break;
			}
		}

		if (found) {
			printf("\n\t\t\t    %s STOCK LIST\n", category);
			printf("==========================================================================\n");
			printf("PRODUCT CODE \t PRODUCT NAME \t  PRODUCT CATEGORY \t AVAILABLE STOCK\n");
			printf("==========================================================================\n");
			for (k = 0; k < numProducts; k++) {
				if ((strcmp(prodList[k].category, category) == 0) && (prodList[k].remainStock < 150)) {
					printf("%s \t\t %-20s %-15s %3d (REQUIRED : %02d)\n", prodList[k].prodCode, prodList[k].prodName, prodList[k].category, prodList[k].remainStock, 150 - prodList[k].remainStock);
					count++;
				}
			}
			printf("==========================================================================\n");
			printf("Total %d Product Stock NOT ENOUGH...Please Reorder As Soon As Possible!!!\n\n", count);

			if (strcmp(category, "FRUIT") == 0) {
				printf("\t\t\t============================\n");
				printf("\t\t\t    FRUIT Supplier List\n");
				printf("\t\t\t============================\n");
				printf("\t\t\t1.Bloor Fruit Market \n");
				printf("\t\t\t2.Opera Fruit Shop\n");
				printf("\t\t\t3.Organic Magic\n");
				printf("\t\t\t============================\n\n");

				do {
					printf("Choose Your Supplier (1-3) > ");
					scanf("%d", &supplier);
					rewind(stdin);
					switch (supplier) {
					case 1:
						strcpy(supplierName, "Bloor Fruit Market");
						break;
					case 2:
						strcpy(supplierName, "Opera Fruit Shop");
						break;
					case 3:
						strcpy(supplierName, "Organic Magic");
						break;
					default:
						printf("Invalid supplier selection.\n");
						continue;
					}
				} while (supplier < 1 || supplier>3);
			}

			if (strcmp(category, "DRINK") == 0) {
				printf("\t\t\t============================\n");
				printf("\t\t\t    DRINK Supplier List\n");
				printf("\t\t\t============================\n");
				printf("\t\t\t1.Cool Fizzy Enterprise \n");
				printf("\t\t\t2.Spark Drinks\n");
				printf("\t\t\t3.Thirsty Delight\n");
				printf("\t\t\t============================\n\n");

				do {
					printf("Choose Your Supplier (1-3) > ");
					scanf("%d", &supplier);
					rewind(stdin);
					switch (supplier) {
					case 1:
						strcpy(supplierName, "Cool Fizzy Enterprise");
						break;
					case 2:
						strcpy(supplierName, "Spark Drinks");
						break;
					case 3:
						strcpy(supplierName, "Thirsty Delight");
						break;
					default:
						printf("Invalid supplier selection.\n");
						continue;
					}
				} while (supplier < 1 || supplier>3);
			}

			if (strcmp(category, "SEAFOOD") == 0) {
				printf("\t\t\t============================\n");
				printf("\t\t\t   SEAFOOD Supplier List\n");
				printf("\t\t\t============================\n");
				printf("\t\t\t1.Monica Seafood \n");
				printf("\t\t\t2.Joe Patti's Seafood\n");
				printf("\t\t\t3.Fisherman's Express\n");
				printf("\t\t\t============================\n\n");

				do {
					printf("Choose Your Supplier (1-3) > ");
					scanf("%d", &supplier);
					rewind(stdin);
					switch (supplier) {
					case 1:
						strcpy(supplierName, "Monica Seafood");
						break;
					case 2:
						strcpy(supplierName, "Joe Patti's Seafood");
						break;
					case 3:
						strcpy(supplierName, "Fisherman's Express");
						break;
					default:
						printf("Invalid supplier selection.\n");
						continue;
					}
				} while (supplier < 1 || supplier>3);
			}

			printf("\t\t\t\t\tREORDER %s LIST (less than 150)\n", category);
			printf("==================================================================================================================\n");
			printf("\t\t\t\t\t%s SUPPLIER : %s\n", category, supplierName);
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("PRODUCT CODE \t PRODUCT NAME \t    AVAILABLE STOCK\tUNIT PRICE(RM)      REORDER STOCK \t  TOTAL PRICE(RM)\n");
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			for (int i = 0; i < numProducts; i++) {
				if (strcmp(prodList[i].category, category) == 0 && prodList[i].remainStock < 150) {
					oldReorder = 150 - prodList[i].remainStock;
					prodList[i].reorderList.reorderQuan = oldReorder;
					unitPrice = prodList[i].price * prodList[i].reorderList.reorderQuan;
					prodList[i].reorderList.totalPrice = unitPrice;
					printf("%s \t\t %-20s %8d %18.2lf %20d %20.2lf\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan, prodList[i].reorderList.totalPrice);
					totalPrice += unitPrice;
					totalReorderQuan += oldReorder;
					countReorder++;
				}
			}
			printf("=====================================================================---------------------------------------------\n");
			printf("                                                                     TOTAL :       %3d              %7.2lf \n", totalReorderQuan, totalPrice);
			printf("                                                                     =============================================\n");
			FILE* fptr;

			fptr = fopen("productList.txt", "w");

			if (fptr == NULL) {
				printf("Unable to open the file. Please check the file name!\n");
				exit(-1);
			}
			for (int i = 0; i < numProducts; i++) {
				fprintf(fptr, "%s|%s|%s|%02d/%02d/%04d|%d|%.2lf|%d|%.2lf\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].category, prodList[i].day, prodList[i].month, prodList[i].year, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan, prodList[i].reorderList.totalPrice);
			}
			fclose(fptr);

			do {
				printf("Reorder More Quantity ? (Y=YES|N=N0) > ");
				scanf("%c", &more);
				rewind(stdin);

				if (toupper(more) == 'Y') {
					for (k = 0; k < numProducts; k++) {
						if (strcmp(prodList[k].category, category) == 0 && prodList[k].remainStock < 150) {
							reorderQuan = 150 - prodList[k].remainStock;
							do {
								printf("\nEnter New Reorder Quantity for %s > ", prodList[k].prodCode);
								scanf("%d", &newReorder);
								rewind(stdin);
								if (newReorder < reorderQuan) {
									printf("Reorder Quantity Not Enough...Please set a new quantity\n");
								}
							} while (newReorder < reorderQuan);
							prodList[k].reorderList.totalPrice = newReorder * prodList[k].price;
							prodList[k].reorderList.reorderQuan = newReorder;
						}
					}
					FILE* fptr;

					fptr = fopen("productList.txt", "w");

					if (fptr == NULL) {
						printf("Unable to open the file. Please check the file name!\n");
						exit(-1);
					}

					for (k = 0; k < numProducts; k++) {
						fprintf(fptr, "%s|%s|%s|%02d/%02d/%04d|%d|%.2lf|%d|%.2lf\n", prodList[k].prodCode, prodList[k].prodName, prodList[k].category, prodList[k].day, prodList[k].month, prodList[k].year, prodList[k].remainStock, prodList[k].price, prodList[k].reorderList.reorderQuan, prodList[k].reorderList.totalPrice);
					}

					fclose(fptr);

					printf("\n\t\t\t\t\tUPDATED REORDER %s LIST\n", category);
					printf("==================================================================================================================\n");
					printf("\t\t\t\t\t%s SUPPLIER : %s\n", category, supplierName);
					printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("PRODUCT CODE \t PRODUCT NAME \t    AVAILABLE STOCK\tUNIT PRICE(RM)      REORDER STOCK \t  TOTAL PRICE(RM)\n");
					printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					for (int i = 0; i < numProducts; i++) {
						if (strcmp(prodList[i].category, category) == 0 && prodList[i].remainStock < 150) {
							printf("%s \t\t %-20s %8d %18.2lf %20d %20.2lf\n", prodList[i].prodCode, prodList[i].prodName, prodList[i].remainStock, prodList[i].price, prodList[i].reorderList.reorderQuan, prodList[i].reorderList.totalPrice);
							newTotalPrice += prodList[i].reorderList.totalPrice;
							newTotalReorderQuan += prodList[i].reorderList.reorderQuan;
						}
					}
					printf("=====================================================================---------------------------------------------\n");
					printf("                                                                     TOTAL :       %3d              %7.2lf \n", newTotalReorderQuan, newTotalPrice);
					printf("                                                                     =============================================\n");
					printf("Reorder For %s Successfully...Thank You!!!\n\n", category);
				}

				else if (toupper(more) == 'N') {
					printf("Reorder For %s Successfully...Thank You!!!\n\n", category);
				}
				else {
					printf("Invalid character to (Reorder More Quantity)...Please re-enter (Y=YES|N=N0) only!!!\n\n");
				}
			} while (toupper(more) != 'Y' && toupper(more) != 'N');
		}

		else {
			printf("Category not found. Please re-enter.\n\n");
		}
		do {
			printf("Continue Reorder ? (Y=YES|N=NO) > ");
			scanf("%c", &another);
			rewind(stdin);
			if (toupper(another) == 'Y') {
				totalPrice = 0;
				totalReorderQuan = 0;
				newTotalReorderQuan = 0;
				newTotalPrice = 0;
			}
			else if (toupper(another) == 'N') {
				break;
			}
			else {
				printf("Character not valid...Please re-enter (Y=YES|N=NO)\n\n");
			}
		} while (toupper(another) != 'Y' && toupper(another) != 'N');
	} while (toupper(another) == 'Y');
}

////END STOCK

////SALES AND ORDER
void salesAndOrderPage() {
	int option, exit = 0;
	do {
		printf("\n");
		printf("                                <<------------| SALES SYSTEM |------------>>\n");
		printf("                                       ============================\n");
		printf("                                       | 1. Display Product       |\n");
		printf("                                       | 2. Search Product        |\n");
		printf("                                       | 3. Add Order             |\n");
		printf("                                       | 4. Modify Order          |\n");
		printf("                                       | 5. Delete Order          |\n");
		printf("                                       | 6. Search Order          |\n");
		printf("                                       | 7. Make Payment          |\n");
		printf("                                       | 8. Sales                 |\n");
		printf("                                       | 9. Exit                  |\n");
		printf("                                       ============================\n");
		printf("                                       Select your option: ");
		rewind(stdin);
		scanf("%d", &option);

		switch (option) {
		case 1:
			displayProduct();
			break;
		case 2:
			searchItems();
			break;
		case 3:
			addOrder();
			break;
		case 4:
			modifyOrder();
			break;
		case 5:
			deleteOrdered();
			break;
		case 6:
			searchOrder();
			break;
		case 7:
			payment();
			break;
		case 8:
			sales();
			break;
		case 9:
			exit = 9;
			break;
		default:
			printf("Please enter the correct number (1 to 9).....\n\n");
		}

	} while (exit != 9);
}

void displayProduct() {
	FILE* fproduct;
	char code[8], name[15];
	double price;


	fproduct = fopen("Product.txt", "r");
	if (fproduct == NULL) {
		printf("openin file errors");
		exit(-1);
	}
	printf("\n");
	printf("                           <<------------| ORDER DISPLAY |------------>>\n");
	printf("\n==============================================================================================\n");
	printf("|                             ( N=Normal B=Broze S=Silver G=Gold )                           |\n");
	printf("|Item Code\tItem Name\tN member\tB Member 5%%\tS Member 15%%\tG Member 25%% |\n");
	printf("==============================================================================================\n");
	for (int i = 0; i < 10; i++)
		while (fscanf(fproduct, "%[^\|]|%[^\|]|RM%lf\n", &code, &name, &price) != EOF) {
			printf("|%-15s %-15s RM%-10.2f\tRM%-11.2f\tRM%-11.2f\tRM%-11.2f|\n", code, name, price, price * 0.95, price * 0.85, price * 0.75);
		}
	printf("==============================================================================================\n");
	printf("\n");
	fclose(fproduct);
}


void searchItems() {
	Item items[10];
	char input_code[6];
	int num_items = 0;
	char sure;
	int found = 0;

	FILE* fp = fopen("Product.txt", "r");
	if (fp == NULL) {
		printf("Error: Unable to open file.\n");
		return 1;
	}

	// Read the items from the file
	while (fscanf(fp, "%5s|%19[^|]|RM%lf\n", items[num_items].code, items[num_items].name, &items[num_items].price) != EOF) {
		num_items++;
		if (num_items == 10) {
			break;
		}
	}

	fclose(fp);
	do {
		printf("\n");
		printf("Enter the Product code: ");
		scanf("%s", input_code);
		printf("                                       ============================\n");
		// Search for the item with the given code
		for (int i = 0; i < num_items; i++) {
			if (strcmp(items[i].code, input_code) == 0) {
				found = 1;
				printf("                                       Item found!!!!\n\n");
				printf("                                       Item Code: %s\n                                       Product: %s\n                                       Normal Price: RM%.2f\n", items[i].code, items[i].name, items[i].price);
			}
		}
		printf("                                       ============================\n\n");
		if (found == 0) {
			printf("Item not found.\n\n");
		}
		printf("Search another Product? (Y=yes, N=no)");
		rewind(stdin);
		scanf("%c", &sure);
	} while (toupper(sure) == 'Y');

}


void addOrder() {
	FILE* fadd, * fpro, * fdisplay;
	int num_items = 0;
	Item item[10];
	Add add;
	char order, confirm, itemName[20];
	double prize = 0;
	int i = 0;
	int found = 0;
	char code[8], name[15];
	double price;
	char another;

	fadd = fopen("Orders.txt", "a");
	if (fadd == NULL) {
		printf("opening file errors");
		return;
	}

	fpro = fopen("Product.txt", "r");
	if (fpro == NULL) {
		printf("Opening file errors");
		return;
	}
	fdisplay = fopen("Product.txt", "r");
	if (fdisplay == NULL) {
		printf("Opening file errors");
		return;
	}
	printf("\n==============================================================================================\n");
	printf("|                             ( N=Normal B=Broze S=Silver G=Gold )                           |\n");
	printf("|Item Code\tItem Name\tN member\tB Member 5%%\tS Member 15%%\tG Member 25%% |\n");
	printf("==============================================================================================\n");
	for (int i = 0; i < 10; i++)
		while (fscanf(fdisplay, "%[^\|]|%[^\|]|RM%lf\n", &code, &name, &price) != EOF) {
			printf("|%-15s %-15s RM%-10.2f\tRM%-11.2f\tRM%-11.2f\tRM%-11.2f|\n", code, name, price, price * 0.95, price * 0.85, price * 0.75);
		}
	printf("==============================================================================================\n");
	fclose(fdisplay);

	while (fscanf(fpro, "%[^|]|%[^|]|RM%lf\n", item[num_items].code, item[num_items].name, &item[num_items].price) != EOF) {
		num_items++;
	}
	printf("\n");
	printf("Do yo want to order? (Y=yes, N=no) ");
	rewind(stdin);
	scanf("%c", &order);

	while (toupper(order) == 'Y') {

		printf("Please Enter your Name: ");
		rewind(stdin);
		scanf("%[^\n]", add.name);



		do {
			printf("Enter your Member Type (N=normal, B=Bronze, S=Silver, G=Gold): ");
			rewind(stdin);
			scanf("%c", &add.memType);
		} while (add.memType != 'N' && add.memType != 'B' && add.memType != 'S' && add.memType != 'G');

		
		do {
			do {
				printf("Enter Item Code:");
				rewind(stdin);
				scanf("%[^\n]", &add.code);
				for (i = 0; i < num_items; i++) {
					if (strcmp(item[i].code, add.code) == 0) {
						found = 1;
						if (add.memType == 'N') {
							add.price = item[i].price;
						}
						else if (add.memType == 'B') {
							add.price = item[i].price * 0.95;
						}
						else if (add.memType == 'S') {
							add.price = item[i].price * 0.85;
						}
						else if (add.memType == 'G') {
							add.price = item[i].price * 0.75;
						}
						strcpy(add.orderName, item[i].name);
					}
				}
				if (found == 0) {
					printf("Please Re-enter the item code correctly...\n");
				}


				if (i == 11) {
					printf("Item not found!\n\n");
					return 0;
				}

				printf("------------------------\n");
				printf("Item Name: %s\n", add.orderName);
				printf("Normal Price: %.2f\n", add.price);

				printf("Enter Quantity: ");
				rewind(stdin);
				scanf("%d", &add.quantity);
			} while (found == 0);

			

			add.price *= add.quantity;
			printf("------------------------\n");
			printf("Payment for this Product: %.2f\n", add.price);
			printf("------------------------\n");

			printf("Confirm Orders? (Y=yes, N=no): ");
			rewind(stdin);
			scanf("%c", &confirm);
			if (toupper(confirm) == 'Y') {
				fprintf(fadd, "Name: %s\n", add.name);
				fprintf(fadd, "Type of Member: %c\n", add.memType);
				fprintf(fadd, "Item Ordered: %s\n", add.orderName);
				fprintf(fadd, "Total Purchase: %.2f\n\n", add.price);
				printf("========================\n");
				printf("|   sucessful added!!  |\n");
				printf("========================\n");
			}
			printf("\n");
			printf("Add another item?(Y=yes, N=no) ");
			rewind(stdin);
			scanf("%c", &another);

		} while (another == 'Y');
		



		
		printf("Do yo want to order more with another Name? (Y=yes, N=no) ");
		rewind(stdin);
		scanf("%c", &order);

	}
	fclose(fadd);
	fclose(fpro);
}


void modifyOrder() {
	FILE* fordered, * fpro, * fmodi;
	char ans;
	Item item[10];
	int num_items = 0;
	char newItemCode[20];
	Add modi[20];
	int count = 0;
	char name[20];
	char sure;

	fordered = fopen("Orders.txt", "r");
	if (fordered == NULL) {
		printf("opening file errros..!\n");
		return;
	}

	fpro = fopen("Product.txt", "r");
	if (fpro == NULL) {
		printf("Opening file errors");
		return;
	}


	while (fscanf(fpro, "%[^|]|%[^|]|RM%lf\n", item[num_items].code, item[num_items].name, &item[num_items].price) != EOF) {
		num_items++;
		/*if (num_items == 10) {
			break;
		}*/
	}
	printf("\n==============================================================================================\n");
	printf("|                             ( N=Normal B=Broze S=Silver G=Gold )                           |\n");
	printf("|Item Code\tItem Name\tN member\tB Member 5%%\tS Member 15%%\tG Member 25%% |\n");
	printf("==============================================================================================\n");
	for (int a = 0; a < num_items; a++) {
		printf("%-15s %-15s RM%-10.2f\tRM%-11.2f\tRM%-11.2f\tRM%-11.2f|\n", item[a].code, item[a].name, item[a].price, item[a].price * 0.95, item[a].price * 0.85, item[a].price * 0.75);
	}
	printf("==============================================================================================\n");
	printf("\n");

	fclose(fpro);

	int found = 0;
	while (fscanf(fordered, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", modi[count].name, &modi[count].memType, modi[count].orderName, &modi[count].price) != EOF) {
		count++;
	}

	printf("\n");
	printf("Enter Name you want to modify: ");
	rewind(stdin);
	scanf("%[^\n]", &name);


	for (int i = 0; i < count; i++) {

		if (strcmp(modi[i].name, name) == 0) {
			found = 1;
			printf("\nItems Ordered\n");
			printf("==============\n");
			printf("Name: %s\n", modi[i].name);
			printf("Type of member: %c\n", modi[i].memType);
			printf("Item ordered: %s\n", modi[i].orderName);
			printf("Total Payment: %.2f\n", modi[i].price);
			printf("=======================\n\n");

			printf("Enter New Item Code: ");
			rewind(stdin);
			scanf("%[^\n]", modi[i].code);

			for (int k = 0; k < num_items; k++) {

				if (strcmp(item[k].code, modi[i].code) == 0) {
					if (modi[i].memType == 'N') {
						modi[i].price = item[k].price;
					}
					else if (modi[i].memType == 'B') {
						modi[i].price = item[k].price * 0.95;
					}
					else if (modi[i].memType == 'S') {
						modi[i].price = item[k].price * 0.85;
					}
					else if (modi[i].memType == 'G') {
						modi[i].price = item[k].price * 0.75;
					}
					strcpy(modi[i].orderName, item[k].name);
				}
			}//end item

			printf("Item Name: %s\n", modi[i].orderName);
			printf("Price for Memeber Type %c: RM %.2f\n", modi[i].memType, modi[i].price);

			printf("Enter Quantity: ");
			rewind(stdin);
			scanf("%d", &modi[i].quantity);

			modi[i].price *= modi[i].quantity;

			printf("Sure to modify? (Y=yes, N=no): ");
			rewind(stdin);
			scanf("%c", &sure);

			if (toupper(sure) == 'Y') {

				printf("\nModified Ordered\n");
				printf("==================\n");
				printf("Name: %s\n", modi[i].name);
				printf("Type of member: %c\n", modi[i].memType);
				printf("Item Name: %s\n", modi[i].orderName);
				printf("Total Payment: %.2f\n", modi[i].price);
				printf("=======================\n\n");

				fclose(fordered);

				fmodi = fopen("Orders.txt", "w");
				if (fmodi == NULL) {
					printf("Opening file errors");
					return;
				}

				for (int j = 0; j < count; j++) {

					fprintf(fmodi, "Name: %s\n", modi[j].name);
					fprintf(fmodi, "Type of Member: %c\n", modi[j].memType);
					fprintf(fmodi, "Item Ordered: %s\n", modi[j].orderName);
					fprintf(fmodi, "Total Purchase: %.2f\n\n", modi[j].price);


				}//end of fprintf a back in file
				printf("============================\n");
				printf("|    sucessful Modify!!!   |\n");
				printf("============================\n\n");
				fclose(fmodi);

			}
			else {
				return 0;
			}//end of if 'Y'

		}///IF got two is same name ???
	}

}

void deleteOrdered() {
	FILE* fdelete;
	Add delete[30];
	int count = 0, dlt = 0;
	char dltname[30];
	int found = 0;
	char cdelete;
	char sure;
	char renter;

	fdelete = fopen("Orders.txt", "r");
	if (fdelete == NULL)
	{
		printf("opening file errors...!");
		exit(-1);
	}


	printf("Enter the name you want to delete: ");
	rewind(stdin);
	scanf("%[^\n]", &dltname);
	while (fscanf(fdelete, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", delete[count].name, &delete[count].memType, delete[count].orderName, &delete[count].price) != EOF) {
		if (strcmp(delete[count].name, dltname) == 0) {
			found = 1;
			dlt = count;
			printf("\nItems Ordered\n");
			printf("==============\n");
			printf("Name: %s\n", delete[count].name);
			printf("Item Ordered: %s\n", delete[count].orderName);
			printf("Type of member: %c\n", delete[count].memType);
			printf("Total Payment: %.2f\n", delete[count].price);
			printf("=======================\n\n");

		}
		count++;
	}
	fclose(fdelete);



	FILE* fstore;
	fstore = fopen("Orders.txt", "w");
	if (fstore == NULL) {
		printf("Opening file errors...!");
		exit(-1);
	}

	printf("Comfirm to delete this order? (Y=yes,N=no)");
	rewind(stdin);
	scanf("%c", &cdelete);
	if (toupper(cdelete) == 'Y') {
		for (int j = 0; j < count; j++) {
			if (dlt == j) {
				printf("=========\n");
				printf("|Deleted|\n");
				printf("=========\n\n");
			}
			else {
				fprintf(fstore, "Name: %s\n", delete[j].name);
				fprintf(fstore, "Type of Member: %c\n", delete[j].memType);
				fprintf(fstore, "Item Ordered: %s\n", delete[j].orderName);
				fprintf(fstore, "Total Purchase: %.2f\n\n", delete[j].price);
			}
		}
		printf("================================\n");
		printf("|    Delete successfully...!   |\n");
		printf("================================\n\n");
	}
	if (toupper(cdelete) == 'N') {
		for (int j = 0; j < count; j++) {
			fprintf(fstore, "Name: %s\n", delete[j].name);
			fprintf(fstore, "Type of Member: %c\n", delete[j].memType);
			fprintf(fstore, "Item Ordered: %s\n", delete[j].orderName);
			fprintf(fstore, "Total Purchase: %.2f\n\n", delete[j].price);
		}
		printf("Its find...Thak you");
	}

	fclose(fstore);
	/*	printf("DO you want to delete more ordered records? (Y=yes,N=no)");
		rewind(stdin);
		scanf("%c", &sure);
	} while (toupper(sure) == 'Y');*/

	return;

}


void searchOrder() {
	char name[20];
	Add add;
	FILE* forder;
	double price;
	char confirm;
	forder = fopen("Orders.txt", "r");

	if (forder == NULL) {
		printf("Error opening file!");
		return;
	}

	printf("\nEnter your name: ");
	rewind(stdin);
	scanf("%[^\n]", name);

	//if (scanf("%19[^\n]", name) != 0) { // validate input
	//	printf("Invalid input. Please enter a valid name.\n");
	//	fclose(forder);
	//	return;
	//}



	int found = 0;
	while (fscanf(forder, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", add.name, &add.memType, add.orderName, &add.price) != EOF) {
		if (strcmp(add.name, name) == 0) {
			found = 1;
			printf("\nItems Ordered\n");
			printf("==============\n");
			printf("Name: %s\n", add.name);
			printf("Type of member: %c\n", add.memType);
			printf("Item Ordered: %s\n", add.orderName);
			printf("Total Payment: %.2f\n", add.price);
			printf("=======================\n\n");
		}
	}
	printf("\n");
	if (!found) {
		printf("No orders found for the given name.\n\n");
	}

	fclose(forder);
}


void payment() {
	FILE* fpay, * forder;

	forder = fopen("Orders.txt", "r");

	if (forder == NULL) {
		printf("Error opening file!");
		return;
	}
	fpay = fopen("Payment", "a");
	if (fpay == NULL) {
		printf("opening file errors");
		exit(-1);
	}

	Payment payment;
	Add add;
	int x;
	char bank[15], confirm, username[20];
	int password, card;
	char name[20];
	double total = 0;
	printf("\nEnter your name: ");
	rewind(stdin);
	scanf("%[^\n]", name);

	int found = 0;
	printf("\nItems Ordered\n");
	printf("==============\n");
	while (fscanf(forder, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", add.name, &add.memType, add.orderName, &add.price) != EOF) {
		if (strcmp(add.name, name) == 0) {
			found = 1;
			printf("Item Ordered: %s\n", add.orderName);
			printf("Payment for this item: %.2f\n", add.price);
			
			total += add.price;
		}

	}
	printf("=======================\n");
	printf("Total Payment: RM %.2f\n", total);
	printf("=======================\n");
	printf("\n");
	if (!found) {
		printf("No orders found for the given name.\n\n");
	}

	fclose(forder);

	do {
		printf("Payment Method\n");
		printf("1. Online Payment\n");
		printf("2. Cash Payment\n");
		printf("Select your payment method:");
		scanf("%d", &x);

		if (x == 1) {
			printf("\n");
			printf("BANK USED (e.g maybank, cimb,public bank): ");
			rewind(stdin);
			scanf("%[^\n]", &payment.bank);

			printf("USERNAME(bank): ");
			rewind(stdin);
			scanf("%s", &payment.username);

			printf("PASSWORD: ");
			rewind(stdin);
			scanf("%d", &payment.pas);

			printf("Comfirm payment? (Y=yes, N=no) ");
			rewind(stdin);
			scanf("%c", &confirm);

			if (confirm == 'Y') {
				printf("==================================\n");
				printf("| Payment sucessfully! Thankyou! |\n| HAVE A GOOD DAY... \t\t |\n");
				printf("==================================\n\n");
			}
			else {
				printf("==================================\n");
				printf("| Payment unsucessfull!!!...     |\n| Pls make the payment again... \t |\n");
				printf("==================================\n\n");
			}
		}
		else if (x == 2) {
			printf("\n");
			printf("Order Name: ");
			rewind(stdin);
			scanf("%s", &payment.username);

			printf("Payment Completed at Counter? (Y=yes, N=no)");
			rewind(stdin);
			scanf("%c", &confirm);

			if (confirm == 'Y') {
				printf("==================================\n");
				printf("| Payment sucessfully! Thankyou! |\n| HAVE A GOOD DAY... \t\t |\n");
				printf("==================================\n\n");
			}
			else {
				printf("Payment unsucessfull!!!...Pls make the payment again...\n\n");
			}
		}
	} while (confirm != 'Y');
	if (x == 1 && confirm == 'Y') {
		fprintf(fpay, "%s(PAID)\tBANK(%s)\tRM %.2f\n", payment.username, payment.bank,total);
	}
	if (x == 2 && confirm == 'Y') {
		fprintf(fpay, "%s(PAID)\tCash Payment\tRM %.2f\n", payment.username,total);
	}

	fclose(fpay);
}


void sales() {
	FILE* forder;
	double price;
	int num=0;

	forder = fopen("Orders.txt", "r");
	if (forder == NULL) {
		printf("Opening file errors...\n");
		return;
	}

	Add add;
	int count = 0;
	 double sales = 0;

	printf("\n");
	printf("                            <<------------| SALES REPORT |------------>>\n");
	printf("                         ==================================================\n");
	printf("                         |Name\t             Item\t    total purchase|\n");
	printf("                         --------------------------------------------------\n");
	while (fscanf(forder, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", add.name, &add.memType, &add.orderName, &price) != EOF) {
		count++;
		sales += price;

		printf("                         |%-2d.%-15s %-16s %-12.2f|\n", num+=1,add.name, add.orderName, price);


	}
	printf("                         --------------------------------------------------\n");


	printf("                         |The sales now is                    %-12.2f|\n", sales);
	printf("                         ==================================================\n\n");
}

////Sales and Order

////Member
void memberPage() {
	int respond1;

	do {
		//print Member Menu 
		menuMember();
		scanf("%d", &respond1);
		printf("\n");

		// follow the number that member key in come out different function
		switch (respond1) {
		case 1:
			signUpMember();
			displayMemberAll();
			break;
		case 2:
			loginMember();
			break;
		case 3:
			deleteMember();
			break;
		case 4:
			printf("Success exit from MEMBER\n\n");
			return 0;
			break;
		default:
			printf("Please enter number 1 to 4 only.......\n\n");
		}
	} while (respond1 != 4);
}

////MEMBER MAIN MENU
void menuMember() {
	printf("\n\n\t\t==============================\n");
	printf("\t\t= Welcome to Member Side !!! =\n");
	printf("\t\t==============================\n");
	printf("\t<<<-------------------------------------->>>\n");
	printf("\t\t\t1. Sign Up\n");
	printf("\t\t\t2. Log In\n");
	printf("\t\t\t3. Delete\n");
	printf("\t\t\t4. Exit Member Side\n");
	printf("\t<<<-------------------------------------->>>>\n");
	printf("\tEnter 1 to 4 :");
}

//1.sign up
void signUpMember(){

	char passwordR[11], confirm,emptyPassword[11];
	int i = 0, mScanCount = 0, f = 0, found = 0,j = 0;
	MEMBER create;
	MEMBER check[MAX_MEMBERS];

	FILE* mbPtr;
	mbPtr = fopen("Member.dat", "rb");
	if (mbPtr == NULL) {
		printf("Unable to open the file or File not exist\n");
		exit(-1);
	}
	while (fread(&check[i], sizeof(MEMBER), 1, mbPtr) != 0) {
		i++;
		mScanCount++;
	}
	//get the all the data that already exist from the member.dat  
	i = 0;

	//Insert new memberID
	//check the memberID exist or not in current file
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\t|                ^_O MEMBER SIGN UP O_^               |\n");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	do {
		if (j > 0) {
			printf("____________________________________________________\n");
			printf("|MemberID more than 9 size!Please key in again.....|\n");
			printf("----------------------------------------------------\n\n");
		}

		if (i > 0) {
			printf("_________________________________________________\n");
			printf("|MemberID already exist!Please key in again.....|\n");
			printf("-------------------------------------------------\n\n");
		}
		printf("Create a member ID (max 9 character size):");
		rewind(stdin);
		scanf("%[^\n]", create.memberId);
		printf("\n");

		for (f = 0; f < mScanCount; f++) {
			if (strcmp(check[f].memberId, create.memberId) == 0) {
				found = 1; break;
			}
		}
		checkLengthMemberId(create.memberId, &j); 
		CheckReturn(&found, &i);
	} while (i == 1 || j == 1);

	//insert new password
	//check Password exist or not in current file
	do {
		if (j > 0) {
			strcpy(passwordR, emptyPassword);
			printf("\n_____________________________________________________\n");
			printf("|Password more than 10 size!Please key in again.....|\n");
			printf("-----------------------------------------------------\n\n");
		}

		if (i > 0) {
			printf("\n------------------------------------------------\n");
			printf("|Password already exist! Please key in again....|\n");
			printf("------------------------------------------------\n\n");
		}

		printf("Password(No more than 10 character) :\n");
		printf("Suggest password is the combination of the symbol,character and number:");
		rewind(stdin);
		scanf("%[^\n]", create.passwordM);

		printf("Re-Enter Password :");
		rewind(stdin);
		scanf("%[^\n]", passwordR);

		while (strcmp(create.passwordM, passwordR) != 0) {
			printf("\n < Password and re-password no match >\n");

			printf("Password(No more than 10 character) :\n");
			printf("Suggest password is the combination of the symbol,character and number:");
			rewind(stdin);
			scanf("%[^\n]", create.passwordM);

			printf("Re-Enter Password :");
			rewind(stdin);
			scanf("%[^\n]", passwordR);
		}
		printf("\n");

		for (f = 0; f < mScanCount; f++) {
			if (strcmp(create.passwordM, check[f].passwordM) == 0) {
				found = 1; break;

			}
		}
		checkLengthPassword(create.passwordM, &j);
		CheckReturn(&found, &i);

	} while (i == 1 || j == 1);

	////Get the details of member from customers

	printf("Name :");
	rewind(stdin);
	scanf("%[^\n]", create.memberName);

	////Get gender of member, check is M or F or not
	do {
		printf("Gender(Male = M ,Female = F) :");
		rewind(stdin);
		scanf("%c", &create.gender);
	} while ((create.gender != 'M') && (create.gender != 'F'));

	////Get phone number and it check exits already or not
	do {

		if (i > 0) {
			printf("\n------------------------------------------------------\n");
			printf("|Phone number already exist! Please key in again....|\n");
			printf("------------------------------------------------------\n\n");
		}

		printf("Phone Number(+60) (eg:01113445667) without(-) :");
		rewind(stdin);
		scanf("%d", &create.phoneNum);

		for (f = 0; f < mScanCount; f++) {
			if (create.phoneNum == check[f].phoneNum) {
				found = 1; break;
			}
		}
		CheckReturn(&found, &i);
	} while (i == 1);

	////Get email and it check exits already or not
	do {

		if (i > 0) {
			printf("\n------------------------------------------------\n");
			printf("|Email already exist! Please key in again....|\n");
			printf("------------------------------------------------\n\n");
		}

		printf("Email (eg : a123@gmail.com) :");
		rewind(stdin);
		scanf("%[^\n]", create.email);


		for (f = 0; f < mScanCount; f++) {
			if (strcmp(create.email, check[f].email) == 0) {
				found = 1; break;
			}
		}
		CheckReturn(&found, &i);

	} while (i == 1);


	//MEMBER TYPE & period and check it correct or not
	do {
		printf("\n\t       Member Type\n");
		printf("\t=========================\n");
		printf("\t| N = Normal (RM 10.00) |\n");
		printf("\t| B = Bronze (RM 30.00) |\n");
		printf("\t| S = Sliver (RM 50.00) |\n");
		printf("\t| G = Gold   (RM 80.00) |\n");
		printf("\t=========================\n");
		printf("Choose(N,B,S or G) : ");
		rewind(stdin);
		scanf("%c", &create.memberType);
		create.memberType = toupper(create.memberType);

		do {
			printf("Choose period(1 = 1 year ,2 = 2 years or 3 = 3 years) :");
			rewind(stdin);
			scanf("%d", &create.period);
		} while ((create.period <= 0) || (create.period > 3));

		switch (create.memberType) {
		case 'N': {
			create.fee = 10.00 * create.period;
			i = 0;
		}
				break;
		case 'B': {
			create.fee = 30.00 * create.period;
			i = 0;
		}
				break;
		case 'S': {
			create.fee = 50.00 * create.period;
			i = 0;
			break;
		}
		case 'G': {
			create.fee = 80.00 * create.period;
			i = 0;
		}
				break;
		default:
			i++;
			printf("\n============================================\n");
			printf("Invalid Member Type. Please key in again....\n");
			printf("============================================\n");
		}
		printf("\n");

	} while (i > 0);
	fclose(mbPtr);

	printf("\nConfirm Sign Up (Y= Yes, N = No)? :");
	rewind(stdin);
	scanf("%c", &confirm);

	////If yes then member create not stop sign up
	if (toupper(confirm) == 'Y') {
		printf("\t\t\t\t\t\t\t______________\n");
		printf("\t\t\t\t\t\t\t| SUCCESS!!! |\n");
		printf("\t\t\t\t\t\t\t--------------\n\n");

		printf("=====================================================================================================================================\n");
		printf("MEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\t\tFEE\n");
		printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\t\t===\n");
		printf("%-10s\t%-20s\t%c\t%d\t%s\t\t%c\t\t%d\t\tRM %.2f\n", create.memberId, create.memberName, create.gender, create.phoneNum, create.email, create.memberType, create.period, create.fee);
		printf("=====================================================================================================================================\n\n\n");
		printf("\t\t\t\t\t\t\t___________________________\n");
		printf("\t\t\t\t\t\t\t|  NEW MEMBER IS CREATE   |\n");
		printf("\t\t\t\t\t\t\t---------------------------\n\n\n");
		//Open file again to write the new data into the file
		FILE* mbPtr2;
		mbPtr2 = fopen("Member.dat", "ab");
		if (mbPtr2 == NULL) {
			printf("FAILURE NEW MEMBER SIGN UP.....\n");
			printf("PLEASE TRY AGAIN\n");
		}
		fwrite(&create, sizeof(MEMBER), 1, mbPtr2);
		fclose(mbPtr2);

	}//if confirm Yes
	else {
		printf("=======================\n");
		printf("= MEMBER SIGN UP STOP =\n");
		printf("=        Q_O          =\n");
		printf("=======================\n\n");
	}

}//End of sign up

////check member data already exists or not
void CheckReturn(int* found, int* i) {
	if (*found == 1) {
		*i = 1;
		*found = 0;
	}
	else {
		*i = 0;
		*found = 0;
	}
}

///check the length of memberId no more than 9
void checkLengthMemberId(char memberID[], int* j) {
	if (strlen(memberID) > 9) {
		*j = 1;
	}
	else {
		*j = 0;
	}

}

///Check the legnth of password no more than 10
void checkLengthPassword(char password[], int* j) {
	if (strlen(password) > 10) {
		*j = 1;
	}
	else {
		*j = 0;
	}
}

//display all member data
void displayMemberAll() {
	MEMBER dsp;
	//Open One More Times the file to read to display the all member details data
	FILE* mbPtr3;
	mbPtr3 = fopen("Member.dat", "rb");
	if (mbPtr3 == NULL) {
		printf("Unable to open the file or File not exist\n");
		exit(-1);
	}

	printf("=====================================================================================================================================\n");
	printf("MEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\t\tFEE\n");
	printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\t\t===\n");
	while (fread(&dsp, sizeof(MEMBER), 1, mbPtr3) != 0) {
		printf("%-10s\t%-20s\t%c\t0%d\t%s\t\t%c\t\t%d\t\tRM %.2f\n", dsp.memberId, dsp.memberName, dsp.gender, dsp.phoneNum, dsp.email, dsp.memberType, dsp.period, dsp.fee);
	}
	printf("=====================================================================================================================================\n\n\n");
	fclose(mbPtr3);
}//End of display all member data in sign up
 ////End of sign up part

////2. Log In
void loginMember() {
	char tempMbId[10], tempPassword[11], confirmAgain = 'N';
	int checkLogin = 0, respond2;

	////LOGIN members key in memberID and password
	printf("\t===========\n");
	printf("\t| LOG IN  |\n");
	printf("\t===========\n\n");
	printf("MEMBER ID :");
	rewind(stdin);
	scanf("%[^\n]", tempMbId);
	printf("Password :");
	rewind(stdin);
	scanf("%[^\n]", tempPassword);
	printf("\n\n");

	checkLogin = checkMemberIDExists(tempMbId, tempPassword);

	do {
		switch (checkLogin) {
		case 1: {
			do {
				////Use 1 to 4 become the command to let the customer to choose the function
				printf("\t\t__________________________\n");
				printf("\t\t|  Welcome Back!!! d^_^b |\n");
				printf("\t\t--------------------------\n\n");
				printf("\t=======================================\n");
				printf("\t|             ^MEMBER^                |\n");
				printf("\t=======================================\n");
				printf("\t|1. SEARCH History PURCHASE in Store  |\n");
				printf("\t|2. MODIFY member personal details    |\n");
				printf("\t|3. DISPALY bonus of member           |\n");
				printf("\t|4. Return                            |\n");
				printf("\t=======================================\n");
				printf("Choose :");
				rewind(stdin);
				scanf("%d", &respond2);

				switch (respond2)
				{
				case 1:
					searchMOrderHis(tempMbId);
					break;
				case 2:
					modifyMember(tempMbId);
					break;
				case 3:
					displayDiscountMember(tempMbId);
					break;
				case 4:
					printf("\t\t\t=========\n");
					printf("\t\t\t|Log OUT|\n");
					printf("\t\t\t=========\n\n\n");
					return 0;
					break;
				default:
					printf("\nPlease Key In 1 to 4 only.......\n\n");
					break;
				}

			} while (respond2 != 4);
		}
			  break;
		case 2: {
			printf("==================================\n");
			printf("Member ID or Password incorrect\n");
			printf("Please Try Again\n");
			printf("==================================\n\n");

			printf("Continue(Y=Yes,N=No)? :");
			rewind(stdin);
			scanf("%c", &confirmAgain);

			if (toupper(confirmAgain) == 'Y') {
				printf("\t===========\n");
				printf("\t| LOG IN  |\n");
				printf("\t===========\n\n");
				printf("MEMBER ID :");
				rewind(stdin);
				scanf("%[^\n]", tempMbId);
				printf("Password :");
				rewind(stdin);
				scanf("%[^\n]", tempPassword);
				printf("\n\n");

				checkLogin = checkMemberIDExists(tempMbId, tempPassword);
			}
			else {
				return 0;
			}
			break;
		}
		}
	} while (toupper(confirmAgain) == 'Y');
}


////login validation
int checkMemberIDExists(char id[], char password[]) {
	MEMBER login;
	int i = 0, found = 0;
	FILE* loginPtr;
	loginPtr = fopen("Member.dat", "rb");

	if (loginPtr == NULL) {
		printf("Unable to open the file or File not exist\n");
		exit(-1);
	}

	////if exits return 1 else 2
	while ((fread(&login, sizeof(MEMBER), 1, loginPtr) != 0) && (i == 0)) {

		if ((strcmp(login.memberId, id) == 0) && (strcmp(login.passwordM, password) == 0)) {
			i++;
			return 1;
		}
		else {
			i = 0;
		}

	}

	if (i == 0)
	{
		return 2;
	}


	fclose(loginPtr);
}

////Sub login 
////1.search Order History
void searchMOrderHis(char tempMbId[]) {
	int countOrder = 0, countMb = 0, i = 0, j = 0, found = 0;
	Add orderHistory[MAX_MEMBERS];
	MEMBER searchMbHis[MAX_MEMBERS];
	FILE* searchPtr, * orderHisPtr;
	searchPtr = fopen("Member.dat", "rb");
	orderHisPtr = fopen("Orders.txt", "r");


	if ((searchPtr == NULL) && (orderHisPtr == NULL))
	{
		printf("opening file errors...!");
		exit(-1);
	}

	while (fscanf(orderHisPtr, "Name: %[^\n]\nType of Member: %c\nItem Ordered: %[^\n]\nTotal Purchase: %lf\n", orderHistory[countOrder].name, &orderHistory[countOrder].memType, orderHistory[countOrder].orderName, &orderHistory[countOrder].price) != EOF) {
		countOrder++;
	}

	while (fread(&searchMbHis[countMb], sizeof(MEMBER), 1, searchPtr) != 0) {
		countMb++;
	}

	////search order from the orders.txt file by using member name
	for (i = 0; i < countMb; i++) {
		if (strcmp(searchMbHis[i].memberId, tempMbId) == 0) {
			printf("MEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\n");
			printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\n");
			printf("%-10s\t%-20s\t%c\t0%d\t%s\t\t%c\t\t%d\n\n\n", searchMbHis[i].memberId, searchMbHis[i].memberName, searchMbHis[i].gender, searchMbHis[i].phoneNum, searchMbHis[i].email, searchMbHis[i].memberType, searchMbHis[i].period);
			for (j = 0; j < countOrder; j++) {
				if (strcmp(searchMbHis[i].memberName, orderHistory[j].name) == 0) {
					found = 1;
					//	printf("\nItems Ordered\n");
					printf("Order %d: %s\n", j, tempMbId);
					printf("======================\n");
					printf("Name: %s\n", orderHistory[j].name);
					printf("Item Ordered: %s\n", orderHistory[j].orderName);
					printf("Type of member: %c\n", orderHistory[j].memType);
					printf("Total Payment: %.2f\n", orderHistory[j].price);
					printf("=======================\n\n");
				}
			}
		}
	}

	if (found == 0) {
		printf("<<<------------------------------------------------------------------->>>\n");
		printf(" %s, no ORDER history for you\n", tempMbId);
		printf(" Please make order at Our at our The Daily Market Order Page first\n");
		printf("<<<------------------------------------------------------------------->>>\n\n\n");
		return 0;
	}
}

////2. modify
void modifyMember(char tempMbId[]) {
	char confirm3;
	char cName[20], cEmail[45], cMemberT;
	int cPhoneNum, cPeriod = 0;
	int respond3 = 0, i = 0, k = 0, mScanCount = 0, j = 0;////Use to control
	double cFee;
	MEMBER modifyMD[MAX_MEMBERS];
	FILE* modifyPtr;
	modifyPtr = fopen("Member.dat", "rb");

	if (modifyPtr == NULL) {
		printf("Unable to open the file or File not exist\n");
		exit(-1);
	}

	while (fread(&modifyMD[i], sizeof(MEMBER), 1, modifyPtr) != 0) {
		mScanCount++;
		i++;
	}

	fclose(modifyPtr);
	////read all the member data from the member binary file then hold the data by using the modifyMD array

	for (i = 0; i < mScanCount; i++) {
		////Check Are member ID correct and match the member ID in file 
		if (strcmp(modifyMD[i].memberId, tempMbId) == 0) {
			printf("\nMEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\n");
			printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\n");
			printf("%-10s\t%-20s\t%c\t0%d\t%s\t\t%c\t\t%d\n\n\n", modifyMD[i].memberId, modifyMD[i].memberName, modifyMD[i].gender, modifyMD[i].phoneNum, modifyMD[i].email, modifyMD[i].memberType, modifyMD[i].period);

			do {
				//display manu of modify data
				printf("\t=======================================\n");
				printf("\t|MODIFY -->                           |\n");
				printf("\t=======================================\n");
				printf("\t|1. CHANGE NAME                       |\n");
				printf("\t|2. CHANGE TELEFON NUMBER             |\n");
				printf("\t|3. CHANGE EMAIL                      |\n");
				printf("\t|4. UPGRADE OR DOWNGRADE MEMBER TYPE  |\n");
				printf("\t|5. Exit                              |\n");
				printf("\t=======================================\n");
				printf("\tChoose One(1 to 5) :");
				rewind(stdin);
				scanf("%d", &respond3);
				printf("\n\n");

				switch (respond3) {
				case 1:
				{
					//Change Name
					printf("Change Name :");
					rewind(stdin);
					scanf("%[^\n]", cName);

					printf("Confirm to change (Y = Yes and N = No) ? :");
					rewind(stdin);
					scanf("%c", &confirm3);

					if (toupper(confirm3) == 'Y') {
						strcpy(modifyMD[i].memberName, cName);
						printf("\n===============================\n");
						printf("\n|Member Name has been updated.|\n");
						printf("\n===============================\n\n\n");
					}
					else {
						printf("\n===========================================\n");
						printf("\n|No changes have been made to member data.|\n");
						printf("\n===========================================\n\n\n");
					}
				}//1
				break;
				case 2:
				{
					//Chnage Phone Number
					printf("Change Phone Number(+60) (eg:01113445667) without(-):");
					rewind(stdin);
					scanf("%d", &cPhoneNum);

					printf("Confirm to change (Y = Yes and N = No) ? :");
					rewind(stdin);
					scanf("%c", &confirm3);

					if (toupper(confirm3) == 'Y') {
						modifyMD[i].phoneNum = cPhoneNum;
						printf("\n=======================================\n");
						printf("\n|Member Phone Number has been updated.|\n");
						printf("\n=======================================\n\n\n");
					}
					else {
						printf("\n===========================================\n");
						printf("\n|No changes have been made to member data.|\n");
						printf("\n===========================================\n\n\n");
					}

				}//2
				break;
				case 3:
				{
					// email address
					printf("Change Email (eg : a123@gmail.com):");
					rewind(stdin);
					scanf("%[^\n]", cEmail);

					printf("Confirm to change (Y = Yes and N = No) ? :");
					rewind(stdin);
					scanf("%c", &confirm3);

					if (toupper(confirm3) == 'Y') {
						strcpy(modifyMD[i].email, cEmail);
						printf("\n================================\n");
						printf("\n|Member Email has been updated.|\n");
						printf("\n================================\n\n\n");
					}
					else {
						printf("\n===========================================\n");
						printf("\n|No changes have been made to member data.|\n");
						printf("\n===========================================\n\n\n");
					}

				}//3
				break;
				case 4:
				{
					//Chang Member Type, Period, Fee
					do {
						printf("\n\t       Member Type\n");
						printf("\t=========================\n");
						printf("\t| N = Normal (RM 10.00) |\n");
						printf("\t| B = Bronze (RM 30.00) |\n");
						printf("\t| S = Sliver (RM 50.00) |\n");
						printf("\t| G = Gold   (RM 80.00) |\n");
						printf("\t=========================\n");
						printf("Choose(N,B,S or G) : ");
						rewind(stdin);
						scanf("%c", &cMemberT);


						do {
							printf("Choose period(1 = 1 year ,2 = 2 years or 3 = 3 years) :");
							rewind(stdin);
							scanf("%d", &cPeriod);
						} while ((cPeriod <= 0) && (cPeriod > 3));

						switch (toupper(cMemberT)) {
						case 'N': {
							cFee = 10.00 * cPeriod;
							i = 0;
						}
								break;
						case 'B': {
							cFee = 30.00 * cPeriod;
							k = 0;
						}
								break;
						case 'S': {
							cFee = 30.00 * cPeriod;
							k = 0;
							break;
						}
						case 'G': {
							cFee = 30.00 * cPeriod;
							k = 0;
						}
								break;
						default:
							k++;
						}//End switch member type modify
						printf("\n");

					} while (k > 0);//End while of Member Type Check

					printf("Confirm to change (Y = Yes and N = No) ? :");
					rewind(stdin);
					scanf("%c", &confirm3);

					if (toupper(confirm3) == 'Y') {
						modifyMD[i].memberType = cMemberT;
						modifyMD[i].period = cPeriod;
						modifyMD[i].fee = cFee;
						printf("\n=========================================\n");
						printf("\n|MemberType and Period has been updated.|\n");
						printf("\n========================================\n\n");
					}
					else {
						printf("\n===========================================\n");
						printf("\n|No changes have been made to member data.|\n");
						printf("\n===========================================\n\n\n");
					}

				}//4
				break;
				case 5:
				{
					////Write updated member data back to binary file
					FILE* modifyPtrW;
					modifyPtrW = fopen("Member.dat", "wb");
					for (j = 0; j < mScanCount; j++) {
						fwrite(&modifyMD[j], sizeof(MEMBER), 1, modifyPtrW);
					}

					printf("Success to Change!!!\n");
					printf("See Changes ^_^ \n\n");
					printf("=====================================================================================================================================\n");
					printf("MEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\t\tFEE\n");
					printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\t\t===\n");
					printf("%-10s\t%-20s\t%c\t0%d\t%s\t\t%c\t\t%d\t\tRM %.2f\n", modifyMD[i].memberId, modifyMD[i].memberName, modifyMD[i].gender, modifyMD[i].phoneNum, modifyMD[i].email, modifyMD[i].memberType, modifyMD[i].period, modifyMD[i].fee);
					printf("=====================================================================================================================================\n\n\n");
					fclose(modifyPtrW);
					return 0;
				}//5
				break;
				default:
					printf("Please Key IN 1 to 5 only\n\n");
				}//end switch

			} while (respond3 != 5);// End do while

		}//End if

	}////End for loop

////end
}

////3. display dicount details for different other member
void displayDiscountMember(char tempMbId[]) {
	//Open and read file data to diplay discount purpose for different memberType
	MEMBER displayDc;
	FILE* displayPtr;
	displayPtr = fopen("Member.dat", "rb");

	if (displayPtr == NULL) {
		printf("Unable to open the file or File not exist\n");
		exit(-1);
	}

	while (fread(&displayDc, sizeof(MEMBER), 1, displayPtr) != 0) {

		if (strcmp(displayDc.memberId, tempMbId) == 0) {

			switch (displayDc.memberType) {
			case 'N': {
				printf("\n=================================================\n");
				printf("|\tBONUS FROM THE NORMAL MEMBER\t\t|\n");
				printf("=================================================\n");
				printf("1. DISCOUNT 0%% in all order\n");
				printf("2. If BUY more than RM 400, parking FREE\n");
				printf("3. More BONUS will update at the FUTURE\n\n");
			}
					break;
			case'B': {
				printf("\n=================================================\n");
				printf("|\tBONUS FROM THE BRONZE MEMBER\t\t|\n");
				printf("=================================================\n");
				printf("1. DISCOUNT %%5 in all order\n");
				printf("2. If BUY more than RM 300, parking FREE\n");
				printf("3. More BONUS will update at the FUTURE\n\n");
			}
				   break;
			case'S': {
				printf("\n=================================================\n");
				printf("|\tBONUS FROM THE SILVER MEMBER\t\t|\n");
				printf("=================================================\n");
				printf("1. DISCOUNT %%15 in all order\n");
				printf("2. If BUY more than RM 200, parking FREE\n");
				printf("3. More BONUS will update at the FUTURE\n\n");
			}
				   break;
			case'G': {
				printf("\n=================================================\n");
				printf("|\tBONUS FROM THE GOLDEN MEMBER\t\t|\n");
				printf("=================================================\n");
				printf("1. DISCOUNT %%25 in all order\n");
				printf("2. If BUY more than RM 100, parking FREE\n");
				printf("3. More BONUS will update at the FUTURE\n\n");
			}
				   break;

			}
		}
	}

	fclose(displayPtr);
	////end 
}
//End of login;

////3. Delete
void deleteMember() {

	////Open and read file data to diplay discount purpose for different memberType
	MEMBER delete[MAX_MEMBERS];
	char tempMbId[10], tempPassword[11];
	int i = 0, mScanCount = 0, j = 0, found = 0;
	char confirm2;


	FILE* deletePtr;
	deletePtr = fopen("Member.dat", "rb");
	if (deletePtr == NULL) {
		printf("Error: Failed to create binary file.\n");
		exit(1);
	}
	printf("\t\t\t=============\n");
	printf("\t\t\tDELETE MEMBER\n");
	printf("\t\t\t=============\n\n");
	printf("MEMBER ID :");
	rewind(stdin);
	scanf("%[^\n]", tempMbId);

	printf("PASSWORD  :");
	rewind(stdin);
	scanf("%[^\n]", tempPassword);
	printf("\n\n");

	while (fread(&delete[i], sizeof(MEMBER), 1, deletePtr) != 0) {
		mScanCount++;
		i++;
	}

	for (i = 0; i < mScanCount; i++) {

		if ((strcmp(delete[i].memberId, tempMbId) == 0) && (strcmp(delete[i].passwordM, tempPassword) == 0)) {
			printf("LIST.NO %d :\n\n", i);
			printf("MEMBER ID\tNAME\t\t\tGENDER\tPhoneNum(+60)\tEMAIL\t\tMEMBER TYPE\t\tPERIOD\n");
			printf("=========\t=============\t\t======\t============\t=====\t\t===========\t\t======\n");
			printf("%-10s\t%-20s\t%c\t0%d\t%s\t\t%c\t\t%d\n\n\n", delete[i].memberId, delete[i].memberName, delete[i].gender, delete[i].phoneNum, delete[i].email, delete[i].memberType, delete[i].period);

			printf("Are you sure you want to delete this member? (Y/N): ");
			rewind(stdin);
			scanf("%c", &confirm2);

			if (toupper(confirm2) == 'Y') {
				fclose(deletePtr);

				// delete the member data
				FILE* deleteWPtr;
				deleteWPtr = fopen("Member.dat", "wb");
				if (deleteWPtr == NULL) {
					printf("Error: Failed to create binary file.\n");
					exit(1);
				}

				// Write back the data but ignore the data that user want delete
				for (j = 0; j < mScanCount; j++) {

					if (strcmp(delete[j].memberId, tempMbId) == 0) {
						printf("===============================================\n");
						printf("= Your Member data has been deleted (d -v- b) =\n");
						printf("===============================================\n\n");
						printf("MEMBER ID: %s\n", delete[i].memberId);
						printf("Mr/Ms.%s, your member fee RM %.2f will be return to you by online banking in 3 working day\n", delete[i].memberName, delete[i].fee * 0.75);
						printf("Please check your bank account, if refund not bank in. Please contact our customer service,03-24356778\n");
						printf("Thank you! Have a nice day!\n\n");
					}
					else {
						fwrite(&delete[j], sizeof(MEMBER), 1, deleteWPtr);
					}
				}//end of for
				fclose(deleteWPtr);
				displayMemberAll();
				return 0;
			}
			else {
				printf("\n\t\t==============================\n");
				printf("\t\t| Deletion cancelled (- & -) |\n");
				printf("\t\t==============================\n");
				return 0;
			}
		}
		else {
			found = 1;
		}//end main if
	}//end of for
	//End if not find
	if (found == 1) {
		printf("\t==================================\n");
		printf("\t=       MEMBER is not exist      =\n");
		printf("\t= %s ,you are not our member     =\n", tempMbId);
		printf("\t==================================\n\n");
		return 0;
	}
}

///?MEMBER