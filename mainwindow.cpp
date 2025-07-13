/*
 * MainWindow.cpp - Implementation file for MainWindow class
 * 
 * This file contains the implementation of the MainWindow class methods.
 */

#include "mainwindow.h"
// Main window class - provides standard window functionality
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include <QPixmap>

/**
 * Constructor
 * 
 * Initializes the window with default settings.
 * This is where we set up the window's appearance and behavior.
 */
MainWindow::MainWindow() {
    // Set the window title
    setWindowTitle("Connect 4 - Welcome");
    
    // Set the window size to 800x600 pixels for better splash screen
    setFixedSize(800, 600);
    
    // Set the window background properties
    setStyleSheet("QMainWindow { background-color: rgba(240, 206, 15, 0.78); }");
   
    // Setup the splash screen
    setupSplashScreen();
}

/**
 * Destructor
 * 
 * Clean up any resources when the window is destroyed.
 * Qt handles most cleanup automatically, but you can add custom cleanup here.
 */
MainWindow::~MainWindow() {
    // Custom cleanup code can go here if needed
}

/**
 * Initialize and show the window
 */
void MainWindow::initializeAndShow() {
    show();
}

/**
 * Setup the splash screen UI
 */
void MainWindow::setupSplashScreen() {
    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create vertical layout for main content
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(30);
    
    // Create horizontal layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(20);
    
    // Create image label
    QLabel *imageLabel = new QLabel(this);
    QPixmap splashImage("images/splash.png");
    if (!splashImage.isNull()) {
        // Scale the image to a reasonable size (e.g., 300x200)
        splashImage = splashImage.scaled(400, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        imageLabel->setPixmap(splashImage);
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    
    // Create welcome label
    QLabel *welcomeLabel = new QLabel("Welcome to Connect 4", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setStyleSheet(
        "QLabel { "
        "font-size: 48px; "
        "font-weight: bold; "
        "color: #2c3e50; "
        "margin: 20px; "
        "}"
    );
    
    // Create begin button
    QPushButton *beginButton = new QPushButton("Play", this);
    beginButton->setFixedSize(200, 60);
    beginButton->setStyleSheet(
        "QPushButton { "
        "font-size: 24px; "
        "font-weight: bold; "
        "background-color: #3498db; "
        "color: white; "
        "border: none; "
        "border-radius: 10px; "
        "padding: 1px; "
        "}"
        "QPushButton:hover { "
        "background-color: #2980b9; "
        "}"
        "QPushButton:pressed { "
        "background-color: #21618c; "
        "}"
    );
    
     // Create cancel button
     QPushButton *cancelButton = new QPushButton("End", this);
     cancelButton->setFixedSize(200, 60);
     cancelButton->setStyleSheet(
         "QPushButton { "
         "font-size: 24px; "
         "font-weight: bold; "
         "background-color: rgb(219, 52, 96); "
         "color: white; "
         "border: none; "
         "border-radius: 10px; "
         "padding: 10px; "
         "}"
         "QPushButton:hover { "
         "background-color: rgb(227, 38, 38); "
         "}"
         "QPushButton:pressed { "
         "background-color: rgb(216, 18, 18); "
         "}"
     );


    // Connect button click signals
    connect(beginButton, &QPushButton::clicked, this, &MainWindow::onBeginButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &MainWindow::onCancelButtonClicked);

    // Add buttons to horizontal layout
    buttonLayout->addWidget(beginButton);
    buttonLayout->addWidget(cancelButton);
    
    // Add widgets to main layout
    layout->addWidget(imageLabel);
    layout->addWidget(welcomeLabel);
    layout->addLayout(buttonLayout);
}

/**
 * Handle the begin button click
 */
void MainWindow::onBeginButtonClicked() {
    // Create a new blank window
    QMainWindow *gameWindow = new QMainWindow();
    gameWindow->setWindowTitle("Connect 4 - Game");
    gameWindow->setFixedSize(800, 600);
    gameWindow->setStyleSheet("QMainWindow { background-color: white; }");
    
    // Show the new window
    gameWindow->show();
    
    // Hide the splash screen window
    this->hide();
}

void MainWindow::onCancelButtonClicked() {
    // Exit the application
    QApplication::quit();
}

// You can add more method implementations here for additional functionality
// For example: void setupMenu(), void setupToolbar(), etc. 
