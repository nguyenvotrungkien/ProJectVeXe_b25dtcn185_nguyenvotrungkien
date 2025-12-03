#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


#define MAX_TRIPS 100
#define MAX_TICKETS 100

struct Location {
    char name[50];      
    char address[100]; 
};

struct Trip {
    char tripId[20];           
    struct Location departure; 
    struct Location destination;
    char date[20];            
    int totalSeats;          
    int bookedSeats;           
};

struct Passenger {
    char name[50];   
    char phone[15];
};

struct Ticket {
    char ticketId[20];       
    char tripId[20];         
    struct Passenger passenger; 
    int seatNumber;         
    double price;            
    int paymentStatus;      
    char date[20];          
};

struct Trip trips[100];
int tripCount = 0;

struct Ticket tickets[100];
int ticketCount = 0;

char check;


int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int isValidDate(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12 || d < 1) return 0;

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear(y))
        daysInMonth[2] = 29;

    return d <= daysInMonth[m];
}

void addTrip() {
    struct Trip t;
    printf("=== THEM CHUYEN DI MOI ===\n");

    printf("Nhap ma chuyen: ");
    fgets(t.tripId, sizeof(t.tripId), stdin);
    t.tripId[strcspn(t.tripId, "\n")] = '\0';
    
    while(strlen(t.tripId) == 0 || sscanf(t.tripId, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(t.tripId, sizeof(t.tripId), stdin);
    t.tripId[strcspn(t.tripId, "\n")] = '\0';
}
    printf("Nhap dia diem khoi hanh: ");
    fgets(t.departure.name, sizeof(t.departure.name), stdin);
    t.departure.name[strcspn(t.departure.name, "\n")] = '\0';
    
    while(strlen(t.departure.name) == 0 || sscanf(t.departure.name, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(t.departure.name, sizeof(t.departure.address), stdin);
    t.departure.name[strcspn(t.departure.name, "\n")] = '\0';
}

    printf("Nhap vung khoi hanh: ");
    fgets(t.departure.address, sizeof(t.departure.address), stdin);
    t.departure.address[strcspn(t.departure.address, "\n")] = '\0';
    
    while(strlen(t.departure.address) == 0 || sscanf(t.departure.address, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(t.departure.address, sizeof(t.departure.address), stdin);
    t.departure.address[strcspn(t.departure.address, "\n")] = '\0';
}

    printf("Nhap dia diem den: ");
    fgets(t.destination.name, sizeof(t.destination.name), stdin);
    t.destination.name[strcspn(t.destination.name, "\n")] = '\0';
    
    while(strlen(t.destination.name) == 0 || sscanf(t.destination.name, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(t.destination.name, sizeof(t.destination.name), stdin);
    t.destination.name[strcspn(t.destination.name, "\n")] = '\0';
}

    printf("Nhap vung den: ");
    fgets(t.destination.address, sizeof(t.destination.address), stdin);
    t.destination.address[strcspn(t.destination.address, "\n")] = '\0';
    
    while(strlen(t.destination.address) == 0 || sscanf(t.destination.address, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(t.destination.address, sizeof(t.destination.address), stdin);
    t.destination.address[strcspn(t.destination.address, "\n")] = '\0';
}
    int d, m, y;
    while (1) {
        printf("Nhap ngay (dd/mm/yyyy): ");
        fgets(t.date, sizeof(t.date), stdin);
        t.date[strcspn(t.date, "\n")] = '\0';

        if (sscanf(t.date, "%d/%d/%d", &d, &m, &y) == 3 && isValidDate(d, m, y)) {
            break;
        }
        printf("Ngay khong hop le! Vui long nhap lai.\n");
    }

    printf("Nhap tong so ghe: ");
    scanf("%d", &t.totalSeats);
    while (getchar() != '\n');
    
    while(t.totalSeats <= 0) {
    printf("Tong so ghe phai lon hon 0! Nhap lai: ");
    scanf("%d", &t.totalSeats);
    while (getchar() != '\n');

}
   t.bookedSeats = 0;
   trips[tripCount++] = t;
   printf("=> Them chuyen thanh cong!\n");
}
void updateTrip() {
    printf("=== CAP NHAT CHUYEN DI ===\n");

    if (tripCount == 0) {
        printf("Khong tim thay chuyen xe!\n");
        return;
    }

    char id[20];
    printf("Nhap ma chuyen can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    while(strlen(id) == 0 || sscanf(id, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
}
    int index = -1;
    for (int i = 0; i < tripCount; i++) {
        if (strcmp(trips[i].tripId, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay chuyen xe!\n");
        return;
    }

    struct Trip *t = &trips[index];
    char input[100];

    printf("Nhap noi khoi hanh moi: ");
    fgets(input, sizeof(input), stdin);
    
    while(strlen(input) == 0 || sscanf(input, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(input, sizeof(input), stdin);
    id[strcspn(input, "\n")] = '\0';
}
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(t->departure.name, input);
    }

    printf("Nhap vung bat dau moi: ");
    fgets(input, sizeof(input), stdin);
    
    while(strlen(input) == 0 || sscanf(input, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(input, sizeof(input), stdin);
    id[strcspn(input, "\n")] = '\0';
}
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(t->departure.address, input);
    }

    printf("Nhap diem den moi: ");
    fgets(input, sizeof(input), stdin);
    
    while(strlen(input) == 0 || sscanf(input, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(input, sizeof(input), stdin);
    id[strcspn(input, "\n")] = '\0';
}
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(t->destination.name, input);
    }

    printf("Nhap vung den moi: ");
    fgets(input, sizeof(input), stdin);
    
    while(strlen(input) == 0 || sscanf(input, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(input, sizeof(input), stdin);
    id[strcspn(input, "\n")] = '\0';
}
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(t->destination.address, input);
    }

    printf("Nhap ngay moi (dd/mm/yyyy): ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';

        int d, m, y;
        if (sscanf(input, "%d/%d/%d", &d, &m, &y) == 3 && isValidDate(d, m, y)) {
            strcpy(t->date, input);
        } else {
            printf("Ngay moi khong hop le! Giu nguyen ngay cu.\n");
        }
    }

    printf("Nhap tong so ghe moi: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        int newSeats = atoi(input);
        if (newSeats < t->bookedSeats) {
            printf("!!! Tong ghe moi nho hon ghe da dat (%d) !!!\n", t->bookedSeats);
        } else {
            t->totalSeats = newSeats;
        }
    }
    printf("\n=> Cap nhat thanh cong!\n");
}
void bookTicket() {
	printf("=== DAT VE ===\n");
    if (tripCount == 0) {
        printf("Khong co chuyen de dat!\n");
        return;
    }

    char tripId[20];
    printf("Nhap ma chuyen muon dat: ");
    fgets(tripId, sizeof(tripId), stdin);
    tripId[strcspn(tripId, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < tripCount; i++) {
        if (strcmp(trips[i].tripId, tripId) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("!!! Ma chuyen khong ton tai!\n");
        return;
    }

    struct Trip *t = &trips[index];

    if (t->bookedSeats >= t->totalSeats) {
        printf("!!! Het ghe!!!\n");
        return;
    }

    struct Ticket tk;

    sprintf(tk.ticketId, "T%03d", ticketCount + 1);
    strcpy(tk.tripId, t->tripId);

    printf("Nhap ten hanh khach: ");
    fgets(tk.passenger.name, sizeof(tk.passenger.name), stdin);
    tk.passenger.name[strcspn(tk.passenger.name, "\n")] = '\0';
    
    while(strlen(tk.passenger.name) == 0 || sscanf(tk.passenger.name, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(tk.passenger.name, sizeof(tk.passenger.name), stdin);
    tk.passenger.name[strcspn(tk.passenger.name, "\n")] = '\0';
}
    printf("Nhap SDT: ");
    fgets(tk.passenger.phone, sizeof(tk.passenger.phone), stdin);
    tk.passenger.phone[strcspn(tk.passenger.phone, "\n")] = '\0';
    
    while(strlen(tk.passenger.phone) == 0 || sscanf(tk.passenger.phone, " %c", &check) != 1) {
    printf("Khong duoc de trong! Vui long nhap lai: ");
    fgets(tk.passenger.phone, sizeof(tk.passenger.phone), stdin);
    tk.passenger.phone[strcspn(tk.passenger.phone, "\n")] = '\0';
}
    printf("Nhap so ghe (1 -> %d): ", t->totalSeats);
    scanf("%d", &tk.seatNumber);
    while (getchar() != '\n');

    if (tk.seatNumber <= 0 || tk.seatNumber > t->totalSeats) {
        printf("!!! So ghe khong hop le!\n");
        return;
    }
    for (int i = 0; i < ticketCount; i++) {
        if (strcmp(tickets[i].tripId, t->tripId) == 0 &&
            tickets[i].seatNumber == tk.seatNumber) {
            printf("!!! Ghe nay da duoc dat!\n");
            return;
        }
    }

    printf("Nhap gia ve: ");
    scanf("%lf", &tk.price);
    while (getchar() != '\n');

    tk.paymentStatus = 0;  
    strcpy(tk.date, t->date);

    tickets[ticketCount++] = tk;
    t->bookedSeats++;

    printf("=> Dat ve thanh cong! Ma ve: %s\n", tk.ticketId);
}
void checkTicket() {
	printf("=== KIEM TRA VE ===\n");
    if (ticketCount == 0) {
        printf("Chua co ve nao!\n");
        return;
    }

    char id[20];
    printf("Nhap ma ve can kiem tra: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < ticketCount; i++) {
        if (strcmp(tickets[i].ticketId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("!!! Ma ve khong ton tai!\n");
        return;
    }

    struct Ticket *tk = &tickets[index];

    printf("\n=== THONG TIN VE ===\n");
    printf("Ma ve: %s\n", tk->ticketId);
    printf("Ma chuyen: %s\n", tk->tripId);
    printf("Ten KH: %s\n", tk->passenger.name);
    printf("SDT: %s\n", tk->passenger.phone);
    printf("So ghe: %d\n", tk->seatNumber);
    printf("Ngay: %s\n", tk->date);
    printf("Gia: %.2lf\n", tk->price);
    printf("Trang thai thanh toan: %s\n",
           tk->paymentStatus == 0 ? "Chua thanh toan" : "Da thanh toan");
}


void listTripsPaging() {
	printf("=== LIET KE CHUYEN XE ===\n");
    if (tripCount == 0) {
        printf("Khong co chuyen xe de hien thi!\n");
        return;
    }

    char input[20];
    int pageSize = 10;
    int pageNumber = 1;

    
    printf("Nhap so dong moi trang: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &pageSize) != 1 || pageSize <= 0)
        pageSize = 10;

    
    printf("Nhap so trang muon xem: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &pageNumber) != 1 || pageNumber <= 0)
        pageNumber = 1;

    int totalPages = (tripCount + pageSize - 1) / pageSize;

    if (pageNumber > totalPages) {
        printf("So trang khong hop le! Chi co %d trang.\n", totalPages);
        return;
    }
    while (1) {
        int start = (pageNumber - 1) * pageSize;
        int end = start + pageSize;
        if (end > tripCount) end = tripCount;

        printf("\n================ DANH SACH CHUYEN (Trang %d / %d) ================\n",
               pageNumber, totalPages);
        printf("%-10s | %-15s | %-15s | %-12s | %-10s\n",
               "TripID", "Departure", "Destination", "Date", "Seats");
        printf("--------------------------------------------------------------------\n");

        for (int i = start; i < end; i++) {
        	
            printf("%-10s | %-15s | %-15s | %-12s | %2d/%d\n",
                   trips[i].tripId,
                   trips[i].departure.name,
                   trips[i].destination.name,
                   trips[i].date,
                   trips[i].bookedSeats,
                   trips[i].totalSeats);
        }
        printf("--------------------------------------------------------------------\n");
        printf("Trang %d / %d\n", pageNumber, totalPages);

        printf("Nhap lenh (n = Next, p = Previous, q = Quit): ");
        fgets(input, sizeof(input), stdin);
        char cmd = input[0];

        if (cmd == 'n' || cmd == 'N') {
            if (pageNumber < totalPages) pageNumber++;
            else printf("Dang o trang cuoi!\n");
        } else if (cmd == 'p' || cmd == 'P') {
            if (pageNumber > 1) pageNumber--;
            else printf("Dang o trang dau!\n");
        } else if (cmd == 'q' || cmd == 'Q') {
            break;
        } else {
            printf("Lenh khong hop le!\n");
        }
    }
}
void payTicket() {
	printf("=== DAT VE ===\n");
    if (ticketCount == 0) {
        printf("Chua co ve nao trong he thong!\n");
        return;
    }
    char id[20];
    printf("Nhap ma ve muon thanh toan: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    if (strlen(id) == 0) {
        printf("Ma ve khong duoc de trong!\n");
        return;
    }
    int index = -1;
    for (int i = 0; i < ticketCount; i++) {
        if (strcmp(tickets[i].ticketId, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("!!! Khong tim thay ma ve !!!\n");
        return;
    }
    struct Ticket *tk = &tickets[index];

    if (tk->paymentStatus == 1) {
        printf("!!! Ve nay da duoc thanh toan truoc do !!!\n");
        return;
    }
    printf("\n=== THONG TIN VE CAN THANH TOAN ===\n");
    printf("Ma ve: %s\n", tk->ticketId);
    printf("Ten hanh khach: %s\n", tk->passenger.name);
    printf("SDT: %s\n", tk->passenger.phone);
    printf("So ghe: %d\n", tk->seatNumber);
    printf("Gia ve: %.2lf\n", tk->price);
    printf("-----------------------------------------\n");

    char confirm[5];
    printf("Xac nhan thanh toan? (y/n): ");
    fgets(confirm, sizeof(confirm), stdin);

    if (confirm[0] == 'y' || confirm[0] == 'Y') {
        tk->paymentStatus = 1;
        printf("=> Thanh toan thanh cong! Ve da duoc xac nhan.\n");
    } else {
        printf("=> Da huy thanh toan.\n");
    }
}
void lockOrCancelTicket() {
    printf("=== KHOA / HUY VE ===\n");

    if (ticketCount == 0) {
        printf("Chua co ve nao trong he thong!\n");
        return;
    }

    char id[20];
    printf("Nhap ma ve: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < ticketCount; i++) {
        if (strcmp(tickets[i].ticketId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("!!! Khong tim thay ma ve !!!\n");
        return;
    }

    struct Ticket *tk = &tickets[index];

    if (tk->paymentStatus == 2) {
        printf("!!! Ve da bi KHOA, khong the thao tac !!!\n");
        return;
    }
    if (tk->paymentStatus == -1) {
        printf("!!! Ve da bi HUY, khong the thao tac !!!\n");
        return;
    }

    printf("1. Khoa ve\n");
    printf("2. Huy ve\n");
    printf("Chon: ");
    char c[10];
    fgets(c, sizeof(c), stdin);
    int opt = atoi(c);

    if (opt == 1) {
        tk->paymentStatus = 2; 
        printf("=> Ve da duoc KHOA thanh cong!\n");
    } 
    else if (opt == 2) {
        if (tk->paymentStatus != 0) {
            printf("!!! Chi duoc huy ve CHUA THANH TOAN !!!\n");
            return;
        }

        for (int i = 0; i < tripCount; i++) {
            if (strcmp(trips[i].tripId, tk->tripId) == 0) {
                trips[i].bookedSeats--;
                break;
            }
        }

        tk->paymentStatus = -1;
        printf("=> HUY ve thanh cong!\n");
    } 
    else {
        printf("Lua chon khong hop le!\n");
    }
}
void revenueReport() {
    printf("=== BAO CAO THONG KE & DOANH THU ===\n");

    if (tripCount == 0) {
        printf("Khong co chuyen xe nao!\n");
        return;
    }

    printf("%-10s | %-10s | %-10s | %-10s | %-12s\n",
           "TripID", "Dat ve", "Thanh toan", "Huy ve", "Doanh thu");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < tripCount; i++) {
        int booked = 0, paid = 0, canceled = 0;
        double revenue = 0;

        for (int j = 0; j < ticketCount; j++) {
            if (strcmp(tickets[j].tripId, trips[i].tripId) == 0) {

                if (tickets[j].paymentStatus == 1) {
                    paid++;
                    revenue += tickets[j].price;
                } 
                else if (tickets[j].paymentStatus == -1) {
                    canceled++;
                } 
                else if (tickets[j].paymentStatus == 0) {
                    booked++;
                }
            }
        }

        printf("%-10s | %-10d | %-10d | %-10d | %-12.2lf\n",
               trips[i].tripId, booked + paid + canceled, paid, canceled, revenue);
    }
}


int main() {
    int choice;
    do {
    	system("cls");
        printf("|=============== Quan ly Ve Xe Khach ===============|\n");
        printf("|                1. Them Chuyen Di                  |\n");
        printf("|===================================================|\n");
        printf("|           2. Cap Nhat Danh Sach Chuyen            |\n");
        printf("|===================================================|\n");
        printf("|                   3. Dat Ve                       |\n");
        printf("|===================================================|\n");
        printf("|           4. Kiem Tra Tinh Trang Ve               |\n");
        printf("|===================================================|\n");
        printf("|           5. Liet Ke Chuyen Xe (Paging)           |\n");
        printf("|===================================================|\n");
        printf("|                6. Thanh Toan Ve                   |\n");
        printf("|===================================================|\n");
        printf("|                7. Khoa / Huy Ve                   |\n");
        printf("|===================================================|\n");
        printf("|         8. Bao Cao Thong Ke & Doanh Thu           |\n");
        printf("|===================================================|\n");
        printf("|                   0. Thoat                        |\n");
        printf("|===================================================|\n");
        
        char error[10];
        printf("Moi ban nhap lua chon: ");
        fgets(error, sizeof(error), stdin);
        if (error[0] == '\n') {
            printf("Ban chua nhap lua chon. Thoat chuong trinh\n");
            return 0;
        }
        if (sscanf(error, "%d ", &choice) != 1) {
            printf("Lua chon khong hop le. Thoat chuong trinh\n");
            return 0;
        }
        
        switch (choice) {
            case 1: addTrip(); 
            system("pause");
            break;
            
            case 2: updateTrip(); 
            system("pause");
            break;
           
            case 3: bookTicket(); 
            system("pause");
            break;
            
            case 4: checkTicket(); 
            system("pause");
            break;
            
            case 5: listTripsPaging(); 
            system("pause");
            break;
            
            case 6: payTicket(); 
            system("pause");
            break;
            
            case 7: lockOrCancelTicket(); 
            system("pause");
            break;
            
            case 8: revenueReport(); 
            system("pause");
            break;
            
            case 0: break;
            
            default: printf("Lua chon khong hop le!\n");
            system("pause");
            system("cls");
        }
    } while (choice != 0);

    return 0;
}
