#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidStudentId(string id) {
    if (id.length() < 3) {
        return false;
    }
    if (id[0] < 'A' || id[0] > 'Z') {
        return false;
    }
    return true;
}

bool isValidScore(double score) {
    if (score >= 0 && score <= 100){
        return true;
    }
    return false;
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score)
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]);
    }
}

double calculateAverageScore(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        return 0.0;
    }

    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += students[i].score;
    }
    return total / size;
}

double findHighestScore(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        return 0.0;
    }

    double highest = students[0].score;
    for (int i = 1; i < size; i++) {
        if (students[i].score > highest) {
            highest = students[i].score;
        }
    }
    return highest;
}

int findStudentById(const Student students[], int size, string targetId) {
    if (students == nullptr || size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (students[i].id == targetId) {
            return i;
        }
    }
    return -1;
}

char determineLetterGrade(double score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}