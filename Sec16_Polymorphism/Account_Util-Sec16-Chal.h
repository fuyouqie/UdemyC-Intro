#pragma once

#include <vector>
#include "Account-Sec16-Chal.h"

// Utility helper functions for Account class

void display(const std::vector<Account*> &accounts);
void deposit(std::vector<Account*> &accounts, double amount);
void withdraw(std::vector<Account*> &accounts, double amount);