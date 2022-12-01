#ifndef MAIN_C_ACCOUNTS_DATABASE_H
#define MAIN_C_ACCOUNTS_DATABASE_H

typedef struct bank_account bank_account_for_ptr;


 struct bank_account{
    u8 full_name[100];
    u8 full_address[100];
    u8 national_id[100];
    u8 age;
    u8 guardian_name[100];
    u8 guardian_id[100];
    u8 account_status;
    f32 balance;
    u32 password;
    u32 account_id;
    bank_account_for_ptr *next;
    bank_account_for_ptr *prev;
};

bank_account_for_ptr *first = NULL;
bank_account_for_ptr *last = NULL;


bank_account_for_ptr *create_bank_account(){

    bank_account_for_ptr *new_account = (bank_account_for_ptr *) malloc(sizeof(bank_account_for_ptr));


    printf("Enter Full Name    :");
    scanf("%[^\n]%*c", new_account->full_name);
    fflush(stdin);

    printf("Enter Full Address :");
    scanf("%[^\n]%*c", new_account->full_address);
    fflush(stdin);

    printf("Enter National ID  :");
    scanf("%[^\n]%*c", new_account->national_id);
    fflush(stdin);

    printf("Enter Age          :");
    scanf("%d", &(new_account->age));
    fflush(stdin);

    srand(time(NULL));

    u32 lower_id = 1000000000;
    u32 upper_id = 1410065407;

    u32 lower_pass = 1000;
    u32 upper_pass = 9999;

    new_account->account_id = (rand() % (upper_id - lower_id + 1)) + lower_id;

    new_account->password = (rand() % (upper_pass - lower_pass + 1)) + lower_pass;

    new_account->balance = 0.0;

    new_account->account_status = 'A';


    if (new_account->age < 21) {
        printf("Enter Guardian Name:");
        scanf("%[^\n]%*c", new_account->guardian_name);
        fflush(stdin);
        printf("Enter Guardian ID  :");
        scanf("%[^\n]%*c", new_account->guardian_id);
        fflush(stdin);
    }


    printf("\n\nYour Account ID       :%lu", new_account->account_id);
    printf("\nYour Account Password :%lu\n", new_account->password);

    new_account->next = NULL;
    new_account->prev = NULL;


    return new_account;
}

void bank_account_add(bank_account_for_ptr* current_account){
    if (first == NULL) {
        first = last = current_account;
    }else{
        current_account->prev = last;
        last->next = current_account;
        last = current_account;
    }
}

bank_account_for_ptr * search_bank_account(u32 acc_id){
    bank_account_for_ptr *current_account = first;
    while (first != NULL) {
        if (current_account->account_id == acc_id) {
            return current_account;
        } else {
            current_account = current_account->next;
        }
    }
    return NULL;
}

bool display_bank_account(bank_account_for_ptr *selected_account) {
    if (selected_account == NULL) {
        printf("Wrong Bank Account Selected!\n"
               "Please Choose Correct One.\n");
        return 0;
    }else {

        printf("\n1. Full Name        : ");
        for (int i = 0; selected_account->full_name[i] != '\0'; ++i) {
            printf("%c", selected_account->full_name[i]);
        }


        printf("\n2. Full Address     : ");
        for (int i = 0; selected_account->full_address[i] != '\0'; ++i) {
            printf("%c", selected_account->full_address[i]);
        }


        printf("\n3. National ID      : ");
        for (int i = 0; selected_account->national_id[i] != '\0'; ++i) {
            printf("%c", selected_account->national_id[i]);
        }



        printf("\n4. Age              : %d",selected_account->age);

        if (selected_account->age < 21) {
            printf("\n5. Guardian Name    : ");
            for (int i = 0; selected_account->guardian_name[i] != '\0'; ++i) {
                printf("%c", selected_account->guardian_name[i]);
            }

            printf("\n6. Guardian ID      : ");
            for (int i = 0; selected_account->guardian_id[i] != '\0'; ++i) {
                printf("%c", selected_account->guardian_id[i]);
            }
        } else {
            printf("\n5. No Guardian Name.");
            printf("\n6. No Guardian ID.");
        }

        printf("\n7. Account Status   : ");
        if (selected_account->account_status == 'A') {
            printf("Active.");
        }else if(selected_account->account_status == 'R') {
            printf("Restricted.");
        }else if(selected_account->account_status == 'S') {
            printf("Suspended.");
        }


        printf("\n8. Account Balance  : %f", selected_account->balance);

        printf("\n9. Account Password : %lu", selected_account->password);

        printf("\n10. Account ID      : %lu\n", selected_account->account_id);

        return 1;
    }

}

u8 make_transaction(bank_account_for_ptr *selected_account){
    printf("Enter The Account ID To Transfer Money To:");
    u32 trans_acc_id;
    scanf("%lu", &trans_acc_id);

    bank_account_for_ptr *trans_acc = search_bank_account(trans_acc_id);

    if (selected_account->account_status == 'A' && trans_acc->account_status == 'A') {
        f32 money;

        while (1) {
            printf("Enter Money You Want To Transfer :");
            scanf("%f", &money);
            fflush(stdin);
            if(money > selected_account->balance) {
                printf("Not Sufficient Balance!\n");
            } else {
                trans_acc->balance += money;
                selected_account->balance -= money;
                printf("----------------------Done-------------------\n");
                break;
            }
        }

    } else {
        printf("One Of The Accounts Is NOT ACTIVE. It May Be Closed Or Restricted.");
    }

}

void change_account_status(bank_account_for_ptr *selected_account){
    u8 new_status;
    printf("Enter New Status \n(A ---> Active.)\n(R ---> Restricted.)"
           "\n(S ---> Suspended.)");
    printf("\n\nYour Choice:");
    scanf("%c", &new_status);
    fflush(stdin);
    selected_account->account_status = new_status;
    printf("----------------------Done-------------------\n");
}

void get_cash(bank_account_for_ptr *selected_account){
    f32 cash;
    printf("Enter Cash Required:");
    scanf("%f", &cash);
    fflush(stdin);
    selected_account->balance -= cash;
    printf("Your New Balance is : %f\n", selected_account->balance);
    printf("----------------------Done-------------------\n");
}

void deposit_cash(bank_account_for_ptr *selected_account){
    f32 cash;
    printf("Enter Cash Required:");
    scanf("%f", &cash);
    fflush(stdin);
    selected_account->balance += cash;
    printf("Your New Balance is : %f\n", selected_account->balance);
    printf("----------------------Done-------------------\n");
}

#endif //MAIN_C_ACCOUNTS_DATABASE_H
