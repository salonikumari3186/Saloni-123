#include <stdio.h>
#include <string.h>

/* ===== Global User Data ===== */
char username[30];
char password[30];
int isRegistered = 0;

/* ===== Bus Data ===== */
int BusNumber = 101;
char SourceCity[20] = "Bihar";
char DestinationCity[20] = "Delhi";
int TotalSeats = 50;
int AvailableSeats = 45;
float fare = 500.0;

/* ===== Function Declarations ===== */
void signup();
void login();
void menu();
void bookTicket();
void cancelTicket();
void checkBusDetails();

/* ===== Main Function ===== */
int main()
{
    printf("\n===== BUS RESERVATION SYSTEM =====\n");

    int choice;
    do
    {
        printf("\n1. Signup");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                signup();
                break;

            case 2:
                login();
                break;

            case 3:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }
    while(choice != 3);

    return 0;
}

/* ===== Signup Function ===== */
void signup()
{
    if(isRegistered == 1)
    {
        printf("\nAccount already registered. Please login.\n");
        return;
    }

    printf("\n===== USER REGISTRATION =====");
    printf("\nEnter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    isRegistered = 1;
    printf("\nRegistration Successful!\n");
}

/* ===== Login Function ===== */
void login()
{
    char u[30], p[30];

    if(isRegistered == 0)
    {
        printf("\nPlease signup first!\n");
        return;
    }

    printf("\n===== USER LOGIN =====");
    printf("\nEnter Username: ");
    scanf("%s", u);

    printf("Enter Password: ");
    scanf("%s", p);

    if(strcmp(username, u) == 0 && strcmp(password, p) == 0)
    {
        printf("\nLogin Successful! Welcome %s\n", username);
        menu();
    }
    else
    {
        printf("\nInvalid Username or Password!\n");
    }
}

/* ===== Menu Function ===== */
void menu()
{
    int choice;
    do
    {
        printf("\n===== USER MENU =====");
        printf("\n1. Book Ticket");
        printf("\n2. Cancel Ticket");
        printf("\n3. Check Bus Details");
        printf("\n4. Logout");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                cancelTicket();
                break;

            case 3:
                checkBusDetails();
                break;

            case 4:
                printf("\nLogged out successfully.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }
    while(choice != 4);
}

/* ===== Book Ticket ===== */
void bookTicket()
{
    int seats;
    printf("\nEnter number of seats to book: ");
    scanf("%d", &seats);

    if(seats > 0 && seats <= AvailableSeats)
    {
        AvailableSeats -= seats;
        printf("\nTicket Booked Successfully!");
        printf("\nSeats Booked: %d", seats);
        printf("\nTotal Fare: %.2f\n", seats * fare);
    }
    else
    {
        printf("\nNot enough seats available!\n");
    }
}

/* ===== Cancel Ticket ===== */
void cancelTicket()
{
    int seats;
    printf("\nEnter number of seats to cancel: ");
    scanf("%d", &seats);

    if(seats > 0 && AvailableSeats + seats <= TotalSeats)
    {
        AvailableSeats += seats;
        printf("\nTicket Cancelled Successfully!");
        printf("\nSeats Cancelled: %d\n", seats);
    }
    else
    {
        printf("\nInvalid cancellation!\n");
    }
}

/* ===== Check Bus Details ===== */
void checkBusDetails()
{
    printf("\n===== BUS DETAILS =====");
    printf("\nBus Number:       %d", BusNumber);
    printf("\nSource City:      %s", SourceCity);
    printf("\nDestination City: %s", DestinationCity);
    printf("\nTotal Seats:      %d", TotalSeats);
    printf("\nAvailable Seats:  %d", AvailableSeats);
    printf("\nFare per seat:    %.2f\n", fare);
}
