#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


int Exit()
{
    printf("\n\t\t          System is Terminated !!! ");
    return 0;
}

void Inventory(){
		printf("\n\tInventory\n\n");
    DIR *mydir = opendir("Items\\");

    struct dirent *entry = NULL;
    printf("\n\tLIST OF ITEMS");
    printf("\n\t=================================================================\n");
    printf("\tCODE     ITEM NAME           DESCRIPTION             PRICE    QTY");
    printf("\n\t=================================================================\n");
   
    while((entry = readdir(mydir))) 
    {
    FILE *f;
	char ch[100];
	char ch2[100];
	char ch3[100];
		
   	char cods[10];
	char iName[50];
	char descp[100];
	char p[10];
	char qty[5];
	int counter =0;	
    char dir[10];
    char path[10]="Items\\";
   
   if(strcmp(entry->d_name,"..") == 0){
 
   }else{
   	
        strcpy(dir,entry->d_name);
    	f = fopen(strcat(path,dir),"r");
        while(fgets(ch,100,f)){
        counter++;	
       	   if(counter==1){
       		  	strcpy(cods,ch);
		   }else if(counter==2){
		   	    strcpy(iName,ch);
		   }else if(counter==3){
		   	    strcpy(descp,ch);
		   }else if(counter==4){
		   	    strcpy(p,ch);
		   }else if(counter==5){
		        strcpy(qty,ch);	    
		   	    counter==0;
		   }
        }
      char _items[100];
      
      strcpy(_items,cods);
      strcat(_items,iName);
      strcat(_items,descp);
      strcat(_items,p);
      strcat(_items,qty);
      
      //==================================
      int i=0;
      for(i=0; _items[i]!='\0'; i++)
     {
     if(_items[i]=='\n')
         {
          _items[i]='\t';
         }
      }
      //==================================
   
      printf("\t %s \n",_items);
      
      fclose(f);	
	 }
   }
   
   closedir(mydir);
   
    printf("\n\t=================================================================");
    char ans;
    printf("\n\n");
    printf("\n\t\t\tBack to Main [y/n] : ");
    scanf(" %c",&ans);
    printf("\n\n");
    
    switch(ans){
    	case 'y':
    		 MainMenu();
    		 break;
    	case 'Y':
		      MainMenu();
			  break;
	    default:
		      Exit();
			  break;		  	 
	}
}

void POS()
{
    
    printf("\n\n\t\t===============================================");
	printf("\n\t\t||            Point Of Sale System           ||");
	printf("\n\t\t===============================================");

}


void MainMenu()
{
    int user_choice;
    printf("\n\n\n");
	    printf("\t\t*  *   *   * CPE 100 is the best  *    *   *   *\n");
		printf("\t\t===============================================");
		printf("\n\t\t||            M A I N     M E N U            ||");
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
        switch (user_choice)
        {
            /*case 1:
                Sale();
                break;
            */
            case 2:
                Inventory();
                break;
            
            case 3:
                POS();
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



/*int main()
{
    int menu_choice;
    printf(" ==================================================================\n");
    printf("|");
    printf("                      Welcome to Mart1 POS System                 |\n");
    printf(" ==================================================================\n");
    printf("\tPlease choose one of numbers to enter into the system\n");
    printf("\t1. \"Inventory System\"\n\t2. \"Point of Sales System\"\n\t3. \"Accounting System\"\n");
    printf("===================================================================\n");
    //printf("--------------------------------------------------------------------\n");
    printf("Please select from above options : ");
    scanf("%d",&menu_choice);

}*/

void menu(){

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