#include "pch.h"
#include "Automata.h"
#include <string>
#include <iostream>
#include <vector>
#include <thread>
using std::vector;
using std::cout;
using std::cin;

namespace UnitTests {

    Automata::Automata() {
        coins = 0;
        menu = { "�������� ����", "���������", "��������", "������", "��������", "��������", "���� ����", "�����", "����� �����", "����� ����" };
        prices = { 100, 150, 200, 250, 300, 350, 400, 450, 500, 550 };
        state = STATES::OFF;
    }

    void Automata::on() {
        if (state == STATES::OFF) {
            state = STATES::WAIT;
            cout << "���������� ��������...\n";
        }
    }

    void Automata::off() {
        if (state == STATES::WAIT) {
            state = STATES::OFF;
            cout << "���������� ���������...\n";
        }
    }

    void Automata::coin(int count) {
        if (state == STATES::WAIT)
        {
            state = STATES::ACCEPT;
        }
        if (count == 0)
            cancel();
        coins += count;
    }

    vector<string> Automata::getMenu() {
        return menu;
    }

    STATES Automata::getState() {
        return state;
    }

    void Automata::choice(int type) {
        if (state != STATES::ACCEPT)
            return;
        state = STATES::CHECK;
        check(type);
    }

    void Automata::check(int type) {
        if (coins < prices[type - 1] && state == STATES::CHECK) {
            std::cout << "\n������������ �������, ���������" << prices[type - 1] - coins << "�����.\n";
            state = STATES::WAIT;
            cancel();
            return;
        }
        if (state == STATES::CHECK) {
            std::cout << "������������� ������...\n";
            coins -= prices[type - 1];
            state = STATES::COOK;
            cook();
        }
    }

    void Automata::cancel() {
        if (state == STATES::ACCEPT)
            state = STATES::WAIT;
    }

    void Automata::cook() {
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "��������� 20%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "��������� 40%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "��������� 60%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "��������� 80%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "��������� 100%\n\n";
        finish();
    }

    void Automata::finish() {
        std::cout << "���� �����, ����������, ��������...\n";
        if (state == STATES::COOK)
            state = STATES::WAIT;
    }
}
