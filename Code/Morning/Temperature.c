#include <stdio.h>

struct City
{
    char name[50];
    float temp[7];
    float avg;
    int hotDays;
};

void readCityData(struct City *c)
{
    int i;

    printf("Enter city name: ");
    scanf("%s", c->name);

    printf("Enter temperatures for 7 days:\n");
    for (i = 0; i < 7; i++)
    {
        scanf("%f", &c->temp[i]);
    }
}

void computeCityStats(struct City *c)
{
    int i;
    float sum = 0.0;

    c->hotDays = 0;

    for (i = 0; i < 7; i++)
    {
        sum += c->temp[i];

        if (c->temp[i] > 35.0)
        {
            c->hotDays++;
        }
    }

    c->avg = sum / 7.0;
}

void displayCity(struct City *c)
{
    if (c->avg >= 30.0 && c->hotDays >= 3)
    {
        printf("\nCity Name       : %s", c->name);
        printf("\nAverage Temp    : %.2f", c->avg);
        printf("\nHot Days (>35)  : %d\n", c->hotDays);
    }
}

int main()
{
    int n, i;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    struct City cities[n];

    for (i = 0; i < n; i++)
    {
        printf("\n--- City %d ---\n", i + 1);
        readCityData(&cities[i]);
        computeCityStats(&cities[i]);
    }

    printf("\n=== Qualifying Cities ===\n");
    for (i = 0; i < n; i++)
    {
        displayCity(&cities[i]);
    }

    return 0;
}
