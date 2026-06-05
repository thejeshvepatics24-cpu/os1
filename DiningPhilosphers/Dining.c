#include <stdio.h> 
int main() {
int n, i;    
printf("Enter number of philosophers: ");
scanf("%d", &n);    
printf("--- Resource Allocation Protocol Sequences ");   
for(i = 0; i < n; i++) { 
           printf("Philosopher %d allocates left chopstick %d and right chopstick %d -> Status: EATIN		G ",                i + 1, i, (i + 1) % n);
            }
            printf("1BF24CS319");    
            return 0; 
        }