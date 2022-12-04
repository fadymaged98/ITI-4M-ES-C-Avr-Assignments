#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "STD_Types.h"
#include "Admin_Program.h"
#include "Client_Program.h"

extern bank_account_for_ptr *first;
extern bank_account_for_ptr *last;
//_____________________________________________________________________________________________________________________

u8 make_client_transaction(bank_account_for_ptr *selected_account){
    printf("Enter The Account ID To Transfer Money To:");
    u32 trans_acc_id;
    scanf("%lu", &trans_acc_id);

    bank_account_for_ptr *trans_acc = admin_search_bank_account(trans_acc_id);

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

//_____________________________________________________________________________________________________________________

void get_client_cash(bank_account_for_ptr *selected_account){
    f32 cash;
    printf("Enter Cash Required:");
    scanf("%f", &cash);
    fflush(stdin);
    selected_account->balance -= cash;
    printf("Your New Balance is : %f\n", selected_account->balance);
    printf("----------------------Done-------------------\n");
}

//_____________________________________________________________________________________________________________________

void deposit_client_cash(bank_account_for_ptr *selected_account){
    f32 cash;
    printf("Enter Cash Required:");
    scanf("%f", &cash);
    fflush(stdin);
    selected_account->balance += cash;
    printf("Your New Balance is : %f\n", selected_account->balance);
    printf("----------------------Done-------------------\n");
}
