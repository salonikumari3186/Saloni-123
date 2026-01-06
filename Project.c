
#include<stdio.h>
#include<string.h>
//structure for bus,
struct Bus
{

    int busNo;
    char Source_City[20];
    char Destination_City[20];
    int TotalSeats;
    int AvailableSeat;
    float fare; //ticket price
};

int main()
{
    int choice, UserChoice;
    char username[20];
    char password[20];

    struct Bus bus[2] = {
        {101, "Delhi", "Agra", 50, 45, 500.0},
        {102, "Bihar", "Patna", 50, 47, 500.0}
    };

    while(1)
    {
        printf("********* BUS RESERVATION SYSTEM **********\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if(choice == 2)
        {
            printf("Thank you! Exiting..\n");
            break;
        }

        if(choice == 1)
        {
            printf("Please enter username: ");
            scanf("%s",username);
            printf("Please enter password: ");
            scanf("%s",password);

            if(strcmp(username, "saloni") == 0 && strcmp(password, "Welcome@123") == 0)
            {
                printf("Login successful! Welcome, %s\n", username);

                do
                {
                    printf("\n===== User Menu =====\n");
                    printf("1. Book a Ticket\n");
                    printf("2. Cancel a Ticket\n");
                    printf("3. Check Bus Status\n");
                    printf("4. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &UserChoice);

                    if(UserChoice == 1)
                    {
                        int busno, seats;
                        printf("Enter a bus number: ");
                        scanf("%d", &busno);
                        printf("Enter seats: ");
                        scanf("%d", &seats);

                        for(int i = 0; i < 2; i++)
                        {
                            if(bus[i].busNo == busno)
                            {
                                if(bus[i].AvailableSeat >= seats)
                                {
                                    bus[i].AvailableSeat -= seats;
                                    printf("Ticket Booked Successfull! %d seats booked on Bus Number %d\n", seats, busno);
                                }
                                else
                                {
                                    printf("Note seats available!\n");
                                }
                            }
                        }
                    }

                } while(UserChoice != 4);

            }
            else
            {
                printf("Invalid credentials!\n");
            }
        }
    }

    return 0;
}