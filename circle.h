/*
 * Circle.h - Header file for Circle class
 * 
 * This file contains the declaration of the Circle class
 * that provides circle functionality with customizable radius and color.
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <QColor>
#include <QPainter>
#include <QWidget>

/**
 * Circle Class
 * 
 * A circle class that allows users to specify radius and color.
 * This class can be used to draw circles in Qt applications.
 */
class Circle {
public:
    /**
     * Constructor
     * 
     * Initializes a circle with specified radius and color.
     * 
     * @param radius The radius of the circle in pixels
     * @param color The color of the circle (defaults to black)
     */
    Circle(double radius = 50.0, const QColor& color = QColor(0, 0, 0));
    
    /**
     * Destructor
     * 
     * Clean up any resources when the circle is destroyed.
     */
    ~Circle();
    
    /**
     * Set the radius of the circle
     * 
     * @param radius The new radius in pixels
     */
    void setRadius(double radius);
    
    /**
     * Get the current radius of the circle
     * 
     * @return The current radius in pixels
     */
    double getRadius() const;
    
    /**
     * Set the color of the circle
     * 
     * @param color The new color for the circle
     */
    void setColor(const QColor& color);
    
    /**
     * Get the current color of the circle
     * 
     * @return The current color of the circle
     */
    QColor getColor() const;
    
    /**
     * Draw the circle on a painter
     * 
     * @param painter The QPainter object to draw on
     * @param x The x-coordinate of the circle center
     * @param y The y-coordinate of the circle center
     */
    void draw(QPainter& painter, int x, int y) const;
    
    /**
     * Calculate the area of the circle
     * 
     * @return The area of the circle in square pixels
     */
    double getArea() const;
    
    /**
     * Calculate the circumference of the circle
     * 
     * @return The circumference of the circle in pixels
     */
    double getCircumference() const;

private:
    double radius;    // The radius of the circle in pixels
    QColor color;     // The color of the circle
};

#endif // CIRCLE_H 