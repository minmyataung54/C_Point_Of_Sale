#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int Exit(){
		printf("\n\t\tSystem Terminated");
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

void SaveItem(char iName[50],char descp[100], char price[50]){
	FILE *f,*ff;
	char _items[350]="";
	
	strcpy(_items,strcat(iName,"   "));
	strcat(_items,strcat(descp,"   "));
	strcat(_items,price);
	
	 int i=0;
      for(i=0; _items[i]!='\0'; i++)
     {
     if(_items[i]=='\n')
         {
          _items[i]=' ';
         }
      }
      
      strcat(_items,"\n");
      
	 f =fopen("Receipt\\List.txt","a");
    	fprintf(f,"%s",_items);
	    fclose(f);
	    printf("\n\t\tItem save");
	    
	     ff =fopen("Receipt\\total.txt","a");
    	fprintf(ff,"%s",price);
	    fclose(ff);
}


void PrintReceipt(){
	FILE *f;
	char ch[350];
	printf("\n");
	printf("\n");
	printf("\t\t List of items\n");
	printf("\t\t=================================================\n");
	int counter = 0;
	f = fopen("Receipt\\List.txt","r");
        while(fgets(ch,100,f)){
        counter++;	
        printf("\t\t %d. - %s",counter,ch);
        }
	
}

void PrintReceipt2(){
	FILE *f,*ff;
	char ch[350];
	char total[10];
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t Magcayan Variety Store 24/7\n");
	printf("\t\t\t Official Receipt N0: xxxxxxx\n");
	printf("\n");
	printf("\t\t items\n");
	printf("\t\t=================================================\n");
	int counter = 0;
	float total2=0;
	f = fopen("Receipt\\List.txt","r");
        while(fgets(ch,100,f)){
        counter++;	
        printf("\t\t %d. - %s",counter,ch);
        }
        
    	ff = fopen("Receipt\\total.txt","r");
        while(fgets(total,10,ff)){
           total2+=atof(total);
           //printf("\n %.2f",total2);
        }    
    printf("\t\t=================================================\n");    
	printf("\n");
	printf("\t\t\t\t\t\t   Total : %.2f \n",total2);
	printf("\n");

	printf("\n");
	printf("\t\t\t This serve as your Official Receipt\n");
	printf("\t\t\t          Thank You !! \n");
}


void DrawStore(){
	    char ans;
	    char ans2;
	    char cod[10];
	    char path[10] = "Items\\";
	    char item[20];
	    char itms[250];
	    FILE *f;
	    printf("\n");
	    printf("\n");
	    printf("\n");
	    printf("\n");
    	printf("\t\t===============================================");
    	printf("\n\t\t||                                           ||");
		printf("\n\t\t||         MAGCAYAN VARIETY STORE 24/7       ||");
		printf("\n\t\t||                                           ||");
		printf("\n\t\t===============================================");
		
		PrintReceipt();
		
		printf("\n\t\t     Enter Barcode : ");
		
	    scanf("%s",cod);
	    f = fopen(strcat(path,strcat(strcpy(item,cod),".txt")),"r");
	    int counter = 0;
	    char inme[270]="Item Name : ";
	    char dcp[270]="Description : ";
	    char pp[270]="Price : ";
	    
	    char inme2[100]="";
	    char dcp2[100]="";
	    char pp2[100]="";
	    
        while(fgets(itms,250,f)){
        	counter++;
        	if(counter==2){
        		strcat(inme,itms);
        		strcpy(inme2,itms);
			}else if(counter==3){
				strcat(dcp,itms);
				strcpy(dcp2,itms);
            }else if(counter==4){
        	    strcat(pp,itms);
        	    strcpy(pp2,itms);
        	    counter=0;
            }	
		}
		printf("\n\n\t\t %s",inme);
		printf("\n\t\t %s",dcp);
		printf("\n\t\t %s",pp);
		
	   fclose(f);
	   
	   printf("\n\n\n\t\t\t Save item [y/n] : ");
	   scanf(" %c",&ans);
	   
	   switch(ans){
	   	  case 'y':
	   	  	   SaveItem(inme2,dcp2,pp2);
	   	  	    printf("\n\n\n\t\t Select Transaction");  
	   	        printf("\n\n\t\t [1] Add item     [2] Print Receipt    [3] Cancel : ");
	           scanf(" %c",&ans2);
	                 switch(ans2){
	                 	case '1':
	                 		    CostumerWalkIn();
	                 		break;
	                 	case '2':
	                 		    PrintReceipt2();
						    break;
						case '3':
							    MainMenu(); 
						    break;		
					 }
	   	  	break;
	   	  case 'Y':
	   	       SaveItem(inme,dcp,pp);
	   	        printf("\n\n\n\t\t Select Transaction");  
	   	        printf("\n\n\t\t [1] Add item     [2] Print Receipt    [3] Cancel : ");
	            scanf(" %c",&ans2);
	                     switch(ans2){
	                 	case '1':
	                 		    CostumerWalkIn();
	                 		break;
	                 	case '2':
	                 		    PrintReceipt2();
						    break;
						case '3':
							    MainMenu(); 
						    break;		
					 }
			 break;
		  default :
		      CostumerWalkIn();
		  break;	 	
	   }
}


void CostumerWalkIn(){
	DrawStore();
}


void AddItem(){
	float price = 0;
	char iName[30] ="";
	char descp[100] = "";
	int qty = 0;
	char code[10]="";
	char dir[8]="Items\\";
	char cod[10];
	FILE *f;
	char ans;
	
		printf("\n\t\tAdd Item\n");
     	printf("\n\t\t===============================================\n");
	    printf("\t\tEnter Item Code : ");
	    scanf("%10s",code);
	    strcpy(cod, code);
	    fflush(stdin);
	    printf("\n\t\tEnter Item Name : ");
	    scanf("%30[^\n]s",iName);
	    fflush(stdin);
	    printf("\n\t\tEnter Item Description : ");
	    scanf("%100[^\n]s",descp);
	    fflush(stdin);
	    printf("\n\t\tEnter Item Unit Price : ");
	    scanf("%f",&price);

	    printf("\n\t\tEnter Item Quantity : ");
	    scanf("%d",&qty);

	    printf("\n\n\n\n");
	    printf("\n\t\t\tSave Entry ?  [y/n] : ");
	    scanf(" %c",&ans);
	
	    switch(ans){
	    	char ans2;
	
	    	case 'y':
	    		 f =fopen(strcat(dir, strcat(code,".txt")),"w");
	             fprintf(f,"%s\n %s\n %s\n %.2f\n %d",cod,iName,descp,price,qty);
	             fclose(f);
	             
	             printf("\n\t\tItem Save..");
	             printf("\n\n\t\t\tAnother Entry ?  [y/n] : ");
	             scanf(" %c",&ans2);
	             
	             switch(ans2){
	             	case 'y':
	             			AddItem(); 
	             		break;
	             	case 'Y':
	             			AddItem();  
					    break;	
					default:
			             	MainMenu();
			            break;    
				 }
	             break;
	    	case 'Y':
			     f =fopen(strcat(dir, strcat(code,".txt")),"w");
	             fprintf(f,"%s\n %s\n %s\n %.2f\n %d",cod,iName,descp,price,qty);
	             fclose(f);
	             printf("\n\t\tItem Save..");
	             printf("\n\n\t\t\tAnother Entry ?  [y/n] : ");
	             scanf(" %c",&ans2);
	             
	             switch(ans2){
	             	case 'y':
	             			AddItem(); 
	             		break;
	             	case 'Y':
	             			AddItem(); 
					    break;	
					default:
			             	MainMenu();
			            break;    
				 }
	             break;
			default:
				MainMenu();
			    break;		
		}  
	
}


void MainMenu(){
	
	int choice = 0;
	
	printf("\n\n\n\n");
	    printf("\t\t *  C O N S O L E  *  P O S  *  S Y S T E M  *\n");
		printf("\t\t===============================================");
		printf("\n\t\t||            M A I N  *  M E N U            ||");
		printf("\n\t\t===============================================");
		printf("\n\t\t||                                           ||");
		printf("\n\t\t||        1. COSTUMER WALK IN                ||");
    	printf("\n\t\t||        2. ADD ITEM                        ||");
		printf("\n\t\t||        3. INVENTORY                       ||");
		printf("\n\t\t||        4. EXIT                            ||");
		printf("\n\t\t||                                           ||");
		printf("\n\t\t===============================================\n\n\n");
		printf("\n\t\t          Select Transaction : ");	
		
		scanf("%d",&choice);
	
	switch (choice){
		case 1:
			CostumerWalkIn();
			break;
			
		case 2:
			AddItem();
			break;
			
		case 3:
			Inventory();
			break;
			
		case 4:
			Exit();
			break;	
	}
}





int main(){
	
	MainMenu();      
	
	return 0;
}
