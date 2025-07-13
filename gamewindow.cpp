/*
 * GameWindow.cpp - Implementation file for GameWindow class
 * 
 * This file contains the implementation of the GameWindow class methods.
 */

#include "gamewindow.h"
// Main window class - provides standard window functionality
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QApplication>

/**
 * Constructor
 * 
 * Initializes the game window with default settings.
 * This is where we set up the game's appearance and behavior.
 */
GameWindow::GameWindow() {
    // Set the window title
    setWindowTitle("Connect 4 - Game On");
    
    // Set the window size to 800x600 pixels
    setFixedSize(800, 600);
    
    // Set the window background properties
    setStyleSheet("QMainWindow { background-color: white; }");
   
    // Setup the game UI
    setupGameUI();
}

/**
 * Destructor
 * 
 * Clean up any resources when the window is destroyed.
 * Qt handles most cleanup automatically, but you can add custom cleanup here.
 */
GameWindow::~GameWindow() {
    // Custom cleanup code can go here if needed
}

/**
 * Initialize and show the window
 */
void GameWindow::initializeAndShow() {
    show();
}

/**
 * Setup the game UI
 */
void GameWindow::setupGameUI() {
    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create vertical layout for main content
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);
    
    // Create horizontal layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(20);
    
    // Create game title label
    QLabel *gameTitleLabel = new QLabel("Connect 4 Game", this);
    gameTitleLabel->setAlignment(Qt::AlignCenter);
    gameTitleLabel->setStyleSheet(
        "QLabel { "
        "font-size: 36px; "
        "font-weight: bold; "
        "color: #2c3e50; "
        "margin: 10px; "
        "}"
    );
    
    // Create placeholder for game board
    QLabel *gameBoardLabel = new QLabel("Game Board Area", this);
    gameBoardLabel->setAlignment(Qt::AlignCenter);
    gameBoardLabel->setStyleSheet(
        "QLabel { "
        "font-size: 24px; "
        "color: #7f8c8d; "
        "background-color: #ecf0f1; "
        "border: 2px solid #bdc3c7; "
        "border-radius: 10px; "
        "padding: 10px; "
        "min-height: 300px; "
        "}"
    );
    
    // Create new game button
    QPushButton *newGameButton = new QPushButton("New Game", this);
    newGameButton->setFixedSize(200, 60);
    newGameButton->setStyleSheet(
        "QPushButton { "
        "font-size: 22px; "
        "font-weight: bold; "
        "background-color: #27ae60; "
        "color: white; "
        "border: none; "
        "border-radius: 10px; "
        "padding: 1px; "
        "}"
        "QPushButton:hover { "
        "background-color: #229954; "
        "}"
        "QPushButton:pressed { "
        "background-color: #1e8449; "
        "}"
    );
    
    // Create back button
    QPushButton *backButton = new QPushButton("Exit", this);
    backButton->setFixedSize(200, 60);
    backButton->setStyleSheet(
        "QPushButton { "
        "font-size: 22px; "
        "font-weight: bold; "
        "background-color:rgb(230, 34, 34); "
        "color: white; "
        "border: none; "
        "border-radius: 10px; "
        "padding: 10px; "
        "}"
        "QPushButton:hover { "
        "background-color:rgb(211, 84, 0); "
        "}"
        "QPushButton:pressed { "
        "background-color: #ba4a00; "
        "}"
    );

    // Connect button click signals
    connect(newGameButton, &QPushButton::clicked, this, &GameWindow::onNewGameButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &GameWindow::onBackButtonClicked);

    // Add buttons to horizontal layout
    buttonLayout->addWidget(newGameButton);
    buttonLayout->addWidget(backButton);
    
    // Add widgets to main layout
    layout->addWidget(gameTitleLabel);
    layout->addWidget(gameBoardLabel);
    layout->addLayout(buttonLayout);
}

/**
 * Handle the back button click
 */
void GameWindow::onBackButtonClicked() {
    // Close this window and return to the main menu
    this->close();
}

/**
 * Handle the new game button click
 */
void GameWindow::onNewGameButtonClicked() {
    // Reset the game state and start a new game
    // This is where you would implement the game reset logic
    // For now, we'll just show a message or reset the board
    QLabel *gameBoardLabel = findChild<QLabel*>();
    if (gameBoardLabel) {
        gameBoardLabel->setText("New Game Started!");
    }
} 