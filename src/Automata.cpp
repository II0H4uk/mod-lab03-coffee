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
        menu = { "Òóðåöêèé êîôå", "Àìåðèêàíî", "Ýñïðåññî", "Ëààòòå", "Êàïó÷èíî", "Ìàêêèàòî", "Ôëýò óàéò", "Ìîêêà", "Ôðåí÷ ïðåññ", "Àéðèø êîôå" };
        prices = { 100, 150, 200, 250, 300, 350, 400, 450, 500, 550 };
        state = STATES::OFF;
    }

    void Automata::on() {
        if (state == STATES::OFF) {
            state = STATES::WAIT;
            cout << "Êîôåìàøèíà âêëþ÷åíà...\n";
        }
    }

    void Automata::off() {
        if (state == STATES::WAIT) {
            state = STATES::OFF;
            cout << "Êîôåìàøèíà âûêëþ÷åíà...\n";
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
            std::cout << "\nÍåäîñòàòî÷íî ñðåäñòâ, íåõâàòàåò" << prices[type - 1] - coins << "ìîíåò.\n";
            state = STATES::WAIT;
            cancel();
            return;
        }
        if (state == STATES::CHECK) {
            std::cout << "Ïðèãîòîâëåíèå çàêàçà...\n";
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
        std::cout << "Çàâåðøåíî 20%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Çàâåðøåíî 40%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Çàâåðøåíî 60%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Çàâåðøåíî 80%...\n";
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Çàâåðøåíî 100%\n\n";
        finish();
    }

    void Automata::finish() {
        std::cout << "Êîôå ãîòîâ, ïîæàëóéñòà, çàáåðèòå...\n";
        if (state == STATES::COOK)
            state = STATES::WAIT;
    }
}
