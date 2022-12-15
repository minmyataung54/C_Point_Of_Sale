#include <stdio.h>
#include <time.h>
#include "file_utility.h"
#include <string.h>
#include "model.h"
#include "env.h"

int main()
{
    time_t t;
    t = time(NULL);
    struct tm *ptr;
    ptr = localtime(&t);
    struct Product pd;
    struct Sale sale;
    struct POS pos;

    sale.transaction_id = 1;
    sale.product_cost = 23.11;
    sale.product_id = 10;
    strcpy(sale.product_name, "product_two");
    sale.product_price = 40.34;
    sale.product_quantity = 1;
    sale.profit = 400.11;
    sale.transaction_datetime.tm_sec = (int)ptr->tm_sec;
    sale.transaction_datetime.tm_min = (int)ptr->tm_min;
    sale.transaction_datetime.tm_hour = (int)ptr->tm_hour;
    sale.transaction_datetime.tm_mday = (int)ptr->tm_mday;
    sale.transaction_datetime.tm_mon = (int)ptr->tm_mon;
    sale.transaction_datetime.tm_year = (int)ptr->tm_year;
    // sale.transaction_datetime = *localtime(&t);
    new_Sale(sale);

    pos.bill_id = 101;
    strcpy(pos.customer_name, "curcur");
    pos.product_cost = 18.44;
    pos.product_id = 12;
    pos.product_price = 22.45;
    pos.product_quantity = 13;
    pos.transaction_datetime.tm_sec = (int)ptr->tm_sec;
    pos.transaction_datetime.tm_min = (int)ptr->tm_min;
    pos.transaction_datetime.tm_hour = (int)ptr->tm_hour;
    pos.transaction_datetime.tm_mday = (int)ptr->tm_mday;
    pos.transaction_datetime.tm_mon = (int)ptr->tm_mon;
    pos.transaction_datetime.tm_year = (int)ptr->tm_year;
    new_POS(pos);

    pos.bill_id = 102;
    strcpy(pos.customer_name, "curcur_1");
    pos.product_cost = 18.44;
    pos.product_id = 12;
    pos.product_price = 22.45;
    pos.product_quantity = 13;
    pos.transaction_datetime.tm_sec = (int)ptr->tm_sec;
    pos.transaction_datetime.tm_min = (int)ptr->tm_min;
    pos.transaction_datetime.tm_hour = (int)ptr->tm_hour;
    pos.transaction_datetime.tm_mday = (int)ptr->tm_mday+1;
    pos.transaction_datetime.tm_mon = (int)ptr->tm_mon;
    pos.transaction_datetime.tm_year = (int)ptr->tm_year;
    new_POS(pos);

    pos.bill_id = 104;
    strcpy(pos.customer_name, "curcur_3");
    pos.product_cost = 18.44;
    pos.product_id = 11;
    pos.product_price = 22.45;
    pos.product_quantity = 13;
    pos.transaction_datetime.tm_sec = (int)ptr->tm_sec;
    pos.transaction_datetime.tm_min = (int)ptr->tm_min;
    pos.transaction_datetime.tm_hour = (int)ptr->tm_hour;
    pos.transaction_datetime.tm_mday = (int)ptr->tm_mday;
    pos.transaction_datetime.tm_mon = (int)ptr->tm_mon;
    pos.transaction_datetime.tm_year = (int)ptr->tm_year;
    new_POS(pos);

    pos.bill_id = 103;
    strcpy(pos.customer_name, "curcur_2");
    pos.product_cost = 18.44;
    pos.product_id = 12;
    pos.product_price = 22.45;
    pos.product_quantity = 13;
    pos.transaction_datetime.tm_sec = (int)ptr->tm_sec;
    pos.transaction_datetime.tm_min = (int)ptr->tm_min;
    pos.transaction_datetime.tm_hour = (int)ptr->tm_hour;
    pos.transaction_datetime.tm_mday = (int)ptr->tm_mday;
    pos.transaction_datetime.tm_mon = (int)ptr->tm_mon;
    pos.transaction_datetime.tm_year = (int)ptr->tm_year;
    new_POS(pos);

    struct tm date;
    date.tm_sec = (int)ptr->tm_sec;
    date.tm_min = (int)ptr->tm_min;
    date.tm_hour = (int)ptr->tm_hour;
    date.tm_mday = (int)ptr->tm_mday;
    date.tm_mon = (int)ptr->tm_mon;
    date.tm_year = (int)ptr->tm_year;
    struct POS *posPtr;
    int len;
    posPtr = POS_Many_Search_By_Date(date,&len);
    // for (int i = 0; i < len; i++)
    // {
    //     Display_POS(posPtr[i]);
    // }
    

    pd.product_id = 12;
    strcpy(pd.product_name, "product_one");
    pd.product_quantity = 34;
    pd.product_cost = 23;
    new_Product(pd);

    pd.product_id = 10;
    strcpy(pd.product_name, "product_two");
    pd.product_quantity = 31;
    pd.product_cost = 98;
    new_Product(pd);

    pd.product_id = 43;
    strcpy(pd.product_name, "product_three");
    pd.product_quantity = 22;
    pd.product_cost = 1010;
    new_Product(pd);

    pd = Product_Search(10);
    pd = Product_Delete(12);
    pd.product_id = 10;
    strcpy(pd.product_name, "T_34");
    pd.product_quantity = 22;
    pd.product_cost = 1010;
    Product_Update(pd);
    return 0;
}