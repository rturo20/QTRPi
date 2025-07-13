/*
 * GameWindow.h - Header file for GameWindow class
 * 
 * This file contains the declaration of the GameWindow class
 * that inherits from QMainWindow for the Connect 4 game.
 */

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>  // Full include needed for inheritance
#include <QVBoxLayout>  // For vertical layout
#include <QHBoxLayout>  // For horizontal layout
#include <QLabel>       // For text display
#include <QPushButton>  // For button
#include <QWidget>      // For central widget

/**
 * GameWindow Class
 * 
 * A game window class that inherits from QMainWindow.
 * This encapsulates all game-specific functionality
 * and provides a clean separation from the splash screen.
 */
class GameWindow : public QMainWindow {

public:
    /**
     * Constructor
     * 
     * Initializes the game window with default settings.
     * This is where we set up the game's appearance and behavior.
     */
    GameWindow();
    
    /**
     * Destructor
     * 
     * Clean up any resources when the window is destroyed.
     * Qt handles most cleanup automatically, but you can add custom cleanup here.
     */
    ~GameWindow();
    
    /**
     * Initialize and show the window
     */
    void initializeAndShow();
    
    /**
     * Setup the game UI
     */
    void setupGameUI();

private:
    /**
     * Handle the back button click
     */
    void onBackButtonClicked();
    
    /**
     * Handle the new game button click
     */
    void onNewGameButtonClicked();

    // You can add private member variables here for game state
    // For example: QLabel *scoreLabel, QPushButton *gameButtons[6][7], etc.
};

#endif // GAMEWINDOW_H 