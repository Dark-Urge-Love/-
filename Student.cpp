#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ���캯��
Student::Student(const std::string& id, const std::string& name,
    double dailyScore, double examScore)
    : id(id), name(name), dailyScore(dailyScore), examScore(examScore) {
    // ���������ɼ���ƽʱ40% + ����60%��
    finalScore = dailyScore * 0.4 + examScore * 0.6;
}

// Getter����ʵ��
string Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getDailyScore() const { return dailyScore; }
double Student::getExamScore() const { return examScore; }
double Student::getFinalScore() const { return finalScore; }

// ���³ɼ�
void Student::updateScores(double newDailyScore, double newExamScore) {
    dailyScore = newDailyScore;
    examScore = newExamScore;
    finalScore = dailyScore * 0.4 + examScore * 0.6;
}

// ��ʾѧ����Ϣ
void Student::display() const {
    cout << left << setw(12) << id
        << setw(15) << name
        << setw(10) << fixed << setprecision(2) << dailyScore
        << setw(10) << examScore
        << setw(10) << finalScore <<endl;
}