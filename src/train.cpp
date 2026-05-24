// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

Train::~Train() {
    if (!first) {
        return;
    }
    if (first->next == first) {
        delete first;
        return;
    }
    Car* current = first->next;
    while (current != first) {
        Car* temp = current;
        current = current->next;
        delete temp;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* car = new Car();
    car->light = light;
    car->next = nullptr;
    car->prev = nullptr;
    if (!first) {
        first = car;
        first->next = first;
        first->prev = first;
        return;
    }
    Car* last = first->prev;
    last->next = car;
    car->prev = last;
    car->next = first;
    first->prev = car;
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    countOp = 0;
    Car* start = first;
    start->light = false;
    int steps = 1;
    while (true) {
        Car* current = start;
        for (int i = 0; i < steps; ++i) {
            current = current->next;
            countOp++;
        }
        if (!current->light) {
            if (current == start) {
                return steps;
            }
            current->light = true;
        }
        steps++;
    }
}
