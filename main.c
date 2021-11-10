#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Creating struct data type do declare multiple variables types
    //that can be accessed through "section"
    typedef struct{
        //Initializing char and float variables
        int serialNum,numParts;
        float price,totalPrice;
    } section;
    //Storing section into a pointer
    section*p0;
    //Initializing and declaring variables
    int i=0,j=0;
    char skip[2]=" ",*p1,line[20],line2[20];

    //Opening parts.txt and order.txt files
    FILE*fp=fopen("parts.txt","r");
    FILE*fw=fopen("order.txt","w");

    //Dynamic memory being allocated using malloc function
    p0=(section*)malloc(sizeof(p0)*25);

    //Initialization of dynamic memory
    memset(p0,'\0',sizeof(p0)*25);

    //While loop gets data from parts.txt file and loops if it does not equal NULL
    while (fgets(line,sizeof line,fp)!=NULL){
        j=0;
        //Strtok function used to break each line into smaller string and store into p1
        p1=strtok(line,skip);

        //If statement converts string at j==0 to integer using atoi function and stores value
        if (j==0){
            p0[i].serialNum=atoi(p1);
        }

        //While iterates if p1 does not equal NULL
        while (p1!=NULL){
            j++;
            p1=strtok(NULL,skip);
            //If statement converts string at j==1 to integer using atoi function and stores value
            if (j==1){
                p0[i].price=atof(p1);
            }
            //If statement converts string at j==1 to integer using atoi function and stores value
            if (j==2){
                p0[i].numParts=atoi(p1);
            }
        }

        //Calculate the total price and store the value
        p0[i].totalPrice=p0[i].price*p0[i].numParts;

        //If statement check for blank lines and skips over the first line
        if (line[0]!='\n'&&j!=1){
            //Prints to the console
            printf("%.2d %.2f %d %.2f\n",p0[i].serialNum,p0[i].price,p0[i].numParts,p0[i].totalPrice);
            //If statement that prints to the console when the final data has been printed
            if(p0[i].serialNum==6689){
                printf("Serial / Price / Units / Total");
            }
            //prints to order.txt file
            sprintf(line2, "%.2d %.2f %d %.2f\n",p0[i].serialNum,p0[i].price,p0[i].numParts,p0[i].totalPrice);
            //If statement that prints to order.txt file when the final data had been printed
            if(p0[i].serialNum==6689){
                sprintf(line2,"Serial / Price / Units / Total");
            }
            fputs(line2,fw);
            i++;
        }
    }
    fclose(fp);
    fclose(fw);
    free(p1);
}

