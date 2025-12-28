#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct {
    int id;
    char name[30];
    float cgpa;
    int codingScore;        
    int technicalScore;     
    int projects;           
    int communication;      
    int internships;        
    int backlogs;           
    float finalScore;
} 
Candidate;
Candidate candidates[MAX];
Candidate filtered[MAX];
Candidate heap[MAX];
int count = 0;
int filteredCount = 0;
int heapSize = 0;
void addCandidate();
void displayCandidates();
float calculateFinalScore(Candidate *c);
void filterCandidates(float minCGPA);
void insertHeap(Candidate c);
void heapify(int i);
Candidate extractMax();
void generateShortlist();
void addCandidate() {
    if (count >= MAX) {
        printf("Candidate limit reached!\n");
        return;
    }

    candidates[count].id = count + 1;
    printf("Enter name: ");
    scanf("%s", candidates[count].name);
    printf("Enter CGPA: ");
    scanf("%f", &candidates[count].cgpa);
    printf("Enter Coding Test Score (0-100): ");
    scanf("%d", &candidates[count].codingScore);
    printf("Enter Technical Skills Score (0-100): ");
    scanf("%d", &candidates[count].technicalScore);
    printf("Enter number of projects: ");
    scanf("%d", &candidates[count].projects);
    printf("Enter Communication Skill (0-10): ");
    scanf("%d", &candidates[count].communication);
    printf("Enter number of internships: ");
    scanf("%d", &candidates[count].internships);
    printf("Any backlogs? (0 = No, 1 = Yes): ");
    scanf("%d", &candidates[count].backlogs);

    candidates[count].finalScore = calculateFinalScore(&candidates[count]);
    count++;

    printf("Candidate added successfully!\n");
}
void displayCandidates() {
    if (count == 0) {
        printf("No candidates available!\n");
        return;
    }

    printf("\nID Name CGPA FinalScore Backlogs\n");
    for (int i = 0; i < count; i++) {
        printf("%d  %s  %.2f  %.2f  %d\n",
               candidates[i].id,
               candidates[i].name,
               candidates[i].cgpa,
               candidates[i].finalScore,
               candidates[i].backlogs);
    }
}
float calculateFinalScore(Candidate *c) {
    float score = 0;

    score += (c->cgpa / 10) * 30;   
    score += (c->codingScore / 100.0) * 25;
    score += (c->technicalScore / 100.0) * 20;
    score += (c->projects / 10.0) * 10;
    score += (c->communication / 10.0) * 10;
    score += (c->internships / 5.0) * 5;

    return score;
}
void filterCandidates(float minCGPA) {
    filteredCount = 0;

    for (int i = 0; i < count; i++) {
        if (candidates[i].cgpa >= minCGPA &&
            candidates[i].backlogs == 0) {
            filtered[filteredCount++] = candidates[i];
        }
    }

    if (filteredCount == 0)
        printf("No candidates passed filtering!\n");
    else
        printf("%d candidates passed filtering.\n", filteredCount);
}
void insertHeap(Candidate c) {
    heap[heapSize] = c;
    int i = heapSize;
    heapSize++;

    while (i > 0 && heap[(i - 1) / 2].finalScore < heap[i].finalScore) {
        Candidate temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].finalScore > heap[largest].finalScore)
        largest = left;

    if (right < heapSize && heap[right].finalScore > heap[largest].finalScore)
        largest = right;

    if (largest != i) {
        Candidate temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}
Candidate extractMax() {
    Candidate max = heap[0];
    heap[0] = heap[--heapSize];
    heapify(0);
    return max;
}
void generateShortlist() {
    if (filteredCount == 0) {
        printf("No candidates to shortlist!\n");
        return;
    }

    heapSize = 0;
    for (int i = 0; i < filteredCount; i++)
        insertHeap(filtered[i]);

    printf("\n--- FINAL SHORTLIST (Ranked) ---\n");
    printf("Rank Name FinalScore\n");

    int rank = 1;
    while (heapSize > 0) {
        Candidate c = extractMax();
        printf("%d    %s   %.2f\n",
               rank++, c.name, c.finalScore);
    }
}
int main() {
    int choice;
    float minCGPA;

    do {
        printf("\n===== PLACEMENT DRIVE SHORTLISTING SYSTEM =====");
        printf("\n1. Add Candidate");
        printf("\n2. Display All Candidates");
        printf("\n3. Filter Candidates");
        printf("\n4. Generate Final Shortlist");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;

            case 2:
                displayCandidates();
                break;

            case 3:
                printf("Enter minimum CGPA: ");
                scanf("%f", &minCGPA);
                filterCandidates(minCGPA);
                break;

            case 4:
                generateShortlist();
                break;

            case 0:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
