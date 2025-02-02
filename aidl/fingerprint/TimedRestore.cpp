/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "TimedRestore.h"
#include <fstream>

TimedRestore::TimedRestore(const std::string& filename)
: filename(filename) {
	std::ifstream ifs(filename);
	if (ifs.fail()) return;
	ifs >> saved_value;
}

TimedRestore::~TimedRestore(void) {
	std::ofstream ofs(filename);
	if (ofs.fail()) return;
	ofs << saved_value;
}

void TimedRestore::set(const std::string& value)
{
    std::ofstream ofs(filename);
    if (saved_value > std::stoi(value)) return;
    if (ofs.fail()) return;
    ofs << value;
}
