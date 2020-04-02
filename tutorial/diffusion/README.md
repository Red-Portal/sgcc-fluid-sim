# 1D Numerical Heat Diffusion 
The goal of this homework "slash" tutorial is to implement the 1D heat diffusion equation. 

## Heat diffusion equation
The heat diffusion equation is given by the following equation.

<img src="https://render.githubusercontent.com/render/math?math=\frac{\partial u}{\partial t} = \alpha \nabla^2 u">

For the 1-dimensional special case, the equation is simplified as below.

<img src="https://render.githubusercontent.com/render/math?math=\frac{\partial u}{\partial t} = \alpha \frac{\partial^2 u}{\partial x^2}">

where `t` denotes the time step, `x` is the position in the domain.
`u(x, t)` is the function denoting the heat at position `x` and time point `t`.

Also, note that the 1-D heat equation has a closed-form solution.

## Numerical solution
The numerical solution can be computed by linearizing the derivative operators.
A step-by-step instruction in Python can be found in step 1 to 3 of [here](https://lorenabarba.com/blog/cfd-python-12-steps-to-navier-stokes/).

## Homework
* Solve the 1-D heat diffusion equation numerically using the finite-difference method.
* Use Neumann boundary conditions
* Visualize the time evolution of the heat equation (consider the gnuplot C API, MathGL or maybe export the data in CSV format using printf and plot using excel).






