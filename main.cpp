#include "GradeManager.h"
#include <iostream>
#include <limits>

// ��ʾ���˵�
void displayMenu() {
    cout << "\n===== ѧ���ɼ�����ϵͳ =====";
    cout << "\n1. ���ѧ��";
    cout << "\n2. ��ѯѧ��";
    cout << "\n3. ��ʾ�ɼ���";
    cout << "\n4. ɾ��ѧ��";
    cout << "\n5. �޸�ѧ����Ϣ";
    cout << "\n6. �ɼ�ͳ�Ʒ���";
    cout << "\n0. �˳�ϵͳ";
    cout << "\n��ѡ�����: ";
}

// ��Ӷ��ѧ��
void addStudents(GradeManager& manager) {
    char choice;
    do {
        string id, name;
        double daily, exam;

        cout << "\n--- ���ѧ�� ---" << endl;
        cout << "����ѧ��: ";
        cin >> id;
        cout << "��������: ";
        cin >> name;
        cout << "����ƽʱ�ɼ�: ";
        cin >> daily;
        cout << "���뿼�Գɼ�: ";
        cin >> exam;

        manager.addStudent(Student(id, name, daily, exam));
        cout << "ѧ����ӳɹ���" << endl;

        cout << "�������? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    GradeManager manager;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // ���ѧ��
            addStudents(manager);
            break;

        case 2: { // ��ѯѧ��
            string id;
            cout << "����Ҫ��ѯ��ѧ��: ";
            cin >> id;

            Student* student = manager.findStudent(id);
            if (student) {
                cout << "\nѧ��        ����          ƽʱ�ɼ�  ���Գɼ�  �����ɼ�\n";
                cout << "------------------------------------------------------\n";
                student->display();
            }
            else {
                cout << "δ�ҵ���ѧ����" << endl;
            }
            break;
        }

        case 3: // ��ʾ�ɼ���
            manager.displayAll();
            break;

        case 4: { // ɾ��ѧ��
            string id;
            cout << "����Ҫɾ����ѧ��: ";
            cin >> id;

            char confirm;
            cout << "ȷ��ɾ��? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                if (manager.removeStudent(id)) {
                    cout << "ɾ���ɹ���" << endl;
                }
                else {
                    cout << "δ�ҵ���ѧ����" << endl;
                }
            }
            break;
        }

        case 5: { // �޸�ѧ����Ϣ
            string id;
            cout << "����Ҫ�޸ĵ�ѧ��: ";
            cin >> id;

            if (manager.updateStudent(id)) {
                cout << "�޸ĳɹ���" << endl;
            }
            else {
                cout << "δ�ҵ���ѧ����" << endl;
            }
            break;
        }

        case 6: // �ɼ�ͳ��
            manager.analyzeScores();
            break;

        case 0: // �˳�
            cout << "��лʹ�ã��ټ���" << endl;
            break;

        default:
            cout << "��Чѡ�����������룡" << endl;
        }
    } while (choice != 0);

    return 0;
}