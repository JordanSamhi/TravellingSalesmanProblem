# Travelling Salesman Problem

This program is part of University of Lorraine last year of bachelor degree.
Given a list of points representing cities, the goal is to compute an approximation of the best solution of the travelling salesman problem using the simulated annealing.
The project is made of two parts : 
* The client ==> C++
* The server ==> Java


## Getting Started

In the client, the different points are hard-coded. One just has to launch the server which will be listening for the client, then one has to lauch (or change the points and compile before launching) the client and give the server address and port. Then the server would draw in real-time the step-by-step solutions computed by the simulated annealing algorithm.

### Prerequisites

In this project, the server binary is given and ready provided one has Java installed. The Windows client binary is given, but of course the project can be re-compiled for any platform.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Screenshots

![Client launching](https://github.com/dusby/TravellingSalesmanProblem/blob/master/screenshots/client.png)
![Result on server](https://github.com/dusby/TravellingSalesmanProblem/blob/master/screenshots/result.png)
