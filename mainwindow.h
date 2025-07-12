/*
 * CustomWindow.h - Header file for CustomWindow class
 * 
 * This file contains the declaration of the CustomWindow class
 * that inherits from QMainWindow.
 */

#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QMainWindow>  // Full include needed for inheritance

/**
 * MainWindow Class
 * 
 * A main window class that inherits from QMainWindow.
 * This allows us to encapsulate all window-specific functionality
 * and makes the code more organized and extensible.
 */
class MainWindow : public QMainWindow {
public:
    /**
     * Constructor
     * 
     * Initializes the window with default settings.
     * This is where we set up the window's appearance and behavior.
     */
    MainWindow();
    
    /**
     * Destructor
     * 
     * Clean up any resources when the window is destroyed.
     * Qt handles most cleanup automatically, but you can add custom cleanup here.
     */
    ~MainWindow();
    
    /**
     * Initialize and show the window
     */
    void initializeAndShow();
    
    // You can add more methods here for additional functionality
    // For example: void setupMenu(), void setupToolbar(), etc.
};

#endif // CUSTOMWINDOW_H 