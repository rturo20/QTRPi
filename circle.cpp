/*
 * Circle.cpp - Implementation file for Circle class
 * 
 * This file contains the implementation of the Circle class methods.
 */

#include "circle.h"
#include <QPainter>
#include <cmath>

/**
 * Constructor
 * 
 * Initializes a circle with specified radius and color.
 * 
 * @param radius The radius of the circle in pixels
 * @param color The color of the circle (defaults to black)
 */
Circle::Circle(double radius, const QColor& color) 
    : radius(radius), color(color) {
    // Validate radius - ensure it's positive
    if (radius <= 0) {
        this->radius = 50.0; // Default to 50 if invalid radius provided
    }
}

/**
 * Destructor
 * 
 * Clean up any resources when the circle is destroyed.
 */
Circle::~Circle() {
    // No dynamic memory to clean up, but destructor is available for future use
}

/**
 * Set the radius of the circle
 * 
 * @param radius The new radius in pixels
 */
void Circle::setRadius(double radius) {
    if (radius > 0) {
        this->radius = radius;
    }
    // Silently ignore invalid radius values
}

/**
 * Get the current radius of the circle
 * 
 * @return The current radius in pixels
 */
double Circle::getRadius() const {
    return radius;
}

/**
 * Set the color of the circle
 * 
 * @param color The new color for the circle
 */
void Circle::setColor(const QColor& color) {
    this->color = color;
}

/**
 * Get the current color of the circle
 * 
 * @return The current color of the circle
 */
QColor Circle::getColor() const {
    return color;
}

/**
 * Draw the circle on a painter
 * 
 * @param painter The QPainter object to draw on
 * @param x The x-coordinate of the circle center
 * @param y The y-coordinate of the circle center
 */
void Circle::draw(QPainter& painter, int x, int y) const {
    // Save the current painter state
    painter.save();
    
    // Set the brush and pen for the circle
    painter.setBrush(color);
    painter.setPen(QPen(color, 1));
    
    // Calculate the bounding rectangle for the circle
    int diameter = static_cast<int>(radius * 2);
    QRect circleRect(x - static_cast<int>(radius), 
                     y - static_cast<int>(radius), 
                     diameter, 
                     diameter);
    
    // Draw the circle
    painter.drawEllipse(circleRect);
    
    // Restore the painter state
    painter.restore();
}

/**
 * Calculate the area of the circle
 * 
 * @return The area of the circle in square pixels
 */
double Circle::getArea() const {
    return M_PI * radius * radius;
}

/**
 * Calculate the circumference of the circle
 * 
 * @return The circumference of the circle in pixels
 */
double Circle::getCircumference() const {
    return 2 * M_PI * radius;
} 