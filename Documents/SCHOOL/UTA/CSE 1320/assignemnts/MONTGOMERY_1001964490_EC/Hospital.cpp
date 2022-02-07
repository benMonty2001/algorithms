#include "Hospital.hpp"
#include "utils.hpp"

#include <fstream>
#include <string>

Hospital::Hospital(string csv_line) {
    vector<string> tokens = tokenizeCSVLine(csv_line);

    provider_ccn_ = stoi(tokens[0]);
    name_ = tokens[1];
    address_ = tokens[2];
    city_ = tokens[3];
    state_ = tokens[4];
    vector<int> zip = parseZip(tokens[5]);
    zip_ = zip[0];
    if (zip.size() == 2) {
        zip_ext_ = zip[1];
    }
    county_ = tokens[6];
    try {
        num_beds_ = stoi(tokens[7]);
    } catch (invalid_argument& e) {
        num_beds_ = 0;
    }

    try {
        inpatient_total_charges_ = parsePrice(tokens[8]);
    } catch (...) {
        cout << "Warning: Missing price!" << endl;
        inpatient_total_charges_ = 0;
    }

    try {
        outpatient_total_charges_ = parsePrice(tokens[9]);
    } catch (...) {
        cout << "Warning: Missing price!" << endl;
        outpatient_total_charges_ = 0;
    }

    try {
        total_salaries_ = parsePrice(tokens[10]);
    } catch (...) {
        cout << "Warning: Missing price!" << endl;
        total_salaries_ = 0;
    }

    try {
        total_income_ = parsePrice(tokens[11]);
    } catch (...) {
        cout << "Warning: Missing price!" << endl;
        total_income_ = 0;
    }
}
