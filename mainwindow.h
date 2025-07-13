/*
 * MainWindow.h - Header file for MainWindow class
 * 
 * This file contains the declaration of the MainWindow class
 * that inherits from QMainWindow.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  // Full include needed for inheritance
#include <QVBoxLayout>  // For vertical layout
#include <QLabel>       // For text display
#include <QPushButton>  // For button
#include <QWidget>      // For central widget
#include "gamewindow.h" // Include our GameWindow class

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
    
    /**
     * Setup the splash screen UI
     */
    void setupSplashScreen();
    
    /**
     * Handle the begin button click
     */
    void onBeginButtonClicked();
    
    /**
     * Handle the cancel button click
     */
    void onCancelButtonClicked();
    
    // You can add more methods here for additional functionality
    // For example: void setupMenu(), void setupToolbar(), etc.
};

#endif // MAINWINDOW_H 