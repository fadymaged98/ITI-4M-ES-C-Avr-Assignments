#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "STD_Types.h"
#include "Admin_Program.h"
#include "Client_Program.h"
#include "Menus_Interface.h"






int main() {
    bool exit_program = 0;
    do {
        int MODE = main_menu();
        switch (MODE) {
            case 1:
                if (admin_menu()) {
                    admin_privilages();
                }
                break;
            case 2:
                if(client_menu()){
                    client_privilages();
                }
                break;
            case 3:
                exit_program = 1;
                break;
            default:
                printf("\t\tWrong Choice!\n\n");
                break;
        }
    } while (!exit_program);
    printf("...................Exiting...................");
    return 0;
}
