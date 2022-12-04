#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "STD_Types.h"
#include "Admin_Program.h"
#include "Client_Program.h"
#include "Menus_Interface.h"


void separation_line(){

    // To Create A line of "_" For Separation
    u8 ursc_no = 45;
    while (ursc_no--) {
        printf("-");
    }
    printf("\n");
}

//_____________________________________________________________________________________________________________________

int main_menu(){
    int main_mode_selection;
    separation_line();
    printf("|||||||||||| Welcome To ITI Bank ||||||||||||\n");
    separation_line();
    printf("For Administrator Mode:    Press 1.\n"
           "For Client Mode:           Press 2.\n"
           "To EXIT:                   Press 3.\n"
           "\nYour Choice:");

    scanf("%d", &main_mode_selection);
    fflush(stdin);
    separation_line();
    return main_mode_selection;
}

//_____________________________________________________________________________________________________________________

bool admin_menu(){
    u8 entered_username[100]={'\0'};
    u8 actual_username[]= "admin";
    int entered_password;
    int actual_password=1111;

    printf("               Welcome Admin\n");
    printf("               -------------\n");
    printf("Please Enter Username and Password.....\n\n");
    printf("Username:");
    scanf("%s", entered_username);
    fflush(stdin);
    printf("Password:");
    scanf("%d", &entered_password);
    fflush(stdin);

    if ((entered_username[0] != 'a') || (entered_username[1] != 'd') || (entered_username[2] != 'm') ||
        (entered_username[3] != 'i') || (entered_username[4] != 'n') || entered_password != actual_password)
    {
        printf("\nWrong Username or Password !!\n");
        return 0;
    }
    return 1;
}

//_____________________________________________________________________________________________________________________

void admin_privilages(){
    u8 mode_selection;
    u8 existing_acc_mode_select;
    bool exit_to_prev = 0;
    bool exit_mode = 0;
    u32 entered_id;
    while (!exit_mode) {
        separation_line();
        printf("1.To Create New Account:        Press 1.\n"
               "2.To Open Existing Account:     Press 2.\n"
               "3.To Exit System:               Press 3.\n");
        printf("\nYour Choice:");
        scanf("%d", &mode_selection);
        fflush(stdin);
        separation_line();
        switch (mode_selection) {
            case 1:
                admin_bank_account_add(admin_create_bank_account());
                break;
            case 2:
                do {
                    printf("Account ID:");
                    scanf("%lu", &entered_id);
                    fflush(stdin);
                } while (!admin_display_bank_account(admin_search_bank_account(entered_id)));
                while (!exit_to_prev) {
                    separation_line();
                    printf("1.To Make Transaction      :         Press 1.\n"
                           "2.To Change Account Status :         Press 2.\n"
                           "3.To Get Cash              :         Press 3.\n"
                           "4.To Deposit In Account    :         Press 4.\n"
                           "5.To Return To Prev. Menu  :         Press 5.\n");
                    printf("\nYour Choice:");
                    separation_line();
                    scanf("%d", &existing_acc_mode_select);
                    fflush(stdin);
                    switch (existing_acc_mode_select) {
                        case 1:
                            admin_make_transaction(admin_search_bank_account(entered_id));
                            break;
                        case 2:
                            admin_change_account_status(admin_search_bank_account(entered_id));
                            break;
                        case 3:
                            admin_get_cash(admin_search_bank_account(entered_id));
                            break;
                        case 4:
                            admin_deposit_cash(admin_search_bank_account(entered_id));
                            break;
                        case 5:
                            exit_to_prev = 1;
                            break;
                    }
                }
                break;
            case 3:
                exit_mode = 1;
                break;
        }
    }
}

//_____________________________________________________________________________________________________________________

u32 client_menu() {
    u32 entered_acc_id;
    u32 entered_password;
    bool id_check = 0;
    bool pass_check = 0;


    printf("               Welcome Client\n");
    printf("               -------------\n");
    while (!(id_check & pass_check)) {

        printf("Please Enter Account ID and Password.....\n\n");
        printf("Account ID:");
        scanf("%lu", &entered_acc_id);
        fflush(stdin);
        printf("Password:");
        scanf("%lu", &entered_password);
        fflush(stdin);

        bank_account_for_ptr *id_validation = admin_search_bank_account(entered_acc_id);
        if (id_validation != NULL) {
            id_check = 1;
            if (id_validation->password == entered_password) {
                pass_check = 1;
            }
        }
        if (id_check & pass_check) {
            return entered_acc_id;
        }else {
            printf("\nWrong Account ID or Password.\n");
            return 0;
        }
    }

}

//_____________________________________________________________________________________________________________________

void client_privilages(u32 entered_acc_id) {
    bool exit_to_prev = 0;
    u8 client_mode_selection;
    while (!exit_to_prev) {
        separation_line();
        printf("1.To Make Transaction      :         Press 1.\n"
               "2.To Get Cash              :         Press 2.\n"
               "3.To Deposit In Account    :         Press 3.\n"
               "4.To Return To Prev. Menu  :         Press 4.\n");
        printf("\nYour Choice:");
        scanf("%d", &client_mode_selection);
        fflush(stdin);
        separation_line();

        switch (client_mode_selection) {
            case 1:
                make_client_transaction(admin_search_bank_account(entered_acc_id));
                break;
            case 2:
                get_client_cash(admin_search_bank_account(entered_acc_id));
                break;
            case 3:
                deposit_client_cash(admin_search_bank_account(entered_acc_id));
                break;
            case 4:
                exit_to_prev = 1;
                break;
            default:
                printf("\t\tWrong Choice!\n");
                break;
        }

    }
}