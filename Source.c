#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Entity.c"

#define VALUE 100

struct Entry Entries[VALUE];
int count;

int GetNumber() {
	int result = -1;
	if (!scanf("%d", &result) && result < 0)
		return -1;
	return result;
}

int Menu() {
	const char * menu = "1.Add\n\r2.Remove\n\r3.Show\n\r4.Save\n\r5.Exit\n\rChose menu number: ";
	printf("%s",menu);
	return GetNumber();
}

void GetEntry() {
	printf("Write data...\r\n");
        printf("Name: ");
        scanf("%s", &Entries[count].FIO);
        printf("TypeOfByke: ");
        scanf("%s", &Entries[count].TypeOfBike);
        printf("Stage: ");
        scanf("%s", &Entries[count].Stage);
}


void Add() {
	system("clear");
	GetEntry();
	count += 1;
	system("clear");
}

void Remove(int value) {
	if (value >= count)
		return;
	struct Entry tempEntry[100];
	Entries[value] = tempEntry[value];
	for (int i = value; i < count - 1; i++) {
		Entries[i] = Entries[i + 1];
	}
	count -= 1;
}

void Show() {
	for (int i = 0; i < count; i++) {
                printf("Number of member %d\r\n", i);
                printf("Name: %s\r\n", Entries[i].FIO);
                printf("TypeOfBike: %s\r\n", Entries[i].TypeOfBike);
                printf("Stage: %s\r\n", Entries[i].Stage);
		printf("======================================\r\n");
	}
	scanf("%s");
	system("clear");
}

int main(void) {
	count = 0;
	const char * path = "data.bin";
	int answer = -1;
	while (answer != 5) {
		answer = Menu();
		switch (answer) {
			case 1:
				Add();
				break;
			case 2:
				system("clear");
				printf("What the cell do you want?\n\r");
				Remove(GetNumber());
				break;
			case 3:
				system("clear");
				Show();
				break;
			case 4:
				break;
			case 5:
				system("clear");
				break;
		}
	}
}
