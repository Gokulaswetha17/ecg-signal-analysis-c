
#include <stdio.h>

int main() {
    int heartRate;

    printf("ECG Signal Analysis System\n");
    printf("--------------------------\n");

    printf("Enter heart rate in BPM: ");
    scanf("%d", &heartRate);

    printf("Recorded heart rate: %d BPM\n", heartRate);

    return 0;
}
