#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilities.h"

int main()
{
    FILE *inFile = fopen("TestInput.txt", "r");
    FILE *outFile = fopen("out.txt", "w");
    char type[50];
    char make[50];
    char model[50];
    char model2[50];
    int year;
    char VIN[50];
    int numDoors;
    char rearConfig[50]; 
    double towCapacity; 
    char motor[50];
    char line [100];

         fscanf(inFile, "%s" , type);
        
        while (fgets (line, 50, inFile)){
           
            if (strcmp(type, "truck")==0){
                fscanf(inFile, "%s %s %s %d %s %d %lf", make, model, model2, &year, VIN, &numDoors, &towCapacity );
                fprintf(outFile, "%d %s %s %s\nVIN: %s\nDoors: %d\nMax Towing Capacity: %0.1lf\n", year, make, model, model2, VIN, numDoors, towCapacity);
            }
            
            else if (strcmp(type, "car") == 0){
                fscanf(inFile, "%s %s %s %d %s %d %s", make, model, model2, &year, VIN, &numDoors, rearConfig );
                fprintf(outFile, "%d %s %s %s\nVIN: %s\nDoors: %d\nRear Configuration: %s", year, make, model, model2, VIN, numDoors, rearConfig);
            }
            
            else if (strcmp(type, "boat") == 0){
                fscanf(inFile, "%s %s %s %d %s %s", make, model, model2, &year, VIN, motor);
                fprintf(outFile, "%d %s %s %s\nVIN: %s\nMotor: %s", year, make, model, model2, VIN, motor);
            }
            
        }
    return 0;
}

