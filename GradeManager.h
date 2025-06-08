#pragma once
#ifndef GRADE_MANAGER_H
#define GRADE_MANAGER_H

#include "Student.h"
#include <vector>
#include <map>
using namespace std;

class GradeManager {
private:
    vector<Student> students;  // �洢����ѧ��

    // ��ѧ�Ų���ѧ������
    int findStudentIndex(const string& id) const;

public:
    // ���ѧ��
    void addStudent(const Student& student);

    // ��ѯѧ��
    Student* findStudent(const string& id);

    // ��ʾ����ѧ������ѧ������
    void displayAll() const;

    // ɾ��ѧ��
    bool removeStudent(const string& id);

    // �޸�ѧ����Ϣ
    bool updateStudent(const string& id);

    // �ɼ�ͳ��
    void analyzeScores() const;
};

#endif // GRADE_MANAGER_H
