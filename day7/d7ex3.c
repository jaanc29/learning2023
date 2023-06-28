#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SENSOR_ID 10
#define MAX_TIMESTAMP 10

typedef struct {
    int entryNo;
    char sensorNo[MAX_SENSOR_ID];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP];
} LogEntry;

void readLogFile(LogEntry logEntries[], int* numEntries) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    char line[256];
    char* token;
    int i = 0;

    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        logEntries[i].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[i].sensorNo, token, MAX_SENSOR_ID);

        token = strtok(NULL, ",");
        logEntries[i].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[i].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[i].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[i].timestamp, token, MAX_TIMESTAMP);

        i++;
    }

    *numEntries = i;

    fclose(file);
}

void displayLogEntries(const LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    readLogFile(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}