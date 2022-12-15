#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utility.h"
#include "model.h"
#include "env.h"

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
                printf("%d %s %d %lf %lf %lf", pd.product_id, pd.product_name, quantity, pd.product_cost, pd.product_price, profit);
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
    printf("%d %s %d %lf %lf %lf", pd.product_id, pd.product_name, quantity, pd.product_cost, pd.product_price, profit);
}

int main()
{

    return 0;
}