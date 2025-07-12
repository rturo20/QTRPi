/*
 * Minimal Qt Window Program - Object-Oriented Version
 * 
 * This version uses a custom window class that inherits from QMainWindow.
 * This is a more structured and extensible approach for Qt applications.
 * 
 * Dependencies: Qt5 development libraries
 */

// Qt core application class - required for any Qt GUI app
#include <QApplication>
// Include our custom window class
#include "customwindow.h"
// Include our new Circle class
#include "circle.h"
#include <iostream>

/**
 * Main function - Program entry point
 * Creates the Qt application and our custom window
 */
int main(int argc, char* argv[]) {
    // Create Qt application object (required for any Qt GUI app)
    QApplication app(argc, argv);
    
    // Example usage of the Circle class
    std::cout << "=== Circle Class Example ===" << std::endl;
    
    // Create a circle with default radius (50) and black color
    Circle circle1;
    std::cout << "Circle 1 - Radius: " << circle1.getRadius() 
              << ", Color: RGB(" << circle1.getColor().red() << ","
              << circle1.getColor().green() << "," << circle1.getColor().blue() << ")" << std::endl;
    std::cout << "Area: " << circle1.getArea() << " square pixels" << std::endl;
    std::cout << "Circumference: " << circle1.getCircumference() << " pixels" << std::endl;
    
    // Create a red circle with radius 75
    Circle circle2(75.0, QColor(255, 0, 0));
    std::cout << "\nCircle 2 - Radius: " << circle2.getRadius() 
              << ", Color: Red" << std::endl;
    std::cout << "Area: " << circle2.getArea() << " square pixels" << std::endl;
    
    // Create a blue circle with radius 100
    Circle circle3(100.0, QColor(0, 0, 255));
    std::cout << "\nCircle 3 - Radius: " << circle3.getRadius() 
              << ", Color: Blue" << std::endl;
    std::cout << "Area: " << circle3.getArea() << " square pixels" << std::endl;
    
    // Demonstrate changing properties
    circle1.setRadius(60.0);
    circle1.setColor(QColor(0, 255, 0)); // Green
    std::cout << "\nCircle 1 after changes - Radius: " << circle1.getRadius() 
              << ", Color: Green" << std::endl;
    std::cout << "New Area: " << circle1.getArea() << " square pixels" << std::endl;
    
    std::cout << "\n=== Starting Qt Window ===" << std::endl;
    
    // Create our custom window object
    CustomWindow window;
    
    // Show the window
    window.initializeAndShow();
    
    // Start the event loop (keeps the program running)
    return app.exec();
} 