#include <stdio.h>
void main(){
int flag=0;
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }

}
if(flag==1){
    printf("Duplicate exist");
}
else{
    printf("Duplicate not exist");
}
}
