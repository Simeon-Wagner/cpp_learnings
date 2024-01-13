#include <stdio.h>
#define CHAR_MAX 255
int bestof(int time, int record);
size_t multiplyarray(int* array, int value);

int main (){
    FILE* fp = fopen("input.txt", "r");
    int times[4]={0};
    int distance[4]={0};
    int counts[4]={0};
    char buffer[CHAR_MAX]={0};
    fgets(buffer, CHAR_MAX, fp);
    sscanf(buffer, "Time:        %d %d %d %d", &times[0], &times[1], &times[2], &times[3]);
    fgets(buffer, CHAR_MAX, fp);
    sscanf(buffer, "Distance:   %d %d %d %d", &distance[0], &distance[1], &distance[2], &distance[3]);

    for (int i = 0; i < 4; i++)
    {
        counts[i]=bestof(times[i], distance[i]);
        printf("%d. Rennen hat %d bessere Moeglichkeiten\n", i+1, counts[i]);
    }
    printf("Alles Multipliziert gibt: %zu\n", multiplyarray(counts, 4));
    fclose(fp);
    return 0;
}

int bestof(int time, int record)
{
    int count = 0;
    int distance = 0;
    for (int i = 0; i <= time; i++)
    {
        distance = (time-i)*i;
        if(distance > record) count++;
    }
    return count;
}

size_t multiplyarray(int* array, int value)
{
   size_t sum = 1;
   for (int i = 0; i < value; i++)
   {
    sum *= (size_t) *(array + i);
   }
    return sum;
}