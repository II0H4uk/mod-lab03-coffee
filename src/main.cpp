#include "Automata.h"
#include <iostream>
using std::cout;
using std::cin;

namespace UnitTests {

    void main() {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeMachine = Automata();
        cout << "Íàæàòèå íà êíîïêó âêëþ÷åíèÿ.\n";
        coffeeMachine.on();
        cout << "Ïîëîæèëè 80 ðóáëåé.\n";
        coffeeMachine.coin(80);
        cout << "Ïîëîæèëè åù¸ 20 ðóáëåé.\n";
        coffeeMachine.coin(20);
        cout << "Ïîëó÷èëè ìåíþ.\n\n";
        vector<string> menu = coffeeMachine.getMenu();
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << "\n";
        }
        cout << "\nÂûáðàëè 1 âàðèàíò.\n\n";
        coffeeMachine.choice(1);
        cout << "Âûêëþ÷àåì êîôåìàøèíó.\n";
        coffeeMachine.off();
    }
}
