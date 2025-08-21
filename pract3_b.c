#include<stdio.h>

struct Data {
    int start;
    int finish;
    float profit;
    const char *name;
};

void sort(struct Data Activity[],int size){
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (Activity[i].finish > Activity[j].finish) {
                struct Data temp = Activity[i];
                Activity[i] = Activity[j];
                Activity[j] = temp;
            }
}

int main(){
    int size = 11;
    struct Data Activity[11];
    float profit[11]={10,15,14,12,20,30,32,28,30,40,45};
    int start_time[11]={1,3,0,5,3,5,6,8,8,2,12};
    int finish_time[11]={4,5,6,7,9,9,10,11,12,14,16};
    

    for(int i=0;i<size;i++){
        Activity[i].start=start_time[i];
        Activity[i].finish=finish_time[i];
        Activity[i].profit=profit[i];
    }
    Activity[0].name  = "A1";
    Activity[1].name  = "A2";
    Activity[2].name  = "A3";
    Activity[3].name  = "A4";
    Activity[4].name  = "A5";
    Activity[5].name  = "A6";
    Activity[6].name  = "A7";
    Activity[7].name  = "A8";
    Activity[8].name  = "A9";
    Activity[9].name  = "A10";
    Activity[10].name = "A11";


    sort(Activity,size);
    printf("After sort:\n");

    for (int i=0;i<size;i++)
    {
        printf("%d \t %d  \t %s \t %.0f \n",Activity[i].start,Activity[i].finish,Activity[i].name,Activity[i].profit);
    }

    int last_finish_time = 0;
    float total_profit = 0;

    printf("\nSelected Activities:\n");
    for (int i = 0; i < size; i++) {
        if (Activity[i].start >= last_finish_time) {
            printf("%s \t Profit:%.0f \n",Activity[i].name,Activity[i].profit);
            last_finish_time = Activity[i].finish;
            total_profit += Activity[i].profit;
        }
    }

    printf("\nTotal Profit: %.0f\n", total_profit);
    
}
