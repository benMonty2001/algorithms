#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hospital {
    int provider_ccn_;
    string name_;
    string address_;
    string city_;
    string state_;
    int zip_;
    int zip_ext_;
    string county_;
    int num_beds_;
    long inpatient_total_charges_;
    long outpatient_total_charges_;
    long total_salaries_;
    long total_income_;

    public:
        Hospital() : provider_ccn_{0}, zip_{0}, zip_ext_{0}, num_beds_{0}, inpatient_total_charges_{0},
            outpatient_total_charges_{0}, total_salaries_{0}, total_income_{0} {}
        Hospital(string);

        const auto & inpatient_total_charges() const { return inpatient_total_charges_; }
        const auto & outpatient_total_charges() const { return outpatient_total_charges_; }
        const auto & total_salaries() const { return total_salaries_; }
        const auto & total_income() const { return total_income_; }

        friend ostream& operator<<(ostream& os, const Hospital & hospital) {
            return os << "[" << to_string(hospital.provider_ccn_) << "] " << hospital.name_
                << " " << hospital.address_ << ", " << hospital.city_ << ", "
                << hospital.state_ << " "
                << hospital.zip_ << " $" << hospital.inpatient_total_charges_;
        }
};
