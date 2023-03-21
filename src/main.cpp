#include "pch.h"
#include "Automata.h"
#include <iostream>
using std::cout;
using std::cin;

namespace UnitTests {

    void main() {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeMachine = Automata();
        cout << "������� �� ������ ���������.\n";
        coffeeMachine.on();
        cout << "�������� 80 ������.\n";
        coffeeMachine.coin(80);
        cout << "�������� ��� 20 ������.\n";
        coffeeMachine.coin(20);
        cout << "�������� ����.\n\n";
        vector<string> menu = coffeeMachine.getMenu();
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << "\n";
        }
        cout << "\n������� 1 �������.\n\n";
        coffeeMachine.choice(1);
        cout << "��������� ����������.\n";
        coffeeMachine.off();
    }
}
