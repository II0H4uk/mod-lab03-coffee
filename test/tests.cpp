// Copyright 2022 GHA Test Team

#include "Automata.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <thread>

namespace UnitTests {

    TEST(OFF_cond, OFF_WAIT) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(WAIT_cond, WAIT_OFF) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.off();
        EXPECT_EQ(coffeeTest.getState(), STATES::OFF);
    }

    TEST(WAIT_cond, WAIT_ACCEPT) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        EXPECT_EQ(coffeeTest.getState(), STATES::ACCEPT);
    }

    TEST(ACCEPT_cond, ACCEPT_WAIT) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(0);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(ACCEPT_cond, ACCEPT_ACCEPT) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(10);
        coffeeTest.coin(90);
        EXPECT_EQ(coffeeTest.getState(), STATES::ACCEPT);
    }

    TEST(CHECK_cond, CHECK_CANCLE) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(10);
        coffeeTest.choice(2);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(CHECK_cond, CHECK_COOK) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(1000);
        coffeeTest.choice(4);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(COOK_cond, COOK_WAIT) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(1000);
        coffeeTest.choice(8);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test1) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test2) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.choice(1);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test3) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.choice(7);
        coffeeTest.coin(200);
        coffeeTest.choice(7);
        coffeeTest.coin(100);
        coffeeTest.choice(7);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test4) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.choice(7);
        coffeeTest.coin(200);
        coffeeTest.choice(7);
        coffeeTest.coin(100);
        coffeeTest.choice(7);
        coffeeTest.off();
        EXPECT_EQ(coffeeTest.getState(), STATES::OFF);
    }

    TEST(Generic_test, test5) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.off();
        coffeeTest.on();
        coffeeTest.coin(1200);
        coffeeTest.choice(10);
        coffeeTest.choice(10);
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test6) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.off();
        coffeeTest.on();
        EXPECT_EQ(coffeeTest.getState(), STATES::WAIT);
    }

    TEST(Generic_test, test7) {
        setlocale(LC_ALL, "RUSSIAN");
        Automata coffeeTest = Automata();
        coffeeTest.on();
        coffeeTest.coin(100);
        coffeeTest.choice(10);
        coffeeTest.coin(200);
        coffeeTest.choice(2);
        coffeeTest.off();
        EXPECT_EQ(coffeeTest.getState(), STATES::OFF);
    }
}
