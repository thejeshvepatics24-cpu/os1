#include <stdio.h>
void main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int key=5;
int flag=0;
for(int i=1;i<=10;i++){
        if(i=key){
            flag=1;
            break;
        }
}
if(flag=1){
    printf("Key found");
}
else{
    printf("Key not found");
}
}
