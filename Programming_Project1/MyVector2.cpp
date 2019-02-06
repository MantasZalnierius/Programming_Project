/// <summary>
/// @author = Mantas Zalnierius
/// @date = Nov 19h of 2018
/// 
/// Estimated time: 350
/// Date:   16/11/2018 (Session 1).
/// Start:  14:00
/// Finish: 16:00
/// 
/// Date:   17/11/2018 (Session 2).
/// Start:  12:00
/// Finish: 2:00
/// 
/// Date:   19/11/2018 (Session 3).
/// start:  17:00
/// finish: 20:00
/// 
/// Actual time taken = 450 mins.
/// 
/// Description: This is a program that uses a variety of functions for calculating vector maths equations.
/// 
/// Known bugs: None at this moment.
/// Got help Joshua, Simon and Arraon.
/// This website helped me to understand the vector maths and what they were used for, for my program https://onlinemschool.com/math/library/vector/
/// 
/// PS: Dear Pete, To let you know, for the roation of the vector on my researh doc, I forgot to do put my calculator to radians mode, which gave me some different answers than what I 
/// expected, but after a bit of time I understood the problem and fix it. Also in my research doc, for the Vector Cross product, I had my formula mixed up, I saw this and changed and fix 
/// this in my code Regards Mantas Zalnierius (The one, and only).


#include "MyVector2.h" // This includes the header file which has all the functions for the vector calculations.

/// <summary>
/// get length of vector using sqrt of the sum of the squares.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>length</returns>
float vectorLength(sf::Vector2f t_vector)
{
	float sumOfSquares = (t_vector.x * t_vector.x ) + (t_vector.y * t_vector.y); // This gets the sum of the squared numbers.
	const float length = sqrt(sumOfSquares); // This gets the square root of the squared numbers.
	return length; // This returns the length of the vector back to the main.cpp.
}

/// <summary>
/// This function gets the vector length squared by squaring the compenents of a vector.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>SumOfSquares</returns>
float vectorLengthSquared(sf::Vector2f t_vector)
{
	float sumOfSquares = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y); // This gets the sum of the squared numbers
	return sumOfSquares; // This returns the sum of the numbers back to the main.pp.
}

/// <summary>
/// This function gets the vector cross product, by multipling compenents of one vector by another vector and then substracting them.
/// </summary>
/// <param name="t_vectorA">input vector</param>
/// <param name="t_VectorB">input vector</param>
/// <returns>crossProductCalculation</returns>


float vectorCorssProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	float crossProductCalculation = (t_vectorA.x * t_VectorB.y) - (t_vectorA.y * t_VectorB.x); // This gets the cross product of the vectors as a single number.
	return crossProductCalculation; // This returns the cross product back to the main.cpp.
}

/// <summary>
/// This function gets the vector cross product, by multipling compenents of one vector by another vector and then adding them.
/// </summary>
/// <param name="t_vectorA">input vector</param>
/// <param name="t_VectorB">input vector</param>
/// <returns>dotProductCalculation</returns>
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	float dotProductCalculation = (t_VectorB.x * t_vectorA.x) + (t_VectorB.y * t_vectorA.y); // This gets the dot product of the vectors
	return dotProductCalculation;
}

/// <summary>
/// This function gets the angle between vectors by getting the magnitude and the dot product of two vectors and then using the inverse of cos
/// and multipling that by 180 / PI to get the angle.
/// </summary>
/// <param name="t_vectorA">input vector</param>
/// <param name="t_VectorB">input vector</param>
/// <returns>angleBetweenVector</returns>
float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	float MagnitudeOfVectorA = vectorLength(t_vectorA); // This gets the magnitude of the first vector.
	float MagnitudeOfVectorB = vectorLength(t_VectorB); // This gets the magnitude of the second vector.
	float DotProductCalculation = vectorDotProduct(t_vectorA, t_VectorB); // This gets the dot product of the two vectors.
	float angleBetweenVector = acosf(DotProductCalculation / (MagnitudeOfVectorA * MagnitudeOfVectorB)) * (180 / PI); // This gets the angle in degress.
	return angleBetweenVector; // This returns the angle between the vectors back to the main.cpp.
}

/// <summary>
/// This funciton gets the cordinates of where a vector has rotated, by multpling the vector compenents by cos and sin to get the x and y cordinates of
/// where the vector has rotated to.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <param name="t_angleRadians">input angle radians</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians)
{
	float cordinateX = (t_vector.x * cos(t_angleRadians)) - (t_vector.y * sin(t_angleRadians)); // This gets the new x cordinate of the vector after rotation.
	float cordinateY = (t_vector.x * sin(t_angleRadians)) + (t_vector.y * cos(t_angleRadians)); // This gets the new y cordinate of the vector after rotation.
	return sf::Vector2f(cordinateX, cordinateY); // This returns a vector with two points back to the main.cpp.
}

/// <summary>
/// This function gets the projection by getting the dot product of the vectors and the magnitude of the vector your projecting onto, and then using 
/// them to get the projection of the new vector.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <param name="t_onto">input vector</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	float DotProductCalculation = vectorDotProduct(t_vector, t_onto); // This gets the dot product of the two vectors.
	float magnitudeOfVector = vectorLength(t_onto); // This gets the length of the vector that is begin projected onto.
	float ProjectionCalculation = (DotProductCalculation / (magnitudeOfVector * magnitudeOfVector)); // This gets the a projection value that will multiply the compenents of the vector that is begin projected onto.
	return sf::Vector2f(ProjectionCalculation * t_onto.x, ProjectionCalculation * t_onto.y); // This returns a vector with 2 different points back to the main.cpp.
}

/// <summary>
/// This function gets the vector rejection, by getting a projection of a vector and substrating that from the original vector.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <param name="t_onto">input vector</param>
/// <returns>vectorRejection</returns>
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	sf::Vector2f projectionCalculation = vectorProjection(t_vector, t_onto); // This gets the projection of two vectors.
	sf::Vector2f vectorRejection = t_vector - projectionCalculation; // This substracts the projection of a vector, from the original vector.
	return sf::Vector2f(vectorRejection); // This returns the vector rejection back to the main.cpp.
}

/// <summary>
/// This function gets the scalar(length) projection of the vector, by getting the length(magnitude) of the projection.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <param name="t_onto">input vector</param>
/// <returns>scalarOfProjectionCalculation</returns>
float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	sf::Vector2f projectionCalculation = vectorProjection(t_vector, t_onto); // This gets the projection of two vectors.
	float scalarOfProjectionCalculation = vectorLength(projectionCalculation); // This gets the length(scalar) of the projection.
	return scalarOfProjectionCalculation; // This returns the scalar of the projection back to the main.cpp.
}

/// <summary>
/// This function gets the unit vector of a vector by getting the length of the vector and then dividing that number by the compenents of the vector.
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>Vector2f</returns>
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	float magnitudeOfVector = vectorLength(t_vector); // This gets the length of the a vector.
	return sf::Vector2f(t_vector.x / magnitudeOfVector, t_vector.y / magnitudeOfVector); // This divides each compenent of a vector by the magintude, this also returns the unit vector back to the main.cpp.
}
