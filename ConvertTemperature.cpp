#include <iostream>
#include <cctype>
using namespace std;

double toCelsius(double value, char fromScale) {
    switch (toupper(fromScale)) {
        case 'F': return (value - 32) * 5 / 9;  
        case 'K': return value - 273.15;        
        case 'C': return value;                 
        default: return -1; 
    }
}
double fromCelsius(double value, char toScale) {
    switch (toupper(toScale)) {
        case 'F': return (value * 9 / 5) + 32;  
        case 'K': return value + 273.15;        
        case 'C': return value;                 
        default: return -1; 
    }
}

double convertTemperature(double value, char fromScale, char toScale) {
    if (toupper(fromScale) == toupper(toScale)) return value; 
    
    double celsiusValue = toCelsius(value, fromScale);
    if (celsiusValue == -1) return -1; 
    
    return fromCelsius(celsiusValue, toScale);
}

int main() {
    double value;
    char fromScale, toScale;
    
    cout << "Temperature Conversion Program" << endl;
    cout << "--------------------------------" << endl;
    cout << "Supported scales: C (Celsius), F (Fahrenheit), K (Kelvin)" << endl;
    cout << "\nEnter the temperature value: ";
    cin >> value;
    cout << "Enter the scale to convert from (C/F/K): ";
    cin >> fromScale;
    cout << "Enter the scale to convert to (C/F/K): ";
    cin >> toScale;
    
    double result = convertTemperature(value, fromScale, toScale);
    if (result != -1) {
        cout << "\n" << value << " " << toupper(fromScale) << " is " << result << " " << toupper(toScale) << "\n";
    } else {
        cout << "\nInvalid scale provided. Please use C, F, or K." << endl;
    }
    
    return 0;
}
