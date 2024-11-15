#include <iostream>
#include <cmath>

// 3d electric field Class
class ElectricField {
private:
    double *E;// Pointer to dynamically allocated array for the field components

public:
    ElectricField() { // Constructor initializing the field to (0.0, 0.0, 0.0)
        E = new double[3];  // Allocate memory for 3 doubles
        E[0] = 0.0;
        E[1] = 0.0;
        E[2] = 0.0;
    }

// Constructor initializing (x,y,z)
    ElectricField(double ex, double ey, double ez) {
        E = new double[3];
        E[0] = ex;
        E[1] = ey;
        E[2] = ez;
    }

// Destructor that frees up  the allocated memory
    ~ElectricField() {
        delete[] E;
    }

    double getX() const { return E[0]; }// Getters for each component
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    void setX(double ex) { E[0] = ex; } // Setters for each component
    void setY(double ey) { E[1] = ey; }
    void setZ(double ez) { E[2] = ez; }

    double calculateMagnitude() const { // Calculate magnitude of Electric field function
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    double calculateInnerProduct(const ElectricField &other) const { // Function to calculate the inner Product
        return E[0] * other.E[0] + E[1] * other.E[1] + E[2] * other.E[2];
    }
};
//3d magnetic Field class
class MagneticField {
private:
    double *B;  // Pointer for allocating array component dynamicaly

public:
    MagneticField() { // Constructor for initializing the field(0.0, 0.0, 0.0)
        B = new double[3];
        B[0] = 0.0;
        B[1] = 0.0;
        B[2] = 0.0;
    }

    MagneticField(double bx, double by, double bz) { //Constructor initializing the (x,y,z) field components
        B = new double[3];
        B[0] = bx;
        B[1] = by;
        B[2] = bz;
    }
    ~MagneticField() { // Destructor to free up memeory
        delete[] B;
    }

    
    double getX() const { return B[0]; } // Getters for each component
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    void setX(double bx) { B[0] = bx; }// Setters for each component
    void setY(double by) { B[1] = by; }
    void setZ(double bz) { B[2] = bz; }

    double calculateMagnitude() const { // function for calculating the magnitude of the magnetic field
        return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    void calculateUnitVector() const { // Function to calculate and print vector of the magnetic field
        double magnitude = calculateMagnitude();
        if (magnitude != 0) {
            std::cout << "Unit Vector: (" << B[0] / magnitude <<  ", " <<B [1] / magnitude << ", " << B[2] / magnitude << ")\n";
        } else {
            std::cout << "There is no Unit Vector.\n";
        }
    }
};



int main() {
// creates ElectricField object using constructors
    ElectricField E_default;  // Default Constructor (0, 0, 0)
    ElectricField E_components(1e5, 10.9, 1.7e2);  // Constructor with components

 // Diplays the magnitude of the electric field for both objects
    std::cout << "Magnitude of the Electric Field (default): " << E_default.calculateMagnitude() << "\n";
    std::cout << "Magnitude of the Electric Field  (components): " << E_components.calculateMagnitude() << "\n";

// Inner product with another ElectricField object
    ElectricField E_other(5e4, -3.2, 2.8);
    std::cout << "Inner Product for E_components and E_other: " << E_components.calculateInnerProduct(E_other) <<  "\n";

// Create MagneticField objects using different constructors
    MagneticField B_default;  // Default constructor (0, 0, 0)
    MagneticField B_components(3.5, 1.1, -4.2);  // Constructor with components

// Displays magnitude of the magnetic field for both objects
    std::cout << "Magnitude of the Magnetic Field Magnitude (default): " << B_default.calculateMagnitude() << "\n";
    std::cout << "Magnitude of the Magnetic Field (components): " <<B_components.calculateMagnitude() << "\n";

// Displays the unit vector of the magnetic field
    std::cout << "Unit Vector for the Magnetic Field (components): ";
    B_components.calculateUnitVector();
    return 0;
}