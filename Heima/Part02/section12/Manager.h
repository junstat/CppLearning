#pragma once

#include <iostream>
#include "Worker.h"

class Manager : public Worker {
public:
    Manager(int id, string name, int dId);

    void showInfo() override;

    string getDeptName() override;
};