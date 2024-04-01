#include<bits/stdc++.h>
using namespace std;

void pattern1(int N)
{
    /*
       
       Pattern

        *****
        *****
        *****
        *****
        *****
    
    */

    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // This is the inner loop which here, loops for the columns
        // as we have to print a rectangular pattern.
        for (int j = 0; j < N; j++)
        {
            cout << "* ";
        }
       
        // As soon as N stars are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern2(int N)
{

    /*
       
       Pattern

        *
        **
        ***
        ****
        *****
    
    */

    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // This is the inner loop which loops for the columns
       // no. of columns = row number for each line here.
        for (int j = 0; j <=i; j++)
        {
            cout << "* ";
        }
       
        // As soon as stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern3(int N)
{
    /*
    
        Pattern 

        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5

    */

    // This is the outer loop which will loop for the rows.
    for (int i = 1; i <= N; i++)
    {
        // This is the inner loop which loops for the columns
       // no. of columns = row number for each line here.
       // Here, we print numbers from 1 to the row number
       // instead of stars in each row.
        for (int j = 1; j <=i; j++)
        {
            cout <<j<<" ";
        }
       
        // As soon as numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern4(int N)
{   
    /*
    
        Pattern 

        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5

    */

    // This is the outer loop which will loop for the rows.
    for (int i = 1; i <= N; i++)
    {
        // This is the inner loop which loops for the columns
       // no. of columns = row number for each line here.
       // Here, we print numbers equal to the row number
       // instead of stars in each row.
        for (int j = 1; j <=i; j++)
        {
            cout <<i<<" ";
        }
       
        // As soon as numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern5(int N)
{
    /*
    
        Pattern 

        * * * * * 
        * * * * 
        * * * 
        * * 
        * 

    */
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // This is the inner loop which loops for the columns
       // no. of columns = (N - row index) for each line here.
        for (int j =N; j>i; j--)
        {
            cout <<"* ";
        }
       
        // As soon as stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern6(int N)
{   /*
    
        Pattern 

        1 2 3 4 5
        1 2 3 4
        1 2 3
        1 2 
        1

    */
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
         // This is the inner loop which loops for the columns
        // no. of columns = (N - row index) for each line here
        // as we have to print an inverted pyramid.
        // (N-j) will give us the numbers in a row starting from 1 to N-i.
        for (int j =N; j>i; j--)
        {
            cout <<N-j+1<<" ";
        }
       
        // As soon as numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern7(int N)
{   
    /*
        Pattern

            *     
           ***    
          *****   
         *******  
        ********* 

    */
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*i+1;j++){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
        
        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern7_al(int num){
    int space=ceil(num);
    for(int i=1;i<=num;i++){
        cout<<setw(space--);
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern8(int N)
{
    // This is the outer loop which will loop for the rows.
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*N -(2*i +1);j++){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
        
        // As soon as the stars for each iteration are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
        cout << endl;
    }
}
void pattern8_al(int num){
    for(int i=num;i>0;i--){
        cout<<setw(num-i+1);
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int j=1;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern9(int num){
    /*
        Pattern

            *    
           ***   
          *****  
         ******* 
        *********
        *********
         ******* 
          *****  
           ***   
            *    
    */
    pattern7(num);
    pattern8(num);
}
void pattern10(int num){
    /*
        Pattern
        * 
        * * 
        * * * 
        * * * * 
        * * * * * 
        * * * * * 
        * * * * 
        * * * 
        * * 
        * 
    */
    pattern2(num);
    pattern5(num);
}
void pattern11(int N)
{       
      /*
        Pattern 

        1
        01
        101
        0101
        10101

      */
      // First row starts by printing a single 1.
      int start =1;
      
      // Outer loop for the no. of rows
      for(int i=0;i<N;i++){
          
          // if the row index is even then 1 is printed first
          // in that row.
          if(i%2 ==0) start = 1;
          
          // if odd, then the first 0 will be printed in that row.
          else start = 0;
          
          // We alternatively print 1's and 0's in each row by using
          // the inner for loop.
          for(int j=0;j<=i;j++){
              cout<<start;
              start = 1-start;
          }
      
      
        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout<<endl;
      }
}
void pattern11_al(int num){
    for(int i=1;i<=num;i++){
        bool x=(i%2==0)?0:1;
        for(int j=1;j<=i;j++){
            cout<<x;
            x=not(x);
        }
        cout<<endl;    
    }
}
void pattern12(int N)
{     /*
            Pattern

            1        1
            12      21
            123    321
            1234  4321
            1234554321


        */
      // initial no. of spaces in row 1.
      int spaces = 2*(N-1);
      
      // Outer loop for the number of rows.
      for(int i=1;i<=N;i++){
          
          // for printing numbers in each row
          for(int j=1;j<=i;j++){
              cout<<j;
          }
          
          // for printing spaces in each row
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          
          // for printing numbers in each row
          for(int j=i;j>=1;j--){
              cout<<j;
          }
          
          // As soon as the numbers for each iteration are printed, we move to the
          // next row and give a line break otherwise all numbers
          // would get printed in 1 line.
          cout<<endl;
          
          // After each iteration nos. increase by 2, thus
          // spaces will decrement by 2.
          spaces-=2;
      }
}
void pattern12_al(int num){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<setw(2*(num-i)+1);
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void pattern13_al(int num){
    /*
        1 
        2 3 
        4 5 6 
        7 8 9 10 
        11 12 13 14 15 

    */
    int count=1;
    for(int i=1;i<num;i++){
        for(int j=1;j<=i;j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }
}
void pattern14_al(int num){

    /*
        Pattern

        A 
        A B 
        A B C 
        A B C D 
        A B C D E 

    */

    for(int i=1;i<num;i++){
        char x='A';
        for(int j=0;j<i;j++){
            cout<<x++<<" ";
        }
        cout<<endl;
    }
}
void pattern15_al(int num){
    /*
        Pattern

        F E D C B A 
        E D C B A 
        D C B A 
        C B A 
        B A 
        A 

    */
    for(int i=num;i>0;i--){
        char x=char('A'+i);
        for(int j=i;j>0;j--){
            cout<<--x<<" ";
        }
        cout<<endl;
    }
}
void pattern16_al(int num){
    /*  
        Pattern

        A 
        B B 
        C C C 
        D D D D 
        E E E E E 
        F F F F F F 
    
    */
    char x='A';
    for(int i=0;i<num;i++){
        for(int j=0;j<=i;j++){
            cout<<x<<" ";
        }
        x++;
        cout<<endl;
    }
}
void pattern17_al(int num){
    /*
        Pattern

             A
            ABA
           ABCBA
          ABCDCBA
         ABCDEDCBA
        ABCDEFEDCBA
    */
    
    for(int i=0;i<num;i++){
        char x='A';
        cout<<setw(num-i);
        for(int j=0;j<=i;j++){
            cout<<x++;
        }
        //since i am using ++ operator after and a global var i need to reset it back
        --x;
        for(int j=1;j<=i;j++){
            //since i first need to decrement the character then print it hence --x and not x--
            cout<<--x;
        }
        cout<<endl;
    }
}
void pattern18_al(int num){

    /*  
        Pattern

        F 
        E F 
        D E F 
        C D E F 
        B C D E F 
        A B C D E F 

    */

    for(int i=0;i<num;i++){
        for(int j=i;j>=0;j--){
            cout<<char('A'+(num-j-1))<<" ";
        }
        cout<<endl;
    }
}
void pattern19(int N)
{       
      /*
        **********
        ****  ****
        ***    ***
        **      **
        *        *
        *        *
        **      **
        ***    ***
        ****  ****
        **********
      */
      // for the upper half of the pattern.
      
      // initial spaces.
      int iniS = 0;
      for(int i=0;i< N;i++){
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          // The spaces increase by 2 every time we hit a new row.
          iniS+=2;
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
      }
      
      // for lower half of the pattern
      
      // initial spaces.
      iniS = 2*N -2;
      for(int i=1;i<=N;i++){
          
          //for printing the stars in the row.
          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          // The spaces decrease by 2 every time we hit a new row.
          iniS-=2;
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
      }
      
}
void pattern20(int n)
{
    /*
        Pattern

        *        *
        **      **
        ***    ***
        ****  ****
        **********
        ****  ****
        ***    ***
        **      **
        *        *

    */
      // initialising the spaces.
      int spaces = 2*n-2;
      
      // Outer loop for printing row.
      for(int i = 1;i<=2*n-1;i++){
          
          // stars for first half
          int stars = i;
          
          // stars for the second half.
          if(i>n) stars = 2*n - i;
          
          //for printing the stars
          for(int j=1;j<=stars;j++){
              cout<<"*";
          }
          
          //for printing the spaces
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          
          //for printing the stars
          for(int j = 1;j<=stars;j++){
              cout<<"*";
          }
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
          if(i<n) spaces -=2;
          else spaces +=2;
      }
      
}
void pattern21_al(int num){
    /*
        Pattern

        ******
        *    *
        *    *
        *    *
        *    *
        ******

    */
    for(int i=0;i<num;i++){
        if(i==0 || i==num-1){
            for(int j=0;j<num;j++){
                cout<<"*";
            }
        }else{
            cout<<"*"<<setw(num-2+1)<<"*";
        }
        cout<<endl;
        }
        
    }
void pattern22_al(int num){
    /*
        Pattern

        555555555
        544444445
        543333345
        543222345
        543212345
        543222345
        543333345
        544444445
        555555555

    */

    int dim=2*num-1;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            int top=i;
            int left=j;
            int right=dim-j-1;
            int bottom=dim-i-1;
            cout<<num-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}


int main(){
    int x;
    cin>>x;
    pattern20(x);
    return 0;
}