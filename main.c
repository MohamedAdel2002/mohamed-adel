#include <stdio.h>
#include <stdlib.h>
void game(char arr[3][3],char arr1[3][3]); /*a function that gives the 'X' player the priority to start the round*/
void game2(char arr[3][3],char arr1[3][3]);/*a function that gives the 'O' player the priority to start the round*/
int sum1=0,sum2=0;/*two variables to store the total points of the previous rounds*/
int main()
{
    int i=0,j=0,t1x,t2x,t3x,t1o,t2o,t3o;/*t is variable that stores the points of each round*/
  char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};/*basic array 'play ground' declaration*/
   for (i=0;i<3;i++){
    for (j=0;j<3;j++){
        printf("%c  ",arr[i][j]);/*printing the play board*/
    }
    printf("\n");
  }
  printf("\n");
  char arr1[3][3]; /*array to store X or O for the first round*/
  char arr2[3][3];/*array to store X or O for the second round*/
  char arr3[3][3]; /*array to store X or O for the third round*/


game(arr,arr1);/*giving player X the priority to start*/
/*Calculating the points of the 1st round for both players:*/
t1x=sum1;
t1o=sum2;
if (t1x==0){printf("player2 win\n");}
else if (t1o==0){printf("player1 win\n");}
else if(t1x==1&&t1o==1){printf("draw\n");}
 for (i=0;i<3;i++){
    for (j=0;j<3;j++){
        printf("%c ",arr1[i][j]);/*Printing the play board for round 1*/
    }
    printf("\n");
  }
   printf("\n");
if(t1o>t1x){game2(arr,arr2);}/*giving player O the priority to play in case of winning the previous round*/
else{game(arr,arr2);}/*giving the priority to player X in case of winning the previous round
                       -->Note:you will pass arr2 to the function as it's round 2*/
/*Calculating the points of the 2nd round for both players:*/
t2x=sum1-t1x;
t2o=sum2-t1o;
if (t2x==0){printf("player2 win\n");}
else if (t2o==0){printf("player1 win\n");}
else if(t2x==1&&t2o==1){printf("draw\n");}
 for (i=0;i<3;i++){
    for (j=0;j<3;j++){
        printf("%c ",arr2[i][j]);/*Printing the play board for round 2*/
    }
    printf("\n");
  }
   printf("\n");

if (t1o>t1x){
    if(t2o>t2x){game2(arr,arr3);}   /*giving player O the priority to play in case of winning the previous round*/
    else if(t2o==t2x){game2(arr,arr3);}/*draw state but O won the round before that so he has the priority to play*/
    else if(t2x>t2o){game(arr,arr3);}/*giving the priority to player X in case of winning the previous round*/
                                     /*-->Note:you will pass arr3 to the function as it's round 3*/
}
else if(t1x>t1o){
    if(t2o>t2x){game2(arr,arr3);}
    else if(t2o==t2x){game(arr,arr3);}
     else if(t2x>t2o){game(arr,arr3);}
}/*giving X player the priority to play as he won the previous round*/
/*Calculating the points of the 3rd round for both players:*/
t3x=sum1-t1x-t2x;
t3o=sum2-t1o-t2o;
if (t3x==0){printf("player2 win\n");}
else if (t3o==0){printf("player1 win\n");}
else if(t3x==1&&t3o==1){printf("draw\n");}
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
        printf("%c ",arr3[i][j]);/*Printing the play board for round 3*/
    }
    printf("\n");
  }
   printf("\n");
   /*Printing the table of results:*/
   printf("num of games\t player1\t player2\n");
   printf("   game1      \t %d   \t         %d  \n",t1x,t1o);
   printf("   game2      \t %d   \t         %d  \n",t2x,t2o);
   printf("   game3      \t %d   \t         %d  \n",t3x,t3o);
   printf("final result  \t %d   \t         %d  \n",sum1,sum2);
  if (sum1>sum2){printf("player1 is winner\n");}
  if (sum1<sum2){printf("player2 is winner\n");}
  if (sum1==sum2){printf("draww\n");}
    return 0;
}

void game(char arr[3][3],char arr1[3][3]) /*A function gives the priority to player X to start the round*/
{
int xwin=0,owin=0,i,j,k;/*xwin & owin are used to increase the variable sum with 3 if the player wins a round*/
char x,o;
for (k=0;k<5;k++){
        printf("player 1: ");
        scanf("%c",&x);
        fflush(stdin);
      for (i=0;i<3;i++){
    for (j=0;j<3;j++){
       if (arr[i][j]==x){
        arr1[i][j]='X';/*storing 'X' in the place the user chooses on 1st play board*/
       }
    }
  }
  /*adding 3 pts to 'X' player:*/
  if (arr1[0][0]=='X'&&arr1[1][1]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][2]=='X'&&arr1[1][1]=='X'&&arr1[2][0]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][0]=='X'&&arr1[1][0]=='X'&&arr1[2][0]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][1]=='X'&&arr1[1][1]=='X'&&arr1[2][1]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][2]=='X'&&arr1[1][2]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][0]=='X'&&arr1[0][1]=='X'&&arr1[0][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[1][0]=='X'&&arr1[1][1]=='X'&&arr1[1][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[2][0]=='X'&&arr1[2][1]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
  if(k!=4){
    printf("player 2: ");
    scanf("%c",&o);
    fflush(stdin);
     for (i=0;i<3;i++){
    for (j=0;j<3;j++){
       if (arr[i][j]==o){
        arr1[i][j]='O';/*storing 'O' in the place the user chooses on 1st play board*/
       }
       }
    }
  }
  /*adding 3 pts to 'O' player*/
  if (arr1[0][0]=='O'&&arr1[1][1]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[0][2]=='O'&&arr1[1][1]=='O'&&arr1[2][0]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][0]=='O'&&arr1[0][1]=='O'&&arr1[0][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[1][0]=='O'&&arr1[1][1]=='O'&&arr1[1][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[2][0]=='O'&&arr1[2][1]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][0]=='O'&&arr1[1][0]=='O'&&arr1[2][0]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[0][1]=='O'&&arr1[1][1]=='O'&&arr1[2][1]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][2]=='O'&&arr1[1][2]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  }
  if(xwin==0){
    if(owin==0){
    /*adding 1 pt to each player in case of ending the round with a draw*/
        sum1++;
        sum2++;
    }
  }
}





void game2(char arr[3][3],char arr1[3][3]){/*A function that gives player 'O' the priority to start the game*/
int xwin=0,owin=0,i,j,k;
char x,o;
for (k=0;k<5;k++){
        printf("player2: ");
        scanf("%c",&o);
        fflush(stdin);
      for (i=0;i<3;i++){
    for (j=0;j<3;j++){
       if (arr[i][j]==o){
        arr1[i][j]='O';/*storing 'O' in the place the user chooses on 1st play board*/
       }
    }
  }
  /*adding 3 pts to 'O' player*/
  if (arr1[0][0]=='O'&&arr1[1][1]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[0][2]=='O'&&arr1[1][1]=='O'&&arr1[2][0]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][0]=='O'&&arr1[0][1]=='O'&&arr1[0][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[1][0]=='O'&&arr1[1][1]=='O'&&arr1[1][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[2][0]=='O'&&arr1[2][1]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][0]=='O'&&arr1[1][0]=='O'&&arr1[2][0]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
   else if (arr1[0][1]=='O'&&arr1[1][1]=='O'&&arr1[2][1]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  else if (arr1[0][2]=='O'&&arr1[1][2]=='O'&&arr1[2][2]=='O'){
    owin+=3;
    sum2+=owin;
    break;
  }
  if(k!=4){
    printf("player1: ");
    scanf("%c",&x);
    fflush(stdin);
     for (i=0;i<3;i++){
    for (j=0;j<3;j++){
       if (arr[i][j]==x){
        arr1[i][j]='X';/*storing 'O' in the place the user chooses on 1st play board*/
       }
    }
  }
   /*adding 3 pts to 'X' player*/
 if (arr1[0][0]=='X'&&arr1[1][1]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][2]=='X'&&arr1[1][1]=='X'&&arr1[2][0]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][0]=='X'&&arr1[1][0]=='X'&&arr1[2][0]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][1]=='X'&&arr1[1][1]=='X'&&arr1[2][1]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][2]=='X'&&arr1[1][2]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[0][0]=='X'&&arr1[0][1]=='X'&&arr1[0][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[1][0]=='X'&&arr1[1][1]=='X'&&arr1[1][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
   else if (arr1[2][0]=='X'&&arr1[2][1]=='X'&&arr1[2][2]=='X'){
    xwin+=3;
    sum1+=xwin;
    break;
  }
  }
  }
  if(xwin==0){
    if(owin==0){
    /*adding 1 pt to each player in case of ending the round with a draw*/
        sum1++;
        sum2++;
    }
  }
}

