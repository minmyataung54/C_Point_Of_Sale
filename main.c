#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define exit_value 3
#define item_name 100
#include "file_utility.h"
#include "model.h"
#include "env.h"

void viewPOS();
void POS();
void MainMenu();
void addItem();
void updateItem();
void viewItem();
void deleteItem();
void Accounting();
void viewInventory();
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

        default:
        printf("\n\tYou inputed wrong choice.Please Try Again");
        
        Inventory();
        

    }
}

void customer_bill()
{
    
    time_t t;
    t = time(NULL);
    struct tm *ptr;
    ptr = localtime(&t);
    struct POS pos;
    //char pos_item[item_name]; 
    //int item_code,item_quantity,item_price;
    int pos_user_choice,total=0;
    viewInventory();
    printf("\n\tEnter Bill's ID: ");
    scanf("%d",&pos.bill_id);
    printf("\n\tEnter Item's Code: ");
    scanf("%d",&pos.product_id);
    printf("\n\tEnter Customer's Name: ");
    scanf("%s",pos.customer_name);
    printf("\n\tEnter Item's Quantity: ");
    scanf("%d",&pos.product_quantity);
    if(pos.product_quantity < 0)
    {
        printf("\n\tPlease enter possible quantity.\n");
        customer_bill();
    }
    else{
        printf("\n\tEnter Item's Sale Price: ");
        scanf("%lf",&pos.product_price);
        pos.transaction_datetime.tm_sec = (int)ptr->tm_sec;
        pos.transaction_datetime.tm_min = (int)ptr->tm_min;
        pos.transaction_datetime.tm_hour = (int)ptr->tm_hour;
        pos.transaction_datetime.tm_mday = (int)ptr->tm_mday;
        pos.transaction_datetime.tm_mon = (int)ptr->tm_mon;
        pos.transaction_datetime.tm_year = (int)ptr->tm_year;
        total = (pos.product_quantity * pos.product_price);
        printf("\n\tTotal price = %d\n\n",total);
        new_POS(pos);
        printf("\n\n\t\t Here is the bill receipt to print !!!\n\n");
            //printf("\n\n\tDate 30/11/2022");
            printf("\tTime: %d:%d:%d    Date - %d/%d/%d",pos.transaction_datetime.tm_hour,pos.transaction_datetime.tm_min,pos.transaction_datetime.tm_sec,pos.transaction_datetime.tm_mday,pos.transaction_datetime.tm_mon,pos.transaction_datetime.tm_year);
            printf("\n\t==============================================================================================\n");
            printf("\tBILL ID  \tITEM CODE\t  Customer's NAME\t  PRICE\t\t   QTY\t    TOTAL PRICE");
            printf("\n\t==============================================================================================\n");
            printf("    \t%d      \t%d           \t%s         \t%lf\t    %d   \t%d\n",pos.bill_id,pos.product_id,pos.customer_name,pos.product_price,pos.product_quantity,total);
            
            MainMenu();
    }
}

void viewPOS()
{
    struct POS pos;
    struct tm date;
    printf("\n\tEnter the day that you want to search: ");
    scanf("%d",&date.tm_mday);
    printf("\n\tEnter the month that you want to search: ");
    scanf("%d",&date.tm_mon);
    printf("\n\tEnter the year that you want to search: ");
    scanf("%d",&date.tm_year);
    printf("\n\tDate-%d/%d/%d",date.tm_mday,date.tm_mon,date.tm_year);
    printf("\n\t==============================================================================================\n");
    printf("\tBILL ID  \tITEM CODE\t  Customer's NAME\t  PRICE\t\t   QTY\t    TOTAL PRICE");
    printf("\n\t==============================================================================================\n");
    struct POS *posPtr;
    int len;
    posPtr = POS_Many_Search_By_Date(date,&len);
    for (int i=0; i<len; i++)
    {
        int total = posPtr[i].product_price * posPtr[i].product_quantity;
        printf("    \t%d      \t%d           \t%s         \t%lf\t    %d   \t%d\n",posPtr[i].bill_id,posPtr[i].product_id,posPtr[i].customer_name,posPtr[i].product_price,posPtr[i].product_quantity,total);
    }
    printf("\t==============================================================================================\n");
    MainMenu();


}


void POS()          //Point of sale system
{
    int pos_choice;
    printf("\n\t\t==================================================\n");
    printf("\t\t||\t    Point Of Sale system\t\t||\n");
    printf("\t\t==================================================");
    printf("\n\t\t||\t        1. View POS by date             ||");
	printf("\n\t\t||\t        2. Customer's Bill              ||");
	printf("\n\t\t||\t        3. Go Back                      ||");
    printf("\n\t\t==================================================\n");
    printf("\n\t\t          Select Transaction : ");
    scanf("%d",&pos_choice);
    switch(pos_choice)
    {
        case 1:
        viewPOS();
        break;

        case 2:
        customer_bill();
        break;

        case 3:
        MainMenu();
        break;

        default:
        printf("\n\tYou inputed wrong choice.Please Try Again.");

        POS();
    }
    
    

    /*printf("\t\t==================================================\n");
    printf("\t\t||\t Press 0 for stop adding items! \t||\n");
    printf("\t\t||\t Press 1 for keep adding items! \t||\n");
    printf("\t\t==================================================\n");
    printf("\t\t Enter your choice: ");
    scanf("%d",&pos_user_choice);
    while (pos_user_choice ==1)
    {
        printf("\n\tEnter Another Bill's ID: ");
        scanf("%d",pos.bill_id);
        printf("\n\tEnter Another Item's Code: ");
        scanf("%d",&pos.product_id);
        printf("\n\tEnter Customer's Name: ");
        scanf("%s",pos.customer_name);
        printf("\n\tEnter Another Item's Quantity: ");
        scanf("%d",&pos.product_quantity);
        printf("\n\tEnter Another Item's Sale Price: ");
        scanf("%d",&pos.product_price);
        total += (pos.product_quantity * pos.product_price);
        printf("\n\tTotal price = %d\n\n",total);
        printf("\t\t==================================================\n");
        printf("\t\t||\t Press 0 for stop adding items! \t||\n");
        printf("\t\t||\t Press 1 for keep adding items! \t||\n");
        printf("\t\t==================================================\n");
        printf("\t\t Enter your choice: ");
        scanf("%d",&pos_user_choice);
    }
    if (pos_user_choice ==0)
    {*/
        
    
}
void addItem()
{
    struct Product pd;
    //char add_item[item_name];
    //double item_cost,item_quantity,item_price;
    viewInventory();
    printf("\n\n\tInsert New Item's ID: ");
    scanf("%d",&pd.product_id);
    printf("\n\tInsert New Item's Name: ");
    scanf("%s",pd.product_name);
    printf("\n\tInsert New Item's Cost: ");
    scanf("%lf",&pd.product_cost);
    if(pd.product_cost <=0 )
    {
        printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
        addItem();
    }
    else{
        printf("\n\tInsert the quantity of New Item: ");
        scanf("%d",&pd.product_quantity);
        if(pd.product_quantity <= 0 )
        {
            printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
            addItem();
        }
        else{
            printf("\n\tInsert sale price of New Item: ");
            scanf("%lf",&pd.product_price);
            if(pd.product_price <= 0)
            {
                printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
                addItem();
            }
            else
            {
                new_Product(pd);
                viewItem();
            }
        }
    }
}
void updateItem()
{
    struct Product Inpd;
    viewInventory();
    //char update_item[item_name];
    //int item_cost,item_quantity,item_price;
    printf("\n\tEnter Item's Code:");
    scanf("%d",&Inpd.product_id);
    printf("\n\tEnter Item's Name:");
    scanf("%s",Inpd.product_name);
    printf("\n\tEnter Item's Cost:");
    scanf("%lf",&Inpd.product_cost);
    if(Inpd.product_cost <=0)
    {
        printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
        updateItem();
    }
    else{
        printf("\n\tEnter the quantity of Item:");
        scanf("%d",&Inpd.product_quantity);
        if(Inpd.product_quantity <= 0 )
        {
            printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
            updateItem();
        }
        else{
            printf("\n\tEnter sale price of Item:");
            scanf("%lf",&Inpd.product_price);
            if(Inpd.product_price <=0 )
            {
                printf("\n\tPlease enter the possible cost value. Retype from the beginning again.\n");
                updateItem();
            }
            else
            {
                Product_Update(Inpd);
                viewItem();
            }    
        }
    }
    

}
void deleteItem()
{
    int deleteItem_code;
    printf("\n\tEnter the code of item that you want to delete: ");
    scanf("%d",&deleteItem_code);
    Product_Delete(deleteItem_code);
    viewItem();
}

void viewInventory()
{
    
    struct Product *Product_Array;
    int length;
    Product_Array = Product_Retrive(&length);
    printf("\n\n\t\t\t\tLIST OF ITEMS");
    printf("\n\t===============================================================\n");
    printf("\tITEM CODE\t  ITEM NAME\t  QTY\t   COST\t    SALE_PRICE");
    printf("\n\t===============================================================");
    for(int i=0;i<length;i++){
        printf("\n\t%d  \t    %s\t   %d\t    %lf\t%lf",Product_Array[i].product_id,Product_Array[i].product_name,Product_Array[i].product_quantity,Product_Array[i].product_cost,Product_Array[i].product_price);
    }
    printf("\n\t===============================================================");
}


void viewItem()
{
    struct Product *Product_Array;
    int length;
    Product_Array = Product_Retrive(&length);
    printf("\n\n\t\t\t\tLIST OF ITEMS");
    printf("\n\t===============================================================\n");
    printf("\tITEM CODE\t  ITEM NAME\t  QTY\t   COST\t    SALE_PRICE");
    printf("\n\t===============================================================");
    for(int i=0;i<length;i++){
        printf("\n\t%d  \t    %s\t   %d\t    %lf\t%lf",Product_Array[i].product_id,Product_Array[i].product_name,Product_Array[i].product_quantity,Product_Array[i].product_cost,Product_Array[i].product_price);
    }
    printf("\n\t===============================================================");
    Inventory();

}
void ShowProfitTable(struct tm date)
{
    struct POS *posPtr;
    int len;
    posPtr = POS_Many_Search_By_Date(date, &len);
    int tempId = -1;
    double profit = 0;
    int quantity = 0;
    // char productName[255];
    // struct POS pos;
    struct Product pd;
    for (int i = 0; i < len; i++)
    {
        if (posPtr[i].product_id != tempId)
        {
            if (tempId != -1)
            {
                profit = (pd.product_price - pd.product_cost) * quantity;
                printf("\t%d\t\t  %s \t %lf \t   %d\t     %lf\t   %lf\n", pd.product_id, pd.product_name, pd.product_cost, quantity, pd.product_price, profit);
            }
            // pos.product_id = posPtr[i].product_id;
            pd = Product_Search(posPtr[i].product_id);
            quantity = posPtr[i].product_quantity;
            tempId = posPtr[i].product_id;
        }
        else
        {
            quantity += posPtr[i].product_quantity;
        }
    }
    profit = (pd.product_price - pd.product_cost) * quantity;
    printf("\t%d\t\t  %s \t %lf \t   %d\t     %lf\t   %lf\n", pd.product_id, pd.product_name, pd.product_cost, quantity, pd.product_price, profit);
}


void Accounting()
{
    struct Sale sale;
    struct tm date;
    printf("\n\t==============================================================================\n");
    printf("\t\t\t\t\tAccounting System\t\t\t\t");
    printf("\n\t==============================================================================\n");
    printf("\n\tEnter the day that you want to search: ");
    scanf("%d",&date.tm_mday);
    printf("\n\tEnter the month that you want to search: ");
    scanf("%d",&date.tm_mon);
    printf("\n\tEnter the year that you want to search: ");
    scanf("%d",&date.tm_year);
    printf("\n\tDate - %d/%d/%d\n",date.tm_mday,date.tm_mon,date.tm_year);
    printf("\n\tThe below is the list of items that are being sold on this day");
    printf("\n\t====================================================================================\n");
    printf("\tITEM CODE\t  ITEM NAME\t  COST\t\t   QTY\t    SALE_PRICE\t    PROFIT");
    printf("\n\t====================================================================================\n");
    ShowProfitTable(date);
    
    /*printf("\t1001\t\t   Apple\t   10\t   100\t\t 20\t   1000\n");
    printf("\t1002\t\t   Orange\t   5\t   100\t\t 15\t   1000\n");
    printf("\t1002\t\t   Ball Pen\t   3\t   100\t\t 5\t   200\n");*/
    printf("\n\t====================================================================================\n");
    //printf("\t\t\t\t\t\t\t    TOTAL PROFIT | 2200");
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
    printf("\n\n\n");
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

            default:
            printf("\n\tYou inputed wrong choice.Please Try Again.");
            MainMenu();
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




