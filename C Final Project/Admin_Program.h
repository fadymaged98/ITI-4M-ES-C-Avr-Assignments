
#ifndef MAIN_C_ADMIN_PROGRAM_H
#define MAIN_C_ADMIN_PROGRAM_H

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



bank_account_for_ptr *admin_create_bank_account();
void admin_bank_account_add(bank_account_for_ptr *current_account);
bank_account_for_ptr *admin_search_bank_account(u32 acc_id);
bool admin_display_bank_account(bank_account_for_ptr *selected_account);
u8 admin_make_transaction(bank_account_for_ptr *selected_account);
void admin_change_account_status(bank_account_for_ptr *selected_account);
void admin_get_cash(bank_account_for_ptr *selected_account);
void admin_deposit_cash(bank_account_for_ptr *selected_account);



#endif //MAIN_C_ADMIN_PROGRAM_H
