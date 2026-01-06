    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    //== GLOBAL VARIABLES ==//
    char username[30];
    char password[30];
    int Registered = 0;

    //===== BUS DATA =====//
    struct Bus
    {
    int BusNumber;
    char SourceCity[50];
    char DestinationCity[50];
    int TotalSeats;
    int AvailableSeats;
    int BookedSeats;
    float fare;
    };
    //==== FUNCTION DECLARATIONS =====//
    struct Bus buses[3]=
    {
        {101,"Bihar","Delhi",50,45,0,500},
        {102,"Patna","Kolkata",50,47,0,400},
        {103,"Rajsthan","Jaipur",55,45,0,600}
    };
    int totalBuses = 3;

    void signup();
    void login();
    void menu();
    void CheckBusDetails();
    void BookTicket();
    void CancelTicket();
    int hasAlphabet(char str[]);
    int payment(float amount);

    int main()
    {
        int choice;
        do
        {
            printf("\n\033[1;31m*********** BUS RESERVATION SYSTEM **********");
            printf("\033[1;33m\n1. Signup");
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
                    printf("\n\033[1;34mThank you for using the Reservation System!\033[0m");
                    break;
                default:
                    printf("\nInvalid choice! Please try again.\n");
            }
        }
        while(choice != 3);

        return 0;
    }
            //====CHECK ALPHABETS ======
    int hasAlphabet(char str[])
    {
        int i;
        for(i = 0; str[i]!='\0';i++)
        {
            if(isalpha(str[i]))
            return 1;
        }
        return 0;
    }

    //======= SIGNUP =======
    void signup()
    {
        if(Registered )
        {
            printf("\n\033[1;32mAccount already registered. Please login.\033[0m\n");
            return;
        }

        printf("\n\033[1;35m<====== USER REGISTRATION ======>");
        printf("\n\033[1;36mEnter Username:");
        scanf(" %[^\n]",username);

        if(strlen(username) < 6|| !hasAlphabet(username))
        {
            printf("\n\033[1;31mInvalid Username!Minimum 6 char with at least one alphabet.");
            return;
        }

        printf("\n\033[1;36mEnter Password:");
        scanf("%s",password);

        if(strlen(password) < 6||!hasAlphabet(password))
        {
            printf("\n\033[1;31mInavalid password!minimum 6 characters with at least one alphabet.\033[0m");
            return;
        }

        Registered = 1;
        printf("\n\033[1;32mRegistered Successfully!\n");
    }

    //======= LOGIN =======
    void login()
    {
        char loginUsername[40];
        char loginPassword[40];

        if(!Registered )
        {
            printf("\n\033[1;32mPlease signup first!");
            return;
        }

        printf("\n\033[1;35m<===== USER LOGIN =====>");
        printf("\n\033[1;33mEnter a Username:");
        scanf(" %[^\n]", loginUsername);

        printf("Enter Password: ");
        scanf("%s", loginPassword);

        if(strcmp(username, loginUsername) == 0 && strcmp(password, loginPassword) == 0)
        {
            printf("\n\033[1;32mLogin Successful! Welcome %s\033[0m\n", loginUsername);
            menu();
        }
        else
        {
            printf("\n\033[1;31mLogin Failed! Invalid Username or Password.");
        }
    }

    //======= USER MENU =======
    void menu()
    {
        int choice;
        do
        {
            printf("\n\033[1;35m<======= USER MENU =======>");
            printf("\n1. Book Ticket");
            printf("\n2. Cancel Ticket");
            printf("\n3. Check Bus Details");
            printf("\n4. Logout");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    BookTicket();
                    break;
                case 2:
                    CancelTicket();
                    break;
                case 3:
                    CheckBusDetails();
                    break;
                case 4:
                    printf("\n\033[1;37mLogged out successfully.\n");
                    break;
                default:
                    printf("\n\033[1;35mInvalid choice!\n");
            }
        }
        while(choice != 4);
    }
    int payment(float amount)
    {
        int option;
        char confirm;
        printf("\n\033[1;33m======= ONLINE PAYMENT =======");
        printf("\n\033[1;37mAmount to pay:Rs%.2f",amount);
        printf("\n\033[1;36m1.UPI");
        printf("\n2.Debit Card");
        printf("\n3.Credit Card");
        printf("\n\033[1;35mChoice payment method:");
        scanf("%d",&option);

        if(option < 1 || option > 3)
        {
            printf("\n\033[1;31mInvalid payment option!\033[0m");
            return 0;
        }
        printf("\nConfirm Payment(yes/no):");
        scanf(" %c",&confirm);

        if(confirm == 'y' || confirm == 'Y')
        {
            printf("\n\033[1;32mPayment Sucessfull!\033[0m");
            return 1;
        }
        else
        {
            printf("\n\033[1;31mpayment cancelled!\033[0m");
            return 0;
        }

    }

    //======= BOOK TICKET =======
    void BookTicket()
    {
        int busNumber,seats;
        char choice;
        int count = 0;
        do
        {
            int found = 0;

            printf("\n\033[1;36mEnter a Bus Number:");
            scanf("%d",&busNumber);

            for(int i = 0; i< totalBuses; i++)
            {
                if(buses[i].BusNumber == busNumber)
                {
                    found = 1; //FIXED BUG

                    printf("\nEnter seats to book:");
                    scanf("%d",&seats);

                    if(seats > 0 && seats<=buses[i].AvailableSeats)
                    {
                        float totalAmount = seats * buses[i].fare;
                        int paymentStatus;
                        char retry;
                        //=====PAYMENT WITH RETRY=====//
                        do
                        {
                            paymentStatus = payment(totalAmount);

                            if(paymentStatus)
                            {
                                buses[i].AvailableSeats -= seats;
                                buses[i].BookedSeats += seats;

                                printf("\n\033[1;37mTicket Booked Sucessfully!");
                                printf("\nBus Number %d",buses[i].BusNumber);
                                printf("\nTotal Fare:%.2f",seats * buses[i].fare);
                                count++;
                                break;
                            }
                            else
                            {
                                printf("\n\033[1;33mDo you want to retry payment?(y/n):");
                                scanf(" %c",&retry);
                                
                                if(retry != 'y'&& retry != 'Y')
                                {
                                    printf("\n\033[1;35mBooking Cancelled by User.\033[0m");
                                    break;
                                }
                                  
                            }
                        }while(1);

                    }
                    else
                    {
                        printf("\n\033[1;31mSeats not available!\033[0m");
                    }
                    break;
                }

            }
            if(!found)
            {
                printf("\n\033[1;31mInvalid Bus Number.This is not available in the system.\033[0m");
            }
            if(count>=3)
            {
                printf("\n\033[1;33mMaximu 3 booking allowed.\033[0m");
                break;
            }
            do
            {
                printf("\nBook another bus(yes/no):");
                scanf(" %c",&choice);

                if(choice !='y' && choice!='Y' && choice !='n' && choice !='N')
                {
                    printf("\n\033[1;33mInvalid choice!please enter y or n.\033[0m\n");
                } 
            }
            while(choice!='y'&& choice!='Y'&& choice!='n' && choice!='N');    
                   
        }
        while(choice =='y' || choice == 'Y');  
    }    
    //======= CANCEL TICKET =======
    void CancelTicket()
    {
        int busNumber,seats;

        printf("\n\033[1;34mEnter Bus Number:");
        scanf("%d", &busNumber);
        
        for( int i= 0; i < totalBuses;i++)
        {

            if(buses[i].BusNumber == busNumber)
            {
                
                printf("\nEnter Seats to cancel:");
                scanf("%d",&seats);

                if(seats >0 && seats <= buses[i].BookedSeats)
                {
                    buses[i].BookedSeats -= seats;
                    buses[i].AvailableSeats += seats;
                    
                    printf("\n\033[1;32mTickets Cancelled Successfully!");
                }
                else
                {
                    printf("\n\033[1;31mInvalid cancel seats!!\n"); 
                }
                return;

            }      
                
        } 
        printf("\nBus not Available.please select a valid bus number.\n");    
        
    }

    //======= CHECK BUS DETAILS =======
    void CheckBusDetails()
    {
        
        printf("\n\033[1;33m------------ BUS DETAILS -------------");
        for(int i = 0; i < totalBuses;i++)
        {
            printf("\n\033[1;32mBus Number:      %d",buses[i]. BusNumber);
            printf("\nSource City:      %s",buses[i]. SourceCity);
            printf("\nDestination City: %s",buses[i]. DestinationCity);
            printf("\nTotal Seats:      %d",buses[i]. TotalSeats);
            printf("\nAvailable Seats:  %d",buses[i]. AvailableSeats);
            printf("\nBooked seats:     %d",buses[i]. BookedSeats);
            printf("\nFare per seat:    %.2f",buses[i]. fare);
            

        }
    }
