/*
 * CustomWindow.h - Header file for CustomWindow class
 * 
 * This file contains the declaration of the CustomWindow class
 * that inherits from QMainWindow.
 */

#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QWidget>  // Full include needed for inheritance
#include <QPainter>
#include <QApplication>

/**
 * CustomWindow Class
 * 
 * A custom window class that inherits from QWidget.
 * This allows us to override paintEvent to draw circles on the screen.
 */
class CustomWindow : public QWidget {
public:
    /**
     * Constructor
     * 
     * Initializes the window with default settings.
     * This is where we set up the window's appearance and behavior.
     */
    CustomWindow();
    
    /**
     * Destructor
     * 
     * Clean up any resources when the window is destroyed.
     * Qt handles most cleanup automatically, but you can add custom cleanup here.
     */
    ~CustomWindow();
    
    /**
     * Initialize and show the window
     */
    void initializeAndShow();
    
    /**
     * Paint event - called when the window needs to be redrawn
     * This is where we draw our circles
     */
    void paintEvent(QPaintEvent* event) override;
    
    // You can add more methods here for additional functionality
    // For example: void setupMenu(), void setupToolbar(), etc.
};

#endif // CUSTOMWINDOW_H 