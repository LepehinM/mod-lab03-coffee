// Copyright 2022 LepehinM
#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;
enum STATES {
    on,
    off,
    coin,
    etMenu,
    getStates,
    choice,
    check,
    cancel,
    cook,
    finish,
};

class Automata {
    public:
    int cash;
    STATES state;
    const vector<string> menu = { "coffee", "tea", "cocoa"};
    const vector<int> prices = {100,70,80};
    Automata();
    void on();
    void off();
    void coin(int money);
    vector<string> getMenu();
    STATES getStates();
    int choice(string drink);
    bool check(int index);
    int cancel();
    void cook(int index);
    int finish();
};