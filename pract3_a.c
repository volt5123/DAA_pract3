#include <stdio.h>
#include <time.h>

struct Data {
    int weight;
    int profit;
    float ratio;
};

void compareByWeight(struct Data BOX[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (BOX[i].weight > BOX[j].weight) {
                struct Data temp = BOX[i];
                BOX[i] = BOX[j];
                BOX[j] = temp;
            }
}

void compareByProfit(struct Data BOX[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (BOX[i].profit < BOX[j].profit) {
                struct Data temp = BOX[i];
                BOX[i] = BOX[j];
                BOX[j] = temp;
            }
}

void compareByRatio(struct Data BOX[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (BOX[i].ratio < BOX[j].ratio) {
                struct Data temp = BOX[i];
                BOX[i] = BOX[j];
                BOX[j] = temp;
            }
}

float loadTruck(struct Data BOX[], int size, int capacity) {
    float total_profit = 0.0;
    int current_weight = 0;

    for (int i = 0; i < size; i++) {
        if (BOX[i].weight == 0) {
            total_profit += BOX[i].profit;
            continue;
        }

        if (current_weight + BOX[i].weight <= capacity) {
            current_weight += BOX[i].weight;
            total_profit += BOX[i].profit;
        } else {
            int remaining = capacity - current_weight;
            if (remaining > 0) {
                total_profit += ((float)remaining / BOX[i].weight) * BOX[i].profit;
                current_weight += remaining;
            }
            break;
        }
    }
    return total_profit;
}

int main() {
    int capacity = 850;
    int size = 50;

    int Weights[50] = {7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8, 15, 42, 9, 0, 42, 47, 52, 32, 26, 48, 55, 6, 29, 84, 2, 4, 18, 56, 7, 29, 93, 44, 71, 3, 86, 66, 31, 65, 0, 79, 20, 65, 52, 13};
    int Profits[50] = {360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147, 78, 256, 63, 17, 120, 164, 432, 35, 92, 110, 22, 42, 50, 323, 514, 28, 87, 73, 78, 15, 26, 78, 210, 36, 85, 189, 274, 43, 33, 10, 19, 389, 276, 312};

    struct Data BOX[50], tempBOX[50];

    for (int i = 0; i < size; i++) {
        BOX[i].weight = Weights[i];
        BOX[i].profit = Profits[i];
        if(BOX[i].weight == 0){
            BOX[i].ratio = BOX[i].profit;
        }
        else{
            BOX[i].ratio = (float)BOX[i].profit / BOX[i].weight;
        }
    }

    //compareByWeight time
    for (int i = 0; i < size; i++) tempBOX[i] = BOX[i];
    clock_t start = clock();
    compareByWeight(tempBOX, size);
    float profit_weight = loadTruck(tempBOX, size, capacity);
    clock_t end = clock();
    double time_weight = (double)(end - start) / CLOCKS_PER_SEC;

    //compareByProfit time
    for (int i = 0; i < size; i++) tempBOX[i] = BOX[i];
    start = clock();
    compareByProfit(tempBOX, size);
    float profit_profit = loadTruck(tempBOX, size, capacity);
    end = clock();
    double time_profit = (double)(end - start) / CLOCKS_PER_SEC;

    //compareByRatio time
    for (int i = 0; i < size; i++) tempBOX[i] = BOX[i];
    start = clock();
    compareByRatio(tempBOX, size);
    float profit_ratio = loadTruck(tempBOX, size, capacity);
    end = clock();
    double time_ratio = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Profit using Minimum Weight: %.2f\n", profit_weight);
    printf("Time: %.8f seconds\n", time_weight);

    printf("Profit using Maximum Profit: %.2f\n", profit_profit);
    printf("Time: %.8f seconds\n", time_profit);

    printf("Profit using Profit/Weight Ratio: %.2f\n", profit_ratio);
    printf("Time: %.8f seconds\n", time_ratio);


    return 0;
}
