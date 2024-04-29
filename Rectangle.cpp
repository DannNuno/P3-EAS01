#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f(0.f,0.f);
    this->objective = Vector2f(0.f,0.f);
    this->shape.setFillColor(Color::Red);

    /**  (4pts)
        Inicializa las variables: 
        - shape: un rectángulo de tamaño size.
        - speed: un Vector2f con valores (0, 0).
        - objective: un Vector2f con valores (0, 0).
        - Haz que el cuadrado se pinte de un color.
    */
}

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f(0.f,0.f);
    this->objective = Vector2f(0.f,0.f);
    this->shape.setFillColor(Color::Blue);
    this->shape.setPosition({position.x,position.y});
    /** (5pts)
        Inicializa las variables:
        - shape: un rectángulo de tamaño size.
        - speed: un Vector2f con valores (0, 0).
        - objective: un Vector2f de position.
        - Haz que el cuadrado se pinte de un color.
        - Haz que el cuadrado esté en la posición position.
    */
}

void Rectangle::update()
{   
    if(abs(this->objective.x - this->shape.getPosition().x) >= 5 && abs(this->objective.y - this->shape.getPosition().y) >= 5){
            this->shape.move(this->speed);
            this->shape.setFillColor(Color::Red);
    }else{
            this->speed = Vector2f(0,0);
            this->shape.setFillColor(Color::Green);
    }
    /**(6pts)
        Mueve el cuadrado.
        Si el cuadrado está a menos de 5 pixeles del objetivo, detén el cuadrado y píntalo de verde.
        Si no, píntalo de rojo.
            - Puedes saber si está a 5 pixeles del objetivo si la diferencia entre la coordeanda x del cuadrado y la x del objetivo es menor a 5 y lo mismo con la y.
    */
}

void Rectangle::setObjective(Vector2f objective)
{
    this->objective = objective;

    float distanciaX = this->objective.x - this->shape.getPosition().x;
    float distanciaY = this->objective.y - this->shape.getPosition().y;
    float distanciaTOT = sqrt(pow(distanciaX,2)+pow(distanciaY,2));
    float speedX = (distanciaX/distanciaTOT)*5;
    float speedY = (distanciaY/distanciaTOT)*5;
    this->speed = Vector2f(speedX,speedY);

    /**(5pts)
        Asigna objetivo a la propiedad objective.
        Calcula la dirección hacia el objetivo y la velocidad necesaria para llegar al objetivo:
        - Calcula la dirección hacia el objetivo.
            - La dirección es la diferencia entre el objetivo y la posición del cuadrado.
        - Calcula la magnitud de la dirección.
            - la magnitud es la distancia entre el cuadrado y el objetivo.
            - usa teorema de pitágoras para calcularla.
        - Calcula la velocidad necesaria para llegar al objetivo.
          - La velocidad es la dirección hacia el objetivo dividida por la magnitud de la dirección, multiplicada por un factor para cada eje.
    */

    /**Reto de valientes (0.5 décimas extra)
        Haz que el centro del cuadrado se posicione donde se dio click en lugar de que la esquina superior izquierda se posicione donde se dio click.
    */
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
