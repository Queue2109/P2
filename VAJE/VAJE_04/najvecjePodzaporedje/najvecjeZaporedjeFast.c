#include <stdio.h>
#include <limits.h>

    int main(){

        int n;
        scanf("%d", &n);

        int sum = INT_MIN;
        int sumTemp = 0;
        for(int i = 0; i < n; i++){
            int temp = 0;
            scanf("%d", &temp);
            sumTemp += temp;

            if(sumTemp > sum){
                sum = sumTemp;
            }

            if(sumTemp < 0){
                sumTemp = 0;
            }
        }

        printf("%d\n", sum);
        return 0;
    }