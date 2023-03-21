#include "Automata.h"
#include <iostream>
using std::cout;
using std::cin;

namespace UnitTests {

    void main() {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeMachine = Automata();
        cout << "Нажатие на кнопку включения.\n";
        coffeeMachine.on();
        cout << "Положили 80 рублей.\n";
        coffeeMachine.coin(80);
        cout << "Положили ещё 20 рублей.\n";
        coffeeMachine.coin(20);
        cout << "Получили меню.\n\n";
        vector<string> menu = coffeeMachine.getMenu();
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << "\n";
        }
        cout << "\nВыбрали 1 вариант.\n\n";
        coffeeMachine.choice(1);
        cout << "Выключаем кофемашину.\n";
        coffeeMachine.off();
    }
}
