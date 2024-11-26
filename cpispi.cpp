#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

float findSpi(vector<float>& grades, vector<int>& credits) {
    if (grades.size() != credits.size() || grades.empty()) {
        cout << "Grades and credits arrays must have the same non-zero length." << endl;
        return -1; 
    }

    float sumProduct = 0;
    int sumCredits = 0;
    for (int i = 0; i < grades.size(); i++) {
        sumProduct += grades[i] * credits[i];
        sumCredits += credits[i];
    }

    if (sumCredits == 0) {
        cout << "Sum of credits is zero, cannot divide by zero." << endl;
        return -1; 
    }

    return sumProduct / sumCredits; 
}

float calculateCpi(const vector<float>& spi) {
    if (spi.empty()) {
        cout << "No SPI data provided." << endl;
        return -1; 
    }

    float sumSpi = 0;
    for (int i = 0; i < spi.size(); i++) {
    sumSpi += spi[i];
}


    return sumSpi / spi.size(); 
}

void calculateSpiAndCpi() {
    vector<float> spiList; 

    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    for (int sem = 1; sem <= numSemesters; sem++) {
        int numSubjects;
        cout << "\nSemester " << sem << ":\n";
        cout << "Enter the number of subjects: ";      //input
        cin >> numSubjects;

        vector<float> grades(numSubjects);
        vector<int> credits(numSubjects);
        for (int i = 0; i < numSubjects; ++i) {
            cout << "Enter grade (up to 2 decimal places) and credit for subject " << (i + 1) << ": ";
            cin >> grades[i] >> credits[i];
            if (grades[i] < 0 || credits[i] < 0) {
                cout << "Grade and credit values must be non-negative." << endl;
                return;
            }
        }  // input

        float spi = findSpi(grades, credits);
        if (spi == -1) {
            cout << "Error in SPI calculation for semester " << sem << ". Skipping..." << endl;
            continue;
        }

        spiList.push_back(spi); 
        cout << "SPI for Semester " << sem << ": " << fixed << setprecision(2) << spi << endl;
    }

    float cpi = calculateCpi(spiList);
    if (cpi != -1) {
        cout << "\nCPI after " << spiList.size() << " semesters: " << fixed << setprecision(2) << cpi << endl;
    }
}

int main() {
    calculateSpiAndCpi(); 
    return 0;
}
