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
    // triangle, circle, x_button, square;
    int masterTime = 2501;
    int correctButton[4];
    int inputButton[4];
    int tempInputList[4]={0,0,0,0};
    int count = 0;
    int controllerTime = 0;

    char nextButton[50]  = "";

    // Master time starts at 2500 and uses controller time elapsed to tick down

    // Master time is reset if correct, and current elapsed time is saved to compare against 

    int random = 0;

    correctButton[0] = 0;
    correctButton[1] = 0;
    correctButton[2] = 0;
    correctButton[3] = 0;
    
    int timeElapsed = masterTime;
    int time = masterTime;
    int tempTime = time + 500;

    // printf("Press the Triangle button to begin!");

    while(1){
        if(time == 2501){
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
        if(tempTime-250>timeElapsed){
            if(inputButton[0]==correctButton[0] && inputButton[1]==correctButton[1] && inputButton[2]==correctButton[2]&& inputButton[3]==correctButton[3]){
                printf("Correct\n");
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
                tempTime = timeElapsed;
                time = time - 100;

                timeElapsed = 0;
            }
            // else{
            //     printf("Fail");
            //     break;
            //}
        }
        
        if(timeElapsed<0){
            break;
        }
        
        timeElapsed = time - controllerTime;
        // printf("Time remaining %d\n", time);
    }

    printf("Out of time\n");
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

int originalButtonPressed(int inputList[]){
    int sum = 0;
    for(int i = 0; i<4; i++){
        sum = sum + inputList[i];
    }
    if(sum>0){
        return 1;
    }
    if(sum<=0){
        printf("False");
        return 0;
    }
}