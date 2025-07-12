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
#include <iostream>

/**
 * Main function - Program entry point
 * Creates the Qt application and our custom window
 */
int main(int argc, char* argv[]) {
    // Create Qt application object (required for any Qt GUI app)
    QApplication app(argc, argv);
    
    // Create our custom window object
    CustomWindow window;
    
    // Show the window
    window.initializeAndShow();
    
    // Start the event loop (keeps the program running)
    return app.exec();
} 
