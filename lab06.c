/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int buttonPressed(int inputList[], int tempInputList[]);
int originalButtonPressed(int inputList[]);

int main(int argc, char *argv[])
{
    srand(time(NULL)); /* This will ensure a random game each time. */
    // srand(0);
    // triangle, circle, x_button, square;
    int masterTime = 2501;
    int nonStopTime = 80000;
    int nonStopMaster = 80000;
    int tempNonStop = nonStopMaster+500;
    int correctButton[4]={0,0,0,0};
    int inputButton[4];
    int tempInputList[4]={0,0,0,0};
    int count = 0;

    int controllerTime = 0;
    int tempControllerTime = 0;

    char nextButton[50]  = "";

    // Master time starts at 2500 and uses controller time elapsed to tick down

    // Master time is reset if correct, and current elapsed time is saved to compare against 

    int random = 0;

    
    
    // int timeElapsed = masterTime;
    // int time = masterTime;
    // int tempTime = time + 500;

    int currentTime = masterTime;
    int time = masterTime;

    // printf("Press the Triangle button to begin!");

    while(1){
        if(time == 2501){
            printf("This is a Bop-It game!\n");
            printf("Press the Triangle button to begin!\n");
            time= time-1;
        }

        scanf("%d, %d, %d, %d, %d", &controllerTime, &inputButton[0], &inputButton[1], &inputButton[2], &inputButton[3]);
        
        correctButton[random] = 1;
        
        // if(buttonPressed(inputButton, tempInputList)){
        //     printf("buttonPressed\n");
        // }

        // for(int i = 0; i<4; i++){
        //     tempInputList[i] = inputButton[i];
        //     // printf("I: %d ", inputButton[i]);   
        //     // printf("T: %d ", tempInputList[i]); 
        // }

        // Reset button
        if(tempNonStop-250>nonStopTime){
            if(inputButton[0]==correctButton[0] && inputButton[1]==correctButton[1] && inputButton[2]==correctButton[2]&& inputButton[3]==correctButton[3]){
                printf("\n");

                random = rand()%4;

                if (random == 0){
                    strcpy(nextButton,"Triangle");
                }
                if (random == 1){
                    strcpy(nextButton,"Circle");
                }
                if (random == 2){
                    strcpy(nextButton,"X button");
                }
                if (random == 3){
                    strcpy(nextButton,"Square");
                }

                printf("Next button: %s\n", nextButton);
                printf("Time remaining %d\n", time);
                // printf("Controller Time Elapsed %d\n", controllerTime);
                
                for(int i = 0; i<4; i++){
                    correctButton[i] = 0;
                    // printf("%d ", inputButton[i]);    
                }
                // tempTime = timeElapsed;
                time = time - 100;
                tempControllerTime = controllerTime;
                tempNonStop = nonStopTime;
                count++;

            }
            else if(inputButton[0]!=0 || inputButton[1]!=0 || inputButton[2]!=0 || inputButton[3]!=0){
                printf("\nWrong Button!\n");
                break;
            }
            
        }
        
        nonStopTime = nonStopMaster - controllerTime;
        currentTime = time - (controllerTime - tempControllerTime);
        // printf("Time remaining %d\n", currentTime);
        if(currentTime<0){
            printf("\nOut of time\n");
            break;
        }
    }
    printf("You lose!\nYou made it through %d rounds!\n", count);
    
    return 0;
}



/* Put your functions here, and be sure to put prototypes above. */

int buttonPressed(int inputList[], int tempInputList[]){
    int sum = 0;
    int isListZero = 1;
    for(int i = 0; i<4; i++){
        sum = sum + tempInputList[i];
        if(inputList[i]!=0){
            isListZero = 0;
        }
    }
    if(sum>0 && isListZero){
        return 1;
    }
    if(sum<=0){
        return 0;
    }
}

// int originalButtonPressed(int inputList[]){
//     int sum = 0;
//     for(int i = 0; i<4; i++){
//         sum = sum + inputList[i];
//     }
//     if(sum>0){
//         return 1;
//     }
//     if(sum<=0){
//         printf("False");
//         return 0;
//     }
// }