#include "Hospital.hpp"

#include <fstream>
#include <future>
#include <chrono>
#include <future>

using namespace std::chrono;

vector<Hospital> loadHospitals(string filename) {
    try {
        ifstream ifs {filename};

        if(!ifs){
            cout << "File not found!" << endl;
            exit(1);
        }

        string line;
        vector<Hospital> hospitals;
        bool is_first = true;

        while (getline(ifs, line)) {

            if (is_first) {
                is_first = false;
                continue;
            }
            hospitals.emplace_back(line);
        }

        return hospitals;
    } catch (...) {
        cout << "Error when loading file..." << endl;
        return vector<Hospital>();
    }
}

// TODO: Part 2 Function Definitions for

long inpatient_total_charges_(vector <Hospital> &hospitals){
    int long sum = 0;
    for(int i = 0; i < hospitals.size(); i++){
       sum += hospitals[i].inpatient_total_charges();
    }   
    return sum/hospitals.size();
}
long outpatient_total_charges_(vector <Hospital> &hospitals){
    int long sum = 0;
    for(int i = 0; i < hospitals.size(); i++){
       sum += hospitals[i].outpatient_total_charges();
    }   
    return sum/hospitals.size();
}
long total_salaries_(vector <Hospital> &hospitals){
    int long sum = 0;
    for(int i = 0; i < hospitals.size(); i++){
       sum += hospitals[i].total_salaries();
    }   
    return sum/hospitals.size();
}
long total_income_(vector <Hospital> &hospitals){
    int long sum = 0;
    for(int i = 0; i < hospitals.size(); i++){
       sum += hospitals[i].total_income();
    }   
    return sum/hospitals.size();
}

int main(int argc, char *argv[]) {
    cout << "Welcome to Hospital DB 1.0" << endl;

    if (argc != 2) {
        cout << "USAGE: ./a.out FILENAME" << endl;
        return 1;
    }

    vector<Hospital> hospitals = loadHospitals(argv[1]);

    if (hospitals.size() == 0) {
        cout << "No hospitals read from file." << endl;
        return 1;
    }

    auto t0 = high_resolution_clock::now();

    // Call calculation functions and print results here
    cout << inpatient_total_charges_(hospitals) << endl;
    cout << outpatient_total_charges_(hospitals) << endl;
    cout << total_salaries_(hospitals) << endl;
    cout << total_income_(hospitals) << endl;

    auto t1 = high_resolution_clock::now();

    ofstream file("part3_improved.txt", ios::app);

    if(!file.is_open()){
        cout << "Could not open file!" << endl;
    }

    // Print time in nanoseconds
    file << "Single Thread: " << duration_cast<nanoseconds>(t1-t0).count()
    << " nanoseconds passed" << endl;

    file.close();

    const auto h_ref = ref(hospitals);
    
    t0 = high_resolution_clock::now();

    future<long> inpatient_total_charges_future = async(launch::async, inpatient_total_charges_, h_ref);
    future<long> outpatient_total_charges_future = async(launch::async, outpatient_total_charges_, h_ref);
    future<long> total_salaries_future = async(launch::async, total_salaries_, h_ref);
    future<long> total_income_future = async(launch::async, total_income_, h_ref);

    cout << inpatient_total_charges_future.get() << endl;
    cout << outpatient_total_charges_future.get() << endl;
    cout << total_salaries_future.get() << endl;
    cout << total_income_future.get() << endl;

    t1 = high_resolution_clock::now();

    ofstream file_4("part4_benchmark.txt", ios::app);

    if(!file_4.is_open()){
        cout << "Could not open file!" << endl;
    }

    // Print time in nanoseconds
    file_4 << "Single Thread: " << duration_cast<nanoseconds>(t1-t0).count()
    << " nanoseconds passed" << endl;

    file_4.close();

    return 0;
}
