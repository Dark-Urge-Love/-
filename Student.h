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
    Student(const std::string& id, const std::string& name,
        double dailyScore, double examScore);

    // Getter����
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