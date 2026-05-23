// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "train.h"

void experiment(const std::string& filename, int maxN, int mode) {
    std::ofstream fout(filename);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);
    for (int n = 2; n <= maxN; n += 2) {
        Train train;
        for (int i = 0; i < n; ++i) {
            bool light = false;
            switch (mode) {
            case 0:
                light = false;
                break;
            case 1:
                light = true;
                break;
            case 2:
                light = dist(gen);
                break;
            }
            train.addCar(light);
        }
        train.getLength();
        fout << n << "," << train.getOpCount() << std::endl;
        std::cout << "n = " << n << " operations = " << train.getOpCount() << std::endl;
    }
    fout.close();
}

int main() {
    int maxN = 200;
    experiment("off.csv", maxN, 0);
    experiment("on.csv", maxN, 1);
    experiment("random.csv", maxN, 2);
    return 0;
}
