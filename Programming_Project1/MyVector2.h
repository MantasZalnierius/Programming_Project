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

#ifndef MY_VECTOR2
#define MY_VECTOR2

#include <SFML/Graphics.hpp> // This includes all the graphic libaries from SFML.



float vectorLength(const sf::Vector2f t_vector);  // root x2 + y2
float vectorLengthSquared(const sf::Vector2f t_vector); // x2 + y2
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector);// length of ans is one
float vectorCorssProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB);  // Vx * Uy - Vy * Ux
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB);  // Vx * Ux + Vy * Uy
float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_vectorB); // result always 0>= && <=180
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians); // anti-clockwise ({1,0},PI/2) = {0,1}
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto);// ans parallel to second vector
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto);// ans perpendicular to second vector
float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto);// scalar resolute



const float PI = 3.14159265359f; // This is PI



#endif  // MY_VECTOR2