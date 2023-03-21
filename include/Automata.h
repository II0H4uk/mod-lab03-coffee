#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

namespace UnitTests {

    enum class STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };

    class Automata {
    private:
        int coins;
        vector<string> menu;
        vector<int> prices;
        STATES state;

    public:
        Automata();

        void on();
        void off();
        void coin(int count);
        vector<string> getMenu();
        STATES getState();
        void choice(int type);
        void check(int type);
        void cancel();
        void cook();
        void finish();
    };
}
