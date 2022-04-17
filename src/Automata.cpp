// Copyright 2022 LepehinM
#include "Automata.h"

using std::string;

Automata::Automata() {
    cash = 0;
    state = off;
}

void Automata::on() {
    if (state == off) {
        state = wait;
    }
}

void Automata::off() {
    if (state == wait) {
        state = off;
    }
}

void Automata::coin(int money) {
    if (state == wait) {
        state = accept;
    }
    if (state == accept) {
        cash += money;
    }
}

bool Automata::check(int index) {
    if (state == check) {
        if (cash >= prices[index]) {
            return true;
        }
    }
    return false;
}

vector<string> Automata::getMenu() {
    return menu;
}

States Automata::getState() {
    return state;
}

int Automata::choice(string drink) {
    int index = -1;
    for (int i = 0; i < menu.size(); i++) {
        if (drink == menu[i]) {
            if (state == accept) {
                state = check;
                index = i;
            }
        }
    }
    return index;
}

void Automata::cook(int index) {
    if (state == check) {
        state = cook;
        cash -= prices[index];
    }
}

int Automata::cancel() {
    int change = 0;
    if (state == accept || state == check) {
        change = cash;
        cash = 0;
        state = wait;
    }
    return change;
}



int Automata::finish() {
    int change = 0;
    if (state == cook) {
        state = wait;
        change = cash;
        cash = 0;
    }
    return change;
}
