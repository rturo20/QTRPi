/*
 * CustomWindow.cpp - Implementation file for CustomWindow class
 * 
 * This file contains the implementation of the CustomWindow class methods.
 */

#include "customwindow.h"
// Main window class - provides standard window functionality
#include <QMainWindow>

/**
 * Constructor
 * 
 * Initializes the window with default settings.
 * This is where we set up the window's appearance and behavior.
 */
CustomWindow::CustomWindow() {
    // Set the window title
    setWindowTitle("Dan's QT Window");
    
    // Set the window size to 600x400 pixels
    setFixedSize(600, 400);
    
    //Set the window background properties
    setStyleSheet("QMainWindow { background-color: rgb(219, 219, 223); }");
   
    // Additional window setup can be added here
    // For example: setWindowIcon(), setStatusBar(), etc.
}

/**
 * Destructor
 * 
 * Clean up any resources when the window is destroyed.
 * Qt handles most cleanup automatically, but you can add custom cleanup here.
 */
CustomWindow::~CustomWindow() {
    // Custom cleanup code can go here if needed
}

/**
 * Initialize and show the window
 */
void CustomWindow::initializeAndShow() {
    show();
}

// You can add more method implementations here for additional functionality
// For example: void setupMenu(), void setupToolbar(), etc. 