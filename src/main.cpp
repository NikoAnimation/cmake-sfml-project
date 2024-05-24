#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "windowThread.cpp"
int main() {

    sf::Thread windowThread0(&threadFunc_windowThread, 0);
    sf::Thread windowThread1(&threadFunc_windowThread, 1);
    sf::Thread windowThread2(&threadFunc_windowThread, 2);
    sf::Thread windowThread3(&threadFunc_windowThread, 3);

    windowThread0.launch();
    windowThread1.launch();
    windowThread2.launch();
    windowThread3.launch();
    
    return 0;
}