#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define exit_value 3
#define item_name 100
#include "file_utility.h"
#include "model.h"
#include "env.h"


void POS();
void MainMenu();
void addItem();
void updateItem();
void viewItem();
void deleteItem();
void Accounting();
void Inventory()
{
    int inventory_choice;
    printf("\n\t\t==================================================\n");
    printf("\t\t||\t    Inventory Management System \t||\n");
	printf("\t\t==================================================");
	printf("\n\t\t||\t        1. Add Item                     ||");
    printf("\n\t\t||\t        2. Update Item                  ||");
	printf("\n\t\t||\t        3. Delete Item                  ||");
	printf("\n\t\t||\t        4. View Item                    ||");
	printf("\n\t\t||\t        5. Go Back                      ||");
	printf("\n\t\t==================================================\n");
    printf("\n\t\t          Select Transaction : ");
    scanf("%d",&inventory_choice);
    switch(inventory_choice)
    {
        case 1:
        addItem();
        break;

        case 2:
        updateItem();
        break;

        case 3:
        deleteItem();
        break;

        case 4:
        viewItem();
        break;

        case 5:
        MainMenu();
        break;

    }
}
void POS()          //Point of sale system
{
    char pos_item[item_name]; 
    int item_code,item_quantity,item_price,pos_user_choice,total=0;
    printf("\n\t\t==================================================\n");
    printf("\t\t||\t    Point Of Sale system\t\t||\n");
    printf("\t\t==================================================\n");
    printf("\n\tEnter Item's Code: ");
    scanf("%d",&item_code);
    printf("\n\tEnter Item's Quantity: ");
    scanf("%d",&item_quantity);
    printf("\n\tEnter Item's Sale Price: ");
    scanf("%d",&item_price);
    total = (item_quantity * item_price);
    printf("\n\tTotal price = %d\n\n",total);

    printf("\t\t==================================================\n");
    printf("\t\t||\t Press 0 for stop adding items! \t||\n");
    printf("\t\t||\t Press 1 for keep adding items! \t||\n");
    printf("\t\t==================================================\n");
    printf("\t\t Enter your choice: ");
    scanf("%d",&pos_user_choice);
    while (pos_user_choice ==1)
    {
        printf("\n\tEnter Another Item's Code: ");
        scanf("%d",&item_code);
        printf("\n\tEnter Another Item's Quantity: ");
        scanf("%d",&item_quantity);
        printf("\n\tEnter Another Item's Sale Price: ");
        scanf("%d",&item_price);
        total += (item_quantity * item_price);
        printf("\n\tTotal price = %d\n\n",total);
        printf("\t\t==================================================\n");
        printf("\t\t||\t Press 0 for stop adding items! \t||\n");
        printf("\t\t||\t Press 1 for keep adding items! \t||\n");
        printf("\t\t==================================================\n");
        printf("\t\t Enter your choice: ");
        scanf("%d",&pos_user_choice);
    }
    if (pos_user_choice ==0)
    {
        printf("\n\n\t\t Here is the bill receipt to print !!!");
        printf("\n\n\tDate 30/11/2022");
        printf("\n\t===============================================================\n");
        printf("\tITEM CODE\t  ITEM NAME\t  PRICE\t   QTY\t    TOTAL PRICE");
        printf("\n\t===============================================================\n");
        printf("\t1001\t\t    Orange\t     2\t    10\t\t 20\n");
        printf("\t1002\t\t    Shirt\t     5\t    30\t\t 150\n");
        printf("\t1005\t\t    Cake\t     10\t    5\t\t 50\n");
        MainMenu();
    }
}
void addItem()
{
    char add_item[item_name];
    int item_cost,item_quantity,item_price;
    printf("\n\tInsert New Item's Name:");
    scanf("%s",add_item);
    printf("\n\tInsert New Item's Cost:");
    scanf("%d",&item_cost);
    printf("\n\tInsert the quantity of New Item:");
    scanf("%d",&item_quantity);
    printf("\n\tInsert sale price of New Item:");
    scanf("%d",&item_price);
    viewItem();
}
void updateItem()
{
    char update_item[item_name];
    int item_cost,item_quantity,item_price;
    printf("\n\tEnter Item's Name:");
    scanf("%s",update_item);
    printf("\n\tEnter Item's Cost:");
    scanf("%d",&item_cost);
    printf("\n\tEnter the quantity of Item:");
    scanf("%d",&item_quantity);
    printf("\n\tEnter sale price of Item:");
    scanf("%d",&item_price);
    viewItem();
}
void deleteItem()
{
    int deleteItem_code;
    char delete_item[item_name];
    printf("\n\tEnter the code of item that you want to delete: ");
    scanf("%d",&deleteItem_code);
    printf("\n\tEnter the name of item that you want to delete: ");
    scanf("%s",delete_item);
    viewItem();
}

void viewItem()
{
    printf("\n\n\t\t\t\tLIST OF ITEMS");
    printf("\n\t===============================================================\n");
    printf("\tITEM CODE\t  ITEM NAME\t  COST\t   QTY\t    SALE_PRICE");
    printf("\n\t===============================================================");
    printf("\n\t0001  \t\t    orange\t   1\t    10\t\t2");
    printf("\n\t0002  \t\t    apple\t   2\t    10\t\t4");
    printf("\n\t===============================================================");
    Inventory();

}

void Accounting()
{
    printf("\n\t==============================================================================\n");
    printf("\t\t\t\t\tAccounting System\t\t\t\t");
    printf("\n\t==============================================================================\n");
    printf("\n\t Date - 20/12/2022\n");
    printf("\n\tThe below is the list of items that are being sold on this day");
    printf("\n\t==============================================================================\n");
    printf("\tITEM CODE\t  ITEM NAME\t  COST\t   QTY\t    SALE_PRICE    PROFIT");
    printf("\n\t==============================================================================\n");
    printf("\t1001\t\t   Apple\t   10\t   100\t\t 20\t   1000\n");
    printf("\t1002\t\t   Orange\t   5\t   100\t\t 15\t   1000\n");
    printf("\t1002\t\t   Ball Pen\t   3\t   100\t\t 5\t   200\n");
    printf("\t==============================================================================\n");
    printf("\t\t\t\t\t\t\t    TOTAL PROFIT | 2200");
    MainMenu();

}
void Exit()
{
    char Exit_str[exit_value];
    int count=0;
    //printf("\n\n\t\t===============================================");
    printf("\n\t\tAre you sure do you want to exit (Yes or No): "); 
  
    scanf("%s",Exit_str); 
    for(int i=0;i<3;i++)
    {
        int exit_code = Exit_str[i];
        if (exit_code == 89 || exit_code == 69 || exit_code == 83 || exit_code == 121 || exit_code ==101 || exit_code ==115)
        {
            count++;
        }
        else if (exit_code == 78 || exit_code == 79 || exit_code == 110 || exit_code == 111)
        {
            count++;
        }
    }
    if (count==3)
    {
        printf("\n\t --------------------------------------------------------------");
        printf("\n\t|    System is terminated!!Thanks for choosing our software.\t|");
        printf("\n\t --------------------------------------------------------------\n\n\n");

    }
    else if (count == 2)
    {
        system("clear");
        MainMenu();
    }
    
    
}

void MainMenu()
{
    int user_choice;
    printf("\n\n\n\n");
	    printf("\t  ____  _                             _       ____  _                 \n");
        printf("\t / ___|| |__   ___   __ _ _   _ _ __ ( )___  / ___|| |_ ___  _ __ ___ \n");
        printf("\t \\___ \\| '_ \\ / _ \\ / _` | | | | '_ \\|// __| \\___ \\| __/ _ \\| '__/ _ \\\n");
        printf("\t  ___) | | | | (_) | (_| | |_| | | | | \\__ \\  ___) | || (_) | | |  __/\n");
        printf("\t |____/|_| |_|\\___/ \\__, |\\__,_|_| |_| |___/ |____/ \\__\\___/|_|  \\___|\n");
        printf("\t                    |___/                                            \n"); 
		printf("\t\t===============================================");
		printf("\n\t\t||            M A I N  *  M E N U            ||");
		printf("\n\t\t===============================================");
		printf("\n\t\t||                                           ||");
		printf("\n\t\t||        1. Inventory Management System     ||");
    	printf("\n\t\t||        2. POS System                      ||");
		printf("\n\t\t||        3. Accounting System               ||");
		printf("\n\t\t||        4. EXIT                            ||");
		printf("\n\t\t||                                           ||");
		printf("\n\t\t===============================================\n");
		printf("\n\t\t          Select Transaction : ");
        
        scanf("%d",&user_choice);
        system("clear");

        switch(user_choice)
        {
            case 1:
            Inventory();
            break;

            case 2:
            POS();
            break;

            case 3:
            Accounting();
            break;

            case 4:
            Exit();
            break;
        }

}
int main()
{
    MainMenu();
    return 0;
}

void add_item(){

}
void remove_item(){

}
void check_item(){

}
void profit(){

}
void total_transaction(){

}

void customer_buy(){

}
void transaction(){
    
}




