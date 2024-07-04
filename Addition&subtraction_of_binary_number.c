//
//  main.c
//  COA lab
//
//  Created by Santosh Raj on 22/05/2024.
//

#include<stdio.h>
//#include<conio.h>
#include<math.h>
void dectobinary(int nbit,int num, int arry[]){
    while(nbit>=0){

        if(num>0){
            arry[nbit-1] = num%2;
            num = num/2;
            nbit--;
        }
        else{
            arry[nbit-1] = 0;
            nbit--;
        }
    }
    
}


void twoComplement(int arry[], int nbit){
    int bitsum,i,carry=1;
    
    for(i=0;i<nbit;i++){
        arry[i] = !arry[i];
    }
    
    for(i=nbit-1;i>=0;i--){
        bitsum = arry[i]+carry;
        arry[i] = bitsum%2;
        carry = bitsum/2;
    }
}

void showbinary(int *p, int size) {
    // Access elements of the array using the arr[] parameter
    int i;
     for (i = 0; i<size; i++) {
        printf("%d ", *(p+i));
    }
    printf("\n");
}


int addbinary(int arry1[],int arry2[],int nbit,int sum[]){
    int i, bitsum,carry =0;
    for(i=nbit-1;i>=0;i--){
        bitsum = arry1[i]+arry2[i]+carry;
        sum[i] = bitsum%2;
        carry = bitsum/2;
    }
    return carry;
}

void binarytodec(int arry[],int nbit){
    int add=0,i;
    if(arry[0]==1){
        add = add-arry[0] * pow(2,nbit-1);
    }
    else{
        add = add+arry[0] * pow(2,nbit-1);
    }
    for(i=1;i<=nbit-1;i++){
        
        add = add + arry[i] * pow(2,(nbit-1)-i);

    }
    printf("The decimal equivalent is %d",add);
}



int main(){
    int num1,num2,arry1[10],arry2[10],sum[10],nbit,status;
    printf("Enter number of bits: ");
    scanf("%d",&nbit);
    printf("Enter the two number: ");
    scanf("%d%d",&num1,&num2);
    
    // negative
    if(num1<0){
        dectobinary(nbit,(num1),arry1);
        twoComplement(arry1,nbit);
        showbinary(&arry1[0],nbit);
    }
    else{
        dectobinary(nbit,num1,arry1);
        showbinary(&arry1[0],nbit);
    }
    
    //negative
    if(num2<0){
        dectobinary(nbit,(num2),arry2);
        twoComplement(arry2,nbit);
        showbinary(&arry2[0],nbit);
    }
    else{
        dectobinary(nbit,num2,arry2);
        showbinary(&arry2[0],nbit);
    }
    
    
    printf("The sum of binary is: \n");
    status = addbinary(arry1,arry2,nbit,sum);
    showbinary(&sum[0],nbit);
            
    binarytodec(sum,nbit);
    
    if(status == 1){
        printf("\nOverflow Detected");
    }
    
    return 0;
}

