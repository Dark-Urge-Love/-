#include "GradeManager.h"
#include <iostream>
#include <limits>

// ��ʾ���˵�
void displayMenu() {
    std::cout << "\n===== ѧ���ɼ�����ϵͳ =====";
    std::cout << "\n1. ���ѧ��";
    std::cout << "\n2. ��ѯѧ��";
    std::cout << "\n3. ��ʾ�ɼ���";
    std::cout << "\n4. ɾ��ѧ��";
    std::cout << "\n5. �޸�ѧ����Ϣ";
    std::cout << "\n6. �ɼ�ͳ�Ʒ���";
    std::cout << "\n0. �˳�ϵͳ";
    std::cout << "\n��ѡ�����: ";
}

// ��Ӷ��ѧ��
void addStudents(GradeManager& manager) {
    char choice;
    do {
        std::string id, name;
        double daily, exam;

        std::cout << "\n--- ���ѧ�� ---" << std::endl;
        std::cout << "����ѧ��: ";
        std::cin >> id;
        std::cout << "��������: ";
        std::cin >> name;
        std::cout << "����ƽʱ�ɼ�: ";
        std::cin >> daily;
        std::cout << "���뿼�Գɼ�: ";
        std::cin >> exam;

        manager.addStudent(Student(id, name, daily, exam));
        std::cout << "ѧ����ӳɹ���" << std::endl;

        std::cout << "�������? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    GradeManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        // ������뻺����
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: // ���ѧ��
            addStudents(manager);
            break;

        case 2: { // ��ѯѧ��
            std::string id;
            std::cout << "����Ҫ��ѯ��ѧ��: ";
            std::cin >> id;

            Student* student = manager.findStudent(id);
            if (student) {
                std::cout << "\nѧ��        ����          ƽʱ�ɼ�  ���Գɼ�  �����ɼ�\n";
                std::cout << "------------------------------------------------------\n";
                student->display();
            }
            else {
                std::cout << "δ�ҵ���ѧ����" << std::endl;
            }
            break;
        }

        case 3: // ��ʾ�ɼ���
            manager.displayAll();
            break;

        case 4: { // ɾ��ѧ��
            std::string id;
            std::cout << "����Ҫɾ����ѧ��: ";
            std::cin >> id;

            char confirm;
            std::cout << "ȷ��ɾ��? (y/n): ";
            std::cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                if (manager.removeStudent(id)) {
                    std::cout << "ɾ���ɹ���" << std::endl;
                }
                else {
                    std::cout << "δ�ҵ���ѧ����" << std::endl;
                }
            }
            break;
        }

        case 5: { // �޸�ѧ����Ϣ
            std::string id;
            std::cout << "����Ҫ�޸ĵ�ѧ��: ";
            std::cin >> id;

            if (manager.updateStudent(id)) {
                std::cout << "�޸ĳɹ���" << std::endl;
            }
            else {
                std::cout << "δ�ҵ���ѧ����" << std::endl;
            }
            break;
        }

        case 6: // �ɼ�ͳ��
            manager.analyzeScores();
            break;

        case 0: // �˳�
            std::cout << "��лʹ�ã��ټ���" << std::endl;
            break;

        default:
            std::cout << "��Чѡ�����������룡" << std::endl;
        }
    } while (choice != 0);

    return 0;
}