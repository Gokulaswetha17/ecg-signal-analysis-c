
#include <stdio.h>

#define MAX 100
#define LOW_LIMIT 60
#define HIGH_LIMIT 100

struct ECG {
    int heartRate;
};

void analyze(struct ECG readings[], int n) {
    int min = readings[0].heartRate;
    int max = readings[0].heartRate;
    int sum = 0;

    printf("\n--- ECG Analysis Report ---\n");

    for (int i = 0; i < n; i++) {
        int hr = readings[i].heartRate;
        sum += hr;

        if (hr < min)
            min = hr;

        if (hr > max)
            max = hr;

        printf("Reading %d: %d BPM - ", i + 1, hr);

        if (hr < LOW_LIMIT)
            printf("LOW HEART RATE ALERT\n");
        else if (hr > HIGH_LIMIT)
            printf("HIGH HEART RATE ALERT\n");
        else
            printf("Within configured limits\n");
    }

    printf("\nMinimum heart rate: %d BPM\n", min);
    printf("Maximum heart rate: %d BPM\n", max);
    printf("Average heart rate: %.2f BPM\n", (float)sum / n);
}

int main() {
    struct ECG readings[MAX];
    int n;

    printf("ECG Signal Analysis System\n");
    printf("--------------------------\n");

    printf("Enter number of readings (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of readings.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter heart rate %d (BPM): ", i + 1);

        if (scanf("%d", &readings[i].heartRate) != 1 ||
            readings[i].heartRate <= 0) {
            printf("Invalid heart rate reading.\n");
            return 1;
        }
    }

    analyze(readings, n);

    return 0;
}
