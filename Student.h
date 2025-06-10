#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string id;        // ѧ��
    string name;      // ����
    double dailyScore;     // ƽʱ�ɼ�
    double examScore;      // ���Գɼ�
    double finalScore;     // �����ɼ�

public:
    Student(const string id, const string name,
        double dailyScore, double examScore);

    string getId() const;
    string getName() const;
    double getDailyScore() const;
    double getExamScore() const;
    double getFinalScore() const;

    // ���³ɼ�
    void updateScores(double newDailyScore, double newExamScore);

    // ��ʾѧ����Ϣ
    void display() const;
};

#endif // STUDENT_H