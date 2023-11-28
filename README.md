# CSC 212 Term Project: Group 5 – Recursive Graphics
Our project uses recursion to create different fractals: Sierpinski Triangle, Hilbert Curve, and Koch Snowflake.

### Compiling and Running
Since we are using L-Systems, it is important to use the L-System Plotter in this repo. 

#### For Each Fractal C++ File:

You need to run and compile this first before plotting. 
To do this, you should run the following cpp files with this:

``g++ [chosenfractal].cpp  && ./a.out [filename].txt [degree/order of fractal]``

For the L-System Plotter Python File:
--
The python file should take in your command file name (that was edited in the cpp file), the name for your png file, and the degree for turns
``python3 "l-system-plotter.py" "[filename].txt" "[outputname].png" [degree]``

# Specifics for Each Fractal
Hilbert Curve Code:
-Degrees: 90

Sierpinski Snowkflake:
-Degrees: 72?

Sierpinski Triangle:
-Degrees: 120
