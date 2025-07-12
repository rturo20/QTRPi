/*
 * CustomWindow.cpp - Implementation file for CustomWindow class
 * 
 * This file contains the implementation of the CustomWindow class methods.
 */

#include "customwindow.h"
#include "circle.h"
// Widget class - provides standard widget functionality
#include <QWidget>

/**
 * Constructor
 * 
 * Initializes the window with default settings.
 * This is where we set up the window's appearance and behavior.
 */
CustomWindow::CustomWindow() {
    // Set the window title
    setWindowTitle("Circle Drawing Demo - Qt Window");
    
    // Set the window size to 800x600 pixels (bigger for drawing)
    setFixedSize(800, 600);
    
    // Set the background color to white
    setStyleSheet("background-color: green;");
    
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

/**
 * Paint event - called when the window needs to be redrawn
 * This is where we draw our circles
 */
void CustomWindow::paintEvent(QPaintEvent* event) {
    // Create a painter for this widget
    QPainter painter(this);
    
    // Enable antialiasing for smoother circles
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Create different circles with various colors and sizes
    Circle redCircle(80.0, QColor(255, 0, 0));      // Red circle, radius 80
    Circle blueCircle(60.0, QColor(0, 0, 255));     // Blue circle, radius 60
    Circle greenCircle(100.0, QColor(0, 255, 0));   // Green circle, radius 100
    Circle yellowCircle(40.0, QColor(255, 255, 0)); // Yellow circle, radius 40
    Circle purpleCircle(70.0, QColor(128, 0, 128)); // Purple circle, radius 70
    
    // Draw circles at different positions
    redCircle.draw(painter, 200, 150);    // Top left area
    blueCircle.draw(painter, 400, 150);   // Top right area
    greenCircle.draw(painter, 300, 300);  // Center area
    yellowCircle.draw(painter, 150, 400); // Bottom left area
    purpleCircle.draw(painter, 500, 400); // Bottom right area
    
    // Draw some additional circles with different properties
    Circle orangeCircle(50.0, QColor(255, 165, 0)); // Orange circle
    Circle pinkCircle(45.0, QColor(255, 192, 203)); // Pink circle
    Circle cyanCircle(35.0, QColor(0, 255, 255));   // Cyan circle
    
    orangeCircle.draw(painter, 600, 200); // Right side
    pinkCircle.draw(painter, 100, 250);   // Left side
    cyanCircle.draw(painter, 450, 500);   // Bottom center
    
    // Draw a large circle in the background
    Circle backgroundCircle(120.0, QColor(240, 240, 240)); // Light gray
    backgroundCircle.draw(painter, 650, 100);
    
   
}

// You can add more method implementations here for additional functionality
// For example: void setupMenu(), void setupToolbar(), etc. 