/*
 * Circle Test Program
 * 
 * This program demonstrates the Circle class functionality
 * without requiring Qt GUI components.
 */

#include "circle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Define M_PI if not already defined (some compilers don't define it)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * Test function to demonstrate Circle class features
 */
void testCircleClass() {
    std::cout << "=== Circle Class Test Program ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    // Test 1: Default constructor
    std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
    Circle defaultCircle;
    std::cout << "Default circle - Radius: " << defaultCircle.getRadius() 
              << " pixels" << std::endl;
    std::cout << "Default circle - Area: " << defaultCircle.getArea() 
              << " square pixels" << std::endl;
    
    // Test 2: Constructor with parameters
    std::cout << "\n--- Test 2: Constructor with Parameters ---" << std::endl;
    Circle redCircle(25.0, QColor(255, 0, 0));
    std::cout << "Red circle - Radius: " << redCircle.getRadius() 
              << " pixels" << std::endl;
    std::cout << "Red circle - Area: " << redCircle.getArea() 
              << " square pixels" << std::endl;
    std::cout << "Red circle - Circumference: " << redCircle.getCircumference() 
              << " pixels" << std::endl;
    
    // Test 3: Setter methods
    std::cout << "\n--- Test 3: Setter Methods ---" << std::endl;
    Circle testCircle(10.0, QColor(0, 0, 255));
    std::cout << "Initial circle - Radius: " << testCircle.getRadius() 
              << ", Color: Blue" << std::endl;
    
    testCircle.setRadius(30.0);
    testCircle.setColor(QColor(255, 255, 0)); // Yellow
    std::cout << "After changes - Radius: " << testCircle.getRadius() 
              << ", Color: Yellow" << std::endl;
    std::cout << "New area: " << testCircle.getArea() 
              << " square pixels" << std::endl;
    
    // Test 4: Invalid radius handling
    std::cout << "\n--- Test 4: Invalid Radius Handling ---" << std::endl;
    Circle invalidCircle(-5.0, QColor(128, 128, 128));
    std::cout << "Attempted to create circle with radius -5" << std::endl;
    std::cout << "Actual radius: " << invalidCircle.getRadius() 
              << " (should be 50.0)" << std::endl;
    
    // Test 5: Multiple circles with different properties
    std::cout << "\n--- Test 5: Multiple Circles ---" << std::endl;
    Circle circles[] = {
        Circle(15.0, QColor(255, 0, 0)),    // Red
        Circle(20.0, QColor(0, 255, 0)),    // Green
        Circle(25.0, QColor(0, 0, 255)),    // Blue
        Circle(30.0, QColor(255, 255, 0)),  // Yellow
        Circle(35.0, QColor(255, 0, 255))   // Magenta
    };
    
    const char* colors[] = {"Red", "Green", "Blue", "Yellow", "Magenta"};
    
    for (int i = 0; i < 5; ++i) {
        std::cout << "Circle " << (i + 1) << " (" << colors[i] 
                  << ") - Radius: " << circles[i].getRadius()
                  << ", Area: " << circles[i].getArea()
                  << ", Circumference: " << circles[i].getCircumference() << std::endl;
    }
    
    // Test 6: Mathematical calculations
    std::cout << "\n--- Test 6: Mathematical Calculations ---" << std::endl;
    Circle mathCircle(50.0, QColor(128, 128, 128));
    double expectedArea = M_PI * 50.0 * 50.0;
    double expectedCircumference = 2 * M_PI * 50.0;
    
    std::cout << "Circle with radius 50.0:" << std::endl;
    std::cout << "  Calculated area: " << mathCircle.getArea() << std::endl;
    std::cout << "  Expected area: " << expectedArea << std::endl;
    std::cout << "  Calculated circumference: " << mathCircle.getCircumference() << std::endl;
    std::cout << "  Expected circumference: " << expectedCircumference << std::endl;
    
    // Test 7: Color manipulation
    std::cout << "\n--- Test 7: Color Manipulation ---" << std::endl;
    Circle colorCircle(40.0, QColor(100, 150, 200));
    QColor originalColor = colorCircle.getColor();
    std::cout << "Original color - R:" << originalColor.red() 
              << " G:" << originalColor.green() 
              << " B:" << originalColor.blue() << std::endl;
    
    colorCircle.setColor(QColor(255, 128, 64)); // Orange
    QColor newColor = colorCircle.getColor();
    std::cout << "New color - R:" << newColor.red() 
              << " G:" << newColor.green() 
              << " B:" << newColor.blue() << std::endl;
    
    std::cout << "\n=== All Tests Completed ===" << std::endl;
}

/**
 * Main function
 */
int main() {
    testCircleClass();
    return 0;
} 