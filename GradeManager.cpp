#include "GradeManager.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// ���ѧ��
void GradeManager::addStudent(const Student& student) {
    students.push_back(student);
}

// ��ѧ�Ų���ѧ������
int GradeManager::findStudentIndex(const string& id) const {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1; // δ�ҵ�
}

// ��ѯѧ��
Student* GradeManager::findStudent(const string& id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        return &students[index];
    }
    return nullptr;
}

// ��ʾ����ѧ������ѧ������
void GradeManager::displayAll() const {
    if (students.empty()) {
        cout << "û��ѧ����¼��" << endl;
        return;
    }

    // ���������������򣨲��޸�ԭ˳��
    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(),
        [](const Student& a, const Student& b) {
            return a.getId() < b.getId();
        });

    // ��ӡ��ͷ
    cout << "\nѧ��        ����          ƽʱ�ɼ�  ���Գɼ�  �����ɼ�\n";
    cout << "------------------------------------------------------\n";

    // ��ӡѧ����Ϣ
    for (const auto& student : sortedStudents) {
        student.display();
    }
    std::cout << std::endl;
}

// ɾ��ѧ��
bool GradeManager::removeStudent(const std::string& id) {
    int index = findStudentIndex(id);
    if (index != -1) {
        students.erase(students.begin() + index);
        return true;
    }
    return false;
}

// �޸�ѧ����Ϣ
bool GradeManager::updateStudent(const std::string& id) {
    Student* student = findStudent(id);
    if (student) {
        double daily, exam;
        std::cout << "�����µ�ƽʱ�ɼ�: ";
        std::cin >> daily;
        std::cout << "�����µĿ��Գɼ�: ";
        std::cin >> exam;

        student->updateScores(daily, exam);
        return true;
    }
    return false;
}

// �ɼ�ͳ��
void GradeManager::analyzeScores() const {
    if (students.empty()) {
        std::cout << "û��ѧ����¼��" << std::endl;
        return;
    }

    // �ɼ��ֶ�ͳ��
    std::map<std::string, int> scoreGroups = {
        {"����(90-100)", 0},
        {"����(80-89)", 0},
        {"�е�(70-79)", 0},
        {"����(60-69)", 0},
        {"������(0-59)", 0}
    };

    double total = 0;

    // ͳ�Ƹ�����������
    for (const auto& student : students) {
        double score = student.getFinalScore();
        total += score;

        if (score >= 90) scoreGroups["����(90-100)"]++;
        else if (score >= 80) scoreGroups["����(80-89)"]++;
        else if (score >= 70) scoreGroups["�е�(70-79)"]++;
        else if (score >= 60) scoreGroups["����(60-69)"]++;
        else scoreGroups["������(0-59)"]++;
    }

    // ����ƽ����
    double average = total / students.size();

    // ���ͳ�ƽ��
    std::cout << "\n============== �ɼ�ͳ�Ʒ��� ==============\n";
    std::cout << "�༶ƽ���ɼ�: " << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "----------------------------------------\n";
    std::cout << "�ɼ��ֶ�ͳ��:\n";

    for (const auto& group : scoreGroups) {
        double percentage = static_cast<double>(group.second) / students.size() * 100;
        std::cout << group.first << ": " << group.second << "�� ("
            << std::fixed << std::setprecision(1) << percentage << "%)" << std::endl;
    }
    std::cout << "========================================\n\n";
}